#include <stdio.h>
#include <stdlib.h>

#include "Unsorted_List.h"

int main() {
    Unsorted_List_double *double_list = Unsorted_List_double_create();
    if (Unsorted_List_double_is_empty(&double_list)) 
        printf("The list is empty\n");
    
    Unsorted_List_double_add_front(&double_list, 31.2);
    Unsorted_List_double_add_front(&double_list, 99.13);
    Unsorted_List_double_add_back(&double_list, 17.1717171);

    if (!Unsorted_List_double_is_empty(&double_list))
        printf("The list is not empty.\n");

    Unsorted_List_double_print(double_list);
    
    Unsorted_List_double_remove_head(&double_list);
    Unsorted_List_double_print(double_list);
    

    printf("The length of the list is: %lu\n", Unsorted_List_double_length(double_list));

    printf("The value of the head is: %.2f\n", *Unsorted_List_double_value_at(double_list, 0));
    
    Unsorted_List_double_insert_at(&double_list, 1, 29.1717);
    Unsorted_List_double_print(double_list);
    Unsorted_List_double_remove_at(&double_list, Unsorted_List_double_length(double_list) - 1);
    Unsorted_List_double_print(double_list);
    
    Unsorted_List_double_remove_back(&double_list);
    Unsorted_List_double_print(double_list);

//    Unsorted_List_double_remove_back(&double_list);
//    Unsorted_List_double_print(double_list);
    
    
   // Unsorted_List_double_remove_back(&double_list);
   // Unsorted_List_double_print(double_list);
    
    Unsorted_List_double_destroy(&double_list);
    return 0;
}


/****************************************************************************************
 * 
 * Singly linked unsorted List of type int
 *
 ***************************************************************************************/

Unsorted_List_int* 
Unsorted_List_int_create() {
    Unsorted_List_int *new_list = malloc(sizeof(Unsorted_List_int));
    new_list->head = NULL; 
    return new_list;
}

int
Unsorted_List_int_is_empty(Unsorted_List_int **list) {
    return !(*list)->head;
}

void 
Unsorted_List_int_destroy(Unsorted_List_int **list) {
    Node_int *temp;
    while ((*list)->head) {
        temp = (*list)->head;
        (*list)->head = (*list)->head->next;
        free(temp);
    }
    free(*list);
}

void 
Unsorted_List_int_add_front(Unsorted_List_int **list, int val) {
    Node_int *new_node = malloc(sizeof(Node_int));
    new_node->value = val;
    new_node->next = ((*list)->head);
    (*list)->head = new_node;
}

