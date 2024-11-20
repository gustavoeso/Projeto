# **ProductivityLang**

### **Introdução**
**ProductivityLang** é uma linguagem de programação criada para auxiliar na organização e gestão de tarefas. A linguagem permite criar, revisar e manipular tarefas, prazos e atributos associados a elas de forma intuitiva.

---

## **Estrutura Formal - EBNF**
Abaixo está a gramática formal da linguagem ProductivityLang, definida em EBNF (Extended Backus-Naur Form). Esta gramática descreve todas as construções permitidas na linguagem.

```ebnf
program         = { statement } ;

statement       = define_task
                | set_deadline
                | set_attribute
                | mark_as_done
                | review_all_tasks
                | show_me
                | save_tasks
                | load_tasks
                | conditional
                | loop
                | function_definition
                | run_function ;

identifier      = letter , { letter | digit | "_" } ;
string          = '"' , { character } , '"' ;
number          = digit , { digit } ;

define_task     = "Define a task" , identifier , "as" , ( string | identifier ) , ";" ;
set_deadline    = "Set deadline for" , identifier , "as" , ( string | identifier ) , ";" ;
set_attribute   = "Set" , identifier , "for" , identifier , "as" , ( string | identifier ) , ";" ;
mark_as_done    = "Mark" , identifier , ( "as done" | "as not done" ) , ";" ;
review_all_tasks = "Review all tasks" , ";" ;
show_me         = "Show me" , ( string | identifier ) , ";" ;
save_tasks      = "Save tasks to" , string , ";" ;
load_tasks      = "Load tasks from" , string , ";" ;
conditional     = "If there's time left before" , ( string | identifier ) , block ,
                  [ "Otherwise focus on" , ( string | identifier ) ] ;
block           = "{" , { statement } , "}" ;
loop            = "Repeat until complete" , block
                | "Do it again" , number , "times" , block ;
function_definition = "Define function" , identifier , "(" , [ parameter_list ] , ")" , block ;
parameter_list  = identifier , { "," , identifier } ;
run_function    = "Run" , identifier , "(" , [ argument_list ] , ")" , ";" ;
argument_list   = ( string | identifier ) , { "," , ( string | identifier ) } ;
```

---

## **Analisador Léxico e Sintático com Flex e Bison**

Para implementar a análise léxica e sintática da linguagem ProductivityLang, utilizamos as ferramentas **Flex** e **Bison**. A seguir, descrevemos a estrutura dos arquivos, o processo de geração e execução do compilador.

---

### **1. Estrutura dos Arquivos**

Os principais arquivos utilizados no processo estão na pasta `Flex_Bison`:

1. **Arquivos Originais**:
   - `productivitylang.l`: Define as regras léxicas da linguagem, como palavras-chave, identificadores e literais.
   - `productivitylang.y`: Define a gramática e as ações associadas às regras sintáticas.

2. **Arquivos Gerados**:
   Durante o processo de compilação, os seguintes arquivos são gerados automaticamente:
   - `productivitylang.tab.c`: Arquivo em C gerado pelo **Bison**, que implementa o analisador sintático.
   - `productivitylang.tab.h`: Cabeçalho gerado pelo **Bison**, contendo definições de tokens para comunicação com o Flex.
   - `lex.yy.c`: Arquivo em C gerado pelo **Flex**, que implementa o analisador léxico.

---

### **2. Passo a Passo de Geração**

1. **Geração dos Arquivos com Bison e Flex**:
   Execute os seguintes comandos no terminal para gerar o compilador:
   ```bash
   bison -d productivitylang.y
   flex productivitylang.l
   gcc -o productivitylang productivitylang.tab.c lex.yy.c -lfl
   ```

2. **Executar o Compilador**:
   Após gerar o executável `productivitylang`, utilize-o para interpretar os arquivos de entrada escritos na linguagem ProductivityLang:
   ```bash
   ./productivitylang < tests/input_file1
   ```

3. **Limpar os Arquivos Gerados**:
   Para remover os arquivos gerados durante a compilação:
   ```bash
   make clean
   ```

---

### **3. Configuração do `Makefile`**

Um arquivo `Makefile` foi configurado para automatizar o processo de compilação. Ele realiza as seguintes etapas:

