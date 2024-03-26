#include "SDL.h"
#include "juce_core/juce_core.h"
/*
#include "JUCE/modules/juce_core/juce_core.h"
#include <juce_core/juce_core.cpp>
#include <juce_data_structures/juce_data_structures.cpp>
#include <juce_events/juce_events.cpp>
#include <juce_graphics/juce_graphics.cpp>
#include <juce_basics/juce_basics.cpp>
#include <juce_gui_extra/juce_gui_extra.cpp>
#include <juce_core/juce_core.h>


#include "NewProject/JuceLibraryCode/JuceHeader.h"

#define JUCE_GLOBAL_MODULE_SETTINGS_INCLUDED 1
*/
void setup() {
   SDL_Window* window = SDL_CreateWindow("gamecube", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,
                              1280,720,0);
   SDL_Renderer* renderer = SDL_CreateRenderer(window,0,0);

   SDL_CreateWindowAndRenderer(1280,720,0,&window,&renderer);
    
   SDL_Init(SDL_INIT_GAMECONTROLLER);
}

int main() {
    setup();
    SDL_Event e;
    while(true) {
        SDL_PollEvent(&e);
        SDL_GameController* c; // = SDL_GameControllerOpen(0);
        if (e.type == SDL_QUIT) {
            return 0;
        }
        if (e.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
            return 0;
        }
        if (e.type == SDL_CONTROLLERDEVICEADDED) {
            c = SDL_GameControllerOpen(0);
            printf(":)");
        }
        if (e.type == SDL_CONTROLLERDEVICEREMOVED) {
            SDL_GameControllerClose(c);
            printf(":(");
        }
        if(e.type == SDL_CONTROLLERAXISMOTION) {
            printf("%d",  e.caxis.axis);
        }
     }
    return 0;
}
