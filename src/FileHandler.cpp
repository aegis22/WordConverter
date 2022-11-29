#include "FileHandler.h"

#include <algorithm>
#include <iostream>

#include "DigitsToNumbers.h"
#include "WordConverter.h"

FileHandler::FileHandler()
    : mExtractToFile(false),
      mIsADigit(false),
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

        mWordConverter->setReady(removePunctuationMarks(word));

        std::transform(word.begin(), word.end(), word.begin(),
                       [](unsigned char c)
                       { return std::tolower(c); });

        int value = DigitsToNumbers(word).operator int();
        if (value != -1)
        {
            mIsADigit = true;
        }

        mWordConverter->processWord(word);

        if (mWordConverter->valueIsReady())
        {
            int number = mWordConverter->getValue();
            mWordConverter->reset();

            std::cout << number << ' ';
            if (mExtractToFile)
            {
                mOutputFile << number << ' ';
            }
            mIsADigit = false;
        }

        if ((value == -1 && word != "a" && word != "and") || (word == "a" && !mIsADigit) || (word == "and" && !mIsADigit))
        {
            std::cout << currentWord << ' ';
            if (mExtractToFile)
            {
                mOutputFile << currentWord << ' ';
            }
        }
    }

    closeFiles();
}

void FileHandler::extractToFile(const std::string &fileName)
{
    mExtractToFile = true;
    mOutputFileName = fileName;
}

bool FileHandler::removePunctuationMarks(std::string &word)
{
    bool removed = false;

    char last = word.back();
    if (last == '.' || last == ',' || last == ';')
    {
        word.pop_back();
        removed = true;
    }

    return removed;
}