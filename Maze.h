#pragma once
class Maze
{
public:
	Maze(int n, int m);
	~Maze();
	const MCell& cell(int i, int j) const;
	bool hasConnection(int i1, int j1, int i2, int j2);
	bool makeConnection(int i1, int j1, int i2, int j2);
	bool removeConnection(int i1, int j1, int i2, int j2);
	void printMaze();
private:
	MCell* m_field;
	int m_columns_count;
	int m_rows_count;
};

enum direction {
	non,
	up,
	down,
	up_down,
	left,
	up_left,
	down_left,
	up_down_left,
	right,
	up_right,
	down_right,
	up_down_right,
	left_right,
	up_left_right,
	down_left_right,
	all
};

