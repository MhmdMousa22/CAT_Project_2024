#ifndef LIBRARY_LIBRARY_H
#define LIBRARY_LIBRARY_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// Define the student structure
struct student {
    char name[88];
    char gender[88];
    char id[88];
    char phnum[88];
    char paswrd[88];
    int grd;
    struct student *next;
};
struct student *head = NULL;

// Function to create a new student node
struct student* createStudent(char id[], char paswrd[], char phnum[], char name[], char gender[], int grd) {
    struct student* newStudent = (struct student*)malloc(sizeof(struct student));
    if (newStudent == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    strcpy(newStudent->name, name);
    strcpy(newStudent->gender, gender);
    strcpy(newStudent->id, id);
    strcpy(newStudent->phnum, phnum);
    strcpy(newStudent->paswrd, paswrd);
    newStudent->grd = grd;
    newStudent->next = NULL;
    return newStudent;
}

// Function to read data from file into linked list
void readFile(struct student** head, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }
    char id[88], paswrd[88], phnum[88], name[88], gender[88];
    int grd;
    while (fscanf(file, "%s %s %s %s %s %d", name, gender, id, phnum, paswrd, &grd) != EOF) {
        struct student* newStudent = createStudent(name, gender, id, phnum, paswrd, grd);
        newStudent->next = *head;
        *head = newStudent;
    }
    fclose(file);
}

// Function to write data from linked list to file
void writeFile(struct student* head, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }
    struct student* current = head;
    while (current != NULL) {
        fprintf(file, "%s %s %s %s %s %d\n", current->name, current->gender, current->id, current->phnum, current->paswrd, current->grd);
        current = current->next;
    }
    fclose(file);
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

#endif //LIBRARY_LIBRARY_H
