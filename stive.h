#ifndef STIVE_H
#define STIVE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char val;
    struct Node* next;
}Node;

char top(Node* );
void push(Node** , char );
char pop(Node** );
int isEmpty(Node* );
void deleteStack(Node** );
void correctlyClosedParentheses();

#endif