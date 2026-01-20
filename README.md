*This project has been created as part of the 42 curriculum by FALAMLIH*

`push_swap` is a sorting algorithm project from 42 Network.
The goal is to sort a stack of integers using a limited set of operations while producing the smallest possible number of instructions.

An `algorithm` is a precise set of instructions to solve a problem, it can also be defined as a procedure for solving a mathematical or computational problem in a finite number of steps, often involving repetitive or recursive operations.
Algorithms are used to solve problems or automate tasks in a systematic and efficient manner. They are a set of instructions or rules that guide the computer or software in performing a particular task or solving a problem.

`The complexity` of an algorithm computes the amount of time and spaces required by an algorithm for an input of size (n). The complexity of an algorithm can be divided into two types. The time complexity and the space complexity.

`Time Complexity`: Time taken by the algorithm to solve the problem. It is measured by calculating the iteration of loops, number of comparisons etc.This calculation is totally independent of implementation and programming language.

`Space Complexity`: Space taken by the algorithm to solve the problem.it is defining as the process of defining a formula for prediction of how much memory space is required for the successful execution of the algorithm. The memory space is generally considered as the primary memory.

why we use algorithms:
# Efficiency
# Consistency
# Automation
# Standardization

`Sorting algorithms`: Bubble Sort, insertion sort, and many more. These algorithms are used to sort the data in a particular format.

                     <-- In this project i worked with chunks algorithm -->
 
The project consists of two main parts:

The Solver `(push_swap)`: A program that calculates the optimized instruction set to sort a list of integers.

The Checker `(checker)`: A program that verifies whether a given sequence of instructions actually results in a sorted stack.

# the Rules
The game is composed of two stacks, A and B.

`Stack A`: Contains a random amount of negative and/or positive numbers which cannot be duplicated.

`Stack B`: Is empty at the beginning.

| Code | Instruction | Action |
| :--- | :--- | :--- |
| **sa** | swap a | Swap the first 2 elements at the top of stack A. |
| **sb** | swap b | Swap the first 2 elements at the top of stack B. |
| **ss** | swap both | sa and sb at the same time. |
| **pa** | push a | Take the first element at the top of B and put it at the top of A. |
| **pb** | push b | Take the first element at the top of A and put it at the top of B. |
| **ra** | rotate a | Shift up all elements of stack A by 1. The first element becomes the last. |
| **rb** | rotate b | Shift up all elements of stack B by 1. The first element becomes the last. |
| **rr** | rotate both | ra and rb at the same time. |
| **rra** | reverse rotate a | Shift down all elements of stack A by 1. The last element becomes the first. |
| **rrb** | reverse rotate b | Shift down all elements of stack B by 1. The last element becomes the first. |
| **rrr** | reverse rotate both | rra and rrb at the same time. |

The project includes a Makefile that compiles both the push_swap and checker binaries. To compile, run the following command in your terminal:
# make

To run the solver:

# ./push_swap 3 2 1 6 0
To run the checker manually:

# ./checker 3 2 1
 ->sa
 ->pb
# (Press Ctrl+D to signal EOF and see the result)

To verify the solver with the checker:

# ARG="4 67 3 1 23"; ./push_swap $ARG | ./checker $ARG

->Linked List Implementation: Used for stacks to allow efficient insertion and deletion at both ends.

->Input Validation: Comprehensive parsing to handle non-integers, duplicates, and integer overflows.

# Error Handling
The program displays Error on the standard error output if:

Arguments are not integers.

Arguments are greater than an integer (overflow).

There are duplicate numbers.

If no arguments are provided, the program displays nothing.

# AI was used to find the best algo to work with and manage some complicatd memory leeks
https://www.geeksforgeeks.org/dsa/introduction-to-algorithms/
https://www.geeksforgeeks.org/computer-science-fundamentals/what-is-an-algorithm-definition-types-complexity-examples/
https://www.tutorialspoint.com/algorithms-and-complexities
