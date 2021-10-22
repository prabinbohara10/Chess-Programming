#include "startmenu.h"



void startmenu::mainmenu()
{
	RenderWindow menu(VideoMode(640, 400), "CHESS", Style::Close | Style::Titlebar);
    //if (!font.loadFromFile("Fonts/Metropolian-Display.ttf"))
	//{
		//jguyhuu
	//}
	//text.setFont(font);
	//text.setFillColor(Color::Blue);
	//text.setString("HELLO");
	//text.setPosition(width/2,height/2);



	background.loadFromFile("../resources/menu/background2.jpg");
	background.setSmooth("true");
	
	sbackground.setTexture(background);
	
	sbackground.setScale(0.5, 0.5);
    menu1.loadFromFile("../resources/menu/mai.png");
	menu1.setSmooth("true");
	smenu1.setTexture(menu1);
	smenu1.setPosition(640 / 2 - smenu1.getGlobalBounds().width/2, 20);
    smenu1.setScale(1.25, 1.25);
	play.loadFromFile("../resources/menu/play.png");
	play.setSmooth("true");
	splay.setTexture(play);
	splay.setPosition(640 / 2 - splay.getGlobalBounds().width/2-20, 80);
    splay.setScale(1.25, 1.25);
    option.loadFromFile("../resources/menu/setting.png");
	option.setSmooth("true");
    soption.setTexture(option);
	soption.setPosition(640 / 2 - soption.getGlobalBounds().width/2-20 , 160);
    soption.setScale(1.25, 1.25);
    exit.loadFromFile("../resources/menu/quit.png");
	exit.setSmooth("true");
    sexit.setTexture(exit);
	sexit.setPosition(640 / 2 - sexit.getGlobalBounds().width/2-20,240);
    sexit.setScale(1.25, 1.25);
    bplay.loadFromFile("../resources/menu/bplay.png");
	bplay.setSmooth("true");
	sbplay.setTexture(bplay);
	sbplay.setPosition(640 / 2 - sbplay.getGlobalBounds().width/2-20, 80);
    sbplay.setScale(1.25, 1.25);
    boption.loadFromFile("../resources/menu/bsetting.png");
	boption.setSmooth("true");
    sboption.setTexture(boption);
	sboption.setPosition(640 / 2 - sboption.getGlobalBounds().width/2-20 , 160);
    sboption.setScale(1.25, 1.25);
    bexit.loadFromFile("../resources/menu/bquit.png");
	bexit.setSmooth("true");
    sbexit.setTexture(bexit);
	sbexit.setPosition(640 / 2 - sbexit.getGlobalBounds().width/2-20, 240);
    sbexit.setScale(1.25, 1.25);


	if (!click.loadFromFile("../resources/music/ClickChessa.wav"))
	{
		cout << "nosound"<<endl;
	}
	if (!hoover.loadFromFile("../resources/music/ClickChess.wav"))
	{
		cout << "nosound"<<endl;
	}
        
        
    
	if(!menu_music.openFromFile("../resources/music/usicMain.ogg"))
	{
		cout<<"error opening music file"<<endl;
	}
	menu_music.play();
	menu_music.setLoop(true);
	



   
    
	


    bcaptured_pieces.clear();
	wcaptured_pieces.clear();
	

	while (menu.isOpen())
	{
		Event ev;
		while (menu.pollEvent(ev))
		{
			if (ev.type == Event::Closed)
				menu.close();
			if (ev.type == Event::KeyPressed && ev.key.code == Keyboard::Escape)
				menu.close();
			if (ev.type == Event::MouseButtonPressed && ev.mouseButton.button == Mouse::Left)
			{
				int x = Mouse::getPosition(menu).x;
				int y = Mouse::getPosition(menu).y;
				if (x >= 0 && x <= 640 && y >= 0 && y <= 400)
				{
				
					connection(x, y,menu);
				}
			}

		}
		menu.clear();
		draw(menu);
		menu.display();

		
	}


	/*
	if (!font.loadFromFile("Fonts/Metropolian-Display.ttf"))
	{
		//jguyhuu
	}
	text.setFont(font);
	text.setFillColor(Color::Red);
	text.setOutlineThickness(1);
	text.setString("Play");
	text.setPosition(300,100);
	*/

	

}


