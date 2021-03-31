/*
 * Created by Bryson Armstrong on 3/30/2021.
 *
 * Contains functions for converting roman numerals to decimal integers and vice versa.
 */
#include <string>
#include <stdexcept>
#include <sstream>
#include <unordered_set>
#include <unordered_map>

const int ROMAN_I = 1;
const int ROMAN_V = 5;
const int ROMAN_X = 10;
const int ROMAN_L = 50;
const int ROMAN_C = 100;
const int ROMAN_D = 500;
const int ROMAN_M = 1000;

/*
 * Converts a single roman character into its decimal equivalent.
 * Throws an invalid_argument error if c is not a valid roman numeral.
 */
int romanCharToDecimal(const char c) {
    if (c == 'I') {
        return ROMAN_I;
    } if (c == 'V') {
        return ROMAN_V;
    } if (c == 'X') {
        return ROMAN_X;
    } if (c == 'L') {
        return ROMAN_L;
    } if (c == 'C') {
        return ROMAN_C;
    } if (c == 'D') {
        return ROMAN_D;
    } if (c == 'M') {
        return ROMAN_M;
    } else {
        std::string message = " is not a valid roman numeral character.";
        message = c + message;
        throw std::invalid_argument(message);
    }
}

/*
 * Converts a Roman Numeral character into decimal
 * Throws an invalid_argument error if the input is not a valid Roman Numberal.
 */
int convertRomanToDecimal(std::string romanNumeral) {
    if (romanNumeral.empty()) {
        return 0;
    }
    int current = romanCharToDecimal(romanNumeral.at(0));
    int next;
    int result = 0;
    int low = ROMAN_M;  //This value will ensure that roman numerals are in descending order (except when a subtraction takes place)
    bool merged = false; //This tracks if a subtraction takes place, preventing multiple subtractions from taking place
    //This for loop runs through all but the last character
    for (int i = 1; i < romanNumeral.size(); i++) {
        next = romanCharToDecimal(romanNumeral.at(i));
        if (next > current) {
            if (merged || next > 10*current) {
                //This violates rule #4 of roman numerals
                throw std::invalid_argument("Invalid roman numeral");
            }
            //We can essentially "merge" the two values into one
            current = next - current;
            merged = true;
        } else {
            //Any value or two-value pair may not be greater than those preceding it.
            if (current > low) {
                throw std::invalid_argument("Invalid roman numeral");
            }
            result += current;
            low = current;
            current = next;
            merged = false;
        }
    }
    //Deals with last character
    if (current > low) {
        throw std::invalid_argument("Invalid roman numeral");
    }
    result += current;

    return result;

}

/*
 * Converts a decimal integer into a Roman Numeral (returned as a string value).
 */
std::string convertDecimalToRoman(unsigned int decimal) {
    std::unordered_map<int, std::string> values;
    values[ROMAN_I] = "I";
    values[ROMAN_V] = "V";
    values[ROMAN_X] = "X";
    values[ROMAN_L] = "L";
    values[ROMAN_C] = "C";
    values[ROMAN_D] = "D";
    values[ROMAN_M] = "M";
    std::stringstream ss;
    while (decimal >= ROMAN_M) {
        ss << "M";
        decimal -= ROMAN_M;
    }
    unsigned int temp;
    //Loops through each ten's digit, in reverse order, appending correct roman numeral characters with each iteration.
    for (unsigned int i = 100; i > 0; i /= 10) {
        temp = decimal / i;
        if (temp == 9) {
            ss << values[i];
            ss << values[10*i];
        } else if (temp == 4) {
            ss << values[i];
            ss << values[5*i];
        } else {
            if (temp >= 5) {
                ss << values[5*i];
                temp -= 5;
            }
            while (temp > 0) {
                ss << values[i];
                temp -= 1;
            }
        }
        decimal %= i;
    }
    return ss.str();
}
