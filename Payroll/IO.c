/**
* CompanyPayroll
*
* FIT ICTAP Procedural Programming Assignment
*
* Author Philip Woulfe
* Version 1.5
* 2016-10-05
* Body for IO
*
* Contains all the logic for dealing with file IO - Loading employees, saving employees and outputting payroll report
*/

#define _CRT_SECURE_NO_DEPRECATE
//#define _CRTDBG_MAP_ALLOC
//#include <stdlib.h>
//#include <crtdbg.h>

#include <stdio.h>
#include <windows.h>

#include "Employee.h"
#include "IO.h"

/* Load employee record */
int loadEmployees(Employee_t employees_p[], int arrayLength) {

	printText("Loading employee records...");

	Sleep(1000); // Adds weight - make it seem like the program is doing something important

	// remember filenames
	char *infile = "EmployeeList.csv";

	// open input file
	FILE* inptr = fopen(infile, "r");
	if (inptr == NULL)
	{
		/* Create message string */
		char *message = "Could not open ";
		char *messageFull = malloc(strlen(message) + 1 + strlen(infile) + "...\n" + 1);
		strcpy(messageFull, message);
		strcat(messageFull, infile);
		strcat(messageFull, "...\n");

		printText(messageFull);

		printText("Creating File...");
		Sleep(2000); // Adds weight - make it seem like the program is doing something important

		inptr = fopen(infile, "w");

		printText("File Created...");

		// free memory
		free(messageFull);
	}
	else {
		printText("Employee records loaded...");
		Sleep(1000); // Adds weight - make it seem like the program is doing something important
	}

	char line[50];
	arrayLength = 0;

	// read lines from file
	while (fgets(line, 50, inptr))
	{
		char* tmp = _strdup(line);

		// get specific field from line
		strcpy(employees_p[arrayLength].name, getfield(tmp, 1));
		employees_p[arrayLength].dept = atoi(getfield(_strdup(line), 2));
		employees_p[arrayLength].rate = atoi(getfield(_strdup(line), 3));
		employees_p[arrayLength].currentEmployee = atoi(getfield(_strdup(line), 4));

		arrayLength++; // increase array length

		// NOTE strtok clobbers tmp
		free(tmp);
	}

	// close infile
	fclose(inptr);

	// return new array length - look, I don't like pointers, don't judge me
	return arrayLength;
}

/* Gets a specific field from a line*/
const char* getfield(char* line, int num)
{
	// do stuff
	const char* tok;
	
	// loop
	for (tok = strtok(line, ",");
		tok && *tok;
		tok = strtok(NULL, ",\n"))
	{
		if (!--num)
			// witchcraft
			return tok;
	}
	// magic
	return NULL;
}

/* Save employee record */
void saveEmployees(Employee_t employees_p[], int arrayLength) {

	printText("Saving employee records...");

	Sleep(1000); // Adds weight - make it seem like the program is doing something important

	// remember filenames
	char *infile = "EmployeeList.csv";

	// open input file
	FILE* inptr = fopen(infile, "w");
	if (inptr == NULL)
	{
		/* Create message string */
		char *message = "Could not open ";
		char *messageFull = malloc(sizeof(message) + 1 + sizeof(infile) + sizeof("...\n"));
		strcpy(messageFull, message);
		strcat(messageFull, infile);
		strcat(messageFull, "...\n");

		printText(messageFull);

		printText("Creating File...");
		Sleep(2000); // Adds weight - make it seem like the program is doing something important

		inptr = fopen(infile, "w");

		printText("File Created...");

		// free memory
		free(messageFull);
	}
	else {
		printText("File Located...");
		Sleep(1000); // Adds weight - make it seem like the program is doing something important
	}

	// do this for each employee
	for (int i = 0; i < arrayLength; i++) {
		fprintf(inptr, "%s,%d,%d,%d\n", employees_p[i].name, employees_p[i].dept, employees_p[i].rate, employees_p[i].currentEmployee);
	}

	// close infile
	fclose(inptr);
}

