#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

class dictionary
{
    map<string, vector<string>> words;

public:
    void addWord(const string& word, const vector<string>& translations)
    {
        words[word] = translations;
        cout << "Word added :: " << word << endl;
    }

    void findWord(const string& word) const
    {
        auto it = words.find(word);
        if (it == words.end())
        {
            cout << "Word not found :: " << word << endl;
            return;
        }
        cout << word << " :: ";
        for (int i = 0; i < (int)it->second.size(); i++)
            cout << it->second[i] << " ";
        cout << endl;
    }

    void addTranslation(const string& word, const string& translation)
    {
        auto it = words.find(word);
        if (it == words.end())
        {
            cout << "Word not found :: " << word << endl;
            return;
        }
        it->second.push_back(translation);
        cout << "Translation added :: " << translation << endl;
    }

    void removeWord(const string& word)
    {
        auto it = words.find(word);
        if (it == words.end())
        {
            cout << "Word not found :: " << word << endl;
            return;
        }
        words.erase(it);
        cout << "Word removed :: " << word << endl;
    }

    void showAll() const
    {
        if (words.empty())
        {
            cout << "Dictionary is empty" << endl;
            return;
        }
        for (auto it = words.begin(); it != words.end(); it++)
        {
            cout << it->first << " :: ";
            for (int i = 0; i < (int)it->second.size(); i++)
                cout << it->second[i] << " ";
            cout << endl;
        }
    }

    void saveToFile(const string& filename) const
    {
        ofstream file(filename);
        if (!file)
        {
            cout << "Cannot open file" << endl;
            return;
        }
        for (auto it = words.begin(); it != words.end(); it++)
        {
            file << it->first;
            for (int i = 0; i < (int)it->second.size(); i++)
                file << ";" << it->second[i];
            file << endl;
        }
        file.close();
        cout << "Dictionary saved to :: " << filename << endl;
    }

    void loadFromFile(const string& filename)
    {
        ifstream file(filename);
        if (!file)
        {
            cout << "Cannot open file" << endl;
            return;
        }
        words.clear();
        string line;
        while (getline(file, line))
        {
            vector<string> parts;
            string current = "";
            for (int i = 0; i < (int)line.length(); i++)
            {
                if (line[i] == ';')
                {
                    parts.push_back(current);
                    current = "";
                }
                else
                {
                    current += line[i];
                }
            }
            parts.push_back(current);

            if (parts.size() < 1)
                continue;

            string word = parts[0];
            vector<string> translations;
            for (int i = 1; i < (int)parts.size(); i++)
                translations.push_back(parts[i]);

            words[word] = translations;
        }
        file.close();
        cout << "Dictionary loaded from :: " << filename << endl;
    }
};