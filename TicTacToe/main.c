//
//  main.c
//  TicTacToe
//
//  Created by 河村和始 on H26/09/25.
//  Copyright (c) 平成26年 Kazushi Kawamura. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>

bool isEnd();
bool isNoneOrEnd();
void displayGrid();

enum conditon{
    none,
    circle,
    cross
};

enum conditon grid[3][3];

int main()
{
    //set your none to your grid
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            grid[i][j] = none;
        }
    }
    
    int turns = 0;
    while(!isEnd() && turns !=9) {
        int point[2];
        printf("player%d: Please Enter The Point [x,y]\n", turns%2+1);
        while (true) { //VALIDATE your input
            scanf("%d,%d",&point[0],&point[1]);
            if (point[0]<=2 && point[0]>=0 && point[1]<=2 && point[1]>=0) {
                if (grid[point[0]][point[1]] == none) { //check if it is already taken or not
                    printf("test\n");
                    break;
                } else {
                    printf("This point is already taken. Please enter an another point\n");
                }
            } else {
                printf("Wrong input please enter again\n");
            }
        }
        
        if(turns%2 == 0) { //player1's turn
            grid[point[0]][point[1]] = circle;
        } else { // players2's turn
            grid[point[0]][point[1]] = cross;
            
        }
        displayGrid();
        turns++;
    }
    
    if (!isEnd()) {
        printf("-----DRAW-----");
    }
    return 0;
}

//check is the game is over
bool isEnd() {
    bool check= false;
    for(int i=0; i<3; i++) {
        if(grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2]) { // check row
            //check who won or it is all none
            if (isNoneOrEnd(i, 0)) {
                check = true;
                break;
            };
        } else if(grid[0][i] == grid [1][i] && grid[1][i] == grid[2][i]) { // check column
            if(isNoneOrEnd(0, i)) {
                check = true;
                break;
            }
        } else if((grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]) || (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0])) { // check diagnal
            if (isNoneOrEnd(1, 1)) {
                check = true;
                break;
            }
        }
    }
    return check;
}
//check if the row, col, and the diagonal is none or a symbol
bool isNoneOrEnd(int row, int col) {
    if (grid[row][col] == none) {//check one of the grid and check if it is none, if is none it is not end
        return false;
    } else if (grid[row][col] == circle) { //if circle wins
        printf("player1 wins!\n");
        return true;
    } else { // if it is the rest(cross)
        printf("player2 wins\n");
        return true;
    }
}

//display the current grid situation
void displayGrid() {
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            if(grid[i][j] == circle) {
                printf("| o ");
            } else if(grid[i][j] == cross) {
                printf("| x ");
            } else {
                printf("|   ");
            }
        }
        printf("|\n");
    }
}



