#include <stdio.h>
#include <stdlib.h>
#include "arvore_binaria.h"

int main()
{
    struct TreeNode *root = NULL;

    root = inserir(root, 50);
    root = inserir(root, 30);
    root = inserir(root, 20);
    root = inserir(root, 40);
    root = inserir(root, 70);
    root = inserir(root, 60);
    root = inserir(root, 80);

    printf("Inorder: ");
    inorder(root);
    printf("\n");

    printf("Preorder: ");
    preorder(root);
    printf("\n");

    printf("Postorder: ");
    postorder(root);
    printf("\n");

    int keyToSearch = 40;
    if (buscar(root, keyToSearch))
        printf("%d esta na arvore.\n", keyToSearch);
    else
        printf("%d not esta na arvore.\n", keyToSearch);

    printf("Menor valor: %d\n", menorValor(root));
    printf("Maior valor: %d\n", maiorValor(root));

    int keyToRemove = 30;
    root = removerNo(root, keyToRemove);
    printf("Inorder apos remover %d: ", keyToRemove);
    inorder(root);
    printf("\n");

    freeTree(root);

    return 0;
}