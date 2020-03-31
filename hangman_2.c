
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAXNUMWORDS 2048
#define MAXWORDLENGTH 64


char palabra[]=" ";
void welcome_messages(int words_read){
	//welcome the user, instructions
    printf("There are %d words in the bank of words\n\n",words_read);
    printf("      | Hangman Game! |\n");
    printf("\n    **** Instructions:****\n");
    printf("\n***If the input string has more than one character, the life counter will be reduce by one.");
    printf("\n***If the character is not in the alphabet, the life counter will be reduced by one.");
    printf("\n***If the word is not in the word, the life counter will be reduced by one\n");
}
int main(int argc, char **argv) {

    //Read the bank of words in my word list
	srand(time(NULL));

	char guess_words[MAXNUMWORDS][MAXWORDLENGTH]; //I'm using my macros
	int words_read, i;
	for(i=0; i<argc-1; i++){
		strcpy(guess_words[i], argv[i+1]); //I don't want  count the name of my code
	}
	words_read = argc-1;
	welcome_messages(words_read); // call my function
	
	//variables used:
	int random_index = rand() % words_read; //ramdomly
	int lives_counter = 5;
	int num_correct = 0; //keep my words correct
	int old_correct = 0; //to keep updated the times you have hits
	int word_length = strlen(guess_words[random_index]); //Returns the length of the number of letters stored, but the random one
	int letter_guessed[8] = { 0,0,0,0,0,0,0,0 }; //my word size is 8 letters
	int loopIndex = 0; //this is to be used in my loopfor
	int reguessed = 0; //
	char guess[16]; //variable where im going to work with char_entered
	char char_entered;
	printf("\n   Let's play!\n   You have 5 lives");

	//While
	while ( num_correct < word_length ) { //while the number of hits is less than the number of letters in the word:
		//system("cls");
        printf("\n\n   Word:"); //reaplacement
		for( loopIndex = 0; loopIndex < word_length; loopIndex++) {  //while the array index is less than the number of letters
			if(letter_guessed[loopIndex] == 1) { // si el numero del indice es igual a uno
				printf("%c",guess_words[random_index][loopIndex]); //to take the letter of the random word and it will print
			} else {
				printf("*");// substitute: asterisk numbers: (word :****)
			}
		}
		printf("\nEnter a character:"); //part where we start to guess
		fgets(guess, 16, stdin); // is the maximum number of characters to be read
		char_entered = guess[0]; //entering here letters and is equal to this**
		reguessed = 0; //repeat
		old_correct = num_correct;// to pass my correct to the new beacuse we need to refresh
		for( loopIndex = 0; loopIndex < word_length; loopIndex++) { // while the word index is less than the size, increase the index to the loop
			if(letter_guessed[loopIndex] == 1) { //if the return value of the letter in that index is one
			if(guess_words[random_index][loopIndex] == char_entered) { //the letter entered is the same as what is entered?
					reguessed = 1; //save this to kno in the future
					break;
				}
				continue;
			}
			if( char_entered == guess_words[random_index][loopIndex] ) { //if the letter entered equals the letter of the chosen word ([][])
				letter_guessed[loopIndex] = 1; // if you guessed save, then increase
				num_correct++; //your number of correct increases
			}
		}
		if( old_correct == num_correct && reguessed == 0) { //if you fail you repeat letters, you lose a life
			lives_counter--; //decrease
			printf("Sorry, wrong input\n");
			printf("You have %d lives", lives_counter);
			if (lives_counter == 0) { //if you don't have lifes, your break the if-else
				break;
			}
		} else if( reguessed == 1) { //repeat letter
			printf("Already Guessed!\n");
		} else {
			printf("Congratulations, you hit a character!\nYou have %d lives", lives_counter); //user guessed
		}
	} 
	
	 if (lives_counter == 0) { //without life
		printf("\nYou lose. !\nThe word was: %s\n", guess_words[random_index]); //orignal word
	} 
	else  { //with at least one life
		printf("\nYOU WIN!\n Word: %s ", guess_words[random_index]); //original word
	}
	return 0;
}
