#include <stdio.h>
#include <string.h>

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

	if (!strcmp(flag, "-round")) {
		i = ROUND;
		valid = 1;
	}

	if (!strcmp(flag, "-sq")) {
		i = SQ;
		valid = 1;
	}

	if (!strcmp(flag, "-curly")) {
		i = CURLY;
		valid = 1;
	}

	if (!valid) {
		err("Invalid flag");

		return 1;
	}

	printf("%c%s%c\n", pair[i][OPEN], buff, pair[i][CLOSE]);

	return 0;
}
