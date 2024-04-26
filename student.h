#ifndef STUDENT_STUDENT_H
#define STUDENT_STUDENT_H
#include "library.h"

// view student record
void voi_student() {
    char id[88];
    char pass[88];

    // Ask user for ID and password
    printf("Enter your ID: ");
    scanf("%s", id);

    printf("Enter your password: ");
    scanf("%s", pass);

    struct student *temp = head;
    int found = 0;

    char* reverted = NULL;
    reverted = (char*)malloc(strlen(temp->name) + 1);

    while (temp != NULL) {
        if (!strcmp(temp->id, id)) {
            // ID matchs, check password
            found = 1;
            if (!strcmp(temp->paswrd, pass)) {
                back:
                strcpy(reverted, temp->name);
                printf("\nName : %s", revert_spaces(reverted));
                printf("\nID : %s", temp->id);
                printf("\nPhone number : %s", temp->phnum);
                printf("\nGender : %s", temp->gender);
                printf("\nGrade : %s\n", temp->grd);
                break;
            } else {
                printf("\nIncorrect Password .. Enter your Phone Number correctly to view your record : ");
                scanf("%s", tempo.phnum);
                if (!strcmp(tempo.phnum, temp->phnum)) { goto back; }
                else {
                    printf("\n\t\t\t[[ Incorrect Phone Number .. Failed to view record ]]\n");
                    break;
                }
            }
        }
        temp = temp->next;
    }

    free(reverted);
    if (!found) {
        printf("\t\t\t\t[[ Student is NOT found or Incorrect Password. ]]\n");
    }
}

    // edit student name
    void e_name() {
        char id[88];
        char pass[88];

        // Ask user for ID and password
        printf("Enter your ID: ");
        scanf("%s", id);
        printf("Enter your password: ");
        scanf("%s", pass);

        struct student *temp = head;
        int found = 0;

        while (temp != NULL) {
            if (!strcmp(temp->id, id) && !strcmp(temp->paswrd, pass)) {
                // ID and password match, allow user to edit name

                temp->name = (char*)malloc(max * sizeof(char));
                if (temp->name == NULL) {
                    printf("Memory allocation failed.\n");
                    return;
                }

                tempo.name = (char*)malloc(max * sizeof(char));
                if (tempo.name == NULL) {
                    printf("Memory allocation failed.\n");
                    free(temp->name); // Free previously allocated memory
                    return;
                }

                // Input new name
                printf("Enter the new name: ");
                strcpy(tempo.name, takestring_v2());

                // Save changes if successful
                if (save()) {
                    strcpy(temp->name, tempo.name);
                    printf("\t\t\t\t[[ Changes have been saved ]]\n");
                } else {
                    printf("\t\t\t\t[[ Changes are not saved ]]\n");
                }

                // Free dynamically allocated memory
                free(tempo.name);

                found = 1;
                break;
            }
            temp = temp->next;
        }

        if (!found) {
            printf("\t\t\t\t[[ Student not found or incorrect ID/password. ]]\n");
        }
    }


void e_pass() { // edit student pass
    char id[88];
    char* pass; // Initialize pass pointer
    char cnfrm_pass[max]; // Increase size to accommodate passwords

    // Ask user for ID and password
    printf("Enter your ID: ");
    scanf("%s", id);

    // Allocate memory for pass pointer
    pass = (char*)malloc(max * sizeof(char));
    if (pass == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter your current password: ");
    scanf("%s", pass);

    struct student *temp = head;
    int found = 0;

    while (temp != NULL) {
        if (strcmp(temp->id, id) == 0 && strcmp(temp->paswrd, pass) == 0) {
            char* new_pass = (char*)malloc(max * sizeof(char)); // Allocate memory for new password

            if (new_pass == NULL) {
                printf("Memory allocation failed.\n");
                free(pass); // Free allocated memory before returning
                return;
            }

            // ID and password match, allow user to edit password
            printf("\nEnter your new password: ");
            scanf("%s", new_pass);

            printf("Confirm new password : "); fflush(stdin); fflush(stdout);
            scanf("%s", cnfrm_pass);

            if(strcmp(new_pass, cnfrm_pass) == 0) { // Compare passwords
                strcpy(temp->paswrd, new_pass); // Update password
                printf("\t\t\t\t Password Updated Successfully\n");
            } else {
                printf("\t\t\t\t Passwords do not match. Password not updated.\n");
            }
            found = 1;
            free(new_pass); // Free memory allocated for new_pass
            break;
        }
        temp = temp->next;
    }

    if (!found) {
        printf("\t\t\t\t [[ Student not found or incorrect ID/password. ]]\n");
    }

    free(pass); // Free allocated memory for pass pointer
}


void e_phnum() {  // edit student phone number
    char id[88];
    char pass[88];

    // Ask user for ID and password
    printf("Enter your ID: ");
    scanf("%s", id);
    printf("Enter your password: ");
    scanf("%s", pass);

    struct student *temp = head;
    int found = 0;

    while (temp != NULL) {
        if (strcmp(temp->id, id) == 0 && strcmp(temp->paswrd, pass) == 0) {
            // ID and password match, allow user to edit phone number

            // Allocate memory for tempo.phnum
            //tempo.phnum = (char*)malloc(max * sizeof(char));
            if (tempo.phnum == NULL) {
                printf("Memory allocation failed.\n");
                return;
            }

            // Input new phone number
            chck:
            printf("\nEnter your new Phone Number: ");
            scanf("%s", tempo.phnum);

            // Validate phone number
            if (!check_phnum(tempo.phnum)) {
                printf("\n\t\t\t\t>> Invalid Phone Number..(Only numbers) <<\n");
                goto chck;
            }

            // Save changes if successful
            if (save()) {
                strcpy(temp->phnum, tempo.phnum);
                printf("\t\t\t\t[[ Changes Have been saved ]]\n");
            } else {
                printf("\t\t\t\t[[ Changes are not saved ]]\n");
            }

            found = 1;
            break;
        }
        temp = temp->next;
    }

    if (!found) {
        printf("\t\t\t\t[[ Student not found or incorrect ID/password. ]]\n");
    }
}


#endif //STUDENT_STUDENT_H
