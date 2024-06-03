/*=======================================================

Write a function that returns the number of elements in the linked list that's
passed to it.

It must be declared as follows:

int	ft_list_size(t_list *begin_list);

You must use the following structure in your program ft_list_size.c :

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;

======================================================== */

// Structure is like a container or a box, similar to an object in JS. 
// Away to group together different pieces of information under one name 
// eg:
// struct Person 
// {
//  char name[50];  
//  int age;
// };
// 'typedef' gives the "nickname" to the data type
typedef struct  s_list
{
    //pointer to the next "node"
    struct s_list   *next;
    // pointer to the information about the node
    void            *data;
}                   t_type;


int     ft_list_size(t_type *begin_list)
{
    int list_size = 0; // Initialize size counter

// While there is still nodes in the list we enter a loop
    while (begin_list != '\0')
    {
        list_size++; // Increment size for each node
        begin_list = begin_list->next; // Move to the next node
        // '->' arrow operator is used to access members of a structure 'struct' or union through a pointer
    }

    return (list_size); // Return the total number of nodes
}

/* 
A linked list is a data structure made up of nodes. 
Each node contains some data and a pointer to the next node in the list.
Here's how you can represent a node in a linked list:

typedef struct s_list {
    struct s_list *next;
    void *data;
} t_list;

s_list is the name of the structure.
next is a pointer to the next node in the list.
data is a pointer to the actual data stored in the node.
t_list is a new name created using typedef for the struct s_list type.

When to Use:
You use 'struct' when you want to group related pieces of information together.
You use 'typedef' to create shorter, more convenient names for data types.
You use a linked list when you need to store a collection of data where 
each element has a pointer to the next element.
*/

/* 
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	t_list *l1 = (t_list *)malloc(sizeof(t_list));
	t_list *l2 = (t_list *)malloc(sizeof(t_list));
	t_list *l3 = (t_list *)malloc(sizeof(t_list));
	t_list *current_node;

	int a = -63;
	int b = 0;
	int c = -87;

	l1->data = (void *)&a;
	l2->data = (void *)&b;
	l3->data = (void *)&c;

	l1->next = l2;
	l2->next = l3;
	l3->next = NULL;

	printf("List size: %d\n", ft_list_size(l1));
	current_node = l1;
	while (current_node != '\0')
	{
		printf("%d\n", *(int *)current_node->data);
		current_node = current_node->next;
	}
	free(l1);
	free(l2);
	free(l3);
} */