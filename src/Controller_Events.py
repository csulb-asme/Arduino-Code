import ctypes
import time
from sdl2 import *
import bluetooth
import math

def calcDeadZone(inval, radius):
    if inval > (0 - radius) and inval < (0 + radius):
        return 0
    return inval

def idlePrevent(value):
    if value == 168.5:
        return 255
    return value

# map_val maps a value val from the range [inmin, inmax] to the range [outmin, outmax]
def map_val(val, inmin, inmax, outmin, outmax):
    return (val - inmin) * (outmax - outmin)  / (inmax - inmin) + outmin

# mag_dir returns a tuple with the magnitude and direction of the joystick (in radians),
# and the magnitude [0, 1]. The inputs should be in the range [-1.0, 1.0]
def mag_dir(xval, yval):
    m = math.hypot(xval, yval)
    d = math.atan2(yval, xval)
    return (m, d)

xraw = 0
yraw = 0
speedMin = 83.0
speedMax = 254.0


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
            BUTTON Y - 2
            BUTTON X - 3

            BUTTON DPAD UP    - 11
            BUTTON DPAD DOWN  - 12
            BUTTON DPAD LEFT  - 13 
            BUTTON DPAD RIGHT - 14
            
            BUTTON 4 - MINUS
            BUTTON 5 - PLUS

            RIGHT BUMPER - 10
            LEFT BUMPER  - 9
            '''
            if event.type == SDL_JOYBUTTONDOWN:
                if event.jbutton.button == 0:
                    print("Button: {} - State: {}".format(event.jbutton.button, SDL_JoystickGetButton(joy, event.jbutton.button)))
                    BD_SOCK.send(str(event.jbutton.button) + " {0:06d}".format(SDL_JoystickGetButton(joy, event.jbutton.button)))
                elif event.jbutton.button == 1:
                    print("Button: {} - State: {}".format(event.jbutton.button, SDL_JoystickGetButton(joy, event.jbutton.button)))
                    BD_SOCK.send(str(event.jbutton.button) + " {0:06d}".format(SDL_JoystickGetButton(joy, event.jbutton.button)))
                elif event.jbutton.button == 2:
                    print("Button: {} - State: {}".format(event.jbutton.button, SDL_JoystickGetButton(joy, event.jbutton.button)))
                    BD_SOCK.send(str(event.jbutton.button) + " {0:06d}".format(SDL_JoystickGetButton(joy, event.jbutton.button)))
                elif event.jbutton.button == 3:
                    print("Button: {} - State: {}".format(event.jbutton.button, SDL_JoystickGetButton(joy, event.jbutton.button)))
                    BD_SOCK.send(str(event.jbutton.button) + " {0:06d}".format(SDL_JoystickGetButton(joy, event.jbutton.button)))
                elif event.jbutton.button == 9:
                    print("Button: {} - State: {}".format(event.jbutton.button, SDL_JoystickGetButton(joy, event.jbutton.button)))
                    BD_SOCK.send(str(event.jbutton.button) + " {0:06d}".format(SDL_JoystickGetButton(joy, event.jbutton.button)))
                elif event.jbutton.button == 10:
                    print("Button: {} - State: {}".format(event.jbutton.button, SDL_JoystickGetButton(joy, event.jbutton.button)))
                    BD_SOCK.send(str(event.jbutton.button) + " {0:06d}".format(SDL_JoystickGetButton(joy, event.jbutton.button)))
                elif event.jbutton.button == 11:
                    print("Button: {} - State: {}".format(event.jbutton.button, SDL_JoystickGetButton(joy, event.jbutton.button)))
                    BD_SOCK.send(str(event.jbutton.button) + " {0:06d}".format(SDL_JoystickGetButton(joy, event.jbutton.button)))
                elif event.jbutton.button == 12:
                    print("Button: {} - State: {}".format(event.jbutton.button, SDL_JoystickGetButton(joy, event.jbutton.button)))
                    BD_SOCK.send(str(event.jbutton.button) + " {0:06d}".format(SDL_JoystickGetButton(joy, event.jbutton.button)))
                elif event.jbutton.button == 13:
                    print("Button: {} - State: {}".format(event.jbutton.button, SDL_JoystickGetButton(joy, event.jbutton.button)))
                    BD_SOCK.send(str(event.jbutton.button) + " {0:06d}".format(SDL_JoystickGetButton(joy, event.jbutton.button)))
                elif event.jbutton.button == 14:
                    print("Button: {} - State: {}".format(event.jbutton.button, SDL_JoystickGetButton(joy, event.jbutton.button)))
                    BD_SOCK.send(str(event.jbutton.button) + " {0:06d}".format(SDL_JoystickGetButton(joy, event.jbutton.button)))
                elif event.jbutton.button == 8:
                    print("Button: {} - State: {}".format(event.jbutton.button, SDL_JoystickGetButton(joy, event.jbutton.button)))
                    BD_SOCK.send(str(event.jbutton.button) + " {0:06d}".format(SDL_JoystickGetButton(joy, event.jbutton.button)))
                elif event.jbutton.button == 7:
                    print("Button: {} - State: {}".format(event.jbutton.button, SDL_JoystickGetButton(joy, event.jbutton.button)))
                    BD_SOCK.send(str(event.jbutton.button) + " {0:06d}".format(SDL_JoystickGetButton(joy, event.jbutton.button)))
            elif event.type == SDL_JOYBUTTONUP:
                if event.jbutton.button == 0:
                    print("Button: {} - State: {}".format(event.jbutton.button, SDL_JoystickGetButton(joy, event.jbutton.button)))
                    BD_SOCK.send(str(event.jbutton.button) + " {0:06d}".format(SDL_JoystickGetButton(joy, event.jbutton.button)))
                elif event.jbutton.button == 1:
                    print("Button: {} - State: {}".format(event.jbutton.button, SDL_JoystickGetButton(joy, event.jbutton.button)))
                    BD_SOCK.send(str(event.jbutton.button) + " {0:06d}".format(SDL_JoystickGetButton(joy, event.jbutton.button)))
                elif event.jbutton.button == 2:
                    print("Button: {} - State: {}".format(event.jbutton.button, SDL_JoystickGetButton(joy, event.jbutton.button)))
                    BD_SOCK.send(str(event.jbutton.button) + " {0:06d}".format(SDL_JoystickGetButton(joy, event.jbutton.button)))
                elif event.jbutton.button == 3:
                    print("Button: {} - State: {}".format(event.jbutton.button, SDL_JoystickGetButton(joy, event.jbutton.button)))
                    BD_SOCK.send(str(event.jbutton.button) + " {0:06d}".format(SDL_JoystickGetButton(joy, event.jbutton.button)))
                elif event.jbutton.button == 9:
                    print("Button: {} - State: {}".format(event.jbutton.button, SDL_JoystickGetButton(joy, event.jbutton.button)))
                    BD_SOCK.send(str(event.jbutton.button) + " {0:06d}".format(SDL_JoystickGetButton(joy, event.jbutton.button)))
                elif event.jbutton.button == 10:
                    print("Button: {} - State: {}".format(event.jbutton.button, SDL_JoystickGetButton(joy, event.jbutton.button)))
                    BD_SOCK.send(str(event.jbutton.button) + " {0:06d}".format(SDL_JoystickGetButton(joy, event.jbutton.button)))
                elif event.jbutton.button == 11:
                    print("Button: {} - State: {}".format(event.jbutton.button, SDL_JoystickGetButton(joy, event.jbutton.button)))
                    BD_SOCK.send(str(event.jbutton.button) + " {0:06d}".format(SDL_JoystickGetButton(joy, event.jbutton.button)))
                elif event.jbutton.button == 12:
                    print("Button: {} - State: {}".format(event.jbutton.button, SDL_JoystickGetButton(joy, event.jbutton.button)))
                    BD_SOCK.send(str(event.jbutton.button) + " {0:06d}".format(SDL_JoystickGetButton(joy, event.jbutton.button)))
                elif event.jbutton.button == 13:
                    print("Button: {} - State: {}".format(event.jbutton.button, SDL_JoystickGetButton(joy, event.jbutton.button)))
                    BD_SOCK.send(str(event.jbutton.button) + " {0:06d}".format(SDL_JoystickGetButton(joy, event.jbutton.button)))
                elif event.jbutton.button == 8:
                    print("Button: {} - State: {}".format(event.jbutton.button, SDL_JoystickGetButton(joy, event.jbutton.button)))
                    BD_SOCK.send(str(event.jbutton.button) + " {0:06d}".format(SDL_JoystickGetButton(joy, event.jbutton.button)))
                elif event.jbutton.button == 7:
                    print("Button: {} - State: {}".format(event.jbutton.button, SDL_JoystickGetButton(joy, event.jbutton.button)))
                    BD_SOCK.send(str(event.jbutton.button) + " {0:06d}".format(SDL_JoystickGetButton(joy, event.jbutton.button)))


            '''
            DUMMY VALUE FRONTLEFT  - 15
            DUMMY VALUE FRONTRIGHT - 16
            DUMMY VALUE BACKLEFT   - 17
            DUMMY VALUE BACKRIGHT  - 18
            '''
            # if event.type == SDL_JOYAXISMOTION:
            #     if event.jaxis.axis == 0 or event.jaxis.axis == 1:

                
            #         value = event.jaxis.value
            #         tempx = SDL_JoystickGetAxis(joy, 1)
            #         tempy = SDL_JoystickGetAxis(joy, 0)
            #         xraw = calcDeadZone(tempx, DEADZONE)
            #         yraw = calcDeadZone(tempy, DEADZONE)
            #         x = map_val(xraw, -33000, 33000, -1.0, 1.0)
            #         y = map_val(yraw, -33000, 33000, -1.0, 1.0)

            #         m, d = mag_dir(x, y)

            #         frontleft = m * math.sin((math.pi / 4) - d) - m
            #         frontright = m * math.cos((math.pi / 4) - d) + m
            #         backleft = m * math.cos((math.pi / 4) - d) - m
            #         backright = m * math.sin((math.pi / 4) - d) + m

            #         frontleft = map_val(frontleft, -1.0, 1.0, speedMin, speedMax)
            #         frontright = map_val(frontright, -1.0, 1.0, speedMin, speedMax)
            #         backleft = map_val(backleft, -1.0, 1.0, speedMin, speedMax)
            #         backright = map_val(backright, -1.0, 1.0, speedMin, speedMax)

            #         print("Front Left: ", idlePrevent(frontleft))
            #         print("Front Right: ", idlePrevent(frontright))
            #         print("Back Left: ", idlePrevent(backleft))
            #         print("Back Right: ", idlePrevent(backright))

            #         BD_SOCK.send("15 {0:06f}".format(frontleft))
            #         BD_SOCK.send("16 {0:06f}".format(frontright))
            #         BD_SOCK.send("17 {0:06f}".format(backleft))
            #         BD_SOCK.send("18 {0:06f}".format(backright))
            #     elif event.jaxis.axis == 2:
            #         tempr = SDL_JoystickGetAxis(joy, 2)
            #         tempr = map_val(tempr, -33000.0, 33000.0, speedMin, speedMax)
            #         print("Rotation Pos: ", idlePrevent(tempr))