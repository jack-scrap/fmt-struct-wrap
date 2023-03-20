#include <stdio.h>

enum {
	OPEN,
	CLOSE
};

const char pair[2] = {
	'(',
	')'
};

void err(char* msg) {
	printf("Error: %s\n", msg);
}

int main(int argc, char* argv[]) {
	if (argc == 1) {
		err("No arguments");

		return 1;
	}

	if (argc != 1 + 1) {
		err("Wrong number of arguments");

		return 1;
	}

	char* buff = argv[1];

	printf("%c%s%c\n", pair[OPEN], buff, pair[CLOSE]);

	return 0;
}
