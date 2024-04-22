#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char adpas[] = "1234";//admin's password
char check[20]; // check another operations choice

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


void VOI_student(char* id) //veiw student
{

    struct student *temp = head;
    int chid=1;
    if(temp == NULL)
    {
        printf("ID doesn't exist..\n");
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
            printf("ID not found..\n");

    }

}

void E_student(char* id) //edit student
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
                    printf("1-edit student's name\n2-edit student's phone number\n3-edit student's password\n");
                    printf("choose edit operation : ");
                    scanf("%d",&r);
                    switch(r)
                    {
                        case 1: // Edit name
                            printf("\t\t\tif you select wrong choise, you can back by press 'b' \n");
                            printf("Enter the new name : ");
                            //get char temp->name
                            scanf("%s",&temp->name);
                            if(!strcmp(temp->name,"b"))
                                goto back;
                            break;
                        case 2: //Edit phone number
                            printf("\t\t\tif you select wrong choise, you can back by press 'b' \n");
                            printf("\nEnter new Phone Number : ");
                            scanf("%d",&temp->phnum);
                            if(temp->phnum == (int)'b')
                                goto back;
                            break;
                        case 3: // Edit password
                            printf("\t\t\tif you select wrong choise, you can back by press 'b' \n");
                            printf("Enter new password : ");
                            //get char temp->name
                            scanf("%s",&temp->paswrd);
                            if(!strcmp(temp->paswrd,"b"))
                                goto back;
                            break;
                        default:
                            printf("Option doesn't exist, please choose another option.\n");
                            goto back;
                            break;
                    }
                    printf("Do you want to do another operation? (Y) for Yes or any other value for No : ");
                    scanf("%s",&check);
                }
                chid = 0;
                break;
            }
            temp = temp->next;
        }
        if(check == 'Y')
            goto back;
    }

}

void main()
{
    VOI_student("148");
    E_student("148");
    VOI_student("148");

}