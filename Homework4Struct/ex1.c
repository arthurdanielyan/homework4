#include <stdio.h>
#include <string.h>

#define CURRENT_YEAR 2024

struct Address {
	char* city;
	char* street;
	int building;
	int apartment;
};

struct Phone {
	char* home;
	char* mobile;
};

struct Person {
	char* fullName;
	int birthYear;
	struct Address address;
	struct Phone phone;
};

struct Person createPerson(
	const char* name,
	int birthYear,
	const char* city,
	const char* street,
	int building,
	int apartment,
	const char* homePhoneNumber,
	const char* mobilePhoneNumber
) {
	struct Person person;
	person.fullName = name;
	person.birthYear = birthYear;
	person.address.city = city;
	person.address.street = street;
	person.address.building = building;
	person.address.apartment = apartment;
	person.phone.home = homePhoneNumber;
	person.phone.mobile = mobilePhoneNumber;

	return person;
}

int ex1() {
	struct Person people[5] = {
		createPerson("Arthur Danielyan Arthuri", 2005, "Yerevan", "Galsoyan", 38, 30, "010646956", "094522581"),
		createPerson("Armen Mamikonyan Davidi", 2003, "Vanadzor", "Arzumanyan", 10, 5, "011253265", "077854578"),
		createPerson("Garnik Kirakosyan Vachei", 2000, "Vanadzor", "Arzumanyan", 10, 5, "011253265", "095854578"),
		createPerson("Kamo Hunanyan Varazdati", 1996, "Sevan", "Halabyan", 17, 23, "033568974", "094854578"),
		createPerson("Hamlet Armenakyan Grigori", 1996, "Vanadzor", "Nalbandyan", 56, 9, "033568974", "095854578"),
	};

	for (int i = 0; i < 5; i++) {
		if (
			people[i].address.city == "Vanadzor" &&
			CURRENT_YEAR - people[i].birthYear > 20
		) {
			char mobileStart[4] = {
				*people[i].phone.mobile++,
				*people[i].phone.mobile++,
				*people[i].phone.mobile,
				'\0'
			};

			if (strcmp(mobileStart, "095") == 0) {
				puts(people[i].fullName);
			}
		}
	}

	
	return 0;
}
