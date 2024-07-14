#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>
#include "datastructures.h"

void stack_example();
void queue_example();
void bst_tree_example();

int main(){
    bst_tree_example();
    // stack_example();
    // queue_example();

}

void bst_tree_example(){
    struct tree *root = NULL;
    struct tree input_item_tree;

    input_item_tree.data = 5;
    root = tree_insert_node(root, &input_item_tree);
    input_item_tree.data = 7;
    root = tree_insert_node(root, &input_item_tree);
    input_item_tree.data = 3;
    root = tree_insert_node(root, &input_item_tree);
    input_item_tree.data = 8;
    root = tree_insert_node(root, &input_item_tree);
    input_item_tree.data = 4;
    root = tree_insert_node(root, &input_item_tree);
    input_item_tree.data = 6;
    root = tree_insert_node(root, &input_item_tree);
    input_item_tree.data = 2;
    root = tree_insert_node(root, &input_item_tree);
    tree_print(root);

    printf("\ntree height: %d\n", tree_get_height(root));
}

void stack_example(){
    struct stack *stacktop = NULL;
    struct stack input_item_stack;
    for (int i = 0; i < MAX_DATA_LENGTH; i++){input_item_stack.data[i] = '\0';}

    strncpy(input_item_stack.data, "hello", 6);
    input_item_stack.data[5] = '\0';
    stack_push(&stacktop, &input_item_stack);

    strncpy(input_item_stack.data, "world", 6);
    input_item_stack.data[5] = '\0';
    stack_push(&stacktop, &input_item_stack);

    stack_print(stacktop);

    stack_pop(&stacktop);
    stack_print(stacktop);

}

void queue_example(){
    struct queue *front = NULL;
    struct queue *back = NULL;
    struct queue input_item_queue;
    for (int i = 0; i < MAX_DATA_LENGTH; i++){input_item_queue.data[i] = '\0';}


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


