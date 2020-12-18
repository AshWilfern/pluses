#include <vector>
#include <iostream>

#include "MCell.h"
#include "Maze.h"
#include "MTreeNode.h"

void childrenCollector(Maze* maze, MTreeNode* tree, int maze_width, int maze_height, int i, int j);

int main()
{
    int width = 5;
    int height = 5;
    Maze* maze = new Maze(height, width);
    for (int d = 0; d < width; d++)
    {
        if (d > 0)
            for (int i = d - 1; i < height; i++)
                maze->makeConnection(i, d, i + 1, d);
        else
            for (int i = d; i < height; i++)
                maze->makeConnection(i, d, i + 1, d);
        for (int j = d; j < width;j++)
            maze->makeConnection(d, j, d, j + 1);
    }
    maze->printMaze();

    int i0 = 0;
    int j0 = 0;
    MTreeNode* tree = MTreeNode::beginTree(i0, j0);
    int* distanses = new int[width * height];
    int count = 0;
    for (int i = 0; i < width * height; i++) distanses[i] = 0;
    std::vector<MTreeNode*> queue;
    std::vector<bool> used (width * height);
    queue.push_back(tree);
    while (queue.size())
    {
        MTreeNode* node = queue.back();
        queue.pop_back();
        used[node->i() * width + node->j()] = true;
        childrenCollector(maze, node, width, height, node->i(), node->j());
        for (int k = 0; k < node->childCount(); k++)
        {
            if (!used[node->child(k)->i() * width + node->child(k)->j()])
                queue.push_back(node->child(k));
        }
        distanses[node->i() * width + node->j()] = node->distance();
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
            std::cout << distanses[i * width + j] << " ";
        std::cout << std::endl;
    }
}

void childrenCollector(Maze* maze, MTreeNode* tree, int maze_width, int maze_height, int i, int j)
{
    if (i > 0 && maze->hasConnection(i, j, i - 1, j)) tree->addChild(i - 1, j);
    if (i < maze_height - 1 && maze->hasConnection(i, j, i + 1, j)) tree->addChild(i + 1, j);
    if (j > 0 && maze->hasConnection(i, j, i, j - 1)) tree->addChild(i, j - 1);
    if (j < maze_width - 1 && maze->hasConnection(i, j, i, j + 1)) tree->addChild(i, j + 1);
}