#include <iostream>
#include <list>
#include <algorithm>
#include <random>

using namespace std;

int maxruntime = 0;

void BogoSort(list<int>& l);
void Print(list<int>& l)
{
    while (!l.empty() or l.size() > 0)
    {
        cout << l.front() << "\n";
        l.pop_front();
    }
    cout << "iterations " << maxruntime << "\n";
}
/// <summary>
/// Prints the list
/// </summary>
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
            cout << "not Sorted\n";
            return false;
        }
        isSorted(list);
    }
}

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

void BogoSort(list<int>& l)
{
    maxruntime += 1;
    if (isSorted(l) || maxruntime == 1000)
        return;
    else
    {
        //shuffleList(l);
        
        BogoSort(l);
    }


}


int main()
{
    int maxValue = 4;
    list<int> mL;
    srand(time(NULL));
    for (int i = 0; i < maxValue; i++)
    {

        mL.push_back(rand() % 10000 + 1);
    }
    BogoSort(mL);
    Print(mL);
    if (maxruntime == 1000)
    {
        cout << "FailSafe\n";
    }

}