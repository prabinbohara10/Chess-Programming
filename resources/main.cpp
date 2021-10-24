
#include <SFML/Graphics.hpp>

#include<iostream>
#include<vector>
#include "chessboard.h"
#include "pawn.h"
#include "rook.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"
#include "knight.h"
#include "EventHandler.h"
#include"startmenu.h"

using namespace std;

int Added_width = 160;

vector<int> bcaptured_pieces;
vector<int> wcaptured_pieces;

int mouse_pos_x;
int mouse_pos_y;


SoundBuffer click,hoover,pmove;
Music menu_music;
Sound click1,hoover1,move1;
bool is_sound = true,is_music = true;

int main()
{
	if (!click.loadFromFile("../resources/music/ClickChessa.wav"))
	{
		cout << "nosound"<<endl;
	}
	if (!hoover.loadFromFile("../resources/music/ClickChess.wav"))
	{
		cout << "nosound"<<endl;
	}
	if (!pmove.loadFromFile("../resources/music/SoundChess1.wav"))
	{
		cout << "nosound"<<endl;
	}
        
        
    
	if(!menu_music.openFromFile("../resources/music/musicMain.ogg"))
	{
		cout<<"error opening music file"<<endl;
	}
	menu_music.play();
	menu_music.setVolume(20.f);
	menu_music.setLoop(true);

	hoover1.setBuffer(hoover);
	hoover1.setVolume(20.f);

	click1.setBuffer(click);

	move1.setBuffer(pmove);
	
	
	startmenu startmenu1;
	startmenu1.mainmenu();

	
	


	return 0;
}
