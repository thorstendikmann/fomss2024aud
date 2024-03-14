#include <iostream>
#include <string>
#include <algorithm>

/**
 * Yiiha - we have strings as type!!
 */
void somestrings()
{
    // Some "Hello World!"
    std::string greeting = "Hello";
    greeting = greeting + " World";
    greeting.append("!");
    std::cout << greeting << " - Length: " << greeting.size() << " chars." << std::endl;

    // The "<<" operators are "overloaded" for adding to a stream.
    // actually, we could call this function
    operator<<(std::cout, "Another hello world\n");

    // Iterators
    for (std::string::const_iterator iter = greeting.begin();
         iter != greeting.end();
         iter++)
    {
        std::cout << *iter << std::endl;
    }

    // "to lowercase" - via std::transform
    // Second begin() is pointing to destination ... which usually is identical to source.
    std::transform(greeting.begin(), greeting.end(), greeting.begin(), tolower);
    std::cout << greeting << std::endl;
}

/**
 * C++ also has bool data types "by default".
 */
void showBool()
{
    bool codingIsFun = true;
    // cppcheck-suppress [knownConditionTrueFalse]
    if (codingIsFun)
    {
        std::cout << "You're so right!" << std::endl;
    }
}

/**
 * An own implementation of a count function.
 *
 * See Stroustrup, §3.8.1 - but differently implemented here.
 * This function internally uses an iterator to iterate over the given std::string s.
 * @param s string to be searched.
 * @param c character to be matched in s.
 */
int count(const std::string &s, char c)
{
    // counter for occurrences of char in string
    int n = 0;

    // iterate over string with iterator.
    std::string::const_iterator i = s.begin();
    while (i != s.end())
    {
        // Dereferencing iterator gives current element.
        if (*i == c)
        {
            n++;
        }
        ++i;
    }
    return n;
}
/**
 * Call count(const std::string &s, char c) with a string and prints result.
 */
void iterators()
{
    std::string s = "Mary had a little lamb";
    int a_count = count(s, 'a');

    std::cout << "String " << s << " has " << a_count << " \"a\"s." << std::endl;
}

#include <stdexcept>
/**
 * Function to demonstrate how to throw and catch exceptions in c++.
 */
void exceptionHandling()
{
    try
    {
        int numerator = 100;

        for (int i = 50; i > -1; i = i - 10)
        {
            int denominator = i;
            float res;

            if (denominator == 0)
            {
                throw std::runtime_error("Division by zero not allowed!");
            }

            // no exception: calculate result
            res = (float)numerator / denominator;
            std::cout << numerator << "/" << denominator << " = " << res << std::endl;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

int main()
{
    somestrings();
    showBool();
    iterators();
    exceptionHandling();
    return 0;
}
