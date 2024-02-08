## Table of Contents
1. [Installation](#installation)
2. [Creating a new project](#creating-a-new-project)
3. [Configuring the ioc](#configuring-the-ioc)
4. [Adding code](#adding-code)
5. [Debugging](#debugging)
6. [I2C](#i2c)
7. [Writing to the SD card](#writing-to-the-sd-card)
8. [UART](#uart)
9.[Videos](#videos)

Additional guides:
- [Interrupts](interrupting.md)
- [USB](USB.md)

## Installation
Install stm32CubeIDE from [here](https://www.st.com/en/development-tools/stm32cubeide.html) and follow the instructions.
This IDE is based on eclipse and is the official IDE for STM32 microcontrollers. 
It has debugging and ST-Link support built in. It can also generate code for HAL drivers based
on the microcontroller you are using.

## Creating a new project
1. Open STM32CubeIDE
2. Click on File -> New -> STM32 Project
3. Select the microcontroller you are using. For example, MARTHA uses a STM32F103C8T6
4. Give a project name, leave the rest of the settings as default and click finish

## Configuring the ioc
1. Open the .ioc file in the project explorer
2. In the IOC editor, you can change clock settings, pin settings, and enable peripherals
3. Enable SPI, UART, and I2C2 for MARTHA.
   - SPI is used for the SD card, UART is used for printing to the console, and I2C2 is used for the IMU and altimeter.
4. Inside of system core | sys, set the debug to serial wire, so we can use
the ST-Link's swd pins for debugging. 
5. Save the ioc file to generate the code for the peripherals you enabled.

## Adding code
1. To start messing around, try adding code to the main.c file in the Core/Src folder.

## Debugging
1. To debug, click on the debug button in the toolbar.
2. The first time you click this, you will be prompted to select a debug configuration.
3. Within the configuration window go inside the debugger tab and enable Serial Wire Viewer.
4. Click debug, and you should be able to step through code and see the values of variables.
5. You can also add breakpoints by double-clicking on the left side of the code editor.

## I2C
Not explored fully yet

## Writing to the SD card
Not explored fully yet

## UART
Not explored fully yet



## Videos
Here are some helpful videos to help you get started:
- [Programming in C Quick](https://www.youtube.com/watch?v=3lQEunpmtRA)
- [Programming in C Long](https://www.youtube.com/watch?v=KJgsSFOSQv0)
- [STM32CubeIDE Tutorial](https://www.youtube.com/watch?v=dnfuNT1dPiM)

I think it goes without saying, that you do not have to watch the entirety of these videos, the only one I reccomend watching entirely through is the Programming In C Quick. Ideally you should skim through the longer ones and watch the parts your confused about; but the best way to tackle this is honestly to just start coding and google things as you go and try and make a quick little hello world or command line calculator in C to get a handle on things. Remember practice is the best way to learn so don't spend too long listening to the videos.