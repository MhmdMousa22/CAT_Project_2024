#include<stdio.h>
 void Welcome();
void adminMode();
void userMode();

void main()
{
	int mode;
    Welcome();
  printf("Choose mode:\n1. Admin Mode\n2. User Mode\n");
    scanf("%d", &mode);
 if (mode == 1) {
        adminMode();
    } else if (mode == 2) {
        userMode();
    } else {
        printf("Invalid mode selection.\n");
    }

    return 0;
}

void Welcome(){
printf("\t\t\t\t############################################################\n\
\t\t\t\t############################################################\n\
\t\t\t\t############################################################\n\
\t\t\t\t############WELCOME TO STUDENT RECORED PROGRAM##############\n\
\t\t\t\t############################################################\n\
\t\t\t\t############################################################\n\
\t\t\t\t############################################################\n\
");}

void adminMode() {
    char admin_password[20] = "1234";
    char input_password[20];
    int attempts = 3;

    while (attempts > 0) {
        printf("Enter admin password: ");
        scanf("%s", input_password);

        if (strcmp(admin_password, input_password) == 0) {
            printf("Login successful.\n");
            break;
        } else {
            attempts--;
            printf("Incorrect password. %d attempts remaining.\n", attempts);
            if (attempts == 0) {
                printf("Login failed. Exiting...\n");
                return;
            }
        }
    }

while(1)
{   int choice;
    char back;
	back:
    printf("Admin Menu:\n");
	printf("1- Add new student\n2-Veiw one student with its ID\n");
	printf("3-veiw all students\n4-Edit student data\n5-Delete  student with its ID\n");
	printf("6-Edit admin's password\n7-Exit\n");
	printf("Enter your choice : ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
		printf("\t\t\tif you select wrong choice, you can go back by press 'b' \n");fflush(stdin);fflush(stdout);
		scanf("%c",&back);
		if(back == 'b')
		goto back;
	//calling
		break;
		case 2:
		printf("\t\t\tif you select wrong choice, you can go back by press 'b' \n");fflush(stdin);fflush(stdout);
		scanf("%c",&back);
		if(back == 'b')
		goto back;
		//calling
		break;
		case 3:
		printf("\t\t\tif you select wrong choice, you can go back by press 'b' \n");fflush(stdin);fflush(stdout);
		scanf("%c",&back);
		if(back == 'b')
		goto back;
		//calling
		break;
		case 4:
		printf("\t\t\tif you select wrong choice, you can go back by press 'b' \n");fflush(stdin);fflush(stdout);
		scanf("%c",&back);
		if(back == 'b')
		goto back;
	//calling
		break;
		case 5:
		printf("\t\t\tif you select wrong choice, you can go back by press 'b' \n");fflush(stdin);fflush(stdout);
		scanf("%c",&back);
		if(back == 'b')
		goto back;
	//calling
		break;
		case 6:
		printf("\t\t\tif you select wrong choice, you can go back by press 'b' \n");fflush(stdin);fflush(stdout);
		scanf("%c",&back);
		if(back == 'b')
		goto back;
	//calling
		break;
		case 7:
		printf("\t\t\tif you select wrong choice, you can go back by press 'b' \n");fflush(stdin);fflush(stdout);
		scanf("%c",&back);
		if(back == 'b')
		goto back;
	//calling
		break;
		default:
		printf("wrong choice...\n");
		goto back;
		break;
	}
	printf("Do you want to do other process press (y~Y) for YES and any other for NO\n");fflush(stdin);fflush(stdout);
	scanf("%c",& back);
	if(back != 'y' && back != 'Y')
	break;
}}

void userMode() {
    printf("Enter Your id:\n");

    printf("Enter your Pass:\n");

    while(1)
{   int choice;
    char back;
	back:
    printf("Student Menu:\n");
	printf("1- Veiw Your Record\n");
	printf("2-Edit Your pass\n");
	printf("3-Edit Edit Your Name\n4-Exit\n");
	printf("Enter your choice : ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
		printf("\t\t\tif you select wrong choice, you can go back by press 'b' \n");fflush(stdin);fflush(stdout);
		scanf("%c",&back);
		if(back == 'b')
		goto back;
	//calling
		break;
		case 2:
		printf("\t\t\tif you select wrong choice, you can go back by press 'b' \n");fflush(stdin);fflush(stdout);
		scanf("%c",&back);
		if(back == 'b')
		goto back;
		//calling
		break;
		case 3:
		printf("\t\t\tif you select wrong choise, you can go back by press 'b' \n");fflush(stdin);fflush(stdout);
		scanf("%c",&back);
		if(back == 'b')
		goto back;
		//calling
		break;
		case 4:
		printf("\t\t\tif you select wrong choice, you can go back by press 'b' \n");fflush(stdin);fflush(stdout);
		scanf("%c",&back);
		if(back == 'b')
		goto back;
	//calling
		break;
		default:
		printf("wrong choise...\n");
		goto back;
		break;
	}
	printf("Do you want to do other process press (y~Y) for YES and any other for NO\n");fflush(stdin);fflush(stdout);
	scanf("%c",& back);
	if(back != 'y' && back != 'Y')
	break;
}}




