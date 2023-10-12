/* date_functions.c
   CSC 111 - Fall 2023 - Assignment 3

   B. Bird - 2023-09-20
   (Put your name/StudentID/date here when you implement your solution)
*/

#include <stdio.h>

/* is_leap_year(year)
   Given a year, determine whether that year is a leap year.
   Parameters: year (integer)
   Return value (integer):
     - If the year is a leap year, return 1
     - Otherwise, return 0
  
   For this function _only_, you may assume that the year number 
   will always be valid (that is, greater than or equal to 1).
*/
int is_leap_year(int year){
    /* Your code here */
    if( year % 4 != 0) { return 0; }
    if ( year % 100 != 0) { return 1;}
    if ( year % 400 != 0) { return 0;}
    return 1; 
}


/* days_in_year(year)
   Given a year, return the number of days in that year.
   A leap year has 366 days. All other years have 365 days.

   Parameters: year (integer)
   Return value (integer):
     - If year is valid (greater than or equal to 1),
       return the number of days in that year.
     - If year is invalid (negative or zero), return -1.
*/
int days_in_year(int year){
    /* Your code here */
    if (year <= 0) { return -1; }
    if (is_leap_year(year) == 1) { return 366; }
    return 365; 

}

/* days_in_month(year, month_number)
   Given a year and a numerical representation of the month (where 1 is January
   and 12 is December), return the number of days in that month.
   
   Note that the number of days in February (month 2) will vary depending on 
   whether the year is a leap year.

   Parameters: year (integer), month_number (integer)
   Return value (integer): 
     - If the month number is valid (between 1 and 12, inclusive),
       the return value will be the number of days in the provided
       month during the provided year.
     - If the month number is invalid (negative, zero, greater than 12),
       or the year number is invalid (negative or zero),
       the return value will be -1.
*/
int days_in_month(int year, int month_number){
    /* Your code here */
    //time for a big big switch statement lmao
    if(month_number > 12 || month_number < 1) { return -1; }
    
    switch(month_number){
        case 1:
            //jan
            return 31;
            break;
        case 2:
            //feb
            if(is_leap_year(year) == 1) {return 29;}
            return 28;
            break;
        case 3:
            //mar
            return 31;
            break;
        case 4:
            //apr
            return 30;
            break;
        case 5:
            //may
            return 31;
            break;
        case 6:
            //jun
            return 30;
            break;
        case 7:
            //jul
            return 31;
            break;
        case 8:
            //aug
            return 31;
            break;
        case 9:
            //sep
            return 30;
            break;
        case 10:
            //oct
            return 31;
            break;
        case 11:
            //nov
            return 30;
            break;
        case 12:
            //dec
            return 31; 
            break;
        default: 
            return -1;
    }         
    
    
    
}

/* date_valid(year, month_number, day)
   Determine if a particular year/month/day combination is a valid date.
   For example, the dates 2018-01-31, 2020-02-29 and 2023-09-15 are valid,
   but the dates 2023-01-32, 2019-02-29 and 2023-15-09 are not.

   Specifically, a date is valid if
    - The year number is greater than or equal to 1
    - The month number is between 1 and 12 (inclusive)
    - The day number is between 1 and the number of days in the provided 
      month during the provided year (note that the number of days in each 
      month may vary depending on whether the year is a leap year).

   Parameters: year (integer), month_number (integer), day (integer)
   Return value (integer): 
     - If the date is valid, return 1
     - Otherwise, return 0
*/
int date_valid(int year, int month_number, int day){
    /* Your code here */
    if (year <= 0){return 0;}
    if (month_number > 12 || month_number < 1){ return 0;}
    if (day > days_in_month(year, month_number)){ return 0; }
    if (day < 1){ return 0; }
    return 1;
}

/* day_index(year, month_number, day)
   Given a date, return the day index of that date within its year.
   The day index is the number of days between the beginning of the year
   and the date. For example, the day index of 2024-01-01 is 1 and the day
   index of 2024-12-31 is 366 (since 2024 is a leap year).

   Parameters: year (integer), month_number (integer), day (integer)
   Return value (integer): 
     - If the date is valid, return the day index of the date
     - Otherwise, return -1
*/
int day_index(int year, int month_number, int day){
    /* Your code here */
    if(date_valid(year, month_number, day) == 0) { return -1; }
    int index =  0;
    for (int i = 1; i < month_number; i++){
        index += days_in_month(year, i); 
    }
    index += day;
    return index;
    
  //  return -999; //Placeholder (replace this return statement when you write your implementation)
}

