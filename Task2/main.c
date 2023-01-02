#include <stdio.h>
#include <stdlib.h>     //rand(), srand()
#include <time.h>       //time()
#include <string.h>     //strlen()

int main(){
    //array of guessable words (random generated animals)
    char words[][20] = {
        "elephant",
        "raccoon",
        "gemsbok",
        "sheep",
        "guanaco",
        "leopard",
        "puma",
        "burro",
        "reindeer",
    };

    //get a random word from the array
    srand(time(NULL));
    int seed = rand() % 9;

    //player starts with 8 lives
    int lives = 8;

    //counters for tracking correct guesses
    int correctGuessCounter = 0;
    int oldCorrectGuessCounter = 0;

    //getting length of the word
    int wordLength = strlen(words[seed]);

    //setting all values of this array to 0 
    int guessedLetters[20];
    for (int i = 0; i < 20; i++){
        guessedLetters[i] = 0;
    }
    
    //game ends when there are the same amount of correct letters guessed and the ampount of letters in a word that you are guessing
    while (wordLength != correctGuessCounter){

        //displaying (un)guessed letters
        for (int i = 0; i < wordLength; i++){
            if (guessedLetters[i] == 1){
                printf("%c", words[seed][i]);
            }else{
                printf("_");
            }
        }
        printf("\n");

        printf("Number of correct guesses: %i\n", correctGuessCounter);
        printf("Guess a letter: ");

        //getting players letter guess
        char playersGuess[20];
        fgets(playersGuess, 20, stdin);

        //incase multiple letters inserted we'll only take the first one 
        char letterEntered;
        letterEntered = playersGuess[0];
        printf("You guessed: %c\n", letterEntered);
    
        //saving the counter value 
        oldCorrectGuessCounter = correctGuessCounter;

        //checking if player guessed the correct letter
        for (int i = 0; i < wordLength; i++){
            if (guessedLetters[i] == 1){
                continue;
            }
            
            if (letterEntered == words[seed][i]){
                guessedLetters[i] = 1;
                correctGuessCounter++;
            }
        }

        //if counters after the round have the same value means the guess was wrong and vice versa
        if (oldCorrectGuessCounter == correctGuessCounter){
            lives--;
            printf("Wrong guess, you have %i lives remaining\n", lives);
            if (lives == 0){
                break;
            }
        }else{
            printf("Your guess was correct, you have %i lives remaining!\n", lives);
        }
    }

    //endgame message
    if (lives == 0){
        printf("You have run out of lives, word was: %s\n", words[seed]);
        }else{
            printf("You win, you correctly guessed: %s\n", words[seed]);
        }
}
