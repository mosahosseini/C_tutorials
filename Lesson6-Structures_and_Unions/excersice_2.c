#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//- Create a date/time handling program

void print_date_time(){
    time_t now; 
    time(&now);
    struct tm*local = localtime(&now);
    printf("Current Date and Time : \n");
    printf("Date : %02d-%02d-%d\n" , local ->tm_mday , local->tm_mon+1 , local->tm_year+1900);
    printf("Hour : %02d-%02d-%02d" , local->tm_hour , local-> tm_min , local->tm_sec);

}


void add_days(int days){
    time_t now ; 
    time(&now);
    struct tm future = *localtime(&now);
    future.tm_mday += days ; 
    mktime(&future); // normalize time struct

    printf("Date %d days from now is : %02d-%02d-%d" ,days ,future.tm_mday , future.tm_mon+1 , future.tm_year+1900); 

}

void add_hours(int hours){
    time_t now ; 
    time(&now);
    struct tm future = *localtime(&now);
    future.tm_hour +=hours;
    mktime(&future);

    printf("%d hours from now the Time and Date will be:\n" , hours);
    printf("Date: %02d-%02d-%d     Time: %02d:%02d:%02d" ,future.tm_mday , future.tm_mon+1
    , future.tm_year+1900 , future.tm_hour , future.tm_min , future.tm_sec);
}



int main(){
    add_hours(240);


}