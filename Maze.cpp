#include "MCell.h"
#include "Maze.h"

#include <iostream>

Maze::Maze(int n, int m)
{
	m_field = new MCell[n * m];
	m_columns_count = m;
	m_rows_count = n;
}

Maze::~Maze()
{
	delete[] m_field;
}

const MCell& Maze::cell(int i, int j) const
{
	return m_field[i * m_columns_count + j];
}

bool  Maze::hasConnection(int i1, int j1, int i2, int j2)
{
	int idx1 = i1 * m_columns_count + j1;
	int idx2 = i2 * m_columns_count + j2;
	if (idx1 < idx2)
	{
		if (i1 < i2) return m_field[idx1].down();
		if (j1 < j2) return m_field[idx1].right();
	}
	else
	{
		if (i1 > i2) return m_field[idx2].down();
		if (j1 > j2) return m_field[idx2].right();
	}
}

bool Maze::makeConnection(int i1, int j1, int i2, int j2)
{
	int idx1 = i1 * m_columns_count + j1;
	int idx2 = i2 * m_columns_count + j2;
	if (idx1 < idx2)
	{
		if (i1 < i2)
		{
			m_field[idx1].m_down = true;
			return m_field[idx1].down();
		}
		if (j1 < j2)
		{
			m_field[idx1].m_right = true;
			return m_field[idx1].right();
		}
	}
	else
	{
		if (i1 > i2)
		{
			m_field[idx2].m_down = true;
			return m_field[idx2].down();
		}
		if (j1 > j2)
		{
			m_field[idx2].m_right = true;
			return m_field[idx2].right();
		}
	}
}

bool Maze::removeConnection(int i1, int j1, int i2, int j2)
{
	int idx1 = i1 * m_columns_count + j1;
	int idx2 = i2 * m_columns_count + j2;
	if (idx1 < idx2)
	{
		if (i1 < i2)
		{
			m_field[idx1].m_down = false;
			return m_field[idx1].down();
		}
		if (j1 < j2)
		{
			m_field[idx1].m_right = false;
			return m_field[idx1].right();
		}
	}
	else
	{
		if (i1 > i2)
		{
			m_field[idx2].m_down = false;
			return m_field[idx2].down();
		}
		if (j1 > j2)
		{
			m_field[idx2].m_right = false;
			return m_field[idx2].right();
		}
	}
}

void Maze::printMaze()
{
	int dir;
	for (int i = 0; i < m_rows_count; i++)
	{
		for (int j = 0; j < m_columns_count; j++)
		{
			dir = 0;
			if (i > 0 && hasConnection(i, j, i - 1, j)) dir |= up;
			if (i < m_rows_count - 1 && hasConnection(i, j, i + 1, j)) dir |= down;
			if (j > 0 && hasConnection(i, j, i, j - 1)) dir |= left;
			if (j < m_columns_count - 1 && hasConnection(i, j, i, j + 1)) dir |= right;
			switch (dir)
			{
			case (up_down):
				std::cout << char(179);
				break;
			case (up_left):
				std::cout << char(217);
				break;
			case (down_left):
				std::cout << char(191);
				break;
			case (up_down_left):
				std::cout << char(180);
				break;
			case (up_right):
				std::cout << char(192);
				break;
			case (down_right):
				std::cout << char(218);
				break;
			case (up_down_right):
				std::cout << char(195);
				break;
			case (left_right):
				std::cout << char(196);
				break;
			case (up_left_right):
				std::cout << char(193);
				break;
			case (down_left_right):
				std::cout << char(194);
				break;
			case (all):
				std::cout << char(197);
				break;
			default:
				std::cout << char(248);
				break;
			}
		}
		std::cout << std::endl;
	}
}