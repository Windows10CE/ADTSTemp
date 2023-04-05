#ifndef ADT_H
#define ADT_H

// I don't *really* want to use a linked list for this?
// The doc says to, but I think its far more interesting to be implemented like this
// I also *kind of* want to go the extra mile and implement an entire deque, but this problem doesn't actually need it, since you can either:
// A. Go through the length of the data the other way really easily
// B. Just reverse the stack the call pop repeatedly (which is what I've done here)
// And as a bonus, this has much better memory usage and locality! Be nice to your cache!
struct StringStack;
typedef struct StringStack* StringStack;

StringStack stringstack_new(void);
void stringstack_del(StringStack);
void stringstack_push(StringStack, char*);
char* stringstack_pop(StringStack);
int stringstack_len(StringStack);
void stringstack_reverse(StringStack);

#endif /* ADT_H */