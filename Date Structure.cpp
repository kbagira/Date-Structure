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

bool isValidDate() const {
    if (year < 0 || year > 2024 || month < 1 || month > 12)
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

string getDayOfWeek() const {
    int a = year % 100;
    int b = a / 4;
    int res = month + a + b;
    if (leapYear(year) && (month == 1 || month == 2)) {
         res -= 1;
    }
    res += day;
    res %= 7;
    if (res == 1)
        return "Monday";
    else if (res == 2)
        return "Tuesday";
    else if (res == 3)
        return "Wednesday";
    else if (res == 4)
        return "Thursday";
    else if (res == 5)
        return "Friday";
    else if (res == 6)
        return "Saturday";
    else if (res == 0)
        return "Sunday";
}

void newDate(int d, int m, int y) {
    day = d;
    month = m;
    year = y;
}
};

int dateToDays(const Date& date) {
    int days = 0;
    for (int y = 1; y < date.year; ++y) {
        if (leapYear(y)) {
            days += 366;
        } else {
            days += 365;
        }
    }
    for (int m = 1; m < date.month; ++m) {
        if (m == 2 && leapYear(date.year))
            days += 29;
        else {
            if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
                days += 31;
            else
                days += 30;
        }
    }
    days += date.day - 1; 
    return days;
}

int calculateDifference(const Date& date1, const Date& date2) {
    int days1 = dateToDays(date1);
    int days2 = dateToDays(date2);
    return abs(days1 - days2);
}


bool operator<(const Date& date1, const Date& date2) {
    if (date1.year != date2.year)
        return date1.year < date2.year;
    if (date1.month != date2.month)
        return date1.month < date2.month;
    return date1.day < date2.day;
}

int main() {
    Date date1, date2;
    int day, month, year;

    cout << "Enter the first date (day month year): ";
    cin >> day >> month >> year;
    date1.newDate(day, month, year);

    cout << "Enter the second date (day month year): ";
    cin >> day >> month >> year;
    date2.newDate(day, month, year);

    if (!date1.isValidDate() || !date2.isValidDate()) {
        cout << "Invalid date entered." << endl;
        return 1;
    }

    cout << "Day of the week for the first date: " << date1.getDayOfWeek() << endl;
    cout << "Day of the week for the second date: " << date2.getDayOfWeek() << endl;

    cout << "Difference between the two dates: " << calculateDifference(date1, date2) << " days." << endl;
    
    if (date1 < date2) {
        cout << "The first date is earlier than the second date." << endl;
    } else if (date2 < date1) {
        cout << "The first date is later than the second date." << endl;
    } else {
        cout << "The two dates are the same." << endl;
    }

    return 0;
}

