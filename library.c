#include "library.h"

//FUNCTION TO CREATE A STUDENT AND STORE THEM IN A STRUCTURE
struct student* createStudent(char id[], char* paswrd, char phnum[], char* name, char gender[], char grd[]);

//TAKING STRING AS INPUT DYNAMICALLY "FUNCTION"
char * takestring_v2();

//SAVING CHANGES MADE FUNCTION
bool save();

//FUNCTION TO REVERT SPACES
char* revert_spaces(char* name);

//PHONE NUMBER VALIDATION
bool check_phnum(const char* phnum); //Checking

//GRADE VALIDATION
bool check_Grade(const char* grade); //Checking

// @ FILE HANDLING >>
//READ FILE [File Handling]
void readFile(struct student** head, const char* filename);

//WRITE FILE [File Handling]
void writeFile(struct student* head, const char* filename);

//ADMIN PASSWORD WRITE FILE [File Handling]
void admin_File(char current[], const char* filename);

//ADMIN PASSWORD READ FILE [File Handling]
void admin_read(char pass[30], const char* filename);