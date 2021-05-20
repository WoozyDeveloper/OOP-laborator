#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "Vector.h"

using namespace std;
int main()
{
    int dim;
    cin >> dim;

    vector<string> v;
    string x;
    for (int i = 0; i < dim; i++)
    {
        cin >> x;
        v.push_back(x);
    }
    auto ex1 = [](string s1, string s2) ->bool
    {
        if (s1.size() < s2.size()) 
            return false;
        else
        {
            if (s1.size() > s2.size()) 
                return true;
            else
            {
                if (s1 < s2) 
                    return false;
                else
                    return true;
            }
        }
    };
    sort(v.begin(), v.end(), ex1);
    for (int i = 0; i < dim; i++)
        cout << v.at(i) << " ";
    int nr[] = { 1,4,3,2,5,3 };
    auto ex2 = [](int numbers[], int dim2) -> int
    {
        int big = INT_MIN;
        for (int i = 0; i < dim2; i++)
            if (numbers[i] > big)
                big = numbers[i];
        return big;
    };
    int biggest_num = ex2(nr,6);
    cout << '\n' << biggest_num << '\n';
    cout << "\n-----------------------------------\n";
    
    Vector vec;
    vec.Add(2);
    vec.Add(54);
    vec.Add(109);
    vec.Add(3);
    vec.Add(6);
    vec.Add(26);
    vec.Print();
    auto lam1 = [](int& nr)
    {
        nr = 123;
    };
    auto lam2 = [](int& nr) ->bool
    {
        if (nr % 2 == 0)
            return true;
        return false;
    };
    vec.Filter(lam2);
    vec.Print();
    vec.Iterate(lam1);
    vec.Print();
}