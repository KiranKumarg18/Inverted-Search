/*
Name:-
Date:-
Description:-
Sample I/P:-
sample O/P:-
 */
#include"main.h"
int update_database(main_node **hashtable,char *file)
{
    FILE *ptr = fopen(file, "r");
    if (ptr == NULL) 
    {
	printf("Error: opening file %s\n", file);
	return FAILURE;

    }
    char str[1000];

    while (fgets(str, sizeof(str), ptr)) 
    {
	char *token = strtok(str, ";");
	if (token == NULL || token[0] != '#') 
	{
	    printf("It is not a backup file\n\n");
	    break;
	}

	int index = atoi(token + 1);

	token = strtok(NULL, ";");
	if (token == NULL) 
	{
	    printf("Incomplete data in the file\n");
	    fclose(ptr);
	    return FAILURE;
	}
	char word[20];
	strcpy(word, token);

	token = strtok(NULL, ";");
	if (token == NULL) 
	{
	    printf("Incomplete data in the file\n");
	    fclose(ptr);
	    return FAILURE;
	}
	int file_count = atoi(token);

	main_node *current = hashtable[index];
	if (current == NULL) 
	{
	    current = (main_node *)malloc(sizeof(main_node));
	    if (current == NULL) 
	    {
		printf("Memory allocation failed for main_node\n");
		fclose(ptr);
		return FAILURE;
	    }

	    strcpy(current->word, word);
	    current->file_count = file_count;
	    current->snode_link = NULL;
	    current->main_link = NULL;

	    hashtable[index] = current;
	} 
	else 
	{
	    while (current->main_link != NULL) 
	    {
		current = current->main_link;
	    }
	    main_node *new_main_node = (main_node *)malloc(sizeof(main_node));
	    if (new_main_node == NULL)
	    {
		printf("Memory allocation failed for new_main_node\n");
		fclose(ptr);
		return FAILURE;
	    }

	    strcpy(new_main_node->word, word);
	    new_main_node->file_count = file_count;
	    new_main_node->snode_link = NULL;
	    new_main_node->main_link = NULL;

	    current->main_link = new_main_node;
	    current = new_main_node;
	}

	// Adding sub-nodes if available along with word count.
	token = strtok(NULL, ";");
	while (token != NULL && token[0] != '#') 
	{
	    sub_node *new_sub_node = (sub_node *)malloc(sizeof(sub_node));
	    if (new_sub_node == NULL)
	    {
		printf("Memory allocation failed for new_sub_node\n");
		fclose(ptr);
		return FAILURE;
	    }

	    strcpy(new_sub_node->filename, token);

	    token = strtok(NULL, ";");
	    if (token == NULL || token[0] == '#') 
	    {
		printf("Incomplete data in the file\n");
		fclose(ptr);
		return FAILURE;
	    }
	    new_sub_node->word_count = atoi(token);

	    if (current->snode_link == NULL) 
	    {
		current->snode_link = new_sub_node;
		new_sub_node->sub_link = NULL;
	    } 
	    else 
	    {
		sub_node *temp = current->snode_link;
		while (temp->sub_link != NULL)
		{
		    temp = temp->sub_link;
		}
		temp->sub_link = new_sub_node;
		new_sub_node->sub_link = NULL;
	    }

	    token = strtok(NULL, ";");
	}
    }

    fclose(ptr);
    return SUCCESS;
}
