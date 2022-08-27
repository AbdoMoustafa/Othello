//Abdo Moustafa

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define W 'W'
#define B 'B'

int Counter = 0; //Global variable that will increment when a player doesn't have a valid move and must pass their turn.
//int InnerCounter = 0;


//int checker(char colour, char op_colour, int x, int y,char board[][8], int test);
int CHECK2(char board[][8], char colour, char op_colour, char nameB[15], char nameW[15]);



void Board(char board[][8]) //Void function that creates an 8x8 board
{

    int i=0; //Counter for a for loop



    printf("\n");

    //I used loops to print several lines to create the board

    for (i=0; i<8; i++)
    {
        printf(" --- ");
    }

    printf("\n");



    for(i=0; i<8; i++)
    {
        printf("|");

        for (int j=0; j<8; j++)
        {
            printf(" %c  |", board[j][i]); // This will print the colours (Black or white) that are inputted by the user
        }
        printf("  %d", i); //Printing the y - axis numbers (0 - 7)

        printf("\n");
        //Use k as an iterator to print --- multiple times
        for (int k=0; k<8; k++)
        {
            printf(" --- ");
        }


        printf("\n");

    }

    for (i = 0; i<=7; i++)
       {
           printf(" %d   ", i); //Printing the x - axis numbers (0 - 7)
       }

    printf("\n");
}





void start(char board[][8]) //Void function to initialise the board
{
    int i=0; //Counter for a for loop

      for(i=0; i<8; i++)
     {

         for (int j=0; j<8; j++)
         {
             board[i][j] = ' '; //We set every position to be blank as the game is just starting
         }

     }

    //Default colours placed to start the game
    board[3][3] = W;
    board[3][4] = B;
    board[4][3] = B;
    board[4][4] = W;

}


int player1(char board[][8], char nameB[15], char nameW[15]); //Function prototype for player1()
int player2(char board[][8], char nameB[15], char nameW[15]); //Function prototype for player2()



int score(char colour, char board[][8], int Pass, char nameB[15], char nameW[15]) //Integer function that will be used to calculate the score of each player. The function holds 5 input ; the colour of the player, the current board, a boolean variable, 'Pass' which will equal 1 if the player must pass his turn if he does not have any valid moves, the name of player 1, and the name of player 2.
{




    int i = 0; //Counter for a loop
    int j = 0; //Counter for a loop
    int scoreB = 0; //Variable that will store the black score
    int scoreW = 0; //Variable that will store the white score

    //Using a double for loop, we will iterate through the board, and if an index contains a black, scoreB will be incremented, if an index contains a white, scoreW will be incremented.
    for (i=0; i<8; i++)
    {
        for (j=0; j<8; j++)
        {
            if (board[i][j] == B)
            {
                scoreB++;
            }

            if (board[i][j] == W)
            {
                scoreW++;
            }
        }
    }

    if(scoreB + scoreW == 64) //as the board is an 8x8, it contains 64 indexes. So when scoreB + scoreW == 64, this means every index has been filled and there are no possible moves
    {
        if (scoreB > scoreW) //Black wins
            {
                Board(board); //Final board printed
                printf("\nThe Game Ends %d:%d , %s (Black) wins by %d points!!! ", scoreB, scoreW, nameB, (scoreB - scoreW));

                FILE *fp; //Pointer to a file

                fp = fopen("Results.txt", "w");  //opening 'Results.txt' for writing

                fprintf(fp, "\nThe Game Ends %d:%d , %s (Black) wins by %d points!!! ", scoreB, scoreW, nameB, (scoreB - scoreW)); //Printing the score to the file

                fclose(fp); //closing the file




                exit(0); //Ending the programme
            }

            if (scoreB < scoreW)//White wins
           {
               Board(board);
               printf("\nThe Game Ends %d:%d , %s (White) wins by %d points!!! ", scoreB, scoreW, nameW, (scoreW - scoreB));

               FILE *fp;

                           fp = fopen("Results.txt", "w");

                           fprintf(fp, "\nThe Game Ends %d:%d , %s (White) wins by %d points!!! ", scoreB, scoreW, nameW, (scoreW - scoreB));

                           fclose(fp);


               exit(0);
           }

            if (scoreB == scoreW)//It's a draw
            {
                Board(board);
                printf("\nThe Game Ends %d:%d ,  It's a draw!", scoreB, scoreW);

                FILE *fp;

                            fp = fopen("Results.txt", "w");

                            fprintf(fp, "The Game Ends %d:%d ,  It's a draw!", scoreB, scoreW);

                            fclose(fp);



                exit(0);
            }
        }





    if (Pass == 0) //If a player has a valid move and doesn't pass, counter will be reset to 0.
       {
           Counter = 0;
       }


       if (Pass == 1 && colour == B) //If black passes, we incremenet Counter
       {
           printf("\nYou have no valid moves available! You must pass your turn :(");

           Counter++;


           if (Counter == 2) //If Counter == 2, this means the two players passed their turn one after another, meaning there are no valid moves avaible and the game must end
           {
               if (scoreB > scoreW)//Black wins
               {
                   Board(board);
                   printf("\nThe Game Ends %d:%d , %s (Black) wins by %d points!!! ", scoreB, scoreW, nameB, (scoreB - scoreW));

                   FILE *fp;

                                          fp = fopen("Results.txt", "w");

                                          fprintf(fp, "\nThe Game Ends %d:%d , %s (Black) wins by %d points!!! ", scoreB, scoreW, nameB, (scoreB - scoreW));

                                          fclose(fp);

                   exit(0);
               }

               if (scoreB < scoreW)//White wins
              {
                  Board(board);
                  printf("\nThe Game Ends %d:%d , %s (White) wins by %d points!!! ", scoreB, scoreW, nameW, (scoreW - scoreB));

                  FILE *fp;

                                         fp = fopen("Results.txt", "w");

                                         fprintf(fp, "\nThe Game Ends %d:%d , %s (White) wins by %d points!!! ", scoreB, scoreW, nameW, (scoreW - scoreB));

                                         fclose(fp);
                  exit(0);
              }

               if (scoreB == scoreW)//It's a draw
               {
                   Board(board);
                   printf("\nThe Game Ends %d:%d ,  It's a draw!", scoreB, scoreW);

                   FILE *fp;

                   fp = fopen("Results.txt", "w");

                   fprintf(fp, "Black wins %d : %d", scoreB, scoreB);

                   fclose(fp);

                   exit(0);
               }
           }

           player2(board, nameB, nameW); //If after player1 plays, and counter != 2, we call player2() so they can have their turn
       }

       if (Pass == 1 && colour == W) //If white passes, we incremenet Counter
          {
              printf("\nYou have no valid moves available! You must pass your turn :(");
              Counter++;


              if (Counter == 2) //If Counter == 2, this means the two players passed their turn one after another, meaning there are no valid moves avaible and the game must end
                       {
                           if (scoreB > scoreW) //Black wins
                           {
                               Board(board);
                               printf("\nThe Game Ends %d:%d , %s (Black) wins by %d points!!! ", scoreB, scoreW, nameB, (scoreB - scoreW));

                               FILE *fp;

                                                      fp = fopen("Results.txt", "w");

                                                      fprintf(fp, "\nThe Game Ends %d:%d , %s (Black) wins by %d points!!! ", scoreB, scoreW, nameB, (scoreB - scoreW));

                                                      fclose(fp);

                               exit(0);
                           }

                           if (scoreB < scoreW) //White wins
                          {
                              Board(board);
                              printf("\nThe Game Ends %d:%d , %s (White) wins by %d points!!! ", scoreB, scoreW, nameW, (scoreW - scoreB));

                              FILE *fp;

                                                     fp = fopen("Results.txt", "w");

                                                     fprintf(fp, "\nThe Game Ends %d:%d , %s (White) wins by %d points!!! ", scoreB, scoreW, nameW, (scoreW - scoreB));

                                                     fclose(fp);

                              exit(0);
                          }

                           if (scoreB == scoreW) //It's a draw
                           {
                               Board(board);
                               printf("\nThe Game Ends %d:%d ,  It's a draw!", scoreB, scoreW);

                               FILE *fp;

                                                      fp = fopen("Results.txt", "w");

                                                      fprintf(fp, "\nThe Game Ends %d:%d ,  It's a draw!", scoreB, scoreW);

                                                      fclose(fp);
                               exit(0);
                           }
                       }

              player1(board, nameB, nameW); //If after player2 plays, and counter != 2, we call player1() so they can have their turn
          }






    printf(" \n| Black %d | : | White %d |\n", scoreB, scoreW); //Score printed after each turn


    return 0;
}


