 /* Eoin Finlay
    29/11/17
    Ex11 - Date Calculator*/


//preprocessor directives
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <windows.h>
#include <cmath>

using namespace std;

// structure definition
struct date
{
	int day;
	int month;
	int year;
};

// Function Declarations
int checkLeapYear(int);
void TodaysDate(struct date &);

//Main Function
int main()
{

    //variable declarations - today & tomorrow members of date, 12 element array for months
    struct date today, tomorrow;
    int monthlength [12] = {31, 28, 31, 30, 30, 30, 31, 31, 30, 31, 30, 31};

    //Calling Todays Date Function
    TodaysDate(today);

    //displaying todays date to user
    cout << "\n\nToday's date is " << today.day  << "/" << today.month<< "/" << today.year << endl;

    //incrementing for next day, keeping month and year same
    tomorrow.day = today.day + 1;
    tomorrow.month = today.month;
    tomorrow.year = today.year;

    //calling checkleapyear function
    monthlength[1] = checkLeapYear(today.year);

    // if statement to increment month by one
    if(tomorrow.day > monthlength[today.month-1])
    {
        tomorrow.day = 1;
        tomorrow.month = today.month +1;
        tomorrow.year = today.year;
    }

    // if statement to increment into new year
    if (today.month >= 12)
    {
        tomorrow.month = 01;
        tomorrow.year = today.year + 1;
    }

    // displaying tomorrows date to user
    cout << "\n\nTomorrows Date is :" << tomorrow.day << "/" << tomorrow.month << "/" << tomorrow.year << endl;

    return 0;
}

// Todays Dated function header
void TodaysDate(struct date &today)
{
    //prompting user to enter date
    cout<< "\n\nEnter todays day (dd): ";
    cin>> today.day;

    cout<< "\nEnter todays month (mm): ";
    cin>> today.month;

    cout<< "\nEnter todays year (yyyy): ";
    cin>> today.year;

    return;
}

// check leap year function header
int checkLeapYear(int year)
{
    //variable declaration
    int days = 28;

    // if statement to check if today.year is a leap year
    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
            {
                days = 29;
            }

        }
        else
        { //only by 4, not by 100
            days = 29;
        }
    }

    return days;
}
