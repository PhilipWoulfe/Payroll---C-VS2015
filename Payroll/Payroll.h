/**
* CompanyPayroll
*
* FIT ICTAP Procedural Programming Assignment
*
* Author Philip Woulfe
* Version 1.5
* 2016-10-05
* Header for program to calculate company payroll
*
* Starting point form program - handles the main programming loop
*/

/*! \mainpage Payroll Application Developer Documentation
*
* \section intro Introduction
*
* This file contains all the information needed to use the payroll application including procedure
* and data type decriptions
*
* \section install Installation
*
* \subsection step1 Step 1: Download the zip file from git hub
* \subsection step2 Step 2: Compile and run the program
*
*
* \section using Using Doxygen Documentation
*
* The data structures can be accessed through the data structures menus above or by using the links below on the main page.<br>
*
*
* \subsection header Header Files
* Payroll.h <br>
* PayrollUI.h <br>
* Employee.h <br>
* IO.h <br>
*
* \subsection classes Class Files
* Payroll.c <br>
* PayrollUI.c <br>
* Employee.c <br>
* IO.c
*
* \subsection data Data Structures And Enums
* Employee_t <br>
* #Rate_t <br>
* #Department_t <br>
*
*/
#ifndef __Payroll_H__
#define __Payroll_H__

#include "Employee.h"


/**
* \brief Processes wages for employees and save to file
*
* \param empArr an array of Employee_t structs
* \param arrayLength the current length of the array
*/
void processWages(Employee_t empArr[], int arrayLength);

/**
* \brief Calculate pay for the week per employee
*
* \param employee an Employee_t - pass in to calcualte weekly pay for employee
*/
Employee_t calculateWeekly(Employee_t employee);

#endif /* __Employee_h_ */