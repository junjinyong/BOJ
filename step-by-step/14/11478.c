#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LENGTH 1001

struct Node {
    char data[LENGTH];
    struct Node* left;
    struct Node* right;
    int height;
} typedef Node;

inline int getHeight(const Node* node) {
    return node == NULL ? 0 : node -> height;
}

inline int getBalanceFactor(const Node* node) {
    return node == NULL ? 0 : getHeight(node -> left) - getHeight(node -> right);
}

inline int max(int a, int b) {
    return a > b ? a : b;
}

Node* getNewNode(const char* data) {
    Node* node = (Node*) malloc(sizeof(Node));
    strcpy(node -> data, data);
    node -> left = NULL;
    node -> right = NULL;
    node -> height = 1;
    return node;
}

void updateHeight(Node* const node) {
    node -> height = 1 + max(getHeight(node -> left), getHeight(node -> right));
}

void rotateLeft(Node** const node) {
    Node* const root = *node;
    Node* const right = root -> right;
    root -> right = right -> left;
    right -> left = root;
    updateHeight(root);
    updateHeight(right);
    *node = right;
}

void rotateRight(Node** const node) {
    Node* const root = *node;
    Node* const left = root -> left;
    root -> left = left -> right;
    left -> right = root;
    updateHeight(root);
    updateHeight(left);
    *node = left;
}

void rotateLeftRight(Node** const node) {
    rotateLeft(&((*node) -> left));
    rotateRight(node);
}

void rotateRightLeft(Node** const node) {
    rotateRight(&((*node) -> right));
    rotateLeft(node);
}

void rebalance(Node** const node) {
    Node* const root = *node;
    const int balance_factor = getBalanceFactor(root);
    if(balance_factor > 1) {
        if(getBalanceFactor(root -> left) >= 0) {
            rotateRight(node);
        } else {
            rotateLeftRight(node);
        }
    }
    if(balance_factor < -1) {
        if(getBalanceFactor(root -> right) <= 0) {
            rotateLeft(node);
        } else {
            rotateRightLeft(node);
        }
    }
}

int insert(Node** const node, const char* data) {
    if(*node == NULL) {
        *node = getNewNode(data);
        return 1;
    }
    Node* const root = *node;
    const int compare = strcmp(data, root -> data);
    int val;
    if(compare < 0) {
        val = insert(&(root -> left), data);
    } else if(compare > 0) {
        val = insert(&(root -> right), data);
    } else {
        return 0;
    }
    updateHeight(root);
    rebalance(node);
    return val;
}

void clear(Node* const node) {
    if(node == NULL) {
        return;
    } else {
        clear(node -> left);
        clear(node -> right);
        free(node);
    }
}

int main() {
    
    
    char S[LENGTH], temp[LENGTH];
    scanf("%s", S);
    
    const int length = (int) strlen(S);
    int count = 0;
    for(int i = 1; i <= length; ++i) {
        Node* node = NULL;
        Node** root = &node;
        
        strcpy(temp, S);
        for(int j = length - i, k = length; j >= 0; --j, --k) {
            temp[k] = '\0';
            count = count + insert(root, temp + j);
        }
        clear(*root);
    }
    
    printf("%d\n", count);
    
    return 0;
}
