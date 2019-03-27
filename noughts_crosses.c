//
//  main.c
//  Tic-Tac-Toe
//
//  Created by Adam Dovciak on 27/02/2019.
//  Copyright © 2019 Adam Dovciak. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>
#define FILE_NAME "Tic-Tac-ToeWinners.txt"

char strPlayer1[20];
char strPlayer2[20];

int checkwin(char tiles[3][3]);
int validCharacterChosen(char);
void print(char ch[3][3]);
char* position(char [3][3], char);

FILE* file;

int main(){
    
    char board[3][3];
    char firstTile = '1';
    char selected_item;
    char *pos;
    bool correct = true;
    
    int i=0;
    int j=0;
    
    printf("Please enter your name player 1: ");
    
    scanf("%s", strPlayer1);
    
    printf("\nPlease enter your name player 2: ");
    
    scanf("%s", strPlayer2);
    
    printf("\n----------------------\n");
    
    //Initiates the board
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
        {
            board[i][j] = firstTile;
            firstTile++;
        }
    
    char string[256];
    
    print(board);
    
    for (int i = 0; i < 9; i++) {
        if(i % 2 == 0) {
            
            // Player 1
            
            printf("Player 1 enter choice from 1 to 9\n");
            scanf(" %s", string);
            
            selected_item = string[0];
            
            //Checks if invalid characters werent used
            while (!validCharacterChosen(selected_item)) {
                correct = false;
                
                while (correct == false) {
                    printf("\n Enter the choice from 1 to 9\n");
                    scanf(" %c", &selected_item);
                    if (validCharacterChosen(selected_item)) {
                        break;
                    } else {
                        continue;
                    }
                }
            }
            
            //Places X on the correct position
            pos = position(board,selected_item);
            *pos= 'X';
            print(board);
            
            file = fopen(FILE_NAME, "w");
            
            //Checks if player 1 won
            if (checkwin(board)) {
                printf("Player 1 wins!\n");
                
                // Output file created and added value needed
                fprintf(file, "Player 1 is winner of this round!");
                fclose(file);
                
                exit(0);
            }
            
        } else {
            
            // Player 2
            
            printf("Player 2 enter choice from 1 to 9\n");
            scanf(" %s", string);
            
            selected_item = string[0];
            
            //Checks if invalid characters werent used
            while (!validCharacterChosen(selected_item)) {
                correct = false;
                
                while (correct == false) {
                    printf("\n Enter the choice from 1 to 9\n");
                    scanf(" %c", &selected_item);
                    if (validCharacterChosen(selected_item)) {
                        break;
                    } else {
                        continue;
                    }
                }
            }
            
            
            pos = position(board,selected_item);
            *pos= '0';
            print(board);
            
            file = fopen(FILE_NAME, "w");
            
            //Checks if player 2 won
            if (checkwin(board)) {
                printf("Player 2 wins\n");
                
                // Output file created and added value needed
                fprintf(file, "Player 2 is winner of this round!");
                fclose(file);
                
                exit(0);
            }
        }
    }
    
    return 0;
}

void print(char ch[3][3]) {
    
    printf("\n");
    int i,j;
    
    printf("%s (X) - %s (0)\n",strPlayer1,strPlayer2);
    
    printf("\n");
    
    for(i=0;i<3;i++) {
        for(j=0;j<3;j++)
            printf("%c  ",ch[i][j]);
        printf("\n\n");
    }
}

char* position(char board[3][3], char item) {
    
    char* position;
    
    for (int i = 0;  i < 3; i++) {
        for (int j = 0 ; j < 3; j++) {
            if (item == board[i][j]) {
                position = &board[i][j];
            }
        }
    }
    
    return position;
}

int validCharacterChosen(char ch)
{
    int ch_to_val = ch;
    
    //Using ASKII checks if characters included are correct
    if (ch_to_val > 48 && ch_to_val <= 57)
        return 1;
    return 0;
}

//Checks if player won
int checkwin(char tiles[3][3]) {
    if (tiles[0][0] == tiles[0][1] && tiles[0][1] == tiles[0][2])
        return 1;
    
    else if (tiles[1][0] == tiles[1][1] && tiles[1][1] == tiles[1][2])
        return 1;
    
    else if (tiles[2][0] == tiles[2][1] && tiles[2][1] == tiles[2][2])
        return 1;
    
    else if (tiles[0][0] == tiles[1][0] && tiles[1][0] == tiles[2][0])
        return 1;
    
    else if (tiles[0][1] == tiles[1][1] && tiles[1][1] == tiles[2][1])
        return 1;
    
    else if (tiles[0][2] == tiles[1][2] && tiles[1][2] == tiles[2][2])
        return 1;
    
    else if (tiles[0][0] == tiles[1][1] && tiles[1][1] == tiles[2][2])
        return 1;
    
    else if (tiles[0][2] == tiles[1][1] && tiles[1][1] == tiles[2][0])
        return 1;
    
    else
        return  0;
}