/* I dont think this code is working as intended. 
int add_leap_days (int year) {
    int out; 
    for (int i = 0; i < year; i++){
        if(is_leap_year(i) == 1){
            out = out + 1; 
        }
    }
    printf("added %d leap days to year %d.\n", out, year);
    return out; 
}
*/        

/* chronological_order(year1, month1, day1, year2, month2, day2)
   Given two dates year1/month1/day1 and year2/month2/day2, determine which 
   date is chronologically earlier (or whether the two dates are equal).

   Parameters (all integers): year1, month1, day1, year2, month2, day2
   Return value (integer): 
     - If either (or both) of the provided dates is invalid, return -2.
     - If the two dates are both valid and year1/month1/day1 is chronologically
       earlier than year2/month2/day2, return -1.
     - If the two dates are both valid and year1/month1/day1 is chronologically
       later than year2/month2/day2, return 1.
     - If the two dates are both valid and exactly equal, return 0.
*/
int chronological_order(int year1, int month1, int day1, int year2, int month2, int day2){
    /* Your code here */
    //why not use an array or list<t> 
    // f it we ball 
    int date1_valid = date_valid(year1, month1, day1);
    int date2_valid = date_valid(year2, month2, day2);
    //please let us use boolean for these man it hurts me 
    
    if(date1_valid == 0 || date2_valid == 0) { return -2; }
    
    
    int index1 = (year1 * 365) + day_index(year1, month1, day1); //this is not an accurate solution but it should work in most cases, unless leap years come into play
    int index2 = (year2 * 365) + day_index(year2, month2, day2);
    
    if (index1 < index2){
        return -1;
    }
    if (index1 > index2){
        return 1;
    }
    if (index1 == index2) {
        return 0;
    }
    else {return -999;}

    
   // return -999; //Placeholder (replace this return statement when you write your implementation)
}
   
/* weekly_reminders(start_year, start_month, start_day, number_of_reminders)
   Given a date (year, month, day) and a number of reminders to generate, print
   out dates (one per line) at one week (7 day) intervals. The first date 
   printed will be the provided start date and the number of dates generated 
   will equal number_of_reminders.

   If the provided start date is invalid for any reason, or if number_of_reminders
   is zero or negative, print out the error message "Error: Invalid Parameters" 
   with no further output.

   If the start date is valid and number_of_reminders is at least one, print
   out dates as described above, using the format (YYYY-MM-DD). You can achieve
   this format with a print statement like 
    printf("%04d-%02d-%02d\n", year, month, day);

  For example, if the function is called with start date 2023-09-01 and
  number_of_reminders set to 14, the function will print the following dates
  2023-09-01
  2023-09-08
  2023-09-15
  2023-09-22
  2023-09-29
  2023-10-06
  2023-10-13
  2023-10-20
  2023-10-27
  2023-11-03
  2023-11-10
  2023-11-17
  2023-11-24
  2023-12-01

  Parameters (all integers): start_year, start_month, start_day, number_of_reminders
  Return value: None (return type void)
*/
void weekly_reminders(int start_year, int start_month, int start_day, int number_of_reminders){
    /* Your code here */
    int year = start_year; 
    int month = start_month;
    int day = start_day; 
    if (date_valid(year, month, day) == 0 || number_of_reminders <= 0){
        printf("Error: Invalid Parameters\n");
        return;
    }
    for(int i = 0; i < number_of_reminders; i++){
        printf("%04d-%02d-%02d\n", year, month, day);
        day = day + 7; 
        if(day > days_in_month(year, month)){
            day = day - days_in_month(year, month);
            month++;
            
            if(month > 12){
                month = month - 12;
                year++;
                }
        }
        
    }
}




int main(){

    printf("Output of weekly_reminders(2024, 2, 29, 2):\n");
    weekly_reminders(2024, 2, 29, 2);
    printf("\n");

    printf("Output of weekly_reminders(2023, 2, 29, 2):\n");
    weekly_reminders(2023, 2, 29, 2);
    printf("\n");

    printf("Output of weekly_reminders(2023, 10, 8, 0):\n");
    weekly_reminders(2023, 10, 8, 0);
    printf("\n");

    printf("Output of weekly_reminders(2015, 4, 31, 2):\n");
    weekly_reminders(2015, 4, 31, 2);
    printf("\n");

    printf("Output of weekly_reminders(2023, 3, 31, -2):\n");
    weekly_reminders(2023, 3, 31, -2);
    printf("\n");

    

    return 0;
}