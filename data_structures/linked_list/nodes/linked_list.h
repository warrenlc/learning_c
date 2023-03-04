#include <stdlib.h>
#include <stdio.h>

/*
 * Struct definitions
 * */
struct Node_int {
    int value;
    struct Node_int *next;
};
typedef struct Node_int Node_int;


struct Node_double {
    double value;
    struct Node_double *next;
};
typedef struct Node_double Node_double;

struct Node_string {
    const char *string;
    struct Node_string *next;
};
typedef struct Node_string Node_string;

/*
 * Node_int functions
 * */
Node_int* Node_int_create(int val); 
void Node_int_push(Node_int **head, int val); 
void Node_int_destroy_all(Node_int **head);
void Node_int_print(const Node_int *head);
size_t Node_int_length(const Node_int *head);
void Node_int_push_back(Node_int **head, int val);
const int* Node_int_value_at(const Node_int *head, size_t index);

/*
 * Node_double functions
 * */
Node_double* Node_double_create(double val);
void Node_double_push(Node_double **head, double val); 
void Node_double_destroy_all(Node_double **head);
void Node_double_print(const Node_double *head);
size_t Node_double_length(const Node_double *head);
void Node_double_push_back(Node_double **head, double val);
const double* Node_double_value_at(const Node_double *head, size_t index);

/*
 * Node_string functions
 * */
Node_string* Node_string_create(const char *str);
void Node_string_push(Node_string **head, char *str); 
void Node_string_destroy_all(Node_string **head);
void Node_string_print(const Node_string *head);
size_t Node_string_length(const Node_string *head);
void Node_string_push_back(Node_string **head, char *str);
const char* Node_string_value_at(const Node_string *head, size_t index);
