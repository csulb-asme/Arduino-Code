#!/usr/local/bin/python3

import bluetooth, time
from sdl2 import *

if __name__ == '__main__':
    SDL_init(SDL_INIT_JOYSTICK)

    if SDL_NumJoysticks() <= 0:
        print("There are no joysticks connected. Quitting now...\n")
        SDL_Quit()
        exit()

    joy = SDL_JoystickOpen(0)

    name = SDL_JoystickName(joy)
    num_axes = SDL_JoystickNumAxes(joy)
    num_buttons = SDL_JoystickNumButtons(joy)
    num_hats = SDL_JoystickNumHats(joy)

    print("Now reading from joystick '%s' with:" % (name))
    print("%d axes" % (num_axes))
    print("%d buttons" % (num_buttons))
    print("%d hats" % (num_hats))


    