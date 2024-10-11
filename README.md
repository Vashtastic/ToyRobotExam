# ToyRobotExam

A game where you place and move a robot on a 5x5 table

#Build
Requirements:  Visual Studio 2022, VisualC++ compiler
1. Open the ToyRobotExam.sln solution in Visual Studio.
2. Build
3. Run

#How to

The application is a simulation of a toy robot moving on a square table top, of dimensions 5 units x 5 units. There are no
other obstructions on the table surface. The robot is free to roam around the surface of the table, but must be prevented
from falling to destruction. Any movement that would result in the robot falling from the table must be prevented,
however further valid movement commands must still be allowed.

Commands allowed
PLACE X,Y,F
MOVE
LEFT
RIGHT
REPORT

PLACE will put the toy robot on the table in position X,Y and facing NORTH, SOUTH, EAST or WEST. The origin (0,0)
can be considered to be the SOUTH WEST most corner. It is required that the first command to the robot is a PLACE
command, after that, any sequence of commands may be issued, in any order, including another PLACE command. The
application will discard all commands in the sequence until a valid PLACE command has been executed. 

MOVE will move the toy robot one unit forward in the direction it is currently facing.
LEFT and RIGHT will rotate the robot 90 degrees in the specified direction without changing the position of the
robot. 

REPORT will announce the X,Y and F of the robot to standard output.
A robot that is not on the table will ignore the MOVE, LEFT, RIGHT and REPORT commands. 
