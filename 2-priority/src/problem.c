#include <stdio.h>
#include <stdlib.h>
#include "transcript.h"
#include "adt.h"

/* Usage: ./mysolution [filename]*/
Line* transcript[1000];
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        exit(EXIT_FAILURE);
    }
    char* filename = argv[1];
    int n = readTranscript(filename, transcript);


    // Initiatilize your ADT
    StringPriorityQueue queue = spq_new();
    // Translate transcript to your ADT functions
    for(int i = 0; i < n; i++){
        int priority = atoi(transcript[i]->action);
        spq_enqueue(queue, priority, transcript[i]->data);
        // printf("Priority %d - %s\n", priority, transcript[i]->data); // Comment out when running make test
    }
    
    // Print the priority list from your ADT
    while (!spq_isEmpty(queue))
    {
        SPQItem item = spq_dequeue(queue);
        printf("Priority %d - %s\n", item.priority, item.data);
    }
    // Memory cleanup
    spq_del(queue);
    destroyTranscript(transcript, n);

    return EXIT_SUCCESS;
}
