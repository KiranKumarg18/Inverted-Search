/*
Name:-
Date:-
Description:-
Sample I/P:-
sample O/P:-
 */
#include "main.h"
int file_validation(slist **head,int argc,char **argv)
{
  
    if(argc>1)
    {
	int i,size;
	for(i=1;argv[i]!=NULL;i++)
	{
	    printf("Reading file %d successfull\n",i);
	    char *present=strstr(argv[i],".txt");
	    if(present!=NULL)
	    {
		printf("-----It is a .txt file-----\n");
		FILE *fptr;
		fptr=fopen(argv[i],"r");
		if(fptr== NULL)
		    return FAILURE;
		fseek(fptr,0,SEEK_END);
		size=ftell(fptr);
		rewind(fptr);

		if(size==0)
		{
		    printf("FILE is Empty\n");
		}
		else
		{
		    printf("CALLING the function\n");
    		    if(insert_at_last(head,argv[i])==SUCCESS)
		    {
			printf("Added file name to DATABASE Successfully\n\n");
		    }
		    else
		    {
			printf("File name already Exists\n\n");
		    }

		}

	    }
	    else
	    {
		printf("It is not a .txt file\n");
	    }
	}


	if(i==argc)
	{
	    return SUCCESS;
	}
	else
	{
	    return FAILURE;
	}
    }
    else
    {
	printf("Please Enter command line arguments\n");
    }
}
