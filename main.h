#ifndef SLL
#define SLL

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdarg.h>
#include<ctype.h>

#define SUCCESS 0
#define FAILURE -1

typedef struct data
{
    char name[10];
    struct data *link;
}slist;
typedef struct mnode
{
    int file_count;
    char word[20];
    struct snode *snode_link;
    struct mnode *main_link;
}main_node;

typedef struct snode
{
    int word_count;
    char filename[10];
    struct snode *sub_link;
}sub_node;

int insert_at_last(slist **head,char *);
int file_validation(slist **head,int, char **);
void display(slist *head);
int display_database(main_node **);
int search_database(main_node **);
int save_database(main_node **,char *);
int update_database(main_node **,char *);
int create_database(main_node **,slist **head);
#endif
