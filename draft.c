#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

void stations_array ()
{
    const char *words[] = {"Mirpur", "Shahbagh", "DU"};

    for (int i = 0; i < sizeof(words) / sizeof(words[0]); i++) 
    {
        printf("%d: %s\n", i + 1, words[i]);
    }
}

int main ()
{
    int from;
    printf("From: \n");
    stations_array();
    scanf("%d" , &from);

    int to;
    printf("To: \n");
    stations_array();
    scanf("%d" , &to);

    int amount;
    amount = (to - from) * 10;
    printf("Amount : %d taka\n" , abs(amount));

    int time_required;
    time_required = (to - from) * 5;
  

//Time
    time_t currentTime;
    struct tm *localTime;

    currentTime = time(NULL);
    localTime = localtime(&currentTime);

    printf("Departure time : %s", asctime(localTime));

    currentTime = time(NULL);
    localTime = localtime(&currentTime);

    int minutesToAdd = abs(time_required);
    currentTime += minutesToAdd * 60;
    localTime = localtime(&currentTime);

    printf("Boarding time : %s" , asctime(localTime));

    return 0;
}