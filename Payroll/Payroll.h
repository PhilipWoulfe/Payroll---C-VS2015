/**
* CompanyPayroll
*
* FIT ICTAP Procedural Programming Assignment
*
* Author Philip Woulfe
* Version 1.0
* 2016-10-05
* Header for program to calculate company payroll
*/

#ifndef __Payroll_H__
#define __Payroll_H__

#include "Employee.h"

/* Processes wages for employees */
void processWages(Employee_t empArr[], int arrayLength);

/* Calculate pay for the week per employee */
Employee_t calculateWeekly(Employee_t employee);

/* Get Week End Date */
char * getWEDate();

#endif /* __Employee_h_ */