#include <iostream>

char toUpper(char c) {
	if (c >= 'a' && c <= 'z') {
		return c - 32;
	}
	return c;
}

int main(int argc, char **argv) {
	int i = 0;
	int j = 1;
	char c;

	if (argc == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	while (argv[j]) {
		i = 0;
		while (argv[j][i])
		{
			c = toUpper(argv[j][i]);

			std::cout << c;
			i++;
		}
		j++;
	}
	std::cout << std::endl;
	return 0;
}
