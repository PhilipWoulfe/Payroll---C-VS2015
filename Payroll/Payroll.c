/**
* CompanyPayroll
*
* FIT ICTAP Procedural Programming Assignment
*
* Author Philip Woulfe
* Version 1.0
* 2016-10-05
* Create a program to calculate company payroll
*/

#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <math.h>;

#include "Payroll.h"
#include "Employee.h"
#include "PayrollUI.h"
#include "IO.h"



int main(int argc, char* argv[])
{
	// ensure proper usage
	if (argc != 1)
	{
		printf("Usage: ./payroll (No arguments)\n");
		return 1;
	}

	// declare variables
	char input = 0;

	Employee_t employees[50];
	if (NULL == employees) {
		fprintf(stderr, "malloc failed\n");
		return(-1);
	}
	int arrayLength = 0;

	// Resize command window
	system("MODE 85,50");

	displayHeader();
	arrayLength = loadEmployees(employees, arrayLength);

	// loop through menu until quit
	do {

		displayMenu();

		// Loop until valid input
		do {

			input = getch();

			switch (input) {
				case '1':
					displayEmployees(employees, arrayLength);
					printText(" Press any key to continue...");
					getch();
					break;
				case '2':
					arrayLength = createNewEmployee(employees, arrayLength);
					break;
				case '3':
					changeEmployeeStatus(employees, arrayLength);
					break;
				case '4':
					changeDept(employees, arrayLength);
					break;
				case '5':
					changeRate(employees, arrayLength);
					break;
				case '6':
					processWages(employees, arrayLength);
					break;
				case '7':
					break;

				default:
					printText("  Invalid selection...");
					printText("  Please select an option from the menu [1-7]: ");

			}

		} while (input < '1' || input > '7');

	} while (input != '7');

	//processWages();

	printText("Exiting program...\n");
	Sleep(2000);

	// that's all folks
	return 0;
}

/* Processes wages for employees and save to file */
void processWages(Employee_t empArr[], int arrayLength) { //TODO reimplement

	displayHeader();


	for (int i = 0; i < arrayLength; i++) {
		
		// skip former employees
		if (!empArr[i].currentEmployee) {
			continue;
		}
		
		do {
			printf("Enter hours worked for %s[80 max]: ", empArr[i].name);
			empArr[i].hoursWorked = atoi(gets());
		} while (empArr[i].hoursWorked < 0 || empArr[i].hoursWorked > 81);

		do {
			printf("Enter minutes worked for %s[Less than 60; Rounded down to nearest 15]: ", empArr[i].name);
			empArr[i].minutesWorked = atoi(gets());
		} while (empArr[i].minutesWorked < 0 || empArr[i].minutesWorked > 59);

		// round to nearest 15 minutes
		empArr[i].minutesWorked = empArr[i].minutesWorked - (empArr[i].minutesWorked % 15);
	
		// assign houly rate
		switch (empArr[i].rate) {
			case ASSOCIATE:
				empArr[i].hourlyRate = 11.55;
				break;
			case SENIOR:
				empArr[i].hourlyRate = 18.45;
				break;
			case MANAGER:
				empArr[i].hourlyRate = 22.99;
				break;
			default:
				empArr[i].weeksWages = 0;
		}

		empArr[i] = calculateWeekly(empArr[i]);

	}

	displayPayroll(empArr, arrayLength);
	
	printText("Save Payroll to File?\n\n\t1. Save and Exit\n\t2. Cancel\n");

	int saveInput;

	do {
		printText("Select[1 - 2]:");
		saveInput = getch() - '0'; // convert char to int
	} while (saveInput < 1 || saveInput > 2);

	if (saveInput == 1) {
		savePayroll(empArr, arrayLength);
	}
	else {
		printText("Cancelling...");
		Sleep(2000);
	}
	
	// save or discard?
	

}

/* Calculate pay for the week per employee */
Employee_t calculateWeekly(Employee_t employee) {
	
	float totalWorked = employee.hoursWorked + (employee.minutesWorked / 60.0);
	
	employee.weeksWages = totalWorked * employee.hourlyRate;

	return employee;
	
}