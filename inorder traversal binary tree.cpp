#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

void inorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->val);
        inorderTraversal(root->right);
    }
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    if (preorderSize == 0 || inorderSize == 0) {
        return NULL;
    }

    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = preorder[0];
    root->left = NULL;
    root->right = NULL;

    int rootIndex = 0;
    while (inorder[rootIndex] != preorder[0]) {
        rootIndex++;
    }

    root->left = buildTree(preorder + 1, rootIndex, inorder, rootIndex);
    root->right = buildTree(preorder + 1 + rootIndex, preorderSize - 1 - rootIndex, inorder + rootIndex + 1, inorderSize - 1 - rootIndex);

    return root;
}

int main() {
    int preorder[] = {3, 9, 20, 15, 7};
    int inorder[] = {9, 3, 15, 20, 7};
    int n = sizeof(preorder) / sizeof(preorder[0]);

    struct TreeNode* root = buildTree(preorder, n, inorder, n);

    printf("Inorder Traversal of the Constructed Tree: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}

