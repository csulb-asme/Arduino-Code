import ctypes
import time
from sdl2 import *
import bluetooth

def deadzone(inval, radius):
    if inval > (0 - radius) and inval < (0 + radius):
        return False
    return True

if __name__ == "__main__":
    SDL_Init(SDL_INIT_JOYSTICK)
    joy = SDL_JoystickOpen(0)

    DEADZONE = 7000

    BD_ADDR = "98:D3:31:FC:1A:4E"
    BD_PORT = 1
    BD_SOCK = bluetooth.BluetoothSocket(bluetooth.RFCOMM)
    BD_SOCK.connect((BD_ADDR, BD_PORT))

    while True:
        event = SDL_Event()
        while SDL_PollEvent(ctypes.byref(event)) != 0:

            '''
            BUTTON EVENTS, listens for up and down events

            Button A - 0
            Button B - 1
            
            '''
            if event.type == SDL_JOYBUTTONDOWN:
                if event.jbutton.button == 0:
                    print("Button: {} - State: {}".format(event.jbutton.button, SDL_JoystickGetButton(joy, event.jbutton.button)))
                    BD_SOCK.send("3 {0:06d}".format(SDL_JoystickGetButton(joy, event.jbutton.button)))
                elif event.jbutton.button == 1:
                    print("Button: {} - State: {}".format(event.jbutton.button, SDL_JoystickGetButton(joy, event.jbutton.button)))
                    BD_SOCK.send("3 {0:06d}".format(SDL_JoystickGetButton(joy, event.jbutton.button)))
            elif event.type == SDL_JOYBUTTONUP:
                if event.jbutton.button == 0:
                    print("Button: {} - State: {}".format(event.jbutton.button, SDL_JoystickGetButton(joy, event.jbutton.button)))
                    BD_SOCK.send("4 {0:06d}".format(SDL_JoystickGetButton(joy, event.jbutton.button)))
                elif event.jbutton.button == 1:
                    print("Button: {} - State: {}".format(event.jbutton.button, SDL_JoystickGetButton(joy, event.jbutton.button)))
                    BD_SOCK.send("4 {0:06d}".format(SDL_JoystickGetButton(joy, event.jbutton.button)))

            '''
            AXIS EVENTS, listens for axis value changes

            Axis 0 - Movement Up and Down
            Axis 1 - Movement Left and Right
            Axis 2 - Rotation Left and Right
            '''

            if event.type == SDL_JOYAXISMOTION:
                if event.jaxis.axis == 0:
                    value = event.jaxis.value
                    if deadzone(value, DEADZONE):
                        print("Axis: {} - Value: {}".format(event.jaxis.axis, event.jaxis.value))
                        BD_SOCK.send(str(event.jaxis.axis) + " {0:06d}".format(event.jaxis.value))
                if event.jaxis.axis == 1:
                    value = event.jaxis.value
                    if deadzone(value, DEADZONE):
                        print("Axis: {} - Value: {}".format(event.jaxis.axis, event.jaxis.value))
                        BD_SOCK.send(str(event.jaxis.axis) + " {0:06d}".format(event.jaxis.value))
                if event.jaxis.axis == 2:
                    value = event.jaxis.value
                    if deadzone(value, DEADZONE):
                        print("Axis: {} - Value: {}".format(event.jaxis.axis, event.jaxis.value))
                        BD_SOCK.send(str(event.jaxis.axis) + " {0:06d}".format(event.jaxis.value))
                