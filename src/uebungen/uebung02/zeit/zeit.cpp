#include <sstream>

#include "zeit.h"

Zeit::Zeit(int st, int mi)
{
    stunde = st;
    minute = mi;
}

int Zeit::getStunde() const
{
    return this->stunde;
}

int Zeit::getMinute() const
{
    return this->minute;
}

void Zeit::set(int st, int mi)
{
    this->stunde = st;
    this->minute = mi;
}

std::string Zeit::toString() const
{
    std::stringstream ss;
    ss << "[" << this->stunde << ":" << this->minute << "]";
    return ss.str();
}

std::ostream &operator<<(std::ostream &os, const Zeit &o)
{
    os << o.toString();
    return os;
}