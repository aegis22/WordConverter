#include "WordConverter.h"

#include "DigitsToNumbers.h"

WordConverter::WordConverter()
    : mValueIsReady(false),
      mCurrentValue(0),
      mAccumulatedValue(0)
{
}

bool WordConverter::valueIsReady()
{
    return mValueIsReady;
}

int WordConverter::getValue()
{
    return mAccumulatedValue;
}

void WordConverter::processWord(const std::string &word)
{
}
