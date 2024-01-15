/*
Name:-
Date:-
Description:-
Sample I/P:-
sample O/P:-
 */
#include"main.h"
int save_database(main_node **hashtable,char *file)
{
    if(strstr(file,".txt"))
    {
	FILE *ptr=fopen(file,"w");

	if(ptr==NULL)
	{
	    printf("Error: opening file %s\n",file);
	    return FAILURE;
	}
	for(int i=0;i<27;i++)
	{
	    if(hashtable[i]!=NULL)
	    {
		main_node *temp = hashtable[i];
		while(temp)
		{
		    fprintf(ptr,"#%d;%s;%d;",i,temp->word,temp->file_count);

		    sub_node *new=temp->snode_link;
		    while(new)
		    {
			fprintf(ptr,"%s;%d;",new->filename,new->word_count);
			new=new->sub_link;
		    }
		    temp=temp->main_link;
		    fprintf(ptr,"#\n");
		}
	    }
	}
	fclose(ptr);
    }
    else
    {
	printf("it is not a .txt %s\n",file);
	return FAILURE;
    }
    return SUCCESS;
}

