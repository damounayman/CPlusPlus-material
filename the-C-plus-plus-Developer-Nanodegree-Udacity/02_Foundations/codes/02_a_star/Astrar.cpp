#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm> // for sort

using namespace std;
using std::sort;

enum class State
{
    kStart,
    kFinish,
    kEmpty,
    kObstacle,
    kClosed,
    kPath
};

// directional deltas, up,left,down,right
const int delta[4][2]{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

vector<vector<State>> ReadBoardFile(string path)
{

    ifstream file(path);
    vector<vector<State>> container_vec{};

    if (file)
    {
        string line;
        while (getline(file, line))
        {
            istringstream string_line(line);
            int n;
            char c;
            vector<State> temp_vec;
            while (string_line >> n >> c && c == ',')
            {
                if (n == 0)
                {
                    temp_vec.push_back(State::kEmpty);
                }
                else
                {
                    temp_vec.push_back(State::kObstacle);
                }
            }
            container_vec.push_back(temp_vec);
        }
    }
    return container_vec;
}

string CellString(State cell) {
  switch(cell) {
      case State::kObstacle: return "⛰️   ";
      case State::kPath: return "🚗   ";
      case State::kEmpty: return "E   ";
      case State::kClosed: return "C   ";
      case State::kStart: return "🚦   ";
      case State::kFinish: return "🏁   ";
      default: return "?   ";
  }
}

void PrintBoard(const vector<vector<State>> dd_vector)
{
    // prints the 2D vector passed by iterating over each row
    // and then each column in the row
    for (vector<State> d_vector : dd_vector)
    {
        for (State col : d_vector)
        {
            cout<<CellString(col);
            cout << "  ";
        }
        cout << "\n";
    }
}

// Calculate the manhattan distance
int Heuristic(int x1, int y1, int x2, int y2)
{
    return abs(x1 - x2) + abs(y1 - y2);
}

// Write the AddToOpen function here.
void AddToOpen(int x, int y, int g, int h, vector<vector<int>> &open_nodes, vector<vector<State>> &grid)
{
    // Create a vector<int> node with the form {x, y, g, h} and push the node to the back of the open vector.
    vector<int> node{x, y, g, h};
    open_nodes.push_back(node);
    grid[x][y] = State::kClosed;
}

// Write function to compare the f-value of two nodes here
// It should return a boolean true if the f-value of the first argument is greater than the f-value of the second,
/**
 * Compare the F values of two cells.
 */
bool Compare(const vector<int> a, const vector<int> b)
{
    int f1 = a[2] + a[3]; // f1 = g1 + h1
    int f2 = b[2] + b[3]; // f2 = g2 + h2
    return f1 > f2;
}

/**
 * Sort the two-dimensional vector of ints in descending order.
 */
void CellSort(vector<vector<int>> *v)
{
    sort(v->begin(), v->end(), Compare);
}

// cell is on the grid and not an obstacle (i.e. equals kEmpty).
bool CheckValidCell(int x, int y, vector<vector<State>> &grid)
{

    /*
    1.Check that the (x, y) coordinate pair is on the grid.
    2.Check that the grid at (x, y) is kEmpty (this is the default case if the grid cell is not kClosed or a kObstacle).

    If both of these conditions are true, then CheckValidCell should return true. Otherwise, it should return false.
    */

    if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size())
    {
        if (State::kEmpty == grid[x][y])
        {
            return true;
        }
    }

    return false;
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
void ExpandNeighbors(vector<int> &current_node, int *goal, vector<vector<int>> &openlist, vector<vector<State>> &grid)
{

    // Get current node's data.
    int curx = current_node[0];
    int cury = current_node[1];
    int curg = current_node[2];
    int curh = current_node[3];
    int newg = curg + 1;
    cout << __func__ << ", cru x:" << curx << ", cur y:" << cury << "\n";
    // Loop through current node's potential neighbors.
    for (int i = 0; i < 4; i++)
    {

        int poetential_x = curx + delta[i][0];
        int poetential_y = cury + delta[i][1];

        // Check that the potential neighbor's x2 and y2 values are on the grid and not closed.
        //  if the point is State::kEmpty (which means not kObstcal, kPath)
        if (CheckValidCell(poetential_x, poetential_y, grid))
        {
            // Increment g value, compute h value, and add neighbor to open list
            // for future use.
            int newh = Heuristic(poetential_x, poetential_y, goal[0], goal[1]);
            cout << poetential_x << poetential_y << goal[0] << goal[1] << newg << newh << "\n";
            AddToOpen(poetential_x, poetential_y, newg, newh, openlist, grid);
        }
    }
}

vector<vector<State>> Search(vector<vector<State>> grid, int initial_point[2], int goal_point[2])
{
    // Create the vector of open nodes.
    vector<vector<int>> open{};
    bool start = true;
    // Initialize the starting node.
    int x = initial_point[0];
    int y = initial_point[1];
    int g = 0;
    int h = Heuristic(x, y, goal_point[0], goal_point[1]);

    // Use AddToOpen to add the starting node to the open vector.
    // We immediately treat the init node as the first open node
    AddToOpen(x, y, g, h, open, grid);

    while (open.size() > 0)
    {
        // sort all open list by f value
        CellSort(&open);
        // get the min f value node, the node is where we will go
        // because the Compare get the decending order , the lastest node is the min-f node
        vector<int> curminfnode = open.back();
        ;
        open.pop_back();
        int curx = curminfnode[0];
        int cury = curminfnode[1];
        grid[curx][cury] = State::kPath;
        if(start){

            grid[x][y] = State::kStart;
            start = false;
        }

        if (curx == goal_point[0] && cury == goal_point[1])
        {
            grid[curx][cury] = State::kFinish;
            return grid;
        }
        // If we're not done, expand search to current node's neighbors.
        // ExpandNeighbors
        // If we're not done, expand search to current node's neighbors.
        ExpandNeighbors(curminfnode, goal_point, open, grid);
    }

    // We've run out of new nodes to explore and haven't found a path.
    cout << "No path found!"
         << "\n";
    return std::vector<vector<State>>{};
}

int main()
{
    // Declare 2D "init" and "goal" arrays with values {0, 0} and {4, 5} respectively.
    int init_point[2]{0, 0};
    int goal_point[2]{4, 5};

    auto board = ReadBoardFile("../board.csv");
    // TODO: Call Search with "board", "init", and "goal". Store the results in the variable "solution".
    auto solution = Search(board, init_point, goal_point);
    // TODO: Change the following line to pass "solution" to PrintBoard.
    PrintBoard(solution);
}