#include <iostream>
using namespace std;



class Date
{
private:
    int day;
    int month;
    int year;
public:
    Date(int d, int m, int y)
    {
        day = d;
        month = m;
        year = y;
    }
    void print() {cout << day << "/" << month << "/" << year << endl;}
    void nextDay() 
    {
        if (day == 31 && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12))
        {
            day = 1;
            if (month == 12) 
            {
                month = 1;
                year++;
                // cout << "1/1/" << year++ << endl;
            }
            else 
            {
                month++;
                // cout << "1/" << month++ << "/" << year << endl;
            }
        }
        else if (day == 30 && (month == 4 || month == 6 || month == 9 || month == 11))
        {
            day = 1;
            month++;
            // cout << "1/" << month++ << "/" << year << endl;
        }
        else if (day == 28 && month == 2)
        {
            // 閏年的規則是「四年一閏，逢百不閏，四百再閏」
            if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
            {
                day++;
            }
            else
            {
                day = 1;
                month++;
            }
        }
        else if (day == 29 && month == 2)
        {
            day = 1;
            month++;
        }
        else
            day++;
    }
};



int main() {
int date, month, year;
cout << "Input date: ";
cin >> date >> month >> year;
Date today(date, month, year);
today.print();
today.nextDay();
today.print();
return 0;
}