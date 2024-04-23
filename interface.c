#include "interface.h"

int main(void)
{
    Welcome();
    readFile(&head, "file.csv");
    while(1) {
        char mode = '0';
        printf("Modes:>>\n1. Admin Mode\n2. User Mode\n3. Exit program\n\nChoose Mode : ");
        scanf("%c", &mode);
        clearInputBuffer();
        if(mode == '3') break;

        switch(mode){
            case '1':
                adminMode();
                break;
            case '2':
                userMode();
                break;
            default:
                printf("Invalid mode selection..Try again.\n");
                break;
        }
    }
    return 0;
}




