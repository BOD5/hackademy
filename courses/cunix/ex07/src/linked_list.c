#include <stdlib.h>
#include <stdio.h>
#include "../include/linked_list.h"

node_t  *list_create(void *data)
{
    node_t  *head = malloc(sizeof(node_t));

    head->data = data;
    head->next = NULL;
    return head;
}

void    list_destroy(node_t **head, void (*fp)(void *data))
{
    node_t  *current = *head;
    node_t  *next;

    while (current)
    {
        next = current->next;
        fp(current->data);
        free(current);
        current = next;
    }
    *head = NULL;
}

void    list_push(node_t *head, void *data)
{
    node_t  *new = malloc(sizeof(node_t));
    new->data = data;

    node_t  *last = head;
    while(last->next)
    {
        last = last->next;
    }
    last->next = new;
}

void    list_unshift(node_t **head, void *data)
{
    node_t  *new_start = malloc(sizeof(node_t));
    new_start->data = data;
    if (*head)
    {
        new_start->next = *head;
    }
    *head = new_start;
}

void    *list_pop(node_t **head)
{
    node_t  *beforeLast = *head;

    while(beforeLast->next->next)
    {
        beforeLast = beforeLast->next;
    }
    node_t  *last = beforeLast->next;
    void    *data = last->data;

    free(last);
    beforeLast->next = NULL;
    return data;
}

void    *list_shift(node_t **head)
{
    if(*head)
    {    
        node_t  *tmp = *head;
        void    *data = tmp->data;
        *head = tmp->next;
        free(tmp);     
        return data;
    }
    return NULL;
}

void    *list_remove(node_t **head, int pos)
{
    int     i = 0;
    while ((*head)->next && i++ != pos) ;
    if (!(*head)->next) {
        return NULL;
    }
    void    *data = (*head)->next->data;
    node_t  *removed = (*head)->next;
    (*head)->next = (*head)->next->next;
    free(removed);
    return data;
}

void    list_print(node_t *head)
{
    printf("%s", (char*)head->data);
    if(head->next)
    {
        list_print(head->next);
    }
}

void    list_visitor(node_t *head, void (*fp)(void *data))
{
    fp(head->data);
    if(head->next)
    {
        list_visitor(head->next, fp);
    }
}
