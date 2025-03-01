#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 8
#define STACK_SIZE 100

typedef struct {
    int value;
    int left;
    int right;
} Node;

Node tree[MAX_NODES] = {
    {50, 1, 2}, 
    {30, 3, 4}, 
    {70, 5, 6}, 
    {20, 7, -1}, 
    {40, -1, -1}, 
    {60, -1, -1}, 
    {70, -1, -1}, 
    {10, -1, -1}
};

void preorderTraversal() {
    int stack[STACK_SIZE], top = -1;
    int i = 0;

    printf("-------| Pre-order Traversal |-------\n\n[  ");
    while (i != -1 || top != -1) {
        printf("%d  ", tree[i].value);
        if (tree[i].right != -1)
            stack[++top] = tree[i].right;
        i = (tree[i].left != -1) ? tree[i].left : (top != -1 ? stack[top--] : -1);
    }
    printf("]\n\n");
}

void inorderTraversal() {
    int stack[STACK_SIZE], top = -1;
    int i = 0;

    printf("-------| In-order Traversal |-------\n\n[  ");
    while (i != -1 || top != -1) {
        while (i != -1) {
            stack[++top] = i;
            i = tree[i].left;
        }
        i = stack[top--];
        printf("%d  ", tree[i].value);
        i = tree[i].right;
    }
    printf("]\n\n");
}

void postorderTraversal() {
    int stack[STACK_SIZE], top = -1;
    int i = 0, lastVisited = -1;

    printf("------| Post-order Traversal |------\n\n[  ");
    while (i != -1 || top != -1) {
        while (i != -1) {
            stack[++top] = i;
            i = tree[i].left;
        }
        i = stack[top];
        if (tree[i].right != -1 && tree[i].right != lastVisited)
            i = tree[i].right;
        else {
            printf("%d  ", tree[i].value);
            lastVisited = i;
            top--;
            i = -1;
        }
    }
    printf("]\n\n");
}

int main() {
    preorderTraversal();
    inorderTraversal();
    postorderTraversal();
    return 0;
}