void
Unsorted_List_int_add_back(Unsorted_List_int **list, int val) {
    Node_int *new_node = malloc(sizeof(Node_int));
    new_node->value = val;
    new_node->next = NULL;
    
    if (!(*list)->head) { 
        (*list)->head = new_node; 
    } else {
        Node_int *current = (*list)->head;
        while (current->next) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void 
Unsorted_List_int_print(Unsorted_List_int *list) {
    const Node_int *temp;
    printf("{");
    temp = (list)->head;
    while (temp) {
        if (!temp->next) {
            printf("%d", temp->value);
        }
        else {
            printf("%d, ", temp->value);
        }
        temp = temp->next;
    }
    printf("}\n");
}

void 
Unsorted_List_int_remove_head(Unsorted_List_int **list) {
    if (!Unsorted_List_int_is_empty(list)) { 
        Node_int *temp_head = (*list)->head; 
        (*list)->head  = (*list)->head->next;
        free(temp_head); 
    }
}

size_t 
Unsorted_List_int_length(const Unsorted_List_int *list) {
    if (!list->head) 
        return 0; 
    
    size_t k = 0;
    const Node_int *temp = list->head;
    while (temp) {
        temp = temp->next;
        k++;
    }
    
    return k; 
}

const int* 
Unsorted_List_int_value_at(const Unsorted_List_int *list, size_t index) {
    if (!list->head) 
        return NULL; 
    
    const Node_int *current = list->head;
    for (size_t i = 0; i < index; i++) {
        current = current->next;
        if (!current) 
            return NULL;
    }
    
    return &(current->value);
}

int 
Unsorted_List_int_insert_at(Unsorted_List_int **list, size_t index, int val) {
    if (index == 0) {
        Unsorted_List_int_add_front(list, val); 
        return 1; 
    }
    
    // We can only add to an empty list at index 0, which is handled above.
    if (Unsorted_List_int_is_empty(list)) 
        return -1; 
    
    Node_int *temp = (*list)->head;
    for (size_t k = 0; k < index - 1; k++) {

        if (temp->next == NULL) { return -1; } 
        temp = temp->next;
    }
   
    Node_int *new_node = malloc(sizeof(Node_int));
    new_node->value = val;
    new_node->next = temp->next;
    temp->next = new_node;

    return 1;
}

int 
Unsorted_List_int_remove_at(Unsorted_List_int **list, size_t index) {
    if (Unsorted_List_int_is_empty(list)) 
        return -1;
   
    if (index == 0) { 
        Unsorted_List_int_remove_head(list); 
        return 1; 
    }
    
    Node_int *temp = (*list)->head; 
    size_t k = 0;
    while (temp->next) {
        if (k == index - 1) {
            Node_int *n = temp->next->next;
            free(temp->next);
            temp->next = n;
            return 1;
        }
        temp = temp->next;
        k++;
    }
    return -1;
}

void 
Unsorted_List_int_remove_back(Unsorted_List_int **list) {
    if (Unsorted_List_int_is_empty(list))
        return; 

    Node_int *counter = (*list)->head;
    while (counter->next->next) {
        counter = counter->next;        
    }

    free(counter->next);
    counter->next = NULL; 
}

/**********************************************************************************************
 *
 * Singly linked unsorted list of type double
 *
 *********************************************************************************************/

Unsorted_List_double 
*Unsorted_List_double_create() {
    Unsorted_List_double *new_list = malloc(sizeof(Unsorted_List_double));
    new_list->head = NULL;
    return new_list;
}

int
Unsorted_List_double_is_empty(Unsorted_List_double **list) {
    return !(*list)->head;
}

void 
Unsorted_List_double_destroy(Unsorted_List_double **list) {
    Node_double *temp;
    while ((*list)->head) {
        temp = (*list)->head;
        (*list)->head = (*list)->head->next;
        free(temp);
    }
    free(*list);
}

void 
Unsorted_List_double_add_front(Unsorted_List_double **list, double val) {
    Node_double *new_node = malloc(sizeof(Node_double));
    new_node->value = val;
    new_node->next = ((*list)->head);
    (*list)->head = new_node;
}

void 
Unsorted_List_double_add_back(Unsorted_List_double **list, double val) {
    Node_double *new_node = malloc(sizeof(Node_double));
    new_node->value = val;
    new_node->next = NULL;
    
    if (!(*list)->head) { 
        (*list)->head = new_node; 
    } else {
        Node_double *current = (*list)->head;
        while (current->next) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void 
Unsorted_List_double_print(Unsorted_List_double *list) {
    const Node_double *temp;
    printf("{");
    temp = (list)->head;
    while (temp) {
        if (!temp->next) {
            printf("%.3f", temp->value);
        }
        else {
            printf("%.3f, ", temp->value);
        }
        temp = temp->next;
    }
    printf("}\n");
}

void 
Unsorted_List_double_remove_head(Unsorted_List_double **list) {
    if (!Unsorted_List_double_is_empty(list)) { 
        Node_double *temp_head = (*list)->head; 
        (*list)->head  = (*list)->head->next;
        free(temp_head); 
    }
}

size_t 
Unsorted_List_double_length(const Unsorted_List_double *list) {
    if (!list->head) 
        return 0; 
    
    size_t k = 0;
    const Node_double *temp = list->head;
    while (temp) {
        temp = temp->next;
        k++;
    }
    
    return k; 
}

const double* 
Unsorted_List_double_value_at(const Unsorted_List_double *list, size_t index) {
    if (!list->head) 
        return NULL; 
    
    const Node_double *current = list->head;
    for (size_t i = 0; i < index; i++) {
        current = current->next;
        if (!current) 
            return NULL;
    }
    
    return &(current->value);
}

int 
Unsorted_List_double_insert_at(Unsorted_List_double **list, size_t index, double val) {
    if (index == 0) {
        Unsorted_List_double_add_front(list, val); 
        return 1; 
    }
    
    // We can only add to an empty list at index 0, which is handled above.
    if (Unsorted_List_double_is_empty(list)) 
        return -1; 
    
    Node_double *temp = (*list)->head;
    for (size_t k = 0; k < index - 1; k++) {

        if (temp->next == NULL) { return -1; } 
        temp = temp->next;
    }
   
    Node_double *new_node = malloc(sizeof(Node_double));
    new_node->value = val;
    new_node->next = temp->next;
    temp->next = new_node;

    return 1;
}

int 
Unsorted_List_double_remove_at(Unsorted_List_double **list, size_t index) {
    if (Unsorted_List_double_is_empty(list)) 
        return -1;
   
    if (index == 0) { 
        Unsorted_List_double_remove_head(list); 
        return 1; 
    }
    
    Node_double *temp = (*list)->head; 
    size_t k = 0;
    while (temp->next) {
        if (k == index - 1) {
            Node_double *n = temp->next->next;
            free(temp->next);
            temp->next = n;
            return 1;
        }
        temp = temp->next;
        k++;
    }
    return -1;
}

void 
Unsorted_List_double_remove_back(Unsorted_List_double **list) {
    if (Unsorted_List_double_is_empty(list))
        return; 
    Node_double *counter = (*list)->head;
    
    printf("last value is: %.2f\n", counter->next->value);
    printf("counter->value is: %.2f\n", counter->value); 

   /* 
    if (counter->next->next == NULL)
        free(counter->next);
        //counter->next = NULL;
        return;
  
    if (counter->next == NULL) {
        printf("I got to !counter->next\n");
        free(counter);
        return;
    } else {
   */ 
    while (counter->next) {
        printf("Did I get here?\n");
        printf("counter value before moving: %.2f\n", counter->value);
        counter = counter->next;        
        printf("counter value after moving: %.2f\n", counter->value);
    }
    free(counter);
    counter->next = NULL; 

}











