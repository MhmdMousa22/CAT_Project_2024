#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char adpas[] = "1234";//admin's pass

struct student
{
    char id[88];
    char paswrd[88];//password
    char phnum[88];//phone number
    char name[88];
    char gender[88];
    int grd;
    struct student *next;
};
struct student *head = NULL;






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
    printf("enter the new student's name : ");
    //get char
    scanf("%s",&ptr->name);
    printf("\nEnter ID : ");
    //get char ptr->id
    scanf("%s",&ptr->id);
    printf("\nEnter phone number :");
    //get char ptr->phnum
    scanf("%s",&ptr->phnum);
    printf("\nEnter thier gender :");
    //get char ptr->phnum
    scanf("%s",&ptr->gender);
    printf("\nenter thier grade : ");
    scanf("%d",&ptr->grd);
}
void VA_student()//veiw all students
{

    struct student *temp = head;
    if(temp == NULL)
    {
        printf("there is no any student ,yet...\n");
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
                            printf("\t\t\tif you select wrong choise, you can back by press 'b' \n");
                            printf("Enter the new name : ");
                            //get char temp->name
                            scanf("%s",&temp->name);
                            if(!strcmp(temp->name,"b"))
                                goto back;
                            break;
                        case 2:
                            printf("\t\t\tif you select wrong choise, you can back by press 'b' \n");
                            printf("\nEnter the new grade(0~100) : ");
                            scanf("%d",&temp->grd);
                            if(temp->grd == (int)'b')
                                goto back;
                            break;
                        case 3:
                            printf("\t\t\tif you select wrong choise, you can back by press 'b' \n");
                            printf("Enter the new name : ");
                            //get char temp->name
                            scanf("%s",&temp->name);
                            if(!strcmp(temp->name,"b"))
                                goto back;
                            printf("\nEnter the new grade(0~100) : ");
                            scanf("%d",&temp->grd);
                            if(temp->grd == (int)'b')
                                goto back;
                            break;
                        default:
                            printf("this option does NOT exist\n");
                            goto back;
                            break;
                    }
                    printf("do you want to do other oeration for YES(1),and and any other for NO : ");
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
    printf("enter the new password : ");
//get char str
    scanf("%s",&str);
    strcpy(adpas,str);
}
int main(void)
{
    FILE *fp;
    fp = fopen ("file.txt", "rw");
    if (fp == NULL) {
        printf("File not found\n");
        return 1;
// always check for system calls fail
    }

    fclose (fp) ;
}