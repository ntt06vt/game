#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "graphics.h"
#include "defs.h"
#include "logic.h"
#include <cstdlib>  // rand()
#include <ctime>    // time()
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
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)cout<<"SDL_Init:"<< SDL_GetError();
    SDL_Window* window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);


    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED |SDL_RENDERER_PRESENTVSYNC);


    SDL_Texture *nen = IMG_LoadTexture(renderer, "nen.jpg");
    SDL_RenderCopy( renderer, nen, NULL, NULL);



    SDL_Texture *tieude = IMG_LoadTexture(renderer, "timhinhgiongnhau.png");
    SDL_Rect *recttieude = new SDL_Rect{400, 150, 700, 100};
    SDL_RenderCopy( renderer, tieude, NULL,recttieude);



    SDL_Texture *choi = IMG_LoadTexture(renderer, "choi.png");
    SDL_Rect *rectchoi = new SDL_Rect{500, 500, 500, 200};
    SDL_RenderCopy( renderer, choi, NULL,rectchoi);
    SDL_RenderPresent( renderer );


    SDL_Texture* textanh[8];
    for(int i=0;i<=7;i++)textanh[i] = IMG_LoadTexture(renderer, a[i]);

    SDL_Event event;
    bool running = true;
    while (running)
        {
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_QUIT:
                    running = false;
                    break;

                case SDL_MOUSEBUTTONDOWN:
                    int chuotx, chuoty;
                    SDL_GetMouseState(&chuotx, &chuoty);
                    if (chuotx >= 500 && chuotx <= 1000 && chuoty >= 500 && chuoty <= 700)
                        {
                         running = false;
                    }

            }
        }
        SDL_Delay(100);
    }


    SDL_RenderCopy( renderer, nen, NULL, NULL);
    SDL_RenderPresent( renderer );


    SDL_Texture *khung = IMG_LoadTexture(renderer, "khung.png");
    for(int j=100;j<=700;j+=200)
    for(int i=200;i<=1100;i+=300)
        {

        SDL_Rect *rectkhung = new SDL_Rect{i, j, 200, 200};
        SDL_RenderCopy( renderer, khung, NULL,rectkhung);

    }
        SDL_RenderPresent( renderer );




    int board[4][4]={{0,0,1,1},{2,2,3,3},{4,4,5,5},{6,6,7,7}};
    srand(time(0));
    for(int m=1;m<=100;m++)
    {
        int nn1 =   rand() % 4;
        int nn2 =   rand() % 4;
        int nn3 =   rand() % 4;
        int nn4 =   rand() % 4;
        swap(board[nn1][nn2],board[nn3][nn4]);
    }



 int dem=0,nhoi=-1,nhoj=-1;

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
                    int chuotx, chuoty;
                    SDL_GetMouseState(&chuotx, &chuoty);
                    for(int j=100;j<=700;j+=200)
                    for(int i=200;i<=1100;i+=300)
                    {
                        if(chuotx>=i &&chuotx<=i+200 && chuoty>=j && chuoty<=j+200)
                        {   if(dem%2==0 )
                            {
                            SDL_Rect *rectkhung = new SDL_Rect{i, j, 200, 200};
                                SDL_RenderCopy( renderer, textanh[board [(i-200)/300][(j-100)/200]], NULL,rectkhung);
                                SDL_RenderPresent( renderer );
                                nhoi=(i-200)/300;
                                nhoj=(j-100)/200;
                                dem++;
                            }
                            else {if (board[nhoi][nhoj]==board[(i-200)/300 ] [(j-100)/200])
                                    {
                                    SDL_Rect *rectkhung = new SDL_Rect{i, j, 200, 200};
                                    SDL_RenderCopy( renderer, textanh[board [(i-200)/300][(j-100)/200]], NULL,rectkhung);
                                    SDL_RenderPresent( renderer );
                                    dem++;
                                    }
                                else
                                {   dem--;
                                     SDL_Rect *rectkhung = new SDL_Rect{i, j, 200, 200};
                                    SDL_RenderCopy( renderer, textanh[board [(i-200)/300][(j-100)/200]], NULL,rectkhung);
                                    SDL_RenderPresent( renderer );
                                    SDL_Delay(1000);

                                      SDL_RenderCopy( renderer, khung, NULL,rectkhung);
                                       SDL_Rect *kk = new SDL_Rect{nhoi*300+200, nhoj*200+100, 200, 200};
                                       SDL_RenderCopy( renderer, khung, NULL,kk);
                                       SDL_RenderPresent( renderer );

                                }






                            }


                        }
                    }

                    if(dem==16){running2 = false;break;}

            }
        }

    }

    if(dem==16){
    SDL_Delay(500);



    SDL_RenderCopy( renderer, nen, NULL, NULL);

    SDL_Texture *win = IMG_LoadTexture(renderer, "win.png");
    SDL_Rect *rectwin = new SDL_Rect{250, 300, 1000, 500};
    SDL_RenderCopy( renderer, win, NULL,rectwin);
    SDL_RenderPresent( renderer );
    SDL_RenderPresent( renderer );
    waitUntilKeyPressed();
}

}













