//
//  Utility.cpp
//  Radix_Sort
//
//  Created by Tyree Stevenson on 4/7/17.
//  Copyright © 2017 Tyree Stevenson. All rights reserved.
//

#include <string>
#include <iostream>
#include <fstream>
#include "Utility.hpp"
#include "Bin.hpp"
#include <stdlib.h>
#include <time.h>
using namespace std;

//==========================================================================================
// Takes constant char pointer and converts it into a string.
// If one of the characters are not a digit the function returns -1.
//==========================================================================================
int String_To_Int(const char *str)
{
    int result = 0;
    int prefix = 0;
    
    if (str[0] == '\0')
    {
        return -1;
    }
    
    else if (str[0] == '-' || str[0] == '+')
    {
        prefix = 1;
    }
    
    for (int i = prefix; str[i] != '\0'; ++i)
    {
        if ('0' <= str[i] && str[i] <= '9')
        {
            result = result*10 + str[i] - '0';
        }
        
        else
        {
            return -1;
        }
    }
    
    if (str[0] == '-')
    {
        result *= -1;
    }
    
    return result;
}

//==========================================================================================
// Stores numbers from text file into an array
// Returns the amount of numbers
//==========================================================================================

int Store_Numbers_Into_Array(int array[], string file_name)
{
    ifstream file;
    file.open(file_name);
    int count = 0;
    int number;
    while (file >> number)
    {
        array[count] = number;
        count++;
    }
    file.close();
    return count;
}

//==========================================================================================
// Stores numbers by siginficant digits
//=========================================================================================

void Radix_Sort(int array[], int amount_of_numbers)
{
    int amount_of_digits = Amount_Of_Digits(array, amount_of_numbers) + 1;
    int sigfig = 10;
    for (int i = 0; i < amount_of_digits; i++)
    {
        Count_Sort(array, amount_of_numbers, sigfig, amount_of_digits);
        sigfig *= 10;
    }
}

void Count_Sort(int array[], int amount_of_numbers, int sigificant_digit, int amount_of_digits)
{
    int output[amount_of_numbers]; // output array
    Bin bins[NUMBER_OF_BINS];
    int counter = 0;
    
    for (int i = 0; i < amount_of_numbers; i++)
    {
        bins[(array[i] % sigificant_digit)/(sigificant_digit/10)].Push(array[i]);
    }
    
    for (int i = 0; i < NUMBER_OF_BINS; i++)
    {
        while (!bins[i].Is_Empty())
        {
            output[counter] = bins[i].Pop();
            counter++;
        }
    }
    
    for (int i = 0; i < amount_of_numbers; i++)
    {
        array[i] = output[i];
    }
}

//=========================================================================================
// Make user user enters a valid number
//=========================================================================================

int User_Inputted_Number(string prompt, string invalid_prompt, string out_of_bounds_prompt, int lower_bounds, int upper_bounds)
{
    int number = -1;
    string user_entered_number;
    
    while (number == -1 || (number < lower_bounds || number > upper_bounds))
    {
        cout << prompt;
        getline(cin, user_entered_number);
        number = String_To_Int(user_entered_number.c_str());
        cout << "\n";
        if (number == -1)
        {
            cout << invalid_prompt << "\n\n";
        }
        
        else if (number < lower_bounds || number > upper_bounds)
        {
            cout << out_of_bounds_prompt << "\n";
        }
    }
    
    return number;
}

//=========================================================================================
// Returns largest amount of digits in an array of numbers
//=========================================================================================

int Amount_Of_Digits(int array[], int array_size)
{
    int max_digits = to_string(array[0]).length();
    for (int i = 1; i < array_size - 1; i++)
    {
        string number;
        String_To_Int(number, array[i]);
        if (number.length() > max_digits)
        {
            max_digits = number.length();
        }
    }
    return max_digits;
}

//=========================================================================================
// Returns largest amount of digits in an array of numbers
//=========================================================================================

void Generate_Array_Of_Random_Numbers(int lower_bound, int upper_bound, int amount_of_numbers, int array[])
{
    srand(0);
    for (int i = 0; i < amount_of_numbers; i++)
    {
        array[i] = lower_bound + (rand() % (upper_bound - lower_bound + 1));
    }
}

//=========================================================================================
// Convert string to int and Int to string
//=========================================================================================

bool String_To_Int(const std::string& str, int& result)
{
    std::string::const_iterator i = str.begin();
    
    if (i == str.end())
        return false;
    
    bool negative = false;
    
    if (*i == '-')
    {
        negative = true;
        ++i;
        
        if (i == str.end())
            return false;
    }
    
    result = 0;
    
    for (; i != str.end(); ++i)
    {
        if (*i < '0' || *i > '9')
            return false;
        
        result *= 10;
        result += *i - '0';
    }
    
    if (negative)
    {
        result = -result;
    }
    
    return true;
}
