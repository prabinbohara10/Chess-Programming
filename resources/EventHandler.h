#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include<vector>

#include "chessboard.h"
#include "pawn.h"
#include "rook.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"
#include "knight.h"
#include"movement.h"
#include"startmenu.h"

using namespace sf;


//GLOBAL ENTITIES:	
extern int mouse_pos_x;
extern int mouse_pos_y;

extern	bool w_check;
extern  bool b_check;

extern int b_row,b_col,w_row,w_col;

class EventHandler
{
	int current_side_to_play=0;//0 for white and 1 for black:
    int clicked_piece;//to know clicked piece
    int row_no,col_no; //to know location of clicked piece:
    chessboard c1;
	pawn p1;
	rook r1;
	knight n1;
	bishop b1;
	queen q1;
	king k1;
    
	movement movement1;
	Texture tex;//to display pieces:
	Sprite sp;

	vector<vector<int>> current_possible;//to store the information of all possible moves of particular piece:
	
    Event event1;
	 


	
		
public:

    
	

   //passing game window, game_array and base squares:
   void event_function(RenderWindow &window,int (&game_array)[8][8],RectangleShape (&square)[8][8]);

   void gamesidescreen(RenderWindow &window,int x, int y);
   
    


};//EventHandler class: