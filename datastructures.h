#ifndef DATASTRUCTURES_H
#define DATASTRUCTURES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>



struct stack {
    char data[10];
    struct stack *next;
};
struct queue{
    char data[10];
    struct queue *left;
    struct queue *right;
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
//#############       UTILS            ###############
//####################################################
int count_digits(int num);
void double_to_string(double num, char *str);

#endif