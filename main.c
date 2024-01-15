/*
Name:-
Date:-
Description:-
Sample I/P:-
sample O/P:-
 */
#include "main.h"
slist *head=NULL;
int main(int argc, char **argv)
{
    main_node *hashtable[27]={NULL};

    int option,flag=0;
    char file[20];
    if(file_validation(&head,argc,argv)==SUCCESS)
    {
	printf("Validation of file SUCCESSFULL\n");
	display(head);
	printf("\n");
	while(1)
	{
	    printf("1.Create Database\n2.Display Database\n3.Search Database\n4.Save Database\n5.update Database\n\n");
	    printf("Enter your choice:- ");
	    scanf("%d",&option);
	    switch(option)
	    {
		case 1:
		    printf("Calling Create Database Function\n\n");
		    flag=1;
		    if(create_database(hashtable,&head)==SUCCESS)
		    {
			printf("Created Data_Base SUCCESSFULLY\n\n");
		    }
		    else
		    {
			printf("Create Data_Base UNSUCCESSFULL\n\n");

		    }
		    break;
		case 2:
		    printf("Calling Display Database Function\n\n");
		    if(display_database(hashtable)== SUCCESS)
		    {
			printf("Displayed Database SUCCESSFULLY\n\n");
		    }
		    break;
		case 3:
		    printf("Calling Search Database function\n\n");
		    if(search_database(hashtable) == SUCCESS)
		    {
			printf("Search SUCCESSFULL\n\n");
		    }
		    break;
		case 4:
		    printf("Calling Save Database function\n\n");
		   
		    printf("Enter backup file name : ");
		    scanf("%s",file);
		    if(save_database(hashtable,file) == SUCCESS)
		    {
			printf("Saving SUCCESSFULL\n\n");
		    }
		    break;
		case 5:
		    if(flag==1)
		    {
			printf("Error : Cannot use update mode while in create mode\n\n");
			break;
		    }
		    printf("Enter the backup filename :-");
		    scanf("%s",file);
		    printf("Calling update Database function\n\n");

		    if(update_database(hashtable,file) == SUCCESS)
		    {
			printf("Update SUCCESSFULL\n\n");
		    }
		    break;
		default :
		    printf("Enter a Valid option\n\n");
	    }
	}
    }
    else
    {
	printf("Validation UNSUCCESSFULL\n");
    }
}
