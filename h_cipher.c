#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "helpers.h"

#define MAX_MSG_SIZE 1000


typedef struct char_node node_t;

struct char_node
{
    char ch;
    int index;
    node_t *next;
};


node_t * add_char(node_t * head, char c, int index)
{
	node_t *return_node; 
	node_t *temp;

	return_node = malloc(sizeof (return_node));

	return_node->next = NULL;
	return_node->ch = c;
    return_node->index = index;

	if (head == NULL)
	{
		head = return_node;
	}
	else
	{
		temp = head;
		
		while (temp->next != NULL)
		{	
			temp = temp->next;
		}
		temp->next = return_node;

	}
	return head;
}

char add_to_char_array(node_t * head, int index)
{
	while(head->next != NULL)
	{
		if (head->index == index)
		{
			return head->ch;
		}
		else
		{
			head = head->next;
		}
	}
    return 0;
}


int main (int argc, char **argv)
{
    printf("\n\n");
    int key[4];
    key[0] = get_m_val(1);
    key[1] = get_m_val(2);
    key[2] = get_m_val(3);
    key[3] = get_m_val(4);
    printf("\n\n");

    node_t *char_list = NULL;
    int char_counter = 0;

    //for each 'word'
    for (int i=1; i<argc; i++)
    {
        //for each character
        for (int c=0; c<strlen(argv[i]); c++)
        {
            node_t *temp = add_char(char_list, argv[i][c], char_counter);
            char_counter++;
            char_list = temp;
        }
        
        node_t *space = add_char(char_list, ' ', char_counter);
        char_list = space;
        char_counter++;
    }

    //init char array
    char *char_array = malloc(sizeof(char)*char_counter);
    //init converted char (int) array to store the encryption target values
    int *converted_array = malloc(sizeof(int)*char_counter);
    //init empty array for cipher values
    int *cipher_array = malloc(sizeof(int)*char_counter);
    //init empty array for cipher conversion chars
    char *cipher_char_array = malloc(sizeof(char)*char_counter);

    //use the list to append to the proper array
    for (int a=0; a<char_counter-1; a++)
    {
        char_array[a] = add_to_char_array(char_list, a);
    }

    //convert those chars to their corresponding alpha-numeric values
    for (int i=0; i<char_counter-1; i++)
    {
        converted_array[i] = convert_to_int(char_array[i]);
    }

    //perform matrix transformation
    for (int b=0; b<char_counter-1; b+=2)
    {
        matrix_transform(&converted_array[b], &converted_array[b+1], key, &cipher_array[b], &cipher_array[b+1]);
    }

    //convert back to chars
    for (int c=0; c<char_counter-1; c++)
    {
        cipher_char_array[c] = convert_to_char(cipher_array[c]);
    }

    //write to terminal
    printf("Your cipher text is as follows:\n'");
    
    for (int p=0; p<char_counter-1; p++)
    {
        printf("%c", cipher_char_array[p]);
    }
    printf("'\n\n");
}

//TODOS?:
    //OPTIONAL ALPHABET LENGTH
    //VARIABLE MATRIX SIZE (3X3 ETC)
    //COMPARTMENTALISE/CLEAN MAIN