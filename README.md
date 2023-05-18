# RPIPicoFlashLEDExamples

Three approaches to flashing an LED on the Raspberry PI Pico. Use for Pico onboard LED but could be adapted to an external LED.

1, LED Blink using the Delay strategy in a main loop
2, LED Blink by checking system time
3, LED Blink through using the timer callback interupt

## Build approach
All example use the Pico SDK in C.

To build use the approach:
```
cd <<project folder>>
mkdir build
cd build
cmake ..
make
```

