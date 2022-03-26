#include<stdio.h>
#include<stdlib.h>

struct node
{
    int key;
    struct node *left, *right;
};


struct node *newNode(int item)
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}


void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d \n", root->key);
        inorder(root->right);
    }
}

void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d \n", root->key);
         preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root){
    if (root != NULL)
    {
         postorder(root->left);
        postorder(root->right);
          printf("%d \n", root->key);
    }
}


struct node* insert(struct node* node, int key)
{

    if (node == NULL) return newNode(key);


    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key >= node->key)
        node->right = insert(node->right, key);


    return node;
}


int main()
{

    struct node *root = NULL;

    int t,key,m,n;
    printf("How many nodes :\n");
    scanf("%d", &t);

    printf("\n");

    while(t-- > 0)
    {
        scanf("%d", &key);
        root=insert(root, key);
    }
    printf("\n");
    printf("Inorder traversal of the given tree :\n");


    inorder(root);
      printf("preorder traversal of the given tree :\n");

      preorder(root);

       printf("postorder traversal of the given tree :\n");

       postorder(root);


    /*while(1)
    {
        printf("insert new value :");
        scanf("%d",&m);
        root=insert(root, m);
        printf("\nNew inorder traversal of the tree :\n");
        inorder(root);

    }*/


    return 0;
}
