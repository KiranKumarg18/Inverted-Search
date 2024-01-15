/*
Name:-
Date:-
Description:-
Sample I/P:-
sample O/P:-
 */
#include "main.h"

int create_database(main_node **hashtable,slist **head)
{
    int index;
    main_node *m_node,*m_ptr;
    sub_node *s_node,*s_ptr,*ms_ptr;
    slist *temp;
    temp=*head;
    while(temp)
    {
	FILE *fptr;
	char wd[20];
	fptr=fopen(temp->name,"r");

	while(fscanf(fptr,"%s",wd)==1)
	{
	    index=toupper(wd[0])%65;
	    if(hashtable[index]==NULL)
	    {
		m_node=malloc(sizeof(main_node));
		s_node=malloc(sizeof(sub_node));

		m_node->file_count=1;
		strcpy(m_node->word,wd);
		m_node->snode_link=s_node;
		m_node->main_link=NULL;

		s_node->word_count=1;
		strcpy(s_node->filename,temp->name);
		s_node->sub_link=NULL;
		hashtable[index]=m_node;
	    }
	    else
	    {
		while(m_node)
		{
		    if(strcmp(m_node->word,wd)==0)
		    {
			s_node=m_node->snode_link;
			while(s_node)
			{
			    if(strcmp(s_node->filename,temp->name)==0)
			    {
				s_node->word_count=s_node->word_count+1;
				break;
			    }
			    else
			    {
				s_node=s_node->sub_link;
			    }
			}
			if(s_node == NULL)
			{
			s_ptr=malloc(sizeof(sub_node));
			if (s_ptr == NULL) 
			{
                            // Handle memory allocation error
                            fclose(fptr);
                            return -1;
                        }

			s_ptr->word_count=1;
			strcpy(s_ptr->filename,temp->name);
			s_ptr->sub_link=NULL;

			s_node = m_node->snode_link;
			while(s_node->sub_link!=NULL)
			{
			    s_node = s_node->sub_link;
			}
			s_node->sub_link = s_ptr;
			}

			m_node->file_count=m_node->file_count+1;
			break;
		    }
		    else
		    {
			m_node=m_node->main_link;
		    }
		}
		if(m_node == NULL)
		{
		m_ptr=malloc(sizeof(main_node));
		ms_ptr=malloc(sizeof(sub_node));

		m_ptr->file_count=1;
		strcpy(m_ptr->word,wd);
		m_ptr->snode_link=ms_ptr;
		m_ptr->main_link=NULL;

		m_node=hashtable[index];
		while(m_node->main_link!=NULL)
		{
		    m_node=m_node->main_link;
		}
		m_node->main_link = m_ptr;

		ms_ptr->word_count=1;
		strcpy(ms_ptr->filename,temp->name);
		ms_ptr->sub_link=NULL;
		}
	    }

	}
	rewind(fptr);
	temp=temp->link;

	//printf("In file %d, %d\n",m_node->file_count,s_node->word_count); 
    }
    return SUCCESS;

}
