#ifndef TYPES_H
#define TYPES_H

typedef struct Attribute {
    char* key;
    char* value;
    struct Attribute* next;
} Attribute;

typedef struct Task {
    char* id;
    char* name;
    char* deadline;
    char* completion_status;  // "done" or "not done"
    char* priority;
    Attribute* attributes;    // List of custom attributes
    struct Task* next;
} Task;

typedef struct Statement {
    char* type;
    void* data;
    struct Statement* next;
} Statement;

typedef struct Function {
    char* name;
    char** parameters;
    int param_count;
    Statement* body;
    struct Function* next;
} Function;

#endif /* TYPES_H */
