#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum {
	ROUND,
	SQ,
	CURLY
};

enum {
	OPEN,
	CLOSE
};

const char pair[3][2] = {
	{
		'(',
		')'
	}, {
		'[',
		']'
	}, {
		'{',
		'}'
	}
};

void err(char* msg) {
	printf("Error: %s\n", msg);
}

int main(int argc, char* argv[]) {
	if (argc == 1) {
		err("No arguments");

		return 1;
	}

	if (argc != 1 + 1 + 1) {
		err("Wrong number of arguments");

		return 1;
	}

	char* buff = argv[1];

	char* flag = argv[2];

	int i;
	int valid = 0;

	if (flag[0] != '-') {
		err("Invalid flag");

		return 1;
	}

	if (strlen(flag) <= 1) {
		err("Invalid flag");

		return 1;
	}

	char* id = malloc(strlen(flag) + 1 - 1 * sizeof (char));
	strcpy(id, &flag[1]);

	if (!strcmp(id, "round")) {
		i = ROUND;
		valid = 1;
	}

	if (!strcmp(id, "sq")) {
		i = SQ;
		valid = 1;
	}

	if (!strcmp(id, "curly")) {
		i = CURLY;
		valid = 1;
	}

	if (!valid) {
		err("Invalid flag");

		return 1;
	}

	printf("%c%s%c", pair[i][OPEN], buff, pair[i][CLOSE]);

	return 0;
}
