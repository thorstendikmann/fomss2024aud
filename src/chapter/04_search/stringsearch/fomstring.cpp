#include <string>
#include <iomanip>

#include "fomstring.h"

namespace fom
{
    namespace AuD
    {
        FomString::FomString(const std::string &val) : str(val)
        {
        }

        const std::string &FomString::getString() const
        {
            return this->str;
        }

        void FomString::set(const std::string &val)
        {
            this->str = val;
        }

        std::size_t FomString::length() const
        {
            return this->str.length();
        }

        std::size_t FomString::find_naive(const std::string &pat) const
        {
            std::cout << "    find_naive [" << pat << "] in " << *this << std::endl;

            // i = iterating through the array => current position in txt
            for (size_t i = 0; i < this->length(); ++i)
            {
                std::cout << "    " << std::setw(3) << i << ": Comparing starting at " << this->str[i] << std::endl;
                size_t j;
                for (j = 0; j < pat.length(); ++j)
                {
                    std::cout << "       " << std::setw(3) << j << ": " << this->str[i + j] << " == " << pat[j] << " ? -> ";
                    if (this->str[i + j] == pat[j])
                    {
                        // match! continue!
                        std::cout << " YES!" << std::endl;
                    }
                    else
                    {
                        std::cout << " no" << std::endl;
                        break; // stop comparing at i, go further.
                    }
                }

                std::cout << "         Final j:" << j << std::endl;
                // when reaching this and j == str.length(), full string found!!
                if (j == pat.length())
                    return i;
            }

            return std::string::npos;
        }

        std::size_t FomString::find_kmp(const std::string &pat) const
        {
            const std::string &txt = this->str; // shortcut, avoiding this->str[]
            std::cout << "    find_kmp [" << pat << "] in " << *this << std::endl;

            // Calculate lps (longest proper prefix)
            LPS lps(pat.size());
            calculateLPS(pat, lps);
            std::cout << "      LPS: " << lps << std::endl;

            int M = pat.length();
            int N = txt.length();

            int i = 0; // index for txt[], this text
            int j = 0; // index for pat[], the search pattern
            // Iterate through txt - as long as match is still possible
            while ((N - i) >= (M - j))
            {
                std::cout << "    i: " << std::setw(3) << i << ": Comparing starting at " << txt[i] << std::endl;
                std::cout << "         j:" << std::setw(3) << j << ": " << txt[i] << " == " << pat[j] << " ? -> ";

                if (pat[j] == txt[i])
                {
                    // matching characters! continue!
                    std::cout << " YES!" << std::endl;
                    j++;
                    i++;
                }
                else
                    std::cout << " no" << std::endl;

                if (j == M) // matching characters is length of pattern?
                {
                    // Pattern found .. return position of first char.
                    std::cout << "       Found pattern at index " << i - j << std::endl;
                    return i - j;
                }

                // We have a mismatch after j matches
                else if (i < N && pat[j] != txt[i])
                {
                    std::cout << "         Mismatch after " << j << " matches: i:" << i << ", j:" << j << " -> " << txt[i] << " == " << pat[j] << std::endl;

                    // Optimization of KMP: do not match lps[0..lps[j-1]] characters - they will match anyway!
                    if (j != 0)
                    {
                        // Unlike naive algorithm, lps tells us which are next chars to be matched!
                        std::cout << "         Moving j from " << j << " to " << lps[j - 1] << " | lps[" << j - 1 << "]: " << lps[j - 1] << std::endl;
                        j = lps[j - 1];
                    }
                    else
                    {
                        // No match, now increment to the next char in our txt
                        std::cout << "         inc i to " << i + 1 << std::endl;
                        i = i + 1;
                    }
                }
            }

            return std::string::npos; // nothing found.
        }

        void FomString::calculateLPS(const std::string &str, LPS &lps) const
        {
            // length of the previous longest prefix suffix
            std::size_t len = 0;

            lps[0] = 0; // lps[0] is always 0

            // calculates lps[i] for i = 1 to (str.size())-1
            std::size_t i = 1;
            while (i < str.size())
            {
                // Found character again?
                if (str[i] == str[len])
                {
                    len++; // prefix has more than one char
                    lps[i] = len;
                    i++;
                }
                else
                {
                    // Did prefix have more than one character before missmatch?
                    if (len != 0)
                    {
                        // Yes, let's finish it then.
                        len = lps[len - 1];
                        // ... and don't increment i!
                    }
                    else // if (len == 0)
                    {
                        lps[i] = 0; // No prefix char, continue
                        i++;
                    }
                }
            }
        }

