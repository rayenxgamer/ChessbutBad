#pragma once

#include <stdio.h>
#include <stdlib.h>

struct node{
    int id;
    struct node* next;
};
typedef struct node list;

void allocate_list(list* node, int id);
void findInList(list* node, int id);


