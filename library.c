#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {

    return 0;
}

char * takestring_v2(){
    char* s = (char *)calloc(1,sizeof(char));
    int len = 1;
    *s = '\0';
    char t;
    t = getchar();
    int c = 1;
    while(t != '\n'){
        if(c == len)
        {
            s = (char *)realloc(s, (2 * len) * sizeof(char));
            len = 2 * len;
        }
        *(s + c - 1) = t;
        *(s + c) = '\0';
        c++;
        t = getchar();
    }
    fflush(stdin);
    if(len == 1)  return takestring_v2();
    if(*s == ' ') {
        printf("Cannot Start With Spaces!\nEnter Again: ");
        return takestring_v2();
    }

    return s;
}
