#include <iostream>
#include <string>

#include "heap.h"

int main()
{
    typedef fom::AuD::Heap<int> HeapInt;
    // typedef fom::AuD::Heap<int> node;

    HeapInt heap;

    std::cout << "Heap: " << std::endl;
    heap.fromVector({4, 7, 42, 8, 27, 19, 2, 3, 1});

    std::cout << heap << std::endl;
    std::cout << heap.toGraphViz() << std::endl;
    
    std::cout << "   -- Build initial max heap" << std::endl;
	int N = heap.size();
	for (int i = N / 2 - 1; i >= 0; i--)
	{
		heap.heapify(N, i);
        std::cout << "       Heap after i = " << i << ":" << std::endl;
        std::cout << heap << std::endl;
        std::cout << heap.toGraphViz() << std::endl;
	}

	// Heap sort
    std::cout << "     Heap Sort" << std::endl;
	for (int i = N - 1; i >= 0; i--)
	{
        std::cout << "       Swap 0," << i << " [0]=>" << heap.at(0) << " [i]=>" << heap.at(i) << std::endl;
		heap.swap(0, i);
		heap.heapify(i, 0);
        std::cout << "       Heapsort after i = " << i << ":" << std::endl;
        std::cout << heap << std::endl;
	}

    return 0;
}