void startmenu::draw(RenderWindow& menu)
{
	
	menu.draw(sbackground);
    menu.draw(smenu1);
    int mousepos_x = Mouse::getPosition(menu).x;
	int mousepos_y= Mouse::getPosition(menu).y;
    if(splay.getGlobalBounds().contains(mousepos_x,mousepos_y))
    {
        if(hov==0)
		{
			hoover1.setBuffer(hoover);
		    hoover1.play();
		    
			hov = 1;

		}
		menu.draw(sbplay);
		

    }
    if(!splay.getGlobalBounds().contains(mousepos_x,mousepos_y))
    {
        menu.draw(splay);
		hov = 0;

    }
    if(soption.getGlobalBounds().contains(mousepos_x,mousepos_y))
    {
        //hoover1.setBuffer(hoover);
		//hoover1.play();
		menu.draw(sboption);

    }
    if(!soption.getGlobalBounds().contains(mousepos_x,mousepos_y))
    {
        menu.draw(soption);

    }
    if(sexit.getGlobalBounds().contains(mousepos_x,mousepos_y))
    {
        //hoover1.setBuffer(hoover);
		//hoover1.play();
		menu.draw(sbexit);

    }
    if(!sexit.getGlobalBounds().contains(mousepos_x,mousepos_y))
    {
        menu.draw(sexit);

    }
}
//connect the main menu with mode or setting menu
void startmenu::connection(int x, int y, RenderWindow& menu)
{
	if (splay.getGlobalBounds().contains(x, y))
	{
		//cout << "play" << endl;
		click1.setBuffer(click);
		click1.play();
		
    
		menu.close();
		mode_of_game();
       // game game2;
       // game2.gamescreen();
		
         //window.close();
	}
	if (soption.getGlobalBounds().contains(x, y))
	{
		//cout << "play" << endl;
		//click1.setBuffer(click);
		//click1.play();
		
    
		menu.close();
		setting();
       // game game2;
       // game2.gamescreen();
		
         //window.close();
	}
    if (sexit.getGlobalBounds().contains(x, y))
	{
		//cout << "play" << endl;
		//click1.setBuffer(click);
		//click1.play();
		menu.close();
    
		
        
	}
	
		
}

void startmenu::main_game()
{

	
	int game_array[8][8] = {
	  { -1,-2,-3,-4,-5,-3,-2,-1 },
	  { -6,-6,-6,-6,-6,-6,-6,-6 },
	  {  0, 0, 0, 0, 0, 0, 0, 0 },
	  {  0, 0, 0, 0, 0, 0, 0, 0 },
	  {  0, 0, 0, 0, 0, 0, 0, 0 },
	  {  0, 0, 0, 0, 0, 0, 0, 0 },
	  {  6, 6, 6, 6, 6, 6, 6, 6 },
	  {  1, 2, 3, 4, 5, 3, 2, 1 }
	};

	// int game_array[8][8]={
	//   { -1,0,-3,-4,-5,-3,0,-1 },
	//   { -6,6,-6,-6,-6,-6,6,-6 },
	//   {  0, 0, 0, 0, 0, 0, 0, 0 },
	//   {  0, 0, 0, 0, 0, 0, 0, 0 },
	//   {  0, 0, -6, 4, 0, 0, 0, 0 },
	//   {  0, 0, 0, 0, 0, 0, 0, 0 },
	//   {  -1, -6, 0, 0, 6, 0,-6, 6 },
	//   {  1, 0, 3, 4, 5, 0, 0, 1 }
	// };

	RectangleShape square[8][8];   //for board
	Texture tex;       //for pieces img
	Sprite sp;         //for displaying those images


	RenderWindow window(VideoMode(Added_width+800, 640), "THE BOARD", Style::Close | Style::Titlebar);
	window.setFramerateLimit(60); 


	
	

	

	chessboard chessboard1;
	

	//initial clear:
	window.clear();
	
	//initial drawing the board in starting position:
	chessboard1.draw_baseboard(window, square);
	chessboard1.set_piece_to_board(window, game_array,square, tex, sp);

	//for handling events: EventHandler class
	EventHandler eventhandler1;
	
	eventhandler1.gameleftsidescreen(window,0,0);
	eventhandler1.gamerightsidescreen(window);
	//display the initial postion board:
	window.display();


	
	
	
	while (window.isOpen()) {
		
		//Event handler section:
		
		eventhandler1.event_function(window,game_array,square);

		

	}

}


