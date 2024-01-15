/*
Name:-
Date:-
Description:-
Sample I/P:-
sample O/P:-
 */
#include"main.h"

int search_database(main_node **hashtable)
{
    char id[20];
    int index;
    printf("Enter the word to search :- ");
    scanf("%s",id);
    printf("\n");
    index=toupper(id[0])%65;
    if(hashtable[index]!=NULL)
    {
	main_node *temp;
	temp=hashtable[index];
	while(temp)
	{
	    if(strcmp(id,temp->word)==0)
	    {
		printf("Index : %d ,Word : %s ,Filecount : %d\n\n",index,temp->word,temp->file_count);
		sub_node *s_temp;
		s_temp=temp->snode_link;
		while(s_temp)
		{
		    printf("FileName : ,%s Wordcount : ,%d\n\n",s_temp->filename,s_temp->word_count);
		    s_temp=s_temp->sub_link;
		}
	    }
	    temp=temp->main_link;
	}
    }
    return SUCCESS;
}