        std::size_t FomString::find_horspool(const std::string &pat) const
        {
            std::cout << "    find_horspool [" << pat << "] in " << *this << std::endl;
            const std::string &text = this->str; // shortcut

            // Calculate ShiftTable
            ShiftTable shiftTable;
            this->calculateShiftTable(pat, shiftTable);
            std::cout << "    shiftTable: " << shiftTable << std::endl;

            std::cout << "      Iterating string" << std::endl;
            // Index that we shift in text to find the substring
            std::size_t i = (pat.size() - 1);
            while (i < text.size())
            {
                std::cout << "        i: " << i << std::endl;
                std::size_t j = i, k = 0;
                bool flag = true;

                // start at the end of the pattern ... until flag indicates we have a missmatch
                for (std::size_t z = (pat.size() - 1); flag; z--)
                {
                    std::cout << "          z: " << z << " -> text[" << j << "] == pat[" << z << "] => " << text[j] << " == " << pat[z] << std::endl;
                    // Checking if all characters of substring are equal with all characters of string
                    if (text[j] == pat[z])
                    {
                        k++; // inc count of matches
                        j--; // "next" pattern character, run from last to first
                    }
                    else
                    {
                        // missmatch, break out of the for-loop
                        flag = false;
                    }

                    if (z == 0)
                        break;
                }

                if (k == pat.size())
                {
                    // all characters match, return first position
                    return (i - k) + 1;
                }
                else
                {
                    // Does shiftTable contain current character?
                    if (shiftTable.find(text[i]) != shiftTable.end())
                    {
                        std::cout << "          " << text[i] << "      in shiftTable -> shifting i by " << shiftTable[text[i]] << ": " << i << " -> " << i + shiftTable[text[i]] << std::endl;
                        i += shiftTable[text[i]];
                    }
                    else
                    {
                        // Not in shiftTable. Shift by size of pattern, because this cannot match
                        std::cout << "           " << text[i] << " not in shiftTable -> shifting i by " << pat.size() << ": " << i << " -> " << i + pat.size() << std::endl;
                        i += pat.size();
                    }
                }
            }

            return std::string::npos; // nothing found.
        }

        void FomString::calculateShiftTable(const std::string &pat, ShiftTable &shiftTable) const
        {
            std::cout << "      building shift table for: " << pat << std::endl;
            // For all characters in search pattern
            for (std::size_t i = 0; i < pat.size(); i++)
            {
                std::cout << "        i: " << i << " - checking: pat[" << i << "] " << pat[i] << " -> ";
                // Already in shiftTable?
                if (shiftTable.find(pat[i]) == shiftTable.end())
                {
                    // char pat[i] not yet in shifTable!
                    std::cout << "new for shiftTable" << std::endl;

                    if (i != pat.size() - 1)
                    {
                        // Insert the character as key and the size of prototype string - index of character - 1 as value
                        std::cout << "          Inserting shiftTable[" << pat[i] << "] to " << pat.size() - i - 1 << std::endl;
                        shiftTable.insert(std::make_pair(pat[i], pat.size() - i - 1));
                    }
                    else
                    {
                        // Insert the character as key and the size of prototype string as value
                        std::cout << "          Inserting shiftTable[" << pat[i] << "] to " << pat.size() << std::endl;
                        shiftTable.insert(std::make_pair(pat[i], pat.size()));
                    }
                }
                else
                {
                    std::cout << "already in shiftTable." << std::endl;
                    if (i != pat.size() - 1)
                    {
                        std::cout << "          Updating  shiftTable[" << pat[i] << "] to " << pat.size() - i - 1 << std::endl;
                        shiftTable[pat[i]] = pat.size() - i - 1;
                    }
                }
            }

            std::cout << "        Adding '*' for non existing chars (for demo only)  * -> " << pat.size() << std::endl;
            shiftTable.insert(std::make_pair('*', pat.size()));
        }
    }
}

std::ostream &operator<<(std::ostream &os, const fom::AuD::FomString &o)
{
    os << o.getString();
    return os;
}

std::ostream &operator<<(std::ostream &os, const fom::AuD::LPS &o)
{
    os << "[";
    for (fom::AuD::LPS::const_iterator it = o.begin(); it != o.end(); ++it)
    {
        os << *it << ", ";
    }
    os << "]";
    return os;
}

std::ostream &operator<<(std::ostream &os, const fom::AuD::ShiftTable &o)
{
    os << "[";
    for (fom::AuD::ShiftTable::const_iterator it = o.begin(); it != o.end(); ++it)
    {
        os << it->first << ": " << it->second << " | ";
    }
    os << "]";
    return os;
}