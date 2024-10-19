#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

void append(int d, node* p){
    int i = 1;
    node *w = p, *new = (node*)malloc(sizeof(node)), *temp;
    new->data = d;
    new->next = NULL;

    while (w->next != NULL){
        temp = w->next;
        w = temp;
        i++;
    }

    new->index = i;
    w->next = new;
    printf("node added\n");
}

void pop(node *p){
    node *w = p, *temp, *sl = p;

    while (w->next != NULL){
        sl = w;
        temp = w->next;
        w = temp;
    }

    if (w->index != 0){
        sl->next = NULL;
        free(w);
        printf("node deleted\n");
    }
    else{
        printf("no nodes exist\n");
    }
}

void out(int n, node *p){
    node *w = p, *temp;

    while ((w->index != n) && (w->next != NULL)){
        temp = w->next;
        w = temp;
    }

    if (w->index == n){
        printf("data at %d is %d\n", w->index, w->data);
    }
    else{
        printf("index does not exist\n");
    }
}

void insert(int d, int n, node *p){
    node *w = p, *sl, *temp, *new = (node *)malloc(sizeof(node));
    new->data = d;
    new->index = n;

    while ((w->index != n) && (w->next != NULL)){
        sl = w;
        temp = w->next;
        w = temp;
    }

    if ((w->index != n) && (w->index != (n-1))){
        printf("node cannot be inserted, too high or invalid index\n");
    }
    else if (w->index == (n-1)){
        new->next = NULL;
        w->next = new;
        printf("node inserted\n");
    }
    else {
        new->next = w;
        sl->next = new;
        w->index += 1;
        printf("node inserted\n");
    }
}

void rmnode(int n, node *p){
    node *w = p, *temp, *sl;

    while ((w->index != n) && (w->next != NULL)){
        sl = w;
        temp = w->next;
        w = temp;
    }

    if (w->index == n){
        sl->next = w->next;
        free(w);
        printf("node removed\n");
    }
    else{
        printf("the index does not exist\n");
    }
}

void search(int d, node *p){
    node *w = p, *temp;
    int flag = 0;

    while (w->next != NULL){
        if ((w->data == d) && (w->index != 0)){
            flag = 1;
            break;
        }
        else {
            temp = w->next;
            w = temp;
        }
    }

    if (w->index == 0){
        printf("no nodes exist\n");
        return;
    }

    if (((flag == 1) || (w->data == d)) && (w->index != 0)){
        printf("data item %d is found at index(es):\n", d);
        printf("%d\n", w->index);

        while (w->next != NULL){
            if (w->data == d){
                printf("%d\n", w->index);
            }
            temp = w->next;
            w = temp;
        }

        if (w->data == d){
            printf("%d\n", w->index);
        }
    }
    else{
        printf("no matches found\n");
    }
}

void printlist(node *p){
    node *w = p, *temp;

    printf("list:\n\n");

    while (w->next != NULL){
        if (w->index != 0){
            printf("%d\t:\t%d\n", w->index, w->data);
        }
        temp = w->next;
        w = temp;
    }

    if (w->index != 0){
        printf("%d\t:\t%d\n", w->index, w->data);
    }

    printf("\nlist end\n");
}