int BOTTOMrightdirection(char colour, char op_colour, int x, int y, char board[][8], int validation, int MoveMade, char nameB[15], char nameW[15])
{
    int x2 = x + 1; //This integer will store the co-ordinate to the bottom right of the x co-ordinate inputted by the user
    int y2 = y + 1; //This integer will store the co-ordinate to the bottom right of the y co-ordinate inputted by the user
    int x1 = x; //This integer will store the x co-ordinate inputted by the user
    int y1 = y; //This integer will store the y co-ordinate inputted by the user

    int flag = 0; //An integer that will act as a boolean variable. flag will be 1 when a test is true, otherwise it'll remain at 0.
    int counter = 0; //Integer to iterate through the loop


        if (board[x2][y2] != colour && x2 < 8 && y2 < 8 && board[x2][y2] != ' ' && x2 >= 0 && y2 >= 0 && board[x2 + 1][y2 + 1] != ' ' ) //For the move to be valid in the bottom right direction, board[x2][y2] which is beside the user's inputted co-ordinates, MUST have the opposite colour stored in it. It cannot be blank and it cannot contain the player's own colour, along with that, we must ensure that board[x2][y2] is within the range (0-7, 0 -7) so it can fit on the board.
        {

          while (x2 < 8 && y2 < 8 && board[x2][y2] != ' ') //As we move in the bottom right direction, the x & y co-ordinates will be altered, so we make sure the while loop iterates until x and y is still in the range and until board[x2][y2] is not an empty index.
          {

            while(board[x2][y2] == op_colour && x2 >= 0 && y2 >= 0) //While ensuring board[x2][y2] is the player's opposite colour, and that x2 and y2 are in the range, we run it through an if statement.
            {
                if (board[x2][y2] == ' ')  //if the index at board[x2][y2] is blank, the move is not valid and it cannot be completed, so we break out of the loop
                {
                    printf("Move not valid");
                    flag = 0; //Indicates invalid move
                    break;
                }

                //We increment the counter of the loop and we increment x2 and increment y2 in order to keep checking if the move is valid in the bottom right direction
                counter++;
                x2++;
                y2++;
            }
              flag=1;//Indicates valid move
              break; //We break out of the loop
           }

        }


    if (flag == 1 && board[x2][y2]==colour) //If flag == 1, the move is valid. At this point, board[x2][y2] must also equal the player's colour in order to satisfy the rules of a valid move.
       {

           while (counter>=0) //As the counter indicates how many indexes will be filled, we start from the top of our counter and decrement, filling each index on our way
           {
               board[x1][y1] = colour; //Setting each index to the players colour

               //increment y1 and increment x1 after an index is filled
               x1++;
               y1++;
               counter--; //Decrement counter
           }


           Board(board); //After each direction is checked, the board will now be printed with the valid moves
           score(colour, board, 0, nameB, nameW); //score() will be called in order to print the score, with 0 inputted for 'Pass' as the player has a valid move

                if (colour == B) //Player 1 just played, we call player2() so player 2 can have their turn.
                {
                    player2(board, nameB, nameW);
                }

                if (colour == W)//Player 2 just played, we call player1() so player 1 can have their turn.
                {
                   player1(board, nameB, nameW);
                }

       }

    if (flag == 0 && MoveMade == 1)//If flag is 0, this means there have been no valid moves in the bottom right direction, but since MoveMade == 1, this means the player has a valid move in at least one direction
     {

         Board(board); //The updated board is now printed
         score(colour, board, 0, nameB, nameW); //score() will be called in order to print the score, with 0 inputted for 'Pass' as the player has a valid move

         if (colour == B) //Player 1 just played, we call player2() so player 2 can have their turn.
         {
             player2(board, nameB, nameW);
         }

         if (colour == W) //Player 2 just played, we call player1() so player 1 can have their turn.
         {
             player1(board, nameB, nameW);
         }
     }

    else
    {
        printf("enter 3");
        CHECK2(board, colour, op_colour, nameB, nameW); //If no valid moves have been found for the players' inputted co-ordinates, CHECK2() will be called to check if the player has valid moves for any co-ordinate


        printf("\n\nNo valid input for this Co-ordinate12!\n\n");




        if (colour == B)
        {
            player1(board, nameB, nameW);
        }

        if (colour == W)
        {
            player2(board, nameB, nameW);
        }
    }



        return flag; //Return 1 if move is valid, otherwise 0 is returned
}



