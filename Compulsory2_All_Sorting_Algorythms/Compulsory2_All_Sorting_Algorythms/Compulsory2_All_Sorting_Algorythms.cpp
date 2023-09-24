// Compulsory2_All_Sorting_Algorythms.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>
#include <algorithm>
#include <random>
#include <chrono>


using namespace std;
 

int algorythm;
int ListSize = 0;
int maxruntime = 0;
bool bubblerecursive;
bool Bogo;

void BogoSort(list<int>& l);
bool isSorted(const list<int> list);

/// <summary>
/// Prints the list
/// </summary>
/// <returns></returns>
void Print(list<int>& l)
{
    cout << "ListSize " << ListSize << "\n";
    while (!l.empty() or l.size() > 0)
    {
        cout << l.front() << "\n";
        l.pop_front();
    }
    if (isSorted(l) == false)
    {
        cout << "not Sorted\n";
    }
    else
    {
        cout << "Sorted\n";
    }
    if(Bogo)
    cout << "iterations " << maxruntime << "\n";
}



/// <summary>
/// Checks if the list is sorted 
/// </summary>
/// <param name="list"></param>
/// <returns></returns>
bool isSorted(const list<int> list) {

    if (list.size() <= 1 or list.empty() == true)
    {
        return true;
    }

    auto it = list.begin();
    auto prev = it++;

    while (it != list.end()) {
        if (*prev > *it) {
            // cout << "not sorted\n";
            return false;
        }
        ++prev;
        ++it;
    }
    //cout << "sorted\n";
    return true;
}



/// <summary>
/// RunsBogo sort.
/// BogoSort works better as iterative rather than Recursive because VS thinks a recursive funksion is an infinateloop a little overt 1k iterations.
/// so with a itterative funksion i can run it 100k or more if i want. 
/// </summary>
/// <param name="l"></param>
void BogoSort(list<int>& l)
{
    if (isSorted(l))
    {
        return;
    }
    else {
        while (!isSorted(l) && maxruntime < 2000000000)
        {
            maxruntime++;
            vector<list<int>::iterator> iterators;
            list<int> shuffledList;

            srand(static_cast<unsigned int>(time(nullptr)));
            random_device rd;
            mt19937 g(rd());

            for (auto it = l.begin(); it != l.end(); ++it)
            {
                iterators.push_back(it);
            }
            shuffle(iterators.begin(), iterators.end(), g);

            for (const auto& it : iterators)
            {
                shuffledList.push_back(*it);
            }
            shuffledList.swap(l);
            if (isSorted(l))
            {
                return;
            }
        }
        return;
    }


}

void BubleSort(list<int>& list)
{
   if(bubblerecursive)
   {
        if (isSorted(list))
        {
            return;
        }
        else //should use while(!isSorted(list); but need another recursion 
        {
            auto it = list.begin();
            auto next = std::next(it);
            while (next != list.end()) {
                if (*it > *next) {
                    iter_swap(it, next);
                }
                ++it;
                ++next;
            }


            BubleSort(list);
        }
    }

    // iterative approach

   else
    {
        do {
            auto it = list.begin();
            auto next = std::next(it);
            while (next != list.end()) {
                if (*it > *next) {
                    iter_swap(it, next);
                }
                ++it;
                ++next;
            }

        } while (!isSorted(list));
    }

}

/// <summary>
/// i'm splitting the list bassed on the pivot, then putting them all together at the end
/// </summary>
/// <param name="list"></param>
void QuickSort(list<int>& list)
{
    std::list<int> lesser;
    std::list<int> equal;
    std::list<int> greater;

    if (list.size() <= 1)
    {
        return;
    }
    else
    {
        auto it = list.begin();
        auto const Pivot = list.front();
        while (it != list.end())
        {
            if (*it < Pivot)
            {
                lesser.push_back(*it);
            }
            else if (*it > Pivot)
            {
                greater.push_back(*it);
            }
            else
            {
                equal.push_back(*it);
            }
            ++it;
        }
        QuickSort(lesser);
        QuickSort(greater);
        list.clear();
        list.splice(list.end(), lesser);
        list.splice(list.end(), equal);
        list.splice(list.end(), greater);
    }
}

int main()
{
    bool Running = true;
    int algorythm;
    int bIterative;
    int continue1;
    list<int> list;
   
    while(Running)
    {

        cout << "How big Should the list be?\n";
        cin >> ListSize;

        srand(time(NULL));
        for (int i = 0; i < ListSize; i++)
        {
            list.push_back(rand() % 10000 + 1);
        }
        cout << "BogoSort = 1  BubbleSort = 2  QuickSort = 3\n";
        cin >> algorythm;
        auto start = std::chrono::high_resolution_clock::now();
        switch (algorythm)
        {
        case 1:
            Bogo = true;
           // auto start = std::chrono::high_resolution_clock::now();
            BogoSort(list);
           // auto end = std::chrono::high_resolution_clock::now();
           // runTime = std::chrono::duration_cast<std::chrono::milliseconds>((end)-(start)).count();
            break;
        case 2:
            cout << "Should Bubblesort be iterative = 1 or recursive = 2\n";
            cin >> bIterative;
            switch (bIterative)
            {
            case 1:
                bubblerecursive = false;
                break;
            case 2:
                bubblerecursive = true;
                break;
            default:
                cout << "invalid choice";
                cout << "Should Bubblesort be iterative = 1 or recursive = 2\n";
                cin >> bIterative;
                break;
            }
           // auto start = std::chrono::high_resolution_clock::now();
            BubleSort(list);
           // auto end = std::chrono::high_resolution_clock::now();
           // runTime = std::chrono::duration_cast<std::chrono::milliseconds>((end)-(start)).count();

            break;
        case 3:
           // auto start = std::chrono::high_resolution_clock::now();
            QuickSort(list);
           // auto end = std::chrono::high_resolution_clock::now();
          //  runTime = std::chrono::duration_cast<std::chrono::milliseconds>((end)-(start)).count();

            break;

        default:
            cout << "invalid choice\n";
            cout << "BogoSort = 1  BubbleSort = 2  QuickSort = 3\n";
            cin >> algorythm;
            break;
        }
        auto end = std::chrono::high_resolution_clock::now();
        Print(list);
        std::cout << "Time taken" << std::chrono::duration_cast<std::chrono::milliseconds>((end)-(start)).count() << " ms" << std::endl;

        cout << "Continue? Yes = 1 No = any other number\n";
        cin >> continue1;
        if (continue1 == 1)
        {
            list.clear();
            Running = true;
            Bogo = false;
        }
        else
            Running = false;
    }


}

