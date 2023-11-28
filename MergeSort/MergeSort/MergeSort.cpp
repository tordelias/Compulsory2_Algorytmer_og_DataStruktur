// MergeSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>
using namespace std; 

void MergeSort(list<int> &l)
{
    int size = l.size(); 
    list<int> left; 
    list<int> right; 
    auto it = l.begin(); 
    while (l.size() != size / 2 && size != 1)
    {
        left.push_back(l.front()); 
        l.pop_front(); 
    }
    if (size != 1 && l.size() == size / 2)
    {
        right.swap(l); 
        l.clear(); 
    }
    MergeSort(left);
    MergeSort(right);
    if (right.front() < left.front())
    {
        if (right.back() < left.back())
        {
            l.merge(right);
            l.merge(left);
        }
        else
        {
            //merge in middle 
        }
        
    }
    if (right.front() > left.front())
    {
        if (right.back() > left.back())
        {
            l.merge(left);
            l.merge(right);
        }
        else
        {
            //merge in middle 
            // kan hende jeg må bruke splice eller hva det heter a
        }

    }

}
int main()
{
    list<int> mainList; 


    std::cout << "Hello World!\n";
}



