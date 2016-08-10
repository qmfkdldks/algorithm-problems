#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

typedef vector<string> SVector;
typedef map<char, char> Table;

int N;
SVector dic;

bool evaluate(string &dic, string &word, string& result, int index, Table &inTable)
{
    Table table = inTable;
    if(index < word.size())
    {
        char c = table[ word[index] ];

        if(c != '*')
            result.push_back(c);
        else
        {
            char sample = dic[index];
            table[ word[index] ] = sample;
            result.push_back(sample);
        }
        ++index;
        bool isOk = evaluate(dic, word, result, index, table);
        if(isOk)
            inTable = table;
        return isOk;
    }

    if(result == dic)
        return true;
    else
        return false;
}

void decrypt(SVector words, Table t)
{
    stringstream output;

    for(int i = 0; i < words.size(); ++i)
    {
        bool success;
        for(int j = 0; j < dic.size(); ++j)
        {
            if(words[i].size() == dic[j].size())
            {
                string result;
                success = evaluate(dic[j], words[i], result, 0, t);

                if(success)
                {
                    words[i] = result;
                    break;
                }
            }
        }

        if(!success)
            words[i] = string(words[i].size(), '*');

        output << words[i];
        if(i != words.size() - 1)
            output << ' ';
        else
            output << endl;
    }

    cout << output.str();
    output.flush();
    output.clear();
}

int main(void)
{
    string dicStr;

    cin >> N;
    while(--N)
    {
        cin >> dicStr;
        dic.push_back(dicStr);
    }

    getline(cin, dicStr);

    string encryptedStr;
    while(getline(cin, encryptedStr))
    {
        SVector words;
        Table charMap;
        for(char i = 'a'; i < 'z'; ++i)
            charMap.insert(pair<char, char>(i, '*'));
        // To seperate the word by whitespaces.
        stringstream stream;
        stream << encryptedStr;
        string word;
        while(stream >> word)
            words.push_back(word);

        decrypt(words, charMap);
    }
    return 0;
}

