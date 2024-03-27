#include <sstream>

#include "strang.h"

Strang::Strang(const std::string& val): str(val)
{
}

std::string Strang::getString() const
{
    return this->str;
}

void Strang::set(const std::string& val)
{
    this->str = val;
}

std::string Strang::toString() const
{
    std::stringstream ss;
    ss << "[" << this->str << "]";
    return ss.str();
}

std::ostream &operator<<(std::ostream &os, const Strang &o)
{
    os << o.toString();
    return os;
}