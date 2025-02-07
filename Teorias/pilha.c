#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *prox;
}node;

typedef struct 
{
    node *top;
    int size_stack;
} stack;

stack *create_stack()
{
    stack *new = malloc(sizeof(stack));
    new->top = NULL;
    new->size_stack = 0;
    return new;
}

node *create_node(int value)
{
    node *new = malloc(sizeof(node));
    new->value = value;
    new->prox = NULL;
    return new;
}

void add(stack *pile, node *node){
    if (node == NULL) 
    {
        return;
    }
    if (pile == NULL) 
    {
        return;
    }
    
    if (pile->top == NULL) 
    {
        pile->top = node;
    }
    else {
        node->prox = pile->top;
        pile->top = node;
    }
    pile->size_stack++;
}

int delete(stack *pile)
{
    int value;
    node *assistant = pile->top;
    if (pile->size_stack > 0) 
    {
        value = assistant->value;
        pile->top = assistant->prox;
        free(assistant);
        pile->size_stack--;
        return value;
    }
    else 
    {
        printf("Stack empty!\n");
        return -1;
    }
}

void print(stack *pile){
    if (pile->top == NULL) 
    {
        printf("stack empty!\n");
        return;
    }
    node *assistant = pile->top;
    while (assistant != NULL) 
    {
        printf("Valor: %d\n", assistant->value);
        assistant = assistant->prox;
    }
}

int main()
{
    stack *pile = create_stack();
    node *newnode = create_node(10);
    node *newnode2 = create_node(5); 
    node *newnode3 = create_node(1);
    add(pile, newnode);
    add(pile, newnode2);
    add(pile, newnode3);
    delete(pile);
    print(pile);
    return 0;
}