/**
* CompanyPayroll
*
* FIT ICTAP Procedural Programming Assignment
*
* Author Philip Woulfe
* Version 1.5
* 2016-10-05
* Header for creation of Employee Data type
*
* Contains all the logic for dealing with Employee_t structs
*/

#ifndef __Employee_h__
#define __Employee_h__

#include <stdbool.h>

/** 
 *  \enum Department_t
 *  Sets Department for employee
 */
typedef enum {
	HR = 1,						/**< enum HR 1 */
	IT = 2,						/**< enum IT 2 */
	PRODUCTION = 3,				/**< enum Production 3 */
	SALES_AND_MARKETING = 4		/**< enum Sales and Marketing 4 */
} Department_t;

/** 
 *  \enum Rate_t
 *  Sets payrate for employee
 */
typedef enum {
	ASSOCIATE = 1,	/**< enum Associate 1 */
	SENIOR = 2,		/**< enum Senior 2*/
	MANAGER = 3,	/**< enum Manager 3*/
} Rate_t;

/**
*  \struct Employee_t
*  Custom data type for storing information related to employees
*/
typedef struct {
	char name[50];			/**< char array name - max size 50 */
	Department_t dept;		/**< Department_t enum dept - stores employee department*/
	Rate_t rate;			/**< Rate_t enum rate - stores employee pay rate*/
	bool currentEmployee;	/**< bool - stores if employee is current or not*/
	int hoursWorked;		/**< int hours worked - stores how many hours an employee worked */
	int minutesWorked;		/**< int minutes worked - stores how many minutes an employee worked*/
	float hourlyRate;		/**< float hourlyRate - stores the hourly rate for an employee*/
	float weeksWages;		/**< float weeks wages - stores the weekly wages for an employee*/

} Employee_t;


/**
* \brief Create a new employee
*
* Input employee array and array length - method will create a new employee
* 
* \param employees[] an array of Employee_t structs
* \param arrayLength the current length of the array
*/
int createNewEmployee(Employee_t employees[], int arrayLength);

/**
* \brief Changes employee's department 
*
* Input employee array and array length - method will change employee department
*
* \param employees[] an array of Employee_t structs
* \param arrayLength the current length of the array
*/
void changeDept(Employee_t employees[], int arrayLength);

/**
* \brief Change employee's pay rate
*
* Input employee array and array length - method will change employee pay rate
*
* \param employees[] an array of Employee_t structs
* \param arrayLength the current length of the array
*/
void changeRate(Employee_t employees[], int arrayLength);

/**
* \brief Terminate or rehire employees
*
* Input employee array and array length - method will change employee empoyment status
*
* \param employees[] an array of Employee_t structs
* \param arrayLength the current length of the array
*/
void changeEmployeeStatus(Employee_t employees[], int arrayLength);


#endif /* __Employee_h_ */