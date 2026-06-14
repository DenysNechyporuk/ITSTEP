#include <iostream>
#include "dictionary.h"
using namespace std;

void main()
{

    dictionary dict;
    int choice;

    do
    {
        cout << endl;
        cout << "1. Add word" << endl;
        cout << "2. Find word" << endl;
        cout << "3. Add translation" << endl;
        cout << "4. Remove word" << endl;
        cout << "5. Show all words" << endl;
        cout << "6. Save to file" << endl;
        cout << "7. Load from file" << endl;
        cout << "0. Exit" << endl;
        cout << "Choice :: ";
        cin >> choice;

        if (choice == 1)
        {
            string word;
            cout << "Enter word :: ";
            cin >> word;

            int count;
            cout << "Enter number of translations :: ";
            cin >> count;

            vector<string> translations;
            for (int i = 0; i < count; i++)
            {
                string t;
                cout << "Translation " << (i + 1) << " :: ";
                cin >> t;
                translations.push_back(t);
            }

            dict.addWord(word, translations);
        }
        else if (choice == 2)
        {
            string word;
            cout << "Enter word :: ";
            cin >> word;
            dict.findWord(word);
        }
        else if (choice == 3)
        {
            string word, translation;
            cout << "Enter word :: ";
            cin >> word;
            cout << "Enter translation :: ";
            cin >> translation;
            dict.addTranslation(word, translation);
        }
        else if (choice == 4)
        {
            string word;
            cout << "Enter word :: ";
            cin >> word;
            dict.removeWord(word);
        }
        else if (choice == 5)
        {
            dict.showAll();
        }
        else if (choice == 6)
        {
            string filename;
            cout << "Enter filename :: ";
            cin >> filename;
            dict.saveToFile(filename);
        }
        else if (choice == 7)
        {
            string filename;
            cout << "Enter filename :: ";
            cin >> filename;
            dict.loadFromFile(filename);
        }

    } while (choice != 0);
}