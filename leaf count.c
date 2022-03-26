#include<stdio.h>
#include<stdlib.h>

struct node {
    int key;
    struct node *left, *right;
};

struct node *newNode(int item) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}


struct node* insert(struct node* node, int key) {

    if (node == NULL) return newNode(key);


    if (key < node->key)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);


    return node;
}
struct node * minValueNode(struct node* node) {
    struct node* current = node;


    while (current->left != NULL)
        current = current->left;

    return current;
}
unsigned int getLeafCount(struct node* node) {
    if(node == NULL)
        return 0;
    if(node->left == NULL && node->right==NULL)
        return 1;
    else
        return getLeafCount(node->left)+
               getLeafCount(node->right);
}
unsigned int countNonleaf(struct node* node) {
    if (node == NULL || (node->left == NULL &&
                         node->right == NULL))
        return 0;

    return 1 + countNonleaf(node->left) +
               countNonleaf(node->right);
}



int main() {

    struct node *root = NULL;

    int key,t,m,n,count;
    printf("How many nodes : ");
    scanf("%d",&t);
    n=t;
    printf("values of nodes : \n");
    while(t-->0) {
        scanf("%d",&key);
        root=insert(root,key);
    }

    printf("Inorder traversal of the given tree : \n");
    inorder(root);
    printf("\ntotal number of nodes: %d",n);
    printf("\nLeaf count of the tree is %d", getLeafCount(root));

    printf("\n nonleaf count : %d",countNonleaf(root));

}
