//
//  Bin.cpp
//  Radix_Sort
//
//  Created by Tyree Stevenson on 4/8/17.
//  Copyright © 2017 Tyree Stevenson. All rights reserved.
//

#include "Bin.hpp"
#include <iostream>

using namespace std;

//=========================================================================================
// Intialize Bin Object.
//=========================================================================================

Bin:: Bin()
{
    head = nullptr;
}

//=========================================================================================
// Adds number to  bin.
//=========================================================================================

void Bin:: Push(int item)
{
    Bin_Node *new_node = new Bin_Node;
    new_node->number = item;
    if (!head)
        head = new_node;
    else
    {
        Bin_Node *traversal_node = head;
        while (traversal_node->next)
        {
            traversal_node = traversal_node->next;
        }
        traversal_node->next = new_node;
    }
}

//=========================================================================================
// Deletes number from bin and returns it.
//=========================================================================================

int Bin:: Pop()
{
    int temp = head->number;
    head = head->next;
    return temp;
}

//=========================================================================================
// Returns Size of bin.
//=========================================================================================

int Bin:: Size()
{
    return size;
}

//=========================================================================================
// Alerts programmer if bin is full.
//=========================================================================================

bool Bin:: Is_Full()
{
    return false;
}

//=========================================================================================
// Alerts programmer if bin is empty.
//=========================================================================================

bool Bin:: Is_Empty()
{
    return head == nullptr;
}
