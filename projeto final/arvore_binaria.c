#include "arvore_binaria.h"
#include <stdio.h>
#include <stdlib.h>

struct TreeNode *criarNo(int key)
{
    struct TreeNode *novoNo = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    novoNo->key = key;
    novoNo->left = NULL;
    novoNo->right = NULL;
    return novoNo;
}

struct TreeNode *inserir(struct TreeNode *root, int key)
{
    if (root == NULL)
        return criarNo(key);

    if (key < root->key)
        root->left = inserir(root->left, key);
    else if (key > root->key)
        root->right = inserir(root->right, key);

    return root;
}

struct TreeNode *menorNo(struct TreeNode *root)
{
    while (root->left != NULL)
        root = root->left;
    return root;
}

struct TreeNode *removerNo(struct TreeNode *root, int key)
{
    if (root == NULL)
        return root;

    if (key < root->key)
        root->left = removerNo(root->left, key);
    else if (key > root->key)
        root->right = removerNo(root->right, key);
    else
    {
        if (root->left == NULL)
        {
            struct TreeNode *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct TreeNode *temp = root->left;
            free(root);
            return temp;
        }

        struct TreeNode *temp = menorNo(root->right);
        root->key = temp->key;
        root->right = removerNo(root->right, temp->key);
    }
    return root;
}

int buscar(struct TreeNode *root, int key)
{
    if (root == NULL)
        return 0;
    if (key == root->key)
        return 1;
    if (key < root->key)
        return buscar(root->left, key);
    else
        return buscar(root->right, key);
}

void inorder(struct TreeNode *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

void preorder(struct TreeNode *root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct TreeNode *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->key);
    }
}

int menorValor(struct TreeNode *root)
{
    while (root->left != NULL)
        root = root->left;
    return root->key;
}

int maiorValor(struct TreeNode *root)
{
    while (root->right != NULL)
        root = root->right;
    return root->key;
}

void freeTree(struct TreeNode *root)
{
    if (root != NULL)
    {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}