1. Geração dos arquivos `productivitylang.tab.c` e `productivitylang.tab.h` com o **Bison**.
2. Geração do arquivo `lex.yy.c` com o **Flex**.
3. Compilação dos arquivos gerados em um único executável `productivitylang`.

#### **Estrutura do `Makefile`**:

```makefile
all: productivitylang

productivitylang: productivitylang.l productivitylang.y
	bison -d productivitylang.y
	flex productivitylang.l
	gcc -o productivitylang productivitylang.tab.c lex.yy.c -lfl

clean:
	rm -f productivitylang productivitylang.tab.c productivitylang.tab.h lex.yy.c
```

---

### **4. Exemplo de Geração e Execução**

Abaixo, um exemplo completo do processo de geração e execução:

1. **Compilar o Código**:
   ```bash
   make
   ```

2. **Executar com Arquivo de Entrada**:
   ```bash
   ./productivitylang < tests/input_file1
   ```

3. **Exemplo de Saída para `tests/input_file1`**:
   - Arquivo de entrada:
     ```plaintext
     Define a task task1 as "Write report";
     Set deadline for task1 as "2023-11-30";
     Repeat until complete {
         Define a task task2 as "Prepare slides";
     }
     ```
   - Saída esperada:
     ```plaintext
     Defined task: task1 as "Write report"
     Set deadline for task: task1 as "2023-11-30"
     Repeat block executed.
     ```

---

