#!/usr/bin/env python3
"""
Advent of Code - Day 1: Secret Entrance
Part 1 : Count how many times the dial points at 0 after any rotation.
Part 2 : method 0x434C49434B - Count the number of times any click causes 
the dial to point at 0, regardless of whether it happens during a rotation or
at the end of a rotation.
The dial starts at 50 and rotates based on instructions (L/R + distance).
Dial is circular (0-99, wraps around).

"""
import sys
from pathlib import Path
import argparse

def count_dial_zeros(input_file,method=0):
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
        step = -1 if direction == 'L' else 1

        if method == 0:
            if direction == 'L':
                position = (position - distance) % 100
            elif direction == 'R':
                position = (position + distance) % 100
            else:
                raise ValueError(f"Invalid direction: {direction}")

            if position == 0:
                count_zero += 1
        elif method == 1:
            for _ in range(distance):
                position = (position + step) % 100
                if position == 0:
                    count_zero += 1
        else:
            raise ValueError(f"Invalid method: {method}")
    return count_zero


if __name__ == "__main__":

    parse = argparse.ArgumentParser(description="Count Zeros.")
    parse.add_argument("input_file", type=Path,help="Path to the file with input.")
    parse.add_argument("--method", type=int, choices=[0, 1], default=0,
                       help="Choose method 0 : to count how many times the dial points at 0 after any rotation." \
                       "Choose method 1: to count how many times the dial points at 0 during any click (method 0x434C49434B) .")
    args = parse.parse_args()

    if not args.input_file.exists():
        print(f"Error: File '{args.input_file}' does not exist.")
        sys.exit(1)    

    result = count_dial_zeros(args.input_file, args.method)
    print(f"Password (times dial points at 0): {result}")
