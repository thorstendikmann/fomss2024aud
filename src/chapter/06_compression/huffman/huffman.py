import graphviz
import heapq
import logging
from decimal import Decimal
logger = logging.getLogger("huffman")


class HuffmanHeapNode:
    """A node in the Huffman tree build for generating the encode/decode dictionary.
    Also used in decode process.
    """

    # Static var for the indicator going "left" in the tree
    _codeLeft = "1"
    # Static var for the indicator going "right" in the tree
    _codeRight = "0"

    def __init__(self, char: str, freq: float):
        """Initializer for node.

        Args:
            char (str): the (to be encoded) character to be stored in this node.
            freq (float): the frequency how often this character occured in the to be encoded text.
        """

        # the (to be encoded) character to be stored in this node.
        self.char = char
        # the frequency how often this character occured in the to be encoded text.
        self.freq = freq
        # left child node
        self.left = None
        # right child node
        self.right = None

    def __lt__(self, other: object) -> bool:
        """Implementing "less than" operator.

        Args:
            other (object): comparison object

        Returns:
            bool: True if this object's frequency is smaller than other's.
        """
        return self.freq < other.freq

    def __eq__(self, other: object) -> bool:
        """Equality operator.

        Args:
            other (object): comparison object

        Returns:
            bool: True if this object's frequency is identical to other object's frequency.
        """
        if (other == None):
            return False
        if (not isinstance(other, HuffmanHeapNode)):
            return False
        return self.freq == other.freq

    def __str__(self) -> str:
        """String representation of this node.

        Returns:
            str: String in form <em>[char]: [freq]</em>
        """
        return f"{self.char}: {self.freq:.2f}"
        # return f"{self.char}: {Decimal(self.freq)}"

    def __repr__(self) -> str:
        """String representation of this node.

        Returns:
            str: see __str__()
        """
        return self.__str__()

    def to_graphviz(self, dot: graphviz.Graph):
        """Fills a graphviz object recursively with this and its child notes.

        Args:
            dot (graphviz.Graph): Graph object to be filled with current node, 
            child node and their edges.
        """
        dot.node(self.char, str(self), style="filled",
                 fillcolor="#BFE5E2", color="#00998A")

        if (self.left != None):
            self.left.to_graphviz(dot)
            dot.edge(self.char, (self.left).char, self._codeLeft)
        if (self.right != None):
            self.right.to_graphviz(dot)
            dot.edge(self.char, (self.right).char, self._codeRight)

    def to_codetable(self, currentPrefix: str, codetable: dict[str, str]):
        """Generate a code table (recursively) starting from the given tree node.

        Args:
            currentPrefix (str): indicator for where we are in the tree, e.g. "001" 
            -> we have already passed three nodes before
            codetable (dict[str, str]): the code table to be filled.
            Example: <tt>{"A": "001", "B": "1", "C": "01"  ...}</tt>
        """

        # we only consider single "char"s, no merged codes.
        if (len(self.char) == 1):
            codetable[self.char] = currentPrefix

        # recursive calls
        if (self.left != None):
            self.left.to_codetable(
                currentPrefix + self._codeLeft, codetable)
        if (self.right != None):
            self.right.to_codetable(
                currentPrefix + self._codeRight, codetable)


def _relative_frequency(data: str, absoluteValues: bool = False) -> dict[str, float]:
    """Calculate the occurrences of each char in the data. Kind of a "histogram" in form of a dict.

    Args:
        data (str): "raw" input data.
        absoluteValues (bool, optional): Use absolute values instead of relative occurrences. Defaults to False.

    Returns:
        dict[str, float]: Example: <tt>{"A": 0.34, "B": 0.16, "C": 0.5}</tt> when absoluteValues = False.
    """

    # Counting occurrence of each char
    countingDict = dict()
    for char in data:
        if char in countingDict:
            countingDict[char] += 1
        else:
            countingDict[char] = 1

    logger.debug(
        f"Char occurrence: {sorted(countingDict.items(), key=lambda x:x[1])}")

    # Calculating the relative occurence of each char
    if (not absoluteValues):
        resultDict = dict()
        totalChars = len(data)
        for char, count in countingDict.items():
            resultDict[char] = countingDict[char] / totalChars
        return resultDict
    else:
        return countingDict


def _make_heap(relativeFreqDict: dict[str, float]) -> list[HuffmanHeapNode]:
    """Create a min heap list according to the given frequencies of all input chars.

    Args:
        relativeFreqDict (dict[str, float]): Frequencies for each character, calculated by _relative_frequency().

    Returns:
        list[HuffmanHeapNode]: a min-heap sorted list of nodes.
    """
    heap = []  # list we utilize for heapq

    for key in relativeFreqDict:
        node = HuffmanHeapNode(key, float(relativeFreqDict[key]))
        heapq.heappush(heap, node)

    return heap


