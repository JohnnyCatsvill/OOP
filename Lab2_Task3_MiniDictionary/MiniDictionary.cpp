#include "MiniDictionary.h"
using namespace std;

int WriteMap(const string& filePosition, const map<string, string>& dict) 
{
    fstream file;

    if (!filePosition.empty())
    {
        file.open(filePosition, ios::out);
        if (file.is_open())
        {
            for (auto& it : dict)
            {
                file << it.first << "=" << it.second << endl;
            }

            file.close();
            return DICTIONARY_OPENED;
        }
        else
        {
            return DICTIONARY_NOT_FOUND;
        }
    }
    else
    {
        return DICTIONARY_UNDEFINED;
    }
}

int ReadMap(const string& filePosition, map<string, string>& dict) 
{    
    fstream file;

    if (!filePosition.empty())
    {
        file.open(filePosition, ios::in);
        if (file.is_open())
        {
            string first;
            string second;
            string line;

            while (getline(file, line))
            {
                stringstream ss(line);
                getline(ss, first, '=');
                getline(ss, second);
                dict.insert(make_pair(first, second));
            }

            file.close();
            return DICTIONARY_OPENED;
        }
        else
        {
            return DICTIONARY_NOT_FOUND;
        }
    }
    else
    {
        return DICTIONARY_UNDEFINED;
    }
}

int GetTranslation(const string& word, string& translation, map<string, string>& dict)
{
    string wordCopy = word;
    transform(wordCopy.begin(), wordCopy.end(), wordCopy.begin(), std::tolower);
    auto translateElem = dict.find(wordCopy);
    if (translateElem != dict.end())
    {
        translation = translateElem->second;
        return TRANSLATION_WAS_FOUND;
    }
    else
    {
        return NO_TRANSLATION_FOUND;
    }
}

int AddTranslation(const string& word, const string& translation, map<string, string>& dict)
{
    string wordCopy = word;
    transform(wordCopy.begin(), wordCopy.end(), wordCopy.begin(), std::tolower);
    if (!translation.empty())
    {
        dict.emplace(make_pair(wordCopy, translation));
        return TRANSLATION_WAS_ADDED;
    }
    else
    {
        return TRANSLATION_WAS_NOT_ADDED;
    }
}

bool AskToSaveChanges(istream& in, ostream& out)
{
    out << "В словарь были внесены изменения. Введите Y или y для сохранения перед выходом.\n> ";
   
    string answer;
    getline(in, answer);

    if (answer == "y" || answer == "Y")
    {
        return true;
    }
    else
    {
        out << "Вы отменили сохранение словаря. До свидания.\n";
        return false;
    }
}

int GetLineFromStream(istream& in, string& line)
{
    string newLine;
    std::getline(in, newLine);
    if (newLine.empty())
    {
        return LINE_EMPTY;
    }
    else
    {
        line = newLine;
        return LINE_GIVEN;
    }
}

void MiniDictionary(istream& in, ostream& out)
{
    map<string, string> dictionary;
    bool isDictionaryHaveFile = false;
    bool isDictionaryChanged = false;
    string line;
    string filePosition;

    out << "Введите файл словаря\n> ";
    if (GetLineFromStream(in, line) == LINE_GIVEN)
    {
        filePosition = line;
        if (ReadMap(filePosition, dictionary) == DICTIONARY_OPENED)
        {
            isDictionaryHaveFile = true;
            out << "Словарь был открыт\n";
        }
        else
        {
            out << "Словарь не удалось открыть\n";
        }
    }
    else
    {
        out << "Словарь не задан\n";
    }

    out << "Вводите слова построчно для перевода\n> ";
  
    string word;
    string translation;
    while (std::getline(in, word))
    {
        if (word.empty())
        {
            out << "> ";
            continue;
        }
        else if (word == "...")
        {
            break;
        }
        else
        {
            if (GetTranslation(word, translation, dictionary) == TRANSLATION_WAS_FOUND)
            {
                out << translation << endl;
            }
            else
            {
                out << "Неизвестное слово “" << word << "”. Введите перевод или пустую строку для отказа.\n> ";
                if (GetLineFromStream(in, line) == LINE_GIVEN)
                {
                    AddTranslation(word, line, dictionary);
                    isDictionaryChanged = true;
                    out << " Слово “" << word << "” сохранено в словаре как “" << line << "”." << endl;
                }
                else
                {
                    out << " Слово “" << line << "” проигнорированно." << endl;
                }
            }
        }
        out << "> ";
    }

    if (isDictionaryChanged && AskToSaveChanges(in, out))
    {
        if (!isDictionaryHaveFile)
        {
            out << "Введите название файла для сохранения словаря\n> ";
            if (GetLineFromStream(in, line) == LINE_GIVEN)
            {
                filePosition = line;
                isDictionaryHaveFile = true;
            }
        }
        if (isDictionaryHaveFile && WriteMap(filePosition, dictionary) == DICTIONARY_OPENED)
        {
            out << "Изменения сохранены. До свидания.\n";
        }
        else
        {
            out << "Словарь не удалось открыть, сохранение отменено. До свидания.\n";
        }
    }
}
