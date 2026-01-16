# Day 5 : Cafeteria

> 🎯 **Goal:**  Count how many available ingredients are Fresh and total number of fresh ingredients

---

## 📖 Problem Summary

In the cafeteria, ingredients are marked as "Fresh" or "Stale" based on their IDs.

The database consists of:
1. A list of fresh ingredient ID ranges (inclusive)
2. A blank line
3. A list of available ingredient IDs

Task is to determine:\
Part 1: How many of the available ingredient IDs are fresh? \
Part 2: How many ingredient IDs are considered to be fresh according to the fresh ingredient ID ranges?

## Example

Given this input IDs:
```
3-5
10-14
16-20
12-18

1
5
8
11
17
32
```
The fresh ID ranges are inclusive: 
the range `3-5` means that ingredient IDs `3`, `4`, and `5` are all fresh. The ranges can also overlap; an ingredient ID is fresh if it is in any range.

Ingredient ID `1` is spoiled because it does not fall into any range.\
Ingredient ID `5` is fresh because it falls into range `3-5`.\
Ingredient ID `8` is spoiled.\
Ingredient ID `11` is fresh because it falls into range `10-14`.\
Ingredient ID 17 is fresh because it falls into range `16-20` as well as range `12-18`.\
Ingredient ID `32` is spoiled.

Part 1 : So, **`3`** of the available ingredient IDs are fresh.

Part 2 : The ingredient IDs that these ranges consider to be fresh are `3, 4, 5, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, and 20`. So, the fresh ingredient ID ranges consider a total of **`14`** ingredient IDs to be fresh.

## 💻 Usage

1. Place your puzzle input in a text file (`input.txt`)  
2. Run the solution script with the input file as an argument:

```bash
./cafeteria.py input.txt
```

