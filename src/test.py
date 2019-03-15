#!/usr/local/bin/python3

from sdl2 import *

if __name__ == '__main__':
    # Initialize the joystick subsystem
    SDL_Init(SDL_INIT_JOYSTICK)

    # If no joysticks are connected, quit
    if SDL_NumJoysticks() <= 0:
        print("There are no joysticks connected. Quitting now...\n")
        SDL_Quit()
        exit()

    # Each joystick is assigned an index when it is plugged in
    # You need that index to open the joystick for reading
    # If there is only one joystick plugged in, it will be index 0
    joy = SDL_JoystickOpen(0)

    # Get the number of axes, buttons, and hats on the joystick
    name = SDL_JoystickName(joy)
    num_axes = SDL_JoystickNumAxes(joy)
    num_buttons = SDL_JoystickNumButtons(joy)
    num_hats = SDL_JoystickNumHats(joy)

    print("Now reading from joystick '%s' with:" % (name))
    print("%d axes" % (num_axes))
    print("%d buttons" % (num_buttons))
    print("%d hats" % (num_hats))

    quit = False
    while not quit:

        if SDL_QuitRequested():
            quit = True

        # Print out the state of each axis
        for i in range(num_axes):
            print("Axis %d: %d" % (i, SDL_JoystickGetAxis(joy, i)))

        # Print out the state of each button
        for i in range(num_buttons):
            print("Button %d: %d" % (i, SDL_JoystickGetButton(joy, i)))

        # Print out the state of each hat
        for i in range(num_hats):
            print("Hat %d: %d" % (i, SDL_JoystickGetHat(joy, i)))

        print("")
        
        SDL_Delay(50)

    SDL_Quit()