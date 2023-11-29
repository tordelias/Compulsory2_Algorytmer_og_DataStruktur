// MergeSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>
#include <chrono>


using namespace std; 


void Merge(std::list<int>& l, std::list<int>& left, std::list<int>& right) 
{
   
    auto i = left.begin(), j = right.begin();

    while (i != left.end() && j != right.end()) {
        if (*i <= *j) {
            l.push_back(*i);
            ++i;
        }
        else {
            l.push_back(*j);
            ++j;
        }
    }

    while (i != left.end()) {
        l.push_back(*i);
        ++i;
    }

    while (j != right.end()) {
        l.push_back(*j);
        ++j;
    }
}

void MergeSort(list<int> &l)
{
    int size = l.size(); 
    list<int> left; 
    list<int> right; 
    while (l.size() != size / 2 && size != 1)
    {
        left.push_back(l.front()); 
        l.pop_front(); 
    }
    if (size != 1 && l.size() == size / 2)
    {
        right.swap(l); 
        l.clear(); 
        MergeSort(left);
        MergeSort(right);
    }
    Merge(l, left, right); 
}

void PrintList(list<int> l)
{
    for (auto first : l)
    {
        cout << first << " "; 
    }
}
int main()
{
    list<int> mainList; 
    int listSize = 10000;
    list<int> mList;
    srand(time(NULL));
    for (int i = 0; i < listSize; i++)
    {
        mainList.push_back(rand() % 10000 + 1);
    }
   
    auto start = std::chrono::high_resolution_clock::now();
    MergeSort(mainList); 
    auto end = std::chrono::high_resolution_clock::now();
    cout << "sorted list\n"; 
    PrintList(mainList); 
    cout << "\n"; 

    std::cout << "Time taken" << std::chrono::duration_cast<std::chrono::milliseconds>((end)-(start)).count() << " ms" << std::endl;

}



