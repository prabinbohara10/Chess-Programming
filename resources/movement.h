#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include<vector>

#include"chessboard.h"

using namespace std;

using namespace sf;
extern int castling_possible_arr[2][3];
extern int en_passant_possible_arr[4];

extern int mouse_pos_x;
extern int mouse_pos_y;

extern	bool w_check;
extern  bool b_check;

class movement
{
    private:

        vector <pair<int,int>> king_direction={ 
		{-1,-1},{-1,0},{-1,1},
		{0,-1},    {0,1},
		{1,-1},{1,0},{1,1},
        {-2,-1},{-2,1},
		{-1,2},{1,2},
		{2,1},{2,-1},
		{1,-2},{-1,-2}
	    };
        Texture tex;
        Sprite sp;
        chessboard c1;
        
    public:
        int is_move_success(RenderWindow (&window),RectangleShape (&square)[8][8],int(&game_array)[8][8],
        vector<vector<int>> &current_possible,int &current_side, int current_row,int current_col);

        void possible_en_passant(int(&game_array)[8][8],vector<vector<int>> &current_possible,int moved_index);
        void find_check(int(&game_array)[8][8],RenderWindow (&window),RectangleShape (&square)[8][8]);
};