def _merge_nodes(heap: list[HuffmanHeapNode]) -> HuffmanHeapNode:
    """Merge individual nodes into Huffman tree.

    Args:
        heap (list[HuffmanHeapNode]): min-heap sorted list of nodes as generated by _make_heap()

    Returns:
        HuffmanHeapNode: the root node of the "Huffman tree".
    """
    # work on a shallow copy
    heapCopy = heap.copy()
    # while we have elements available ...
    while (len(heapCopy) > 1):
        # ... take the two char-nodes with the minimal frequency [can be also a node from a merge before]
        node1 = heapq.heappop(heapCopy)
        node2 = heapq.heappop(heapCopy)

        # merges is a new node, sum up the frequencies as frequency of this new one
        merged = HuffmanHeapNode(
            node1.char+node2.char, node1.freq + node2.freq)

        # the new now is the parent of the existing
        merged.left = node1
        merged.right = node2
        logger.debug(f"  merging nodes: {node1}, {node2} -> {merged}")

        # add the new merged node to the min-heap
        heapq.heappush(heapCopy, merged)
    return heapCopy[0]


def huffman_encode(data: str, absoluteValues=False) -> tuple[str, HuffmanHeapNode]:
    """Encode given data with the Huffman code.

    Procedure:
    - Calculate (relative) frequencies / occurrences of each char in input data.
    - Create all nodes and store them in a min-heap (= priority queue) sorted by their frequencies
    - Merge all heaps into a "Huffman tree"
    - Create a code table from the "Huffman tree"
    - Encode each char according to the code table

    Args:
        data (str): the raw data.
        absoluteValues (bool, optional): set to True if frequencies should be considered by 
        absolute values instead of relative frequencies. Defaults to False.

    Returns:
        tuple[str, HuffmanHeapNode]: Tuple with encoded string and the root node for the "Huffman tree"
        which can be used for decoding.
    """
    # Calculate (relative) frequencies / occurrences of each char in input data.
    relativeFreqDict = _relative_frequency(data, absoluteValues)
    logger.debug(f"relativeFreqDict: {relativeFreqDict}")

    # Create all nodes and store them in a min-heap (= priority queue) sorted by their frequencies
    heap = _make_heap(relativeFreqDict)
    logger.debug(f"heap: {heap}")

    # Merge all heaps into a "Huffman tree"
    merged_heapnode = _merge_nodes(heap)
    logger.debug(f"merged_heapnode: {merged_heapnode}")

    # Debug output as graphviz
    G = graphviz.Graph()
    merged_heapnode.to_graphviz(G)
    logger.debug(G)

    # Create a code table from the "Huffman tree"
    codetable = dict()
    merged_heapnode.to_codetable("", codetable)
    logger.debug(f"codetable: {codetable}")

    # Encode each char according to the code table
    encoded_data = ""
    for char in data:
        # add space for better readability
        encoded_data += codetable[char] + " "

    return (encoded_data, merged_heapnode)


def huffman_decode(encoded_data: str, heap_node: HuffmanHeapNode) -> str:
    """Decode given encoded data accoding to a "Huffman code".

    Procedure:
    - For each char:
      - Follow the path in the given "Huffman tree" according to the char:
        go to left or right child node.
      - Once a child node is reached, add char of child node to decoded output,
        reset node and start at root node.

    Args:
        encoded_data (str): the encoded data.
        heap_node (HuffmanHeapNode): the root node of the "Huffman tree"
        as returned from huffman_encode().

    Returns:
        str: decoded string.
    """
    logger.debug(f"huffman_decode: {encoded_data}")
    # clear any remaining spaces we had for better readability
    encoded_data = encoded_data.replace(" ", "")

    decoded_data = ""

    # start with root node of "Huffman tree"
    currentNode = heap_node
    # for each char of encoded string ...
    for char in encoded_data:
        logger.debug(
            f"  char: {char} | current node: {currentNode}     -- left: {currentNode.left} | right: {currentNode.right}")
        # check if we need to continue to the left or right, based on the current char
        if (char == HuffmanHeapNode._codeLeft):
            logger.debug(f"    going left: {currentNode.left}")
            currentNode = currentNode.left
            pass
        if (char == HuffmanHeapNode._codeRight):
            logger.debug(f"    going right: {currentNode.right}")
            currentNode = currentNode.right
            pass

        # Did we reach a leaf?
        if (currentNode.left == None or currentNode.right == None):
            logger.debug(f"    leaf reached: {currentNode.char}")
            # add char of leaf node to decoded data
            decoded_data += currentNode.char
            # reset current node back to root node of "Huffman tree"
            currentNode = heap_node

    return decoded_data


if __name__ == "__main__":
    string = "AABABCABCD"
    encoded_str, heap_node = huffman_encode(string)
    decoded_str = huffman_decode(encoded_str, heap_node)

    print(f"Original string : {string}")
    print(f"Encoded string  : {encoded_str}")
    print(f"Decoded string  : {decoded_str}")
