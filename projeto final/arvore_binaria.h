struct TreeNode
{
    int key;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *criarNo(int key);
struct TreeNode *inserir(struct TreeNode *root, int key);
struct TreeNode *removerNo(struct TreeNode *root, int key);
int buscar(struct TreeNode *root, int key);
void inorder(struct TreeNode *root);
void preorder(struct TreeNode *root);
void postorder(struct TreeNode *root);
int menorValor(struct TreeNode *root);
int maiorValor(struct TreeNode *root);
void freeTree(struct TreeNode *root);