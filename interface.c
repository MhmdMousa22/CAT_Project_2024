#include<stdio.h>
void main()
{
	int ad_choi;//admon choise
	char back;
printf("\t\t\t\t############################################################\n\
\t\t\t\t############################################################\n\
\t\t\t\t############################################################\n\
\t\t\t\t############WELCOME TO STUDENT RECORED PROGRAM##############\n\
\t\t\t\t############################################################\n\
\t\t\t\t############################################################\n\
\t\t\t\t############################################################\n\
");









//adnim

while(1)
{
	back:
	printf("1- Add new student\n2-Veiw one student with its ID\n");
	printf("3-veiw all students\n4-Edit student data\n5-Delete  student with its ID\n");
	printf("6-Edit admin's password\n7-Exit\n");
	printf("Enter your choise : ");
	scanf("%d",&ad_choi);
	switch(ad_choi)
	{
		case 1:
		printf("\t\t\tif you select wrong choise, you can go back by press 'b' \n");fflush(stdin);fflush(stdout);
		scanf("%c",&back);
		if(back == 'b')
		goto back;
	//calling
		break;
		case 2:
		printf("\t\t\tif you select wrong choise, you can go back by press 'b' \n");fflush(stdin);fflush(stdout);
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
		printf("\t\t\tif you select wrong choise, you can go back by press 'b' \n");fflush(stdin);fflush(stdout);
		scanf("%c",&back);
		if(back == 'b')
		goto back;
	//calling
		break;
		case 5:
		printf("\t\t\tif you select wrong choise, you can go back by press 'b' \n");fflush(stdin);fflush(stdout);
		scanf("%c",&back);
		if(back == 'b')
		goto back;
	//calling
		break;
		case 6:
		printf("\t\t\tif you select wrong choise, you can go back by press 'b' \n");fflush(stdin);fflush(stdout);
		scanf("%c",&back);
		if(back == 'b')
		goto back;
	//calling
		break;
		case 7:
		printf("\t\t\tif you select wrong choise, you can go back by press 'b' \n");fflush(stdin);fflush(stdout);
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
}


}