/* Save Payroll*/
void savePayroll (Employee_t employees[], int arrayLength) {
	
	// create output file name
	char *outfile_basic = "Payroll_Week_Ending_";
	char *fileExtension = ".txt";

	char *WEDate = getWEDate();

	char *outfile = (char*)malloc(sizeof(outfile_basic) + sizeof(WEDate) + sizeof(fileExtension) + 100);

	// construct file name
	strcpy(outfile, outfile_basic);
	outfile = strcat(outfile, WEDate);
	outfile = strcat(outfile, fileExtension);

	printText("Creating output file...");

	Sleep(2000); // Adds weight - make it seem like the program is doing something important

	// create output file
	FILE* outptr = fopen(outfile, "w");
	if (outptr == NULL)
	{
		// create error message
		char *message = "Could not create ";
		char *messageFull = (char *) malloc(sizeof(message) + 1 + sizeof(outfile) + sizeof("...\n") + 1);
		strcpy(messageFull, message);
		strcat(messageFull, outfile);
		//strcat(messageFull, "...\n");

		printText(messageFull);
		 
		Sleep(2000); // Adds weight - make it seem like the program is doing something important

		// free memory
		free(messageFull);

	}
	else {
		printText("Output file created...");
		printText("Saving...");
		Sleep(2000); // Adds weight - make it seem like the program is doing something important
	}

	// construct file interface
	fprintf(outptr, "   _______________________________________________________________________________\n");
	fprintf(outptr, "  |                                                                               |\n");
	fprintf(outptr, "  |                    Wolf Payroll - Payroll WE%s                        |\n", WEDate);
	fprintf(outptr, "  |_______________________________________________________________________________|\n");
	fprintf(outptr, "  |  # | Name                                 |   Hours | Hourly Rate |    Total  |\n");
	fprintf(outptr, "  |____|______________________________________|_________|_____________|___________|\n");
	fprintf(outptr, "  |    |                                      |         |             |           |\n");



	for (int i = 0; i < arrayLength; i++) {

		// Skip former employees
		if (!employees[i].currentEmployee) {
			continue;
		}

		char name[50];
		strcpy(name, employees[i].name); // copy name

		char totalHours[10];
		char totalMinutes[10];

		sprintf(totalHours, "%d", employees[i].hoursWorked); // convert int to char*
		sprintf(totalMinutes, "%2d", employees[i].minutesWorked); // convert int to char*

		strcat(totalHours, "."); // construct hours + minutes
		strcat(totalHours, totalMinutes); // construct hours + minutes

		// print to file
		fprintf(outptr, "  | %2d | %-36s | %7s | $%10.2f | $%7.02f  |\n", i + 1, name, totalHours, employees[i].hourlyRate, employees[i].weeksWages);

	}

	fprintf(outptr, "  |____|______________________________________|_________|_____________|___________|\n");

	// close outfile
	fclose(outptr);

	// free memory
	free(WEDate);
	free(outfile); 

	Sleep(2000); // Adds weight - make it seem like the program is doing something important

}

/* get week end date */
char * getWEDate() {

	// Declare Variables
	char *result;
	// get date
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);

	// get week end date
	tm.tm_mday += 7 - tm.tm_wday;
	mktime(&tm); // resolve into real date

	// get year
	char year[5];
	sprintf(year, "%d", tm.tm_year + 1900);

	// get month
	char month[3];
	char tempMonth[3];
	strcpy(month, "0");

	// convert to actual month number
	int monthNum = tm.tm_mon + 1;
	sprintf(tempMonth, "%d", monthNum);

	// add 0 if necessary
	if (monthNum / 10 == 0) {
		// convert int to char *
		strcat(month, tempMonth);
	}
	else
		strcpy(month, tempMonth);

	// get day
	char day[3];
	char tempDay[3];
	strcpy(day, "0");

	int dayNum = tm.tm_mday; // gets date for Sunday of that week
	sprintf(tempDay, "%d", dayNum);

	// add 0 if necessary
	if (dayNum / 10 == 0)
		strcat(day, tempDay);
	else
		strcpy(day, tempDay);

	// declare variable and allocate memory
	int temp = sizeof(year) + sizeof("-") + sizeof(day) + sizeof("-") + sizeof(month) + sizeof('\0');

	result = malloc(temp);
	// add year
	strcpy(result, year);
	result = strcat(result, "-");

	// add month
	result = strcat(result, month);
	result = strcat(result, "-");

	// add day
	result = strcat(result, day);

	// add end of string
	result = strcat(result, "\0");
	return result;
}