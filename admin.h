#ifndef ADMIN_ADMIN_H
#define ADMIN_ADMIN_H
#include "Student.h"

char adpas[30] = "1234";//admin's pass

// ADD STUDENT
void add_student()
{
    struct student *ptr = NULL;
    struct student *temp = head;
    struct student *search = head;
    char id[max];
    if(head == NULL)
    {
        ptr=(struct student*)malloc(sizeof(struct student));
        head = ptr;
    }
    else
    {
        while(temp->next != NULL )
            temp = temp->next;

        ptr=(struct student*)malloc(sizeof(struct student));
        temp->next= ptr;
    }
    ptr->next=NULL;
    printf("Enter new student's name : ");
    //get char
    strcpy(ptr->name, takestring_v2());
    printf("\nEnter their gender :");
    //get char ptr->phnum
    scanf("%s",&ptr->gender);
    //get char ptr->id
    printf("\nEnter ID : ");
    scanf("%s", id);

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
    strcpy(ptr->id, id);

    printf("\nEnter phone number :");
    //get char ptr->phnum
    scanf("%s",&ptr->phnum);
    printf("\nEnter their Password : ");
    scanf("%s",&ptr->paswrd);
    printf("\nEnter their grade : ");
    scanf("%d",&ptr->grd);

    //save();
}
void VA_student()//veiw all students
{
    struct student *temp = head;
    if(temp == NULL)
    {
        printf("There are no students yet...\n");
    }
    else
    {
        while(temp)
        {
            printf("\nName : %s",temp->name);
            printf("\nID : %s",temp->id);
            printf("\nphone number :%s",temp->phnum);
            printf("\nGender : %s",temp->gender);
            printf("\nGrade : %d\n",temp->grd);
            temp = temp->next;
        }

    }
}

void VOI_student(char* id)//veiw one id students
{

    struct student *temp = head;
    int chid=1;
    if(temp == NULL)
    {
        printf("No students yet..\n");
    }
    else
    {
        while(temp)
        {
            if(!strcmp( temp->id , id))
            {
                printf("\nName : %s",temp->name);
                printf("\nID : %s",temp->id);
                printf("\nPhone number :%s",temp->phnum);
                printf("\nGender : %s",temp->gender);
                printf("\nGrade : %d\n",temp->grd);
                chid = 0;
                break;
            }
            temp = temp->next;
        }
        if(chid)
            printf("This ID does NOT exist\n");

    }

}

void E_student(char* id)//edit students
{

    struct student *temp = head;
    int chid=1,r;
    if(temp == NULL)
    {
        printf("No students yet...\n");
    }
    else
    {
        while(temp)
        {
            if(!strcmp(temp->id,id))
            {
                    back:
                    printf("1-edit student's name\n2-edit student's grade\n3-both of them\n");
                    printf("choose edit operation : ");
                    scanf("%d",&r);
                    switch(r)
                    {
                        case 1:
                            printf("\t\t\tif you select wrong choise, you can back by press '-1' \n");
                            printf("Enter the new name : ");
                            //get char temp->name
                            strcpy(temp->name, takestring_v2());
                            if(!strcmp(temp->name,"-1"))
                                goto back;
                            //save();
                            break;
                        case 2:
                            printf("\t\t\tif you select wrong choise, you can back by press '-1' \n");
                            printf("Enter the new Grade : ");
                            //get char temp->name
                            scanf("%d",&temp->grd);
                            if(temp->grd == -1)  {goto back;}
                            //save();
                            break;
                        case 3:
                            printf("\t\t\tif you select wrong choise, you can back by press '-1' \n");
                            printf("Enter the new name : ");
                            //get char temp->name
                            strcpy(temp->name, takestring_v2());
                            if(!strcmp(temp->name,"-1"))
                                goto back;
                            printf("Enter the new Grade : ");
                            scanf("%d",&temp->grd);
                            //save();
                            break;
                        default:
                            printf("This option does NOT exist\n");
                            goto back;
                            break;
                }
                chid = 0;
                break;
            }
            temp = temp->next;
        }
        if(chid)
            printf("This ID does NOT exist\n");
    }

}

//Delete student function
void DeleteStudent(char *id)  //delete  student with its id
{
    if(head){
        struct student *temp = head;
        struct student* pre=NULL;
        while (temp){
            if(!strcmp(temp->id,id)){
                if(pre){
                    pre->next=temp->next;
                }
                else{
                    head=temp->next;

                }
                free(temp);
            }

            pre=temp;
            temp=temp->next;
        }
    }
    //save();
}


//Edit admin password
void EA_pas()
{
    char str[30], str1[30];
    printf("Enter new password : ");
    fflush(stdin); fflush(stdout);
//get char str
    scanf("%s",&str);

    printf("Confirm new password : ");
    fflush(stdin); fflush(stdout);
//get char str
    scanf("%s",&str1);
    if(!strcmp(str, str1)){
        strcpy(adpas,str);
        printf("\t\t\t\t Password Updated Successfully\n");
    }
    else {printf("\t\t\t\t Password Is NOT Updated\n");}

}
#endif //ADMIN_ADMIN_H
