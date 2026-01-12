#!/usr/bin/env python3
"""
Advent of Code - Day 1: Secret Entrance
Count how many times the dial points at 0 after any rotation.

The dial starts at 50 and rotates based on instructions (L/R + distance).
Dial is circular (0-99, wraps around).

"""
import sys
from pathlib import Path

def count_dial_zeros(input_file):
    # Start position
    position = 50
    count_zero = 0
    
    with open(input_file, 'r') as f:
        instructions = f.readlines()
    
    for line in instructions:
        line = line.strip()
        if not line:
            continue
        
        direction = line[0]
        distance = int(line[1:])
        

        if direction == 'L':
            position = (position - distance) % 100
        elif direction == 'R':
            position = (position + distance) % 100
        else:
            raise ValueError(f"Invalid direction: {direction}")

        if position == 0:
            count_zero += 1
    
    return count_zero


if __name__ == "__main__":

    if len(sys.argv) != 2:
        print("Usage: python secret_entrance.py <input_file>")
        sys.exit(1)
    
    input_file = sys.argv[1]
    if not Path(input_file).exists():
        print(f"Error: File '{input_file}' does not exist.")
        sys.exit(1)

    result = count_dial_zeros(input_file)
    print(f"Password (times dial points at 0): {result}")
