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

void Sort(list<int>& list)
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
}
void BubleSort(list<int>& list)
{
    if (isSorted(list))
    {
        return;
    }
    else
    {
        Sort(list);
        if (isSorted(list))
        {
            return;
        }

        BubleSort(list);
    }
}

int main()
{
    int listSize = 1000;
    list<int> mList;
    srand(time(NULL));
    for (int i = 0; i < listSize; i++)
    {
        mList.push_back(rand() % 10000 + 1);
    }
    BubleSort(mList);
    Print(mList);

}