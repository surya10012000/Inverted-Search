#include"sll.h"
#include<stdio.h>
#include<string.h>
#include<ctype.h>
int create_database( Slist *head,main_node*hashtable[])
{
    Slist *temp = head;
    while(temp)                                 
    {
	FILE *fptr=fopen(temp->data,"r");                                               // file is open by using filepointer
	char*filename = temp->data;
	char word[45];
	while(fscanf(fptr,"%s",word)!=EOF)                                              // fetch the word one by one from the file
	{
	    int index = tolower((word[0])%97);                                          // get the index value
	    if(!(index>=0 && index<=25))
		index=26;
	    if(hashtable[index]==NULL)
	    {
		create_data(&hashtable[index],word,filename);                          // calling the function to create the data
	    }
	    else if(hashtable[index]!=NULL)
	    {
		insert_data(&hashtable[index],word,filename);                          // calling the fuction to insert the data

	    }
	}
	temp=temp->link;                                                               // update the temp
	printf("--------created database successfully for %s file--------\n",filename);
    }
}

int create_data(main_node **head,char *data,char *fname)
{
    main_node *main_new = malloc(sizeof(main_node));                                           // allocate the memory for mainnode
    if(main_new == NULL)                                                                       // check the node is created or not
	return FAILURE;
    main_new->filecount =1;
    strcpy(main_new->word,data);
    main_new->S_link = NULL;
    main_new->main_link = NULL;


    sub_node *sub_new = malloc(sizeof(sub_node));                                             // allocate the memory for subnode
    if(sub_new == NULL)
	return FAILURE;
    sub_new->wordcount = 1;
    strcpy(sub_new->filename,fname);
    sub_new->sub_link = NULL;
    main_new->S_link=sub_new;
    *head = main_new;
    return SUCCESS;
} 
int insert_data(main_node **head,char *data,char *fname)
{
    main_node *main_prev;
    main_node *main_temp;
    sub_node *sub_prev;
    sub_node *sub_temp;
    main_temp = *head;
    while(main_temp!=NULL)                                                            
    {
	main_prev = main_temp;                                                                // update the main_prev
	if(strcmp(main_temp->word,data)==0)                                                   // check the word is same or not          
	{
	    sub_temp=main_temp->S_link;                                                       // take the sub_temp to traverse through the list
	    while(sub_temp != NULL)
	    {
		sub_prev=sub_temp;                                                           // update the sub_prev
		if(strcmp(sub_temp->filename,fname)==0)                                      // compare the file name if it is same just increase the wordcount    
		{
		    (sub_temp->wordcount)++;
		    return SUCCESS;
		}
		sub_temp =sub_temp->sub_link;                                                // update the sub_temp
	    }
	    (main_temp->filecount)++;                                                       // increase the file count
	    sub_node *new =malloc(sizeof(sub_node));                                       // create the sub_node
	    if(new == NULL)
		return FAILURE;
	    new->wordcount =1;
	    strcpy(new->filename,fname);
	    new->sub_link = NULL;
	    sub_prev ->sub_link=new;
	    // (main_temp->filecount)++;
	    return SUCCESS;
	}
	main_temp=main_temp->main_link;                                                   // update the main_temp
    }
    main_node *main_new=malloc(sizeof(main_node));                                        // allocate the memory for main node                            
    main_new->filecount=1;
    strcpy(main_new->word,data);
    main_new->S_link = NULL;
    main_new->main_link = NULL;


    sub_node *sub_new = malloc(sizeof(sub_node));                                          // allocate the memory for sub node
    if(sub_new == NULL)
	return FAILURE;
    sub_new->wordcount = 1;
    strcpy(sub_new->filename,fname);
    sub_new->sub_link = NULL;
    main_new->S_link = sub_new;
    main_prev->main_link=main_new;
    return SUCCESS;
}







