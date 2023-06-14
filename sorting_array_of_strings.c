#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lexicographic_sort(const char *a, const char *b)
{
    return strcmp(a, b) < 0;
}

int lexicographic_sort_reverse(const char *a, const char *b)
{
    return strcmp(a, b) > 0;
}

int sort_by_number_of_distinct_characters(const char *a, const char *b)
{
    int l1 = strlen(a);
    int l2 = strlen(b);

    int hash1[128] = {0};
    int i, c = 0;
    for (i = 0; i < l1; ++i)
    {
        // set the position corresponding
        // to the ASCII value of str[i] in hash[] to 1
        hash1[a[i]] = 1;
    }
    // counting number of unique characters
    // repeated elements are only counted once
    for (i = 0; i < 128; ++i)
    {
        c += hash1[i];
    }
    l1 = c;

    int hash2[128] = {0};
    c = 0;
    for (i = 0; i < l2; ++i)
    {
        hash2[b[i]] = 1;
    }
    for (i = 0; i < 128; ++i)
    {
        c += hash2[i];
    }
    l2 = c;

    if (l1 == l2)
    {
        return lexicographic_sort(a, b);
    }
    return l1 < l2;
}

int sort_by_length(const char *a, const char *b)
{
    int l1 = strlen(a);
    int l2 = strlen(b);

    if (l1 == l2)
    {
        return lexicographic_sort(a, b);
    }
    return l1 < l2;
}

void string_sort(char **arr, const int len, int (*cmp_func)(const char *a, const char *b))
{
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - i - 1; j++)
        {
            if (cmp_func(*(arr + j), *(arr + j + 1)) == 0)
            {
                char *temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    char **arr;
    arr = (char **)malloc(n * sizeof(char *));

    for (int i = 0; i < n; i++)
    {
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }

    string_sort(arr, n, lexicographic_sort);
    for (int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for (int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for (int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for (int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");
}