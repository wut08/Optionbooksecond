#ifndef _CppOptions_GenericOption_
#define _CppOptions_GenericOption_
#include <stdio.h>

enum OptionType{
    OptionType_Call,
    OptionType_Put
};
class GenericOption {
public:
    GenericOption(double strike, OptionType Type, double cost);
    GenericOption(const GenericOption &p);
    ~GenericOption();
    GenericOption &operator=(const GenericOption &p);

    double valueAtExpiration(double underlyingAtExpiration);
    double profitAtExpiration(double underlyingAtExpiration);
private:
    double m_strike;
    OptionType m_type;
    double m_cost;
};
#endif
