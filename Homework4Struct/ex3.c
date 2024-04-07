#include <stdio.h>
#include <string.h>

#define MIN_AVG_SALARY 30000.0

struct Family {
	char* partner; // possible values: yes, no, dead
	int boys;
	int girls;
};

struct Employee {
	char* fullName;
	char* gender;
	struct Family family;
	int salary;
};

struct Employee createEmployee(
	const char* name,
	const char* gender,
	const char* partner,
	int boys,
	int girls,
	int salary
) {
	struct Employee employee;
	employee.fullName = name;
	employee.gender = gender;
	employee.family.partner = partner;
	employee.family.boys = boys;
	employee.family.girls = girls;
	employee.salary = salary;

	return employee;
};

double calculateAvgSalary(struct Employee employee) {
	return employee.salary / ((employee.family.partner == "yes" ? 1 : 0) +
		employee.family.boys + employee.family.girls + 1);
}

int ex3() {
	struct Employee employees[5] = {
		createEmployee("Arthur Danielyan Arthuri", "male", "yes", 1, 0, 999999),
		createEmployee("Vazgen Ananyan Anastasi", "male", "dead", 2, 1, 100000),
		createEmployee("Marine Voskanyan Vahagni", "female", "yes", 1, 2, 200000),
		createEmployee("Gurgen Manukyan Armenaki", "male", "dead", 5, 3, 100000),
		createEmployee("Ashot Gevorgyan Armani", "male", "dead", 3, 1, 250000),
	};

	for (int i = 0; i < 5; i++) {
		struct Employee currentEmployee = employees[i];
		if (
			strcmp(currentEmployee.gender, "male") == 0 &&
			strcmp(currentEmployee.family.partner, "dead") == 0 &&
			calculateAvgSalary(currentEmployee) < MIN_AVG_SALARY
		) {
			puts(currentEmployee.fullName);
		}
	}
}