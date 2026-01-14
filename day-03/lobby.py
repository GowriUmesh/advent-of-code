#!/usr/bin/env python3
"""
Advent of Code - Day 3: Lobby

The batteries are arranged into banks; each line of digits in your input corresponds
to a single bank of batteries. Within each bank, you need to turn on batteries;
the joltage that the bank produces is equal to the number formed by the digits on the
batteries you've turned on. 

Part 1 : Find the sum of largest joltage output possible from a single bank of batteries 
by turning on exactly two of them.

Part 2 : To overcome static friction , more power is needed, 
so find the sum of the largest joltage outputs from all banks of batteries by 
turning on 12 of them.

"""
import sys
from pathlib import Path
import argparse
from itertools import combinations

def find_largest_joltage(line,static_friction=False):
    max_joltage = 0
    digits = [int(d) for d in line]
    n = len(digits)
    
    if not static_friction:
        for i in range(n):
            for j in range(i+1, n):
                joltage = digits[i] * 10 + digits[j]
                if joltage > max_joltage:
                    max_joltage = joltage
    else:
        k = 12
        result = []
        start = 0
        for remaining in range(k, 0, -1):
            end = n - remaining + 1
            max_digit = 0
            max_index = start
            for i in range(start, end):
                if digits[i] > max_digit:
                    max_digit = digits[i]
                    max_index = i
            result.append(max_digit)
            start = max_index + 1
        max_joltage = int(''.join(map(str, result)))

    return max_joltage

def total_output_joltage(input_file, static_friction=False):
    total_output = 0
    with open(input_file, 'r') as f:
        banks = f.readlines()   
    for line in banks:
        total_output+= find_largest_joltage(line.strip(),static_friction)
    return total_output

if __name__ == "__main__":

    parse = argparse.ArgumentParser(description="Find Largest Joltage.")
    parse.add_argument("input_file", type=Path,help="Path to the file with input.")
    parse.add_argument("--static_friction", type=bool, choices=[False, True], default=False,)
    args = parse.parse_args()

    if not args.input_file.exists():
        print(f"Error: File '{args.input_file}' does not exist.")
        sys.exit(1)    

    result = total_output_joltage(args.input_file, args.static_friction)
    print(f"The total output joltage: {result}")
