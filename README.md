Projeto de Logica Computacional para criação de uma linguagem de programação

Autalmente no compilador atual, temos um limite de rodar 10 iteracoes de um programa, caso o programa ultrapasse esse limite, o compilador irá parar a execução do programa por questões de segurança.

test5 tem um overview por cima de coisas que podem ser feitas na nossa linguagem.

---

## **ProductivityLang**

### **Introdução**
**ProductivityLang** é uma linguagem de programação criada para auxiliar na organização e gestão de tarefas. A linguagem permite criar, revisar e manipular tarefas, prazos e atributos associados a elas de forma intuitiva.

---

### **Conteúdo**
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

---

#### **Exibir Informações**
- Exibe mensagens ou valores de variáveis.
- **Sintaxe:**
  ```plaintext
  Show me "Welcome to ProductivityLang!";
  Show me task1;
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

If there's time left before "2024-12-10" {
    Show me "You have time to prepare slides!";
} Otherwise focus on "Critical tasks";

Review all tasks;
```

**Saída Esperada:**
```plaintext
Task 'Finish report' defined.
Set deadline for 'Finish report' to 2024-12-01.
Set priority for 'Finish report' to High.
Set category for 'Finish report' to Work.
Task 'Finish report' marked as done.
Task 'Prepare slides' defined.
Set priority for 'Prepare slides' to Medium.
Task 'Prepare slides' marked as not done.
Tasks saved to tasks.json.
Tasks loaded from tasks.json.
You have time to prepare slides!
Reviewing all tasks:
 - task1: 'Finish report', Deadline: 2024-12-01, Status: done
   - priority: High
   - category: Work
 - task2: 'Prepare slides', Deadline: No deadline set, Status: not done
   - priority: Medium
```
