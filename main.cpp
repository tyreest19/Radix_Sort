//
//  main.cpp
//  Radix_Sort
//
//  Created by Tyree Stevenson on 4/7/17.
//  Copyright © 2017 Tyree Stevenson. All rights reserved.
//

#include <iostream>
#include "Utility.hpp"
#include "constants.h"
using namespace std;



int main(int argc, const char * argv[]) {
    int numbers[MAX_CONSTANT];
    int menu_value;
    int counter = 0;
    int count_user_entered_numbers = 0;
    int temp;
    int amount_of_numbers = 0;
    string file_name;
    
    cout << "This is a program reads a file of spaced numbers and sorts them by sigificant digits\n";
    menu_value = User_Inputted_Number(PRINT_INPUT_MENU, INVALID_NUMBER, INVALID_NUMBER, 0, 1);
    
    if (menu_value == 0)
    {
        cout << "Enter in desired numbers and use spaces to diferentaite numbers. Also enter non number to quit: \n";

        for (int i = 0; cin >> temp && i < MAX_USER_INPUTTED_NUMBERS; i++)
        {
            numbers[i] = temp;
            amount_of_numbers++;
        }
        cin.clear();
    }
    
    else if (menu_value == 1)
    {
        int lower_bound = User_Inputted_Number("Enter a lower bound: ", "Please enter a number from 0 to 1000: ", "Please enter a number from 0 to 1000: ", MINIMUM_CONSTANT, NUMBER_MAXIMUM_VALUE);
        int upper_bound = User_Inputted_Number("Enter a upper bound: ", "Invalid Input", "Invalid Input", lower_bound, NUMBER_MAXIMUM_VALUE);
        amount_of_numbers = User_Inputted_Number("Enter amount of numbers: ", "Please enter a number from 0 to  1000: ", "Please enter a number from 0 to  1000: ", MINIMUM_CONSTANT, MAX_CONSTANT);
        Generate_Array_Of_Random_Numbers(lower_bound, upper_bound, amount_of_numbers, numbers);
    }
    
    cout << "\n\nOroginal List: \n";
    for (int i = 0; i < amount_of_numbers; i++)
    {
        cout << numbers[i] << " ";
        counter++;
        if (counter == 10)
        {
            counter = 0;
            cout << "\n";
        }
        
    }
    
    cout << "\n";
    Radix_Sort(numbers, amount_of_numbers);
    counter = 0;
    cout << "\nAscending Order: \n";
    for (int i = 0; i < amount_of_numbers; i++)
        {
            cout << numbers[i] << " ";
            counter++;
            if (counter == 10)
            {
                counter = 0;
                cout << "\n";
            }
        }
    counter = 0;
    cout << "\n\nDescending Order: \n";
    for (int i = amount_of_numbers - 1; i >= 0; i--)
        {
            cout << numbers[i] << " ";
            counter++;
            if (counter == 10)
            {
                counter = 0;
                cout << "\n";
            }
        }
    cout << "\n";
    return 0;
}

