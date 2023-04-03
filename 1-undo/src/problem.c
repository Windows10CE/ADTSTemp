#include <stdio.h>
#include <stdlib.h>
#include "transcript.h"
#include "adt.h"

/* Usage: ./mysolution [filename]*/
Line* transcript[1000];
int main(int argc, char *argv[])
{
    char* filename = argv[1];
    int n = readTranscript(filename, transcript);
    int i_data;

    // Initiatilize your ADT

    
    // Translate transcript to your ADT functions
    for(int i = 0; i < n; i++){
        if(strcmp(transcript[i]->action, "Type") == 0){
            // Do something with your ADT
            printf("Type %s\n", transcript[i]->data); // Comment out when running make test
        }
        if(strcmp(transcript[i]->action, "Undo") == 0){
            // Do something with your ADT
            i_data = atoi(transcript[i]->data);
            printf("Undo %d\n", i_data); // Comment out when running make test
        }
        if(strcmp(transcript[i]->action, "Redo") == 0){
            // Do something with your ADT
            i_data = atoi(transcript[i]->data);
            printf("Redo %d\n", i_data); // Comment out when running make test
        }

    }

    // Print out the final text (after redo/undo)
    

    // Memory cleanup
    destroyTranscript(transcript, n);

    return EXIT_SUCCESS;
}
