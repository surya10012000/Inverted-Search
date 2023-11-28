#include"sll.h"
#include<string.h>

int update_validation(main_node *hashtable[],char *filename)
{
    FILE *fptr =fopen(filename,"r");                                                 // open the file in read mode
    if(fptr!=NULL)                                                   
    {
	fseek(fptr,0,SEEK_END);                                                      // move the pointer to the EOF to get the size
	int check=ftell(fptr);
	if(check != 0)
	{
	    if(!strcmp((strstr(filename,".")),".txt"))                               // compare the file given is .txt file or not
	    {
		rewind(fptr);                                                        // move the cursor to the starting postion
		if(update_database(fptr,hashtable)== SUCCESS)                        // function calling
		{
		    printf("UPDATED SUCCESS\n");
		}
		else
		{
		    printf("Error : updation failed");
		}
	    }
	    else
	    {
		printf("The given %s is not in  .txtfile\n",filename);
		return FAILURE;
	    }
	}
	else
	{
	    printf("Error : the given %s file is empty\n",filename);
	    return FAILURE;
	}
    }
    else
    {
	printf("The given %s file is not present in the list\n",filename);
	return FAILURE;
    }
}

int update_database(FILE *fptr,main_node *hashtable[ ])
{
    char data[40];				                                                        // declare the variable
    int word_count,file_count,index=0;
    char word[60];
    char file_name[40];					
    while(fscanf(fptr,"%s",data) != EOF)                                                              // fetch the data one by one
    {
	if(data[0] == '#')		                                                             // check the condition	
	{
	    index=atoi(strtok(&data[1],";"));
	    strcpy(word,(strtok(NULL,";")));
	    file_count=atoi(strtok(NULL,";"));		

	    if(hashtable[index]== NULL )                                                            // check whether hashtable[index] is null or not
	    {
		main_node *main_new =malloc(sizeof(main_node));	                                    // allocate the memory for mainnode	
		if(main_new == NULL)                                                                //  check the node is created or not
		    return FAILURE;
		main_new->filecount = file_count;	                                              // update the filecount,word,main_link and S_link in the mainnode           
		strcpy(main_new->word,word);
		main_new->main_link=NULL;
		main_new->S_link=NULL;
		strcpy(file_name,(strtok(NULL,";")));
		word_count = atoi(strtok(NULL,";"));
		sub_node *sub_new=malloc(sizeof(sub_node));                                          // allocate the memory for the subnode
		if(sub_new == NULL)                                                                  // check the node is  created or not
		    return FAILURE;

		strcpy( sub_new->filename, file_name);                                               // update the filename,wordcount and sublink in the subnode
		sub_new->wordcount = word_count;
		sub_new->sub_link=NULL;
		main_new->S_link= sub_new;                                                          // update the main_new->S_link

		sub_node *temp=sub_new;                                                             // take temp as reference traverse through the list
		while(--file_count)				
		{
		    sub_node *sub_new=malloc(sizeof(sub_node));                                      // allocate the memory for subnode
		    if(sub_new == NULL)
			return FAILURE;

		    strcpy(file_name,(strtok(NULL,";")));
		    word_count = atoi(strtok(NULL,";"));
		    strcpy( sub_new->filename, file_name);
		    sub_new->wordcount = word_count;
		    sub_new->sub_link=NULL;
		    temp->sub_link= sub_new;                                                          // update the temp->sub_link
		    temp=sub_new;                                                                     // update the temp


		}

		hashtable[index]=main_new;				                              //update the hashtable[index]
	    }
	    else if(hashtable[index]!=NULL)
	    {
		main_node *tem=hashtable[index];                                                     // take the tem as refrence traverse through the list
		main_node *prev=NULL;	
		while(tem != NULL)				
		{
		    prev=tem;					                                     // update the prev
		    tem=tem->main_link;                                                              // update the tem
		}
		main_node *main_new =malloc(sizeof(main_node));                                      // allocate the memory for mainnode
		if(main_new == NULL)
		    return FAILURE;				

		main_new->filecount = file_count;                                                    // update the filecount,word,main_link,S_link
		strcpy(main_new->word,word);
		main_new->main_link=NULL;			
		main_new->S_link=NULL;
		strcpy(file_name,(strtok(NULL,";")));
		word_count = atoi(strtok(NULL,";"));
		sub_node *sub_new=malloc(sizeof(sub_node));                                         // allocate the memory for subnode
		if(sub_new == NULL)
		    return FAILURE;
  
       		strcpy( sub_new->filename, file_name);                                             // update the wordcount ,sublink and filename in subnode 
		sub_new->wordcount = word_count;
		sub_new->sub_link=NULL;
		main_new->S_link= sub_new;

		sub_node *temp=sub_new;
		while(--file_count)
		{
		    sub_node *sub_new=malloc(sizeof(sub_node));                                    // allocate the memory for the subnode
		    if(sub_new == NULL)
			return FAILURE;

		    strcpy(file_name,(strtok(NULL,";")));
		    word_count = atoi(strtok(NULL,";"));
		    strcpy( sub_new->filename, file_name);
		    sub_new->wordcount = word_count;
		    sub_new->sub_link=NULL;
		    temp->sub_link= sub_new;                                                      //update the temp->sub_link
		    temp=sub_new;                                                                 // update the temp


		}
		prev->main_link=main_new;					                  // update the prev->main_link

	    }
	}
	else						
	{
	    printf("Invalid file format\n");
	    return FAILURE;
	}

    }
    return SUCCESS;
}