int TOPleftdirection(char colour, char op_colour, int x, int y, char board[][8], int validation, int MoveMade, char nameB[15], char nameW[15])
{

    int x2 = x - 1; //This integer will store the co-ordinate to the top left of the x co-ordinate inputted by the user
    int y2 = y - 1; //This integer will store the co-ordinate to the top left of the y co-ordinate inputted by the user
    int x1 = x; //This integer will store the x co-ordinate inputted by the user
    int y1 = y; //This integer will store the y co-ordinate inputted by the user

    int flag = 0; //An integer that will act as a boolean variable. flag will be 1 when a test is true, otherwise it'll remain at 0.
    int counter = 0; //Integer to iterate through the loop



        if (board[x2][y2] != colour && x2 < 8 && y2 < 8 && board[x2][y2] != ' ' && x2 >= 0 && y2 >= 0 && board[x2 - 1][y2 - 1] != ' ') //For the move to be valid in the top left direction, board[x2][y2] which is beside the user's inputted co-ordinates, MUST have the opposite colour stored in it. It cannot be blank and it cannot contain the player's own colour, along with that, we must ensure that board[x2][y2] is within the range (0-7, 0 -7) so it can fit on the board.
        {



          while (x2 < 8 && y2 < 8 && board[x2][y2] != ' ') //As we move in the top left direction, the x & y co-ordinates will be altered, so we make sure the while loop iterates until x and y is still in the range and until board[x2][y2] is not an empty index.
          {

            while(board[x2][y2] == op_colour && x2 >= 0 && y2 >= 0) //While ensuring board[x2][y2] is the player's opposite colour, and that x2 and y2 are in the range, we run it through an if statement.
            {
                if (board[x2][y2] == ' ') //if the index at board[x2][y2] is blank, the move is not valid and it cannot be completed, so we break out of the loop
                {
                    printf("Move not valid");
                    flag = 0; //Indicates invalid move.
                    break;
                }


                //We increment the counter of the loop and we decrement x2 and decrement y2 in order to keep checking if the move is valid in the top left direction
                counter++;
                x2--;
                y2--;
            }
              flag=1; //Indicates valid move
              break; //We break out of the loop
           }

        }


    if (flag == 1 && board[x2][y2]==colour) //If flag == 1, the move is valid. At this point, board[x2][y2] must also equal the player's colour in order to satisfy the rules of a valid move.
       {
           while (counter>=0) //As the counter indicates how many indexes will be filled, we start from the top of our counter and decrement, filling each index on our way
           {
               board[x1][y1] = colour; //Setting each index to the players colour

               //decrement y1 and decrement x1 after an index is filled
               x1--;
               y1--;
               counter--; //Decrement counter
           }



           int MoveMade = 1; //This will be used as boolean variable, if MoveMade = 1, this means we are able to make a valid move in at least one direction.
           BOTTOMrightdirection(colour, op_colour, x, y, board, validation, MoveMade, nameB, nameW); //The bottom right direction will now be checked.


       }


    else
    {


        BOTTOMrightdirection(colour, op_colour, x, y, board, validation, MoveMade, nameB, nameW);
    }



        return flag; //Return 1 if move is valid, otherwise 0 is returned
}



