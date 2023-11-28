#include "sll.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int insert_at_last(Slist **head,char *data)
{
    Slist *temp1 = *head;
    while(temp1)
    {
	if(strcmp(temp1 -> data,data)==0)                            // check the data is similar or not
	{
	    printf("Duplicate found\n");
	    return DUPLICATE_FOUND;
	}
	temp1 = temp1 -> link;
    }
    Slist *new =malloc(sizeof(Slist));                              // allocate the memory
    if(new == NULL)                                                 // check the new is created or not
	return FAILURE;
    strcpy(new ->data,data);                                       // copy the data
    new->link = NULL;
    if(*head == NULL)                                             
    {
	*head = new;                                                // update the head
	return SUCCESS;
    }
    Slist *temp = *head;                                            // take temp as refernce traverse through the list
    while(temp->link!=NULL)
	temp=temp->link;                                            // update the temp
    temp->link = new;
    return SUCCESS;
}


    

