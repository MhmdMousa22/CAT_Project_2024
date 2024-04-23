#ifndef LIBRARY_LIBRARY_H
#define LIBRARY_LIBRARY_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 88


void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/// Define the student structure
struct student {
    char name[max];
    char gender[max];
    char id[max];
    char phnum[max];
    char paswrd[max];
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

    while (fscanf(file, "%87s %87s %87s %87s %87s %d", name, gender, id, phnum, paswrd, &grd) == 6) {
        // Check if memory allocation fails
        struct student* newStudent = createStudent(id, paswrd, phnum, name, gender, grd);
        if (newStudent == NULL) {
            printf("Memory allocation failed.\n");
            fclose(file);
            return;
        }

        // Insert the new student at the beginning of the list
        newStudent->next = *head;
        *head = newStudent;
    }

    // Check if reading stopped due to a format error
    if (!feof(file)) {
        printf("Error reading file. Invalid format.\n");
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

// Saving changes or not
void save() {
    int chk;
    printf("\nDo you want to save changes ? (1) for yes (or) any other number for no.");
    scanf("%d", &chk); fflush(stdin);fflush(stdout);

    if (chk == 1) {
        writeFile(head, "file.csv"); fflush(stdin);fflush(stdout);
        printf("\n\t\t\t\t<<Student Added Successfuly>>\n");}
    else { printf("\t\t\t\t<<Data Is NOT Saved>>\n"); }
}

//Search id fuction
/*void search_ID(char* id){
    struct student *search = head;
    while (search != NULL) {
        if (strcmp(search->id, id) == 0) {
            printf("\nID Already Exists.\n");
            // Prompt for ID input again
            printf("\nEnter ID: ");
            scanf("%s", id);
            // Reset temp pointer to head for rechecking
            search = head;
        } else {
            search = search->next;
        }
    }
}*/

#endif //LIBRARY_LIBRARY_H
