#include "FileHandler.h"

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
    std::string word;
    while (mInputFile >> word)
    {
        std::cout << word << '\n';
    }
}

void FileHandler::extractToFile(const std::string &fileName)
{
    mExtractToFile = true;
    mOutputFile = fileName;
}
