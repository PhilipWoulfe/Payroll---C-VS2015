/**
* CompanyPayroll
*
* FIT ICTAP Procedural Programming Assignment
*
* Author Philip Woulfe
* Version 1.0
* 2016-10-05
* Header for IO
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

/* Load Employees */
int loadEmployees(Employee_t employees[], int arrayLength);

/* Get fields from csv */
const char* getfield(char* line, int num);

/* Save current employees to file */
void saveEmployees(Employee_t employees_p[], int arrayLength);

/* get week end date */
char * getWEDate();

#endif /* __IO_h_ */