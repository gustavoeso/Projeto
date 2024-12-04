# **ProductivityLang**

## Gustavo Eliziario Stevenson de Oliveira e Luca Mizrahi

### **Introdução**
**ProductivityLang** é uma linguagem de programação criada para auxiliar na organização e gestão de tarefas. A linguagem permite criar, revisar e manipular tarefas, prazos e atributos associados a elas de forma intuitiva.

---

## **Estrutura Formal - EBNF**
Abaixo está a gramática formal da linguagem ProductivityLang, definida em EBNF (Extended Backus-Naur Form). Esta gramática descreve todas as construções permitidas na linguagem.

```ebnf
~program         = { statement } ;

statement       = define_task
                | set_deadline
                | set_attribute
                | mark_as_done
                | review_all_tasks
                | show_me
                | save_tasks
                | load_tasks
                | function_definition
                | run_function
                | conditional
                | loop ;

identifier      = letter , { letter | digit | "_" } ;
string          = '"' , { character } , '"' ;
number          = digit , { digit } ;

define_task     = "Define a task" , identifier , "as" , ( string | identifier ) , ";" ;
set_deadline    = "Set deadline for" , identifier , "as" , ( string | identifier ) , ";" ;
set_attribute   = "Set" , identifier , "for" , identifier , "as" , ( string | identifier ) , ";" ;
mark_as_done    = "Mark" , identifier , ( "as done" | "as not done" ) , ";" ;
review_all_tasks = "Review all tasks" , ";" ;
show_me         = "Show me" , value_list , ";" ;
save_tasks      = "Save tasks to" , string , ";" ;
load_tasks      = "Load tasks from" , string , ";" ;

function_definition = "Define function" , identifier , "(" , [ parameter_list ] , ")" , block ;
run_function    = "Run" , identifier , "(" , [ argument_list ] , ")" , ";" ;

conditional     = "If there's time left before" , ( string | identifier ) , block ,
                  [ "Otherwise focus on" , ( string | identifier ) , ";" ] ;

loop            = "Repeat until complete" , block
                | "Do it again" , number , "times" , block ;

parameter_list  = identifier , { "," , identifier } ;
argument_list   = ( string | identifier ) , { "," , ( string | identifier ) } ;
value_list      = ( string | identifier ) , { " " , ( string | identifier ) } ;

block           = "{" , { statement } , "}" ;
```

---

## **Diagrama Sintático**

![Diagrama Sintático](imgs/DS_organ_lang.png)

---

## **Analisador Léxico e Sintático com Flex e Bison**

Para implementar a análise léxica e sintática da linguagem **ProductivityLang**, utilizamos as ferramentas **Flex** e **Bison**. Estas ferramentas permitem a definição de regras léxicas e gramaticais que transformam o código fonte escrito em ProductivityLang em um executável funcional.

### **1. Estrutura dos Arquivos**

Os principais arquivos envolvidos no processo de análise léxica e sintática estão localizados na pasta `Flex_Bison`:

1. **Arquivos de Definição:**
   - **`lexer.l`**: Arquivo de definição léxica criado com **Flex**. Nele, são definidas as regras para identificar tokens como palavras-chave, identificadores, literais de string e números.
   - **`parser.y`**: Arquivo de definição sintática criado com **Bison**. Contém a gramática da linguagem ProductivityLang, especificando como os tokens são combinados para formar estruturas válidas na linguagem.

2. **Arquivo de Tipos:**
   - **`types.h`**: Arquivo de cabeçalho que define as estruturas de dados utilizadas pelo interpretador, como `Task`, `Function` e `Statement`. Este arquivo é incluído tanto em `lexer.l` quanto em `parser.y` para compartilhar definições entre análise léxica e sintática.

3. **Arquivo de Compilação:**
   - **`Makefile`**: Automatiza o processo de geração dos analisadores e a compilação do interpretador. Define as regras para gerar os arquivos necessários a partir de `lexer.l` e `parser.y`, e para compilar o executável final `productivitylang`.

### **2. Processo de Geração e Compilação**

O processo de geração e compilação do interpretador **ProductivityLang** segue as etapas abaixo, facilitadas pelo **Makefile**:

