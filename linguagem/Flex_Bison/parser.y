%{
/* C code section */

#define _XOPEN_SOURCE 700  /* For strptime */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "types.h"

int yylex(void);
void yyerror(const char *s);
extern int yylineno;

int inside_function = 0;
int inside_block = 0;

Task* task_list = NULL;
Function* function_list = NULL;

/* Function prototypes */
Task* create_task(char* id, char* name);
void add_task(Task* task);
Task* find_task(char* id);
void review_all_tasks();
void free_tasks();
void set_task_attribute(Task* task, char* key, char* value);
char* get_task_attribute(Task* task, char* key);
void free_task_attributes(Task* task);

void add_function(Function* func);
Function* find_function(char* name);
void execute_function(Function* func, char** arguments, int arg_count);

void execute_show_me(Statement* stmt, char** param_names, char** param_values, int param_count);
void execute_mark_as_done(Statement* stmt, char** param_names, char** param_values, int param_count);
void execute_statement(Statement* stmt, char** param_names, char** param_values, int param_count);
int check_deadline(char* deadline);

%}

/* Include the types in the parser header */
%code requires {
    #include "types.h"
}

%union {
    char* string;
    int number;
    char** str_list;
    Statement* stmt;
    Statement* stmt_list;
    struct {
        char** list;
        int count;
    } param_data;
}

%token DEFINE_FUNCTION
%token DEFINE_TASK
%token SET_DEADLINE
%token SET_ATTRIBUTE
%token FOR_TASK
%token AS_NOT_DONE
%token AS_DONE
%token AS
%token MARK_AS_DONE
%token REVIEW_ALL_TASKS
%token SHOW_ME
%token SAVE_TASKS
%token LOAD_TASKS
%token IF_TIME_LEFT
%token BEFORE
%token OTHERWISE_FOCUS
%token REPEAT_UNTIL_COMPLETE
%token DO_IT_AGAIN
%token TIMES
%token RUN_FUNCTION

%token <string> IDENTIFIER STRING
%token <number> NUMBER

%token SEMICOLON LBRACE RBRACE LPAREN RPAREN COMMA

%type <string> value status optional_else
%type <param_data> parameter_list parameters argument_list arguments
%type <str_list> value_list
%type <stmt_list> func_statements block
%type <stmt> mark_as_done show_me func_statement
%type <stmt> define_task set_deadline set_attribute conditional loop

%start program

%debug  /* Adicione esta linha */

%%

program:
          /* empty */
        | program statement
        ;

statement:
          define_task          {}
        | set_deadline         {}
        | set_attribute        {}
        | mark_as_done         {}
        | review_all_tasks     {}
        | show_me              {}
        | save_tasks           {}
        | load_tasks           {}
        | function_definition  {}
        | run_function         {}
        | conditional          {}
        | loop                 {}
        ;

define_task:
    DEFINE_TASK IDENTIFIER AS value SEMICOLON
    {
        printf("Define task: %s as %s\n", $2, $4);
        Statement* stmt = malloc(sizeof(Statement));
        stmt->type = strdup("define_task");
        stmt->data = malloc(sizeof(char*) * 2);
        ((char**)stmt->data)[0] = strdup($2); // Task ID
        ((char**)stmt->data)[1] = strdup($4); // Task Name
        stmt->next = NULL;
        if (inside_function || inside_block) {
            $$ = stmt;
        } else {
            Task* new_task = create_task($2, $4);
            add_task(new_task);
            $$ = NULL;
        }
    }
    ;

set_deadline:
    SET_DEADLINE FOR_TASK IDENTIFIER AS value SEMICOLON
    {
        printf("Set deadline for %s as %s\n", $3, $5);
        Statement* stmt = malloc(sizeof(Statement));
        stmt->type = strdup("set_deadline");
        stmt->data = malloc(sizeof(char*) * 2);
        ((char**)stmt->data)[0] = strdup($3); // Task ID
        ((char**)stmt->data)[1] = strdup($5); // Deadline
        stmt->next = NULL;
        if (inside_function || inside_block) {
            $$ = stmt;
        } else {
            Task* task = find_task($3);
            if (task) {
                if (task->deadline) free(task->deadline);
                task->deadline = strdup($5);
            } else {
                printf("Error: Task %s not found.\n", $3);
            }
            $$ = NULL;
        }
    }
    ;

