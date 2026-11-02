# Dino Invitation — Multi-source BFS

## Problem

An office is represented by an n × m grid:

- `*` — an empty cell that blocks the invitation;
- `S` — an intern who has not received the invitation yet;
- `D` — a dinosaur that starts spreading the invitation at time 0.

At each time step, every dinosaur and every invited intern invites adjacent interns (up, down, left, right).

The task is to find the minimum time needed to invite all interns. If at least one intern cannot be reached, output `-1`. If there are no interns, output `0`.

## Approach

The solution uses **multi-source breadth-first search (BFS)**.

1. Read the grid and add every `D` cell to the queue.
2. Set the time for every dinosaur cell to `0`. All other cells start with time `-1`.
3. Process the queue. For each cell, check its four orthogonal neighbours.
4. Visit a neighbour only if it is an unvisited intern (`S` with time `-1`). Its invitation time is the current cell's time plus one.
5. After BFS, inspect all intern cells:
   - if any still has time `-1`, output `-1`;
   - otherwise, output the maximum invitation time.
6. If there are no intern cells, the answer remains `0`.

Starting BFS from all dinosaurs at once ensures that each intern receives the shortest possible invitation time from the nearest dinosaur.

## Complexity

Let `n` be the number of rows and `m` the number of columns.

- **Time:** `O(n × m)` — each cell is inserted into the queue and processed at most once.
- **Memory:** `O(n × m)` — the grid, distance matrix, and BFS queue.

## Build

With GCC or MinGW:

```bash
g++ -std=c++17 -O2 -Wall -Wextra -pedantic main.cpp -o dino-invitation
```

Run in PowerShell:

```powershell
.\dino-invitation.exe
```

## Concepts practised

- `std::vector` and a two-dimensional grid;
- `std::queue` and `std::pair`;
- breadth-first search;
- multi-source BFS;
- grid boundaries and four-direction movement;
- unreachable states and edge cases.
