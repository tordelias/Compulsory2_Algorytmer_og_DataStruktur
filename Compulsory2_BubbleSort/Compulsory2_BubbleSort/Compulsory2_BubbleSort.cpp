#include <iostream>
#include <list>
#include <algorithm>
#include <chrono>


using namespace std;
bool isSorted(const list<int> list);

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

    //if (!isSorted)
    //{
    //    cout << " not sorted\n";
    //}
    //else
    //{
    //    cout << "sorted\n";
    //}


}

/// <summary>
/// Checks if the list is sorted 
/// </summary>
/// <param name="list"></param>
/// <returns></returns>
bool isSorted(const list<int> list)
{
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

void sort(list<int>& l, list<int>::iterator current, list<int>::iterator next)
{
    if (next == l.end())
        return;
    if (*current > *next)
    {
        iter_swap(current, next);
    }
    sort(l, current, next);
}

 
void BubleSort(list<int>& list)
{
    //if (isSorted(list))
    //    return;
    //sort(list, list.begin(), std::next(list.begin()));
    //BubleSort(list);
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

int main()
{
    int listSize = 100; // 1393 is the max size bubbleSort can do with recursion 
    list<int> mList;
    srand(time(NULL));
    for (int i = 0; i < listSize; i++)
    {
        mList.push_back(rand() % 10000 + 1);
    }
    auto start = std::chrono::high_resolution_clock::now();
    BubleSort(mList);
    auto end = std::chrono::high_resolution_clock::now();
    Print(mList);
    std::cout << "Time taken " << std::chrono::duration_cast<std::chrono::milliseconds>((end)-(start)).count() << " ms" << std::endl;

}