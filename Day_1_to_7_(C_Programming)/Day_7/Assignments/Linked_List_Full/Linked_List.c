#include <stdio.h>
#include <stdlib.h>
#include "Linked_List.h"


// defining crucial global variables
node* head = NULL;
s32 list_size = 0;

static node* createNode(void)
{
	return (node*)malloc(sizeof(node));
}

void swap_nodes(node* node1, node* node2)
{
	(node1->data) ^= (node2->data);
	(node2->data) ^= (node1->data);
	(node1->data) ^= (node2->data);
}


s8 linkedList_addNode_atIndex(s32 value, u16 index)
{
	// check index validity
	//if ((index < 1) || (index > list_size))
		//return -1; // indicates that index is out of bounds
	
	node* dumDumNode = NULL;
	dumDumNode = createNode();
	
	// check if node was created successfully
	if (dumDumNode == NULL)
		return -2; // indicates that memory allocation was not successful
	
	dumDumNode->data = value;
	dumDumNode->next_node = NULL;
	
	if(head == NULL) // first node in the list
	{
		head = dumDumNode;
	}
	else
	{
		node *temp = head;
		node* temp2 = NULL;
		
		while (--index) // keep looping until you reach the node @ index
			temp = (temp->next_node);
		
		// temp is now the node @ the index
		// temp->next_node = dumDumNode
		// dumDumNode->next_node = *old node's next node*
		temp2 = temp->next_node;
		temp->next_node = dumDumNode;
		dumDumNode->next_node = temp2;
	}
	
	list_size++;
	
	return 1; // indicates normal behaviour
}

s8 linkedList_addNode_first(s32 value)
{
	return linkedList_addNode_atIndex(value, 1);
}

s8 linkedList_addNode_last(s32 value)
{
	return linkedList_addNode_atIndex(value, list_size);
}

// Remove Node
s8 linkedList_removeNode_atIndex(u16 index)
{
	// check index validity
	//if ((index < 1) || (index > list_size))
		//return -1; // indicates that index is out of bounds
	
	
	
	if (list_size == 0)
		return -3; // trying to remove node from an empty list
	else if (list_size > 1)
	{
		node *temp = head;
		node* temp2 = NULL;
		index--; // this ensures that temp would be AT MOST (end-1)
		
		while (--index) // keep looping until you reach the node @ index-1
			temp = (temp->next_node);
		
		temp2 = (temp->next_node->next_node); // keep it here to free it
		temp->next_node = temp2->next_node;
		
		free(temp2);
		temp2 = NULL;
	}
	else // list_size = 1 => free head node and set it to NULL
	{
		free(head);
		head = NULL;
	}
	
	list_size--;
	return 1; // indicates normal behaviour
}

s8 linkedList_removeNode_first(void)
{
	return linkedList_removeNode_atIndex(1);
}

s8 linkedList_removeNode_last(void)
{
	return linkedList_removeNode_atIndex(list_size);
}

// Sorting
s8 linkedList_sort_ascendingly(void)
{
	if (list_size == 0) // empty list
		return -4; // trying to sort an empty list
	else if (list_size == 1)
		return 0; // trying to sort a list that contains only one element
	else // list larger than 2
	{
		int i, j;
		node* temp_i = head;
		node* temp_j = NULL;
		
		// bubble sort
		for (i = 0; i < list_size; i++)
		{
			temp_j = temp_i;
			for (j = 0; j < (list_size - i - 1); j++)
			{
				if ((temp_j->data) > (temp_j->next_node->data))
				{
					swap_nodes(temp_j, temp_j->next_node);
				}
			}
			temp_i = (temp_i->next_node);
		}
	}
	
	return 1; // indicates normal behaviour
}

// this should be the same as ascendingly but I will make all value comparisons -ve
s8 linkedList_sort_descendingly(void) 
{
	if (list_size == 0) // empty list
		return -4; // trying to sort an empty list
	else if (list_size == 1)
		return 0; // trying to sort a list that contains only one element
	else // list larger than 2
	{
		int i, j;
		node* temp_i = head;
		node* temp_j = NULL;
		
		// bubble sort
		for (i = 0; i < list_size; i++)
		{
			temp_j = temp_i;
			for (j = 0; j < (list_size - i - 1); j++)
			{
				if ((-(temp_j->data)) > (-(temp_j->next_node->data)))
				{
					swap_nodes(temp_j, temp_j->next_node);
				}
			}
			temp_i = (temp_i->next_node);
		}
	}
	
	return 1; // indicates normal behaviour
}

// General-purpose
s32 linkedList_size(void)
{
	return list_size;
}

s8 linkedList_isEmpty(void)
{
	return ( (linkedList_size() < 1) ? -5 : 5 ); // return 5 for populated list and -5 for empty list
}

s8 linkedList_print(void)
{
	//if (linkedList_isEmpty())
		//return -6; // trying to print an empty list
	
	u16 i;
	node* temp = head;
	
	printf("[ ");
	for (i = 0; i < list_size; i++)
	{
		printf("%d ", temp-> data);
		temp = (temp->next_node);
	}
	printf("]");
			
	return 1; // indicates normal behaviour
}

// is_in_list => returns the index if yes : returns -1 if no
s8 linkedList_isInList(s32 value)
{
	if (linkedList_isEmpty())
		return -7; // trying to check for the existance of value in an empty list
	
	node* temp = head;
	
	u8 is_in_list = 0;
	u16 index_counter = 1;
	
	while(temp != NULL)
	{	
		if ((temp->data) == value)
		{
			is_in_list ^= 1;
			break;
		}
		
		temp = (temp->next_node);
		index_counter++;
	}
	
	if (is_in_list)
		return index_counter;
	else
		return -8; // indicates that no nodes were found with this value
}