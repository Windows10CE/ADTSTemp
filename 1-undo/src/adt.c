#include <stdlib.h>
#include "adt.h"

typedef struct _stackNode {
    char* data;
    struct _stackNode* next;
} StackNode;

struct StringStack
{
    StackNode* head;
};

StringStack stringstack_new(void)
{
    StringStack s = calloc(1, sizeof(struct StringStack));
    return s;
}

void stringstack_del(StringStack s)
{
    StackNode* current = s->head;
    free(s);
    while (current)
    {
        StackNode* next = current->next;
        free(current);
        current = next;
    }
}

void stringstack_push(StringStack s, char* thing)
{
    StackNode* newNode = malloc(sizeof(StackNode));
    newNode->data = thing;
    newNode->next = s->head;
    s->head = newNode;
}

char* stringstack_pop(StringStack s)
{
    if (!s->head) exit(EXIT_FAILURE);
    StackNode* node = s->head;
    s->head = node->next;
    return node->data;
}

bool stringstack_empty(StringStack s)
{
    return s->head == NULL;
}

void stringstack_reverse(StringStack s)
{
    StackNode* prev = NULL;
    StackNode* current = s->head;
    while (current)
    {
        StackNode* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    s->head = prev;
}
