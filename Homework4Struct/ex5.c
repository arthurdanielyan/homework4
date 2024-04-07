#include <stdio.h>
#include <string.h>

struct Movie {
	char* title;
	int seriesCount;
};

struct Cinema {
	char* name;
	struct Movie movie;
	char* startTime;
	char* endTime;
	char* address;
};

int ex5() {
	struct Cinema cinemas[5] = {
		{"Cinema 1", {"Money Heist", 10}, "10:00", "12:30", "Yerevan"},
		{"Cinema 2", {"Harry Potter", 8}, "12:00", "14:30", "Berlin"},
		{"Cinema 3", {"Beauty and the Beast", 2}, "18:00", "19:30", "London"},
		{"Cinema 4", {"Money Heist", 10}, "11:00", "13:30", "Tokyo"},
		{"Cinema 5", {"Harry Potter", 8}, "21:00", "23:30", "Nairobi"},
	};

	char desiredMovie[21];
	gets_s(desiredMovie, 21);
	
	for (int c = 0; c < 5; c++) {
		struct Cinema currentCinema = cinemas[c];
		if (strcmp(currentCinema.movie.title, desiredMovie) == 0) {
			printf(
				"Cinema: %s, address: %s, start time: %s, end time: %s\n",
				currentCinema.name, currentCinema.address,
				currentCinema.startTime, currentCinema.endTime
			);
		}
	}
}