int BOTTOMleftdirection(char colour, char op_colour, int x, int y, char board[][8], int validation, int MoveMade, char nameB[15], char nameW[15])
{
    int x2 = x - 1; //This integer will store the co-ordinate to the bottmom left of the x co-ordinate inputted by the user
    int y2 = y + 1; //This integer will store the co-ordinate to the bottmom left of the y co-ordinate inputted by the user
    int x1 = x; //This integer will store the x co-ordinate inputted by the user
    int y1 = y; //This integer will store the y co-ordinate inputted by the user

    int flag = 0; //An integer that will act as a boolean variable. flag will be 1 when a test is true, otherwise it'll remain at 0.
    int counter = 0; //Integer to iterate through the loop


        if (board[x2][y2] == op_colour && x2 < 8 && y2 < 8 && board[x2][y2] != ' ' && x2 >= 0 && y2 >= 0 && board[x2 - 1][y2 + 1] != ' ') //For the move to be valid in the bottom left direction, board[x2][y2] which is beside the user's inputted co-ordinates, MUST have the opposite colour stored in it. It cannot be blank and it cannot contain the player's own colour, along with that, we must ensure that board[x2][y2] is within the range (0-7, 0 -7) so it can fit on the board.
        {



          while (x2 < 8 && y2 < 8 && board[x2][y2] != ' ') //As we move in the bottom left direction, the x & y co-ordinates will be altered, so we make sure the while loop iterates until x and y is still in the range and until board[x2][y2] is not an empty index.
          {

            while(board[x2][y2] == op_colour && x2 >= 0 && y2 >= 0) //While ensuring board[x2][y2] is the player's opposite colour, and that x2 and y2 are in the range, we run it through an if statement.
            {
                if (board[x2][y2] == ' ') //if the index at board[x2][y2] is blank, the move is not valid and it cannot be completed, so we break out of the loop
                {
                    printf("Move not valid");
                    flag = 0; //Indicates invalid move
                    break;
                }


                 //We increment the counter of the loop and we increment y2 and decrement x2 in order to keep checking if the move is valid in the bottom left direction
                counter++;

                x2--;
                y2++;
            }
              flag=1; //Indicates valid move
              break; //We break out of the loop
           }

        }


    if (flag == 1 && board[x2][y2]==colour) //If flag == 1, the move is valid. At this point, board[x2][y2] must also equal the player's colour in order to satisfy the rules of a valid move.
       {
           while (counter>=0) //As the counter indicates how many indexes will be filled, we start from the top of our counter and decrement, filling each index on our way
           {
               board[x1][y1] = colour; //Setting each index to the players colour
               //printf("\n\n%d %d", x1, y1);
               //increment y1 and decrement x1 after an index is filled
               x1--;
               y1++;
               counter--; //Decrement counter
           }


           int MoveMade = 1; //This will be used as boolean variable, if MoveMade = 1, this means we are able to make a valid move in at least one direction.
           TOPleftdirection(colour, op_colour, x, y, board, validation, MoveMade, nameB, nameW); //The top left direction will now be checked.


       }



    else
    {

        TOPleftdirection(colour, op_colour, x, y, board, validation, MoveMade, nameB, nameW);
    }



        return flag; //Return 1 if move is valid, otherwise 0 is returned
}



int TOPrightdirection(char colour, char op_colour, int x, int y, char board[][8], int validation, int MoveMade, char nameB[15], char nameW[15])
{

    int x2 = x + 1; //This integer will store the co-ordinate to the top right of the x co-ordinate inputted by the user
    int y2 = y - 1; //This integer will store the co-ordinate to the top right of the x co-ordinate inputted by the user
    int x1 = x; //This integer will store the x co-ordinate inputted by the user
    int y1 = y; //This integer will store the y co-ordinate inputted by the user

    int flag = 0; //An integer that will act as a boolean variable. flag will be 1 when a test is true, otherwise it'll remain at 0.
    int counter = 0; //Integer to iterate through the loop



        if (board[x2][y2] == op_colour && x2 < 8 && y2 < 8 && board[x2][y2] != ' ' && x2 >= 0 && y2 >= 0 && board[x2 + 1][y2 - 1] != ' ') //For the move to be valid in the top right direction, board[x2][y2] which is beside the user's inputted co-ordinates, MUST have the opposite colour stored in it. It cannot be blank and it cannot contain the player's own colour, along with that, we must ensure that board[x2][y2] is within the range (0-7, 0 -7) so it can fit on the board.
        {



          while (x2 < 8 && y2 < 8 && board[x2][y2] != ' ') //As we move in the top right direction, the x & y co-ordinates will be altered, so we make sure the while loop iterates until x and y is still in the range and until board[x2][y2] is not an empty index.
          {

            while(board[x2][y2] == op_colour && x2 >= 0 && y2 >= 0) //While ensuring board[x2][y2] is the player's opposite colour, and that x2 and y2 are in the range, we run it through an if statement.
            {
                if (board[x2][y2] == ' ') //if the index at board[x2][y2] is blank, the move is not valid and it cannot be completed, so we break out of the loop
                {
                    printf("Move not valid");
                    flag = 0; //Indicated invalid move
                    break;
                }

                //We increment the counter of the loop and we increment x2 and decrement y2 in order to keep checking if the move is valid in the top right direction
                counter++;

                x2++;
                y2--;
            }
              flag=1; //Indicates valid move
              break; //We break out of the loop
           }

        }


    if (flag == 1 && board[x2][y2]==colour) //If flag == 1, the move is valid. At this point, board[x2][y2] must also equal the player's colour in order to satisfy the rules of a valid move
       {
           while (counter>=0) //As the counter indicates how many indexes will be filled, we start from the top of our counter and decrement, filling each index on our way
           {
               board[x1][y1] = colour; //Setting each index to the players colour

               //increment x1 and decrement y1 after an index is filled
               x1++;
               y1--;
               counter--; //Decrement counter
           }


           int MoveMade = 1; //This will be used as boolean variable, if MoveMade = 1, this means we are able to make a valid move in at least one direction.
           BOTTOMleftdirection(colour, op_colour, x, y, board, validation, MoveMade, nameB, nameW);//The bottom left direction will now be checked


       }



    else
    {


        BOTTOMleftdirection(colour, op_colour, x, y, board, validation, MoveMade, nameB, nameW);
    }


        return flag; //Return 1 if move is valid, otherwise 0 is returned
}




