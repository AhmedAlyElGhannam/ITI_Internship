#include <stdio.h>
#include <stdlib.h>
#include "Linked_List.h"

s16 menu(void);
void return_type_handler(s32 return_value);

void main(void)
{
	
	u8 is_running = 1;
	s32 value= 0;
	u8 index = 1;
	
	
	while (is_running)
	{
		switch (menu())
		{
			case 1 : 	printf("Enter a value to insert at the beginning: ");
						scanf("%d", &value);
						value = linkedList_addNode_first(value);
						return_type_handler(value);
						break;
						
			case 2 : 	printf("Enter a value: ");
						scanf("%d", &value);
						printf("Enter an index: ");
						scanf("%hhd", &index);
						value = linkedList_addNode_atIndex(value, index);
						return_type_handler(value);
						break;
			
			case 3 : 	printf("Enter a value to insert at the end: ");
						scanf("%d", &value);
						value = linkedList_addNode_last(value);
						return_type_handler(value);
						break;
			
			
			case 4 : 	value = linkedList_removeNode_first();
						return_type_handler(value);
						break;
						
			case 5 : 	printf("Enter an index: ");
						scanf("%hhd", &index);
						value = linkedList_removeNode_atIndex(index);
						return_type_handler(value);
						break;
						
			case 6 : 	value = linkedList_removeNode_last();
						return_type_handler(value);
						break;
						
			case 7 : 	value = linkedList_sort_ascendingly();
						return_type_handler(value);
						break;
						
			case 8 : 	value = linkedList_sort_descendingly();
						return_type_handler(value);
						break;
						
			case 9 : 	printf("\nSize of List = %d\n", linkedList_size());
						break;
						
			case 10: 	value = linkedList_isEmpty();
						return_type_handler(value);
						break;
						
			case 11: 	printf("Enter a value to search for: ");
						scanf("%d", &value);
						value = linkedList_isInList(value);
						return_type_handler(value);
						break;
						
			case 12: 	value = linkedList_print();
						return_type_handler(value);
						break;
						
			
			case 13: 	is_running ^= 1;
						break;
						
			default:	printf("Invalid Input! Try Again\n");
			
		}
	}
}

s16 menu(void)
{
	s16 choice = 0;
	
	printf("\n\n");
	printf("01. Add a node at the beginning\n");
	printf("02. Add a node at index\n");
	printf("03. Add a node at the end\n");
	printf("04. Remove a node at the beginning\n");
	printf("05. Remove a node at index\n");
	printf("06. Remove a node at the end\n");
	printf("07. Sort list ascendingly\n");
	printf("08. Sort list descendingly\n");
	printf("09. Print the size of list\n");
	printf("10. Tell me if list is empty\n");
	printf("11. Tell me if value is in list\n");
	printf("12. Print the linked list\n");
	printf("13. Exit\n");

	printf("Enter your choice: ");
	scanf("%hd", &choice);
	
	return choice;
}

void return_type_handler(s32 return_value)
{
	printf("\n\n");
	
	switch(return_value)
	{
		case -8: printf("Cannot Find a Node with Such Value\n"); break;
		case -7: printf("Cannot Find a Node in an Empty List\n"); break;
		case -5: printf("List is Empty\n"); break;
		case -4: printf("Unable to Sort an Empty List\n"); break;
		case -3: printf("Node Removal from an Empty List is Prohibited\n"); break;
		case -2: printf("Memory Allocation was not Successful\n"); break;
		case -1: printf("Out of Bounds: Invalid Index\n"); break;
		case  0: printf("Cannot Sort a List with Size 1\n"); break;
		case  1: printf("Command Executed Successfully\n"); break;
		case  5: printf("List is Populated\n");
		case  6: printf("Cannot Print an Empty List\n"); break;
	}
}