## **Conteúdo**
1. [Características](#características)
2. [Estruturas Básicas](#estruturas-básicas)
   - [Variáveis](#variáveis)
   - [Condicionais](#condicionais)
   - [Loops](#loops)
3. [Comandos](#comandos)
   - [Definir Tarefas](#definir-tarefas)
   - [Definir Prazos](#definir-prazos)
   - [Atributos Customizados](#atributos-customizados)
   - [Status de Conclusão](#status-de-conclusão)
   - [Salvar e Carregar Tarefas](#salvar-e-carregar-tarefas)
   - [Revisar Tarefas](#revisar-tarefas)
   - [Exibir Informações](#exibir-informações)
4. [Comentários](#comentários)
5. [Formato de Data](#formato-de-data)
6. [Exemplo Completo](#exemplo-completo)

---

### **Características**
- Foco em produtividade e organização.
- Estruturas básicas de programação: variáveis, loops e condicionais.
- Comandos intuitivos como `Define a task`, `Set deadline`, e `Review all tasks`.
- Suporte para salvar e carregar tarefas em arquivos JSON.
- Suporte para criação e execução de funções.
- Suporte para comentários no código.

---

### **Estruturas Básicas**

#### **Variáveis**
- As variáveis principais da linguagem são tarefas (`tasks`).
- Cada tarefa possui um nome (obrigatório) e pode ter:
  - Um **prazo** (`deadline`).
  - Atributos adicionais (`priority`, `category`, etc.).
  - Status de conclusão (`done` ou `not done`).

---

#### **Condicionais**
- Use `If there's time left before` para executar blocos condicionais baseados em datas.
- **Sintaxe:**
  ```plaintext
  If there's time left before "2024-12-01" {
      Define a task task1 as "Prepare slides";
  } Otherwise focus on "Urgent tasks";
  ```

---

#### **Loops**
- **`Repeat until complete`:** Executa blocos repetidamente até ser interrompido (limitado a 10 iterações para segurança).
- **`Do it again X times`:** Executa o bloco um número fixo de vezes.
- **Sintaxe:**
  ```plaintext
  Repeat until complete {
      Define a task task1 as "Iterative task";
  }

  Do it again 3 times {
      Define a task task2 as "Repeated task";
  }
  ```

---

### **Comandos**

#### **Definir Tarefas**
- Cria uma nova tarefa com um nome.
- **Sintaxe:**
  ```plaintext
  Define a task task1 as "Finish report";
  ```

---

#### **Definir Prazos**
- Define um prazo para uma tarefa existente.
- **Sintaxe:**
  ```plaintext
  Set deadline for task1 as "2024-12-01";
  ```

---

#### **Atributos Customizados**
- Adiciona atributos às tarefas, como prioridade ou categoria.
- **Sintaxe:**
  ```plaintext
  Set priority for task1 as "High";
  Set category for task1 as "Work";
  ```

---

#### **Status de Conclusão**
- Marca uma tarefa como concluída ou não concluída.
- **Sintaxe:**
  ```plaintext
  Mark task1 as done;
  Mark task2 as not done;
  ```

---

#### **Salvar e Carregar Tarefas**
- **Salvar tarefas:** Salva todas as tarefas em um arquivo JSON.
  - **Sintaxe:**
    ```plaintext
    Save tasks to "tasks.json";
    ```

- **Carregar tarefas:** Substitui o estado atual das tarefas pelo conteúdo do arquivo JSON.
  - **Sintaxe:**
    ```plaintext
    Load tasks from "tasks.json";
    ```

---

#### **Revisar Tarefas**
- Lista todas as tarefas, seus prazos e atributos.
- **Sintaxe:**
  ```plaintext
  Review all tasks;
  ```

- **Exemplo de saída:**
  ```plaintext
  Reviewing all tasks:
  Task ID             | Name                 | Deadline        | Status     | Other Attributes
  ---------------------------------------------------------------------------------------------
  task1               | Finish report        | 2024-12-01      | done       | priority: High, category: Work
  task2               | Prepare slides       | No deadline set | not done   | priority: Medium
  ```

---

#### **Exibir Informações**
- Exibe mensagens ou valores de variáveis.
- **Sintaxe:**
  ```plaintext
  Show me "Welcome to ProductivityLang!";
  Show me task1;
  ```

---

#### **Funções**
- Crie e execute funções para automatizar tarefas repetitivas.
- **Definir funções:**
  ```plaintext
  Define function addHomework(taskName, taskDeadline) {
      Define a task taskName as taskName;
      Set deadline for taskName as taskDeadline;
      Set category for taskName as "Homework";
  }
  ```
- **Executar funções:**
  ```plaintext
  Run addHomework("Math Homework", "2024-12-01");
  Run addHomework("Science Project", "2024-12-15");
  ```

---

### **Comentários**
- Use `#` para adicionar comentários de linha única.
- Tudo após o `#` em uma linha será ignorado.
- **Exemplo:**
  ```plaintext
  # Este é um comentário
  Define a task task1 as "Complete project";  # Comentário após o comando
  ```

---

### **Formato de Data**
- As datas devem estar no formato **YYYY-MM-DD**.
- Exemplo: `"2024-12-01"`

---

### **Exemplo Completo**

```plaintext
Define a task task1 as "Finish report";
Set deadline for task1 as "2024-12-01";
Set priority for task1 as "High";
Set category for task1 as "Work";
Mark task1 as done;

Define a task task2 as "Prepare slides";
Set priority for task2 as "Medium";
Mark task2 as not done;

Save tasks to "tasks.json";
Load tasks from "tasks.json";

Define function addHomework(taskName, taskDeadline) {
    Define a task taskName as taskName;
    Set deadline for taskName as taskDeadline;
    Set category for taskName as "Homework";
}

Run addHomework("Math Homework", "2024-12-01");
Run addHomework("Science Project", "2024-12-15");

If there's time left before "2024-12-10" {
    Show me "You have time to prepare slides!";
} Otherwise focus on "Critical tasks";

Review all tasks;
```

**Saída Esperada:**
```plaintext
Task 'Finish report' defined.
Deadline for 'Finish report' set to 2024-12-01.
Set priority for 'Finish report' to High.
Set category for 'Finish report' to Work.
Task 'Finish report' marked as done.
Task 'Prepare slides' defined.
Set priority for 'Prepare slides' to Medium.
Task 'Prepare slides' marked as not done.
Tasks saved to tasks.json.
Tasks loaded from tasks.json.
Function 'addHomework' defined with parameters ['taskName', 'taskDeadline'].
Task 'Math Homework' defined.
Deadline for 'Math Homework' set to 2024-12-01.
Set category for 'Math Homework' to Homework.
Task 'Science Project' defined.
Deadline for 'Science Project' set to 2024-12-15.
Set category for 'Science Project' to Homework.
You have time to prepare slides!
Reviewing all tasks:
Task ID             | Name                 | Deadline        | Status     | Other Attributes
---------------------------------------------------------------------------------------------
task1               | Finish report        | 2024-12-01      | done       | priority: High, category: Work
task2               | Prepare slides       | No deadline set | not done   | priority: Medium
Math Homework       | Math Homework        | 2024-12-01      | not done   | category: Homework
Science Project     | Science Project      | 2024-12-15      | not done   | category: Homework
```