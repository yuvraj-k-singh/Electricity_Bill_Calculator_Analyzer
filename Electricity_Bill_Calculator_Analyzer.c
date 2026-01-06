/*
Project: Electricity Bill Calculator & Analyzer
Date: 01-01-2026
Developer: Yuvraj Kumar Singh
Revised: 6-01-2026
Improvements: Fixed data types, billing logic, input handling, and file operations
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_USERS 25
#define FIXED 50.00
#define METER_RENT 10.00

struct Consumer
{
	char name[30];
	int room_no;
	int meter_no;
	float amount;
	int unit;
} users[MAX_USERS];

int userCount = 0;
int silentSave = 0;

void addConsumer();
void calculateGenericBill();
void analyzeBill();
void addBill();
void powerSaving();
void saveData();
void loadData();
void clearInputBuffer();

void clearInputBuffer()
{
	int c;
	while ((c = getchar()) != '\n' && c != EOF)
		;
}

int main()
{
	loadData();
	int choice;

	while (1)
	{
		printf("\n=================================================\n");
		printf("      Electricity Bill Calculator & Analyzer\n");
		printf("=================================================\n");
		printf("1. Add New Consumer\n");
		printf("2. Calculate Generic Bill\n");
		printf("3. Analyze Monthly Bill\n");
		printf("4. Add New Bill to Consumer\n");
		printf("5. Power Saving Tips\n");
		printf("6. Exit\n");
		printf("--------------------------------------------------\n");
		printf("Enter your choice: ");

		if (scanf("%d", &choice) != 1)
		{
			printf("Invalid input! Please enter a number.\n");
			clearInputBuffer();
			continue;
		}

		switch (choice)
		{
		case 1:
			addConsumer();
			break;
		case 2:
			calculateGenericBill();
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
			silentSave = 0;
			saveData();
			printf("Exiting program.......\n");
			exit(0);
		default:
			printf("Invalid choice! Please select a number between 1-6.\n");
		}
	}
	return 0;
}

void addConsumer()
{
	int i;

	printf("\n---------ADD NEW CONSUMER----------\n");

	if (userCount >= MAX_USERS)
	{
		printf("Maximum consumers reached!\n");
		return;
	}

	clearInputBuffer();

	printf("Enter Consumer Name: ");
	fgets(users[userCount].name, sizeof(users[userCount].name), stdin);

	users[userCount].name[strcspn(users[userCount].name, "\n")] = '\0';

	if (strlen(users[userCount].name) == 0)
	{
		printf("Consumer name cannot be empty!\n");
		return;
	}

	for (i = 0; i < userCount; i++)
	{
		if (strcmp(users[i].name, users[userCount].name) == 0)
		{
			printf("Consumer already exists! Enter a different name.\n");
			return;
		}
	}

	printf("Enter Consumer Room No: ");
	if (scanf("%d", &users[userCount].room_no) != 1)
	{
		printf("Invalid room number!\n");
		clearInputBuffer();
		return;
	}

	printf("Enter Consumer Meter No: ");
	if (scanf("%d", &users[userCount].meter_no) != 1)
	{
		printf("Invalid meter number!\n");
		clearInputBuffer();
		return;
	}

	users[userCount].unit = 0;
	users[userCount].amount = 0.0;

	userCount++;

	printf("Consumer added successfully!\n");
	printf("\n-----------------------------------\n");

	silentSave = 1;
	saveData();
}

void calculateGenericBill()
{
	printf("\n---------CALCULATE GENERIC BILL----------\n");
	int unit = 0;
	float amount = 0;

	printf("Enter unit consumed: ");
	if (scanf("%d", &unit) != 1 || unit < 0)
	{
		printf("Invalid unit value! Must be a non-negative integer.\n");
		clearInputBuffer();
		return;
	}

	if (unit <= 50)
	{
		amount = unit * 4.27;
	}
	else if (unit <= 150)
	{
		amount = (50 * 4.27) + ((unit - 50) * 5.23);
	}
	else if (unit <= 300)
	{
		amount = (50 * 4.27) + (100 * 5.23) + ((unit - 150) * 6.61);
	}
	else
	{
		amount = (50 * 4.27) + (100 * 5.23) + (150 * 6.61) + ((unit - 300) * 6.80);
	}

	amount += FIXED + METER_RENT;

	printf("\nUnits Used    : %d", unit);
	printf("\nFixed Price   : RS %.2f", FIXED);
	printf("\nMeter Rent    : RS %.2f", METER_RENT);
	printf("\nEnergy Charge : RS %.2f", amount - FIXED - METER_RENT);
	printf("\nTotal Bill    : RS %.2f", amount);
	printf("\n-----------------------------------------\n");
}

void analyzeBill()
{

	if (userCount == 0)
	{
		printf("No consumer data available to analyze!\n");
		return;
	}

	char maxName[30];
	char minName[30];
	int maxUnit = -1;
	int minUnit = 999999;
	float maxAmount = 0;
	float minAmount = 0;
	int maxRoom = 0, i;
	int minRoom = 0;
	int validConsumers = 0;

	printf("\n-----------ANALYZE BILL-----------\n");

	for (i = 0; i < userCount; i++)
	{
		if (users[i].unit > 0)
		{
			validConsumers++;
		}
	}

	if (validConsumers == 0)
	{
		printf("No bills have been added to consumers yet.\n");
		printf("Use 'Add New Bill to Consumer' option first.\n");
		printf("\n----------------------------------\n");
		return;
	}

	for (i = 0; i < userCount; i++)
	{
		if (users[i].unit > 0)
		{
			maxUnit = users[i].unit;
			minUnit = users[i].unit;
			maxAmount = users[i].amount;
			minAmount = users[i].amount;
			maxRoom = users[i].room_no;
			minRoom = users[i].room_no;
			strcpy(maxName, users[i].name);
			strcpy(minName, users[i].name);
			break;
		}
	}

	for (i = 0; i < userCount; i++)
	{
		if (users[i].unit == 0)
			continue;

		if (maxUnit < users[i].unit)
		{
			maxUnit = users[i].unit;
			maxAmount = users[i].amount;
			maxRoom = users[i].room_no;
			strcpy(maxName, users[i].name);
		}

		if (minUnit > users[i].unit)
		{
			minUnit = users[i].unit;
			minAmount = users[i].amount;
			minRoom = users[i].room_no;
			strcpy(minName, users[i].name);
		}
	}

	printf("\n1. Highest Consumption: \n");
	printf("\nName          : %s", maxName);
	printf("\nRoom Number   : %d", maxRoom);
	printf("\nAmount        : RS %.2f", maxAmount);
	printf("\nUnits Used    : %d", maxUnit);

	printf("\n");

	printf("\n2. Lowest Consumption: \n");
	printf("\nName          : %s", minName);
	printf("\nRoom Number   : %d", minRoom);
	printf("\nAmount        : RS %.2f", minAmount);
	printf("\nUnits Used    : %d", minUnit);
	printf("\n----------------------------------\n");
}

void addBill()
{
	char name[30];
	int i, userIndex = -1, units = 0;
	float amount = 0;

	printf("\n-----------ADD NEW BILL TO CONSUMER-----------\n");

	clearInputBuffer();

	printf("Enter Consumer Name: ");
	fgets(name, sizeof(name), stdin);

	name[strcspn(name, "\n")] = '\0';

	for (i = 0; i < userCount; i++)
	{
		if (strcmp(name, users[i].name) == 0)
		{
			userIndex = i;
			break;
		}
	}

	if (userIndex == -1)
	{
		printf("Consumer not found, Try again!\n");
		printf("\n-----------------------------------\n");
		return;
	}

	printf("Enter unit consumed: ");
	if (scanf("%d", &units) != 1 || units < 0)
	{
		printf("Invalid unit value! Must be a non-negative integer.\n");
		clearInputBuffer();
		return;
	}

	if (units <= 50)
	{
		amount = units * 4.27;
	}
	else if (units <= 150)
	{
		amount = (50 * 4.27) + ((units - 50) * 5.23);
	}
	else if (units <= 300)
	{
		amount = (50 * 4.27) + (100 * 5.23) + ((units - 150) * 6.61);
	}
	else
	{
		amount = (50 * 4.27) + (100 * 5.23) + (150 * 6.61) + ((units - 300) * 6.80);
	}

	amount += FIXED + METER_RENT;

	users[userIndex].amount = amount;
	users[userIndex].unit = units;

	printf("\nBill Details for %s:", users[userIndex].name);
	printf("\nUnits Used    : %d", units);
	printf("\nFixed Price   : RS %.2f", FIXED);
	printf("\nMeter Rent    : RS %.2f", METER_RENT);
	printf("\nTotal Bill    : RS %.2f", amount);
	printf("\n\nBill Added Successfully!\n");
	printf("\n-----------------------------------\n");

	silentSave = 1;
	saveData();
}

void powerSaving()
{
	printf("\n---------POWER SAVING TIPS----------\n");
	printf("1. Use LED bulbs\n");
	printf("2. Turn off appliances when not in use\n");
	printf("3. Use energy-efficient devices\n");
	printf("4. Avoid excessive AC usage\n");
	printf("5. Use natural light\n");
	printf("\n-----------------------------------\n");
}

void saveData()
{
	FILE *fp;
	int i;

	if (userCount == 0)
	{
		if (!silentSave)
		{
			printf("No data available to save!\n");
		}
		return;
	}

	fp = fopen("electricity_data.txt", "w");

	if (fp == NULL)
	{
		printf("Error opening file for writing!\n");
		return;
	}

	fprintf(fp, "Total Consumers: %d\n\n", userCount);

	for (i = 0; i < userCount; i++)
	{
		fprintf(fp, "Name      : %s\n", users[i].name);
		fprintf(fp, "Room No   : %d\n", users[i].room_no);
		fprintf(fp, "Meter No  : %d\n", users[i].meter_no);
		fprintf(fp, "Units     : %d\n", users[i].unit);
		fprintf(fp, "Amount    : RS %.2f\n", users[i].amount);
		fprintf(fp, "--------------------------\n");
	}

	fclose(fp);

	if (!silentSave)
	{
		printf("Data saved successfully to 'electricity_data.txt'!\n");
	}
}

void loadData()
{
	FILE *fp;
	char line[200];
	int i = 0;

	fp = fopen("electricity_data.txt", "r");

	if (fp == NULL)
	{

		printf("No previous data found. Starting fresh.\n");
		return;
	}

	if (fgets(line, sizeof(line), fp) == NULL)
	{
		fclose(fp);
		return;
	}

	if (sscanf(line, "Total Consumers: %d", &userCount) != 1)
	{

		fclose(fp);
		printf("Warning: Old data format detected. Starting fresh.\n");
		userCount = 0;
		return;
	}

	fgets(line, sizeof(line), fp);

	if (userCount > MAX_USERS || userCount < 0)
	{
		printf("Data file corrupted or too large! Starting fresh.\n");
		fclose(fp);
		userCount = 0;
		return;
	}

	for (i = 0; i < userCount && i < MAX_USERS; i++)
	{

		if (fgets(line, sizeof(line), fp) == NULL)
			break;
		if (sscanf(line, "Name      : %[^\n]", users[i].name) != 1)
			break;

		if (fgets(line, sizeof(line), fp) == NULL)
			break;
		if (sscanf(line, "Room No   : %d", &users[i].room_no) != 1)
			break;

		if (fgets(line, sizeof(line), fp) == NULL)
			break;
		if (sscanf(line, "Meter No  : %d", &users[i].meter_no) != 1)
			break;

		if (fgets(line, sizeof(line), fp) == NULL)
			break;
		if (sscanf(line, "Units     : %d", &users[i].unit) != 1)
		{

			printf("Warning: Old data format detected. Some data may not load correctly.\n");
			users[i].unit = 0;
		}

		if (fgets(line, sizeof(line), fp) == NULL)
			break;
		if (sscanf(line, "Amount    : RS %f", &users[i].amount) != 1)
		{
			users[i].amount = 0.0;
		}

		fgets(line, sizeof(line), fp);
	}

	fclose(fp);

	if (userCount > 0)
	{
		printf("Previous data loaded successfully! (%d consumers)\n", userCount);
	}
	else
	{
		printf("No valid consumer data found in file.\n");
	}
}