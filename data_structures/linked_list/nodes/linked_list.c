#include <stdio.h>
#include "linked_list.h"

/*
 * Basic function definitions for using the concept of a singly 
 * linked list. These are intended to be basic building blocks for building other
 * more sophisticated datatypes, based on the concept of a Node where
 * a Node has a value and points to the next Node. 
 */



int main() {
    
    Node_double* head = Node_double_create(11.1);
    int start;
    for (start = 0; start < 101; start++) {
        Node_double_push_back(&head, start + 0.13159);
    }
    
    Node_double_print(head); 
    printf("\n\n");
    for (start = 0; start < 101; start++) {
        Node_double_push(&head, start + 0.131);
    }    

    Node_double_print(head);
    
    printf("\nSize of double list is %lu\n", Node_double_length(head)); 

    Node_string* string_head = Node_string_create("Warren");
    int countdown = 100;
    while (countdown > 0) {   
        if (countdown % 2 == 0) {
            Node_string_push(&string_head, "Apple");
        }
        else if (countdown % 7 == 0) {
            Node_string_push(&string_head, "Pomegranite");
        }
        else if (countdown % 13 == 0) {
            Node_string_push(&string_head, "Banana");
        }
        else {
            Node_string_push(&string_head, "Orange");
        }
        countdown--;
    }
    
    printf("\nThe 48th value of each list is %.2f and %s.\n", *Node_double_value_at(head, 47), Node_string_value_at(string_head, 47));


    printf("\nSize of string list is %lu\n", Node_string_length(string_head)); 
    Node_string_print(string_head); 

    Node_string_destroy_all(&string_head);

    Node_double_destroy_all(&head); 
    return 0;
}


// Node_int

Node_int* 
Node_int_create(int val) {
    Node_int *new_node = malloc(sizeof(Node_int));
    new_node->value = val;
    new_node->next = NULL;
    return new_node;
}

void 
Node_int_push(Node_int **head, int val) {
    Node_int *new_node = Node_int_create(val);
    new_node->next = *head;
    *head = new_node;
}

void 
Node_int_destroy_all(Node_int **head) {
    Node_int *temp;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

void 
Node_int_print(const Node_int *head) {
   const Node_int *temp;
    printf("{");
    temp = head;
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

size_t 
Node_int_length(const Node_int *head) {
    if (head == NULL) return 0; 
    size_t k = 0;
    const Node_int *temp = head;
    while (temp != NULL) {
        temp = temp->next;
        k++;
    }
    return k; 
}

void 
Node_int_push_back(Node_int **head, int val) {
    Node_int *new_node = Node_int_create(val);
    if (*head == NULL) { 
        *head = new_node; 
    } 
    else {
        Node_int *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

const int* 
Node_int_value_at(const Node_int *head, size_t index) {
    if (head == NULL) return NULL; 
    const Node_int *current = head;
    for (size_t i = 0; i < index; i++) {
        current = current->next;
        if (current == NULL) return NULL;
    }
    return &(current->value);
}


// Node_double

Node_double* 
Node_double_create(double val) {
    Node_double *new_node = malloc(sizeof(Node_double));
    new_node->value = val;
    new_node->next = NULL;
    return new_node;
}

void 
Node_double_push(Node_double **head, double val) {
    Node_double *new_node = Node_double_create(val);
    new_node->next = *head;
    *head = new_node;
} 

void 
Node_double_destroy_all(Node_double **head) {
    Node_double *temp;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

void 
Node_double_print(const Node_double *head) {
    const Node_double *temp;
    printf("{");
    temp = head;
    while (temp != NULL) {
        if (temp->next == NULL) {
            printf("%.3f", temp->value);
        }
        else {
            printf("%.3f, ", temp->value);
        }
        temp = temp->next;
    }
    printf("}\n");
}

size_t 
Node_double_length(const Node_double *head) {
    if (head == NULL) return 0; 
    size_t k = 0;
    const Node_double *temp = head;
    while (temp != NULL) {
        temp = temp->next;
        k++;
    }
    return k; 
}

void 
Node_double_push_back(Node_double **head, double val) {
    Node_double *new_node = Node_double_create(val);
    if (*head == NULL) { 
        *head = new_node; 
    } 
    else {
        Node_double *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

const double* 
Node_double_value_at(const Node_double *head, size_t index) {
    if (head == NULL) return NULL; 
    const Node_double *current = head;
    for (size_t i = 0; i < index; i++) {
        current = current->next;
        if (current == NULL) return NULL;
    }
    return &(current->value);
}

// Node_string functions

Node_string* 
Node_string_create(const char *str) {
    Node_string *new_node = malloc(sizeof(Node_string));
    new_node->string = str;
    new_node->next = NULL;
    return new_node;
}

void 
Node_string_push(Node_string **head, char *str) {
    Node_string *new_node = Node_string_create(str);
    new_node->next = *head;
    *head = new_node;
}

void 
Node_string_destroy_all(Node_string **head) {
    Node_string *temp;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

void 
Node_string_print(const Node_string *head) {
    const Node_string *temp;
    printf("{");
    temp = head;
    while (temp != NULL) {
        if (temp->next == NULL) {
            printf("%s", temp->string);
        }
        else {
            printf("%s, ", temp->string);
        }
        temp = temp->next;
    }
    printf("}\n");
}

size_t 
Node_string_length(const Node_string *head) {
    if (head == NULL) return 0; 
    size_t k = 0;
    const Node_string *temp = head;
    while (temp != NULL) {
        temp = temp->next;
        k++;
    }
    return k; 
}

void 
Node_string_push_back(Node_string **head, char *str) {
    Node_string *new_node = Node_string_create(str);
    if (*head == NULL) { 
        *head = new_node; 
    } 
    else {
        Node_string *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

const char* 
Node_string_value_at(const Node_string *head, size_t index) {
    if (head == NULL) return NULL; 
    const Node_string *current = head;
    for (size_t i = 0; i < index; i++) {
        current = current->next;
        if (current == NULL) return NULL;
    }
    return (current->string);
}

