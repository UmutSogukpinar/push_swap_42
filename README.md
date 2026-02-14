<div align="center">
  <a href="https://github.com/umutsogukpinar/push_swap">
    <img src="https://github.com/ayogun/42-project-badges/blob/main/badges/push_swapm.png" alt="push_swap Logo" width="200">
  </a>

  <h1>push_swap</h1>

  <p>
    <b>"Sorting a stack with limited operations — as few moves as possible."</b>
  </p>

  <p>
    <a href="https://github.com/umutsogukpinar/push_swap">
      <img src="https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c" alt="C Language">
    </a>
    <a href="#">
      <img src="https://img.shields.io/badge/Score-125%2F100-success?style=for-the-badge" alt="Score">
    </a>
  </p>
</div>

> A sorting algorithm project from the 42 curriculum.
> The goal is to sort a stack of integers using a limited set of operations, with the minimum number of moves possible.

---

## Table of Contents

- [Overview](#overview)
- [Rules](#rules)
- [Operations](#operations)
  - [Swap](#swap)
  - [Push](#push)
  - [Rotate (top goes to bottom)](#rotate-top-goes-to-bottom)
  - [Reverse rotate (bottom goes to top)](#reverse-rotate-bottom-goes-to-top)
- [Algorithm](#algorithm)
  - [1) Indexing (Rank compression)](#1-indexing-rank-compression)
  - [2) Reducing Stack A (A → B)](#2-reducing-stack-a-a--b)
  - [3) Core detection + small sort (circular condition)](#3-core-detection--small-sort-circular-condition)
  - [4) Greedy reinsertion (B → A)](#4-greedy-reinsertion-b--a)
  - [5) Circular sort (final alignment)](#5-circular-sort-final-alignment)
- [Build](#build)
- [Usage](#usage)
- [Examples](#examples)
  - [Count number of moves](#count-number-of-moves)
  - [Validate with checker](#validate-with-checker)
- [Checker](#checker)
- [Error Handling](#error-handling)

---

## Overview

`push_swap` takes a list of integers as arguments and prints a sequence of operations that sorts them in ascending order.

You must use **two stacks**:

* **Stack A**: starts with all numbers
* **Stack B**: starts empty

Your program must print only valid operations (one per line). **No extra text.**

---

## Rules

* Only the allowed operations are permitted.
* Numbers must be sorted in **ascending order** in **stack A**.
* **Stack B must be empty** at the end.
* Input can include:

  * negative numbers
  * spaces and/or multiple arguments (depending on your parser)
  * integers must fit in **signed 32-bit int**
* Input **must NOT** include:

  * duplicates (duplicates = error)
* If input is invalid, print `Error` to `stderr`.

---

## Operations

### Swap

* `sa` : swap the first 2 elements at the top of stack A
* `sb` : swap the first 2 elements at the top of stack B
* `ss` : `sa` and `sb` at the same time

### Push

* `pa` : take the first element at the top of B and put it on A
* `pb` : take the first element at the top of A and put it on B

### Rotate (top goes to bottom)

* `ra` : rotate A up by 1
* `rb` : rotate B up by 1
* `rr` : `ra` and `rb` at the same time

### Reverse rotate (bottom goes to top)

* `rra` : rotate A down by 1
* `rrb` : rotate B down by 1
* `rrr` : `rra` and `rrb` at the same time

---

## Algorithm

This project is basically: **"Sorting with handcuffs on."**

I used the **Turk Algorithm (Greedy Reinsertion)** and reduced the number of moves with a **circular sort (final alignment)**.

### 1) Indexing (Rank compression)

- Instead of working with raw values, I map each number to its **rank/index** in the sorted order (`0..n-1`).
- This makes comparisons consistent and simplifies target position calculations.

### 2) Reducing Stack A (A → B)

Goal: keep a small **core** in `A` and push the rest into `B`.

- I push most elements from `A` to `B` using `pb`.
- While pushing, I choose between `ra` / `rra` to bring the next candidate to the top with **minimum rotations**.
- Typically, I keep **3 elements** in `A` as the core.

### 3) Core detection + small sort (circular condition)

- While pushing elements to `B`, I constantly check whether stack `A` is already **circularly sorted**
  (i.e., it is sorted but rotated, so it can be fixed only with `ra` / `rra`).
- As soon as `A` becomes circularly sorted, I **stop pushing** more elements to `B`.
- If `A` is reduced to a very small set (e.g., 3 elements), I sort that remaining part using a minimal hardcoded sequence.


### 4) Greedy reinsertion (B → A)

This is the main optimization step.

For each element in `B`:

- I compute its **target insertion position** in `A` (where it should be placed to keep `A` sorted).
- I calculate the rotation cost for both stacks:
  - `ra` / `rra` for `A`
  - `rb` / `rrb` for `B`
- If both stacks rotate in the same direction, I merge rotations to save moves:
  - `rr` (rotate both)
  - `rrr` (reverse rotate both)

Then I pick the element in `B` with the **lowest total cost** (greedy choice), perform the required rotations, and insert it with `pa`.

This loop continues until `B` becomes empty.

### 5) Circular sort (final alignment)

After reinsertion, `A` is sorted but may start from a non-minimum element.

- I finish by rotating `A` (`ra` or `rra`) to bring the **smallest element** to the top.
- This **circular alignment** reduces unnecessary extra operations and produces the final sorted stack efficiently.

---

## Build
```bash
make
```

Cleaning:
```bash
make clean
make fclean
make re
```

---

## Usage
```bash
./push_swap 2 1 3 6 5 8
```

If your parser supports a single string input:
```bash
./push_swap "2 1 3 6 5 8"
```

Output: operations list, e.g.
```text
sa
ra
pb
...
```

---

## Examples

### Count number of moves
```bash
ARG="4 67 3 87 23"
./push_swap $ARG | wc -l
```

### Validate with checker
```bash
ARG="4 67 3 87 23"
./push_swap $ARG | ./checker $ARG
```

Expected output:

* `OK` if sorted correctly
* `KO` if not sorted

---

## Checker

If you don't have the official checker, you can use a community checker or write your own.

Minimal idea:

1. Initialize stack A from input.
2. Read operations from stdin.
3. Execute operations on stacks.
4. If A is sorted and B is empty → `OK`, else → `KO`.

---

## Error Handling

The program prints `Error` to `stderr` when:

* non-numeric input
* duplicate numbers
* overflow / underflow (outside `int` range)
* invalid formatting (empty strings, bad signs, etc.)
