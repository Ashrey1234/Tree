#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

struct node* Insert(struct node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = Insert(root->left, data);
    } else if (data > root->data) {
        root->right = Insert(root->right, data);
    }
    return root;
}

struct node* MinValue(struct node* root) {
    while (root && root->left != NULL) {
        root = root->left;
    }
    return root;
}

struct node* Remove(struct node* root, int data) {
    if (root == NULL) return root;
    if (data < root->data) {
        root->left = Remove(root->left, data);
    } else if (data > root->data) {
        root->right = Remove(root->right, data);
    } else {
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        struct node* temp = MinValue(root->right);
        root->data = temp->data;
        root->right = Remove(root->right, temp->data);
    }
    return root;
}

int search(struct node* root, int data) {
    if (root == NULL) return 0;
    if (root->data == data) return 1;
    if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

void InOrder(struct node* root) {
    if (root != NULL) {
        InOrder(root->left);
        printf("%d ", root->data);
        InOrder(root->right);
    }
}

void PreOrder(struct node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

void PostOrder(struct node* root) {
    if (root != NULL) {
        PostOrder(root->left);
        PostOrder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    struct node* root = NULL;
    int choice=1, value;

    while (choice==1) {
        printf("\n8 Binary Tree Operations:\n");
        printf("1 Insert\n");
        printf("2 Delete\n");
        printf("3 Search\n");
        printf("4 Find Minimum Value\n");
        printf("5 Find Maximum Value\n");
        printf("6 InOrder Traversal\n");
        printf("7 PreOrder Traversal\n");
        printf("8 PostOrder Traversal\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert into the tree: ");
                scanf("%d", &value);
                root = Insert(root, value);
                printf("%d inserted into the tree.\n", value);
                break;

            case 2:
                printf("Enter value to delete from the tree: ");
                scanf("%d", &value);
                root = Remove(root, value);
                printf("%d deleted from the tree.\n", value);
                break;

            case 3:
                printf("Enter value to search in the tree: ");
                scanf("%d", &value);
                if (search(root, value)) {
                    printf("%d is present in the tree.\n", value);
                } else {
                    printf("%d is not present in the tree.\n", value);
                }
                break;

            case 4:
                if (root) {
                    printf("Minimum value in the tree: %d\n", MinValue(root)->data);
                } else {
                    printf("The tree is empty.\n");
                }
                break;

            case 5:
                if (root) {
                    struct node* current = root;
                    while (current->right != NULL) {
                        current = current->right;
                    }
                    printf("Maximum value in the tree: %d\n", current->data);
                } else {
                    printf("The tree is empty.\n");
                }
                break;

            case 6:
                printf("InOrder Traversal: ");
                InOrder(root);
                printf("\n");
                break;

            case 7:
                printf("PreOrder Traversal: ");
                PreOrder(root);
                printf("\n");
                break;

            case 8:
                printf("PostOrder Traversal: ");
                PostOrder(root);
                printf("\n");
                break;
        }

        printf("\nDo you want to continue? (1/0): ");
        scanf("%d", &choice);
   
    }
    return 0;
}
