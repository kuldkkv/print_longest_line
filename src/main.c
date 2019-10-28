#include <stdio.h>

#define MAXLINE 1000

int readline (char[], int);
void copy(char[], char[]);

int line_no = 0;

int main()
{
	char line[MAXLINE];
	char longest_line[MAXLINE];
	int len;
	int max_len = 0;
	int max_line_no;

	while ((len = readline(line, MAXLINE)) > 0)
	{
		if (len > max_len) {
			max_len = len;
			max_line_no = line_no;
			copy(longest_line, line);
		}
	}
	if (max_len > 0)
		printf ("longest line is: [%s] at line no [%d]\n", longest_line, max_line_no);
	return 0;
}

int readline(char line[], int maxline)
{
	int i, c;

	for (i=0; i < maxline-1 && (c = getchar()) != EOF && c != '\n'; i++)
		line[i] = c;
	line[i] = '\0';
	line_no++;
	return i;
}

void copy(char to[], char from[])
{
	int i = 0;

	while ((to[i] = from[i]) != '\0')
		i++;
}

