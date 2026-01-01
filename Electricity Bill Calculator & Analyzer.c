/*
Project: Electricity Bill Calculator & Analyzer
Date: 01-01-2026
Developer: Yuvraj Kumar Singh
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_USERS 100
#define FIXED 50.00
#define METER_RENT 10.00

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
void calculateBill();
void analyzeBill();

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
    	printf("3. Analyze Monthly Bill\n");
    	printf("4. ADD New Bill\n");
    	printf("5. Power Saving Tips\n");
    	printf("6. Exit\n");
    	printf("--------------------------------------------------\n");
    	printf("Enter your choice: ");
    	scanf("%d", &choice);
    	
    	switch(choice){
    		case 1:
    			addConsumer();
    			break;
    		case 2:
    			calculateBill();
    			break;
    		case 3:
    			analyzeBill();
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

//1. add consumer
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

//2. calculate bill
void calculateBill(){
	printf("\n---------CALCULATE BILL----------\n");
	int unit = 0;
	float amount = 0;
	
	printf("Enter unit consumed: ");
	scanf("%d", &unit);
	
	if(unit <= 50){
		amount = unit * 4.27;
	} else if(unit >= 51 && unit <= 150){
		amount = unit * 5.23;
	} else if(unit >= 151 && unit <= 300){
		amount = unit * 6.61;
	} else if(unit >= 301){
		amount = unit * 6.80;
	}
	
	amount += FIXED + METER_RENT;
	
	printf("\nUnits Used    : %d", unit);
	printf("\nFixed Price   : RS %.2f", FIXED);
	printf("\nMeter Rent    : RS %.2f", METER_RENT);
    printf("\nTotal Bill    : RS %.2f", amount);
    printf("\n----------------------------------\n");
    return;
}

