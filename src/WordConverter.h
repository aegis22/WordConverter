#ifndef WORD_CONVERTER
#define WORD_CONVERTER

#include <string>

class WordConverter
{
public:
    WordConverter();

    bool valueIsReady();

    int getValue();

    void processWord(const std::string &word);

private:
    bool mValueIsReady;

    int mCurrentValue;

    int mAccumulatedValue;
};

#endif
