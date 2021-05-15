/*
 * arrayEmployees.h
 *
 *  Created on: 15 may. 2021
 *      Author: chuchi
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

typedef struct
{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;
} Employee;


#endif /* ARRAYEMPLOYEES_H_ */
int menu();
int initEmployees(Employee lista[], int len);
int searchFreeSpace(Employee lista[], int len);
int addEmployee(Employee lista[],int len, int* pId);
int sortEmployees(Employee lista[], int len, int order);
int findEmployeeById(Employee lista[], int len, int id);
int removeEmployee(Employee lista[], int len, int idEmployee);
int printEmployee(Employee oneEmployee, int len);
int printEmployees(Employee lista[], int length);
int modifyEmployee(Employee lista[], int len, int idEmployee);
int infoSalary(Employee lista[], int len);
int infoSalary(Employee lista[], int len);
