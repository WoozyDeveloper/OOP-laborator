#include<iostream>
#include<sstream>
#include<string>
#include<queue>
#include<map>

using namespace std;

int main()
{
    string input;
    getline(cin, input);
    map<string, int> myMap;
    istringstream iss(input);
    int i = 0;
    while (iss) {
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
        auto pos = input.find(word, 0);
        while (pos != string::npos)
        {
            ++count;
            pos = input.find(word, pos + 1);
        }
        if (word.size() != 0)
            myMap[word] = count;
    }
    for (const auto& p : myMap) {
        std::cout << "\"" << p.first << "\" : " << p.second << '\n';
    }
    return 0;
}