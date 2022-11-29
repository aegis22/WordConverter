#include "FileHandler.h"

#include <algorithm>
#include <iostream>

#include "WordConverter.h"

FileHandler::FileHandler()
    : mExtractToFile(false),
      mWordConverter(std::make_unique<WordConverter>())
{
}

FileHandler::~FileHandler()
{
    closeFiles();
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

void FileHandler::closeFiles()
{
    if (mInputFile.is_open())
    {
        mInputFile.close();
    }

    if (mOutputFile.is_open())
    {
        mOutputFile.close();
    }
}

void FileHandler::processCurrentFile()
{
    if (mExtractToFile)
    {
        mOutputFile.open(mOutputFileName);
        // TODO: Error control
    }

    std::string currentWord;
    while (mInputFile >> currentWord)
    {
        std::string word = currentWord;
        removePunctuationMarks(word);

        std::transform(word.begin(), word.end(), word.begin(),
                       [](unsigned char c)
                       { return std::tolower(c); });

        mWordConverter->processWord(word);

        std::cout << word << ' ';
    }

    closeFiles();
}

void FileHandler::extractToFile(const std::string &fileName)
{
    mExtractToFile = true;
    mOutputFileName = fileName;
}

void FileHandler::removePunctuationMarks(std::string &word)
{
    char last = word.back();
    if (last == '.' || last == ',' || last == ';')
    {
        word.pop_back();
    }
}