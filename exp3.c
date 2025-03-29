#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int weight;
    struct TreeNode *left, *right;
};

struct TreeNode* newNode(int weight) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->weight = weight;
    node->left = node->right = NULL;
    return node;
}

struct TreeNode* mergeTrees(int weights[], int n) {
    if (n == 1) {
        return newNode(weights[0]);
    }

    struct TreeNode* nodes[n];
    for (int i = 0; i < n; i++) {
        nodes[i] = newNode(weights[i]);
    }
    while (n > 1) {
        int min1 = 0, min2 = 1;
        if (nodes[min1]->weight > nodes[min2]->weight) {
            int temp = min1;
            min1 = min2;
            min2 = temp;
        }

        for (int i = 2; i < n; i++) {
            if (nodes[i]->weight < nodes[min1]->weight) {
                min2 = min1;
                min1 = i;
            } else if (nodes[i]->weight < nodes[min2]->weight) {
                min2 = i;
            }
        }
        struct TreeNode* newNodePtr = newNode(nodes[min1]->weight + nodes[min2]->weight);
        newNodePtr->left = nodes[min1];
        newNodePtr->right = nodes[min2];
        nodes[min1] = newNodePtr;
        nodes[min2] = nodes[n - 1];

        n--;
    }

    return nodes[0];
}

int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int weights[n];
    printf("Enter node weights: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &weights[i]);
    }

    struct TreeNode* root = mergeTrees(weights, n);
    printf("Root weight of merged tree: %d\n", root->weight);

    return 0;
}
