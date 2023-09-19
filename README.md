# Cave

## Build:
```bash
    cd src
    make install
```

## Test:
```bash
    cd src
    make gcov_report
```

## Project Description

The project is a program for displaying and exploring caves. The user selects a file that describes the cave in a special format. The cave is displayed on the screen in a separate window or tab of the user interface.

## Project Features:

- The user can select a file describing the cave.
- The maximum size of the cave is 50 x 50.
- The loaded cave is rendered on the screen in a 500 x 500 pixel box.
- The user is given the opportunity to set the limits of "birth" and "death" of the cell, as well as the chance of initialization of the cell.
- The "birth" and "death" limits can have values from 0 to 7.
- A step-by-step mode of drawing the results of the algorithm is provided in two variants:
  - When the next step button is clicked, the next iteration of the algorithm operation is drawn.
  - Clicking on the button of automatic work starts drawing iterations of the algorithm with the frequency of 1 step in N milliseconds, where the number of milliseconds N is set through a special field in the user interface.


![d](/materials/gif/Screen%20Recording%202023-06-27%20at%2015.14.39.gif)