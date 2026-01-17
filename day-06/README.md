# Day 6: Trash Compactor

> 🎯 **Goal:** : While we wait for the Trash compactor to open we help solve math problems of cephalopod.

---
## 📖 Problem Summary

The math worksheet consists  of a list of problems:each problem
has a group of numbers that need to be either added or multiplied together.

The problems are in a long horizontal list and each problem's numbers are arranged vertically. 
At the bottom of the problem is the symbol for the operation. 

* Part 1 : *Solve normal way*\
Calculate the result of each problem and sum them all together.
(ignore the alignment of the numbers within each problem)

* Part 2 : *Solve cephalopod way*\
Calculate the result when math is written right-to-left in columns.
Each number is given in its own column, with the most significant digit at the top 
and the least significant digit at the bottom.

## Example
Given this worksheet
```
123 328  51 64 
 45 64  387 23 
  6 98  215 314
*   +   *   +  
```
**Solve Normal Way**

- `123 * 45 * 6 = 33210`
- `328 + 64 + 98 = 490`
- `51 * 387 * 215 = 4243455`
- `64 + 23 + 314 = 401`

the grand total is `33210` + `490` + `4243455` + `401` = `4277556`.

**Solve Cephalopod way**

* The rightmost problem is `4 + 431 + 623 = 1058`
* The second problem from the right is `175 * 581 * 32 = 3253600`
* The third problem from the right is `8 + 248 + 369 = 625`
* Finally, the leftmost problem is `356 * 24 * 1 = 8544`

Now, the grand total is `1058` + `3253600` + `625` + `8544` = `3263827`.
## 💻 Usage

1. Place your puzzle input in a text file (`input.txt`)  
2. Create a build directory

```bash
mkdir build && cd build
cmake ..
make 
```
3. Run the solution script with the input file as an argument:

```bash
./solve_math_homework <path_to_input_file> <0|1>
# Use 0 to solve the problems normal way and 
# Use 1 to solve the cephalopod way.
```