#include <stdio.h>
#include <stdlib.h>

int n;
char board[100][100];
int player;
void startGame();
int checkWin();
void printBoard();
void playerMove();
int main() {
    startGame();
    int moves = 0;
    while (1) {
        printBoard();
        playerMove();
        moves++;
        if (moves == n*n) {
            printf("\n\nIt's a tie!\n");
            printBoard();
            exit(0);
        }
    }
    return 0;
}
void startGame() {
    int response;
    printf("===WELCOME TO TIC TAC TOE===\n");
    printf("To play the game press 1 or press 0 to quit: ");
    scanf("%d", &response);
    if(response == 1)
    {
        printf("\nEnter the value of N for N x N Tic Tac Toe (upto 100): ");
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) 
            {    
                board[i][j] = ' ';
            }
    }
    player = 1;
    }
    else if (response == 0)
    {
        exit(0);
    }
    
}
int checkWin() {
    int i, j;
    
    for (i = 0; i < n; i++) {
        for (j = 1; j < n; j++) {
            if (board[i][j] != board[i][0] || board[i][0]==' ')
                break;
        }
        if (j == n)
            return 1;
    }
    
    for (i = 0; i < n; i++) {
        for (j = 1; j < n; j++) {
            if (board[j][i] != board[0][i] || board[0][i]==' ')
                break;
        }
        if (j == n)
            return 1;
    }
    
    for (i = 1; i < n; i++) {
        if (board[i][i] != board[0][0]|| board[0][0]==' ')
            break;
    }
    if (i == n)
        return 1;
    for (i = 1; i < n; i++) {
        if (board[i][n - i - 1] != board[0][n - 1]|| board[0][n - 1]==' ')
            break;
    }
    if (i == n)
        return 1;
    return 0;
}
void printBoard() {
    system("clear || cls");
    printf("===ALL THE BEST===\n\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%c |", board[i][j]);
        }
        printf("\n");
        for (int j = 0; j < n; j++)
            printf("---");
        printf("\n");
    }
}
void playerMove() {
    int x, y;
    printf("Player %d, enter the position of your move in cartesian system (row no., column no.): ", player);
    scanf("%d %d", &x, &y);
    if (x<0 || x >= n || y < 0 || y >= n)
    {
        printf("Wrong input! fill again\n");
       
    }
    else if (board[x][y] != ' ') {
        printf("This box is already filled!\n");
    } else {
        board[x][y] = (player == 1) ? 'X' : 'O';
        if (checkWin() == 1) {
            
            
            printBoard();
            printf("Player %d wins!\n\n", player);
            exit(0);
        } else {
            player = (player == 1) ? 2 : 1;
            
            printBoard();
        }
    }
}

