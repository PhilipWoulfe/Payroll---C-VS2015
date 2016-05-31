/**
* CompanyPayroll
*
* FIT ICTAP Procedural Programming Assignment
*
* Author Philip Woulfe
* Version 1.5
* 2016-10-05
* Body for creation of Employee Data type
* 
* Contains all the logic for dealing with Employee_t structs
*/

#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <windows.h>

#include "Employee.h"
#include "PayrollUI.h"

/* Create a new employee*/
int createNewEmployee(Employee_t employees[], int arrayLength) {
	
	Employee_t newEmployee;
	newEmployee.currentEmployee = true;

	char result;

	displayHeader();

	printText("Enter new employee name: ");
	gets(newEmployee.name);

	displayHeader();

	printText("\t1. HR\n\t2. IT\n\t3. Production\n\t4. Sales and Marketing");

	// Loop until valid input
	do {
		printText("\n  Select Department [1 - 4]: ");
		newEmployee.dept = getch() - '0';
	} while (newEmployee.dept < 1 || newEmployee.dept > 4);

	displayHeader();

	printText("\t1. Associate\n\t2. Senior\n\t3. Manager");

	// Loop until valid input
	do {
		printText("\n  Select Pay Rate [1 - 3]: ");
		char temp = getch();
		newEmployee.rate =  temp - '0';
	} while (newEmployee.rate < 1 || newEmployee.rate > 3);

	displayHeader();
	displayNewEmployee(newEmployee, arrayLength);
	printText("\t1. Save New Employee\n\t2. Exit Without Saving");

	// Loop until valid input
	do {
		printText("\n  Save or Cancel [1 - 2]: ");
		result = getch();
	} while (result < '1' || result > '2');

	if (result == '1') {
		employees[arrayLength] = newEmployee;
		arrayLength++;
		saveEmployees(employees, arrayLength);
		return arrayLength;
	} else {
		return arrayLength;
	}
}

/* Terminate or rehire employees */
void changeEmployeeStatus(Employee_t employees[], int arrayLength) {
	
	// display employees' employment status
	displayStatusEmployee(employees, arrayLength);

	// declare variables
	char inputStr[10];
	int input;

	// Loop until valid input
	do {
		printf("\n  Enter employee number to change status[1 - %d]:", arrayLength);
		gets(inputStr);
		input = atoi(inputStr);
		//input = getch() - '0'; // convert char to int
	} while (input < 1 || input > arrayLength);

	input--; // convert to array index

	// display employees' employment status
	displayStatusEmployee(employees, arrayLength);

	printf("\n  Change status for %s", employees[input].name);
	printText("\n  Employment status\n\n\t1. False\n\t2. True\n");

	// save status input
	int statusInput;

	// loop until valid input
	do {
		printText("Set employment status to[1 - 2]:");
		statusInput = getch() - '0'; // convert char to int
	} while (statusInput < 1 || statusInput > 2);

	statusInput--; // convert to boolean

	// display employees' employment status
	displayStatusEmployee(employees, arrayLength);

	printf("\n  Set employee status for %s to %s?", employees[input].name, statusInput == 1 ? "true" : "false");

	printText("\n\t1. Save and Exit\n\t2. Cancel\n");

	// save input status
	int saveInput;

	// loop until valid input
	do {
		printText("Select[1 - 2]:");
		saveInput = getch() - '0'; // convert char to int
	} while (saveInput < 1 || saveInput > 2);


	// save or cancel
	if (saveInput == 1) {

		employees[input].currentEmployee = statusInput;
		displayHeader();
		saveEmployees(employees, arrayLength);
	}
	else {
		printText("Cancelling...");
		Sleep(2000); // Adds weight - make it seem like the program is doing something important
	}

}

/* Changes employee's department */
void changeDept(Employee_t employees[], int arrayLength) {
	
	// display employees
	displayEmployees(employees, arrayLength);

	// declare variables
	int input;
	char inputStr[10];

	// Loop until valid input
	do {
		printf("\n  Enter employee number to change department[1 - %d]:", arrayLength);
		gets(inputStr);
		input = atoi(inputStr); // convert char to int
	} while (input < 1 || input > arrayLength);

	input--; // convert to array index

	// display employees
	displayEmployees(employees, arrayLength);

	printf("\n  Change department for %s", employees[input].name);
	printText("\n  Department\n\n\t1. HR\n\t2. IT\n\t3. Production\n\t4. Sales & Marketing\n");

	// department input
	int deptInput;

	// loop until valid input
	do {
		printText("Set department to[1 - 4]:");
		deptInput = getch() - '0'; // convert char to int
	} while (deptInput < 1 || deptInput > 4);

	// diaplsy employees
	displayEmployees(employees, arrayLength);

	// department variable
	char* dept;

	// convert enum to string
	switch (deptInput) {
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
			printf("How the hell did you do that?");
			return 4;
	}

	printf("\n  Set department for %s to %s?", employees[input].name, dept);

	printText("\n\t1. Save and Exit\n\t2. Cancel\n");

	// save input
	int saveInput;

	// loop until valid input
	do {
		printText("Select[1 - 2]:");
		saveInput = getch() - '0'; // convert char to int
	} while (saveInput < 1 || saveInput > 2);

	// save or cancel
	if (saveInput == 1) {

		employees[input].dept = deptInput;
		displayHeader();
		saveEmployees(employees, arrayLength);
	}
	else {
		printText("Cancelling...");
		Sleep(2000); // Adds weight - make it seem like the program is doing something important
	}

}

/* Change employee's pay rate */
void changeRate(Employee_t employees[], int arrayLength) {
	
	displayEmployees(employees, arrayLength);

	int input;
	char inputStr[10];

	// Loop until valid input
	do {
		printf("\n  Enter employee number to change pay rate[1 - %d]:", arrayLength);
		gets(inputStr);
		input = atoi(inputStr); // convert char to int
	} while (input < 1 || input > arrayLength);

	input--; // convert to array index

	displayEmployees(employees, arrayLength);

	printf("\n  Change pay rate for %s", employees[input].name);
	printText("\n  Rate\n\n\t1. Associate\n\t2. Senior\n\t3. Manager\n");

	// save rate input
	int rateInput;

	// loop until valid input
	do {
		printText("Set pay rate to[1 - 4]:");
		rateInput = getch() - '0'; // convert char to int
	} while (rateInput < 1 || rateInput > 3);

	displayEmployees(employees, arrayLength);

	// rate
	char* rate;

	// convert enum to string
	switch (rateInput) {
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
			printf("How the hell did you do that?");
			return 5;
	}

	printf("\n  Set rate for %s to %s?", employees[input].name, rate);

	printText("\n\t1. Save and Exit\n\t2. Cancel\n");

	// save input
	int saveInput;

	// loop until valid input
	do {
		printText("Select[1 - 2]:");
		saveInput = getch() - '0'; // convert char to int
	} while (saveInput < 1 || saveInput > 2);

	// save or cancel
	if (saveInput == 1) {

		employees[input].rate = rateInput;
		displayHeader();
		saveEmployees(employees, arrayLength);
	}
	else {
		printText("Cancelling...");
		Sleep(2000); // Adds weight - make it seem like the program is doing something important
	}
}