1. **Geração dos Analisadores com Flex e Bison:**
   - **Bison** processa o arquivo `parser.y` para gerar dois arquivos:
     - **`parser.tab.c`**: Implementação em C do analisador sintático.
     - **`parser.tab.h`**: Cabeçalho contendo definições de tokens para comunicação com o Flex.
   - **Flex** processa o arquivo `lexer.l` para gerar:
     - **`lex.yy.c`**: Implementação em C do analisador léxico.

2. **Compilação dos Arquivos Gerados:**
   - **GCC** compila os arquivos `parser.tab.c` e `lex.yy.c` junto com quaisquer outros arquivos necessários, ligando a biblioteca **Flex** (`-lfl`) para produzir o executável final:
     ```bash
     gcc -g -Wall -Wextra -Wno-unused-function -o productivitylang parser.tab.c lex.yy.c -lfl
     ```

3. **Automatização com Makefile:**
   - O **Makefile** define regras para executar os comandos acima automaticamente. Ao executar `make`, o **Makefile**:
     - Chama **Bison** para processar `parser.y`.
     - Chama **Flex** para processar `lexer.l`.
     - Compila os arquivos gerados em um único executável `productivitylang`.
   - O comando `make clean` remove os arquivos gerados durante a compilação, permitindo uma recompilação limpa:
     ```bash
     make clean
     make
     ```

### **3. Configuração do Makefile**

O **Makefile** está configurado para simplificar o processo de compilação e garantir que todas as dependências sejam corretamente gerenciadas. A seguir, apresenta-se a estrutura do **Makefile**:

```makefile
# Makefile para compilar o interpretador ProductivityLang usando Flex e Bison

LEXER=lexer.l
PARSER=parser.y
EXECUTABLE=productivitylang
TYPES=types.h

LEXER_C=lex.yy.c
PARSER_C=parser.tab.c
PARSER_H=parser.tab.h

CC=gcc
CFLAGS=-g -Wall -Wextra -Wno-unused-function

all: $(EXECUTABLE)

$(EXECUTABLE): $(LEXER_C) $(PARSER_C)
	$(CC) $(CFLAGS) -o $@ $(PARSER_C) $(LEXER_C) -lfl

$(LEXER_C): $(LEXER) $(PARSER_H) $(TYPES)
	flex $(LEXER)

$(PARSER_C) $(PARSER_H): $(PARSER) $(TYPES)
	bison -d $(PARSER)

types.h:

clean:
	rm -f $(EXECUTABLE) $(LEXER_C) $(PARSER_C) $(PARSER_H)
```

**Explicação das Regras e Variáveis:**

- **Variáveis:**
  - `LEXER` e `PARSER`: Referenciam os arquivos de definição léxica e sintática.
  - `EXECUTABLE`: Nome do executável final.
  - `TYPES`: Arquivo de cabeçalho com definições de tipos.
  - `LEXER_C`, `PARSER_C`, `PARSER_H`: Arquivos gerados por Flex e Bison.
  - `CC` e `CFLAGS`: Compilador e flags de compilação utilizados.

- **Regras:**
  - `all`: Alvo padrão que depende do executável.
  - `$(EXECUTABLE)`: Compila os arquivos gerados por Flex e Bison em um executável.
  - `$(LEXER_C)`: Gera o analisador léxico com Flex.
  - `$(PARSER_C)` e `$(PARSER_H)`: Gera o analisador sintático com Bison.
  - `clean`: Remove os arquivos gerados durante a compilação.

### **4. Exemplo de Uso**

A seguir, um exemplo completo do processo de geração e execução do interpretador:

1. **Compilar o Interpretador:**
   Navegue até o diretório `Flex_Bison` e execute:
   ```bash
   make
   ```
   Este comando gera os analisadores léxico e sintático e compila o executável `productivitylang`.

2. **Executar com um Arquivo de Entrada:**
   Execute o interpretador passando um arquivo de teste:
   ```bash
   ./productivitylang tests/input_file1
   ```

3. **Exemplo de Entrada e Saída:**

   - **Arquivo de Entrada (`tests/input_file1`):**
     ```plaintext
     Define a task task1 as "Write report";
     Set deadline for task1 as "2023-11-30";
     Repeat until complete {
         Define a task task2 as "Prepare slides";
     }
     ```

   - **Saída Esperada:**
     ```plaintext
     Define task: task1 as "Write report"
     Set deadline for task1 as "2023-11-30"
     Repeat block executed.
     Parsing concluído com sucesso.
     ```

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
