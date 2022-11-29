#include "FileHandler.h"

#include <algorithm>
#include <iostream>

FileHandler::FileHandler()
    : mExtractToFile(false)
{
}

bool FileHandler::openFile(const std::string &fileName)
{
    bool result = true;

    mInputFile.open(fileName);
    if (!mInputFile.is_open())
    {
        std::cerr << "Cannot open file " << fileName << "\n";
        result = false;
    }

    return result;
}

void FileHandler::processCurrentFile()
{
    if (mExtractToFile)
    {
    }

    std::string word;
    while (mInputFile >> word)
    {
        removePunctuationMarks(word);

        std::transform(word.begin(), word.end(), word.begin(),
                       [](unsigned char c)
                       { return std::tolower(c); });

        std::cout << word << '\n';
    }
}

void FileHandler::extractToFile(const std::string &fileName)
{
    mExtractToFile = true;
    mOutputFile = fileName;
}

void FileHandler::removePunctuationMarks(std::string &word)
{
    char last = word.back();
    if (last == '.' || last == ',' || last == ';')
    {
        word.pop_back();
    }
}