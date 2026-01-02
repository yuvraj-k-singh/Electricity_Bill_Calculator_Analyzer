/*
Project: Electricity Bill Calculator & Analyzer
Date: 01-01-2026
Developer: Yuvraj Kumar Singh
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_USERS 25
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
void addBill();
void powerSaving();
void saveData();
void loadData();

int main()
{
	loadData();
	int choice, user_index = -1;
	
	//main menu of program
	while(1){
		printf("\n=================================================\n");
    	printf("      Electricity Bill Calculator & Analyzer\n");
    	printf("=================================================\n");
    	printf("1. Add New Consumer\n");
    	printf("2. Calculate Bill\n");
    	printf("3. Analyze Monthly Bill\n");
    	printf("4. Add New Bill\n");
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
    		case 4:
    			addBill();
    			break;
    		case 5:
    			powerSaving();
    			break;
    		case 6:
    			printf("Thank you for using, Use again!\n");
    			saveData();
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
	
	printf("\n---------ADD NEW CONSUMER----------\n");

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
    printf("\n-----------------------------------\n");
    saveData();
    return;
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

//3. Analyze Bill
void analyzeBill(){
	
	//check if user is available or not
	if (userCount == 0) {
    	printf("No consumer data available to analyze!\n");
    	return;
	}

	char maxName[30];
	char minName[30];
	int maxUnit = users[0].unit;
	int minUnit = users[0].unit;
    float maxAmount = users[0].amount;
    float minAmount = users[0].amount;
    strcpy(maxName, users[0].name);
    strcpy(minName, users[0].name);
    int maxRoom = users[0].room_no, i;
    int minRoom = users[0].room_no;
    
	printf("\n-----------ANALYZE BILL-----------\n");
	
	//find max and min units user
	for(i=0; i<userCount; i++){
		if(maxUnit < users[i].unit){
			maxUnit = users[i].unit;
			maxAmount = users[i].amount;
			maxRoom = users[i].room_no;
			strcpy(maxName, users[i].name);
		}
		
		if(minUnit > users[i].unit){
			minUnit = users[i].unit;
			minAmount = users[i].amount;
			minRoom = users[i].room_no;
			strcpy(minName, users[i].name);
		}
	}
	
	printf("\n1. Max Unit: \n");
	printf("\nName          : %s", maxName);
    printf("\nRoom Number   : %d", maxRoom);
    printf("\nAmount        : %.2f", maxAmount);
    printf("\nUnits Used    : %d", maxUnit);
    
    printf("\n");
    
    printf("\n2. Min Unit: \n");
	printf("\nName          : %s", minName);
    printf("\nRoom Number   : %d", minRoom);
    printf("\nAmount        : %.2f", minAmount);
    printf("\nUnits Used    : %d", minUnit);
	printf("\n----------------------------------\n");
}

//4. Add bill
void addBill(){
	char name[30];
	int i, userIndex = -1, units = 0;
	float amounts = 0;
	printf("\n-----------ADD NEW BILL-----------\n");

	getchar(); // clear input buffer
	printf("Enter Consumer Name: ");
	fgets(name, sizeof(name), stdin);
	
	name[strcspn(name, "\n")] = '\0';
	
	//check consumer
	for(i=0; i<userCount; i++){
		if(strcmp(name, users[i].name) == 0){
			userIndex = i;
			break;
		}
	}
	
	//if user is not available
	if(userIndex == -1) {
		printf("No Consumer Name Founded, Try again!\n");
		printf("\n-----------------------------------\n");
		return;
	}
	
	//reset user unit to 0 every time so new unit will update
	users[userIndex].unit = 0;
	users[userIndex].amount = 0.00;
	
	printf("Enter unit consumed: ");
	scanf("%d", &units);
	
	if(units <= 50){
		amounts = units * 4.27;
	} else if(units >= 51 && units <= 150){
		amounts = units * 5.23;
	} else if(units >= 151 && units <= 300){
		amounts = units * 6.61;
	} else if(units >= 301){
		amounts = units * 6.80;
	}
	
	amounts += FIXED + METER_RENT;
	
	users[userIndex].amount = amounts;
	users[userIndex].unit = units;
	printf("Bill Added Successfully..............\n");
	printf("\n-----------------------------------\n");
	saveData();
	return;
}


//5. Power saving tips
void powerSaving(){
	printf("\n---------POWER SAVING TIPS----------\n");
	printf("1. Use LED bulbs\n");
    printf("2. Turn off appliances when not in use\n");
    printf("3. Use energy-efficient devices\n");
    printf("4. Avoid excessive AC usage\n");
    printf("5. Use natural light");
    printf("\n-----------------------------------\n");
}


//6. saveData
void saveData(){
    FILE *fp;
    int i;

    if (userCount == 0) {
        printf("No data available to save!\n");
        return;
    }

    fp = fopen("electricity_data.txt", "w");

    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    fprintf(fp, "Total Consumers: %d\n\n", userCount);

    for (i = 0; i < userCount; i++) {
        fprintf(fp, "Name      : %s\n", users[i].name);
        fprintf(fp, "Room No   : %d\n", users[i].room_no);
        fprintf(fp, "Meter No  : %d\n", users[i].meter_no);
        fprintf(fp, "Units     : %.2f\n", users[i].unit);
        fprintf(fp, "Amount    : RS %.2f\n", users[i].amount);
        fprintf(fp, "--------------------------\n");
    }

    fclose(fp);
    printf("Data saved successfully in text file!\n");
}

void loadData(){
	    FILE *fp;
    int i;

    fp = fopen("electricity_data.txt", "r");

    if (fp == NULL) {
        // File not found is NOT an error (first run)
        printf("No previous data found. Starting fresh.\n");
        return;
    }

    // Read total consumers
    fscanf(fp, "Total Consumers: %d\n\n", &userCount);

    if (userCount > MAX_USERS) {
        printf("Data file corrupted!\n");
        fclose(fp);
        userCount = 0;
        return;
    }

    for (i = 0; i < userCount; i++) {
        fscanf(fp, "Name      : %[^\n]\n", users[i].name);
        fscanf(fp, "Room No   : %d\n", &users[i].room_no);
        fscanf(fp, "Meter No  : %d\n", &users[i].meter_no);
        fscanf(fp, "Units     : %f\n", &users[i].unit);
        fscanf(fp, "Amount    : RS %f\n", &users[i].amount);
        fscanf(fp, "--------------------------\n");
    }

    fclose(fp);
    printf("Previous data loaded successfully!\n");
}

