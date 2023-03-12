#include <stdio.h>
#include <stdlib.h>

typedef struct tree tree;

typedef enum { fuck, shit} token;
struct tree {
    token value;
    tree *left;
    tree *right;
};



int main(int argc, char *argv[]) {
    tree *binary_tree = malloc(sizeof(tree));
    binary_tree->value = fuck;
    binary_tree->left = NULL;
    binary_tree->right = NULL;
    printf("our initialized tree with value %d and no children.\n", binary_tree->value);
    
    free(binary_tree);

    return 0;
}
