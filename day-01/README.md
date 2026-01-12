# Day 1: Secret Entrance

> 🎯 **Goal:** Count how many times a circular dial points at 0 after a series of rotations.

---

## 📖 Problem Summary

The puzzle simulates a **circular dial numbered 0–99**, starting at position `50`.  
We are given a series of rotations, each consisting of a direction (`L` for left, `R` for right) and a distance.  

The **twist**: the password is **not the final position**, but the **number of times the dial points at 0** during the sequence based of two different methods.

## Examples 

Given these rotations: 
L68
L30
R48
L5
R60
L55
L1
L99
R14
L82

* Method 0: Count only the final position after each rotation.
Result: 3 times at 0.

* Method 1 (0x434C49434B): Count every click that passes 0.
Result: 6 times at 0.

## 💻 Usage

1. Place your puzzle input in a text file (`input.txt`)  
2. Run the solution script with the input file as an argument:

```bash
# Default method (method 0)
./secret_entrance.py input.txt

# Method 1 (count every click, 0x434C49434B)
./secret_entrance.py input.txt --method 1
