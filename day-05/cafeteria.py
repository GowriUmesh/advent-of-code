#!/usr/bin/env python3

"""
Advent of Code - Day 5: Cafeteria

In the cafeteria, ingredients are marked as "Fresh" or "Stale" based on their IDs.

The database consists of:
1. A list of fresh ingredient ID ranges (inclusive)
2. A blank line
3. A list of available ingredient IDs

Task is to determine:
Part 1: How many of the available ingredient IDs are fresh? 
Part 2: How many ingredient IDs are considered to be fresh according to the fresh ingredient ID ranges?
"""

import argparse
import sys
from pathlib import Path

def get_fresh_ranges(lines):

    fresh_ranges = []
    for line in lines:
        if line == "":
            break
        start, end = map(int, line.split('-'))
        fresh_ranges.append((start, end))

    return fresh_ranges

def count_fresh_in_available_ids(lines):
    # Part 1: Count how many available IDs are fresh
    fresh_ranges = []
    available_ids = []

    fresh_ranges = get_fresh_ranges(lines)
    blank_index = next(i for i, line in enumerate(lines) if line == "")
    available_ids = [int(line) for line in lines[blank_index + 1:] if line.strip()]

    fresh_count_in_available = sum(1 for id in available_ids if any(start <= id <= end for start, end in fresh_ranges))

    return fresh_count_in_available

def count_total_fresh_ids(lines):
    # Part 2: Count total fresh IDs based on ranges
    fresh_ranges = get_fresh_ranges(lines)
    if not fresh_ranges:
        total_fresh_count = 0
    else:
        sorted_ranges = sorted(fresh_ranges)
        merged = [sorted_ranges[0]]
        
        for start, end in sorted_ranges[1:]:
            last_start, last_end = merged[-1]
            if start <= last_end + 1:
                merged[-1] = (last_start, max(last_end, end))
            else:
                merged.append((start, end))
        
        total_fresh_count = sum(end - start + 1 for start, end in merged)
    return total_fresh_count

if __name__ == "__main__":

    parse = argparse.ArgumentParser(description="Count number of Fresh Ingredients")
    parse.add_argument("input_file", type=Path,help="Path to the file with input.")
    args = parse.parse_args()

    if not args.input_file.exists():
        print(f"Error: File '{args.input_file}' does not exist.")
        sys.exit(1)    
    
    with open(args.input_file, 'r') as file:
        lines = file.read().strip().split('\n')

    fresh_count_in_available = count_fresh_in_available_ids(lines)
    total_fresh_count = count_total_fresh_ids(lines)
    print(f"Number of ingredients that are Fresh in available IDs: {fresh_count_in_available}")
    print(f"Number of ingredient IDs considered fresh according to the ranges: {total_fresh_count}")
