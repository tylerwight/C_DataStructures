#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "datastructures.h"

double eval_rpn(char *expression);
bool infix_to_postfix(char *expression, char *output);
double get_full_number(char *input);
void double_to_string(double num, char *str);
int get_num_len(char *input);
bool is_valid_operator(char *input){
    return *input == '+' || *input == '-' || *input == '*' || *input == '/';
}


int main(){
    //stack
    struct stack *stacktop = NULL;
    struct stack input_item_stack;

    strncpy(input_item_stack.data, "hello", 6);
    input_item_stack.data[5] = '\0';
    stack_push(&stacktop, &input_item_stack);

    strncpy(input_item_stack.data, "world", 6);
    input_item_stack.data[5] = '\0';
    stack_push(&stacktop, &input_item_stack);

    stack_print(stacktop);

    stack_pop(&stacktop);
    stack_print(stacktop);


    //queue
    struct queue *front = NULL;
    struct queue *back = NULL;
    struct queue input_item_queue;


    strncpy(input_item_queue.data, "hello", 6);
    input_item_queue.data[5] = '\0';
    queue_enqueue(&back, &input_item_queue);
    front = queue_get_front(back);
    
    strncpy(input_item_queue.data, "world", 6);
    input_item_queue.data[5] = '\0';
    queue_enqueue(&back, &input_item_queue);

    queue_print(front);

    
    queue_dequeue(&front);
    queue_print(front);


}





