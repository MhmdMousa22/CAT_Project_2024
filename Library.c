#include "Library.h"

struct student *head = NULL; // Definition (initialization) of head pointer
char check[4];

// Function to create a new student node
struct student* createStudent(char* id, char* paswrd, char* phnum, char* name, char* gender, char* grd) {
    struct student* newStudent = malloc(sizeof(struct student));
    if (newStudent == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    newStudent->name = (char*)malloc(max * sizeof(char));
    newStudent->paswrd = (char*)malloc(max * sizeof(char));

    newStudent->name = strdup(name);
    strcpy(newStudent->gender, gender);
    strcpy(newStudent->id, id);
    strcpy(newStudent->phnum, phnum);
    newStudent->paswrd = strdup(paswrd);
    strcpy(newStudent->grd, grd);
    newStudent->next = NULL;

    if (newStudent->name == NULL || newStudent->paswrd == NULL) {
        printf("Memory allocation failed.\n");
        free(newStudent); // Free allocated memory before returning
        return NULL;
    }
    return newStudent;
}

// Function to read data from file into linked list
void readFile(struct student** header, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    char id[max], paswrd[max], phnum[max], name[max], gender[max], grd[8];

    while (fscanf(file, "%87s %87s %87s %87s %87s %5s", name, gender, id, phnum, paswrd, grd) == 6)
    {
        // Check if memory allocation fails
        struct student* newStudent = createStudent(id, paswrd, phnum, name, gender, grd);
        if (newStudent == NULL) {
            printf("Memory allocation failed.\n");
            fclose(file);
            return;
        }

        // Insert the new student at the beginning of the list
        newStudent->next = *header;
        *header = newStudent;
    }

    // Check if reading stopped due to a format error
    if (!feof(file)) {
        printf("Error reading file. Invalid format.\n");
    }

    fclose(file);
}


// Function to write data from linked list to file
void writeFile(struct student* header, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }
    struct student* current = header;
    while (current != NULL) {
        fprintf(file, "%s %s %s %s %s %s\n", current->name, current->gender, current->id, current->phnum, current->paswrd, current->grd);
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
        if (t == ' ') {
            t = '_';
        }
    }
    fflush(stdin); fflush(stdout);
    if(len == 1)  return takestring_v2();
    if(*s == ' ') {
        printf("Cannot Start With Spaces!\nEnter Again: ");
        return takestring_v2();
    }

    return s;
}

// Saving changes
bool save() {
    //char check[4];
    printf("\nDo you want to Save changes? Press (Y) for yes or any other thing for No : ");
    scanf("%s", check);
    if (!strcmp(check, "Y") || !strcmp(check, "y")) return true;
    else return false;
}

//Revert spaces in names
char* revert_spaces(char* name){

    for(int i = 0; i< strlen(name); i++) {
        if (name [i] == '_') {
            name [i] = ' ';
        }
    }
    return name;
}

//check grade
bool check_Grade(const char* grade) {
    // Check if the string contains only numeric characters
    for (int i = 0; grade[i] != '\0'; i++) {
        if (!isdigit(grade[i])) {
            return false; // Non-numeric character found
        }
    }
    // Convert the string to an integer
    int numGrade = atoi(grade);

    // Check if the converted integer is within the valid range
    if (numGrade >= 0 && numGrade <= 100) {
        return true; // Grade is valid
    } else {
        return false; // Grade is invalid
    }
}

//check phone number validation
bool check_phnum(const char* phnum) {
    // Check if the string contains only numeric characters
    for (int i = 0; phnum[i] != '\0'; i++) {
        if (!isdigit(phnum[i])) {
            return false; // Non-numeric character found
        }
    }
    return true;

}

//check phone number validation
bool check_name(const char* name) {
    // Check if the string contains only numeric characters
    for (int i = 0; name[i] != '\0'; i++) {
        if (isdigit(name[i])) {
            return false; // Non-numeric character found
        }
    }
    return true;

}


//admin password write file
void admin_File(char current[], const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }
    fprintf(file, "%s" ,current);

    fclose(file);
}


//admin password read file
//Function to read data from file into linked list
void admin_read(char pass[30], const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    // Read the password from the file
    if (fscanf(file, "%29s", pass) != 1) {
        printf("Error reading password from file.\n");
        fclose(file);
        return;
    }

    fclose(file);

    // Update the global admin password variable
    strcpy(adpas, pass);
}

void freeList(struct student *header) {
    struct student *current = header;
    struct student *next;

    while (current != NULL) {
        next = current->next; // Store the next pointer before freeing the current node
        free(current); // Free the memory allocated for the current node
        current = next; // Move to the next node
    }
}