set_attribute:
    SET_ATTRIBUTE IDENTIFIER FOR_TASK IDENTIFIER AS value SEMICOLON
    {
        printf("Set attribute %s for %s as %s\n", $2, $4, $6);
        Statement* stmt = malloc(sizeof(Statement));
        stmt->type = strdup("set_attribute");
        stmt->data = malloc(sizeof(char*) * 3);
        ((char**)stmt->data)[0] = strdup($2); // Attribute Key
        ((char**)stmt->data)[1] = strdup($4); // Task ID
        ((char**)stmt->data)[2] = strdup($6); // Attribute Value
        stmt->next = NULL;
        if (inside_function || inside_block) {
            $$ = stmt;
        } else {
            Task* task = find_task($4);
            if (task) {
                if (strcmp($2, "priority") == 0) {
                    if (task->priority) free(task->priority);
                    task->priority = strdup($6);
                } else if (strcmp($2, "completion_status") == 0) {
                    if (task->completion_status) free(task->completion_status);
                    task->completion_status = strdup($6);
                } else {
                    // Custom attributes
                    set_task_attribute(task, $2, $6);
                }
            } else {
                printf("Error: Task %s not found.\n", $4);
            }
            $$ = NULL;
        }
    }
    ;

mark_as_done:
    MARK_AS_DONE IDENTIFIER status SEMICOLON
    {
        printf("Mark %s as %s\n", $2, $3);
        Statement* stmt = malloc(sizeof(Statement));
        stmt->type = strdup("mark_as_done");
        stmt->data = strdup($2);
        stmt->next = NULL;
        if (inside_function || inside_block) {
            $$ = stmt;
        } else {
            Task* task = find_task($2);
            if (task) {
                if (task->completion_status) free(task->completion_status);
                task->completion_status = strdup($3);
            } else {
                printf("Error: Task %s not found.\n", $2);
            }
            $$ = NULL;
        }
    }
    ;

status:
      AS_DONE
      {
          $$ = strdup("done");
      }
    | AS_NOT_DONE
      {
          $$ = strdup("not done");
      }
    ;

review_all_tasks:
    REVIEW_ALL_TASKS SEMICOLON
    {
        review_all_tasks();
    }
    ;

show_me:
    SHOW_ME value_list SEMICOLON
    {
        Statement* stmt = malloc(sizeof(Statement));
        stmt->type = strdup("show_me");
        stmt->data = $2;
        stmt->next = NULL;
        if (inside_function || inside_block) {
            $$ = stmt;
        } else {
            // Execute immediately
            execute_show_me(stmt, NULL, NULL, 0);
            // Free memory
            free(stmt->type);
            free(stmt);
            $$ = NULL;
        }
    }
    ;

save_tasks:
    SAVE_TASKS STRING SEMICOLON
    {
        printf("Save tasks to %s\n", $2);
        // Implement saving logic here
    }
    ;

load_tasks:
    LOAD_TASKS STRING SEMICOLON
    {
        printf("Load tasks from %s\n", $2);
        // Implement loading logic here
    }
    ;

function_definition:
    DEFINE_FUNCTION IDENTIFIER LPAREN parameter_list RPAREN block
    {
        printf("Define function %s\n", $2);
        inside_function = 1;

        Function* new_func = (Function*)malloc(sizeof(Function));
        new_func->name = strdup($2);
        new_func->parameters = $4.list;
        new_func->param_count = $4.count;
        new_func->body = $6;
        new_func->next = NULL;

        inside_function = 0;
        add_function(new_func);
    }
    ;

run_function:
    RUN_FUNCTION IDENTIFIER LPAREN argument_list RPAREN SEMICOLON
    {
        printf("Run function %s\n", $2);
        Function* func = find_function($2);
        if (func) {
            execute_function(func, $4.list, $4.count);
        } else {
            printf("Error: Function %s not found.\n", $2);
        }
    }
    ;

conditional:
    IF_TIME_LEFT BEFORE value block optional_else
    {
        printf("If there's time left before %s\n", $3);
        Statement* stmt = malloc(sizeof(Statement));
        stmt->type = strdup("conditional");
        stmt->data = malloc(sizeof(void*) * 3); // Data[0]: deadline, Data[1]: then_block, Data[2]: else_value
        ((char**)stmt->data)[0] = strdup($3); // Deadline
        ((Statement**)stmt->data)[1] = $4;    // Then block
        ((char**)stmt->data)[2] = $5;         // Else value
        stmt->next = NULL;
        if (inside_function || inside_block) {
            $$ = stmt;
        } else {
            // Execute immediately
            execute_statement(stmt, NULL, NULL, 0);
            // Free memory
            free(stmt->type);
            free(((char**)stmt->data)[0]);
            free(stmt->data);
            free(stmt);
            $$ = NULL;
        }
    }
    ;

