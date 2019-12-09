#include <stdio.h>
#include <stdlib.h>
#include "mk_list.h"

struct data {
	int id;
	struct mk_list mk_list_head;
};

void add(int arg, struct mk_list *head)
{
    struct data *headPtr = (struct data *)malloc(sizeof(struct data));
    headPtr->id = arg;
    mk_list_init(&headPtr->mk_list_head);
    mk_list_add(&headPtr->mk_list_head, head);
}

int delete(int arg, struct mk_list *head)
{
    struct mk_list *iter;
    struct data *objPtr;

    mk_list_foreach(iter, head) {
        objPtr = mk_list_entry(iter, struct data,mk_list_head);
        if(objPtr->id == arg) {
            mk_list_del(&objPtr->mk_list_head);
            free(objPtr);
            return 1;
        }
    }

    return 0;
}

void print(struct mk_list *head)
{
    struct mk_list *iter;
    struct data *objPtr;

    mk_list_foreach(iter, head) {
        objPtr = mk_list_entry(iter, struct data,mk_list_head);
        printf("%d ", objPtr->id);
    }
    printf("\n");
}



int main() 
{
    struct mk_list fooHead;
    mk_list_init(&fooHead);
    
    //Make a Linked List with ten nodes
    for(int i=1;i<=10;i++)
        add(i,&fooHead);
    
    printf("Original Linked List:\n");
    print(&fooHead); //print this linked list
    
    printf("Linked List after deleted node 5:\n");
    delete(5, &fooHead); //delete node with id=5
    print(&fooHead); ////print this linked list
}