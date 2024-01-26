#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

void stations_array ()
{
    const char *words[] = {"Uttara" , "Mirpur" , "Bijoy Sarani" , "Farmgate" , "Kawran Bazar" , "Shahbagh", "Dhaka University" , "Motijheel"};

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

    int time_required , amount;

    if(from == 1 && to == 2 || from == 2 && to == 1)
    {
        amount = 40;
        time_required = 15;
    }
    else if(from == 1 && to > 2 || from > 2 && to == 1)
    {
        amount = 40 + (abs(to - 2) * 10);
        time_required = 15 + (abs(to - 2) * 5);
    }
    else if(from == 2 && to == 3 || from == 3 && to == 2)
    {
        amount = 20;
        time_required = 15;
    }
    else if(from == 2 && to > 3 || from > 3 && to == 2)
    {
        amount = 20 + (abs(to - 2) * 10);
        time_required = 15 + (abs(to - 2) * 5);
    }
    else if(from > 3 && to == 2 || to > 3 && from == 2)
    {
        amount = 20 + (abs(to - from) * 10);
    }
    else
    {
        amount = abs(to - from) * 10;
        time_required = abs(to - from) * 5;
    }

    printf("Amount : %d taka\n" , amount);

  

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

    printf("Duration : %d min\n" , time_required);

    return 0;
}
