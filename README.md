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
     	 
    	         BEST     	AVERAGE 		WORST
STL:         O(n log(n))    O(n log(n))   O(n log(n))
QSORT:    probably nlogn    O(n log(n))  unknown, possibly n^2
MERGE:       O(n log(n))    O(n log(n))	  O(n log(n))
QUICK:       O(n log(n))    O(n log(n))   O(n^2)

**2) Benchmark all four different sorting modes on files with the following number of integers:**

    10, 100, 1000, 10000, 100000, 1000000, 10000000


| Mode    | Size     | Elapsed Time  | Memory    |
|---------|----------|---------------|-----------|
| STL     | 10       |  0.001532     |   0.761719|
| STL     | 100      |  0.001536     |   0.765625|
| STL     | 1000     |  0.002892     |   0.816406|
| STL     | 10000    |  0.018187     |   1.328125|
| STL     | 100000   |  0.188890     |   6.285156|
| STL     | 1000000  |  2.378373     |  54.976562|
| STL     | 10000000 | 25.956360     | 542.179688|
|---------|----------|---------------|-----------|
| QSORT   | 10       |  0.001489     |   0.757812|
| QSORT   | 100      |  0.001579     |   0.761719|
| QSORT   | 1000     |  0.002933     |   0.812500|
| QSORT   | 10000    |  0.018598     |   1.324219|
| QSORT   | 100000   |  0.185926     |   6.285156|
| QSORT   | 1000000  |  2.332013     |  54.996094|
| QSORT   | 10000000 | 26.060291     | 542.171875|
|---------|----------|---------------|-----------|
| MERGE   | 10       |  0.001404     |   0.750000|
| MERGE   | 100      |  0.001524     |   0.753906|
| MERGE   | 1000     |  0.002871     |   0.796875|
| MERGE   | 10000    |  0.018633     |   1.242188|
| MERGE   | 100000   |  0.189622     |   5.507812|
| MERGE   | 1000000  |  2.412186     |  47.359375|
| MERGE   | 10000000 | 27.742207     | 465.871094|
|---------|----------|---------------|-----------|
| QUICK   | 10       |  0.001490     |   0.750000|
| QUICK   | 100      |  0.001550     |   0.753906|
| QUICK   | 1000     |  0.002971     |   0.796875|
| QUICK   | 10000    |  0.020463     |   1.242188|
| QUICK   | 100000   |  0.196883     |   5.492188|
| QUICK   | 1000000  |  2.838332     |  47.355469|
| QUICK   | 10000000 | 37.399971     | 465.863281|
|---------|----------|---------------|-----------|


**3) After you have performed your benchmark:**

- **Discuss the relative performance of each sorting method and try to explain the differences.**

stl and qsort had similar time and memory usage. stl was usually slightly faster
with a miniscule increase in memory usage over qsort. Merge sort and quick sort
used less memory than stl and qsort (about 80 Mbytes for last benchmark), but
were slower to sort a large number of elements. Quick sort became much slower
than the others on the last benchmark (~10 more seconds). This may be because
it performs badly with repeat numbers, which there are likely many of in a large
set of randomly generated numbers.

- **What do these results reveal about the relationship between theoretical complexity and actual performance?**

With small sets, there probably won't be a large difference between algorithm
performance, but as the set grows, algorithms with different complexities
will likely show a difference which grows according to the difference in
complexity.

- **In your opinion, which sorting mode is the best? Justify your conclusion by examining the trade-offs for the chosen mode.**

Surprisingly, merge sort seemed to perform the best. Its execution time was
comparable to stl and qsort ( within 2 seconds at the last benchmark), but
it used considerably less memory than either. Quick sort would probably be
the best if it used a third partition for keys equal to the pivot.

Group Contributions
-------------------

- David: 

Merge.cpp and quick.cpp

- Troy:

shell script, benchmark testing, readme, help with code

- Michael:

List.cpp, stl.cpp, qsort.cpp, comparison functions
