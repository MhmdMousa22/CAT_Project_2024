#ifndef ADMIN_ADMIN_H
#define ADMIN_ADMIN_H
#include "Student.h"

// ADD STUDENT "done"
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
    ptr->name = (char*)malloc(max * sizeof(char));
    strcpy(ptr->name, takestring_v2());

    printf("\nEnter their gender : ");
    //get char ptr->phnum
    scanf("%s", ptr->gender);

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

    check1:
    printf("\nEnter phone number : ");
    //get char ptr->phnum
    scanf("%s", ptr->phnum);

    if(!check_phnum(ptr->phnum)) {
        printf("\nInvalid Phone Number..(Only numbers)");
        goto check1;}

    ptr->paswrd = (char*)malloc(max * sizeof(char));
    printf("\nEnter their Password : ");
    strcpy(ptr->paswrd, takestring_v2());
    //checking grade 1
    check2:
    printf("\nEnter their grade : ");
    scanf("%s",ptr->grd);

    if(!check_Grade(ptr->grd)) {
        printf("\nInvalid Grade..(0 ~ 100)");
        goto check2;}

    //save_ADD(ptr);
}
void VA_student() //veiw all students
{
    struct student *temp = head;
    char* reverted = NULL;
    reverted = (char*)malloc(strlen(temp->name) + 1);
    //strcpy(reverted, temp->name);
    if(temp == NULL)
    {
        printf("There are no students yet...\n");
    }
    else
    {
        while(temp)
        {
            strcpy(reverted, temp->name);
            printf("\nName : %s",revert_spaces(reverted));
            printf("\nID : %s",temp->id);
            printf("\nphone number : %s",temp->phnum);
            printf("\nGender : %s",temp->gender);
            printf("\nGrade : %s\n",temp->grd);
            temp = temp->next;
        }
        free(reverted);
    }
}

void VOI_student(char* id) //veiw one id students
{

    struct student *temp = head;
    int chid=1;
    char* reverted = NULL;
    reverted = (char*)malloc(strlen(temp->name) + 1);

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
                strcpy(reverted, temp->name);
                printf("\nName : %s",revert_spaces(reverted));
                printf("\nID : %s",temp->id);
                printf("\nPhone number : %s",temp->phnum);
                printf("\nGender : %s",temp->gender);
                printf("\nGrade : %s\n",temp->grd);
                chid = 0;
                break;
            }
            temp = temp->next;
        }
        free(reverted);

        if(chid)
            printf("This ID does NOT exist\n");

    }

}

// (DONE)
void E_student(char* id) //edit students
{

    struct student *temp = head;
    int chid=1,r;

    temp->name = (char*)malloc(max * sizeof(char));
    tempo.name = (char*)malloc(max * sizeof(char));

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
                        printf("\t\t\tIf you want to go back, press (b) \n");
                        printf("Enter the new name : ");

                        strcpy(tempo.name, takestring_v2());
                        if(!strcmp(tempo.name,"b"))
                            goto back;

                        (save())? strcpy(temp->name, tempo.name) && printf("\t\t\t\t[[ Changes Have been saved ]]\n"): printf("\t\t\t\t[[ Changes are not saved ]]\n");

                        break;
                    case 2:
                        printf("\t\t\tIf you want to go back, press (b) \n");

                    check:
                        printf("\nEnter their grade : ");
                        scanf("%s",tempo.grd);

                        if(!check_Grade(tempo.grd)) {
                            printf("\nInvalid Grade..(0 ~ 100)");
                            goto check;}

                        (save())? strcpy(temp->grd, tempo.grd) && printf("\t\t\t\t[[ Changes Have been saved ]]\n"): printf("\t\t\t\t[[ Changes are not saved ]]\n");
                        break;
                    case 3:
                        printf("\t\t\tIf you want to go back, press (b) \n");
                        printf("Enter the new name : ");
                        //get char tempo.name
                        strcpy(tempo.name, takestring_v2());  fflush(stdin); fflush(stdout);
                        if(!strcmp(tempo.name,"b"))
                            goto back;
                    check2:
                        printf("\nEnter their grade : ");
                        scanf("%s",tempo.grd);  fflush(stdin); fflush(stdout);

                        if(!check_Grade(tempo.grd)) {
                            printf("\nInvalid Grade..(0 ~ 100)");
                            goto check2;}

                        (save())? strcpy(temp->name, tempo.name) && strcpy(temp->grd, tempo.grd) && printf("\t\t\t\t[[ Changes Have been saved ]]\n"): printf("\t\t\t\t[[ Changes are not saved ]]\n");
                        break;
                    default:
                        printf("[[ This option does NOT exist .. Choose Again ]]\n");
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
    int found = 0;
    char check[10];
    printf("Are you sure you want to delete this student? Press (Y) for Yes or anything else for No : ");
    strcpy(check, takestring_v2());

    if ( strcmp(check, "Y") && strcmp(check, "y") ){
        printf("\t\t\t\t[[ Student is NOT deleted ]]\n");
    }
    else {
        if (head) {
            struct student *temp = head;
            struct student *pre = NULL;
            while (temp) {
                if (!strcmp(temp->id, id)) {
                    if (pre) {
                        pre->next = temp->next;
                    } else {
                        head = temp->next;

                    }
                    //struct student* ptr = temp;
                    free(temp);
                    found = 1;
                    printf("\t\t\t\t[[ Student is deleted successfully ]]\n");
                    break;
                }

                pre = temp;
                temp = temp->next;
            }
        }
        if(!found)
            printf("This ID already does NOT exist\n");
        //writeFile(head, "file.csv");
    }
}


//Edit admin password
void EA_pas()
{
    char str[30], str1[30];
    printf("Enter new password : ");
    getchar();
//get char str
    scanf("%s", str);

    printf("Confirm new password : ");
    getchar();
//get char str
    scanf("%s", str1);
    if(!strcmp(str, str1)){
        //strcpy(adpas,str);
        //printf("\t\t\t\t Password Updated Successfully\n");
        (save())? strcpy(adpas,str) && printf("\t\t\t\t[[ Password Updated Successfully ]]\n") : printf("\t\t\t\t[[ Changes are not saved ]]\n");
    }
    else {printf("\t\t\t\t[[ Password Is NOT Updated ]]\n");}

}

#endif //ADMIN_ADMIN_H
