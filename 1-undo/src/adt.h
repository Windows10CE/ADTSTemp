#include <stdbool.h>

#ifndef ADT_H
#define ADT_H

struct StringStack;
typedef struct StringStack* StringStack;

StringStack stringstack_new(void);
void stringstack_del(StringStack);
void stringstack_push(StringStack, char*);
char* stringstack_pop(StringStack);
bool stringstack_empty(StringStack);
void stringstack_reverse(StringStack);

#endif /* ADT_H */