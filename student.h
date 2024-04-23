#ifndef STUDENT_STUDENT_H
#define STUDENT_STUDENT_H

#include "library.h"

char check[20]; // check another operations choice

void voi_student() { // view student record
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
            // ID and password match, display student record
            printf("\n ID : %s", temp->id);
            printf("\nname : %s", temp->name);
            printf("\nphone number : %s", temp->phnum);
            printf("\ngender : %s", temp->gender);
            printf("\ngrade : %d\n", temp->grd);
            found = 1;
            break;
        }
        temp = temp->next;
    }

    if (!found) {
        printf("Student not found or incorrect ID/password.\n");
    }
}

void e_name() {  // edit student name
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
            // ID and password match, allow user to edit name
            printf("Enter the new name: ");
            scanf("%s", temp->name);
            printf("Name updated successfully.\n");
            found = 1;
            break;
        }
        temp = temp->next;
    }

    if (!found) {
        printf("Student not found or incorrect ID/password.\n");
    }
}

void e_pass() { // edit student pass
    char id[88];
    char pass[88];
    char new_pass[88];

    // Ask user for ID and password
    printf("Enter your ID: ");
    scanf("%s", id);
    printf("Enter your current password: ");
    scanf("%s", pass);

    struct student *temp = head;
    int found = 0;

    while (temp != NULL) {
        if (strcmp(temp->id, id) == 0 && strcmp(temp->paswrd, pass) == 0) {
            // ID and password match, allow user to edit password
            printf("Enter your new password: ");
            scanf("%s", new_pass);
            strcpy(temp->paswrd, new_pass);
            printf("Password updated successfully.\n");
            found = 1;
            break;
        }
        temp = temp->next;
    }

    if (!found) {
        printf("Student not found or incorrect ID/password.\n");
    }
}

void e_phnum() {  // edit student phone number
    char id[88];
    char pass[88];
    char new_phnum[88];

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
            printf("Enter your new phone number: ");
            scanf("%s", new_phnum);
            strcpy(temp->phnum, new_phnum);
            printf("Phone number updated successfully.\n");
            found = 1;
            break;
        }
        temp = temp->next;
    }

    if (!found) {
        printf("Student not found or incorrect ID/password.\n");
    }
}


#endif //STUDENT_STUDENT_H
