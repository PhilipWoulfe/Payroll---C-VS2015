/**
* CompanyPayroll
*
* FIT ICTAP Procedural Programming Assignment
*
* Author Philip Woulfe
* Version 1.0
* 2016-10-05
* Body for creation of UI
*/

#define _CRT_SECURE_NO_DEPRECATE
//#define _CRTDBG_MAP_ALLOC
//#include <stdlib.h>
//#include <crtdbg.h>

// used to underline text for UI 
#define ANSI_UNDERLINED_PRE  "\033[4m"
#define ANSI_UNDERLINED_POST "\033[0m"

#include "PayrollUI.h"
#include "IO.h"
//#include<iostream>;
#include <conio.h>;

/* Displays the header for the program */
void displayHeader(void) {
	
	clearScreen();

	printf("  * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf("  *                                                                               *\n");
	printf("  *          _      _   _____   _     ___                                         *\n");
	printf("  *         | |    | | |  _  | | |   |  _|                                        *\n");
	printf("  *         | | /\\ | | | | | | | |   | |_                                         *\n");
	printf("  *         | |//\\\\| | | |_| | | |_  |  _|                                        *\n");
	printf("  *         |__/  \\__| |_____| |___| |_|                                          *\n");
	printf("  *                                                                               *\n");
	printf("  *                 ____     ___   __   __  ____    _____   _     _   TM          *\n");
	printf("  *                |  _ \\   / _ \\  \\ \\ / / |  _ \\  |  _  | | |   | |              *\n");
	printf("  *                | |_| | | |_| |  \\ v /  | |_| | | | | | | |   | |              *\n");
	printf("  *                |  __/  |  _  |   | |   |  _ <  | |_| | | |_  | |_             *\n");
	printf("  *                |_|     |_| |_|   |_|   |_| |_| |_____| |___| |___|            *\n");
	printf("  *                                                                               *\n");
	printf("  *                                   © Copyright Wolf Accounting 2016            *\n");
	printf("  * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");

}

/* Clears the command screen */
void clearScreen(void) {
	system("cls");
}

/* Prints text to console 1 character at a time */
void printText(char *text) {

	// Formatting
	printf("\n  ");

	for (int i = 0; text[i] != '\0'; i++) {
		printf("%c", text[i]);
		fflush(stdout); // outputs to console 1 char at a time instead of buffering all first
		Sleep(10);
	}

	Sleep(50);
}

/* Display main menu */
void displayMenu(void) {

	clearScreen();
	displayHeader();

	printText("Welcome to the Wolf Accounting Payroll System.\n");
	printText("\t1. View Employees");
	printText("\t2. Add Employee");
	printText("\t3. Change Employee Employment status");
	printText("\t4. Change Employee Department");
	printText("\t5. Change Employee Pay Rate");
	printText("\t6. Calculate Payroll for this week");
	printText("\t7. Quit\n");
	printText("Please select an option from the menu [1-7]: ");

}

/* Display Employees */
void displayEmployees(Employee_t employees[], int arrayLength) {

	clearScreen();
	displayHeader();
	//printf("  * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf("   _______________________________________________________________________________\n");
	printf("  |                                                                               |\n");
	printf("  |                    Wolf Payroll - Display Current Employees                   |\n");
	printf("  | _____________________________________________________________________________ |\n");
	printf("  |  # | Name                                   | Department          | Pay Rate  |\n");
	printf("  |  __|________________________________________|_____________________|_________  |\n");
	printf("  |    |                                        |                     |           |\n");

	for (int i = 0; i < arrayLength; i++) {

		// Skip former employees
		if (!employees[i].currentEmployee) {
			continue;
		}

		char name[50];
		strcpy(name, employees[i].name);

		char* dept = "";
		char* rate = "";

		// Set Department
		switch (employees[i].dept) {
		case 1:
			dept = "HR";
			break;
		case 2:
			dept = "IT";
			break;
		case 3:
			dept = "Production";
			break;
		case 4:
			dept = "Sales & Marketing";
			break;
		default:
			printText("How the hell did you manage that?");
		}

		// Set pay rate
		switch (employees[i].rate) {
		case 1:
			rate = "Associate";
			break;
		case 2:
			rate = "Senior";
			break;
		case 3:
			rate = "Manager";
			break;
		default:
			printText("Seriously, how are you doing this?");
		}

		bool current = employees[i].currentEmployee;

		printf("  | %2d | %-38s | %-19s | %-9s |\n", i + 1, name, dept, rate);

	}

	printf("  |____|________________________________________|_____________________|___________|\n");

}

/* Display new Employee */
void displayNewEmployee(Employee_t employee, int arrayLength) {

	char name[50];
	strcpy(name, employee.name);

	char* dept = "";
	char* rate = "";

	clearScreen();
	displayHeader();

	printf("   _______________________________________________________________________________\n");
	printf("  |                                                                               |\n");
	printf("  |                           Wolf Payroll - New Employee                         |\n");
	printf("  | _____________________________________________________________________________ |\n");
	printf("  |  # | Name                                   | Department          | Pay Rate  |\n");
	printf("  |  __|________________________________________|_____________________|_________  |\n");
	printf("  |    |                                        |                     |           |\n");

	// Set Department
	switch (employee.dept) {
		case 1:
			dept = "HR";
			break;
		case 2:
			dept = "IT";
			break;
		case 3:
			dept = "Production";
			break;
		case 4:
			dept = "Sales & Marketing";
			break;
		default:
			printText("How the hell did you manage that?");
	}

	// Set pay rate
	switch (employee.rate) {
		case 1:
			rate = "Associate";
			break;
		case 2:
			rate = "Senior";
			break;
		case 3:
			rate = "Manager";
			break;
		default:
			printText("Seriously, how are you doing this?");
	}

	printf("  | %2d | %-38s | %-19s | %-9s |\n", arrayLength + 1, name, dept, rate);
	printf("  |____|________________________________________|_____________________|___________|\n");
}

/* Display Employee Status */
void displayStatusEmployee(Employee_t employee[], int arrayLength) {

	clearScreen();
	displayHeader();

	printf("   _______________________________________________________________________________\n");
	printf("  |                                                                               |\n");
	printf("  |                          Wolf Payroll - Employee Status                       |\n");
	printf("  | _____________________________________________________________________________ |\n");
	printf("  |  # | Name                                           | Current Employee        |\n");
	printf("  |  __|________________________________________________|_______________________  |\n");
	printf("  |    |                                                |                         |\n");

	for (int i = 0; i < arrayLength; i++) {
		printf("  | %2d | %-46s | %23s |\n", i + 1, employee[i].name, employee[i].currentEmployee ? "true" : "false");
	}

	printf("  |____|________________________________________________|_________________________|\n");
}

/* Display this weeks payroll */
void displayPayroll(Employee_t employee[], int arrayLength) {
	
	clearScreen();
	displayHeader();

	char *WEDate = getWEDate();

	printf("   _______________________________________________________________________________\n");
	printf("  |                                                                               |\n");
	printf("  |                    Wolf Payroll - Payroll WE%s                        |\n", WEDate);
	printf("  | _____________________________________________________________________________ |\n");
	printf("  |  # | Name                                 |   Hours | Hourly Rate |    Total  |\n");
	printf("  | ___|______________________________________|_________|_____________|__________ |\n");
	printf("  |    |                                      |         |             |           |\n");

	free(WEDate);

	for (int i = 0; i < arrayLength; i++) {

		// Skip former employees
		if (!employee[i].currentEmployee) {
			continue;
		}

		char name[50];
		strcpy(name, employee[i].name);

		char totalHours[10];
		char totalMinutes[10];

		sprintf(totalHours, "%d", employee[i].hoursWorked);
		sprintf(totalMinutes, "%2d", employee[i].minutesWorked);

		strcat(totalHours, ".");
		strcat(totalHours, totalMinutes);

		printf("  | %2d | %-36s | %7s | $%10.2f | $%7.02f  |\n", i + 1, name, totalHours, employee[i].hourlyRate, employee[i].weeksWages);

	

	}

	printf("  |____|______________________________________|_________|_____________|___________|\n");
}