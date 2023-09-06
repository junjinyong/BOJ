#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    int height;
} typedef Node;

int getHeight(const Node* node) {
    return node == NULL ? 0 : node -> height;
}

int getBalanceFactor(const Node* node) {
    return node == NULL ? 0 : getHeight(node -> left) - getHeight(node -> right);
}

int max(int a, int b) {
    return a > b ? a : b;
}

Node* getNewNode(int data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node -> data = data;
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
        if(getBalanceFactor(root->right) <= 0) {
            rotateLeft(node);
        } else {
            rotateRightLeft(node);
        }
    }
}

void insert(Node** const node, int data) {
    if(*node == NULL) {
        *node = getNewNode(data);
        return;
    }
    Node* const root = *node;
    const int key = root -> data;
    if(data < key) {
        insert(&(root -> left), data);
    } else if(data > key) {
        insert(&(root -> right), data);
    } else {
        return;
    }
    updateHeight(root);
    rebalance(node);
}

void delete(Node** const node, int data) {
    if(*node == NULL) {
        return;
    }
    Node* const root = *node;
    const int key = root -> data;
    if(data < key) {
        delete(&(root -> left), data);
    } else if(data > key) {
        delete(&(root -> right), data);
    } else {
        if(root -> left == NULL && root -> right == NULL) {
            *node = NULL;
            free(root);
        } else if(root -> left == NULL) {
            *node = root -> right;
            free(root);
        } else if(root -> right == NULL) {
            *node = root -> left;
            free(root);
        } else {
            Node** target = &(root -> right);
            while((*target) -> left != NULL) {
                target = &((*target) -> left);
            }
            const int value = (*target) -> data;
            root -> data = value;
            delete(&((*node) -> right), value);
        }
    }
    if(*node != NULL) {
        updateHeight(*node);
        rebalance(node);
    }
}

int encode_(const char ch) {
    return ch < 'a' ? ch - 'A' + 1 : ch - 'a' + 26 + 1;
}

char decode_(const int code) {
    return (char) (code > 26 ? code - 26 - 1 + 'a' : code - 1 + 'A');
}

int encode(const char* name) {
    int result = 0, index = 0;
    char ch;
    while(index < 5 && (ch = name[index]) != '\0') {
        result = (result << 6) + encode_(ch);
        ++index;
    }
    while(index < 5) {
        result = result << 6;
        ++index;
    }
    return result;
}

void decode(char* name, int code) {
    int mask = (1 << 30) - (1 << 24), index = 0, offset = 24;
    while(mask) {
        const int val = (mask & code) >> offset;
        if(val == 0) {
            break;
        }
        name[index] = decode_((mask & code) >> offset);
        ++index;
        mask = mask >> 6;
        offset = offset - 6;
    }
    name[index] = '\0';
}

void travel(Node* node) {
    static char arr[6];
    if(node != NULL) {
        travel(node -> right);
        decode(arr, node -> data);
        printf("%s\n", arr);
        travel(node -> left);
    }
}

int main() {
    Node* node = NULL;
    Node** root = &node;
    
    int n;
    scanf("%d", &n);
    
    char name[6], state[6];
    while(n--) {
        scanf("%s %s", name, state);
        if(state[0] == 'e') {
            insert(root, encode(name));
        } else {
            delete(root, encode(name));
        }
    }
    
    travel(*root);
    
    return 0;
}
