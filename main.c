#include <stdio.h>
#include <stdbool.h>
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
	bool valid = false;

	if (flag[0] != '-') {
		err("Invalid flag");

		return 1;
	}

	if (!strcmp(flag, "-round")) {
		i = ROUND;
		valid = true;
	}

	if (!strcmp(flag, "-sq")) {
		i = SQ;
		valid = true;
	}

	if (!strcmp(flag, "-curly")) {
		i = CURLY;
		valid = true;
	}

	if (!valid) {
		err("No flag");

		return 1;
	}

	printf("%c%s%c\n", pair[i][OPEN], buff, pair[i][CLOSE]);

	return 0;
}
