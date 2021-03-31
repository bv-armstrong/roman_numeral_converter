/*
 * Created by Bryson Armstrong
 */
#include <iostream>
#include "RomanNumeralConverter.h"
using namespace std;

void decimalToRomanMenu() {
    bool running = true;
    int decimal = 0;
    cout << "Enter integers to convert, 0 or -1 to quit" << endl;
    while (running) {
        cin >> decimal;
        if (decimal <= 0) {
            running = false;
        } else {
            cout << decimal << " in Roman numerals is: " << convertDecimalToRoman(decimal) << endl;
        }
    }
}

void romanToDecimalMenu() {
    bool running = true;
    string roman;
    cout << "Enter Roman Numerals to convert, or q to quit" << endl;
    while (running) {
        cin >> roman;
        if (roman == "q") {
            running = false;
        } else {
            try {
                int decimal = convertRomanToDecimal(roman);
                cout << roman << " in decimal is: " << decimal << endl;
            } catch (invalid_argument) {
                cout << roman << " is not a valid Roman Numeral." << endl;
            }
        }
    }
}

int main() {
    bool running = true;
    char selection;
    while (running) {
        cout << "Do you wish to: " << endl;
        cout << "a). Convert decimal to Roman" << endl;
        cout << "b). Convert Roman to decimal" << endl;
        cout << "q). Quit" << endl;
        cin >> selection;
        if (selection == 'a') {
            decimalToRomanMenu();
        } else if (selection == 'b') {
            romanToDecimalMenu();
        } else if (selection == 'q') {
            running = false;
        } else {
            cout << "Invalid selection." << endl;
        }
        cin.clear();
        cin.ignore();
    }
}
