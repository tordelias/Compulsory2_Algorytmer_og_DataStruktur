// Compulsory2_MergeSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>

using namespace std;

/// <summary>
/// Prints the list
/// </summary>
/// <returns></returns>
void Print(list<int>& l)
{
    while (!l.empty() or l.size() > 0)
    {
        cout << l.front() << "\n";
        l.pop_front();
    }
}

/// <summary>
/// Checks if the list is sorted 
/// </summary>
/// <param name="list"></param>
/// <returns></returns>
bool isSorted(list<int> list) {
    int front;

    if (list.empty() or list.size() <= 1)
    {
        cout << "Sorted\n";
        return true;

    }

    else
    {
        front = list.front();
        list.pop_front();
        if (front > list.front())
        {
            return false;
        }
        isSorted(list);
    }
}

int main()
{
    std::cout << "Hello World!\n";
}

