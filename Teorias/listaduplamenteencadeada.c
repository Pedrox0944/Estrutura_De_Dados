#include <cstddef>
#include <linux/limits.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *next;
    struct Node *prev;
} node;

typedef struct 
{    
    node *start;
    node *end;
    node *assist;
    int size_list;
} double_linked_list;

double_linked_list *create_list()
{
    double_linked_list *new = malloc(sizeof(double_linked_list));
    new->start = NULL;
    new->end = NULL;
    new->assist = NULL;
    new->size_list = 0;
    return new;
}

node *create_node(int value)
{
    node *new = malloc(sizeof(node));
    new->value = value;
    new->next = NULL;
    new->prev = NULL;
    return new;
}

void add(double_linked_list *list, node *node, int pos)
{
    if (list == NULL)
    {
        return;
    }
    if (node == NULL) 
    {
        return;
    }
    if (pos >= 0 && pos <= list->size_list) 
    {
        if (list->start == NULL) 
        {
            list->start = node;
            list->end = node;
        }
        else if (pos == 0) 
        {
            node->next = list->start;
            list->start->prev = node;
            list->start = node;
        }
        else if (pos == list->size_list) 
        {
            list->end->next = node;
            node->prev = list->end;
            list->end = node;
        }
        else 
        {
            list->assist = list->start;
            for (int i = 0; i < pos-1; i++) 
            {
                list->assist = list->assist->next;
            }
            node->next = list->assist->next;
            node->prev = list->assist;
            list->assist->next = node;
            node->next->prev = node;
        }
        list->size_list++;
    }
    else 
    {
        puts("Postion invalid!\n");
    }
}

int delete_biggest(double_linked_list *list)
{
    node *trash= list->start;
    int value;
    if (list->size_list == 1) 
    {
        trash = list->start;
        list->start = NULL;
        list->end = NULL;
        value = trash->value;
        free(trash);
        list->size_list--;
    }
    else if (list->size_list > 1) 
    {
        node *biggest = list->start;
        list->assist = list->start;
        while (list->assist != NULL) 
        {
            if (list->assist->value > biggest->value) 
            {
                biggest = list->assist;
            }
            list->assist = list->assist->next;
        }
        
        if (list->start->value == biggest->value) 
        {
            list->start = list->start->next;
            list->start->prev = NULL;
            value = trash->value;
            free(trash);
        }
        else if (list->end->value == biggest->value) 
        {
            list->end = list->end->prev;
            list->end->next = NULL;
            value = trash->value;
            free(trash);
        }
        else 
        {
            biggest->prev->next = biggest->next;
            biggest->next->prev = biggest->prev;
            value = biggest->value;
            free(biggest);
        }
        list->size_list--;
    }
    else 
    {
        puts("list empty\n");
        value = -1;
    }
    return value;
}

void print(double_linked_list *list)
{
    list->assist = list->start;
    while (list->assist != NULL) 
    {
        printf("%d", list->assist->value);
        list->assist = list->assist->next;
    }
}

int main(){
    return 0;
}