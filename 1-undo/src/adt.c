#include <stdlib.h>
#include "adt.h"

struct StringStack
{
    int length;
    int capacity;
    char** data;
};

StringStack stringstack_new(void)
{
    StringStack s = malloc(sizeof(struct StringStack));
    s->data = malloc(4 * sizeof(char*));
    s->capacity = 4;
    s->length = 0;
    return s;
}

void stringstack_del(StringStack s)
{
    free(s->data);
    free(s);
}

void stringstack_push(StringStack s, char* thing)
{
    if (s->length == s->capacity)
    {
        s->data = realloc(s->data, s->capacity * 2 * sizeof(char*));
        s->capacity *= 2;
    }

    s->data[s->length++] = thing;
}

char* stringstack_pop(StringStack s)
{
    if (s->length == 0) exit(EXIT_FAILURE);
    else return s->data[--s->length];
}

int stringstack_len(StringStack s)
{
    return s->length;
}

void stringstack_reverse(StringStack s)
{
    char** start = s->data;
    char** end = start + s->length - 1;
    while (start < end)
    {
        char* tmp = *start;
        *start = *end;
        *end = tmp;
        start += 1;
        end -= 1;
    }
}
