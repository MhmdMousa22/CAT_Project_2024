#include <stdio.h>
#include <string.h>
#include "interface.h"

int main(void)
{
    Welcome();
    readFile(&head, "file.csv");
    while(1) {
        int mode;
        printf("Choose mode:\n1. Admin Mode\n2. User Mode\n3. Exit program\n");
        scanf("%d", &mode);
        if (mode == 1) {
            adminMode();
        } else if (mode == 2) {
            userMode();
        }else if (mode == 3) {
            break;
        } else {
            printf("Invalid mode selection..Try again.\n");
        }
    }
    return 0;
}




