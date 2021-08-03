#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <vector>
#include "piece.h"
using namespace std;
using namespace sf;


class king
{
	vector <pair<int,int>> step_direction={
		{-1,-1},{-1,0},{-1,1},
		{0,-1},    {0,1},
		{1,-1},{1,0},{1,1}
		};
		
	piece piece1;
	int can_kill;
public:
	void showpath(RenderWindow& window, int(&board)[8][8],RectangleShape (&square)[8][8],int row,int col,
		int piece,vector<vector<int>> &current_possible,int current_side);
};

