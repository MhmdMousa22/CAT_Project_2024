#ifndef ADMIN_ADMIN_H
#define ADMIN_ADMIN_H

#include "Student.h"

char adpas[] = "1234";//admin's pass


void add_student()
{
    struct student *ptr = NULL;
    struct student *temp = head;
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
    scanf("%s",&ptr->name);
    printf("\nEnter their gender :");
    //get char ptr->phnum
    scanf("%s",&ptr->gender);
    printf("\nEnter ID : ");
    //get char ptr->id
    scanf("%s",&ptr->id);
    printf("\nEnter phone number :");
    //get char ptr->phnum
    scanf("%s",&ptr->phnum);
    printf("\nEnter their Password : ");
    scanf("%s",&ptr->paswrd);
    printf("\nEnter their grade : ");
    scanf("%d",&ptr->grd);

    printf("\n<<Student added successfuly>>\n");

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
            printf("\n ID : %s",temp->id);
            printf("\nname : %s",temp->name);
            printf("\n phone number :%s",temp->phnum);
            printf("\ngender : %s",temp->gender);
            printf("\n grade : %d",temp->grd);
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
        printf("there is no any student,yet...\n");
    }
    else
    {
        while(temp)
        {
            if(!strcmp( temp->id , id))
            {
                printf("\n ID : %s",temp->id);
                printf("\nname : %s",temp->name);
                printf("\n phone number :%s",temp->phnum);
                printf("\ngender : %s",temp->gender);
                printf("\n grade : %d\n",temp->grd);
                chid = 0;
                break;
            }
            temp = temp->next;
        }
        if(chid)
            printf("this ID does NOT exist\n");

    }

}

void E_student(char* id)//edit students
{

    struct student *temp = head;
    int chid=1,x = 1,r;
    if(temp == NULL)
    {
        printf("there is no any student,yet...\n");
    }
    else
    {
        while(temp)
        {
            if(!strcmp(temp->id,id))
            {
                while(x == 1)
                {
                    back:
                    printf("1-edit student's name\n2-edit student's grade\n3-both of them\n");
                    printf("choose edit operation : ");
                    scanf("%d",&r);
                    switch(r)
                    {
                        case 1:
                            printf("\t\t\tIf you want to go back, press 'b' \n");fflush(stdin);fflush(stdout);
                            printf("Enter the new name : ");
                            //get char temp->name
                            scanf("%s",&temp->name);
                            if(!strcmp(temp->name,"b"))
                                goto back;
                            break;
                        case 2:
                            printf("\t\t\tIf you want to go back, press 'b' \n");fflush(stdin);fflush(stdout);
                            printf("\nEnter the new grade(0~100) : ");
                            scanf("%d",&temp->grd);
                            if(temp->grd == (int)'b')
                                goto back;
                            break;
                        case 3:
                            printf("\t\t\tIf you want to go back, press 'b' \n");fflush(stdin);fflush(stdout);
                            printf("Enter the new name : ");
                            //get char temp->name
                            scanf("%[^\\n]",&temp->name);
                            if(!strcmp(temp->name,"b"))
                                goto back;
                            printf("\nEnter the new grade(0~100) : ");
                            scanf("%d",&temp->grd);
                            if(temp->grd == (int)'b')
                                goto back;
                            break;
                        default:
                            printf("This option does NOT exist\n");
                            goto back;
                            break;
                    }
                    printf("\nIf you want to do another operation, press (1) for YES or any other value for NO :\n");
                    scanf("%d",&x);
                }
                chid = 0;
                break;
            }
            temp = temp->next;
        }
        if(x)
            printf("this ID does NOT exist\n");
    }

}
void EA_pas()
{
    char *str;
    printf("Enter new password : ");
//get char str
    scanf("%s",&str);
    strcpy(adpas,str);
}
#endif //ADMIN_ADMIN_H
