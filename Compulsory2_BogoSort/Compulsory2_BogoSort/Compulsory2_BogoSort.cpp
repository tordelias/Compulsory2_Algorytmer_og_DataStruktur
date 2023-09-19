#include <iostream>
#include <list>
#include <algorithm>
#include <random>

using namespace std;
int ListSize = 0;
int maxruntime = 0;

void BogoSort(list<int>& l);
bool isSorted(list<int> list);

/// <summary>
/// Prints the list
/// </summary>
/// <returns></returns>
void Print(list<int>& l)
{
    cout << "ListSize " << ListSize << "\n";
    if (isSorted(l) == false)
    {
        cout << "not Sorted\n";
    }
    else
    {
        cout << "Sorted\n";
    }
    while (!l.empty() or l.size() > 0)
    {
        cout << l.front() << "\n";
        l.pop_front();
    }
    cout << "iterations " << maxruntime << "\n";
}



/// <summary>
/// Checks if the list is sorted 
/// </summary>
/// <param name="list"></param>
/// <returns></returns>
bool isSorted(list<int> list) {
   
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
/// Randomises the numbers in the list and their position 
/// did not need to have it's own void 
/// </summary>
/// <param name="l"></param>
void shuffleList(list<int>& l)
{
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
    //BogoSort(shuffledList);
    l.swap(shuffledList);

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
    else{
        while (!isSorted(l) && maxruntime < 1000000)
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

int main()
{
    ListSize = 10;

    list<int> mL;
    srand(time(NULL));
    for (int i = 0; i < ListSize; i++)
    {
        mL.push_back(rand() % 10000 + 1);
    }
    BogoSort(mL);
    Print(mL);

}