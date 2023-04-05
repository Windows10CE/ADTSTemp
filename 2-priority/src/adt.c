#include <stdlib.h>
#include "adt.h"

// YOUR SOLUTION
typedef struct _queueNode {
    SPQItem item;
    struct _queueNode* next;
} QueueNode;

struct StringPriorityQueue {
    QueueNode* head;
};

StringPriorityQueue spq_new(void)
{
    return calloc(1, sizeof(struct StringPriorityQueue));
}

void spq_del(StringPriorityQueue q)
{
    QueueNode* current = q->head;
    while (current != NULL)
    {
        QueueNode* last = current;
        current = last->next;
        free(last);
    }
    free(q);
}

void spq_enqueue(StringPriorityQueue q, int priority, char* data)
{
    QueueNode* newNode = malloc(sizeof(QueueNode));
    newNode->item.priority = priority;
    newNode->item.data = data;
    if (q->head == NULL)
    {
        newNode->next = NULL;
        q->head = newNode;
    }
    else
    {
        if (q->head->item.priority > priority)
        {
            newNode->next = q->head;
            q->head = newNode;
        }
        else
        {
            QueueNode* last = q->head;
            while (last->next != NULL)
            {
                QueueNode* current = last->next;
                if (current->item.priority > priority)
                {
                    break;
                }
                last = current;
            }
            newNode->next = last->next;
            last->next = newNode;
        }
    }
}

SPQItem spq_dequeue(StringPriorityQueue q)
{
    if (q->head == NULL) exit(EXIT_FAILURE);
    SPQItem item = q->head->item;
    q->head = q->head->next;
    return item;
}

bool spq_isEmpty(StringPriorityQueue q)
{
    return q->head == NULL;
}
