#ifndef FOM_STRING_H
#define FOM_STRING_H

#include <string>
#include <iostream>
#include <vector>
#include <map>

namespace fom
{
    namespace AuD
    {
        /** "LPS array" - Helper within KMP algorithm. */
        typedef std::vector<unsigned int> LPS;
        /** "Shift table" - Helper within Boyer-Moore-Horspool algorithm. */
        typedef std::map<char, unsigned int> ShiftTable;

        /**
         * String implementation for demonstrating searching in strings.
         */
        class FomString
        {
        private:
            /** Internal storage: str. */
            std::string str;

        public:
            /**
             * Constructor, initialize string.
             * @param val String zur internen Speicherung.
             */
            explicit FomString(const std::string &val);

            /**
             * @return internal string as reference.
             */
            const std::string &getString() const;

            /**
             * Set new internal string.
             * @param val New value for internal string.
             */
            void set(const std::string &val);

            /**
             * Returns the length of the string.
             * @return length of characters.
             */
            std::size_t length() const;

            /**
             * Searching for given <em>str</em> in this instance.
             *
             * This search algorithm follows a "brute force" naive approach:
             * Search every char in this string for the first occurrence of the first char of str.
             * If this matches, match this[n+1] == str[n+1] and continue for all chars in str.
             *
             * @param str search for this string within current instance.
             * @return The position of the first character of the first match.
             * If no matches were found, the function returns std::string::npos.
             */
            std::size_t find_naive(const std::string &str) const;

            /**
             * Find a substring in this instance following the Knuth-Morris-Pratt algorithm.
             *
             * Following the implementation on
             * https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/
             *
             * @param pat search for this string within current instance.
             * @return The position of the first character of the first match.
             * If no matches were found, the function returns std::string::npos.
             */
            std::size_t find_kmp(const std::string &pat) const;

            /**
             * Find a substring in this instance following the Boyer–Moore–Horspool algorithm.
             *
             * Following the implementation on
             * https://github.com/TheAlgorithms/C-Plus-Plus/blob/master/strings/horspool.cpp
             *
             * @param pat search for this string within current instance.
             * @return The position of the first character of the first match.
             * If no matches were found, the function returns std::string::npos.
             */
            std::size_t find_horspool(const std::string &pat) const;

        protected:
            /**
             * Helper function to calculate lps array (longest proper prefix)
             * as needed in find_kmp().
             * @param str search string.
             * @param lps reference to lps instance to be filled (reference parameter avoids copy on return!).
             */
            void calculateLPS(const std::string &str, LPS &lps) const;

            /**
             * Helper function to calculate shift table for Boyer-Moore-Horspool algorithm
             * as needed in find_horspool().
             * @param str search string.
             * @param shiftTable reference to st instance to be filled (reference parameter avoids copy on return!).
             */
            void calculateShiftTable(const std::string &str, ShiftTable &shiftTable) const;
        };
    }
}

/**
 * Output operator for fom::AuD::FomString.
 * @param os Destination output stream, usually std::cout.
 * @param o a reference to the instance to be transformed onto output stream.
 */
std::ostream &operator<<(std::ostream &os, const fom::AuD::FomString &o);

/**
 * Output operator for fom::AuD::LPS.
 * @param os Destination output stream, usually std::cout.
 * @param o a reference to the instance to be transformed onto output stream.
 */
std::ostream &operator<<(std::ostream &os, const fom::AuD::LPS &o);

/**
 * Output operator for fom::AuD::ShiftTable.
 * @param os Destination output stream, usually std::cout.
 * @param o a reference to the instance to be transformed onto output stream.
 */
std::ostream &operator<<(std::ostream &os, const fom::AuD::ShiftTable &o);

#endif // FOM_STRING_H