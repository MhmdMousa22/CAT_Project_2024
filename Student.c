#include "Student.h"

// view student record
void voi_student(struct student* temp) {

    char* reverted = NULL;
    reverted = (char*)malloc(strlen(temp->name) + 1);

                strcpy(reverted, temp->name);
                printf("\nName : %s", revert_spaces(reverted));
                printf("\nID : %s", temp->id);
                printf("\nPhone number : %s", temp->phnum);
                printf("\nGender : %s", temp->gender);
                printf("\nGrade : %s\n", temp->grd);

    free(reverted);
}

// edit student name
void e_name(struct student* temp) {

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
            chck:
            printf("Enter the new name: ");
            strcpy(tempo.name, takestring_v2());
            if(!check_name(tempo.name)) {
                printf("\nInvalid Name..(Only Letters)\n");
                goto chck;}

            // Save changes if successful
            if (save()) {
                strcpy(temp->name, tempo.name);
                printf("\t\t\t\t[[ Changes have been saved ]]\n");
            } else {
                printf("\t\t\t\t[[ Changes are not saved ]]\n");
            }

            // Free dynamically allocated memory
            free(tempo.name);
}

void e_pass(struct student* temp) { // edit student pass
    char cnfrm_pass[max]; // Increase size to accommodate passwords

            tempo.paswrd = (char*)malloc(max * sizeof(char)); // Allocate memory for new password

            if (tempo.paswrd == NULL) {
                printf("Memory allocation failed.\n");
                //free(pass); // Free allocated memory before returning
                return;
            }
    back2:
            printf("Enter your old password : ");
            scanf("%s", tempo.paswrd);
            if(!strcmp(tempo.paswrd, temp->paswrd)){
                // ID and password match, allow user to edit password
                printf("\nEnter your new password: ");
                scanf("%s", tempo.paswrd);

                printf("Confirm new password : "); fflush(stdin); fflush(stdout);
                scanf("%s", cnfrm_pass);

                if(strcmp(tempo.paswrd, cnfrm_pass) == 0) { // Compare passwords
                    strcpy(temp->paswrd, tempo.paswrd); // Update password
                    printf("\t\t\t\t Password Updated Successfully\n");
                } else {
                    printf("\t\t\t\t Passwords do not match. Password not updated.\n");
                }
            }
            else {
                printf("\n[[ Wrong Password .. Enter Again ]]");
                goto back2;
            }
            free(tempo.paswrd); // Free memory allocated for new_pass
}

void e_phnum(struct student* temp) {  // edit student phone number
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
}