int rightdirection(char colour, char op_colour, int x, int y, char board[][8], int validation, int MoveMade, char nameB[15], char nameW[15])
{

    int x2 = x + 1; //This integer will store the co-ordinate to the right of the x co-ordinate inputted by the user
    int y2 = y; //This integer will store the y co-ordinate inputted by the user
    int x1 = x; //This integer will store the x co-ordinate inputted by the user

    int flag = 0; //An integer that will act as a boolean variable. flag will be 1 when a test is true, otherwise it'll remain at 0.
    int counter = 0; //Integer to iterate through the loop



        if (board[x2][y2] != colour && x2 < 8 && board[x2][y2] != ' ' && x2 >= 0 && y2 >= 0 && board[x2 + 1][y2] != ' ') //For the move to be valid in the right direction, board[x2][y2] which is beside the user's inputted co-ordinates, MUST have the opposite colour stored in it. It cannot be blank and it cannot contain the player's own colour, along with that, we must ensure that board[x2][y2] is within the range (0-7, 0 -7) so it can fit on the board.
        {



          while (x2 < 8 && board[x2][y2] != ' ') //As we move in the right direction, only the x co-ordinate will be altered, so we make sure the while loop iterates until x is still in the range and until board[x2][y2] is not an empty index.
          {

            while(board[x2][y2] == op_colour && x2>=0) //While ensuring board[x2][y2] is the player's opposite colour, and that x2 is in the range, we run it through an if statement.
            {
                if (board[x2][y2] == ' ') //if the index at board[x2][y2] is blank, the move is not valid and it cannot be completed, so we break out of the loop
                {
                    printf("Move not valid");
                    flag = 0; //Indicates invalid move
                    break;
                }


                //We increment the counter of the loop and we increment x2 in order to keep checking if the move is valid in the right direction
                counter++;
                x2++;
            }
              flag=1; //Indicates valid move
              break; //We break out of the loop
           }

        }


    if (flag == 1 && board[x2][y2]==colour) //If flag == 1, the move is valid. At this point, board[x2][y2] must also equal the player's colour in order to satisfy the rules of a valid move
       {
           while (counter>=0) //As the counter indicates how many indexes will be filled, we start from the top of our counter and decrement, filling each index on our way
           {
               board[x1][y2] = colour; //Setting each index to the players colour
               x1++; //Increment x2 after an index is filled
               counter--; //Decrement counter
           }

           int MoveMade = 1; //This will be used as boolean variable, if MoveMade = 1, this means we are able to make a valid move in at least one direction.
           TOPrightdirection(colour,op_colour,  x,  y,  board,  validation,  MoveMade, nameB, nameW); //The top right direction will now be checked


       }


    else
    {

         TOPrightdirection(colour,op_colour,  x,  y,  board,  validation,  MoveMade, nameB, nameW);
    }


        return flag; //Return 1 if move is valid, otherwise 0 is returned
}



int leftdirection(char colour, char op_colour, int x, int y, char board[][8], int validation, int MoveMade, char nameB[15], char nameW[15])
{

    int x2 = x - 1; //This integer will store the co-ordinate to the left of the x co-ordinate inputted by the user
    int y2 = y; //This integer will store the y co-ordinate inputted by the user
    int x1 = x; //This integer will store the x co-ordinate inputted by the user

    int flag = 0; //An integer that will act as a boolean variable. flag will be 1 when a test is true, otherwise it'll remain at 0.
    int counter = 0; //Integer to iterate through the loop



        if (board[x2][y2] != colour && x2 < 8 && board[x2][y2] != ' ' && x2 >= 0 && y2 >= 0 && board[x2 - 1][y2] != ' ') //For the move to be valid in the left direction, board[x2][y2] which is beside the user's inputted co-ordinates, MUST have the opposite colour stored in it. It cannot be blank and it cannot contain the player's own colour, along with that, we must ensure that board[x2][y2] is within the range (0-7, 0 -7) so it can fit on the board.
        {



          while (x2 < 8 && board[x2][y2] != ' ') //As we move in the left direction, only the x co-ordinate will be altered, so we make sure the while loop iterates until x is still in the range and until board[x2][y2] is not an empty index.
          {

            while(board[x2][y2] == op_colour && x2>=0)  //While ensuring board[x2][y2] is the player's opposite colour, and that x2 is in the range, we run it through an if statement.
            {
                if (board[x2][y2] == ' ') //if the index at board[x2][y2] is blank, the move is not valid and it cannot be completed, so we break out of the loop
                {
                    printf("Move not valid");
                    flag = 0; //Indicates invalid move
                    break;
                }


                //We increment the counter of the loop and we decrement x2 in order to keep checking if the move is valid in the left direction
                counter++;
                x2--;
            }
              flag=1; //Indicates valid move
              break; //We break out of the loop
           }

        }



    if (flag == 1 && board[x2][y2]==colour) //If flag == 1, the move is valid. At this point, board[x2][y2] must also equal the player's colour in order to satisfy the rules of a valid move
       {


           while (counter>=0) //As the counter indicates how many indexes will be filled, we start from the top of our counter and decrement, filling each index on our way
           {
               board[x1][y2] = colour; //Setting each index to the players colour
               x1--; //Decrement x1 after an index is filled
               counter--; //Decrement the counter
           }


           int MoveMade = 1; //This will be used as boolean variable, if MoveMade = 1, this means we are able to make a valid move in at least one direction.
           rightdirection(colour, op_colour, x, y, board, validation, MoveMade, nameB, nameW);//The right direction will now be checked


       }



    else
    {

        rightdirection(colour, op_colour, x, y, board, validation, MoveMade, nameB, nameW);
    }


        return flag; //Return 1 if move is valid, otherwise 0 is returned
}


