#include <iostream>
#include <cstring>
#include <string>

void printUseOfProgram()
{
    std::cerr << "Usage: word_converter -i <input_file> [-o output file]\n";
}

void takeArgumentWithCheck(std::string &file, char *argv[], int index, const char *token)
{
    if (strcmp(argv[index], token) == 0)
    {
        file = argv[index + 1];
    }
    else
    {
        printUseOfProgram();
    }
}

void checkAndReadArguments(std::string &inputFilePath, std::string &outputFilePath,
                           int argc, char *argv[])
{
    const int minimumArguments = 3;
    const int maximumArguments = 5;
    const char *iToken = "-i";
    const char *oToken = "-o";

    if (argc == minimumArguments)
    {
        takeArgumentWithCheck(inputFilePath, argv, 1, iToken);
    }
    else if (argc == maximumArguments)
    {
        if (strcmp(argv[1], iToken) == 0)
        {
            inputFilePath = argv[2];
            takeArgumentWithCheck(outputFilePath, argv, 3, oToken);
        }
        else if (strcmp(argv[1], oToken) == 0)
        {
            outputFilePath = argv[2];
            takeArgumentWithCheck(inputFilePath, argv, 3, iToken);
        }
        else
        {
            printUseOfProgram();
        }
    }
    else
    {
        printUseOfProgram();
    }
}

int main(int argc, char *argv[])
{
    std::string inputFilePath, outputFilePath;

    checkAndReadArguments(inputFilePath, outputFilePath, argc, argv);

    if (!inputFilePath.empty())
    {
        if (!outputFilePath.empty())
        {
        }
        else
        {
        }
    }

    return 0;
}
