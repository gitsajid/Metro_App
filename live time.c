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

    // Display formatted date and time
    printf("Current Date and Time: %s", asctime(localTime));

    return 0;
}
