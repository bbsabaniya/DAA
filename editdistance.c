#include <stdio.h>
#include <string.h>
int min(int x, int y, int z)
{
    return x < y ? (x < z ? x : z) : (y < z ? y : z);
}
int editDist(char* str1, char* str2, int m, int n)
{
    // If first string is empty, the only option is to
    // insert all characters of second string into first
    if (m == 0)
        return n;

    // If second string is empty, the only option is to
    // remove all characters of first string
    if (n == 0)
        return m;

    if (str1[m - 1] == str2[n - 1])
        return editDist(str1, str2, m - 1, n - 1);

    return 1
        + min(
            editDist(str1, str2, m, n - 1), // Insert
            editDist(str1, str2, m - 1, n), // Remove
            editDist(str1, str2, m - 1, n - 1) // Replace
        );
}
int main()
{
    char str1[] = "HELLO";
    char str2[] = "BOOKS";
    int m = strlen(str1);
    int n = strlen(str2);
    printf("Minimum steps to convert is %d", editDist(str1, str2, m, n));
    return 0;
}

