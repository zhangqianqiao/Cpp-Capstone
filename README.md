{
 "cells": [
  {
   "cell_type": "markdown",
   "metadata": {},
   "source": [
    "##  CPPND: Capstone Tetris\n",
    "---\n",
    "\n",
    "This is Tetris vedio game for the Capstone project in the Udacity C++ Nanodegree Program.\n",
    "\n",
    "In this game, we have seven different shapes called tetrominoes. S-shape, Z-shape, T-shape, L-shape, Line-shape, MirroredL-shape, and a Square-shape. Each of these shapes is formed with four squares. The shapes are falling down the GameBlock. The object of the Tetris game is to move and rotate the shapes, so that they fit as much as possible. If we manage to form a row, the row is destroyed and we score. We play the Tetris game until we top out.\n",
    "\n",
    "The standard mapping for computer keyboards is used:\n",
    "\n",
    "- *Up arrow* rotate 90 degrees clockwise.\n",
    "- *Left*, *Right*, and *Down* to shift accordingly.\n",
    "- *Esc* to quit the game.\n",
    "\n",
    "## Dependencies for Running Locally\n",
    "* cmake >= 3.7\n",
    "  * All OSes: [click here for installation instructions](https://cmake.org/install/)\n",
    "* make >= 4.1 (Linux, Mac), 3.81 (Windows)\n",
    "  * Linux: make is installed by default on most Linux distros\n",
    "  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)\n",
    "  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)\n",
    "* SDL2 >= 2.0\n",
    "  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)\n",
    "  * Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source.\n",
    "* gcc/g++ >= 5.4\n",
    "  * Linux: gcc / g++ is installed by default on most Linux distros\n",
    "  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)\n",
    "  * Windows: recommend using [MinGW](http://www.mingw.org/)\n",
    "\n",
    "## Basic Build Instructions\n",
    "\n",
    "1. Clone this repo.\n",
    "2. Make a build directory in the top level directory: `mkdir build && cd build`\n",
    "3. Compile: `cmake .. && make`\n",
    "4. Run it: `./Tetris`.\n",
    "\n",
    "## Project Description\n",
    "\n",
    "The Tetris game code consists of five main classes: Game, Shape, GameBlock, Controller, and Renderer.\n",
    "\n",
    "To begin, main creates a Controller, a Game, and a Renderer object. Game stores a Shape and GameBlock object as part of the state, main calls Game::Run to start the game loop.\n",
    "\n",
    "#### main.cpp\n",
    "\n",
    "This is the entrypoint for the program. The main function in this file sets variables such as the window height and width and the number of frames per second at which the game will be played. The main also creates Renderer, Controller, and Game objects, and calls the Game::Run method to start the game loop.\n",
    "\n",
    "#### shape.h and shape.cpp\n",
    "\n",
    "These files define the seven different shapes called tetrominoes. S-shape, Z-shape, T-shape, L-shape, Line-shape, MirroredL-shape, and a Square-shape.Each shape contains attributes to keep track of the shape dircetion, state;\n",
    "\n",
    "#### gameblock.h and gameblockcpp\n",
    "\n",
    "Gameblock initial a area for game play, The area is divide into 10 x 20 grids; The girds is repreased by Noshape state and other seven Shape states.    \n",
    "The NoShape state represent the area can be play;  Additionally, if the area row is all complated ,we used BlockGame::clearRows() to clear up this area.\n",
    "\n",
    "#### controller.h and controller.cpp\n",
    "These files define the Controller class. This class handles keyboard input using the SDL libary, and it sets the shape's direction based on the input.\n",
    "\n",
    "#### render.h and render.cpp\n",
    "These files define the Renderer class which uses the SDL library to render the game to the screen. The Renderer class constructor creates the SDL window and an SDL renderer object that can draw in the window. The Renderer::Render method draws the food and the snake in the window using the SDL renderer.\n",
    "\n",
    "#### game.h and game.cpp\n",
    "These files define the Game class and the game loop: Game::Run. The Game class stores the state of the game, including an instance of a Shape and GameBlock object, the game score and level. Aside from the game loop, the Game class also contains methods to update the state of the game (Game::Update), get the new object of the shape, get the total score in the game, and renderer gameblock in the game.  \n",
    "\n",
    "---"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": null,
   "metadata": {},
   "outputs": [],
   "source": []
  }
 ],
 "metadata": {
  "kernelspec": {
   "display_name": "Python 3",
   "language": "python",
   "name": "python3"
  },
  "language_info": {
   "codemirror_mode": {
    "name": "ipython",
    "version": 3
   },
   "file_extension": ".py",
   "mimetype": "text/x-python",
   "name": "python",
   "nbconvert_exporter": "python",
   "pygments_lexer": "ipython3",
   "version": "3.6.9"
  }
 },
 "nbformat": 4,
 "nbformat_minor": 2
}