#!/usr/local/bin/python3
# Phillip LE bluetooth code (C), 
# Contributors: Fabio Colacio 
# ask Phillip Le for permission regarding usage of code.
# 

import bluetooth
from sdl2 import *

# -32720 - 32720
def deadzone(inval, radius):
    if inval > (0 - radius) and inval < (0 + radius):
        return 0
    return inval

if __name__ == '__main__':
    deadzone_size = 7000

    SDL_Init(SDL_INIT_JOYSTICK)
    bd_addr = "98:D3:31:FC:1A:4E"
    bd_port = 1
    bd_sock = bluetooth.BluetoothSocket(bluetooth.RFCOMM)
    bd_sock.connect((bd_addr, bd_port))

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

    data = ""

    quit = False
    while not quit:
        if SDL_QuitRequested():
            quit = True

        data += "{0:06d}".format(deadzone(SDL_JoystickGetAxis(joy, 0), deadzone_size)) # Left Right
        data += " "
        data += "{0:06d}".format(deadzone(SDL_JoystickGetAxis(joy, 1), deadzone_size)) # Up Down
        data += " "
        data += "{0:06d}".format(deadzone(SDL_JoystickGetAxis(joy, 2), deadzone_size)) # Rotation Left Right
        data += " "
        data += str(SDL_JoystickGetButton(joy, 0)) # B Button
        data += " "
        data += str(SDL_JoystickGetButton(joy, 1)) # A Button
        data += "\n"

        print(data, end="")
        bd_sock.send(data)

        data = ""
        SDL_Delay(150)
    
    SDL_Quit()
    bd_sock.close()
