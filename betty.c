#include <stdio.h>
/**
 * _strncat - concatenates two strings.
 * @dest:the first str
 * @src:the second string
 * @n:number of bytes
 * Return:returns pointer points on the new string
 */
char *_strncat(char *dest, char *src, int n)
{
int i, j;
for (i = 0; dest[i] != '\0'; i++)
;
for (j = 0; src[j] != '\0' && j < n; j++)
{
dest[i] = src[j];
i++;
}
dest[i] = '\0';
return (dest);
}
