# DataStructures-Project1
Assignment 1 of my Data Structures and Algorithms project course

CS 165 Project #1 — Analyzing Sorting Algorithms
Project 1 involves implementing and testing various sorting algorithms experimentally to determine their real-world running times. In particular, you will need to implement each of the following sorting algorithms:

1. Insertion-sort
2. Merge-sort
3. The following implementations of Shellsort:
     1. The original Shell sequence, [n/2k ], ..., 1, for k=1,2,...,log n, where [*] denotes the floor function.
     2. The A083318 (Links to an external site.) sequence, 2k + 1, for k=log n, ..., 3, 2, 1, plus the value 1.
     3. The A003586 (Links to an external site.) sequence, 2p3q, ordered from the largest such number less than n down to 1.
     4. The A033622 (Links to an external site.) sequence, in reverse order, starting from the largest value less than n, down to 1.
4. The following implementations of Hybrid sort (using merge-sort and insertion-sort):
     1. H = n1/2
     2. H = n1/4
     3. H = n1/6

# DataStructures-Project2
Assignment 2 of my Data Structures and Algorithms project course

CS 165 - Project 2 - Testing Solution Quality

Project 2 involves testing various bin packing algorithms experimentally to determine the quality of the solutions they produce. The specific bin-packing algorithms you should implement are the following five algorithms:

1. Next Fit (NF)
2. First Fit (FF)
3. Best Fit (BF)
4. First Fit Decreasing (FFD)
5. Best Fit Decreasing (BFD)

For your implementations of First Fit and Best Fit (including the FFD and BFD versions), you must implement these methods to run in O(n log n) expected time. Moreover, your solutions must use a balanced binary search tree known as a zip tree and you must implement this data structure yourself, not from a library.

# DataStructures-Project3
Assignment 3 of my Data Structures and Algorithms project course

CS 165 - Project 3
Algorithmic Experiments of Real-World Phenomena

Project 3 involves testing various graph algorithms experimentally to determine properties of models of real-world networks. The specific graph algorithms you should implement are the following three algorithms (please see the course notes for details on these algorithms):

1. Diameter algorithm, that is, as best is reasonably possible, determine the length of a longest path in the graph
2. Clustering-coefficient algorithm, that is, determine the ratio of three times the number of triangles over the number of paths of length 2
3. Degree-distribution algorithm, that is, determine for each possible degree, the number of vertices in the graph with that degree

You need to test each algorithm on Barabasi-Albert random graphs, generated with the parameter d = 5 as the number of neighbors each new vertex chooses.

You should determine the diameter and clustering coefficients of multiple random graphs of length n. 
