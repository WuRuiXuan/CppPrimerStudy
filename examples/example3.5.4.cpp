#include <iostream>
#include <cstring>

int main()
{
    char largeStr[] = "";
    char ca1[] = "Hello";
    char ca2[] = "World";
    strcpy(largeStr, ca1);
    strcat(largeStr, " ");
    strcat(largeStr, ca2);
    printf("%s", largeStr);
}