#ifndef FILE_HANDLER
#define FILE_HANDLER

#include <fstream>
#include <string>

class FileHandler
{
public:
    FileHandler();

    bool openFile(const std::string &fileName);

    void processCurrentFile();

    void extractToFile(const std::string &fileName);

private:
    bool mExtractToFile;

    std::string mOutputFile;

    std::ifstream mInputFile;
};

#endif
