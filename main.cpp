#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "graphics.h"
#include "defs.h"
#include "logic.h"
using namespace std;

void waitUntilKeyPressed()
{
    SDL_Event e;
    while (true) {
        while ( SDL_PollEvent(&e) != 0 )
             if( e.type == SDL_QUIT)
            return;

    }
}

int main(int argc, char *argv[])
{

    Graphics graphics;

    graphics.init();


    Mix_Music *gMusic = graphics.loadMusic(music1);
    graphics.play(gMusic);


    Mix_Chunk *gJump = graphics.loadSound(music2);
     Mix_Chunk *gWin = graphics.loadSound(music3);
    graphics.prepareScene(graphics.loadTexture(background));

    graphics.renderTexture(graphics.loadTexture(title),400, 150, 700, 100);

    graphics.renderTexture(graphics.loadTexture(playbutton),500, 500, 500, 200);

    graphics.presentScene();

    graphics.clicktoplay();
     graphics.play(gJump);

    graphics.prepareScene(graphics.loadTexture(background));



    for(int i=200;i<=1100;i+=300)
    for(int j=100;j<=700;j+=200)

        {
          graphics.renderTexture(graphics.loadTexture(unknowimage),i, j, 200, 200);
        }

    graphics.presentScene();

    Game game;
    for (int i = 0; i < 4; ++i)
    for (int j = 0; j < 4; ++j)
        {
            game.board[i][j] = board[i][j];
        }
    game.mix();


    int Count=0,nhoi=-1,nhoj=-1;
    SDL_Event event;
    bool running2 = true;
    while (running2)
        {

        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_QUIT:
                    running2 = false;
                    break;

                case SDL_MOUSEBUTTONDOWN:
                   graphics.play(gJump);


                    int chuotx, chuoty;
                    SDL_GetMouseState(&chuotx, &chuoty);
                    for(int j=100;j<=700;j+=200)
                    for(int i=200;i<=1100;i+=300)
                    {
                        if(chuotx>=i &&chuotx<=i+200 && chuoty>=j && chuoty<=j+200 )
                        {   if(Count%2==0 )
                            {   graphics.renderTexture(graphics.loadTexture(image[game.board [(i-200)/300][(j-100)/200]]),i, j, 200, 200);
                                graphics.presentScene();
                                nhoi=(i-200)/300;
                                nhoj=(j-100)/200;
                                Count++;
                            }
                            else {if (game.board[nhoi][nhoj]==game.board[(i-200)/300 ] [(j-100)/200])
                                    {
                                     graphics.renderTexture(graphics.loadTexture(image[game.board [(i-200)/300][(j-100)/200]]),i, j, 200, 200);
                                    graphics.presentScene();
                                    Count++;
                                    }
                                else
                                {   Count--;
                                      graphics.renderTexture(graphics.loadTexture(image[game.board [(i-200)/300][(j-100)/200]]),i, j, 200, 200);
                                    graphics.presentScene();
                                    SDL_Delay(1000);

                                    graphics.renderTexture(graphics.loadTexture(unknowimage),i, j, 200, 200);
                                    graphics.renderTexture(graphics.loadTexture(unknowimage),nhoi*300+200,  nhoj*200+100, 200, 200);
                                      graphics.presentScene();

                                }
                            }
                        }
                    }
                    if(Count==16){running2 = false;break;}

            }
        }

    }
    if(Count==16)
        {
            SDL_Delay(500);
            graphics.prepareScene(graphics.loadTexture(background));
            graphics.renderTexture(graphics.loadTexture(win),250, 300, 1000, 500);
            graphics.play(gWin);
            graphics.presentScene();
            waitUntilKeyPressed();
        }
      graphics.quit();
      SDL_QUIT;

}
