#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<queue>
#include<map>

using namespace std;

int main()
{
    map<string, int>aux;
    map<string, int> myMap;
    auto comp = [&](const string& a, const string& b) -> bool {
        if (myMap[a] == myMap[b])
            return a > b;
        else
            return myMap[a] < myMap[b];
    };
    auto comp2 = [&](const string& a, const string& b) -> bool {
        return a.size() < b.size();
    };
    priority_queue<string, vector<string>, decltype(comp)> myQueue(comp);
    priority_queue<string, vector<string>, decltype(comp2)> myQueue2(comp2);
    string input;
    getline(cin, input);
    for (int i = 0; i <= input.length(); ++i)
        if (input[i] >= 'A' && input[i] <= 'Z')
            input[i] = input[i] - 'A' + 'a';
    istringstream iss(input);
    int i = 0;
    while (iss)
    {
        string word;

        char delimiter = NULL;
        for (; i <= input.size() && delimiter == NULL; i++)
            if (input[i] == ' ')
                delimiter = ' ';
            else if (input[i] == '!')
                delimiter = '!';
            else if (input[i] == '?')
                delimiter == '?';
            else if (input[i] == '.')
                delimiter = '.';
            else if (input[i] == ',')
                delimiter = ',';

        getline(iss, word, delimiter);
        int count = 0;
        int pos = input.find(word, 0);
        ///fol un map pt numaratoare
        while (pos != string::npos)
        {
            if (pos < input.length() && (input[pos - 1] < 'a' || input[pos - 1] > 'z'))
                ++count;
            pos = input.find(word, pos + 1);
        }
        if (word.size() != 0)
        {
            myMap[word] = count;
            aux[word] = count;
            myQueue.push(word);
            myQueue2.push(word);
        }
    }
    while (!myQueue.empty())
    {
        if (myMap[myQueue.top()] != -112)
            cout << myQueue.top() << " => " << myMap[myQueue.top()] << '\n';
        myMap[myQueue.top()] = -112;
        myQueue.pop();
    }
    cout << "\n---------------------------------------------------------------\n";
    while (!myQueue2.empty())
    {
        if (aux[myQueue2.top()] != -112)
            cout << myQueue2.top() << " => " << aux[myQueue2.top()] << '\n';
        aux[myQueue2.top()] = -112;
        myQueue2.pop();
    }

    return 0;
}

