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
    int i_data;

    // Initiatilize your ADT
    StringStack output = stringstack_new();
    StringStack undo = stringstack_new();
    
    // Translate transcript to your ADT functions
    for(int i = 0; i < n; i++){
        if(strcmp(transcript[i]->action, "Type") == 0){
            // Do something with your ADT
            stringstack_push(output, transcript[i]->data);
            //printf("Type %s\n", transcript[i]->data); // Comment out when running make test
        }
        if(strcmp(transcript[i]->action, "Undo") == 0){
            // Do something with your ADT
            i_data = atoi(transcript[i]->data);
            for (int i = 0; i < i_data; i++)
            {
                stringstack_push(undo, stringstack_pop(output));
            }
            //printf("Undo %d\n", i_data); // Comment out when running make test
        }
        if(strcmp(transcript[i]->action, "Redo") == 0){
            // Do something with your ADT
            i_data = atoi(transcript[i]->data);
            for (int i = 0; i < i_data; i++)
            {
                stringstack_push(output, stringstack_pop(undo));
            }
            //printf("Redo %d\n", i_data); // Comment out when running make test
        }

    }

    // Print out the final text (after redo/undo)
    stringstack_reverse(output);
    while (stringstack_len(output) > 0)
    {
        printf("%s", stringstack_pop(output));
    }
    printf("\n");

    // Memory cleanup
    destroyTranscript(transcript, n);
    stringstack_del(output);
    stringstack_del(undo);

    return EXIT_SUCCESS;
}
