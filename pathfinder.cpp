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
	//Andrew Beck
    // TODO Implement needed properties and functions to represent a cell on the grid
	private:
	int x, y; //position variables
	bool isWall; //determines if cell is a wall or not

	//used in pathfinder algorithm
	double g = 0.0;
	double h = 0.0;
	double f = 0.0; 

	//holds value of previous cell
	MazeCell* parent = nullptr 

	public:
	//constructor (doesn't include g, h, f, and parent because those values will never be different in class initialization)
	MazeCell(bool new_isWall, int new_x, int new_y) : isWall(new_isWall), x(new_x), y(new_y) {
		//class invariants
		if (x < 0) throw invalid_argument("No negative x values on the grid!");
		if (y < 0) throw invalid_argument("No negative y values on the grid!");
	}

	//getters
	int get_g const() {
		return g;
	}
	int get_h const() {
		return h;
	}
	int get_f const() {
		return f;
	}
	MazeCell* get_parent const() {
		return parent;
	}
	bool get_isWall const() {
		return isWall;
	}
	int get_x const() {
		return x;
	}
	int get_y const() {
		return y;
	}

	//setters
	void set_g (int new_g) {
		g = new_g;
	}
	void set_h (int new_h) {
		h = new_h;
	}
	void set_f (int new_f) {
		f = new_f;
	}
	void set_parent (MazeCell* new_parent) {
		parent = new_parent;
	}
	void set_isWall (bool new_isWall) {
		isWall = new_isWall;
	}
	void set_x (int newX) {
		if (x < 0) throw invalid_argument("No negative x values on the grid!");
    	x = newX;
  ` }
  ` void set_y (int newY) {
		if (y < 0) throw invalid_argument("No negative y values on the grid!");
    	y = newY;
  	}

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
      	// Justus Pettit
	  	int SIZE = 10;

      	// TODO:

      	// Initialize the pathfinder cell which represents
      	// a position on the grid.
      	pathfinder(1,1);

      	// Initialize the goal cell
      	MazeCell goal(SIZE-1,SIZE-1);

      	// Populate the cells list for the entire grid
	  	vector<vector<MazeCell>> map(vector<MazeCell>(SIZE),SIZE);

      	// Generate a maze on the grid using any maze algorithm
     	// Set cells that are walls using your cell implementation
		
    }

    virtual void gameLoop() override {
      try {
		//Andrew Beck
        // TODO:
        // Check input for resetting the board
		
        // Run one step of the AStar algorithm each time process is called.
        // Update the pathfinders position to the position of the current step
		void process () {
			//A star algorithm
		}

        // Draw the grid including different colors or symbols for walls,
        // empty cells, the pathfinder, and the end goal.
		void draw () {}
		/*  for (x size...) {
				for (y size...) {
					if (Mazecell.get_isWall() == true) {
						cout << "X"; //"X" means wall
					} else if (MazeCell.get_isWall() == false) {
						cout << " "; //" " means optional path
					}
				}
			}
			movecursor(pathfinder.y,pathfinder.x);
			cout << "O"; //"O" means pathfinder
			movecutsor(start.y,start.x);
			cout << "~"; //"~" means start
			movecursor(end.y,end.x);
			cout << "-"; //"-" means end
		}
			*/

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
