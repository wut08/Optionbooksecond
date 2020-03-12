#include <iostream>

using namespace std;


#include "GenericOption.h"
using std::cout;
using std::endl;
GenericOption::GenericOption(double strike, OptionType type, double cost)
: m_strike(strike),
  m_type(type),
  m_cost(cost)
{

}
GenericOption::GenericOption(const GenericOption &p)
:m_strike(p.m_strike),
  m_type(p.m_type),
  m_cost(p.m_cost)
{

}
GenericOption::~GenericOption()
{
}
GenericOption &GenericOption::operator=(const GenericOption &p)
{
    if(this !=&p)
    {
        m_type=p.m_type;
        m_strike=p.m_strike;
        m_cost=p.m_cost;
    }
    return *this;
}
double GenericOption::valueAtExpiration(double underlyingAtExpiration)
{
    double value=0.0;
    if (m_type==OptionType_Call)
    {
        if (m_strike<underlyingAtExpiration)
        {
            value=underlyingAtExpiration - m_strike;
        }
    }
    else
    {
        if(m_strike>underlyingAtExpiration)
        {
            value=m_strike - underlyingAtExpiration;
        }
    }
    return value;

}
double GenericOption::profitAtExpiration(double underlyingAtExpiration)
{
    double value=0.0;
    double finalValue=valueAtExpiration(underlyingAtExpiration);
    if(finalValue>m_cost)
    {
        value=finalValue-m_cost;
    }
    return value;
}
int main()
{
    GenericOption option(100.0, OptionType_Put, 1.1);
    double price1=120.0;
    double value=option.valueAtExpiration(price1);
    cout<<"For 100 Put, value at expiration for price"
        <<price1
        <<"is"
        <<value<<endl;
    double price2=85.0;
    value=option.valueAtExpiration(85.0);
    cout<<"For 100 put, value at expiration for price"
        <<price2
        <<"is"
        <<value<<endl;
    auto double limit =120.0;
    for(auto double price=80.0; price<=limit;price+=0.1)
    {
        value=option.profitAtExpiration(price);
        cout<<price<<","<<value<<endl;
    }
    return 0;
}
