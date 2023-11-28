#include "sll.h"
#include <string.h>
void search_database(main_node *hashtable,char *word,int num)
{
    if(hashtable == NULL)                                                                                            // check the condition
    {
	printf("Error : search word is not found in list and list is empty\n");
	return;
    }
    while(hashtable)
    {
	if(!(strcmp(hashtable->word,word)))                                                                         // check the word is similar or not
	{
	    printf("-------------------word %s is present in %d file-----------------\n",hashtable->word,hashtable->filecount);
	    sub_node *temp=hashtable->S_link;
	    while(temp)
	    {
		printf("Index[%d] the word %s present in the %s  file and wordcount  is %d times \n",num,hashtable->word,temp->filename,temp->wordcount);
		temp=temp->sub_link;                                                                               // update the temp
	    }
	    return;
	}
	hashtable=hashtable->main_link;                                                                          // update the hashtable
    }
    printf("Error : search word is not found in list \n");
}

