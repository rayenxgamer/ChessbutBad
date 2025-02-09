#pragma once

#include <stdio.h>
#include <string.h>


int LOG(char* log){
    if (log == NULL) {
        return -1;
    }
    printf("%s",log);
    return 0;
}

