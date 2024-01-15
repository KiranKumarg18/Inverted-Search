/*
Name:-
Date:-
Description:-
Sample I/P:-
sample O/P:-
 */
#include"main.h"
int display_database(main_node **hashtable)
{
    int index;
    printf("Index\tWord\tFilecount\tFilename\twordcount\n");
    for(index=0;index<27;index++)
    {
	if(hashtable[index]!=NULL)
	{

	    main_node *temp;
	    temp=hashtable[index];
	    while(temp!=NULL)
	    {
		sub_node *s_temp;
		s_temp=temp->snode_link;
		printf("%3d\t%s\t%d\t\t",index,temp->word,temp->file_count);
		while(s_temp!=NULL)
		{
		    printf("%s\t%d\n",s_temp->filename,s_temp->word_count);
		    s_temp=s_temp->sub_link;
		}
		temp=temp->main_link;
	    }
	}
    }
}
