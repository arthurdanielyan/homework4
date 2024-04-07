#include <stdio.h>
#include <stdbool.h>

struct Student {
	char* fullName;
	char* gender;
	int marks[5];
	int pension;
};

struct Student createStudent(
	const char* name,
	const char* gender,
	int marks[],
	int pension
) {
	struct Student student;
	student.fullName = name;
	student.gender = gender;
	student.marks[0] = marks[0];
	student.marks[1] = marks[1];
	student.marks[2] = marks[2];
	student.marks[3] = marks[3];
	student.marks[4] = marks[4];
	student.pension = pension;

	return student;
}

int ex2() {
	char* subjects[5] = { "Math", "Cybersecurity", "Physics", "Programming", "English" };
	struct Student students[5] = {
		createStudent("Arthur Danielyan Arthuri", "Male", (const int[]) { 30, 70, 35, 90, 20 }, 50000),
		createStudent("Sargis Barseghyan Hrachi", "Male", (const int[]) { 70, 30, 50, 25, 100 }, 40000),
		createStudent("Vardan Gevorgyan Roberti", "Male", (const int[]) { 40, 50, 80, 90, 50 }, 60000),
		createStudent("Varduhi Adamyan Kareni", "Female", (const int[]) { 30, 70, 21, 30, 20 }, 35000),
		createStudent("Nari Gabrielyan Adami", "Feale", (const int[]) { 50, 70, 60, 90, 40 }, 45000),
	};

	for (int i = 0; i < 5; i++) {
		struct Student current = students[i];
		bool namePrinted = false;
		bool isFirstSubject = true;

		for (int j = 0; j < 5; j++) {
			if (current.marks[j] < 40) {
				if (!namePrinted) {
					printf("%s: ", current.fullName);
					namePrinted = true;
				}
				if (!isFirstSubject) {
					printf(", ");
				}
				printf(subjects[j]);
				isFirstSubject = false;
			}
		}
		if(namePrinted) printf("\n");
	}

	return 0;
}