optional_else:
          /* empty */
          {
              $$ = NULL;
          }
        | OTHERWISE_FOCUS value SEMICOLON
          {
              $$ = strdup($2);
          }
        ;

loop:
      REPEAT_UNTIL_COMPLETE block
      {
          printf("Repeat until complete\n");
          Statement* stmt = malloc(sizeof(Statement));
          stmt->type = strdup("repeat_until_complete");
          stmt->data = $2;
          stmt->next = NULL;
          if (inside_function || inside_block) {
              $$ = stmt;
          } else {
              // Execute immediately
              execute_statement(stmt, NULL, NULL, 0);
              // Free memory
              free(stmt->type);
              free(stmt);
              $$ = NULL;
          }
      }
    | DO_IT_AGAIN NUMBER TIMES block
      {
          printf("Do it again %d times\n", $2);
          Statement* stmt = malloc(sizeof(Statement));
          stmt->type = strdup("loop");
          stmt->data = malloc(sizeof(void*) * 2);
          int* times_ptr = malloc(sizeof(int));
          *times_ptr = $2;
          ((void**)stmt->data)[0] = times_ptr;
          ((void**)stmt->data)[1] = $4;
          stmt->next = NULL;
          if (inside_function || inside_block) {
              $$ = stmt;
          } else {
              // Execute immediately
              execute_statement(stmt, NULL, NULL, 0);
              // Free memory
              free(times_ptr);
              free(stmt->data);
              free(stmt->type);
              free(stmt);
              $$ = NULL;
          }
      }
    ;

parameter_list:
      /* empty */
      {
          $$.list = NULL;
          $$.count = 0;
      }
    | parameters
      {
          $$ = $1;
      }
    ;

parameters:
    IDENTIFIER
    {
        $$.list = malloc(2 * sizeof(char*));
        $$.list[0] = strdup($1);
        $$.list[1] = NULL;
        $$.count = 1;
    }
  | parameters COMMA IDENTIFIER
    {
        int i = $1.count;
        $$.list = realloc($1.list, (i + 2) * sizeof(char*));
        $$.list[i] = strdup($3);
        $$.list[i + 1] = NULL;
        $$.count = i + 1;
    }
  ;

argument_list:
      /* empty */
      {
          $$.list = NULL;
          $$.count = 0;
      }
    | arguments
      {
          $$ = $1;
      }
    ;

arguments:
    value
    {
        $$.list = malloc(2 * sizeof(char*));
        $$.list[0] = strdup($1);
        $$.list[1] = NULL;
        $$.count = 1;
    }
  | arguments COMMA value
    {
        int i = $1.count;
        $$.list = realloc($1.list, (i + 2) * sizeof(char*));
        $$.list[i] = strdup($3);
        $$.list[i + 1] = NULL;
        $$.count = i + 1;
    }
  ;

value_list:
    value
    {
        $$ = malloc(2 * sizeof(char*));
        $$[0] = strdup($1);
        $$[1] = NULL;
    }
  | value_list value
    {
        int i = 0;
        while ($1[i] != NULL) i++;
        $$ = realloc($1, (i + 2) * sizeof(char*));
        $$[i] = strdup($2);
        $$[i + 1] = NULL;
    }
    ;

value:
    STRING
    {
        $$ = strdup($1);
    }
  | IDENTIFIER
    {
        $$ = strdup($1);
    }
    ;

block:
    begin_block func_statements end_block
    {
        $$ = $2;
    }
    ;

begin_block:
    LBRACE { inside_block++; }
    ;

end_block:
    RBRACE { inside_block--; }
    ;

func_statements:
      func_statement
        {
            $$ = $1;
        }
    | func_statements func_statement
        {
            if ($1 == NULL) {
                $$ = $2;
            } else if ($2 == NULL) {
                $$ = $1;
            } else {
                Statement* temp = $1;
                while (temp->next != NULL) {
                    temp = temp->next;
                }
                temp->next = $2;
                $$ = $1;
            }
        }
    ;

func_statement:
      mark_as_done          { $$ = $1; }
    | show_me               { $$ = $1; }
    | define_task           { $$ = $1; }
    | set_deadline          { $$ = $1; }
    | set_attribute         { $$ = $1; }
    | loop                  { $$ = $1; }
    | conditional           { $$ = $1; }
    ;

%%

/* Auxiliary function implementations */

Task* create_task(char* id, char* name) {
    Task* task = malloc(sizeof(Task));
    task->id = strdup(id);
    task->name = strdup(name);
    task->deadline = NULL;
    task->completion_status = strdup("not done");
    task->priority = NULL;
    task->attributes = NULL;
    task->next = NULL;
    return task;
}

void add_task(Task* task) {
    task->next = task_list;
    task_list = task;
}

