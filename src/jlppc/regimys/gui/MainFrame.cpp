#include "MainFrame.hpp"
#include <iostream>
#include "../start/main.hpp"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "../start/main.hpp"

using namespace std;


namespace MainFrame {
	SDL_Window *frame = NULL;
	SDL_Renderer *renderer = NULL;
	bool init = false;
	void open(){

		if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK | SDL_INIT_AUDIO) == -1){
			rerrLog << "Erreur d'initialisation de SDL." << endl;
			rlog << "Une erreur fatale s'est produite. Merci de consulter errLog.txt" << endl;
			gererErreur(SDL_GetError(), true);
		}

		if (IMG_Init(IMG_INIT_PNG) < 0){
            rerrLog << "Erreur d'initialisation de SDL_Image" << endl;
            rlog << "Une erreur fatale s'est produite. Merci de consulter errLog.txt1" << endl;
            gererErreur(SDL_GetError(), true);

        }

		init = true;
		frame = SDL_CreateWindow("Pokémon Regimys", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 512, 512, SDL_WINDOW_SHOWN);
		renderer = SDL_CreateRenderer(frame, -1, SDL_RENDERER_ACCELERATED);
		SDL_Rect fondP;
        SDL_Rect profP;
        SDL_Texture *fondT;
        SDL_Texture *profT;
        SDL_Rect dialogP;
        SDL_Texture *dialogT;
		rlog << "[T = " << time(NULL) - Main::startTime << "] - Initialisation des SDL_Rect" << endl;
        fondP.h = 512;
        fondP.w = 512;
        fondP.x = 0;
        fondP.y = 0;
        dialogP.h = 150;
        dialogP.w = 512;
        dialogP.x = 0;
        dialogP.y = 362;
        profP.h = 300;
        profP.w = 180;
        profP.x = (fondP.w / 2) - (profP.w / 2) + 10;
        profP.y = ((fondP.h - dialogP.h) / 2) - (profP.h / 2);
        rlog << "[T = " << time(NULL) - Main::startTime << "] - Initialisation des sprites..." << endl;
        #ifdef WINDOWS
        fondT = IMG_LoadTexture(renderer, "ressources\\backgrounds\\start\\startscene.png");

        profT = IMG_LoadTexture(renderer, "ressources\\sprites\\chara\\jlppc\\jlppc.png");

        #else

        fondT = IMG_LoadTexture(renderer, "ressources/backgrounds/start/startscene.png");
        profT = IMG_LoadTexture(renderer, "ressources/sprites/chara/jlppc/jlppc.png");
        #endif

        SDL_RenderCopy(renderer, fondT, NULL, &fondP);
        SDL_RenderCopy(renderer, profT, NULL, &profP);
        SDL_RenderPresent(renderer);
        rlog << "[T = " << time(NULL) - Main::startTime << "] - Fin des initialisations" << endl;
        SDL_Delay(5000);
		SDL_DestroyWindow(frame);
        atexit(IMG_Quit);
		SDL_Quit();
	}

	void loop(){

	}
}