int down_direction(char colour, char op_colour, int x, int y, char board[][8], int validation, int MoveMade, char nameB[15], char nameW[15])
{


    int x2 = x; //This integer will store the x co-ordinate inputted by the user
    int y2 = y + 1; //This integer will store the co-ordinate below the y co-ordinate inputted by the user
    int y1 = y; //This integer will store the y co-ordinate inputted by the user
    int flag = 0;
    int counter = 0; //Integer to iterate through the loop



     if (board[x2][y2] != colour && y2 < 8 && board[x2][y2] != ' ' && x2 >= 0 && y2 >= 0 && board[x2][y2 + 1] != ' ') //For the move to be valid in the down direction, board[x2][y2] which is below the user's inputted co-ordinates, MUST have the opposite colour stored in it. It cannot be blank and it cannot contain the player's own colour, along with that, we must ensure that board[x2][y2] is within the range (0-7, 0 -7) so it can fit on the board.
     {



       while (y2 < 8 && board[x2][y2] != ' ') //As we move in the down direction, only the y co-ordinate will be altered, so we make sure the while loop iterates until y is still in the range and until board[x2][y2] is not an empty index.
       {

         while(board[x2][y2] == op_colour && y2>=0) //While ensuring board[x2][y2] is the player's opposite colour, and that y2 is in the range, we run it through an if statement.
         {

             if (board[x2][y2] == ' ') //if the index at board[x2][y2] is blank, the move is not valid and it cannot be completed, so we break out of the loop
             {
                 printf("Move not valid");
                 flag = 0; //Indicates invalid move
                 break;
             }


             //We increment the counter of the loop and we decrement y2 in order to keep checking if the move is valid in the down direction
             counter++;
             y2++;
         }
           flag=1; //Indicated valid move
           break; //We break out of the loop
        }

     }



 if (flag == 1 && board[x2][y2]==colour) //If flag == 1, the move is valid. At this point, board[x2][y2] must also equal the player's colour in order to satisfy the rules of a valid move
    {
        while (counter>=0) //As the counter indicates how many indexes will be filled, we start from the top of our counter and decrement, filling each index on our way
        {
            board[x2][y1] = colour; //Setting each index to the players colour
            y1++; //Increment y1 after an index is filled
            counter--; //Decrement counter
        }


        int MoveMade = 1; //This will be used as boolean variable, if MoveMade = 1, this means we are able to make a valid move in at least one direction.
        leftdirection(colour, op_colour, x, y, board, validation, MoveMade, nameB, nameW); //The left direction will now be checked


    }



    else
    {


        leftdirection(colour, op_colour, x, y, board, validation, MoveMade, nameB, nameW);
    }

    return flag; //Return 1 if move is valid, otherwise 0 is returned
}

int up_direction(char colour, char op_colour, int x, int y, char board[][8], int validation, int MoveMade, char nameB[15], char nameW[15])
{

    int x2 = x; //This integer will store the x co-ordinate inputted by the user
    int y2 = y - 1; // /This integer will store the co-ordinate above the y co-ordinate inputted by the user
    int y1 = y; //This integer will store the y co-ordinate inputted by the user

    int flag = 0;//An integer that will act as a boolean variable. flag will be 1 when a test is true, otherwise it'll remain at 0.
    int counter = 0; //Integer to iterate through a loop



     if (board[x2][y2] == op_colour && y2 < 8 && board[x2][y2] != ' ' && x2 >= 0 && y2 >= 0 && board[x2][y2 - 1] != ' ') //For the move to be valid in the up direction, board[x2][y2] which is above the user's inputted co-ordinates, MUST have the opposite colour stored in it. It cannot be blank and it cannot contain the player's own colour, along with that, we must ensure that board[x2][y2] is within the range (0-7, 0 -7) so it can fit on the board.

     {

       while (y2 < 8 && board[x2][y2] != ' ') //As we move in the up direction, only the y co-ordinate will be altered, so we make sure the while loop iterates until y is still in the range and until board[x2][y2] is not an empty index.
       {

         while(board[x2][y2] == op_colour && y2>=0) //While ensuring board[x2][y2] is the player's opposite colour, and that y2 is in the range, we run it through an if statement.
         {

             if (board[x2][y2] == ' ') //if the index at board[x2][y2] is blank, the move is not valid and it cannot be completed, so we break out of the loop
             {
                 printf("Move not valid");
                 flag = 0; //Indicates invalid move
                 break;
             }


             //We increment the counter of the loop and we decrement y2 in order to keep checking if the move is valid in the up direction
             counter++;
             y2--;
         }
           flag=1; //Indicates valid move
           break; //We break out the loop
        }

     }



 if (flag == 1 && board[x2][y2]==colour) //If flag == 1, the move is valid. At this point, board[x2][y2] must also equal the player's colour in order to satisfy the rules of a valid move
    {
       // printf("Enter");
        while (counter>=0) //As the counter indicates how many indexes will be filled, we start from the top of our counter and decrement, filling each index on our way
        {
            board[x2][y1] = colour; //Setting each index to the players colour
            y1--; //Decrement y1 after an index is filled
            counter--; //Decrement counter.
        }

        int MoveMade = 1; //This will be used as boolean variable, if MoveMade = 1, this means we are able to make a valid move in at least one direction.

        down_direction(colour, op_colour, x, y, board, validation, MoveMade, nameB, nameW); //The down direction will now be checked.


    }


    else
    {

        down_direction(colour, op_colour, x, y, board, validation, flag, nameB, nameW);
    }


    return flag; //Return 1 if move is valid, otherwise 0 is returned
}




