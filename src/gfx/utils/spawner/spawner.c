#include "spawner.h"
#include <stdio.h>
#include <stdlib.h>



void allocate_list(list* node, int id){
    node -> next = malloc(sizeof(list));
    if (node->next == NULL) {
        sprintf(stderr, "this is terrible, failed to allocate linked list and exited with code %d\n",-1);
    }else {
        node->id = id;
    }
}

void findInList(list* node, int id){
    while (node->next != NULL) {
        if (node->id == id) {
            printf("found!");
            break;
        }
    }
    if (node->id != id) {
        printf("your value %d was not found!", id);
    }
};
