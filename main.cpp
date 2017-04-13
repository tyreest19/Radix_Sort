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
    bool ascending_order;
    string file_name;
    
    cout << "This is a program reads a file of spaced numbers and sorts them by sigificant digits\n";
    cout << "Enter the filename: ";
    getline(cin,file_name);
    
    int amount_of_numbers = Store_Numbers_Into_Array(numbers, file_name);
    cout << "Choose a display option for the numbers\n0) Descending Order\n1)Ascending Order\n";
    

    Radix_Sort(numbers, amount_of_numbers);
    
    if(ascending_order)
    {
        for (int i = 0; i < amount_of_numbers; i++)
        {
            cout << numbers[i] << endl;
        }
    }
    
    else
    {
        for (int i = amount_of_numbers; i >= 0; i--)
        {
            cout << numbers[i] << endl;
        }
    }
    
    return 0;
}

