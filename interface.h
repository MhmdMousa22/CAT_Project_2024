
#ifndef INTERFACE_INTERFACE_H
#define INTERFACE_INTERFACE_H

#include <stdio.h>
#include "admin.h"

void Welcome(){
    printf("\t\t\t\t#################################################################\n\
\t\t\t\t#################################################################\n\
\t\t\t\t#################################################################\n\
\t\t\t\t############ |WELCOME TO STUDENT RECORED PROGRAM| ###############\n\
\t\t\t\t#################################################################\n\
\t\t\t\t#################################################################\n\
\t\t\t\t#################################################################\n\
");
    printf("\t\t\t\t>>>>>>> [Press (b) anytime to return to previous process] <<<<<<<\n\
");}

void adminMode() {
    char admin_password[20] = "1234";
    char input_password[20];
    int attempts = 3;

    while (attempts > 0) {
        printf("Enter admin password: ");
        scanf("%s", input_password);
        getchar();

        if (strcmp(admin_password, input_password) == 0) {
            printf("Login successful.\n");
            break;
        } else {
            attempts--;
            printf("Incorrect password. %d attempts remaining.\n", attempts);
            if (attempts == 0) {
                printf("Login failed. Exiting...\n");
                return;
            }
        }
    }

    while(1)
    {   int choice;
        char back;
        back:
        printf(">> Admin Menu:\n");
        printf("1- Add new student\n2- Veiw a student with their ID\n");
        printf("3- veiw all students\n4- Edit student data\n5- Delete  student with its ID\n");
        printf("6- Edit admin's password\n7- Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        getchar();
        switch(choice)
        {
            case 1:
                printf("\t\t\tIf you want to go back, press 'b' \n");fflush(stdin);fflush(stdout);
                scanf("%c",&back);
                if(back == 'b')
                    goto back;
                //calling
                add_student();
                writeFile(head, "file.csv");
                break;
            case 2:
                printf("\t\t\tIf you want to go back, press 'b' \n");fflush(stdin);fflush(stdout);
                scanf("%c",&back);
                if(back == 'b')
                    goto back;
                printf("\nEnter student's ID : ");
                VOI_student(takestring_v2());
                break;
            case 3:
                printf("\t\t\tIf you want to go back, press 'b' \n");fflush(stdin);fflush(stdout);
                scanf("%c",&back);
                if(back == 'b')
                    goto back;
                //calling
                //readFile(&head, "file.csv");
                VA_student();
                break;
            case 4:
                printf("\t\t\tIf you want to go back, press 'b' \n");fflush(stdin);fflush(stdout);
                scanf("%c",&back);
                if(back == 'b')
                    goto back;
                //calling
                E_student(takestring_v2());
                writeFile(head, "file.csv");
                break;
            case 5:
                printf("\t\t\tIf you want to go back, press 'b' \n");fflush(stdin);fflush(stdout);
                scanf("%c",&back);
                if(back == 'b')
                    goto back;
                //calling
                break;
            case 6:
                printf("\t\t\tIf you want to go back, press 'b' \n");fflush(stdin);fflush(stdout);
                scanf("%c",&back);
                if(back == 'b')
                    goto back;
                //calling
                void EA_pas();
                break;
            case 7:
                printf("\t\t\tIf you want to go back, press 'b' \n");fflush(stdin);fflush(stdout);
                scanf("%c",&back);
                if(back == 'b')
                    goto back;
                //calling
                break;
            default:
                printf("wrong choice...Choose again.\n");
                goto back;
                break;
        }
        if( choice == 7) {break;}
        printf("If you want to do another operation, press (Y) for YES or any other value for NO :\n");fflush(stdin);fflush(stdout);
        scanf("%c",& back);
        if(back != 'y' && back != 'Y')
            break;
    }}

void userMode() {

    while(1)
    {   int choice;
        char back;
        back:
        printf("Student Menu:\n");
        printf("1- Veiw Your Record\n");
        printf("2- Edit Your pass\n");
        printf("3- Edit Your name\n");
        printf("4- Edit Your phone number\n5- Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("\t\t\tIf you want to go back, press 'b' \n");fflush(stdin);fflush(stdout);
                scanf("%c",&back);
                if(back == 'b')
                    goto back;
                //calling
                voi_student();
                break;
            case 2:
                printf("\t\t\tIf you want to go back, press 'b' \n");fflush(stdin);fflush(stdout);
                scanf("%c",&back);
                if(back == 'b')
                    goto back;
                //calling
                e_pass();
                break;
            case 3:
                printf("\t\t\tIf you want to go back, press 'b' \n");fflush(stdin);fflush(stdout);
                scanf("%c",&back);
                if(back == 'b')
                    goto back;
                //calling
                e_name();
                writeFile(head, "file.csv");
                break;
            case 4:
                printf("\t\t\tIf you want to go back, press 'b' \n");fflush(stdin);fflush(stdout);
                scanf("%c",&back);
                if(back == 'b')
                    goto back;
                //calling
                e_phnum();
                break;
            case 5:
                printf("\t\t\tIf you want to go back, press 'b' \n");fflush(stdin);fflush(stdout);
                scanf("%c",&back);
                if(back == 'b')
                    goto back;
                //calling
                break;
            default:
                printf("wrong choise...Choose again.\n");
                goto back;
                break;
        }
        if( choice == 5) {break;}
        printf("Do you want to do other process press (y~Y) for YES and any other for NO\n");fflush(stdin);fflush(stdout);
        scanf("%c",& back);
        if(back != 'y' && back != 'Y')
            break;
    }}

#endif //INTERFACE_INTERFACE_H
