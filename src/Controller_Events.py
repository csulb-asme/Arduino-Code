import ctypes
import time
from sdl2 import *

def deadzone(inval, radius):
    if inval > (0 - radius) and inval < (0 + radius):
        return False
    return True

if __name__ == "__main__":
    SDL_Init(SDL_INIT_JOYSTICK)
    joy = SDL_JoystickOpen(0)

    DEADZONE = 7000

    while True:
        event = SDL_Event()
        while SDL_PollEvent(ctypes.byref(event)) != 0:

            # BUTTON
            if event.type == SDL_JOYBUTTONDOWN:
                if event.jbutton.button == 0:
                    print("Button: {} - State: {}".format(event.jbutton.button, SDL_JoystickGetButton(joy, event.jbutton.button)))
                elif event.jbutton.button == 1:
                    print("Button: {} - State: {}".format(event.jbutton.button, SDL_JoystickGetButton(joy, event.jbutton.button)))
            elif event.type == SDL_JOYBUTTONUP:
                if event.jbutton.button == 0:
                    print("Button: {} - State: {}".format(event.jbutton.button, SDL_JoystickGetButton(joy, event.jbutton.button)))
                elif event.jbutton.button == 1:
                    print("Button: {} - State: {}".format(event.jbutton.button, SDL_JoystickGetButton(joy, event.jbutton.button)))

            # AXIS

            if event.type == SDL_JOYAXISMOTION:
                if event.jaxis.axis == 0:
                    value = event.jaxis.value
                    if deadzone(value, DEADZONE):
                        print("Axis: {} - Value: {}".format(event.jaxis.axis, event.jaxis.value))
                if event.jaxis.axis == 1:
                    value = event.jaxis.value
                    if deadzone(value, DEADZONE):
                        print("Axis: {} - Value: {}".format(event.jaxis.axis, event.jaxis.value))
                if event.jaxis.axis == 2:
                    value = event.jaxis.value
                    if deadzone(value, DEADZONE):
                        print("Axis: {} - Value: {}".format(event.jaxis.axis, event.jaxis.value))
                