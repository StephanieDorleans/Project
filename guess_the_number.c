/* 
COP 3223 Fall 2023 Assignment 2.1
Copyright 2023 Dorleans Stephanie
 */

// include library for the input/ouput
#include <stdio.h>
// include standard library
#include <stdlib.h>
// inluding for the use of rand() function
#include <time.h>



// function to generate the random number
int random_number_gen(int );

// function to guess the number
void guess_number(int );


// main program begins here
int main (void) {

    // variable for the random number
    int random_number = 0; 

    // variable for difficulty level
    int level = 0;

    // variable for choice to play again
    int new_game = 0;

    // do..while structure to play the game
    do{
        printf("Let's play Guess the Number ! \n");

        // ask the user to pick a difficulty level
        printf("Pick a difficulty level (1,2,3): ");
        scanf("%d", &level);

        // calling function to generate random number
        random_number = random_number_gen(level);

        // calling function to guess the generated number
        guess_number(random_number);

        // ask the user to play again
        printf("Play again? ");
        scanf("%d", &new_game);
    }while (new_game > 0);
}

// this function will generate the random number
int random_number_gen(level)
{
    // variable for the random number
    int y = 0;
     
    // using rand function for the random number generator 
    srand(time(NULL));

    //using the switch structure to generate the random number
    switch(level){

        // first level of difficulty
        case 1:
            y = rand() % 10;
            break;

        // second level of difficulty
        case 2: 
            y = rand() % 100;
            break;

        // third level of difficulty
        case 3:
            y = rand() % 1000;
            break;
        
        // player picks a number bigger than 1000
        default:
            printf("Not a valid number");

    }
    return y;
}

// this function will guess the random number
void guess_number(rightGuess){
    
    // this variable represents the player's guess
    int playersGuess;

    // this variable will keep track of the number of guesses during game
    int count = 0; 

    // this variable will track if the player's guess is greater than 8
    int current_num_guesses = 0;

    //ask the player for their guess
    printf("I have my number. What's your guess? ");
    scanf("%d", &playersGuess);

    // loop that will let player keep guessing when less than or equal to 8
    while (count <= 8 ){

        // if the players guess is smaller than the right guess
        if(playersGuess < rightGuess){
            
            // ask the player to guess again 
            printf("Too low. Guess again: ");
            scanf("%d", &playersGuess);
            count = count + 1;

        }

        // the players guess is larger than the right guess
        else if (playersGuess > rightGuess){
            
            //ask the player to guess again
            printf("Too high. Guess again: ");
            scanf("%d", &playersGuess);
            count = count + 1;

        }

        // player guess is the right guess
        else{

            // tells the user the number of guess
            printf("You got it in %d guesses! \n", count);

            //player guessed the correct number
            current_num_guesses = 1;
            break;


        }
    }
    if (current_num_guesses == 0){
        printf("Better luck next time! \n");
    }
}


