#include <bits/stdc++.h>
using namespace std;

bool leapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        return true;
    else
        return false;
}




struct Date {
    int day;
    int month;
    int year;

    bool isValidDate(){
        if (year < 0  || month < 1 || month > 12)
            return false;
        if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
            return day >= 1 && day <= 31;
        } else if (month == 4 || month == 6 || month == 9 || month == 11) {
            return day >= 1 && day <= 30;
        } else if (month == 2 && !leapYear(year)) {
            return day >= 1 && day <= 28;
        } else if (month == 2 && leapYear(year)) {
            return day >= 1 && day <= 29;
        }
        return false;
    }

    void newDate(int d, int m, int y) {
        day = d;
        month = m;
        year = y;
    }

    string getDayOfWeek(){
        if (month <= 2) {
            month += 12;
            year--;
        }
        int res = day + 13 * (month + 1) / 5 + year % 100 + year % 100 / 4 + (year / 100) / 4 - 2 * (year / 100);
        res %= 7;
        if (res == 0) 
            return "Saturday";
        else if (res == 1) 
            return "Sunday";
        else if (res == 2) 
            return "Monday";
        else if (res == 3) 
            return "Tuesday";
        else if (res == 4)
            return "Wednesday";
        else if (res == 5) 
            return "Thursday";
        else if (res == 6) 
            return "Friday";
    }
    
    int calculateDifference(const Date& date) const {
    const int daysPerMonth[] = {31, 28 + leapYear(year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int totalDays1 = day;
    for (int m = 0; m < month - 1; ++m) {
        totalDays1 += daysPerMonth[m];
    }
    int totalYears1 = year - 1;
    totalDays1 += totalYears1 * 365 + totalYears1 / 4 - totalYears1 / 100 + totalYears1 / 400;

    int totalDays2 = date.day;
    for (int m = 0; m < date.month - 1; ++m) {
        totalDays2 += daysPerMonth[m];
    }
    int totalYears2 = date.year - 1;
    totalDays2 += totalYears2 * 365 + totalYears2 / 4 - totalYears2 / 100 + totalYears2 / 400;

    return abs(totalDays1 - totalDays2);
   }


   
   void printDate(){
        string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
        cout << day << " " << months[month - 1] << "," << year << endl;
   }

    bool operator<(const Date& date) {
       if (year != date.year)
            return year < date.year;
        if (month != date.month)
            return month < date.month;
            return day < date.day;
   }
};

int main() {
    Date d1= {2, 11, 2020};
    Date d2={28, 2, 2022};
    Date d3={15, 7, 2014};
    Date d4={31, 4, 2011};
    Date d5={3, 3, 2023};
    Date d6={12, 8, 2021};
    
    cout << d1.isValidDate() << endl;
    cout << d4.isValidDate() << endl;
    
    d2.printDate();  
    d4.newDate(30, 4, 2022);
    
    cout << d4.getDayOfWeek() << endl;
    cout << d5.getDayOfWeek() << endl;
    
    cout << d1.calculateDifference(d2) << endl;
    cout << d5.calculateDifference(d6) << endl;
    
    d3.printDate();
    d4.printDate();
    
    
    vector<Date> dates;
    dates.push_back(d1);
    dates.push_back(d2);
    dates.push_back(d3);
    dates.push_back(d4);
    dates.push_back(d5);
    dates.push_back(d6);
    sort(dates.begin(), dates.end());
    for (int i = 0; i < dates.size(); ++i) {
        dates[i].printDate();
    }


    
    return 0;
}

