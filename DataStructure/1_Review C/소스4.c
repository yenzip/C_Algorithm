#include <stdio.h>
#include <string.h>

int main() {
	char s[101] = { '\0' };
	char res[101] = { '\0' };

	scanf("%s", s);

	for (int i = 0; i < strlen(s); i++) {
		for (int j = 0; j < strlen(s); j++) {
			res[j] = s[(i + j) % strlen(s)];
		}
		printf("%s\n", res);
	}

	return 0;
}