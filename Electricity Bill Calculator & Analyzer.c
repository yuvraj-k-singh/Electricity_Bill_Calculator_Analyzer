/*
Project: Electricity Bill Calculator & Analyzer
Date: 01-01-2026
Developer: Yuvraj Kumar Singh
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

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
    	printf("2. Calculate Bill\n");
    	printf("3. ADD New Bill\n");
    	printf("4. Analyze Monthly Bill\n");
    	printf("5. Power Saving Tips\n");
    	printf("6. Exit\n");
    	printf("--------------------------------------------------\n");
    	printf("Enter your choice: ");
    	scanf("%d", &choice);
    	
    	switch(choice){
    		case 1:
    			addConsumer();
    			break;
    		case 6:
    			printf("Thank you for using, Use again!\n");
    			printf("Exiting program.......");
    			exit(0);
    		default:
    			printf("Invalid choice! Please select a number between 1-5.\n");
    			
		}
	}
	return 0;
}

void addConsumer(){
	int i;

    if (userCount >= MAX_USERS) {
        printf("Maximum consumers reached!\n");
        return;
    }

    getchar(); // clear input buffer

    printf("Enter Consumer Name: ");
    fgets(users[userCount].name, sizeof(users[userCount].name), stdin);

    // remove newline
    users[userCount].name[strcspn(users[userCount].name, "\n")] = '\0';

    // check duplicate consumer
    for (i = 0; i < userCount; i++) {
        if (strcmp(users[i].name, users[userCount].name) == 0) {
            printf("Consumer already exists! Enter a different name.\n");
            return;
        }
    }

    printf("Enter Consumer Room No: ");
    scanf("%d", &users[userCount].room_no);

    printf("Enter Consumer Meter No: ");
    scanf("%d", &users[userCount].meter_no);

    users[userCount].unit = 0;
    users[userCount].amount = 0.0;

    userCount++;

    printf("Consumer added successfully!\n");
}
