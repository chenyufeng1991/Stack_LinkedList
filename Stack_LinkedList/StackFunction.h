//
//  StackFunction.h
//  Stack_LinkedList
//
//  Created by chenyufeng on 16/3/6.
//  Copyright © 2016年 chenyufengweb. All rights reserved.
//

#include <stdio.h>

typedef int elemType;
typedef struct NodeList{

    int element;
    struct NodeList *next;
}Node;

void createStack(Node **pNode);
void destroyStack(Node *pNode);
void push(Node *pNode,int value);
void pop(Node *pNode);
void top(Node *pNode);
int isEmpty(Node *pNode);
int isFull(Node *pNode);
void printStack(Node *pNode);
