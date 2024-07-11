#include "datastructures.h"


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