
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char** a, char** b)
{
    char* temp = *a;
    *a = *b;
    *b = temp;
}
void reverse(char** s, int start, int end)
{
    while (start < end) 
    {
        swap(s + start++, s + end--);
    }
}
int next_permutation(int n, char** s)
{
    for (int i = n - 2; i >= 0; --i) 
    {
        
        for (int j = n - 1; j > i; --j) 
        {
            if (strcmp(s[i], s[j]) < 0) 
            {
                swap(s + i, s + j);
                reverse(s, i + 1, n - 1);
                return 1;
            }
        }
        
    }
    return 0;
}


int main()
{
	char **s;
	int n;
	scanf("%d", &n);
	s = calloc(n, sizeof(char*));
	for (int i = 0; i < n; i++)
	{
		s[i] = calloc(11, sizeof(char));
		scanf("%s", s[i]);
	}
	do
	{
		for (int i = 0; i < n; i++)
			printf("%s%c", s[i], i == n - 1 ? '\n' : ' ');
	} while (next_permutation(n, s));
	for (int i = 0; i < n; i++)
		free(s[i]);
	free(s);
	return 0;
}