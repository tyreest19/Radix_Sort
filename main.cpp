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
    string file_name;
    
    cout << "This is a program reads a file of spaced numbers and sorts them by sigificant digits\n";
    menu_value = User_Inputted_Number(PRINT_INPUT_MENU, INVALID_NUMBER, INVALID_NUMBER, 0, 1);
    
    if (menu_value == 0)
    {
        cout << "Enter in desired numbers and use spaces to diferentaite numbers. Also enter non number to quit: \n";
        while (cin >> temp)
        {
            numbers[count_user_entered_numbers] = temp;
        }
    }
    
    cout << "Enter the filename: ";
    getline(cin,file_name);
    cout << "\n";
    
    int amount_of_numbers = Store_Numbers_Into_Array(numbers, file_name);
    menu_value = User_Inputted_Number(PRINT_ORDER_MENU, INVALID_NUMBER, INVALID_NUMBER, 0, 1);
    Radix_Sort(numbers, amount_of_numbers);
    
    cout << "\nOroginal List: \n\n";
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
    
    counter = 0;
    
    if(menu_value)
    {
        cout << "\nAscending Order: \n\n";
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
    }
    
    else
    {
        cout << "\nDescending Order: \n\n";
        for (int i = amount_of_numbers; i >= 0; i--)
        {
            cout << numbers[i] << " ";
            counter++;
            if (counter == 10)
            {
                counter = 0;
                cout << "\n";
            }
        }
    }
    
    cout << "\n";
    return 0;
}

