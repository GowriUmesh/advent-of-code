# Day 1: Secret Entrance

> 🎯 **Goal:** Count how many times a circular dial points at 0 after a series of rotations.

---

## 📖 Problem Summary

The puzzle simulates a **circular dial numbered 0–99**, starting at position `50`.  
We are given a series of rotations, each consisting of a direction (`L` for left, `R` for right) and a distance.  

The **twist**: the password is **not the final position**, but the **number of times the dial points at 0** during the sequence.

## 💻 Usage

1. Place your puzzle input in a text file (`input.txt`)  
2. Run the solution script with the input file as an argument:

```bash
./secret_entrance.py input.txt