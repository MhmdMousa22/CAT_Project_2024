#ifndef PROJECT_LIBRARY_H
#define PROJECT_LIBRARY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

// Global Declarations
#define max 88
extern char adpas[30];
extern char check[4];

/// Define the student structure
struct student {
    char *name;
    char gender[max];
    char id[max];
    char phnum[max];
    char *paswrd;
    char grd[8];
    struct student *next;
};
extern struct student *head;

//Global temporarely object to save data temporarely
struct student tempo;


//FUNCTION TO CREATE A STUDENT AND STORE THEM IN A STRUCTURE
struct student *createStudent(char id[], char *paswrd, char phnum[], char *name, char gender[], char grd[]);

//TAKING STRING AS INPUT DYNAMICALLY "FUNCTION"
char *takestring_v2();

//SAVING CHANGES MADE FUNCTION
bool save();

//FUNCTION TO REVERT SPACES
char *revert_spaces(char *name);

//PHONE NUMBER VALIDATION
bool check_phnum(const char *phnum); //Checking

//GRADE VALIDATION
bool check_Grade(const char *grade); //Checking

// @ FILE HANDLING >>
//READ FILE [File Handling]
void readFile(struct student **head, const char *filename);

//WRITE FILE [File Handling]
void writeFile(struct student *head, const char *filename);

//ADMIN PASSWORD WRITE FILE [File Handling]
void admin_File(char current[], const char *filename);

//ADMIN PASSWORD READ FILE [File Handling]
void admin_read(char pass[30], const char *filename);

//Free list function
void freeList(struct student *header);

//Validate Name
bool check_name(const char* name);

#endif //PROJECT_LIBRARY_H
