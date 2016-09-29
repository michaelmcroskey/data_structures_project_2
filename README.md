Project 02: lsort
===================

This is a simple implementation of the Unix [sort] utility that works on
[singly-linked lists].

[sort]: http://man7.org/linux/man-pages/man1/sort.1.html
[singly-linked lists]: https://en.wikipedia.org/wiki/Linked_list#Singly_linked_lists

Questions
==========

Michael McRoskey, Troy Prince, David Mellitt

---

**1) What is complexity of each of the sorting modes (ie. STL, QSORT, MERGE, QUICK)? For each method, briefly explain the best, average, and worst case complexities of the sorting mode in terms of Big-O notation.**
     	 
	 BEST     	AVERAGE		WORST
STL:    
QSORT: 
MERGE:   O(n log(n))    O(n log(n))	O(n log(n))
QUICK:   O(n log(n))    O(n log(n))     O(n^2)

**2) Benchmark all four different sorting modes on files with the following number of integers:**

    10, 100, 1000, 10000, 100000, 1000000, 10000000


| Mode    | Size     | Elapsed Time  | Memory    |
|---------|----------|---------------|-----------|
| STL     | 10       | 0             | 0         |
| STL     | 100      | 0             | 0         |
| STL     | 1000     | 0             | 0         |
| STL     | 10000    | 0             | 0         |
| STL     | 100000   | 0             | 0         |
| STL     | 1000000  | 0             | 0         |
| STL     | 10000000 | 0             | 0         |
|---------|----------|---------------|-----------|
| QSORT   | 10       | 0             | 0         |
| QSORT   | 100      | 0             | 0         |
| QSORT   | 1000     | 0             | 0         |
| QSORT   | 10000    | 0             | 0         |
| QSORT   | 100000   | 0             | 0         |
| QSORT   | 1000000  | 0             | 0         |
| QSORT   | 10000000 | 0             | 0         |
|---------|----------|---------------|-----------|
| MERGE   | 10       | 0             | 0         |
| MERGE   | 100      | 0             | 0         |
| MERGE   | 1000     | 0             | 0         |
| MERGE   | 10000    | 0             | 0         |
| MERGE   | 100000   | 0             | 0         |
| MERGE   | 1000000  | 0             | 0         |
| MERGE   | 10000000 | 0             | 0         |
|---------|----------|---------------|-----------|
| QUICK   | 10       | 0             | 0         |
| QUICK   | 100      | 0             | 0         |
| QUICK   | 1000     | 0             | 0         |
| QUICK   | 10000    | 0             | 0         |
| QUICK   | 100000   | 0             | 0         |
| QUICK   | 1000000  | 0             | 0         |
| QUICK   | 10000000 | 0             | 0         |
|---------|----------|---------------|-----------|


**3) After you have performed your benchmark:**

- **Discuss the relative performance of each sorting method and try to explain the differences.**

- **What do these results reveal about the relationship between theoretical complexity and actual performance?**

- **In your opinion, which sorting mode is the best? Justify your conclusion by examining the trade-offs for the chosen mode.**


Group Contributions
-------------------

- David: 

- Troy:

- Michael:
