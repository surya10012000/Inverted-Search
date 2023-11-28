#include"sll.h"

void display_database(main_node *hashtable[])
{
    printf("____________________________________________________________________________________________________________________\n");     
    printf("[Index]\t\tWord\t\t   filecount\t\tfilename\t\twordcount\n");
    printf("____________________________________________________________________________________________________________________\n");
    for(int i=0;i<27;i++)                                                                                                                 // iterate the outer loop
    {
	main_node *temp = hashtable[i];                                                                                                  // take temp as reference traverse through the list
	while(temp)
	{
	    printf("[%d]\t\t%s\t\t\t%d", i,temp->word,temp->filecount);
	    sub_node * sub = temp->S_link;                                                                                               // take sub as refernce traverse through the list
	    while(sub!=NULL)
	    {
		printf("\t\t%s\t\t%d",sub->filename,sub->wordcount);
		sub=sub->sub_link;                                                                                                      // update the sub
	    }
	    printf("\n");
	    temp=temp->main_link;                                                                                                       // update the temp
	}
    }
    printf("____________________________________________________________________________________________________________________\n");   
}

