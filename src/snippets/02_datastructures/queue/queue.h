#ifndef QUEUE_H
#define QUEUE_H

struct LinkedList;

namespace fom
{
    namespace AuD
    {
        /**
         * Queue implementation based on LinkedList.
         */
        class Queue
        {
        public:
            /** Default constructor. */
            Queue();
            /** Destructor, free's resources. */
            ~Queue();

            /**
             * Pushes an element to the Queue.
             *
             * @param element the new element.
             */
            void enqueue(const char element);

            /**
             * Returns the top element from the Queue
             * (and deletes it from the Queue).
             *
             * @return the top element.
             */
            char dequeue();

            /**
             * Helper to output a Queue.
             *
             * @return a String representation of the contents.
             */
            const std::string toString();

        private:
            LinkedList *l;
        };
    }
}

#endif // QUEUE_H