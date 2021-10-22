#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

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


using namespace std;
using namespace sf;

extern vector<int> bcaptured_pieces;
extern vector<int> wcaptured_pieces;

class startmenu
{
private:
    SoundBuffer click,hoover;
	Music menu_music;
	Sound click1,hoover1;
	int hov=0;



public:

	void mainmenu();
	
	void draw(RenderWindow& menu);
	Font font;
	Text text;
	//Music music;
	Texture background,play,exit,option,menu1,bplay,boption,bexit,back,bback,online,bonline,offline,boffline;
	Sprite sbackground, splay, soption, sexit,smenu1,sbplay,sboption,sbexit,sback,sbback,sonline,sbonline,soffline,sboffline;
	Texture back1,bback1,bmusicon,bmusicoff,soundon,soundoff,bbmusicon,bbmusicoff,bsoundon,bsoundoff;
	Sprite sback1,sbback1,sbmusicon,sbmusicoff,ssoundon,ssoundoff,sbbmusicon,sbbmusicoff,sbsoundon,sbsoundoff;
	void connection(int x, int y, RenderWindow& menu);
	void main_game();
	void mode_of_game();
	void setting();
	void drawmode(RenderWindow& menu);//helps to draw icon in mode window
	void drawsetting(RenderWindow& menu);//helps to draw icon in setting window

	
};
