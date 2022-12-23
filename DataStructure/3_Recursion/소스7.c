#include <stdio.h>
#include <string.h>

int rFindChar(char *s, char c, int cnt) {
	if (*s == '\0')
		return cnt;

	if (*s == c)
		cnt++;
	return rFindChar(s + 1, c, cnt);
}

int main() {
	char s[101] = { '\0' };
	char c;

	scanf("%s ", s);
	scanf("%c", &c);

	printf("%d\n", rFindChar(s, c, 0));

	return 0;
}