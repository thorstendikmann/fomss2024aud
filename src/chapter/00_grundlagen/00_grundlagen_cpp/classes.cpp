#include <iostream>
#include <string>

/**
 * Just a little demo class.
 */
class MyCppClass
{
public:
    /** Demo for public member num. */
    int num;
    /** Demo for public member str. */
    std::string str;

    /**
     * Member class demonstration. Just prints str.
     */
    void printThatStr()
    {
        std::cout << this->str << std::endl;
    }
};

/**
 * Function to show some class examples.
 */
void handleClass()
{
    MyCppClass myclass;
    myclass.num = 34;
    myclass.str = "Hello from my class!";

    myclass.printThatStr();
}

/**
 * Creating a class instance in heap memory, do something with it and then delete it.
 */
void handleMemory()
{
    MyCppClass* myclass = new MyCppClass();
    myclass->num = 34;
    myclass->str = "Hello from my class in heap memory!";

    myclass->printThatStr();

    delete(myclass);
}

int main()
{
    handleClass();
    handleMemory();
    return 0;
}
