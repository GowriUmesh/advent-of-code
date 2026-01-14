# Day 3: Lobby 

> 🎯 **Goal:** For each bank of batteries, choose digits in order to form the largest possible joltage number.
Then sum the maximum joltages from all banks to get the total output.

----
## 📖 Problem Summary
The batteries are arranged into banks; each line of digits in your input corresponds
to a single bank of batteries. Within each bank, you need to turn batteries;
the joltage that the bank produces is equal to the number formed by the digits on the batteries youve turned on. 

* Part 1 : Find the sum of largest joltage output possible from a single bank of batteries by turning on exactly two of them.\
* Part 2 : To overcome static friction , more power is needed, 
so find the sum of the largest joltage outputs from all banks of batteries by turning on 12 of them.

[Read More ...](https://adventofcode.com/2025/day/3)

## Examples 
Given these battery banks
```
987654321111111
811111111111119
234234234234278
818181911112111
```
* **Without static Friction**

Youll need to find the largest possible joltage each bank can produce by turning on exactly 2 batteriess:

In `987654321111111`, you can make the largest joltage possible, 98, by turning on the first two batteries.\
In `811111111111119`, you can make the largest joltage possible by turning on the batteries labeled `8` and `9`, producing `89` jolts.\
In `234234234234278`, you can make `78` by turning on the last two batteries (marked `7` and `8`).\
In `818181911112111`, the largest joltage you can produce is `92`.\

The total output joltage is the sum of the maximum joltage from each bank, so in this example, the total output joltage is `98 + 89 + 78 + 92 = 357`.

* **With static Friction**

To overcome static friction , youll need to now turn on 12 batteries in each bank: 

In `987654321111111`, the largest joltage can be found by turning on everything except some 1s at the end to produce `987654321111`.\
In the digit sequence `811111111111119`, the largest joltage can be found by turning on everything except some 1s, producing `811111111119`.\
In `234234234234278`, the largest joltage can be found by turning on everything except a 2 battery, a 3 battery, and another 2 battery near the start to produce 434234234278.\
In `818181911112111`, the joltage `888911112111` is produced by turning on everything except some 1s near the front.\

The total output joltage is now much larger:\
`987654321111 + 811111111119 + 434234234278 + 888911112111 = 3121910778619.`


## 💻 Usage
1. Place your puzzle input in a text file (`input.txt`)  
2. Run the solution script with the input file as an argument:

```bash
# Default method (without static friction)
./lobby.py <path_to_input.txt>

# Method with static friction 
./lobby.py <path_to_input.txt> --static_friction True
```