//interface to select the mode of game
void startmenu::mode_of_game()
{
	RenderWindow window_mode(VideoMode(500,320), "TYPE OF MODE", Style::Close | Style::Titlebar);
	window_mode.setFramerateLimit(60);


	back.loadFromFile("../resources/menu/back.png");
	back.setSmooth("true");
	sback.setTexture(back);
	sback.setPosition(400 / 2 - sback.getGlobalBounds().width/2-20, 160);
    sback.setScale(1.25, 1.25);
	bback.loadFromFile("../resources/menu/bback.png");
	bback.setSmooth("true");
	sbback.setTexture(bback);
	sbback.setPosition(400 / 2 - sbback.getGlobalBounds().width/2-20, 160);
    sbback.setScale(1.25, 1.25);


	offline.loadFromFile("../resources/menu/offline.png");
	offline.setSmooth("true");
	soffline.setTexture(offline);
	soffline.setPosition(30, 100);
    soffline.setScale(1.1, 1.1);
	online.loadFromFile("../resources/menu/online.png");
	online.setSmooth("true");
	sonline.setTexture(online);
	sonline.setPosition(270, 100);
    sonline.setScale(1.1, 1.1);

	while (window_mode.isOpen()) {
		
		Event ev;
		while (window_mode.pollEvent(ev))
		{
			if (ev.type == Event::Closed)
				window_mode.close();
			if (ev.type == Event::KeyPressed && ev.key.code == Keyboard::Escape)
				window_mode.close();
			if (ev.type == Event::MouseButtonPressed && ev.mouseButton.button == Mouse::Left)
			{
				int a = Mouse::getPosition(window_mode).x;
				int b = Mouse::getPosition(window_mode).y;
				if (a >= 0 && a <= 400 && b >= 0 && b <= 280)
				{
				
					if (sback.getGlobalBounds().contains(a, b))
	                {

		               //cout << "play" << endl;
		               //click1.setBuffer(click);
		               //click1.play();

		               window_mode.close();
		               mainmenu();
    
		
        
	                }

					if (soffline.getGlobalBounds().contains(a, b))
	                {

		               
		               window_mode.close();
		               main_game();
    
		
        
	                }
				}
			}

		}
		//menu.clear();
		//draw(menu);
		//menu.display();
		window_mode.clear();
		drawmode(window_mode);
		window_mode.draw(soffline);
		window_mode.draw(sonline);
		window_mode.display();

		

	}


}
//helps to draw icon in mode window
void startmenu::drawmode(RenderWindow& menu)
{
	sbackground.setScale(0.8,0.8);
	menu.draw(sbackground);
    
    int mousepos_x = Mouse::getPosition(menu).x;
	int mousepos_y= Mouse::getPosition(menu).y;
    if(sback.getGlobalBounds().contains(mousepos_x,mousepos_y))
    {
        // if(hov==0)
		// {
		// 	hoover1.setBuffer(hoover);
		//     hoover1.play();
		    
		// 	hov = 1;

		// }
		menu.draw(sbback);
		

    }
    if(!sback.getGlobalBounds().contains(mousepos_x,mousepos_y))
    {
        menu.draw(sback);
		//hov = 0;

    }
}

