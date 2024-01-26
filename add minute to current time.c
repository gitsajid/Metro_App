#include <stdio.h>
#include <time.h>

int main() 
{
    // Declare variables
    time_t currentTime;
    struct tm *localTime;

    // Get current time
    currentTime = time(NULL);
    localTime = localtime(&currentTime);

    // Add minutes to the current time
    int minutesToAdd = 30; // Change this value as needed
    currentTime += minutesToAdd * 60; // Convert minutes to seconds
    localTime = localtime(&currentTime);

    // Display the updated time
    printf("Current Time + %d minutes: %s", minutesToAdd, asctime(localTime));

    return 0;
}
