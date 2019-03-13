#!/usr/local/bin/python3
# Phillip LE bluetooth code (C), 
# Contributors: Fabio Colacio 
# ask Phillip Le for permission regarding usage of code.
# 

import bluetooth
from sdl2 import *

if __name__ == '__main__':
    SDL_Init(SDL_INIT_JOYSTICK)

    if SDL_NumJoysticks() <= 0:
        print("There are no joysticks connected. Quitting now...\n")
        SDL_Quit()
        exit()
    joy = SDL_JoystickOpen(0)

    while SDL_PollEvent(SDL_Event()):
        event = SDL_Event()
        if event.type == SDL_JOYAXISMOTION:
            if ( ( event.jaxis.value < -3200 ) or (event.jaxis.value > 3200 ) ): 
                if event.jaxis.axis == 0:
                    print("axis 0 move detected")
