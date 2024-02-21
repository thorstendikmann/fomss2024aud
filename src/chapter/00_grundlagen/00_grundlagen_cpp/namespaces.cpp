#include <iostream>
#include <string>
#include <algorithm>

// avoid prefixing std::
using namespace std;

/** Namespace for FOM Developments. */
namespace fom
{
    /** Namespace for developments within "Algorithm and Data Structures". */
    namespace AuD
    {
        /** Class in a given namespace. */
        class FomCppClass
        {
        public:
            /** Static member class demonstration. Just prints some text. */
            static void printAString()
            {
                std::cout << "Some string ...in a namespace" << std::endl;
            }
        };
    }
}

/** Utilizes namespaces.  */
void someNamespaceClass()
{
    // Calls the static function in the FomCppClass class inside the fom::AuD namespace
    fom::AuD::FomCppClass::printAString();
}

/** Demonstration of std namespace.  */
void somestrings()
{
    string greeting = "Hello World";
    cout << greeting << endl;
}

int main()
{
    somestrings();
    someNamespaceClass();
    return 0;
}
