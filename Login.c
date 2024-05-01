#include "Include.h"

int main() {
    Welcome();
    char password[30];
    readFile(&head, "Students.csv");
    admin_read(password, "Admin_PASS.csv");
    while(1) {
        char mode[10];
        printf("Modes:>>\n1. Admin Mode\n2. User Mode\n3. Exit program\n\nChoose Mode : ");
        strcpy(mode, takestring_v2());
        //clearInputBuffer();

        if (!strcmp(mode, "1") )  adminMode();
        else if (!strcmp(mode, "2") )  userMode();
        else if (!strcmp(mode, "3")) break;
        else printf("Invalid mode selection..Try again.\n");
    }

    writeFile(head, "Students.csv");
    admin_File(adpas, "Admin_PASS.csv");
    freeList(head);
    return 0;
}
