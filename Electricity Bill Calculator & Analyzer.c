/*
Project: Electricity Bill Calculator & Analyzer
Date: 01-01-2026
Developer: Yuvraj Kumar Singh
*/

#include<stdio.h>
#include<string.h>

#define MAX_USERS 100

struct Consumer{
	char name[30];
	int room_no;
	int meter_no;
	float amount;
	float unit; 
} users[MAX_USERS];

int userCount = 0;

//function prototype
void addConsumer();


int main()
{
	int choice, user_index = -1;
	
	//main menu of program
	while(1){
		printf("\n=================================================\n");
    	printf("      Electricity Bill Calculator & Analyzer\n");
    	printf("=================================================\n");
    	printf("1. Add New Consumer\n");
    	printf("2. Display All Bills\n");
    	printf("3. Calculate Bill\n");
    	printf("4. Store Monthly Bill\n");
    	printf("5. Power Saving Tips\n");
    	printf("6. Exit\n");
    	printf("--------------------------------------------------\n");
    	printf("Enter your choice: ");
    	scanf("%d", &choice);
    	
    	switch(choice){
    		case 1:
    			addConsumer();
    			break;
    		default:
    			printf("Invalid choice! Please select a number between 1-5.\n");
    			
		}
	}
	return 0;
}
