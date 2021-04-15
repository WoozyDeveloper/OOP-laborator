#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<queue>
#include<map>

using namespace std;

int main()
{
    map<string, int> myMap;
    auto comp = [&](const string& a, const string& b) -> bool {
        if (myMap[a] == myMap[b])
            return a > b;
        else
            return myMap[a] < myMap[b];
    };
    priority_queue<string, vector<string>, decltype(comp)> myQueue(comp);
    string input;
    getline(cin, input);
    for (int i = 0; i <= input.length(); ++i)
        if (input[i] >= 'A' && input[i] <= 'Z')
            input[i] = input[i] - 'A' + 'a';

    map<string, int> aux;
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
        while (pos != string::npos)
        {
            if ((pos < input.length() && input[pos + 1] >= 'a' && input[pos + 1] <= 'z'))
                ++count;
            pos = input.find(word, pos + 1);
        }
        if (word.size() != 0)
        {
            myMap[word] = count;
            myQueue.push(word);
            word = " ";
        }
    }
    while (!myQueue.empty())
    {
        if (myMap[myQueue.top()] != -112)
            cout << myQueue.top() << " => " << myMap[myQueue.top()] << '\n';
        myMap[myQueue.top()] = -112;
        myQueue.pop();
    }

    return 0;
}

