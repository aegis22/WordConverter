#ifndef WORD_CONVERTER
#define WORD_CONVERTER

#include <string>

class WordConverter
{
public:
    WordConverter();

    void setReady(bool newValue);

    bool valueIsReady();

    int getValue();

    void reset();

    void processWord(const std::string &word);

private:
    int magnitudeOrder(int number);

    bool mValueIsReady;

    int mLastValue;

    int mAccumulatedValue;
};

#endif
