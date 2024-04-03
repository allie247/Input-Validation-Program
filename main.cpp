#include <ctype.h>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

char get_char_from_user();
string get_word_from_user();
string get_sentence_from_user();
int get_int_from_user();
double get_float_from_user();

// main method created by Lisa Dion, prompts user for input
int main() {
    char letter = get_char_from_user();
    cout << "You entered the character " << letter << endl;
    string word = get_word_from_user();
    cout << "You entered the word " << word << endl;
    string sentence = get_sentence_from_user();
    cout << "You entered the sentence: " << sentence << endl;
    int num = get_int_from_user();
    cout << "You entered the number " << num << endl;
    double flo = get_float_from_user();
    cout << "You entered the floating-point number " << flo << endl;
    return 0;
}

//input validation for characters
char get_char_from_user() {
    string sentence = "a";
    char character = 'a';
    bool flag = true;
    cout << "Enter a single character: "; //prompts user for input
    while (flag) {
        getline(cin, sentence); //assigns input to string sentence
        if (sentence.length() > 1) { //if string is greater than 1 character in length, invalid
            cout << "Invalid input. Enter a single character: ";
            sentence = "a";
        }
        else if (sentence.length() == 0) { //no input
            cout << "No input. Enter a single character: ";
        }
        else {
            flag = false;
        }
    }
    character = sentence[0]; //converts string sentence to character
    return character;
}

//input validation for words
string get_word_from_user() {
    string word;
    bool flag = true;
    cout << "Enter a single word: "; //prompts user for input
    while (flag) {
        getline(cin, word); //assigns input to string word
        bool hasSpace = false;
        if (word.length() == 0) { //no input
            cout << "No input. Enter a single word: ";
            hasSpace = true;
        }
        for (int i = 0; i < word.length() && hasSpace == false; i++) { //loops through string
            if (isspace(word[i])) { //checks each character for whitespace, invalid if detected
                cout << "Invalid input. Enter a single word: ";
                hasSpace = true;
            }
        }
        if (hasSpace) {
            flag = true;
        }
        else {
            flag = false;
        }
    }
    return word;
}

//input validation for sentences
string get_sentence_from_user() {
    string s = "";
    cout << "Enter a sentence: "; //prompts user for input
    while (s.length() == 0) {
        getline(cin, s); //assigns input to string s
        if (s.length() == 0) { //no input
            cout << "No input. Enter a sentence: ";
        }
    }
    return s;
}

//input validation for integers
int get_int_from_user() {
    string stringNumber;
    int number;
    bool flag = true;
    bool wasNegative = false;
    cout << "Enter a number: "; //prompts user for input
    while (flag) {
        getline(cin, stringNumber); //assigns input to string stringNumber
        bool notNumber = false;
        if (stringNumber.length() == 0) { //no input
            cout << "No input. Enter a number: ";
            notNumber = true;
        }
        else if (stringNumber[0] == '-') { //checks if number is negative
            stringNumber.erase(0,1); //removes the negative
            wasNegative = true; //marks that number was negative
        }
        for (int i = 0; i < stringNumber.length() && notNumber == false; i++) { //loops through string
            if (!isdigit(stringNumber[i])) { //checks to see if character is a digit, invalid if not
                cout << "Invalid input. Enter a number: ";
                notNumber = true;
            }
        }
        if (notNumber) {
            flag = true;
        }
        else {
            flag = false;
        }
    }
    number = stoi(stringNumber); //converts string to integer
    if (wasNegative) { //reassigns negative sign to number if it was marked as negative
        number = number * -1;
    }
    return number;
}

//input validation for floating-point numbers
double get_float_from_user() {
    string stringFloat;
    double floatingPoint;
    bool flag = true;
    bool wasNegative = false;
    int pointCounter = 0;
    cout << "Enter a floating-point number: "; //prompts user for input
    while (flag) {
        getline(cin, stringFloat); //assigns input to string stringFloat
        bool notNumber = false;
        if (stringFloat.length() == 0) { //no input
            cout << "No input. Enter a floating-point number: ";
            notNumber = true;
        }
        else if (stringFloat[0] == '-') { //checks if number is negative
            stringFloat.erase(0, 1); //removes the negative
            wasNegative = true; //marks that number was negative
        }
        for (int i = 0; i < stringFloat.length() && notNumber == false && pointCounter <=1; i++) { //loops through string
            if (stringFloat[i] == '.') { //checks to see if character is a point
                pointCounter++; //increments point counter to make sure no more than 1 point is validated
            }
            else if (!isdigit(stringFloat[i])) { //checks to see if character is a digit, invalid if not
                cout << "Invalid input. Enter a floating-point number: ";
                notNumber = true;
            }
        }
        if (stringFloat.back() == '.') { //checks to see if last character is a point, invalid if so
            cout << "Invalid input. Enter a floating-point number: ";
            notNumber = true;
        }
        if (notNumber) {
            flag = true;
        }
        else {
            flag = false;
        }
    }
    floatingPoint = stod(stringFloat); //converts string into floating point number
    if (wasNegative) { //reassigns negative sign to number if it was marked as negative
        floatingPoint = floatingPoint * -1;
    }
    return floatingPoint;
}