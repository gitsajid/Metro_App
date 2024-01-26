#include <stdio.h>

int main() 
{
    // Declare an array of strings
    const char *words[] = {"apple", "banana", "orange", "grape"};

    // Access and print the words
    for (int i = 0; i < sizeof(words) / sizeof(words[0]); ++i) {
        printf("Word %d: %s\n", i + 1, words[i]);
    }

    return 0;
}
