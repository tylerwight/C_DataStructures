#ifndef DATASTRUCTURES_H
#define DATASTRUCTURES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>

#define MAX_DATA_LENGTH 10

struct stack {
    char data[MAX_DATA_LENGTH];
    struct stack *next;
};
struct queue{
    char data[MAX_DATA_LENGTH];
    struct queue *left;
    struct queue *right;
};

struct tree{
    int data;
    struct tree *parent;
    struct tree *left;
    struct tree *right;
};


//####################################################
//#############       STACK            ###############
//####################################################
struct stack *stack_create_node(struct stack *input);
void stack_push(struct stack **head, struct stack *input);
void stack_pop(struct stack **head);
void stack_print(struct stack *head);
int stack_has_paren(struct stack *head);


//####################################################
//#############       QUEUE            ###############
//####################################################
struct queue* queue_create_node( struct queue *input);
void queue_enqueue(struct queue **back, struct queue *input);
void queue_dequeue(struct queue **front);
void queue_print(struct queue *front);
struct queue* queue_get_front(struct queue *back);


//####################################################
//#############       Tree             ###############
//####################################################
struct tree* tree_create_node(struct tree *input);
struct tree* tree_insert_node(struct tree *root, struct tree *input);
struct tree* tree_insert_node_internal(struct tree *root, struct tree *input, struct tree *parent);
int tree_get_height(struct tree *root);
int tree_get_cols(int height);
void tree_print(struct tree *root);
void tree_populate_print_matrix(int **print_matrix, struct tree *root, int col, int row, int height);



//####################################################
//#############       UTILS            ###############
//####################################################
int count_digits(int num);
void double_to_string(double num, char *str);

#endif