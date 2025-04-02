#include <NonBlockingGame.h>

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace bridges::game;

// TODO:
// Create a cell class that holds each cells position, a bool for if it is a wall or open cell
// Also have values for g, h, f, and parent as helpers for astar
class MazeCell {
    // TODO Implement needed properties and functions to represent a cell on the grid

    // Should incldude
    // Constructors
    // Properties for g, h, and f values used in AStar
    // Property to track if this cell contains a wall
    // Property to track if this cell has been discovered for AStar
    // A reference to this cells parent for AStar
};

class Pathfind : public NonBlockingGame {
  private:
    const vector<vector<int>> DIRECTIONS = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

  protected:
    static const vector<int> size;
    vector<MazeCell> cells;

    // Pathfinder holds the position of the AStar algorithm
    // It's also used for looping back and drawing the best path using its parents
    MazeCell pathfinder;
    bool finished = false;

    vector<int> goal;

    // Open list and closed list used for AStar
    priority_queue<MazeCell> openList;
    vector<MazeCell> closedList;

  public:
    Pathfind(int assignmentID, std::string username, std::string apikey)
      : NonBlockingGame(assignmentID, username, apikey, size[0], size[1]) {
          setTitle("AStar Maze");
          setDescription("Build an algorithm that finds the shortest path out of the maze from your starting point.");
      }

  protected:
    virtual void initialize() override {
      // TODO:
      // Initialize the pathfinder cell which represents
      // a position on the grid.

      // Initialize the goal cell

      // Populate the cells list for the entire grid

      // Generate a maze on the grid using any maze algorithm
      // Set cells that are walls using your cell implementation
    }

    virtual void gameLoop() override {
      try {
        // TODO:
        // Check input for resetting the board

        // Run one step of the AStar algorithm each time process is called.
        // Update the pathfinders position to the position of the current step

        // Draw the grid including different colors or symbols for walls,
        // empty cells, the pathfinder, and the end goal.
      }
      catch (char const * e) {
        cout << e << endl;
      }
    }
};

const vector<int> Pathfind::size = { 31, 31 };

int main(int argc, char *argv[]) {
  Pathfind nbg(112, "BRIDGES_USER_ID", "BRIDGES_API_KEY");

  nbg.start();

  return 0;
}
