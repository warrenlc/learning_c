#include <stdio.h>
#include <stdlib.h>

#include "Unsorted_List.h"

int main() {
/*
    Unsorted_List_int *int_list = Unsorted_List_int_create();
    if (Unsorted_List_int_is_empty(&int_list) == 1) {
        printf("head is Null\n");
    }
    
    Unsorted_List_int_add_front(&int_list, 11);

    if (Unsorted_List_int_is_empty(&int_list) == 1) {
        printf("head is Null\n");
    } else {
        printf("Head is not null, but has value: %d\n", int_list->head->value); 
    }
    
    unsigned k;
    for(k = 4; k < 1000; k++) {
        if (k % 19 == 0) {
            Unsorted_List_int_add_front(&int_list, (int)k);
        }
    }
    
    Unsorted_List_int_add_back(&int_list, 7);
    for (k = 19; k < 77; k++) {
        if (k % 2 != 0) {
            Unsorted_List_int_add_back(&int_list, (int)k);
        }
    } 
    
    printf("\nThe size of the list is: %lu\n", Unsorted_List_int_length(int_list));
    Unsorted_List_int_print(int_list);

    printf("The value of the list at position %u is %d\n", k, *Unsorted_List_int_value_at(int_list, (size_t)k));
    for (k = 1; k < 29; k++) {
        Unsorted_List_int_remove_head(&int_list);
    }
    

    printf("\nThe size of the list is: %lu\n", Unsorted_List_int_length(int_list));
    Unsorted_List_int_print(int_list);
    
    if (Unsorted_List_int_insert_at(&int_list, 0, 973) == 1) {
        printf("\nadded.\n\n");
    } else {
        printf("\nOut of range.\n\n");
    }
    
    Unsorted_List_int_print(int_list);


    if (Unsorted_List_int_insert_at(&int_list, 234234, 12123) == 1) {
        printf("\nadded.\n\n");
    } else {
        printf("\nOut of range.\n\n");
    }
    
    if (Unsorted_List_int_insert_at(&int_list, 10, 713) == 1) {
        printf("\nadded.\n\n");
    } else {
        printf("\nOut of range.\n\n");
    } 
    printf("\n");
    Unsorted_List_int_print(int_list);    
    
    printf("\nThe size of the list is: %lu\n", Unsorted_List_int_length(int_list));
    if (Unsorted_List_int_remove_at(&int_list, 57) == 1) {
        printf("removed!\n\n");
    } else {
        printf("cannot remove. out of range!\n\n");
    }
    Unsorted_List_int_print(int_list);
    Unsorted_List_int_destroy(&int_list);
*/

    Unsorted_List_int* fuck = Unsorted_List_int_create();

    Unsorted_List_int_print(fuck);
    printf("\n");
    
    Unsorted_List_int_insert_at(&fuck, 0, 13);
    Unsorted_List_int_print(fuck);
    printf("\n");

    Unsorted_List_int_add_back(&fuck, 17);
    Unsorted_List_int_print(fuck);
    printf("\n");
    
    Unsorted_List_int_insert_at(&fuck, 1, 123);
    Unsorted_List_int_print(fuck);
    printf("\n");
    
    Unsorted_List_int_insert_at(&fuck, Unsorted_List_int_length(fuck), 19);
    Unsorted_List_int_print(fuck);
    printf("\n");

    Unsorted_List_int_insert_at(&fuck, 0, 13);
    Unsorted_List_int_print(fuck);
    printf("\n");
    
    Unsorted_List_int_insert_at(&fuck, 1, 17);
    Unsorted_List_int_print(fuck);
    printf("\n");
    
    Unsorted_List_int_insert_at(&fuck, Unsorted_List_int_length(fuck), 19);
    Unsorted_List_int_print(fuck);
    printf("\n");

    Unsorted_List_int_add_front(&fuck, 999);
    Unsorted_List_int_print(fuck);
    printf("\n");

    Unsorted_List_int_insert_at(&fuck, 0, 777);
    Unsorted_List_int_print(fuck);
    printf("\n");

    Unsorted_List_int_insert_at(&fuck, Unsorted_List_int_length(fuck) - 1, 666);
    Unsorted_List_int_print(fuck);
    printf("\n");
   

    Unsorted_List_int_add_back(&fuck, 888);
    Unsorted_List_int_print(fuck);
    printf("\n");
    
    Unsorted_List_int_remove_at(&fuck, Unsorted_List_int_length(fuck));
    Unsorted_List_int_print(fuck);
    printf("\n");

    Unsorted_List_int_destroy(&fuck);
    return 0;
}

Unsorted_List_int* 
Unsorted_List_int_create() {
    Unsorted_List_int *new_list = malloc(sizeof(Unsorted_List_int));
    new_list->head = NULL; 
    return new_list;
}

int
Unsorted_List_int_is_empty(Unsorted_List_int **list) {
    return (*list)->head == NULL;
}

void 
Unsorted_List_int_destroy(Unsorted_List_int **list) {
    Node_int *temp;
    while ((*list)->head != NULL) {
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
    if ((*list)->head == NULL) { 
        (*list)->head = new_node; 
    } else {
        Node_int *current = (*list)->head;
        while (current->next != NULL) {
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
    while (temp != NULL) {
        if (temp->next == NULL) {
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
    if (Unsorted_List_int_is_empty(list) != 1) { 
        Node_int *temp_head = (*list)->head; 
        (*list)->head  = (*list)->head->next;
        free(temp_head); 
    }
}

size_t 
Unsorted_List_int_length(const Unsorted_List_int *list) {
    if (list->head == NULL) return 0; 
    size_t k = 0;
    const Node_int *temp = list->head;
    while (temp != NULL) {
        temp = temp->next;
        k++;
    }
    return k; 
}

const int* 
Unsorted_List_int_value_at(const Unsorted_List_int *list, size_t index) {
    if (list->head == NULL) return NULL; 
    const Node_int *current = list->head;
    for (size_t i = 0; i < index; i++) {
        current = current->next;
        if (current == NULL) return NULL;
    }
    return &(current->value);
}

int 
Unsorted_List_int_insert_at(Unsorted_List_int **list, size_t index, int val) {
    if (index == 0) { Unsorted_List_int_add_front(list, val); return 1; }
    if (Unsorted_List_int_is_empty(list) == 1) { return -1; }
    Node_int *temp = (*list)->head;
    size_t k;
    for (k = 0; k < index - 1; k++) {

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
    if (Unsorted_List_int_is_empty(list) == 1) { return -1; }
    if (index == 0) { Unsorted_List_int_remove_head(list); return 1; }
    Node_int *temp = (*list)->head->next;
    size_t k;
    for (k = 1; k < index - 2; k++) {
        if (temp->next == NULL) { printf("outof fucking boundS!\n"); return -1; }
        temp = temp->next;
    }
    Node_int *n = temp->next->next;
    free(temp->next);
    temp->next = n;
    return 1;
}

//void Unsorted_List_int_remove_back(Unsorted_List_int **list);

















