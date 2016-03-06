//
//  main.c
//  Stack_LinkedList
//
//  Created by chenyufeng on 16/3/6.
//  Copyright © 2016年 chenyufengweb. All rights reserved.
//

/**
 *  使用单链表来模拟栈;
 因为单链表可以非常方便的在第一个节点操作，可以理解为在栈顶操作。和栈的逻辑结构非常像。
 我这里使用带头节点的单链表
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StackFunction.h"

//初始化带头结点的单链表
void createStack(Node **pNode){

    *pNode = (Node *)malloc(sizeof(Node));
    if (*pNode == NULL) {
        printf("%s函数执行，内存分配失败，初始化单链表失败\n",__FUNCTION__);
    }else{

        (*pNode)->next = NULL;
        printf("%s函数执行，带头结点的单链表初始化完成\n",__FUNCTION__);
    }
}

//压入一个元素
void push(Node *pNode,int value){

    Node *pInsert;
    pInsert = (Node *)malloc(sizeof(Node));//需要检测分配内存是否成功 pInsert == NULL  ?
    memset(pInsert, 0, sizeof(Node));
    pInsert->next = NULL;
    pInsert->element = value;

    pInsert->next = pNode->next;
    pNode->next = pInsert;
}

//弹出一个元素
void pop(Node *pNode){

    if (!isEmpty(pNode)) {

        Node *pNext;
        pNext = pNode->next;

        pNode->next = pNext->next;
        free(pNext);
        pNext = NULL;
    }
}

//打印栈元素
void printStack(Node *pNode){

    if (!isEmpty(pNode)) {

        Node *pMove;
        pMove = pNode->next;
        while (pMove != NULL) {
            printf("%d ",pMove->element);
            pMove = pMove->next;
        }
        printf("\n");
    }else{
        printf("栈为空，打印失败\n");
    }
}

//清空栈元素
void destroyStack(Node *pNode){

    Node *pMove;
    pMove = pNode->next;
    while (pMove != NULL) {

        pNode->next = pMove->next;
        free(pMove);
        pMove = pNode->next;
    }
}

//判断栈是否为空
int isEmpty(Node *pNode){
    /**
     *  当只有一个头结点的时候，该链表就为空
     */
    if (pNode->next == NULL) {
        return 1;
    }
    return 0;
}

//判断栈是否已满，由于链表可以动态申请，栈可以不断压入元素，故该方法可以不实现。
int isFull(Node *pNode);

//取栈顶元素
void top(Node *pNode){
    if (!isEmpty(pNode)) {
        printf("栈顶元素为%d\n",pNode->next->element);
    }
}

int main(int argc, const char * argv[]) {

    Node *pList;
    createStack(&pList);

    push(pList, 3);push(pList, 1);push(pList, 9);push(pList, 4);push(pList, 7);
    printStack(pList);

    pop(pList);pop(pList);
    printf("经过pop后栈的元素为:\n");
    printStack(pList);

    top(pList);
    
    destroyStack(pList);
    printStack(pList);
    
    return 0;
}












