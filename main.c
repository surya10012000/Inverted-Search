#include"sll.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

/*
NAME      : SURYA . S
DATE      : 26.09.2023
TITLE     : Inverted search
sample O/P: successfully file1.txt insert at last
            successfully file2.txt insert at last
            choose the option
            *********************
            1. create database
            2. Display database
            3. search database
            4. save database
            5. update database
            **********************
            Enter your choice : 1
            --------created database successfully for file1.txt file--------
	    --------created database successfully for file2.txt file--------
            Do you want to continue (y/n) : y
            choose the option
	    *********************
	    1. create database
	    2. Display database
	    3. search database
	    4. save database
	    5. update database
	    **********************
	    Enter your choice : 3
	    Enter the word to search:  apple
	    word apple is present in 2 file
	    In File : file1.txt     1 times
	    In File : file2.txt     3 times																				 
	    Do you want to continue (y/n) : y
	    choose the option
	    *********************
	    1. create database
	    2. Display database
            3. search database
            4. save database
	    5. update database
	    *********************
	    Enter your choice : 4
sample I/P: Enter the filename you want to store the data : nu1.txt
	    -------------------Database saved successfully in nu1.txt------------------
	    Do you want to continue (y/n) : n

*/
int main(int argc,char *argv[])
{
    //system("clear");
    Slist *head=NULL;
    if(argc > 1)                                                                       
    {
	for(int i=1;i<argc;i++)                                                                 // iterate the loop
	{
	    if(strstr(argv[i],".txt"))                                                        // check whether the file is .txt format or not
	    {
		FILE *fptr=fopen(argv[i],"r");                                                // open the file using file pointer
		fseek(fptr,0,SEEK_END);                                                       // check the file size
		int val= ftell(fptr);
		if(val!=0)                                                                    // check the condition
		{
		    char ret = insert_at_last(&head,argv[i]);                                 // calling the function to insert
		    if(ret== FAILURE)
			printf("INFO : insertion FAILURE \n");
		    else if(ret == SUCCESS)
			printf("successfully %s insert at last \n",argv[i]);
		}
		else
		{
		    printf("Error :file is empty \n");
		}
	    }
	    else
	    {
		printf("Error  :file is not a .txt format \n");
	    }
	}
    }
    else
    {
	printf("Error :please pass the argument\n");
    }
   main_node *hashtable[27]={NULL};                                                          // create the hashtable
   int choice;
   char word[50];
   char filename[50];
   char option;
   int index;
   do
   {
       printf("choose the option \n ********************* \n 1. create database \n 2. Display database \n 3. search database \n 4. save database \n 5. update database \n **********************\n Enter your choice : ");
       scanf("%d",&choice);                                                                   // get the choice from the user
       switch (choice)
       {
	   case 1:
	       create_database(head,hashtable);
	       break;
	   case 2:
	       display_database(hashtable);
	       break;
	   case 3:
	       printf("Enter the word to search:  ");
	       scanf("%s",word);
	       index=tolower((word[0])%97);
	       search_database(hashtable[index],word,index);
	       break;
	   case 4:
	       save_database(hashtable);
	       break;
	   case 5:
	       printf("enter the filename do you want to insert in database : ");
	       scanf("%s",filename);
	       update_validation(hashtable,filename);   
	       break;
	   default:
	       printf("ERROR : please enter the choice between 1 to 5\n");
	       break;
	   
       }
       printf("Do you want to continue (y/n) : ");
       scanf(" %c",&option);

   }while('y'== option|| 'Y'== option);

}





