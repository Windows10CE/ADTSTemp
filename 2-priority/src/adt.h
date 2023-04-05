#include <stdbool.h>

#ifndef ADT_H
#define ADT_H

// YOUR FUNCTION PROTOTYPES HERE
struct StringPriorityQueue;
typedef struct StringPriorityQueue* StringPriorityQueue;

typedef struct {
    int priority;
    char* data;
} SPQItem;

StringPriorityQueue spq_new(void);
void spq_del(StringPriorityQueue);
void spq_enqueue(StringPriorityQueue, int priority, char* item);
SPQItem spq_dequeue(StringPriorityQueue);
bool spq_isEmpty(StringPriorityQueue);

#endif /* ADT_H */