int player2(char board[][8], char nameB[15], char nameW[15]) //Integer function to dictate move for player 2. Three inputs are the board, and  the name of player 1 and player2.
{
    int x, y; //x is an integer that will store the x coordinate inputted by user,y  is an integer that will store the y coordinate inputted by user
    char colour = W; //storing player 2's colour in a character named, op_colour (W = White)
    char op_colour = B; //storing player 1's colour in a character named, colour (B = Black)
    int flag = 0; //An integer that will act as a boolean variable. flag will be 1 when a test is true, otherwise it'll remain at 0.

     printf("\n\n(%s) Input 'P' or 'p' if would like to pass your turn (This should only be done if there are no valid moves), else input any other letter : ", nameW);
     char input2;
     input2 = getchar();
    while (input2 == '\n') //While loop used to remove trailing '\n' characters from the standard input.
    {
        input2 = getchar();
    }

    while ((input2 < 'a' && input2 > 'Z') || (input2 < 'A') || (input2 > 'z') ) //While loop to insure the input is a letter
     {
         printf("\n(%s) Please enter a valid charcter : ", nameW); //While input isn't a letter, user is prompted to try again.
         input2 = getchar();
         while (input2 == '\n')
            {
                input2 = getchar();
            }
     }


     if (input2 == 'p' || input2 == 'P')
     {
         CHECK2(board, colour, op_colour, nameB, nameW); //If the user chooses to input p/P and pass his turn, the CHECK2() function is called to ensure the player is eligible to pass his turn. Player 1 can only pass his turn if, and only if, their are no valid moves available to them.
     }

    else
    {
    printf("\n\n(%s) Please enter coordinates : ", nameW);
    scanf("%d %d", &x, &y);

        if (x < 0 || x > 7 || y < 0 || y > 7)
             {
                 printf("\n\n(%s) Please enter valid coordinates : ", nameW);
                 scanf("%d %d", &x, &y); //Player 2 is prompted to enter their desired co-ordinates
             }

        if (board[x][y]== colour || board[x][y]== op_colour)  //An if statement to ensure the user's inputted co-ordinates are not already taken.
        {
            if (colour == B)
            {
                printf("Taken!");
                player1(board, nameB, nameW); //If the position is taken, we call this function again and the user is prompted to enter another input
            }

            if (colour == W)
                  {
                      printf("Taken!");
                      player2(board, nameB, nameW); //If the position is taken, we call this function again and the user is prompted to enter another input
                  }
        }

    int validation = 0; //An integer that will act as a boolean variable. flag will be 1 when a test is true, otherwise it'll remain at 0.
    up_direction(colour, op_colour, x, y, board, validation, flag, nameB, nameW); //If all the if statements are satisfied, the x & y co-ordinates will now be checked in all directions, starting from the up direction (north)
    }


    return 0;
}







int player1(char board[][8], char nameB[15], char nameW[15]) //Integer function to dictate move for player 1. Three inputs are the board, and  the name of player 1 and player2.
{

    int x, y; //x is an integer that will store the x coordinate inputted by user,y  is an integer that will store the y coordinate inputted by user
    char colour = B; //storing player 1's colour in a character named, colour (B = Black)
    char op_colour = W; //storing player 2's colour in a character named, op_colour (W = White)
    int flag = 0; //An integer that will act as a boolean variable. flag will be 1 when a test is true, otherwise it'll remain at 0.



    printf("\n\n (%s) Input 'P' or 'p' if would like to pass your turn (This should only be done if there are no valid moves), else input any other letter : ", nameB);
    char input;
    input = getchar(); //We use getchar() in order to request a character from the user.

    while (input == '\n')//While loop used to remove trailing '\n' characters from the standard input.
       {
           input = getchar();
       }

    while ((input < 'a' && input > 'Z') || (input < 'A') || (input > 'z')) //While loop to insure the input is a letter
    {
        printf("\n(%s) Please enter a valid character : ", nameB); //While input isn't a letter, user is prompted to try again.
        input = getchar();
        while (input == '\n')
           {
               input = getchar();
           }
    }


    if (input == 'p' || input == 'P')
    {

        CHECK2(board, colour, op_colour, nameB, nameW); //If the user chooses to input p/P and pass his turn, the CHECK2() function is called to ensure the player is eligible to pass his turn. Player 1 can only pass his turn if, and only if, their are no valid moves available to them.
    }



    else
    {


    printf("\n\n(%s) Please enter coordinates : ", nameB);
    scanf("%d %d", &x, &y); //Player 1 is prompted to enter their desired co-ordinates

        if (x < 0 || x > 7 || y < 0 || y > 7)  //If statement to ensure that the user's input is between the range 0-7
        {
            printf("\n\n(%s) Please enter valid coordinates : ", nameB);
            scanf("%d %d", &x, &y); //User prompted to input another set of co-ordinates if the previous set wasn't in the correct range.

        }


        if (board[x][y]== colour || board[x][y]== op_colour) //An if statement to ensure the user's inputted co-ordinates are not already taken.
        {
            if (colour == B)
            {
                printf("Taken!");
                player1(board, nameB, nameW); //If the position is taken, we call this function again and the user is prompted to enter another input
            }

            if (colour == W)
                  {
                      printf("Taken!");
                      player2(board, nameB, nameW); //If the position is taken, we call this function again and the user is prompted to enter another input
                  }
        }


    int validation = 0; //An integer that will act as a boolean variable. flag will be 1 when a test is true, otherwise it'll remain at 0.
    up_direction(colour, op_colour, x, y, board, validation, flag, nameB, nameW);//If all the if statements are satisfied, the x & y co-ordinates will now be checked in all directions, starting from the up direction (north)

    }






    return 0;
}



