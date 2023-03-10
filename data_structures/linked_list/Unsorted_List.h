#include <stdlib.h>

/****************************************************************
 * Singly linked lists
 ***************************************************************/

/***************************
 * Integer Lists
 *******************'******/
struct Node_int {
    int value;
    struct Node_int *next;
};
typedef struct Node_int Node_int;

typedef struct {
   Node_int *head; 
}Unsorted_List_int;


/***************************
 * Double Lists
 **************************/
struct Node_double {
    double value;
    struct Node_double *next;
};
typedef struct Node_double Node_double;

typedef struct {
    Node_double *head;
}Unsorted_List_double;


/***************************
 * String Lists
 **************************/
struct Node_string {
    const char *string;
    struct Node_string *next;
};
typedef struct Node_string Node_string;

typedef struct {
    Node_string *head;
}Unsorted_List_string;


/*************************'**************************************
 * Functions
 ***************************************************************/

/***************************
 * Unsorted integer lists
 **************************/

Unsorted_List_int *Unsorted_List_int_create();
int Unsorted_List_int_is_empty(Unsorted_List_int **list);
void Unsorted_List_int_destroy(Unsorted_List_int **list);
void Unsorted_List_int_add_front(Unsorted_List_int **list, int val);
void Unsorted_List_int_add_back(Unsorted_List_int **list, int val);
void Unsorted_List_int_print(Unsorted_List_int *list);
void Unsorted_List_int_remove_head(Unsorted_List_int **list);
size_t Unsorted_List_int_length(const Unsorted_List_int *list);
const int* Unsorted_List_int_value_at(const Unsorted_List_int *list, size_t index);
int Unsorted_List_int_insert_at(Unsorted_List_int **list, size_t index, int val);
int Unsorted_List_int_remove_at(Unsorted_List_int **list, size_t index);

/***************************
 * Unsorted double lists
 **************************/

Unsorted_List_double *Unsorted_List_double_create();
int Unsorted_List_double_is_empty(Unsorted_List_double **list);
void Unsorted_List_double_destroy(Unsorted_List_double **list);
void Unsorted_List_double_add_front(Unsorted_List_double **list, double val);
void Unsorted_List_double_add_back(Unsorted_List_double **list, double val);
void Unsorted_List_double_print(Unsorted_List_double *list);
void Unsorted_List_double_remove_head(Unsorted_List_double **list);
size_t Unsorted_List_double_length(const Unsorted_List_double *list);
const double* Unsorted_List_double_value_at(const Unsorted_List_double *list, size_t index);
int Unsorted_List_double_insert_at(Unsorted_List_double **list, size_t index, double val);
int Unsorted_List_double_remove_at(Unsorted_List_double **list, size_t index);

/**************************
 * Unsorted string lists
 *************************/

Unsorted_List_string *Unsorted_List_string_create();
int Unsorted_List_string_is_empty(Unsorted_List_string **list);
void Unsorted_List_string_destroy(Unsorted_List_string **list);
void Unsorted_List_string_add_front(Unsorted_List_string **list, char *str);
void Unsorted_List_string_add_back(Unsorted_List_string **list, char *str);
void Unsorted_List_string_print(Unsorted_List_string *list);
void Unsorted_List_string_remove_head(Unsorted_List_string **list);
size_t Unsorted_List_string_length(const Unsorted_List_string *list);
const char* Unsorted_List_string_value_at(const Unsorted_List_string *list, size_t index);
int Unsorted_List_string_insert_at(Unsorted_List_string **list, size_t index, char *str);
int Unsorted_List_string_remove_at(Unsorted_List_string **list, size_t index);
