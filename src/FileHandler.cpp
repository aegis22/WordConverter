#include "FileHandler.h"

#include <fstream>
#include <iostream>

void FileHandler::readFile(const std::string &fileName)
{
    std::ifstream file;

    file.open(fileName);
    if (!file.is_open())
        return;

    std::string word;
    while (file >> word)
    {
        std::cout << word << '\n';
    }
}
