# Day 8: Playground

> 🎯 **Goal:** : Connect 3D junction boxes using shortest-distance links to analyze circuit formation.
---
## 📖 Problem Summary

TThe elves are trying to figure out which junction boxes to connect 
so that the electrictiy can reach every junction box. 

Elves have a list of junction boxs' position in 3D space (input).
To save on string lights, the elves want to connect the junction boxes that are 
as close to each other as possible.

* Part 1 : Find the product of the sizes of the three largest circuits formed when 
connecting the 1000 closest pairs of junction boxes.

* Part 2 : Find the product of the x-coordinates of the two junction boxes connected by 
the last connection made when connecting all junction boxes with the minimum total distance.

[Read more ..](https://adventofcode.com/2025/day/8)
## Example
Given this input of junction boxes' positions

```
162,817,812
57,618,57
906,360,560
592,479,940
352,342,300
466,668,158
542,29,236
431,825,988
739,650,466
52,470,668
216,146,977
819,987,18
117,168,530
805,96,715
346,949,466
970,615,88
941,993,340
862,61,35
984,92,344
425,690,689
```
* **Part 1**

Each line represents a junction box at `(X, Y, Z)`. Junction boxes are connected in order of increasing straight-line distance, forming electrical circuits. After making the 10 shortest connections, the circuits have sizes `5, 4, 2, 2, 1, 1, 1, 1, 1, 1, 1`.
The product of the three largest circuit sizes is `40`.

* **Part 2**

Connections continue until all junction boxes form a single circuit.\
The final connection is between `(216,146,977)` and (`117,168,530)`, and multiplying their X coordinates gives `25272`.

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
./circuit_builder <path_to_input_file> 

```