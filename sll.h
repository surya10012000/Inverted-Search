#ifndef SLL_H
#define SLL_H
#include<stdio.h>
#include<stdlib.h>

#define SUCCESS 0
#define FAILURE -1
#define LIST_EMPTY -2
#define DUPLICATE_FOUND -3
typedef struct node
{
    char data[20];
    struct node *link;
}Slist;
typedef struct sub_node
{
    int wordcount;
    char filename[30];
    struct sub_node *sub_link;
}sub_node;

typedef struct main_node
{
    char word[30];
    int filecount;
    struct main_node *main_link;
    sub_node *S_link;
}main_node;

int insert_at_last(Slist **head , char* data);
int create_database(Slist *head, main_node *hashtable[]);
void search_database(main_node *hashtable,char *word,int num);
void display_database(main_node *hashtable[]);
int insert_data(main_node **head,char *data,char *fname);
int create_data(main_node **head,char *data,char *fname);
int save_database(main_node *hashtable[]);
int update_database(FILE *fptr,main_node *hashtable[]);
 int update_validation(main_node *hashtable[],char *filename) ;
#endif

