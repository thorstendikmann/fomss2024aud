#ifndef STACK_H
#define STACK_H

struct LinkedList;

namespace fom
{
    namespace AuD
    {
        /**
         * Stack implementation based on LinkedList.
         */
        class Stack
        {
        public:
            /** Default constructor. */
            Stack();
            /** Destructor, free's resources. */
            ~Stack();

            /** Copy constructur. Not implemented here. */
            Stack(const Stack&) = delete;
            /** Assignment operator. Not implemented here. */
            Stack& operator=(const Stack& other) = delete;

            /**
             * Pushes an element to the Stack.
             *
             * @param element the new element.
             */
            void push(const char element);

            /**
             * Returns the top element from the Stack
             * (and deletes it from the Stack).
             *
             * @return the top element.
             */
            char pop();

            /**
             * Returns the top element from the Stack
             * (but leaves the Stack "as is").
             *
             * @return the top element.
             */
            char top();

            /**
             * Helper to output a Stack.
             *
             * @return a String representation of the contents.
             */
            const std::string toString();

            /**
             * Convert the Stack to a string in a Graphviz format.
             * @return a string in Graphviz format representing the data inside.
            */
            std::string toGraphviz() const;

        private:
            LinkedList *l;
        };
    }
}

#endif // STACK_H