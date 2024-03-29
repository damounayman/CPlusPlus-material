## 2.3A* Search
### Intro

#### Lesson Outline

- Introduction to Search
  - A* search algorithm
- Program A* Search
  - Algorithm will be broken down into several exercises for you 
  - Algorithm summary and structure of code for exercises
- C++ Features
  - Pass-by-reference
  - const and constexpr
  - Arrays

#### Lesson Goal

![project](../../assets/project.png)

#### A* search algorithm

The A* Search algorithm is an algorithm that is frequently used for path finding when working with graphs. In this context, you can think of a graph as just a collection of nodes with edges connecting some of the nodes. A* Search allows you to efficiently find a path, if one exists, between any two nodes in the graph.

### Motion Planning

> Artificial Intelligence for Robotics

- Motion planning: The process of finding a path from a start location to a goal location is called "planning". For robots, it's often called "robot motion planning".

- Discrete methods for planning: In the discrete methods for planning, the world chopped into small bins.

- Planning problem: Given Map, Start Location, Goal Location and a Cost Function, the simplest way to think of cost is just the time it takes to drive a certain route. The goal is finding the minimum cost path.

### A* Search

![astar](../../assets/astar.png)

This algorithm described is very similar to other search algorithms you may have seen before, such as [breadth-first search ](https://en.wikipedia.org/wiki/Breadth-first_search), except for the additional step of computing a heuristic and using that heuristic (in addition to the cost) to find the next node.

The following is psuedocode for the algorithm described in the video. Although the pseudocode shows the complete algorithm in a single function, we will split parts of the algorithm into separate functions in this lesson so you can implement them step-by-step in a sequence of exercises:

**Search** ( *grid* , *initial_point* , *goal_point* ) :

1. Initialize an empty list of open nodes.

2. Initialize a starting node with the following:

   - x and y values given by *initial_point* .
   - g = 0, where g is the cost for each move.
   - h given by the heuristic function (a function of the current coordinates and the goal).

3. Add the new node to the list of open nodes.

4. **while** the list of open nodes is nonempty:

   1. Sort the open list by f-value
   2. Pop the optimal cell (called the *current* cell).
   3. Mark the cell's coordinates in the grid as part of the path.
   4. **if** the *current* cell is the goal cell:

   - return the *grid* .

   1. **else** , expand the search to the *current* node's neighbors. This includes the following steps:

   - Check each neighbor cell in the *grid* to ensure that the cell is empty: it hasn't been closed and is not an obstacle.
   - If the cell is empty, compute the cost (g value) and the heuristic, and add to the list of open nodes.
   - Mark the cell as closed.

5. If you exit the while loop because the list of open nodes is empty, you have run out of new nodes to explore and haven't found a path.

#### Summary

The A* algorithm finds a path from the start node to the end node by checking for open neighbors of the current node, computing a heuristic for each of the neighbors, and adding those neighbors to the list of open nodes to explore next. The next node to explore is the one with the lowest total cost + heuristic (g + h). This process is repeated until the end is found, as long as there are still open nodes to explore.

### Lesson Code Structure

![code](../../assets/code.png)




Below are the steps from the `while ` loop in the A* pseudocode you saw previously:

**while** the list of open nodes is nonempty:

1. Sort the open list by f-value 
2. Pop the optimal cell (called the *current* cell).
3. Mark the cell's coordinates in the grid as part of the path.
4. if the current cell is the goal cell:
   - return the *grid* .
5. else, expand the search to the current node's neighbors. This includes the following steps:
   - Check each neighbor cell in the *grid* to ensure that the cell is empty: it hasn't been closed and is not an obstacle.
   - If the cell is empty, compute the cost (g value) and the heuristic, and add to the list of open nodes.
   - Mark the cell as closed.



The code for the A* search algorithm has been broken down into the following functions:

- `CellSort() `- sorts the open list according to the sum of h + g
- `ExpandNeighbors() `- loops through the current node's neighbors and calls appropriate functions to add neighbors to the open list
- `CheckValidCell() `- ensures that the potential neighbor coordinates are on the grid and that the cell is open
- `Heuristic() `- computes the distance to the goal
- `AddToOpen() `- adds the node to the open list and marks the grid cell as closed



### Starting A* Search

Starting with the `Search() `function

#### To Complete This Exercise

1. Write a `std::vector<vector<State>> Search ` function stub which takes a board grid and two length 2 int arrays as arguments. The int arrays will represent the start and goal coordinates for the search. The function should print "No path found!" and return an empty `std::vector<vector<State>> `. The function will later return the board with a path from the start to the goal.
2. In `main() `, call `Search ` with a start of `{0, 0} ` and a goal of `{4, 5} `. Store the results in the variable `solution `.
3. Pass `solution ` to `PrintBoard `.

```cpp
// TODO: Write the Search function stub here.
/*
Search( grid, initial_point, goal_point ) :

    1.Initialize an empty list of open nodes.

    2.Initialize a starting node with the following:
        x and y values given by initial_point.
        g = 0, where g is the cost for each move.
        h given by the heuristic function (a function of the current coordinates and the goal).

    3.Add the new node to the list of open nodes.

    4.while the list of open nodes is nonempty:
        4.1 Sort the open list by f-value and pop the optimal cell (called the current cell).
        4.2 Mark the cell's coordinates in the grid as part of the path.
        4.3 if the current cell is the goal cell:
            return the grid.
        else, expand the search to the current node's neighbors. This includes the following steps:
            Check each neighbor cell in the grid to ensure that the cell is empty: it hasn't been closed and is not an obstacle.
            If the cell is empty, compute the cost (g value) and the heuristic, and add to the list of open nodes.
            Mark the cell as closed.

    5.If you exit the while loop because the list of open nodes is empty, you have run out of new nodes to explore and haven't found a path.
*/
vector<vector<State>> Search(vector<vector<State>> grid,int initial_point[2], int goal_point[2] ){
    cout << "No path found!" << "\n";
    return vector<vector<State>> {};
}
```

```cpp
int main() {
    // TODO: Declare 2D "init" and "goal" arrays with values {0, 0} and {4, 5} respectively.
    int init_point[2] {0,0};
    int goal_point[2] {4,5};

    auto board = ReadBoardFile("1.board");
    // TODO: Call Search with "board", "init", and "goal". Store the results in the variable "solution".
    auto solution = Search(board, init_point, goal_point);
    // TODO: Change the following line to pass "solution" to PrintBoard.
    PrintBoard(solution);
}
```



### Writing the A* Heuristic

In this quiz, you will write a `Heuristic ` function that will be used to guide the A* search. In general, any [admissible function ](https://en.wikipedia.org/wiki/Admissible_heuristic)can be used for the heuristic, but for this project, you will write one that takes a pair of 2D coordinates on the grid and returns the [Manhattan Distance ](https://en.wikipedia.org/wiki/Taxicab_geometry)from one coordinate to the other.

#### To Complete This Exercise

Write an `int Heuristic ` function which takes four `int `s as arguments. The `int `s represent two pairs of 2D coordinates: $(x_1, y_1, x_2, y_2)$. The function should return an `int` which is the Manhattan Distance from one coordinate to the other: $|x_2- x_1| + |y_2 - y_1|$.



```cpp
// TODO: Write the Heuristic function here.
// Calculate the manhattan distance
int Heuristic(int x1,int y1,int x2,int y2){
  	return abs(x1-x2) + abs(y1-y2);
}
```



### Pass by Reference

In the previous exercises, you've written functions that accept and return various kinds of objects. However, in all of the functions you've written so far, the objects returned by the function are different from the objects provided to the function. In other words, when the function is called on some data, a copy of that data is made, and the function operates on a copy of the data instead of the original data. This is referred to as pass by value, since only a copy of the values of an object are passed to the function, and not the actual objects itself.

```cpp
#include <iostream>
#include <string>
using std::cout;
using std::string;

int MultiplyByTwo_passbyvalue(int i) {
    i = 2*i;
    return i;
}

int MultiplyByTwo_passreference(int &i) {
    i = 2*i;
    return i;
}

int MultiplyByTwo_passpointer(int *i) {
    *i = 2*(*i);
    return *i;
}

void DoubleString(string &value) {
    // Concatentate the string with a space and itself.
    value = value + " " + value;
}

int main() {
    //Passing Values
    int a = 5;
    cout << "The int a equals: " << a << "\n";
    int b = MultiplyByTwo_passbyvalue(a);
    cout << "The int b equals: " << b << "\n";
    cout << "The int a still equals: " << a << "\n";

    //Passing ref
    int c = 5;
    cout << "The int c equals: " << c << "\n";
    int d = MultiplyByTwo_passreference(c);
    cout << "The int d equals: " << d << "\n";
    cout << "The int c equals: " << c << "\n";
    
  	//pass pointer in C code
    int e = 5;
    cout << "The int e equals: " << e << "\n";
    int f = MultiplyByTwo_passpointer(&e);
    cout << "The int f equals: " << f << "\n";
    cout << "The int e equals: " << e << "\n";


    //Passing ref
    string s = "Hello";
    cout << "The string s is: " << s << "\n";
    DoubleString(s);
    cout << "The string s is now: " << s << "\n";
}
```

Output:

```
The int a equals: 5
The int b equals: 10
The int a still equals: 5
The int c equals: 5
The int d equals: 10
The int c equals: 10
The int e equals: 5
The int f equals: 10
The int e equals: 10
The string s is: Hello
The string s is now: Hello Hello
```

### Adding Nodes to the Open Vector

Writing the `AddToOpen() ` function

As you've seen from Sebastian's explanation of A* search, the search algorithm keeps a list of potential board cells to search through. In this implementation of A*, we will refer to a board cell along with it's `g ` and `h ` values as a *node* . In other words, each node will consist of the following values which are needed for the A* algorithm:

- an **x** coordinate,
- a **y** coordinate,
- the **g** value (or *cost* ) that has accumulated up to that cell,
- the **h** value for the cell, given by the heuristic function.

In the code, nodes will be implemented with the type `vector<int> `, and should have the form `{x, y, g, h} ` for `int `s x, y, g, and h. Also, the open list will be implemented as a C++ vector (of type `vector<vector<int>> `). The goal in this exercise is for you to write a helper function for your A* Search which will add nodes to the open vector and mark them as visited in the grid.

```cpp
// 新增 kClosed
enum class State {kEmpty, kObstacle, kClosed};

// TODO: Write the AddToOpen function here.
void AddToOpen(int x, int y, int g, int h, vector<vector<int>> &open_nodes, vector<vector<State>> &grid){
    //Create a vector<int> node with the form {x, y, g, h} and push the node to the back of the open vector.
    vector<int> node{x,y,g,h};
    open_nodes.push_back(node);
    grid[x][y] = State::kClosed;
}
```



### Initialize the Open Vector

Filling out the `Search() ` function

In this exercise, you will begin implementing the body of the `Search `function. In particular, you will take the arguments that are passed to the search function, get the x, y, g, and h values for the first node, and then add the first node to the open vector.

#### To Complete This Exercise:

1. Initialize variables with the starting node values as follows:

- `x` and `y ` are given by the `init ` variable values,
- Set the initial cost `g ` = 0,
- `h ` is given by `Heuristic ` function.

2. Add first node to open vector using the `AddToOpen ` function by passing the node values: `x `, `y `, `g `, and `h `, along with the `open ` and `grid ` vectors.



```cpp
/**
 * Implementation of A* search algorithm
 */
vector<vector<State>> Search(vector<vector<State>> grid, int init[2], int goal[2]) {
  // Create the vector of open nodes.
  vector<vector<int>> open {};

  // TODO: Initialize the starting node.
  int x = init[0];
  int y = init[1];
  int g = 0;
  int h = Heuristic(x,y,goal[0],goal[1]);

  // TODO: Use AddToOpen to add the starting node to the open vector.
  // We immediately treat the init node as the first open node
  AddToOpen(x,y,g,h,open,grid);

  cout << "No path found!" << "\n";
  return std::vector<vector<State>>{};
}
```



### Create a Comparison Function

Before you can use the vector of open nodes to expand the A* search, you will first need to be able to sort the vector. Since the vector contains nodes `{x, y, g, h} `, and there is no standard library function to sort these types of vectors, you will begin by writing a function which compares two nodes to determine their order.

This function is a helper function for the `CellSort() `function you will write later, so it is not shown on the code structure diagram.

#### To Complete This Exercise

Write a function `bool Compare ` that accepts two nodes of type `vector<int> ` as arguments. It should return a boolean `true ` if the f-value of the first argument is greater than the f-value of the second, and it should return `false ` otherwise. Recall that the f-value is the sum of the cost and heuristic: `f = g + h `.

```cpp
// TODO: Write function to compare the f-value of two nodes here
//It should return a boolean true if the f-value of the first argument is greater than the f-value of the second,
bool Compare(vector<int> &node1, vector<int> &node2){
    return  (node1[2] + node1[3] > node2[2] + node2[3]);
}
```



### Write a While Loop for the A* Algorithm

Writing the `while `loop for the search

![loop](../../assets/loop.png)



Now on to some of the core functionality of the A* search algorithm. A* search works by sorting the open list using the f-value, and using the node with the lowest f-value as the next node in the search. This process continues until the goal node has been found or the open list runs out of nodes to use for searching.

In this exercise, you will implement the primary `while ` loop in the algorithm which carries out the process described above:

#### To Complete This Exercise

Complete all of the TODOs in the pseudocode below. These are also marked directly in the exercise code.

```
  // TODO: while open vector is non empty {
    // TODO: Sort the open list using `CellSort`, and get the current node.

    // TODO: Get the x and y values from the current node,
    // and set grid[x][y] to kPath.

    // TODO: Check if you've reached the goal. If so, return grid.


    // If we're not done, expand search to current node's neighbors. This step will be completed in a later quiz.
    // ExpandNeighbors

  //} // TODO: End while loop
```

**Note:** We've included a header and a function to sort the open vector:

- `#include <algorithm>`
- `std::sort`
- `CellSort`

The `CellSort ` function uses the `Compare ` function you wrote previously to determine the sorting order. The `CellSort ` function contains two operators that you haven't seen before: `* ` and `-> `. These operators have to do with C++ pointers, which you will learn about in the next lesson. Don't worry about them for now!



```cpp
#include <algorithm>  // for sort
using std::sort;

// kPath
enum class State {kEmpty, kObstacle, kClosed, kPath};

/**
 * Compare the F values of two cells.
 */
bool Compare(const vector<int> a, const vector<int> b) {
  int f1 = a[2] + a[3]; // f1 = g1 + h1
  int f2 = b[2] + b[3]; // f2 = g2 + h2
  return f1 > f2;
}

/**
 * Sort the two-dimensional vector of ints in descending order.
 */
void CellSort(vector<vector<int>> *v) {
  sort(v->begin(), v->end(), Compare);
}

/**
 * Implementation of A* search algorithm
 */
vector<vector<State>> Search(vector<vector<State>> grid, int init[2], int goal[2]) {
  // Create the vector of open nodes.
  vector<vector<int>> open {};

  // Initialize the starting node.
  int x = init[0];
  int y = init[1];
  int g = 0;
  int h = Heuristic(x, y, goal[0],goal[1]);
  AddToOpen(x, y, g, h, open, grid);
  /*
  // TODO: while open vector is non empty {
    // TODO: Sort the open list using CellSort, and get the current node.

    // TODO: Get the x and y values from the current node,
    // and set grid[x][y] to kPath.

    // TODO: Check if you've reached the goal. If so, return grid.


    // If we're not done, expand search to current node's neighbors. This step will be completed in a later quiz.
    // ExpandNeighbors

  //} // TODO: End while loop
  */

  while (open.size() > 0){
      //sort all open list by f value
      CellSort(&open);
      //get the min f value node, the node is where we will go
      //because the Compare get the decending order , the lastest node is the min-f node
      vector<int> curminfnode = open.back();;
      open.pop_back();
      int curx = curminfnode[0];
      int cury = curminfnode[1];
      grid[curx][cury] = State::kPath;

      if (curx == goal[0] && cury == goal[1])
        return grid;

        // If we're not done, expand search to current node's neighbors.
        // ExpandNeighbors

  }

  // We've run out of new nodes to explore and haven't found a path.
  cout << "No path found!" << "\n";
  return std::vector<vector<State>>{};
}

```



### Check For Valid Neighbors

The last part of the A* algorithm to be implemented is the part that adds neighboring nodes to the open vector. In order to expand your A* search from the current node to neighboring nodes, you first will need to check that neighboring grid cells are not closed, and that they are not an obstacle. In this exercise, you will write a function `CheckValidCell `that does exactly this.

#### To Complete This Exercise

Write a function `bool CheckValidCell ` that accepts two `int`s for the x and y coordinates and a reference to the `grid `. The function should do two things:

1. Check that the (x, y) coordinate pair is on the grid.
2. Check that the grid at (x, y) is `kEmpty `(this is the default case if the grid cell is not `kClosed ` or a `kObstacle `).
   If both of these conditions are true, then `CheckValidCell ` should return `true `. Otherwise, it should return `false `.

```cpp
// TODO: Write CheckValidCell here. Check that the
// cell is on the grid and not an obstacle (i.e. equals kEmpty).
bool CheckValidCell(int x, int y,vector<vector<State>> &grid){

/*
1.Check that the (x, y) coordinate pair is on the grid.
2.Check that the grid at (x, y) is kEmpty (this is the default case if the grid cell is not kClosed or a kObstacle).

If both of these conditions are true, then CheckValidCell should return true. Otherwise, it should return false.
*/

  if ( x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() ){
      if (State::kEmpty == grid[x][y]){
          return true;
      }
  }
  
  return false;
}
```



# Constants

In [*A Tour of C++* ](http://www.stroustrup.com/Tour.html), Bjarne Stroustrup writes:

C++ supports two notions of immutability:

- `const `: meaning roughly " I promise not to change this value."…The compiler enforces the promise made by `const `….

- `constexpr `: meaning roughly "to be evaluated at compile time." This is used primarily to specify constants…



This example highlights how to use const to promise not to modify a variable, even though the variable can only be evaluated at run time. The example also show how to use constexpr to guarantee that a variable can be evaluated at compile time.

```cpp
#include <iostream>
#include <vector>

//j can cowork with a non-const i, but k can't
void example1(){
    int i;
    std::cout << "Enter an integer value for i: ";
    std::cin >> i;
    const int j = i * 2;  // "j can only be evaluated at run time."
                          // "But I promise not to change it after it is initialized."

    constexpr int k = 3;  // "k, in contrast, can be evaluated at compile time."

    std::cout << "j = " << j << "\n";
    std::cout << "k = " << k << "\n";
}


void example2(){
    const int i = 2; // "I promise not to change this."
    i++;             // "I just broke my promise."

    //will get error
    //main.cpp: In function ‘void example2()’:
    //main.cpp:41:6: error: increment of read-only variable ‘i’
    //     i++;             // "I just broke my promise."
}

void example3(){

    constexpr int i = 2;  // "i can be evaluated at compile time."
    i++;                  // "But changing a constexpr variable triggers an error."


    //main.cpp: In function ‘void example3()’:
    //main.cpp:53:6: error: increment of read-only variable ‘i’
    //     i++;                  // "But changing a constexpr variable triggers an error."

}


void example4(){
    //The compiler will catch a constexpr variable that cannot be evaluated at compile time.
    int i;
    std::cout << "Enter an integer value for i: ";
    std::cin >> i;
    constexpr int j = i * 2;  // "j can only be evaluated at run time, because i will get the value in run time."
                              // "constexpr must be evaluated at compile time."
                              // "So this code will produce a compilation error."

}


/*
A common usage of const is to guard against accidentally changing a variable,
especially when it is passed-by-reference as a function argument.
*/

int sum(const std::vector<int> &v)
{
    int sum = 0;
    for(int i : v)
        sum += i;
    return sum;
}

/*
The major difference between const and constexpr, is that constexpr must be evaluated at compile time.
*/

int main()
{
    example1();
    //example2();
    //example3();
    //example4();
    std::vector<int> v {0, 1, 2, 3, 4};
    std::cout << sum(v) << "\n";
}
```



### Expand the A* Search to Neighbors

Writing the `ExpandNeighbors() ` function

You are ready to expand your A* search to neighboring nodes and add valid neighbors to the open vector. In this exercise, you will write an `ExpandNeighbors ` function that takes care of this functionality for you.

#### To Complete This Exercise

Write a `void ExpandNeighbors `function that accepts references to the following:

- The current node,
- the open vector,
- the grid, 
- and an int array for the goal coordinates.

The `ExpandNeighbors ` function should implement the functionality given in the pseudocode below:

```
// TODO: ExpandNeighbors {

  // TODO: Get current node's data.

  // TODO: Loop through current node's potential neighbors.

    // TODO: Check that the potential neighbor's x2 and y2 values are on the grid and not closed.

      // TODO: Increment g value, compute h value, and add neighbor to open list.

// } TODO: End function
```

**Note:** we have provided directional deltas in the form of a 2D [array ](https://www.programiz.com/cpp-programming/arrays). An array is a C++ container much like a vector, although without the ability to change size after initialization. Arrays can be accessed and iterated over just as vectors.

In the exercise, you can iterate over these `delta ` values to check the neighbors in each direction:

```
// directional deltas
const int delta[4][2]{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
```



```cpp
#include <algorithm>  // for sort
using std::sort;

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using std::cout;
using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;
using std::abs;

enum class State {kEmpty, kObstacle, kClosed, kPath};

// directional deltas, up,left,down,right
const int delta[4][2]{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};


/*
1.board

rowA = i,1,0,0,0,0,->ParseLine() only get rowA data, 0,1,0,0,0,0, size 6 = y direction
rowB = 0,1,0,0,0,0,
rowC = 0,1,0,0,0,0,
rowD = 0,1,0,0,0,0,
rowE = 0,0,0,0,1,g,


ReadBoardFile() append rowA -> rowE as grid. size 5 = x direction

so, the size becomes..

grid[comes from ReadBoardFile() size 5][comes from ParseLine() size 6]
turn to index
grid[0~4][0~5] or we can treat as gird[x][y]

goal point (4,5)
init point (0,0)

*/
//read char as the future cols, 0~5 = size 6
vector<State> ParseLine(string line) {
    istringstream sline(line);
    int n;
    char c;
    vector<State> row;
    while (sline >> n >> c && c == ',') {
      if (n == 0) {
        row.push_back(State::kEmpty);
      } else {
        row.push_back(State::kObstacle);
      }
    }
    return row;
}

//append rows as the future rows, 0~4 = size 5
vector<vector<State>> ReadBoardFile(string path) {
  ifstream myfile (path);
  vector<vector<State>> board{};
  if (myfile) {
    string line;
    while (getline(myfile, line)) {
      vector<State> row = ParseLine(line);
      board.push_back(row);
    }
  }
  return board;
}


/**
 * Compare the F values of two cells.
 */
bool Compare(const vector<int> a, const vector<int> b) {
  int f1 = a[2] + a[3]; // f1 = g1 + h1
  int f2 = b[2] + b[3]; // f2 = g2 + h2
  return f1 > f2;
}


/**
 * Sort the two-dimensional vector of ints in descending order.
 */
void CellSort(vector<vector<int>> *v) {
  sort(v->begin(), v->end(), Compare);
}


// Calculate the manhattan distance
int Heuristic(int x1, int y1, int x2, int y2) {
  return abs(x2 - x1) + abs(y2 - y1);
}


/**
 * Check that a cell is valid: on the grid, not an obstacle, and clear.
 */
bool CheckValidCell(int x, int y, vector<vector<State>> &grid) {
  bool on_grid_x = (x >= 0 && x < grid.size());
  bool on_grid_y = (y >= 0 && y < grid[0].size());
  if (on_grid_x && on_grid_y)
    return grid[x][y] == State::kEmpty;//return T or F
  return false;
}


/**
 * Add a node to the open list and mark it as open.
 */
void AddToOpen(int x, int y, int g, int h, vector<vector<int>> &openlist, vector<vector<State>> &grid) {
  // Add node to open vector, and mark grid cell as closed.
  openlist.push_back(vector<int>{x, y, g, h});
  grid[x][y] = State::kClosed;
}


/**
 * Expand current nodes's neighbors and add them to the open list.
 */
// TODO: ExpandNeighbors(arguments) {

  // TODO: Get current node's data.

  // TODO: Loop through current node's potential neighbors.

    // TODO: Check that the potential neighbor's x2 and y2 values are on the grid and not closed.

      // TODO: Increment g value, compute h value, and add neighbor to open list.

// } TODO: End the function

/*
input:
reference of ...
    The current node,
    the open vector,
    the grid, and
    an int array for the goal coordinates.
*/
void ExpandNeighbors(vector<int> &current_node, int *goal, vector<vector<int>> &openlist,vector<vector<State>> &grid){

    //Get current node's data.
    int curx = current_node[0];
    int cury = current_node[1];
    int curg = current_node[2];
    int curh = current_node[3];
    int newg = curg + 1;
    cout << __func__ << ", cru x:"<<curx<<", cur y:"<<cury<<"\n";
    //Loop through current node's potential neighbors.
    for(int i = 0; i < 4; i++){

        int poetential_x = curx +  delta[i][0];
        int poetential_y = cury +  delta[i][1];

        //Check that the potential neighbor's x2 and y2 values are on the grid and not closed.
        // if the point is State::kEmpty (which means not kObstcal, kPath)
        if (CheckValidCell(poetential_x, poetential_y, grid)){
            //Increment g value, compute h value, and add neighbor to open list
            //for future use.
            int newh =Heuristic(poetential_x,poetential_y,goal[0],goal[1]);
            cout << poetential_x << poetential_y << goal[0] << goal[1] << newg << newh << "\n";
            AddToOpen(poetential_x, poetential_y, newg, newh, openlist, grid);

        }
    }

}



/**
 * Implementation of A* search algorithm
 */
vector<vector<State>> Search(vector<vector<State>> grid, int init[2], int goal[2]) {
  // Create the vector of open nodes.
  vector<vector<int>> open {};

  // Initialize the starting node.
  int x = init[0];
  int y = init[1];
  int g = 0;
  int h = Heuristic(x, y, goal[0],goal[1]);
  AddToOpen(x, y, g, h, open, grid);

  while (open.size() > 0) {
    // Get the next node
    CellSort(&open);
    auto current = open.back();
    open.pop_back();
    x = current[0];
    y = current[1];
    grid[x][y] = State::kPath;

    // Check if we're done.
    if (x == goal[0] && y == goal[1]) {
      return grid;
    }

    // If we're not done, expand search to current node's neighbors.
    ExpandNeighbors(current, goal, open, grid);
  }

  // We've run out of new nodes to explore and haven't found a path.
  cout << "No path found!" << "\n";
  return std::vector<vector<State>>{};
}


string CellString(State cell) {
  switch(cell) {
    case State::kObstacle: return "⛰️   ";
    case State::kPath: return "🚗   ";
    case State::kEmpty: return "E   ";
    case State::kClosed: return "C   ";
    default: return "?   ";
  }
}


void PrintBoard(const vector<vector<State>> board) {
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[i].size(); j++) {
      cout << CellString(board[i][j]);
    }
    cout << "\n";
  }
}

#include "test.cpp"

int main() {
  int init[2]{0, 0};
  int goal[2]{4, 5};
  auto board = ReadBoardFile("1.board");
  PrintBoard(board);

  auto solution = Search(board, init, goal);
  PrintBoard(solution);
  // Tests
  TestHeuristic();
  TestAddToOpen();
  TestCompare();
  TestSearch();
  TestCheckValidCell();
  TestExpandNeighbors();
}
```

Output:

```
E   ⛰️   E   E   E   E   
E   ⛰️   E   E   E   E   
E   ⛰️   E   E   E   E   
E   ⛰️   E   E   E   E   
E   E   E   E   ⛰️   E   
ExpandNeighbors, cru x:0, cur y:0
104518
ExpandNeighbors, cru x:1, cur y:0
204527
ExpandNeighbors, cru x:2, cur y:0
304536
ExpandNeighbors, cru x:3, cur y:0
404545
ExpandNeighbors, cru x:4, cur y:0
414554
ExpandNeighbors, cru x:4, cur y:1
424563
ExpandNeighbors, cru x:4, cur y:2
324574
434572
ExpandNeighbors, cru x:4, cur y:3
334583
ExpandNeighbors, cru x:3, cur y:3
234594
344592
ExpandNeighbors, cru x:3, cur y:4
2445103
3545101
ExpandNeighbors, cru x:3, cur y:5
2545112
4545110
🚗   ⛰️   E   E   E   E   
🚗   ⛰️   E   E   E   E   
🚗   ⛰️   E   C   C   C   
🚗   ⛰️   C   🚗   🚗   🚗   
🚗   🚗   🚗   🚗   ⛰️   🚗
```



### Arrays

In the previous exercise, we included an array of directional deltas for convenience:

```cpp
// directional deltas
const int delta[4][2]{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
```

Arrays are a lower level data structure than vectors, and can be slightly more efficient, in terms of memory and element access. However, this efficiency comes with a price. Unlike vectors, which can be extended with more elements, arrays have a fixed length. Additionally, arrays may require careful memory management, depending how they are used.

The example in the project code is a good use case for an array, as it was not intended to be changed during the execution of the program. However, a vector would have worked there as well.



### Adding a Start and End to the Board

In this exercise, you will add a `🚦 ` for the beginning of the path, and a `🏁 ` for the end.

#### To Complete This Exercise

1. Add a kStart and kFinish to the `State ` enum.
2. Set the grid cell to kStart for the initial coordinates and kFinish for the goal coordinates. This will happen in the `Search ` function.
3. In `CellString `, add cases to return `"🚦 " ` for kStart and `"🏁 " ` for kFinish.



```cpp
// TODO: Add kStart and KFinish enumerators to the State enum.
enum class State {kStart, kFinish, kEmpty, kObstacle, kClosed, kPath};

string CellString(State cell) {
  switch(cell) {
      case State::kObstacle: return "⛰️   ";
      case State::kPath: return "🚗   ";
      case State::kEmpty: return "E   ";
      case State::kClosed: return "C   ";
      case State::kStart: return "🚦   ";
      case State::kFinish: return "🏁   ";
      default: return "?   ";
    // TODO: Add cases to return "🚦   " for kStart
    // and "🏁   " for kFinish.

  }
}
```

Output:

```
🚦   ⛰️   E   E   E   E   
🚗   ⛰️   E   E   E   E   
🚗   ⛰️   E   C   C   C   
🚗   ⛰️   C   🚗   🚗   🚗   
🚗   🚗   🚗   🚗   ⛰️   🏁   
```

