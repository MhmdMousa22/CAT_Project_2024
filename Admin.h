#ifndef PROJECT_ADMIN_H
#define PROJECT_ADMIN_H

#include "Student.h"

//ADD STUDENT
void add_student();

//VIEW ALL STUDENTS
void VA_student();

//VIEW ONE STUDENT (BY ID)
void VOI_student(char* id);

//EDIT STUDENTS
void E_student(char* id);

//DELETE STUDENT FUNCTION (delete student with their id)
void DeleteStudent(char *id);

//EDIT ADMIN'S PASSWORD
void EA_pas();

#endif //PROJECT_ADMIN_H
