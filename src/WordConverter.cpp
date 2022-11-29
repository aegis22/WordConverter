#include "WordConverter.h"

#include "DigitsToNumbers.h"

WordConverter::WordConverter()
    : mValueIsReady(false),
      mLastValue(0),
      mAccumulatedValue(0)
{
}

void WordConverter::setReady(bool newValue)
{
    mValueIsReady = newValue;
}

bool WordConverter::valueIsReady()
{
    return mValueIsReady;
}

int WordConverter::getValue()
{
    return mAccumulatedValue;
}

void WordConverter::reset()
{
    mValueIsReady = false;
    mAccumulatedValue = 0;
}

void WordConverter::processWord(const std::string &word)
{
    int value = DigitsToNumbers(word).operator int();

    if (value != -1)
    {
        int valueOrder = magnitudeOrder(value);
        int lastOrder = magnitudeOrder(mLastValue);

        if (mLastValue == 0)
        {
            mLastValue = value;
        }
        else if (valueOrder > lastOrder)
        {
            mAccumulatedValue += (mLastValue * value);
            mLastValue = value;
        }
        else
        {
            mLastValue = value;
        }
    }
    else if (mLastValue != 0 && word != "and" && word != "a")
    {
        mAccumulatedValue += mLastValue;
        mLastValue = 0;
        mValueIsReady = true;
    }
}

int WordConverter::magnitudeOrder(int number)
{
    int counter = 0;

    while (number > 10)
    {
        number = number / 10;
        counter++;
    }

    return counter;
}
