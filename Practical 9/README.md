# Experiment 9: Graph Traversal for Campus Navigation Using BFS and DFS

## Practical title

**Campus Navigation using Breadth-First Search and Depth-First Search**

## Problem statement

Represent a campus as a graph in which each location (such as a building, gate, or parking area) is a vertex and each direct path between two locations is an edge. Given a starting location, traverse the connected campus map using:

- **Breadth-First Search (BFS):** Visits locations level by level.
- **Depth-First Search (DFS):** Follows one path as far as possible before backtracking.

The program should display the order in which locations are visited. If the graph is unweighted, BFS can also find a route with the fewest edges from the start to a destination. DFS provides a traversal, but does not necessarily produce the shortest route.

## Objective

- Represent campus locations and paths as a graph.
- Implement BFS and DFS from a chosen starting location.
- Track visited locations to avoid revisiting nodes or looping.
- Compare queue-based and stack/recursion-based graph traversal.

## Algorithm / approach

Store the campus graph as an adjacency list or adjacency matrix. For an undirected campus path, add an edge in both directions. Mark locations as visited when they are discovered so each location is processed at most once.

### Breadth-First Search (BFS)

1. Mark the starting location visited and add it to a queue.
2. While the queue is not empty:
   - Remove the front location and visit it.
   - For every unvisited adjacent location, mark it visited and add it to the queue.
3. Stop when the queue is empty or, for a destination search, when the destination is found.

### Depth-First Search (DFS)

1. Mark the starting location visited and visit it.
2. For each adjacent location that has not been visited, recursively run DFS from that location.
3. Alternatively, use an explicit stack and push adjacent unvisited locations.
4. Stop when all locations reachable from the start have been visited or the destination is found.

The exact traversal order can vary depending on how neighboring locations are stored and processed.

## Data structure / concept used

- **Graph:** Models locations (vertices) and paths (edges).
- **Adjacency list or adjacency matrix:** Stores which locations connect directly.
- **Queue:** Supports BFS in first-in, first-out order.
- **Recursion or stack:** Supports DFS depth-first exploration.
- **Visited array/set:** Prevents repeated visits and infinite traversal cycles.

## Test cases

| Case | Graph / input condition | Expected result |
|---|---|---|
| 1 | Start at a location with several adjacent locations | BFS visits immediate neighbors before more distant locations. |
| 2 | Start at a location with several paths | DFS follows one branch before backtracking. |
| 3 | Campus graph contains a cycle | Each location is visited at most once. |
| 4 | Some locations are disconnected from the start | Traversal visits only the start's connected component. |
| 5 | Start equals destination | Destination is found immediately; path contains only the start. |
| 6 | Destination is unreachable | Report that no route was found. |
| 7 | Empty graph or invalid starting location | Reject the input or display an appropriate message. |

## Sample input and output

Assume the graph is undirected and neighbors are processed in alphabetical order. Locations and connections:

- Gate connects to Library and ScienceBlock.
- Library connects to Cafeteria.
- ScienceBlock connects to Cafeteria and Gym.

### Sample input

```text
Locations: Gate, Library, ScienceBlock, Cafeteria, Gym
Paths: Gate-Library, Gate-ScienceBlock, Library-Cafeteria,
       ScienceBlock-Cafeteria, ScienceBlock-Gym
Start: Gate
```

### Sample output

```text
BFS traversal: Gate Library ScienceBlock Cafeteria Gym
DFS traversal: Gate Library Cafeteria ScienceBlock Gym
```

The DFS order shown depends on the listed neighbor order. Other valid adjacency ordering can produce a different DFS sequence.

## Time complexity

Let `V` be the number of locations (vertices) and `E` the number of paths (edges).

- **BFS with an adjacency list:** O(V + E)
- **DFS with an adjacency list:** O(V + E)
- **With an adjacency matrix:** Each traversal may take O(V²) because all possible neighbors are checked.

## Space complexity

- **Adjacency list representation:** O(V + E)
- **Visited tracking:** O(V)
- **BFS queue:** O(V) in the worst case.
- **DFS recursion stack or explicit stack:** O(V) in the worst case.

Overall auxiliary space for traversal is **O(V)**, in addition to the graph representation.

## Conclusion

BFS and DFS provide two ways to explore a campus graph. BFS explores nearby locations first and can find a shortest path by edge count in an unweighted graph. DFS explores deeply before backtracking and is useful for reachability and full traversal. Both rely on visited tracking to handle cycles safely.
