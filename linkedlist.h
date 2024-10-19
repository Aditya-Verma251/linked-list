typedef struct node {
    int data;
    int index;
    struct node* next;
} node;

void append(int, node*);
void pop(node*);
void out(int, node*);
void insert(int, int, node*);
void rmnode(int, node*);
void search(int, node*);
void printlist(node*);
