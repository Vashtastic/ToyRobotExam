# ToyRobotExam

A game where you place and move a robot on a 5x5 table

# Build
Requirements:  Visual Studio 2022, VisualC++ compiler
1. Open the ToyRobotExam.sln solution in Visual Studio.
2. Build the solution by going to ```Build -> Build Solution (Ctrl+Shift+B)```
3. Run by pressing the ```"Start without debugging" button (Ctrl+f5)```

# Tests
1. Build the solution by going to ```Build -> Build Solution (Ctrl+Shift+B)``` if you haven't yet
3. Open the test explorer by going to `Test` -> `Test Explorer`
2. Run all tests `Test` -> `Run All Tests`
3. View test results in the `Test Explorer`

# How to

The application is a simulation of a toy robot moving on a square table top, of dimensions 5 units x 5 units. There are no
other obstructions on the table surface. The robot is free to roam around the surface of the table, but must be prevented
from falling to destruction. Any movement that would result in the robot falling from the table must be prevented,
however further valid movement commands must still be allowed.

`Commands allowed`     <br />
```PLACE X,Y,F```      <br />
```MOVE```             <br />
```LEFT```             <br />
```RIGHT```            <br />
```REPORT```           <br />

# Commands Allowed

## PLACE
`PLACE` will put the toy robot on the table in position X,Y and facing NORTH, SOUTH, EAST or WEST. The origin (0,0)
can be considered to be the SOUTH WEST most corner. It is required that the first command to the robot is a PLACE
command, after that, any sequence of commands may be issued, in any order, including another PLACE command. The
application will discard all commands in the sequence until a valid PLACE command has been executed.

## MOVE COMMANDS
MOVE will move the toy robot one unit forward in the direction it is currently facing.
`LEFT` and `RIGHT` will rotate the robot 90 degrees in the specified direction without changing the position of the
robot.
## REPORT
REPORT will announce the X,Y and F of the robot to standard output.

A robot that is not on the table will ignore the MOVE, LEFT, RIGHT and REPORT commands.

Example Input and Output:

`PLACE 0,0,NORTH`     <br />
`MOVE`                <br />
`REPORT`              <br />
Output: 0,1,NORTH     <br />


`PLACE 0,0,NORTH`     <br />
`LEFT`                <br />
`REPORT`              <br />
Output: 0,0,WEST      <br />


`PLACE 1,2,EAST`      <br />
`MOVE`                <br />
`MOVE`                <br />
`LEFT`                <br />
`MOVE`                <br />
`REPORT`              <br />
Output: 3,3,NORTH     <br />

# Possible Improvements
* Add Design Documents
* Add End to End testing
