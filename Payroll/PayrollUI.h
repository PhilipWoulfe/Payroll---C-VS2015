/**
* CompanyPayroll
*
* FIT ICTAP Procedural Programming Assignment
*
* Author Philip Woulfe
* Version 1.5
* 2016-10-05
* Header for creation of UI
*/

#ifndef __Payroll_h__
#define __Payroll_h__

// used to underline text for UI 
#define ANSI_UNDERLINED_PRE  "\033[4m"
#define ANSI_UNDERLINED_POST "\033[0m"

#include <stdio.h>
#include <windows.h>

#include "Employee.h"

/**
* \brief Display header 
*
* Displays the header for the UI
*
*/
void displayHeader(void);

/**
* \brief Clear screen
*
* Clear the UI screen
*
*/
void clearScreen(void);

/**
* \brief Print text
*
* Prints text to the UI on character at a time
*
* \param text string to be printed
*/
void printText(char *text);

/**
* \brief Display Main Menu
*
* Displays the main menu in the command window
*
*/
void displayMenu(void);

/**
* \brief Display employees
*
* Display a list of current employees to the command window
*
* \param employees[]  an array of Employee_t structs
* \param arrayLength the current length of the array
*
* Contains all the logic for outputting the UI including menus and payroll file structure
*/
void displayEmployees(Employee_t employees[], int arrayLength);

/**
* \brief Display new employee
*
* Displays the new employee for confirmation
*
* \param employee an Employee_t struct to be displayed
* \param arrayLength the current length of the array
*/
void displayNewEmployee(Employee_t employee, int arrayLength);

/**
* \brief Display status 
*
* Displays the employment status for all employees - current and former
*
* \param employee[] an array of Employee_t structs
* \param arrayLength the current length of the array
*/
void displayStatusEmployee(Employee_t employee[], int arrayLength);

/**
* \brief Display payroll
*
* Displays the payroll for all current employees
*
* \param employee[]  an array of Employee_t structs
* \param arrayLength the current length of the array
*/
void displayPayroll(Employee_t employee[], int arrayLength);

#endif /* __Payroll_h_ */