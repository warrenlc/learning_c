/*
 *
 *
 * enum TokenType {
    NUMBER,     // a number token
    PLUS,       // a plus token
    MINUS,      // a minus token
    TIMES,      // a times token
    DIVIDE,     // a divide token
    LPAREN,     // a left parenthesis token
    RPAREN      // a right parenthesis token
};

struct Token {
    enum TokenType type;    // the type of the token
    double value;           // the numerical value of the token (if it's a number)
};
struct Node {
    Token token;               // the token associated with the node
    struct Node** children;    // array of pointers to children
    int num_children;          // number of children in the array
};
struct Node {
    Token token;          // the token associated with the node
    struct Node* left;    // pointer to the left child
    struct Node* right;   // pointer to the right child
};
 
 *
 *
 *
 * */
typedef struct tree tree;

typedef enum { joe, steve }token;
struct tree {
    token value;
    tree *left;
    tree *right;
};
