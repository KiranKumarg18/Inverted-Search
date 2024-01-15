/*
Name:-
Date:-
Description:-
Sample I/P:-
sample O/P:-
 */
#include "main.h"

int insert_at_last(slist **head,char *argv)
{
    slist *ptr=malloc(sizeof(slist)),*temp;
    temp=*head;
    strcpy(ptr->name,argv);
    ptr->link=NULL;
    if(*head == NULL)
    {
	*head=ptr;
	return SUCCESS;
    }
    while(temp->link!=NULL)
    {
	if(strcmp(temp->name,argv)==0)
	{
	    printf("error :File Already present\n");
	    return FAILURE;
	}
	else
	    temp=temp->link;
    }
    temp->link=ptr;
    return SUCCESS;
}
void display(slist *head)
{
    if (head == NULL)
    {
	printf("INFO : List is empty\n");
    }
    else
    {
	printf("head -> ");
	while (head)
	{
	    printf("%s -> ", head -> name);
	    head = head -> link;
	}

	printf("NULL\n");
    }
}