Task* find_task(char* id) {
    Task* current = task_list;
    while (current != NULL) {
        if (strcmp(current->id, id) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void review_all_tasks() {
    printf("Reviewing all tasks:\n");
    printf("Task ID              | Name                 | Deadline        | Done       | Priority   | Attributes\n");
    printf("-------------------------------------------------------------------------------------------------------------\n");
    Task* current = task_list;
    while (current != NULL) {
        printf("%-20s| %-20s| %-15s| %-10s| %-10s| ", current->id, current->name ? current->name : "N/A", current->deadline ? current->deadline : "N/A", current->completion_status ? current->completion_status : "N/A", current->priority ? current->priority : "N/A");
        // Print custom attributes
        Attribute* attr = current->attributes;
        while (attr != NULL) {
            printf("%s: \"%s\" ", attr->key, attr->value);
            attr = attr->next;
        }
        printf("\n");
        current = current->next;
    }
}

void free_task_attributes(Task* task) {
    Attribute* current = task->attributes;
    while (current != NULL) {
        Attribute* temp = current;
        current = current->next;
        free(temp->key);
        free(temp->value);
        free(temp);
    }
}

void free_tasks() {
    Task* current = task_list;
    while (current != NULL) {
        Task* temp = current;
        current = current->next;
        free(temp->id);
        free(temp->name);
        if (temp->deadline) free(temp->deadline);
        if (temp->completion_status) free(temp->completion_status);
        if (temp->priority) free(temp->priority);
        free_task_attributes(temp);
        free(temp);
    }
}

void set_task_attribute(Task* task, char* key, char* value) {
    Attribute* new_attr = malloc(sizeof(Attribute));
    new_attr->key = strdup(key);
    new_attr->value = strdup(value);
    new_attr->next = task->attributes;
    task->attributes = new_attr;
}

char* get_task_attribute(Task* task, char* key) {
    Attribute* current = task->attributes;
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return current->value;
        }
        current = current->next;
    }
    return NULL;
}

void add_function(Function* func) {
    func->next = function_list;
    function_list = func;
}

Function* find_function(char* name) {
    Function* current = function_list;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void execute_function(Function* func, char** arguments, int arg_count) {
    int param_count = func->param_count;
    char** param_names = func->parameters;
    char** param_values = arguments;

    if (param_count != arg_count) {
        printf("Error: Function %s expects %d arguments, but %d were provided.\n", func->name, param_count, arg_count);
        return;
    }

    // Execute statements
    Statement* stmt = func->body;
    while (stmt != NULL) {
        execute_statement(stmt, param_names, param_values, param_count);
        stmt = stmt->next;
    }
}

void execute_statement(Statement* stmt, char** param_names, char** param_values, int param_count) {
    if (!stmt || !stmt->type) return;

    if (strcmp(stmt->type, "show_me") == 0) {
        execute_show_me(stmt, param_names, param_values, param_count);
    } else if (strcmp(stmt->type, "mark_as_done") == 0) {
        execute_mark_as_done(stmt, param_names, param_values, param_count);
    } else if (strcmp(stmt->type, "loop") == 0) {
        void** data = (void**)stmt->data;
        int times = *((int*)data[0]);
        Statement* block = (Statement*)data[1];
        if (block) {
            for (int i = 0; i < times; i++) {
                Statement* inner_stmt = block;
                while (inner_stmt != NULL) {
                    execute_statement(inner_stmt, param_names, param_values, param_count);
                    inner_stmt = inner_stmt->next;
                }
            }
        } else {
            printf("Warning: Loop block is empty.\n");
        }
    } else if (strcmp(stmt->type, "repeat_until_complete") == 0) {
        Statement* block = (Statement*)stmt->data;
        int task_completed = 0;
        while (!task_completed) {
            // Check if any task is marked as "not done"
            Task* current = task_list;
            task_completed = 1; // Assume all tasks are complete
            while (current != NULL) {
                if (strcmp(current->completion_status, "not done") == 0) {
                    task_completed = 0; // Found an incomplete task
                    break;
                }
                current = current->next;
            }
            if (task_completed) {
                break; // All tasks are complete
            }
            // Execute the block
            Statement* inner_stmt = block;
            while (inner_stmt != NULL) {
                execute_statement(inner_stmt, param_names, param_values, param_count);
                inner_stmt = inner_stmt->next;
            }
        }
    } else if (strcmp(stmt->type, "conditional") == 0) {
        char* deadline = ((char**)stmt->data)[0];
        Statement* then_block = ((Statement**)stmt->data)[1];
        char* else_value = ((char**)stmt->data)[2];

        if (check_deadline(deadline)) {
            // There's still time before the deadline
            Statement* inner_stmt = then_block;
            while (inner_stmt != NULL) {
                execute_statement(inner_stmt, param_names, param_values, param_count);
                inner_stmt = inner_stmt->next;
            }
        } else {
            // The deadline has passed
            if (else_value != NULL) {
                printf("Otherwise focus on %s\n", else_value);
            }
        }
    } else if (strcmp(stmt->type, "define_task") == 0) {
        char* id = ((char**)stmt->data)[0];
        char* name = ((char**)stmt->data)[1];
        Task* new_task = create_task(id, name);
        add_task(new_task);
    } else if (strcmp(stmt->type, "set_deadline") == 0) {
        char* id = ((char**)stmt->data)[0];
        char* deadline = ((char**)stmt->data)[1];
        Task* task = find_task(id);
        if (task) {
            if (task->deadline) free(task->deadline);
            task->deadline = strdup(deadline);
        } else {
            printf("Error: Task %s not found.\n", id);
        }
    } else if (strcmp(stmt->type, "set_attribute") == 0) {
        char* key = ((char**)stmt->data)[0];
        char* id = ((char**)stmt->data)[1];
        char* value = ((char**)stmt->data)[2];
        Task* task = find_task(id);
        if (task) {
            if (strcmp(key, "priority") == 0) {
                if (task->priority) free(task->priority);
                task->priority = strdup(value);
            } else if (strcmp(key, "completion_status") == 0) {
                if (task->completion_status) free(task->completion_status);
                task->completion_status = strdup(value);
            } else {
                set_task_attribute(task, key, value);
            }
        } else {
            printf("Error: Task %s not found.\n", id);
        }
    }
    // Add other statement types as needed
}

void execute_show_me(Statement* stmt, char** param_names, char** param_values, int param_count) {
    char** values = (char**)stmt->data;
    for (int i = 0; values[i] != NULL; i++) {
        char* val = values[i];
        // Substitute parameters
        for (int j = 0; j < param_count; j++) {
            if (strcmp(val, param_names[j]) == 0) {
                val = param_values[j];
                break;
            }
        }
        // Remove quotes if it's a string literal
        if (val[0] == '"' && val[strlen(val) - 1] == '"') {
            // Criar uma cópia sem as aspas
            char* trimmed = strdup(val + 1); // Pular a primeira aspa
            trimmed[strlen(trimmed) - 1] = '\0'; // Remover a última aspa
            printf("%s", trimmed);
            free(trimmed);
        } else {
            printf("%s", val);
        }
        // Adicionar espaço se não for o último elemento
        if (values[i + 1] != NULL) {
            printf(" ");
        }
    }
    printf("\n");
}

void execute_mark_as_done(Statement* stmt, char** param_names, char** param_values, int param_count) {
    char* task_name = (char*)stmt->data;
    // Substitute parameters
    for (int j = 0; j < param_count; j++) {
        if (strcmp(task_name, param_names[j]) == 0) {
            task_name = param_values[j];
            break;
        }
    }
    // Mark the task as done
    Task* task = find_task(task_name);
    if (task) {
        if (task->completion_status) free(task->completion_status);
        task->completion_status = strdup("done");
    } else {
        printf("Error: Task %s not found.\n", task_name);
    }
}

int check_deadline(char* deadline_str) {
    // Remove quotes from the string
    if (deadline_str[0] == '"' && deadline_str[strlen(deadline_str) - 1] == '"') {
        deadline_str[strlen(deadline_str) - 1] = '\0';
        deadline_str++;
    }

    time_t now = time(NULL);
    struct tm deadline_tm = {0};
    strptime(deadline_str, "%Y-%m-%d", &deadline_tm);
    time_t deadline_time = mktime(&deadline_tm);

    // Return 1 if there's still time, 0 if the deadline has passed
    return difftime(deadline_time, now) > 0;
}

int main(int argc, char* argv[]) {
    extern FILE* yyin;
    yydebug = 0;  // Set to 1 to enable debugging

    if (argc > 1) {
        yyin = fopen(argv[1], "r");
        if (!yyin) {
            perror("Error opening file");
            return EXIT_FAILURE;
        }
    }
    if (yyparse() == 0) {
        printf("Parsing concluído com sucesso.\n");
    } else {
        printf("Parsing failed.\n");
    }
    free_tasks();  // Clean up allocated memory for tasks
    // Free functions and statements if necessary
    return EXIT_SUCCESS;
}

void yyerror(const char* s) {
    fprintf(stderr, "Syntax error at line %d: %s\n", yylineno, s);
}
