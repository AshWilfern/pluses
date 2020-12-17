#pragma once
class MCell
{
public:
	bool down();
	bool right();
private:
	bool m_down;
	bool m_right;
	MCell() { m_down = false; m_right = false; };

	friend class Maze;
};

