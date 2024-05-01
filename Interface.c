#include "Interface.h"

void Welcome(){
    printf("\t\t\t\t\t\t\t\t\t\t\t#################################################################\n\
\t\t\t\t\t\t\t\t\t\t\t#################################################################\n\
\t\t\t\t\t\t\t\t\t\t\t#################################################################\n\
\t\t\t\t\t\t\t\t\t\t\t############ |WELCOME TO STUDENT RECORED PROGRAM| ###############\n\
\t\t\t\t\t\t\t\t\t\t\t#################################################################\n\
\t\t\t\t\t\t\t\t\t\t\t#################################################################\n\
\t\t\t\t\t\t\t\t\t\t\t#################################################################\n\
");
    printf("\t\t\t\t\t\t\t\t\t\t\t>>>>> [ Press (b) anytime to return to previous process ] <<<<<<\n\
");}

void adminMode() {
    //char admin_password[20] = "1234";
    char input_password[30];
    int attempts = 3;

    while (attempts > 0) {
        printf("Enter admin password: ");
        scanf("%s", input_password);
        getchar();

        if (strcmp(adpas, input_password) == 0) {
            printf("\t\t\t\t>> Login successful <<\n");
            break;
        } else {
            attempts--;
            printf("Incorrect password. %d attempts remaining.\n", attempts);
            if (attempts == 0) {
                printf("\t\t\t\t>> Login failed. Exiting <<\n");
                return;
            }
        }
    }

    while(1)
    {   char str[8];
        //char *endptr;
        int choice;
        char back[8];
        back:
        printf(">> Admin Menu:\n");
        printf("1- Add new student\n2- Veiw a student with their ID\n");
        printf("3- veiw all students\n4- Edit student data\n5- Delete student by their ID\n");
        printf("6- Edit admin's password\n7- Exit\n");
        printf("Enter your choice : ");
        scanf("%s",str);
        choice = atoi(str);
        //scanf("%d",&choice);
        //getchar();
        switch(choice)
        {
            case 1:
                printf("\t\t\tIf you want to go back, press (b) \n"); fflush(stdin);fflush(stdout);
                scanf("%s",back);
                if(!strcmp(back, "b"))
                    goto back;
                //calling
                add_student();
                break;
            case 2:
                printf("\t\t\tIf you want to go back, press (b) \n"); fflush(stdin);fflush(stdout);
                scanf("%s",back);
                if(!strcmp(back, "b"))
                    goto back;
                printf("Enter student's ID : ");
                VOI_student(takestring_v2());
                break;
            case 3:
                printf("\t\t\tIf you want to go back, press (b) \n"); fflush(stdin);fflush(stdout);
                scanf("%s",back);
                if(!strcmp(back, "b"))
                    goto back;
                //calling
                VA_student();
                break;
            case 4:
                printf("\t\t\tIf you want to go back, press (b) \n"); fflush(stdin);fflush(stdout);
                scanf("%s",back);
                if(!strcmp(back, "b"))
                    goto back;
                //calling
                printf("Enter student's ID : ");
                E_student(takestring_v2());
                //writeFile(head, "students.csv");
                break;
            case 5:
                printf("\t\t\tIf you want to go back, press (b) \n"); fflush(stdin);fflush(stdout);
                scanf("%s",back);
                if(!strcmp(back, "b"))
                    goto back;
                //calling
                printf("Enter student's ID : ");
                DeleteStudent(takestring_v2());
                //writeFile(head, "students.csv");
                break;
            case 6:
                printf("\t\t\tIf you want to go back, press (b) \n"); fflush(stdin);fflush(stdout);
                scanf("%s",back);
                if(!strcmp(back, "b"))
                    goto back;
                //calling
                EA_pas();
                break;
            case 7:
                printf("\t\t\tIf you want to go back, press (b) \n"); fflush(stdin);fflush(stdout);
                scanf("%s",back);
                if(!strcmp(back, "b"))
                    goto back;
                //calling
                break;
            default:
                printf("wrong choice...Choose again.\n");
                goto back;
                //break;
        }
        if( choice == 7 ) {break;}
        printf("If you want to do another operation, press (Y) for YES or any other value for NO :\n");fflush(stdin);fflush(stdout);
        scanf("%s", back);
        if (strcmp(back, "Y") != 0 && strcmp(back, "y") != 0)
            {break;}
    }}


    //Student Mode
