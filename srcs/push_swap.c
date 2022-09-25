#include "../include/push_swap.h"

struct Stack
{
    int data;
    struct Stack    *next;
};
struct Stack    *top = NULL;

void    ft_push(int val)
{
    struct Stack    *newNode;

    newNode = (struct Stack *)malloc(sizeof(struct Stack));
    newNode->data = val;
    newNode->next = top;
    top = newNode;
}

void    display()
{

    struct Stack *temp = top;
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");    
}

void    push_swap(int *nbrs, int size)
{
    int i;

    i = size;
		while (0 < i--)
        {
			// printf("|%d||\n", nbrs[size]);
            ft_push(nbrs[i]);
        }
        display();
		printf("size = %d\n", size);
}