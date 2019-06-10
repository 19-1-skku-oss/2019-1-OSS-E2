#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Employee {
	char name[32];
	char nationality[32];
	int salary;
	struct Employee * superior;
};

void Get_Employee(struct Employee * data) {
	printf("name : ");
	gets(data->name);
	printf("nationality : ");
	gets(data->nationality);
	printf("salary : ");
	scanf("%d", &data->salary);
	getc(stdin);
}

void Print_Employee(struct Employee employee) {
	printf("name : %s\n", employee.name);
	printf("nationality : %s\n", employee.nationality);
	printf("salary : %d\n", employee.salary);
	if (employee.superior != NULL)
		printf("superior name : %s\n", employee.superior->name);
}

void Print_superior_hierarchy(struct Employee * data) {
	int num;
	int count = 1;
	struct Employee * cursor = NULL;
	printf("Write Employee number you want\n");
	scanf("%d", &num);
	getc(stdin);

	printf("\n");
	printf("%s\n", data[num].name);
	cursor = data[num].superior;
	while (cursor != NULL) {
		for (int i = 0; i < count; i++)
			printf("  ");
		count++;
		printf(" => %s\n", cursor->name);
		cursor = cursor->superior;
	}
	printf("\n");
}

void Print_Minor(struct Employee * data, int num, int superior_num, int class_num) {
	char first = 1;
	for (int i = 0; i < num; i++) {
		if (data[i].superior == &data[superior_num]) {
			printf("\n");
			for (int j = 0; j < class_num; j++) {
				printf("   ");
			}
			printf("=> ");
			printf("%s ", data[i].name);
			Print_Minor(data, num, i, class_num + 1);
		}
	}
}

void Print_Organization(struct Employee * data, int num) {
	for (int i = 0; i < num; i++) {
		if (data[i].superior == NULL) {
			printf("%s", data[i].name);
			Print_Minor(data, num, i, 1);
			printf("\n");
		}
	}
	printf("\n");
}

struct Employee * Add_Employee(struct Employee * employees, int * employee_num, int * employee_data_size) {
	char answer[4];
	int num;

	while (1) {
		printf("Do you want to register employee information? (yes or no) : ");
		gets(answer);
		if (strcmp(answer, "yes") == 0) {
			printf("Insert number %d employee\n", *employee_num);
			if (*employee_num >= *employee_data_size) {
				(*employee_data_size) *= 2;
				employees = (struct Employee*)realloc(employees, sizeof(struct Employee)*(*employee_data_size));
			}
			Get_Employee(&employees[*employee_num]);
			printf("Dose %s has a superior? (yes or no) : ", employees[*employee_num].name);
			gets(answer);
			if (strcmp(answer, "yes") == 0) {
				printf("What is the number of Superior?\n");
				scanf("%d", &num);
				getc(stdin);
				employees[*employee_num].superior = &employees[num];
			}
			else
				employees[*employee_num].superior = NULL;
			(*employee_num)++;
		}
		else if (strcmp(answer, "no") == 0) {
			break;
		}
		printf("\n");
	}

	return employees;
}

void Print_Employees(struct Employee * employees, int employee_num) {

	for (int i = 0; i < employee_num; i++) {
		printf("----------employee %d----------\n", i);
		Print_Employee(employees[i]);
	}
	printf("\n");
}

void testq(struct Employee * employees, int employee_num, char wildcard[], int * result) {

	for (int j = 0; j < employee_num; j++) {
		for (int i = 0; i < 32; i++) {
			if (wildcard[i] == NULL) {
				if (employees[j].name[i] != NULL) result[j] = 0;
				break;
			}
			if (employees[j].name[i] == NULL) result[j] = 0;
			while (wildcard[i] != '?') {
				if (wildcard[i] != employees[j].name[i]) result[j] = 0;
				break;
			}
		}
	}	
}


void tests(struct Employee * employees, int employee_num, char wildcard[], int * result) {
	int num = 0;
	int wpt = 0;

	for (int j = 0; j < employee_num; j++) {
		for (num = 0; employees[j].name[num] != NULL;) {
			while (wildcard[wpt] != '*' && employees[j].name[num] != '\0') {
				if (wildcard[wpt++] != employees[j].name[num++]) result[j] = 0;
			}
			if (wildcard[wpt] == '*')
			{
				if (wildcard[wpt + 1] == employees[j].name[num + 1])
					wpt++;
				num++;
			}
		}
		if (wildcard[wpt] != '\0')
			result[j] = 0;
		wpt = 0;
	}
}

void Search_Employees(struct Employee * employees, int employee_num) {
	char wildcard[32];
	int* result = malloc(sizeof(int)*employee_num);
	for (int i = 0; i < employee_num; i++) result[i] = 1;
	
	gets(wildcard);

	for (int i = 0; i < 32; i++) {
		if (wildcard[i] == '\0') break;
		if (wildcard[i] == '?') testq(employees, employee_num, wildcard, result);
		if (wildcard[i] == '*') tests(employees, employee_num, wildcard, result);
	}
				
	for (int i = 0; i < employee_num; i++) {
		if (result[i] == 1) {
			printf("Wildcard : [ %s ]\n", wildcard);
			Print_Employee(employees[i]);
			printf("\n");
		}
	}

	free(result);
}



int main(void) {
	
	int choice = 1;
	struct Employee * employees = (struct Employee*)calloc(8, sizeof(struct Employee));
	int employee_num = 0;
	int employee_data_size = 8;

	while (choice) {
		printf("What are you going to do?\n");
		printf("1 => Add Employee\n");
		printf("2 => Print Employee\n");
		printf("3 => Print Organization\n");
		printf("4 => Search Employees\n");
		printf("0 => Exit\n");
		scanf("%d", &choice);
		getc(stdin);

		switch (choice)
		{
		case 0:
			break;
		case 1:		//practice 2, 3
			employees = Add_Employee(employees, &employee_num, &employee_data_size);
			break;
		case 2:		//practice 2, 3
			Print_Employees(employees, employee_num);
			break;
		case 3:		//practice 4
			Print_Organization(employees, employee_num);
			break;
		case 4:
			Search_Employees(employees, employee_num);
			break;
			
		}
	}

	free(employees);
	return 0;
}
