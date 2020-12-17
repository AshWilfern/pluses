#include <iostream>

#include "MCell.h"
#include "Maze.h"

int main()
{
    int height = 5;
    int width = 5;
    Maze* maze = new Maze(height, width);
    int i = 0;
    for (int j = 0; j < width; j++)
    {
        if ((i + j) % 2 == 0) 
        {
            maze->makeConnection(i, j, i, j + 1);
        }
        else
        {
            maze->makeConnection(i, j, i + 1, j);
            i += 1;
            j -= 1;
        }
    }
    maze->printMaze();
}