void userMode() {

    char id[88];
    char pass[88];
    char str[8];
    int choice;
    char back[8];

    // Ask user for ID and password
    printf("Enter your ID: ");
    scanf("%s", id);

    printf("Enter your password: ");
    scanf("%s", pass);

    struct student *temp = head;
    int found = 0;

    while (temp != NULL) {
        if (!strcmp(temp->id, id)) {
            // ID matchs, check password
            found = 1;
            if (!strcmp(temp->paswrd, pass)) {
                back1:
                while(1)
                {
                    back:
                    printf(">> Student Menu:\n");
                    printf("1- Veiw Your Record\n");
                    printf("2- Edit Your pass\n");
                    printf("3- Edit Your name\n");
                    printf("4- Edit Your phone number\n5- Exit\n");
                    printf("Enter your choice : ");
                    scanf("%s",str);
                    choice = atoi(str);
                    //scanf("%d",&choice);
                    //choice = getchar();
                    switch(choice)
                    {
                        case 1:
                            printf("\t\t\tIf you want to go back, press (b) \n"); fflush(stdin);fflush(stdout);
                            scanf("%s",back);
                            if(!strcmp(back, "b"))
                                goto back;
                            //calling
                            voi_student(temp);
                            break;
                        case 2:
                            printf("\t\t\tIf you want to go back, press (b) \n"); fflush(stdin);fflush(stdout);
                            scanf("%s",back);
                            if(!strcmp(back, "b"))
                                goto back;
                            //calling
                            e_pass(temp);
                            //writeFile(head, "students.csv"); fflush(stdin);fflush(stdout);
                            break;
                        case 3:
                            printf("\t\t\tIf you want to go back, press (b) \n"); fflush(stdin);fflush(stdout);
                            scanf("%s",back);
                            if(!strcmp(back, "b"))
                                goto back;
                            //calling
                            e_name(temp);
                            break;
                        case 4:
                            printf("\t\t\tIf you want to go back, press (b) \n"); fflush(stdin);fflush(stdout);
                            scanf("%s",back);
                            if(!strcmp(back, "b"))
                                goto back;
                            //calling
                            e_phnum(temp);
                            break;
                        case 5:
                            printf("\t\t\tIf you want to go back, press (b) \n"); fflush(stdin);fflush(stdout);
                            scanf("%s",back);
                            if(!strcmp(back, "b"))
                                goto back;
                            //calling
                            break;
                        default:
                            printf("wrong choise...Choose again.\n");
                            goto back;
                            //break;
                    }
                    if( choice == 5) {break;}
                    printf("Do you want to do other process press (Y) for YES and any other for NO\n");fflush(stdin);fflush(stdout);
                    scanf("%s",back);
                    if (strcmp(back, "Y") != 0 && strcmp(back, "y") != 0)
                    {break;}
                }
                break;
            }
            else {
                printf("\nIncorrect Password .. Enter your Phone Number correctly to view your record : ");
                scanf("%s", tempo.phnum);
                if (!strcmp(tempo.phnum, temp->phnum)) { goto back1; }
                else {
                    printf("\n\t\t\t[[ Incorrect Phone Number .. Failed to view record ]]\n");
                    break;
                }
            }
        }
        temp = temp->next;
    }

    if (!found) {
        printf("\t\t\t\t[[ Student is NOT found or Incorrect Password. ]]\n");
    }
}
