# Day 2: Gift Shop

> 🎯 **Goal:** : Find all the invalid product IDs in a gift shop database and sum them up.



--- 
## 📖 Problem Summary

Given a set of numeric ID ranges, identify all invalid product IDs.
An ID is considered invalid if it consists of a sequence of digits

repeated atleast twice (e.g., 12341234, 123123123, 1111111).

The task is to scan all provided ranges, find every invalid ID,
and return the sum of those invalid values.

[Read more..](https://adventofcode.com/2025/day/2)

## Example
Given these set of input ID ranges 
```
11-22,95-115,998-1012,1188511880-1188511890,222220-222224,1698522-1698528,446443-446449,38593856-38593862,565653-565659,824824821-824824827,2121212118-2121212124
```
`11-22` has two invalid IDs, `11` and `22`. \
`95-115` now has two invalid IDs, `99` and `111`.\
`998-1012` now has two invalid IDs, `999` and `1010`.\
`1188511880-1188511890` has one invalid ID, `1188511885`.\
`222220-222224` has one invalid ID, `222222`.\
`1698522-1698528` contains no invalid IDs. \
`446443-446449` has one invalid ID, `446446`.\
`38593856-38593862` has one invalid ID, `38593859`.\
`565653-565659` now has one invalid ID, `565656`.\
`824824821-824824827` now has one invalid ID, `824824824`. \
`2121212118-2121212124` now has one invalid ID, `2121212121`.

Adding up all the invalid IDs in this example produces **`4174379265`**.


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
./invalid_ids <path_to_input_file>
```