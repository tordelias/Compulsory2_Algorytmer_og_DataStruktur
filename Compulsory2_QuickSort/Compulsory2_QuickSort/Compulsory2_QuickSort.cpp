

#include <iostream>
#include <list>
#include <algorithm>


using namespace std;
bool isSorted(list<int> list);

/// <summary>
/// Prints the list
/// </summary>
/// <returns></returns>
void Print(list<int>& l)
{
    bool Sorted = false;
    if (!isSorted(l))
    {
        Sorted = false;
    }
    else
    {
        Sorted = true;
    }
    while (!l.empty() or l.size() > 0)
    {
        cout << l.front() << "\n";
        l.pop_front();
    }

    if (!Sorted)
    {
        cout << " not sorted\n";
    }
    else
    {
        cout << "sorted\n";
    }


}

/// <summary>
/// Checks if the list is sorted 
/// </summary>
/// <param name="list"></param>
/// <returns></returns>
bool isSorted(list<int> list) 
{

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
        auto Pivot = list.front();
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
    int listSize = 100000;
    list<int> mList;
    srand(time(NULL));
    for (int i = 0; i < listSize; i++)
    {
        mList.push_back(rand() % 10000 + 1);
    }
    QuickSort(mList);
    Print(mList);

}

