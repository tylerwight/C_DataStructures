#include "datastructures.h"
#include <math.h>


//####################################################
//#############       STACK            ###############
//####################################################

struct stack *stack_create_node( struct stack *input){
    struct stack *newnode = (struct stack*) malloc (sizeof(struct stack));
    if (newnode == NULL){
        printf("error allocating memory");
        exit(1);
    }
    //newnode->data = input->data;
    //printf("newnode created. strlen(input->data) = %ld", strlen(input->data));
    strncpy(newnode->data, input->data, strlen(input->data)+1);
    newnode->next = NULL;
    return newnode;
}

void stack_push(struct stack **head, struct stack *input){
    struct stack *newnode = stack_create_node(input);
    
    newnode->next = *head;
    *head = newnode;
}

void stack_pop(struct stack **head) {
    if (head == NULL || *head == NULL) {
        printf("List is already empty.\n");
        return;
    }

    struct stack *temp = *head;
    *head = temp->next;
    free(temp);
}


void stack_print(struct stack *head){
    struct stack *current = head;
    printf("STACK (Top->Bottom): ");
    while (current != NULL){
        printf("%s <>", current->data);
        current = current->next;
    }
    printf("\n");
}

int stack_has_paren(struct stack *head){
    struct stack *current = head;
    while (current != NULL){
        if (current->data[0] == '(' || current->data[0] == ')'){
            return 1;
        } 
        current = current->next;
    }
    return 0;
}

//####################################################
//#############       QUEUE            ###############
//####################################################


struct queue *queue_create_node( struct queue *input){
    struct queue *newnode = (struct queue*) malloc (sizeof(struct queue));
    //struct queue *newnode = NULL;
    if (newnode == NULL){
        printf("error allocating memory");
        exit(1);
    }

    strncpy(newnode->data, input->data, strlen(input->data)+1);
    newnode->right = NULL;
    newnode->left = NULL;
    return newnode;
    return NULL;
}

void queue_enqueue(struct queue **back, struct queue *input){
    struct queue *newnode = queue_create_node(input);
    newnode->left = *back;
    if (*back != NULL){
        (*back)->right = newnode;
    }

     *back = newnode;
}


void queue_dequeue(struct queue **front) {
    if (front == NULL || *front == NULL) {
        printf("List is already empty.\n");
        return;
    }

    struct queue *temp = *front;
    *front = temp->right;
    free(temp);
}


void queue_print(struct queue *front){
    struct queue *current = front;
    printf("QUEUE (front->back): ");
    while (current != NULL){
        printf(" %s <>", current->data);
        current = current->right;
    }
    printf("\n");
}

struct queue *queue_get_front(struct queue *back){
    struct queue *current = back;
    if (current == NULL) return current;

    while (current->left != NULL){
        current = current->left;
    }
    return current;

}


//####################################################
//#############       Tree             ###############
//####################################################
struct tree *tree_create_node( struct tree *input){
    struct tree *newnode = (struct tree*) malloc(sizeof(struct tree));
    if (newnode == NULL){
        printf("error allocating memory");
        exit(1);
    }

    newnode->data = input->data;
    newnode->parent = input->parent;
    newnode->right = NULL;
    newnode->left = NULL;
    return newnode;
    return NULL;
}

struct tree* tree_insert_node_internal(struct tree *root, struct tree *input, struct tree *parent){
    if (root == NULL) {
        input->parent = parent;
        return tree_create_node(input);
    }

    if (input->data < root->data){
        root->left = tree_insert_node_internal(root->left, input, root);
    } else if (input->data > root->data){
        root->right = tree_insert_node_internal(root->right, input, root);
    }
    return root;
}

struct tree* tree_insert_node(struct tree *root, struct tree *input){
    return tree_insert_node_internal(root, input, NULL);

}


int tree_get_height(struct tree *root){
    int output;
    if (root == NULL){
        return 0;
    }
    int left_height = tree_get_height(root->left);
    int right_height = tree_get_height(root->right);

    if (left_height > right_height){
        output = left_height + 1;
    }else{
        output = right_height + 1;
    }

    return output;
}

int tree_get_cols(int height) {
    if (height == 1)
        return 1;
    return tree_get_cols(height - 1) + tree_get_cols(height - 1) + 1;
}


void tree_print_internal(int **m, struct tree *root, int col, int row, int height){
    if (root == NULL){return;}

    m[row][col] = root->data;
    tree_print_internal(m, root->left, col - pow(2, height - 2), row + 1, height - 1);
    tree_print_internal(m, root->right, col + pow(2, height - 2), row + 1, height - 1);

}

void tree_print(struct tree *root){
    int height = tree_get_height(root);
    int col = tree_get_cols(height);
    int **m = (int**)malloc(height * sizeof(int*));
    for (int i = 0; i < height; i++){
        m[i] = (int*)malloc(col * sizeof(int));
        for (int j = 0; j < col; j++){
            m[i][j] = 0;
        }
    }

    tree_print_internal(m, root, col/2, 0, height);

    for (int i = 0; i < height; i++){
        for (int j = 0; j < col; j++){
            if (m[i][j] == 0){
                printf("  ");
            } else{
                printf("%d ", m[i][j]);
            }
        }
        printf("\n");
    }

    for (int i = 0; i < height; i++){
        free(m[i]);
    }
    free(m);


}






//####################################################
//#############       UTILS            ###############
//####################################################

int count_digits(int num) {
    int count = 0;
    if (num < 0) {
        num = -num;
    }
    if (num == 0) {
        return 1;
    }
    while (num != 0) {
        num /= 10;
        count++;
    }
    
    return count;
}

void double_to_string(double num, char *str) {
    sprintf(str, "%.10f", num);

    char *dot = strchr(str, '.');
    if (dot != NULL) {
        char *end = str + strlen(str) - 1;

        while (end > dot && *end == '0') {
            *end = '\0';
            end--;
        }
        if (end == dot) {
            *end = '\0';
        }
    }
}