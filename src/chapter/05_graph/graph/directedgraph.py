from __future__ import annotations
from graph.undirectedgraph import Node, Graph

from collections import deque
import networkx as nx
import logging
logger = logging.getLogger(__name__)


class DirectedGraph(Graph):
    """Directed Graph implementation. """

    def add_edge(self, v1: int, v2: int, weight=1):
        """Add an edge between two nodes, given by the <em>index</em> of these nodes in adjacency matrix.

        Args:
            v1 (int): index of the first connecting node.
            v2 (int): index of the second connecting node.
            weight (int, optional): Optional weight of edge. Defaults to 1 == edge exists. Used to label edges in getEdgeLabels().

        Raises:
            ValueError: when v1 == v2, no self-references allowed.
        """
        if v1 == v2:
            raise ValueError(
                f"Graph does not support self-references. {v1}")

        # Only one way! - Difference to undirected graph!
        self.adjMatrix[v1][v2] = weight

    def toNetworkx(self) -> nx.DiGraph:
        """Transforms this graph instance into a DiGraph from the networkx package. Used for visualization.

        This is identical to the undirected graph implementation, just the return object is a DiGraph.

        Returns:
            nx.DiGraph: this graph as networkx Graph object.
        """
        return super().toNetworkx(returnObject=nx.MultiDiGraph())  # type: ignore ## will return right object!

    def _topological_sort_rec_util(self, curNode: Node, visited: list[Node], stack: list[Node]):
        """
        Internal helper for the topological sorting of this graph.

        Args:
            curNode (Node): The current node to be considered.
            visited (list[Node]): A list of nodes storing which ones we have considered before.
            stack (list[Node]): the stack of nodes which will contain the final result.
        """
        logger.debug(f"  _topological_sort_rec_util for {curNode}")
        visited.append(curNode)

        # Check for all connected nodes ...
        for i in self.getNodeAdjacencyList(curNode):
            # ... when we haven't seen them before
            if (i not in visited):
                logger.debug(f"  Not yet visited: {i}")
                # ... call recursively with the neighbor
                self._topological_sort_rec_util(i, visited, stack)

        stack.insert(0, curNode)

    def topological_sort(self) -> list[Node]:
        """
        Recursive implementation of a topological sort.

        Utilizes _topological_sort_rec_util() for the recursive part.

        Returns:
            list[Node]: list of nodes in tolopogical order.
        """
        visited = []
        topoListStack = []

        for n in self.get_nodes():
            if n not in visited:
                self._topological_sort_rec_util(n, visited, topoListStack)

        return topoListStack

    def calculate_in_degree(self) -> dict[Node, int]:
        """
        Calculates the in-degree for each node of the graph.

        Returns:
            dict[Node, int]: dict with node and corresponding in-degree.
        """
        nodeInDegree = dict()

        for n in self.get_nodes():
            nodeInDegree[n] = 0

        # For every node ...
        for n in self.get_nodes():
            # ... increase the in-count its neighbors by one
            neighbors = self.getNodeAdjacencyList(n)
            for neighbor in neighbors:
                nodeInDegree[neighbor] += 1

        return nodeInDegree

    def topological_sort_Kahn(self) -> list[Node]:
        """
        Topological sort implementation following Kahn's algorithm.

        Returns:
            list[Node]: nodes in a topological sorted list.
        """
        resultList = []
        q = deque()
        nodes_inDegree = self.calculate_in_degree()

        # Initialize queue with all nodes not having incoming connections (== no dependencies)
        for node, degree in nodes_inDegree.items():
            if degree == 0:
                q.append(node)

        # As long there are elements on the queue (of nodes without incoming connections)
        while q:
            logger.debug(f"    Node queue: {q} (with out-degree == 0)")

            # Take an element and place it on the final list
            node = q.popleft()
            resultList.append(node)

            logger.debug(f"    node {node} on sorted list.")

            # For all neighbors of this node ...
            neighbors = self.getNodeAdjacencyList(node)
            for neighbor in neighbors:
                # ... decrement the in-degree by 1
                nodes_inDegree[neighbor] -= 1

                # If this leads to now not having any incoming connections => add it to queue
                if nodes_inDegree[neighbor] == 0:
                    logger.debug(f"        q.append: {neighbor}")
                    q.append(neighbor)

            logger.debug(f"    nodeInDegree: {nodes_inDegree}")

        return resultList
