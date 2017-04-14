//
//  Utility.hpp
//  Radix_Sort
//
//  Created by Tyree Stevenson on 4/7/17.
//  Copyright © 2017 Tyree Stevenson. All rights reserved.
//

#ifndef Utility_hpp
#define Utility_hpp

#include <stdio.h>
#include <string>
int Store_Numbers_Into_Array(int array[], std::string file_name);
int String_To_Int(const char *str);
void Radix_Sort(int array[], int amount_of_numbers);
void Count_Sort(int array[], int amount_of_numbers, int sigificant_digit, int amount_of_digits);
int Amount_Of_Digits(int array[], int array_size);
int User_Inputted_Number(std::string prompt, std::string invalid_prompt, std::string out_of_bounds_prompt, int lower_bounds, int upper_bounds);
#endif /* Utility_hpp */
