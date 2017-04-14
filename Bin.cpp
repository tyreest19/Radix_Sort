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
Bin:: Bin()
{
    head = nullptr;
}

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

int Bin:: Pop()
{
    int temp = head->number;
    head = head->next;
    return temp;
}

int Bin:: Size()
{
    return size;
}

bool Bin:: Is_Full()
{
    return false;
}

bool Bin:: Is_Empty()
{
    return head == nullptr;
}
