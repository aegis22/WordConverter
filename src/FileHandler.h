#ifndef FILE_HANDLER
#define FILE_HANDLER

#include <fstream>
#include <string>

#include <memory>

class WordConverter;

class FileHandler
{
public:
    FileHandler();

    ~FileHandler();

    bool openFile(const std::string &fileName);

    void closeFiles();

    void processCurrentFile();

    void extractToFile(const std::string &fileName);

private:
    bool removePunctuationMarks(std::string &word);

    bool mExtractToFile;

    bool mIsADigit;

    std::string mOutputFileName;

    std::ifstream mInputFile;

    std::ofstream mOutputFile;

    std::unique_ptr<WordConverter> mWordConverter;
};

#endif
