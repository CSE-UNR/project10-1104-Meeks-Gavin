// Author: Gavin Meeks
// Date: 4/21/26
// Purpose: Project 10 Submission

#include<stdio.h>

#define STRING_CAP 100


void removeNewline(char guesses[][STRING_CAP], int rows);
int lengthCheck(char guesses[][STRING_CAP], int rows);
void allLowercase(char guesses[][STRING_CAP], int rows);
int correctGuess(char guesses[][STRING_CAP], int rows, char correctWord[]);
void correctPositions(char guesses[][STRING_CAP], int rows, char correctWord[]);
void incorrectPositions(char guesses[][STRING_CAP], int rows, char correctWord[]);
void outputs(int guessNum, int correct);

int main(){

char correctWord[STRING_CAP];

FILE *readFilePtr;

readFilePtr = fopen("mystery.txt" , "r");

	if(readFilePtr == NULL){
	 printf("Cannot open file\n");
	 return 0;
	}


fgets(correctWord , STRING_CAP , readFilePtr);

fclose(readFilePtr);


char guesses[STRING_CAP][STRING_CAP];
int guessNum = 1;
int correct = 0;
do{

if(guessNum == 6){
printf("FINAL GUESS: ");
}
else{printf("GUESS %d! Enter your guess: ", guessNum);}
fgets(guesses[0], STRING_CAP , stdin);

removeNewline(guesses, 0);
int lettercount = lengthCheck(guesses, 0);
while(lettercount == 0){
printf("Your guess must be 5 letters long.\nPlease try again: ");
fgets(guesses[0], STRING_CAP, stdin);
removeNewline(guesses, 0);
lettercount = lengthCheck(guesses, 0);
}
allLowercase(guesses, 0);
correct = correctGuess(guesses, 0 , correctWord);
correctPositions(guesses , 0 , correctWord);
printf("================================\n");
printf("%s\n", guesses[0]);

incorrectPositions(guesses , 0 , correctWord);
printf("%s\n", guesses[1]);

 guessNum++;
}while(guessNum <= 6 && correct != 1);

outputs(guessNum, correct);

	return 0;
}

void removeNewline(char guesses[][STRING_CAP], int rows){
for(int colI = 0 ; guesses[rows][colI] != '\0' ; colI++){
 if(guesses[rows][colI] == '\n'){
  guesses[rows][colI] = '\0';
 }
}
}

int lengthCheck(char guesses[][STRING_CAP], int rows){
int count = 0;

for(int colI = 0; guesses[rows][colI] != '\0'; colI++){
 count++; 
}

if(count == 5){
return 1;
}
else{
return 0;
}
}

void allLowercase(char guesses[][STRING_CAP], int rows){

for(int colI=0 ; guesses[rows][colI] != '\0' ; colI++){
 if(guesses[rows][colI] >= 'A' && guesses[rows][colI] <= 'Z'){
  guesses[rows][colI] = guesses[rows][colI] + ('a' - 'A');
 }
}
}

int correctGuess(char guesses[][STRING_CAP], int rows, char correctWord[]){ 
for(int colI = 0; guesses[rows][colI] != '\0' ; colI++){
 if(guesses[rows][colI] != correctWord[colI]){
  return 0; 
 }
}
	return 1;
}

void correctPositions(char guesses[][STRING_CAP], int rows, char correctWord[]){
for(int colI=0 ; guesses[rows][colI] != '\0' ; colI++){
 if(guesses[rows][colI] == correctWord[colI]){
  guesses[rows][colI] -= ('a' - 'A');
 }
}
}

void incorrectPositions(char guesses[][STRING_CAP], int rows, char correctWord[]){
for(int colI=0 ; guesses[rows][colI] != '\0' ; colI++){
 char letter = guesses[rows][colI];
 int rightLetter = 0;
 for(int i = 0 ; guesses[rows][i] != '\0' ; i++){
  if(letter == correctWord[i] && i != colI){
   rightLetter = 1;
  }
  
 }
 if(rightLetter == 1){
  guesses[rows+1][colI]= '^';
 }
 else{guesses[rows+1][colI]= ' ';}
}
}

void outputs(int guessNum, int correct){

 if(correct == 1){
 guessNum = guessNum-1;
  switch (guessNum){
  case 1: printf("You won in 1 guess!\n GOATED!\n");
  	  break;
  case 2: printf("You won in %d guesses!\nAmazing!\n", guessNum);
  	  break;
  case 3: printf("You won in %d guesses!\nAmazing!\n", guessNum);
  	  break;
  case 4: printf("You won in %d guesses!\nNice!\n", guessNum);
  	  break;
  case 5: printf("You won in %d guesses!\nNice!\n", guessNum);
  	  break;
  case 6: printf("You won in %d guesses!\n", guessNum);
  	  break;
  }
 }
 if(guessNum > 6){
 printf("You lost, better luck next time!\n");
 }
}

