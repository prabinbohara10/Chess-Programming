#include "chessboard.h"

//comment
void chessboard::set_piece_to_board(RenderWindow& window,int (&board)[8][8],RectangleShape(&square)[8][8],Texture& tex,Sprite& sp)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			n = board[i][j];

			if (n != 0)
			{
		
				//for setting the pieces according to the board 2D matrix
				switch (n)
				{
				case -1:       //for black rook
					tex.loadFromFile("../resources/texture/black rook.png");
					
					

					break;
				case -2:      //for black knight
					tex.loadFromFile("../resources/texture/black knight.png");
					
					

					break;
				case -3:
					tex.loadFromFile("../resources/texture/black bishop.png");
					
					break;

				case -4:
					tex.loadFromFile("../resources/texture/black queen.png");
					
					

					break;
				case -5:
					tex.loadFromFile("../resources/texture/black king.png");
					
					

					break;
				case -6:
					tex.loadFromFile("../resources/texture/black pawn.png");
					
					

					break;
				case 1:
					tex.loadFromFile("../resources/texture/white rook.png");
					
					

					break;
				case 2:
					tex.loadFromFile("../resources/texture/white knight.png");
					
					

					break;
				case 3:
					tex.loadFromFile("../resources/texture/white bishop.png");
					
					

					break;
				case 4:
					tex.loadFromFile("../resources/texture/white queen.png");
					
					

					break;
				case 5:
					tex.loadFromFile("../resources/texture/white king.png");
					
					

					break;
				case 6:
					tex.loadFromFile("../resources/texture/white pawn.png");
					
					

					break;

				}
				tex.setSmooth(true);
				sp.setTexture(tex);

				sp.setPosition((Added_width+size * j), (size * i));
				sp.setScale(scale,scale);
				window.draw(sp);

			}

		}
	}
	
}
	




void chessboard::draw_baseboard(RenderWindow& window,RectangleShape(&square)[8][8])
{

	float scale = 5/7;
	//Texture t1,t2;
	//t1.loadFromFile("../resources/texture/3.jpg");
	//t2.loadFromFile("../resources/texture/4.jpg");
	//Sprite s[64];
	//int m =0;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			
			square[i][j].setSize(Vector2f(80.f, 80.f));
			square[i][j].setPosition((Added_width+80 * j), (80 * i));
			if ((i + j) % 2 == 0) {
				
				//s[m].setTexture(t1);
				//s[m].setPosition((Added_width+80 * j), (80 * i));
				//s[m].setScale(scale,scale);
				square[i][j].setFillColor(Color::White);
				square[i][j].setOutlineThickness(1.f);
				square[i][j].setOutlineColor(Color::Black);
				
				//window.draw(s1);
			}
			else {
				//s[m].setTexture(t2);
				//s[m].setPosition((Added_width+80 * j), (80 * i));
				//s[m].setScale(scale,scale);
				square[i][j].setFillColor(Color(55, 55, 55, 255));
				square[i][j].setOutlineThickness(1.f);
				square[i][j].setOutlineColor(Color::Black);
				//window.draw(square[i][j]);
				//window.draw(s2);
			}
			//window.draw(s[m]);
			window.draw(square[i][j]);
			
			//m++;

			
			
			

		}
		

	}
}
