#include"sll.h"
#include<string.h>
int save_database(main_node *hashtable[])
{
    char filename[60];
    printf("Enter the filename you want to store the data : ");                                       // get the filename from the user
    scanf("%s",filename);
    FILE *fptr =fopen(filename,"w");                                                                  // open the file to write by using filepointer
    if(fptr==NULL)                                                                                    // check the condition
    {
	printf("Error : File not available\n");
	return FAILURE;
    }
    for(int i=0;i<27;i++)                                                                              // iterate the loop
    {
	main_node *temp = hashtable[i];                                                                // take temp as refernce traverse through the list             
	while(temp!=NULL)
	{
	    fprintf(fptr,"#%d;%s;%d;",i,temp->word,temp->filecount);                                   // store the data inside the file
	    sub_node *temp1 =temp->S_link;
	    while(temp1!=NULL)
	    {
		fprintf(fptr,"%s;%d;",temp1->filename,temp1->wordcount);                               // store the data inside the file
		temp1 = temp1->sub_link;                                                                // update the temp1
	    }
	    fprintf(fptr,"#\n");
	    temp=temp->main_link;                                                                      // update the temp
	}
    }
    printf("-------------------Database saved successfully in %s------------------\n",filename);
    fclose(fptr);
}



