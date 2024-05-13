#include <iostream>
#include <sstream>
#include <string>
#include <list>
#include <stack>
#include <map>

#include "stack/stack.h"

/**
 * Helper function to check if a given string is numeric.
 * Note: This cannot handle negative numbers currently.
 *
 * @param s the string to be checked.
 * @return true if the given string is a numeric value.
 */
bool is_numeric(const std::string &s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it))
        ++it;
    return !s.empty() && it == s.end();
}

/**
 * Helper function to print the contents of the stacks "output" and "operators" to std::cout.
 * 
 * @param output copy (!) of the output stack.
 * @param operators copy (!) of the operators stack.
*/
void printState(std::stack<std::string> output, std::stack<std::string> operators)
{
    std::cout << "  output: ";
    while (!output.empty())
    {
        std::cout << "[" << output.top() << "] ";
        output.pop();
    }
    std::cout << "  | operators: ";
    while (!operators.empty())
    {
        std::cout << "[" << operators.top() << "] ";
        operators.pop();
    }
    std::cout << std::endl;
}

/**
 * Return the precedence of an operator.
 * Useful for relatively comparing the precedence of two operators.
 * 
 * @return a numeric value indicating the precedence of the operator. Higher is higher precedence.
*/
std::size_t get_precedence(const std::string &op)
{
    // hardcode common operators
    std::map<std::string, std::size_t> precedences{{"+", 1}, {"-", 1}, {"*", 2}, {"/", 2}, {"^", 3}};
    return precedences[op];
}

/**
 * Infix to postix converter function.
 * 
 * Dijkstra's Shunting Yard algorithm.
 *   - Parse all tokens of the input string (separated by " ")
 *   - If token is numeric, put numeric token to output stack
 *   - If token is left "(", put it to operator stack
 *   - If token is right ")", look for left "(" and put push all operators to output stack
 *   - Else operator is found. Check for precedence of operator.
 *     While last operator on stack is higher, push last it to output stack
 * 
 * This will print the resulting postfix notation to std::cout.
 * 
 * References:
 *   - [https://en.wikipedia.org/wiki/Shunting_yard_algorithm](Shunting yard algorithm - wikipedia)
 *   - [https://www.youtube.com/watch?v=1VjJe1PeExQ&t=19](The Shunting Yard Algorithm Demystified - youtube)
 * 
 * @param inputStr input in infix notation to be processed.
*/
void infix_to_postfix(std::istringstream &inputStr)
{
    std::cout << "Parsing " << inputStr.str() << std::endl;

    std::stack<std::string> output;
    std::stack<std::string> operators;
    std::string str;

    while (inputStr >> str)
    {
        std::cout << "  processing " << str;
        if (is_numeric(str))
        {
            // put numeric token to output stack
            std::cout << " -> numeric" << std::endl;
            output.push(str);
            printState(output, operators);
        }
        else if (str == "(")
        {
            std::cout << " -> '('" << std::endl;
            operators.push(str);
            printState(output, operators);
        }
        else if (str == ")")
        {
            std::cout << " -> ')'" << std::endl;
            // transfer all args to output until left "(" is reached
            std::cout << "    Looking for left '(' ... " << std::endl;
            std::string c;
            while (!operators.empty() && c != "(")
            {
                c = operators.top();
                std::cout << "      top op: " << c << std::endl;

                operators.pop();
                if (c != "(")
                    output.push(c);
            }
            printState(output, operators);
        }
        else
        {
            std::cout << " -> operator" << std::endl;

            // if not first operator
            if (!operators.empty())
            {
                // Check precedence of operator
                std::string lastOp = operators.top();
                while (!operators.empty() && (get_precedence(lastOp) >= get_precedence(str)))
                {
                    // push higher precedence operators to outpus stack
                    std::cout << "   Last op " << lastOp << " precedence is higher than mine " << str << std::endl;
                    output.push(lastOp);
                    operators.pop();
                    if (!operators.empty())
                        lastOp = operators.top();
                }
            }

            operators.push(str);
            printState(output, operators);
        }
    }

    // transfer remaining operators to output.
    while (!operators.empty())
    {
        std::string c = operators.top();
        output.push(c);
        operators.pop();
    }

    printState(output, operators);

    // print result:
    std::cout << " Postfix result: ";
    std::string s;
    while (!output.empty())
    {
        s = output.top() + " " + s;
        output.pop();
    }
    std::cout << s << std::endl;
}

int main()
{
    // Add some test data
    std::list<std::istringstream> inputs = {};
    inputs.push_back(std::istringstream("3 + 4"));
    inputs.push_back(std::istringstream("1 + 2 * 3"));
    inputs.push_back(std::istringstream("3 + 4 * 2"));
    inputs.push_back(std::istringstream("3 * 4 + 2"));
    inputs.push_back(std::istringstream("( 3 + 4 ) * ( 5 - 6 )"));
    inputs.push_back(std::istringstream("( 3 + 4 ) * 2"));
    inputs.push_back(std::istringstream("( 36 * 12 ) - 144 * 3"));
    inputs.push_back(std::istringstream(" ( ( 36 * 12 ) - ( 144 + 2048 ) ) + 5"));
    // // Negative numbers not yet supported.
    // inputs.push_back(std::istringstream("13 - -3"));

    for (auto it = inputs.begin(); it != inputs.end(); ++it)
    {
        infix_to_postfix(*it);
    }
}
