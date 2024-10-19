#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

void parse(int, node*);

void parse(int option, node* p){
    int n, dp;

    if (option < 0){
        return;
    }
    else if (option == 0){
        printf("enter data item: ");
        scanf("%d", &dp);
        append(dp, p);
    }
    else if (option == 1){
       pop(p); 
    }
    else if (option == 2){
        printf("enter index (starts at 1): ");
        scanf("%d", &n);
        if (n < 1){
            printf("invalid index\n");
            return;
        }
        out(n, p);
    }
    else if (option == 3){
        printf("enter index (starts at 1): ");
        scanf("%d", &n);
        if (n < 1){
            printf("invalid index\n");
            return;
        }
        printf("enter data item: ");
        scanf("%d", &dp);
        
        insert(dp, n, p);
    }
    else if (option == 4){
        printf("enter index (starts at 1): ");
        scanf("%d", &n);
        if (n < 1){
            printf("invalid index\n");
            return;
        }
        rmnode(n, p);
    }
    else if (option == 5){
        printf("enter item to search: ");
        scanf("%d", &dp);
        search(dp, p);
    }
    else{
        printlist(p);
    }

    char *discard = (char *)malloc(sizeof(char) * 1024), *discard2 = (char *)malloc(sizeof(char));
    printf("press enter to continue");
    scanf("%[^\n]c", discard);
    scanf("%c", discard2);
    scanf("%c", discard2);
    if (*discard2 != '\n'){
        scanf("%[^\n]c", discard);
        scanf("%c", discard2);
    }
    free(discard);
    discard = NULL;
    discard2 = NULL;
}

int main() {
	int option;
    node head;
    head.data = 0;
    head.index = 0;
    head.next = NULL;

    do{
        printf("\nenter an option:\n0 to add to the end of the list\n1 to delete the last item\n2 to print the item at an index n\n3 to add at a specific index\n4 to delete an item at an index\n5 to search if an item exists and return all indexes of that item\nany negative no. to quit\nprints the entire list for any other integer\noption: ");
        scanf("%d", &option);

        parse(option, &head);
        printf("\n----------------------------------------------------\n");
    } while (option >= 0);

	return 0;
}
