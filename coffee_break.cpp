#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

bool allDigitsSame(int hour, int minute) {
    // Convert to 4 digits: HH:MM
    int h1 = hour / 10;
    int h2 = hour % 10;
    int m1 = minute / 10;
    int m2 = minute % 10;
    
    return (h1 == h2 && h2 == m1 && m1 == m2);
}

string formatTime(int hour, int minute) {
    string result = "";
    if (hour < 10) result += "0";
    result += to_string(hour);
    result += ":";
    if (minute < 10) result += "0";
    result += to_string(minute);
    return result;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        string time;
        cin >> time;
        
        // Parse HH:MM
        int hour = stoi(time.substr(0, 2));
        int minute = stoi(time.substr(3, 2));
        
        // Check if current time already has all same digits
        if (allDigitsSame(hour, minute)) {
            cout << formatTime(hour, minute) << endl;
            continue;
        }
        
        // Find next valid time
        // Valid times: 00:00, 11:11, 22:22
        bool found = false;
        
        // Check 11:11 on same day
        if (hour < 11 || (hour == 11 && minute < 11)) {
            cout << "11:11" << endl;
            found = true;
        }
        // Check 22:22 on same day
        else if (hour < 22 || (hour == 22 && minute < 22)) {
            cout << "22:22" << endl;
            found = true;
        }
        // Next day 00:00
        else {
            cout << "00:00" << endl;
            found = true;
        }
    }
    
    return 0;
}