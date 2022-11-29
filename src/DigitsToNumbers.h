#ifndef DIGITS_TO_NUMBERS
#define DIGITS_TO_NUMBERS

#include <map>
#include <string>

class DigitsToNumbers
{
public:
    explicit DigitsToNumbers(const std::string &word);

    DigitsToNumbers(int number);

    operator int() const { return mDigit; }

private:
    static int getNumber(const std::string &word);

    static const std::map<std::string, int> &getNumbers();

    const int mDigit;
};

#endif
