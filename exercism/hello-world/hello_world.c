#include "hello_world.h"
#include <stdlib.h>
#include <string.h>

const char *hello(void)
{
    char * answer = malloc(sizeof(char) * strlen("Hello, World!"));
    if (!answer) return NULL;
    strcpy(answer,"Hello, World!");

    /* string is pointer of the first character */
    return  answer;
}