int CHECK(char board [][8], int x, int y, int x2, int y2, char colour, char op_colour) //Integer function that contains 7 inputs; the board, x and y co-ordinates, integers x2 and y2 which will be inputted from the CHECK2() function, the players' colour, and his opposite colour
{



    if (board[x][y] == op_colour) //if board[x][y] is the players' oppostie colour
    {

      while ((x >= 0 && x <= 7) && (y >= 0 && y <= 7)) //While x & y are in the range 0-7 (Still inside the board)
      {
         x = x + x2; //We add x2 to x, x2 will vary depending on the direction being checked
         y = y + y2; //We add y2 to y, y2 will vary depending on the direction being checked

         if (board[x][y] == ' ') //If board[x][y] is a blank index, we return 0 as the move isn't valid for the direction being tested
         {
             return 0;
         }

            if (board[x][y] == colour)
            {
                return 1; //If board[x][y] is the players' colour, we return 1 as the move is valid for the direction being tested
            }

      }

    }

    return 0;
}




int CHECK2(char board[][8], char colour, char op_colour, char nameB[15], char nameW[15]) //Integer function that contains 5 inputs; the board, the players' colour, thei opposite colour, and the name of each player
{
    int x = 0 ; //Integer to iterate through the loop
    int y = 0 ; //Integer to iterate through the loop
    int AvailableMove = 0; //Boolean variable to will only equal 1 if the player has avalid move in at least one direction

    //Here, we use a double for loop to iterate through the entire board. Everywhere there is an empty index, we will check if the player has any valid moves by calling CHECK() 8 times, once for each direction. If the player has a valid move in at least one direction , AvailableMove will now equal 1.
    for (x=0; x<8; x++)
    {
        for (y = 0; y<8; y++)
        {
            if (board[x][y] == ' ') //If board[x][y] is an empty index
            {


            if (CHECK(board,x - 1, y, -1, 0, colour, op_colour) == 1 || CHECK(board, x + 1, y, 1, 0, colour, op_colour) == 1 || CHECK(board, x, y-1, 0, -1, colour, op_colour) == 1|| CHECK(board, x, y + 1, 0, 1, colour, op_colour) == 1 || CHECK(board, x-1, y - 1, -1, -1, colour, op_colour) == 1|| CHECK(board, x - 1, y + 1, -1, 1, colour, op_colour) == 1|| CHECK(board, x + 1, y + 1, 1, 1, colour, op_colour) == 1) //Value of x and y are altered depeneding on the direction being checked.
            {

                AvailableMove = 1;

            }


            }
        }
    }

    if (AvailableMove == 1 && colour == B) //If player 1 passed or has inputted co-ordinates with no valid moves, the board still has a valid move available for him, he will be prompted to try again, as you can only pass when there are no valid inputs at all.
    {
        printf("\n\n\nYou still have valid moves available, you cannot pass!");
        player1(board, nameB, nameW);

    }

    if (AvailableMove == 1 && colour == W) //If player 2 passed or has inputted co-ordinates with no valid moves, the board still has a valid move available for him, he will be prompted to try again, as you can only pass when there are no valid inputs at all.
       {
           printf("\n\n\nYou still have valid moves available, you cannot pass!");
           player2(board, nameB, nameW);

       }

    if (AvailableMove == 0 && colour == B) //If player 1 indeed has no valid moves, Pass will equal 1, and score() will be called in order to determine the next phase of the game (i.e. Player 2 plays or game ends if player 2 also has no valid move).
    {
        int Pass = 1;


        score(colour, board, Pass, nameB, nameW);

    }

    if (AvailableMove == 0 && colour == W) //If player 2 indeed has no valid moves, Pass will equal 1, and score() will be called in order to determine the next phase of the game (i.e. Player 1 plays or game ends if player 1 also has no valid move).
      {
          int Pass = 1;

          score(colour, board, Pass, nameB, nameW);

      }


        return 0;
}





int main()
{


  char board[8][8]; //Defining the board

  start(board); //We start by calling the start() function in order to initialse the board


    printf("$ othello\n");
    printf("    ***  Welcome to Othello!  ***\n\n");
    char nameB[15]; //Character array to hold name of player 1.
    char nameW[15]; //Character array to hold name of player 2.
    printf("Enter first name of Player 1 (Black): [No Spaces Please!] ");
    scanf("%s", nameB); //Asking player 1 for their name
    printf("Hey!, %s\n\n", nameB);
    printf("Enter first name of Player 2 (White): [No Spaces Please!] ");
    scanf("%s", nameW); //Asking player 2 for their name
    printf("Hey!, %s\n\n", nameW);


    Board(board); //Initial board is printed by calling the board() function

    printf("\n\n\nLET'S PLAY :D\n\n\n");

    printf("NOTE : While inputting co-ordinates, input the x-axis followed by the y-axis, E.g. 4 5\n\n\n");



    player1(board, nameB, nameW); //To begin the game, we call the player1() function, as player 1 begins the game.


}
