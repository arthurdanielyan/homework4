#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_PRICE 20000

struct Book {
	char* title;
	int pagesCount;
	int price;
};

struct Author {
	char* fullName;
	struct Book publishedBooks[20];
};

char* generateName(int length) {
	char* name = malloc((length + 1) * sizeof(char));

	for (int i = 0; i < length; i++) {
		name[i] = (char)randomInt(97, 122);
	}
	name[length] = '\0';
	return name;
}

struct Book* generateBooks() {
	struct Book books[20];

	for (int i = 0; i < 20; i++) {
		books[i].title = generateName(randomInt(5, 20));
		books[i].pagesCount = randomInt(50, 300);
		books[i].price = randomInt(1000, 50000);
	}

	return books;
}

struct Author generateAuthor() {
	struct Author author;
	for (int i = 0; i < 20; i++) {
		author.fullName = generateName(randomInt(5, 15));
		struct Book* books = generateBooks();
		for (int j = 0; j < 20; j++) {
			author.publishedBooks[j] = books[j];
		}
	}

	return author;
}


int ex4() {
	struct Author authors[5] = {
		generateAuthor(),
		generateAuthor(),
		generateAuthor(),
		generateAuthor(),
		generateAuthor(),
	};

	for (int a = 0; a < 5; a++) {
		printf("Author: %s", authors[a].fullName);

		bool isBookPrinted = false;
		for (int b = 0; b < 20; b++) {
			struct Book currentBook = authors[a].publishedBooks[b];
			if (currentBook.pagesCount > 200 && currentBook.price <= MAX_PRICE) {
				printf(isBookPrinted ? ", " : "\nBooks: ");
				printf(currentBook.title);
				isBookPrinted = true;
			}
		}
		printf("\n\n");
	}
}

int randomInt(int min, int max) {
	return min + (int)(((float)rand() / (float)RAND_MAX) * (max - min));
}