# ROS_Tic-Tac-Toe

This repository hosts the code for the ROS <project1_pkg> package which implements the Tic-Tac-Toe game for the Robot Operating System (ROS 1 Melodic) 
using turtlesim 

This game will have turtlesim create a tic-tac-toe game board and it will draw all the player commands on the board to provide a physical interpretation of 
the progress of the game

# Usage

To use the project1_pkg package clone this repository into the src folder of your catkin workspace.

Then build the workspace with catkin_make.

Finally start the package using roslaunch command: roslaunch project1_pkg tic_tac_toe.launch

# ROS Node Graph

<img src = "pics/game_rqt_graph.png" width = "700" height = "400" >

# Node Descriptions

## /turtle_draw

* This node prepares the game board by creating a grid pattern on the turtlesim screen

## /Game

* This node takes input positions from the players and publishes them, along with the symbol, to another node called "/turtle_mark"

## /turtle_mark

* This node, which subscribes to the "/Game" node, computes the received message and draws the appropriate at the desired location on the game board
  
# Game Play

![5dgct1](https://user-images.githubusercontent.com/62556280/122666331-3bb13400-d1ca-11eb-9ef6-4477f2af9b85.gif)