//interface to manage the setting
void startmenu::setting()
{
	RenderWindow window_setting(VideoMode(600,400), "SETTING", Style::Close | Style::Titlebar);
	window_setting.setFramerateLimit(60);


	back1.loadFromFile("../resources/menu/back.png");
	back1.setSmooth("true");
	sback1.setTexture(back1);
	sback1.setPosition(600 / 2 - sback1.getGlobalBounds().width/2-20, 280);
    sback1.setScale(1.25, 1.25);
	bback1.loadFromFile("../resources/menu/bback.png");
	bback.setSmooth("true");
	sbback1.setTexture(bback1);
	sbback1.setPosition(600 / 2 - sbback1.getGlobalBounds().width/2-20, 280);
    sbback1.setScale(1.25, 1.25);

	soundon.loadFromFile("../resources/menu/soundon.png");
	soundon.setSmooth("true");
	ssoundon.setTexture(soundon);
	ssoundon.setPosition(600 / 4 - ssoundon.getGlobalBounds().width/2-20, 80);
    ssoundon.setScale(1.25, 1.25);
	bsoundon.loadFromFile("../resources/menu/bsoundon.png");
	bsoundon.setSmooth("true");
	sbsoundon.setTexture(bsoundon);
	sbsoundon.setPosition(600 / 4 - sbsoundon.getGlobalBounds().width/2-20, 80);
    sbsoundon.setScale(1.25, 1.25);

	soundoff.loadFromFile("../resources/menu/soundoff.png");
	soundoff.setSmooth("true");
	ssoundoff.setTexture(soundoff);
	ssoundoff.setPosition(3*600 / 4 - ssoundoff.getGlobalBounds().width/2-20, 80);
    ssoundoff.setScale(1.25, 1.25);
	bsoundoff.loadFromFile("../resources/menu/bsoundoff.png");
	bsoundon.setSmooth("true");
	sbsoundoff.setTexture(bsoundoff);
	sbsoundoff.setPosition(3*600 / 4 - sbsoundoff.getGlobalBounds().width/2-20, 80);
    sbsoundoff.setScale(1.25, 1.25);

	bmusicon.loadFromFile("../resources/menu/bgmusicon.png");
	bmusicon.setSmooth("true");
	sbmusicon.setTexture(bmusicon);
	sbmusicon.setPosition(600 / 4 - sbmusicon.getGlobalBounds().width/2-20, 160);
    sbmusicon.setScale(1.25, 1.25);
	bbmusicon.loadFromFile("../resources/menu/bbgmusicon.png");
	bbmusicon.setSmooth("true");
	sbbmusicon.setTexture(bbmusicon);
	sbbmusicon.setPosition(600 / 4 - sbbmusicon.getGlobalBounds().width/2-20, 160);
    sbbmusicon.setScale(1.25, 1.25);

	bmusicoff.loadFromFile("../resources/menu/bgmusicoff.png");
	bmusicoff.setSmooth("true");
	sbmusicoff.setTexture(bmusicoff);
	sbmusicoff.setPosition(3*600 / 4 - sbmusicoff.getGlobalBounds().width/2-20, 160);
    sbmusicoff.setScale(1.25, 1.25);
	bbmusicoff.loadFromFile("../resources/menu/bbgmusicoff.png");
	bbmusicoff.setSmooth("true");
	sbbmusicoff.setTexture(bbmusicoff);
	sbbmusicoff.setPosition(3*600 / 4 - sbbmusicoff.getGlobalBounds().width/2-20, 160);
    sbbmusicoff.setScale(1.25, 1.25);

	while (window_setting.isOpen()) {
		
		Event ev;
		while (window_setting.pollEvent(ev))
		{
			if (ev.type == Event::Closed)
				window_setting.close();
			if (ev.type == Event::KeyPressed && ev.key.code == Keyboard::Escape)
				window_setting.close();
			if (ev.type == Event::MouseButtonPressed && ev.mouseButton.button == Mouse::Left)
			{
				int a = Mouse::getPosition(window_setting).x;
				int b = Mouse::getPosition(window_setting).y;
				if (a >= 0 && a <= 600 && b >= 0 && b <= 400)
				{
				
					if (sback1.getGlobalBounds().contains(a, b))
	                {

		               //cout << "play" << endl;
		               //click1.setBuffer(click);
		               //click1.play();

		               window_setting.close();
		               mainmenu();
    
		
        
	                }
				}
			}

		}
		//menu.clear();
		//draw(menu);
		//menu.display();
		window_setting.clear();
		drawsetting(window_setting);
		window_setting.display();

}
}

//helps to draw icon in setting window
void startmenu::drawsetting(RenderWindow& menu)
{
	menu.draw(sbackground);
    
    int mousepos_x = Mouse::getPosition(menu).x;
	int mousepos_y= Mouse::getPosition(menu).y;
    if(sback1.getGlobalBounds().contains(mousepos_x,mousepos_y))
    {
        // if(hov==0)
		// {
		// 	hoover1.setBuffer(hoover);
		//     hoover1.play();
		     
		// 	hov = 1;

		// }
		menu.draw(sbback1);
		

    }
    if(!sback1.getGlobalBounds().contains(mousepos_x,mousepos_y))
    {
        menu.draw(sback1);
		//hov = 0;

    }
	 if(ssoundon.getGlobalBounds().contains(mousepos_x,mousepos_y))
    {
        
		menu.draw(sbsoundon);
		

    }
    if(!ssoundon.getGlobalBounds().contains(mousepos_x,mousepos_y))
    {
        menu.draw(ssoundon);
		

    }
	if(ssoundoff.getGlobalBounds().contains(mousepos_x,mousepos_y))
    {
        
		menu.draw(sbsoundoff);
		

    }
    if(!ssoundoff.getGlobalBounds().contains(mousepos_x,mousepos_y))
    {
        menu.draw(ssoundoff);
		

    }
	if(sbmusicon.getGlobalBounds().contains(mousepos_x,mousepos_y))
    {
        
		menu.draw(sbbmusicon);
		

    }
    if(!sbmusicon.getGlobalBounds().contains(mousepos_x,mousepos_y))
    {
        menu.draw(sbmusicon);
		

    }
    if(sbmusicoff.getGlobalBounds().contains(mousepos_x,mousepos_y))
    {
        
		menu.draw(sbbmusicoff);
		

    }
    if(!sbmusicoff.getGlobalBounds().contains(mousepos_x,mousepos_y))
    {
        menu.draw(sbmusicoff);
		

    }



}
