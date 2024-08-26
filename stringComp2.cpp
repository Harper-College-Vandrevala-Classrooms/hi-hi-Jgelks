#include <iostream>
#include <cctype>
#include <string>
#include <cmath>
#include <vector>
#include <cassert>
using namespace std;

vector<int> compValueFinder(string word, string anotherWord)
{
    vector<int> comparisonValues;
    int howManyLettersToCompare = word.size();
    if (word.size() != anotherWord.size())
    {
        if (word.size() > anotherWord.size())
        {
            howManyLettersToCompare = anotherWord.size();
        }

        cout << "Your strings are not the same size. The first " << howManyLettersToCompare << " characters will be compared." << endl;
    }

    for (int i = 0; i < howManyLettersToCompare; i++)
    {
        cout << "Comparison " << i + 1 << " is " << tolower(word.at(i)) - tolower(anotherWord.at(i)) << endl;
        comparisonValues.push_back(tolower(word.at(i)) - tolower(anotherWord.at(i)));
        if (i == howManyLettersToCompare - 1)
        {
            cout << "Comparison complete." << endl;
        }
    }

    return comparisonValues;
}
vector<int> compValueFinderHidden(string word, string anotherWord)
{
    vector<int> comparisonValues;
    int howManyLettersToCompare = word.size();
    if (word.size() != anotherWord.size())
    {
        if (word.size() > anotherWord.size())
        {
            howManyLettersToCompare = anotherWord.size();
        }
    }

    for (int i = 0; i < howManyLettersToCompare; i++)
    {

        comparisonValues.push_back(tolower(word.at(i)) - tolower(anotherWord.at(i)));
    }

    return comparisonValues;
}
int assertStatements()
{
    vector<int> test1;
    test1.push_back(1);
    test1.push_back(0);
    test1.push_back(-1);
    assert(test1 == compValueFinderHidden("bbb", "abc"));
    vector<int> test2;
    test2.push_back(0);
    assert(test2 == compValueFinderHidden(" ", " "));
    vector<int> test3;
    test3.push_back(0);
    test3.push_back(-1);
    test3.push_back(-2);
    assert(test3 == compValueFinderHidden("aaa", "abcd"));
    vector<int> test4;
    test4.push_back(-33);
    test4.push_back(-63);
    test4.push_back(-63);
    assert(test4 == compValueFinderHidden("@#$", "abc"));
    vector<int> test5;
    test5.push_back(-1);
    test5.push_back(0);
    test5.push_back(1);
    assert(test5 == compValueFinderHidden("abc", "bbb"));
    vector<int> test6;
    test6.push_back(-33);
    test6.push_back(-63);
    test6.push_back(-63);
    assert(test4 == compValueFinderHidden("@#$", "abcd"));
    return 0;
}
int main()
{
    string firstWord;
    string secondWord;

    cout << "What is your first word?\n";
    getline(cin, firstWord);
    cout << "What is your second word?\n";
    getline(cin, secondWord);

    compValueFinder(firstWord, secondWord);
    assertStatements();
    return 0;
}