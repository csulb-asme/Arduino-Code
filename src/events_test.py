import ctypes
import time
from sdl2 import *


class Joystick:
    def __init__(self):
        SDL_Init(SDL_INIT_JOYSTICK)
        self.axis = {}
        self.button = {}

    def update(self):
        event = SDL_Event()
        while SDL_PollEvent(ctypes.byref(event)) != 0:
            if event.type == SDL_JOYDEVICEADDED:
                self.device = SDL_JoystickOpen(event.jdevice.which)
            elif event.type == SDL_JOYBUTTONDOWN:
                self.button[event.jbutton.button] = True


if __name__ == "__main__":
    joystick = Joystick()
    while True:
        joystick.update()
        time.sleep(0.1)
        print(joystick.axis)
        print(joystick.button)