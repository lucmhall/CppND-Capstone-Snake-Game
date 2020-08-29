# CPPND: Capstone Snake Game Example

This is a starter repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

<img src="snake_game.gif"/>

The Capstone Project gives you a chance to integrate what you've learned throughout this program. This project will become an important part of your portfolio to share with current and future colleagues and employers.

In this project, you can build your own C++ application or extend this Snake game, following the principles you have learned throughout this Nanodegree Program. This project will demonstrate that you can independently create applications using a wide range of C++ features.

## Dependencies for Running Locally

- cmake >= 3.7
  - All OSes: [click here for installation instructions](https://cmake.org/install/)
- make >= 4.1 (Linux, Mac), 3.81 (Windows)
  - Linux: make is installed by default on most Linux distros
  - Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  - Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
- SDL2 >= 2.0
  - All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  - Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source.
- gcc/g++ >= 5.4
  - Linux: gcc / g++ is installed by default on most Linux distros
  - Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  - Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.

## FOR GRADING

### Features Added

- Game Restart (Press enter after game end)
- Multiple Food Types
- High Score

### Loops/Functions/IO

- The project demonstrates an understanding of C++ functions and control structures.

  - The food type feature resulted in the addition of loops to change the size of the snake based on the `growthRate`

    - https://github.com/lucmhall/CppND-Capstone-Snake-Game/blob/master/src/snake.cpp#L63
    - https://github.com/lucmhall/CppND-Capstone-Snake-Game/blob/master/src/snake.cpp#L74

  - High Score feature introduced new functions to call.
    - https://github.com/lucmhall/CppND-Capstone-Snake-Game/blob/master/src/game.cpp#L8
    - https://github.com/lucmhall/CppND-Capstone-Snake-Game/blob/master/src/game.cpp#L26

- The project reads data from a file and process the data, or the program writes data to a file.

  - The high score feature reads and writes to a file called `highScore.txt`
    - https://github.com/lucmhall/CppND-Capstone-Snake-Game/blob/master/src/game.cpp#L8
    - https://github.com/lucmhall/CppND-Capstone-Snake-Game/blob/master/src/game.cpp#L26

- The project accepts user input and processes the input.
  - I added the enter and keypad enter keys to the Controller for game restart.
    - https://github.com/lucmhall/CppND-Capstone-Snake-Game/blob/master/src/controller.cpp#L23

### Object Oriented Programming

- The project uses Object Oriented Programming techniques.
  - I added a very simple Food class that inherits from SDL_Point
    - https://github.com/lucmhall/CppND-Capstone-Snake-Game/blob/master/src/Food.cpp

### Memory Management

- The project uses smart pointers instead of raw pointers.
  - The introduction of Food was accomplished with shared pointers.
    - https://github.com/lucmhall/CppND-Capstone-Snake-Game/blob/master/src/game.h#L25

### Concurrency

- The project uses multithreading.

  - The high score reading/writing is performed in a thread
    - https://github.com/lucmhall/CppND-Capstone-Snake-Game/blob/master/src/game.cpp#L119
    - https://github.com/lucmhall/CppND-Capstone-Snake-Game/blob/master/src/game.cpp#L74

- A promise and future is used in the project.
  - https://github.com/lucmhall/CppND-Capstone-Snake-Game/blob/master/src/game.cpp#L74
