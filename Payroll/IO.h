/**
* CompanyPayroll
*
* FIT ICTAP Procedural Programming Assignment
*
* Author Philip Woulfe
* Version 1.5
* 2016-10-05
* Header for IO
*
* Contains all the logic for dealing with file IO - Loading employees, saving employees and outputting payroll report
*/

#ifndef __IO_h__
#define __IO_h__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <windows.h>

#include "Employee.h"

/**
* \brief Load employees  
*
* Loads employees from file - creates file if none exists
*
* \param employees[] an array of Employee_t structs
* \param arrayLength the current length of the array
*/
int loadEmployees(Employee_t employees[], int arrayLength);

/**
* \brief Get fields from csv fild
*
* gets fields from the loaded employee file
*
* \param line - a char* line from the employee file
* \param num - the number of the  field you want
*/
const char* getfield(char* line, int num);

/**
* \brief Save Employees
*
* Save employees to file - overwrites existing file
*
* \param employees_p[] an array of Employee_t structs
* \param arrayLength the current length of the array
*/
void saveEmployees(Employee_t employees_p[], int arrayLength);

/**
* \brief Get Week End Date
*
* Get the date of the last day in  the currrent week
*/
char * getWEDate();

#endif /* __IO_h_ */