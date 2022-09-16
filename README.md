# DataStructures-Project1
Assignment 1 of my Data Structures and Algorithms project course

CS 165 Project #1 — Analyzing Sorting Algorithms (Phase 1)
Project 1 involves implementing and testing various sorting algorithms experimentally to determine their real-world running times. In particular, for Phase 1 you will need to implement each of the following sorting algorithms:

Insertion-sort
Merge-sort
The following implementations of Shellsort:
 The original Shell sequence, [n/2k ], ..., 1, for k=1,2,...,log n, where [*] denotes the floor function.
The A083318 (Links to an external site.) sequence, 2k + 1, for k=log n, ..., 3, 2, 1, plus the value 1.
The A003586 (Links to an external site.) sequence, 2p3q, ordered from the largest such number less than n down to 1.
The A033622 (Links to an external site.) sequence, in reverse order, starting from the largest value less than n, down to 1.
The following implementations of Hybrid sort (using merge-sort and insertion-sort):
H = n1/2
H = n1/4
H = n1/6
