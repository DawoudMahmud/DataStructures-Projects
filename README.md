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
