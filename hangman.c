#include<stdio.h>
#include<string.h>

void showHangman(int);

int main(void)
{
    char tempWord[100], hangmanOutput[100], alphabetFromUser, hangmanWord[100]="hello";    
      
    /* hangmanWord[] array is used for the original word and tempWord[] array is used to get the alphabet from user and compare it with original word */

    /* alphabetFromUser array is used to show the remaining blanks and correct inputs */
    int wrongTry = 6 , matchFound = 0, counter = 0 , position = 0, winner, length , i;          
    /* Player will get 5 chance, so we use int wrongTry as chance counter updater */

    /** int matchFound is used to search the alphabet and if the alphabet from user does not exist in the original word, it will remain 0 and upon finding the word, matchFound will be set as 1 **/

    printf("\n\n\tHIT >>ENTER<<");
    getchar();                                  /*hold the computer screen*/
    length = strlen(hangmanWord);               /*get the length of the word*/


    printf("\n\n !!!!!!!!!!!!!!!!!!!Welcome to the HANGMAN GAME!!!!!!!!!!!!!!!!!\n\n\n");
    printf("\n\n You will get 5 chances to guess the right word");

    getchar();

    printf("\n\n\tHIT >>ENTER<< ");

    getchar();


        printf("\n\t||===== ");                 /**to show the HANGMAN**/
	printf("\n\t||    | ");
        printf("\n\t||      ");
        printf("\n\t||      ");
        printf("\n\t||      ");
        printf("\n\t||      ");

    printf("\n\n     The word has %d alphabets \n\n",length);  /** to tell the user how many alphabets the word has**/
    for( i = 0; i < length ; i++)
    {
        hangmanOutput[i] = '_';
        hangmanOutput[length] = '\0';
    }

    for(i = 0 ; i < length ; i++)
    {
        printf(" ");
        printf("%c",hangmanOutput[i]);        /** to show the word With n(length of the original word) number of underscores (_)**/

    }
    while(wrongTry != 0)                        /**while loop for exiting the program when no tries are left**/
    {
        matchFound = 0;
        printf("\n\n   enter any alphabet from a to z and please use small case!!");
        printf("\n\n\t Enter HERE ==> ");

	    scanf("%c",&alphabetFromUser);            /* to get alphabet from user */
    if(alphabetFromUser < 'a' || alphabetFromUser > 'z') /** In case player gives input other than 'a' to 'z' the console will ask again**/
    {
        printf("\n\n\t invalid input, please enter an aplhabet ");
        matchFound = 2;
    }
    if (matchFound != 2)
    {
        for(counter=0;counter<length;counter++)    /*for loop to check whether player input alphabet exists or not in the word**/
	    {
		    if(alphabetFromUser==hangmanWord[counter])
		     {
		       matchFound = 1;
                     }
            }

	   if(matchFound == 0)                      /**in case of wrong guess from the user **/
	    {
     	      printf("\n\t :( You have %d tries left ",--wrongTry);
	          getchar();
              showHangman(wrongTry);
              getchar();
	    }

	   else
	   {
	        for(counter = 0; counter < length; counter++)
             {
     	        matchFound = 0;
                if(alphabetFromUser == hangmanWord[counter])
	            {
     		        position = counter ;
     		        matchFound = 1;
	            }
    	      if(matchFound == 1)
	          {
                    for(i = 0 ; i < length ; i++)
                    {
                      if( i == position)
                  	  {
                            hangmanOutput[i] = alphabetFromUser; /**Put the alphabet at right position**/
                      }
                      else if( hangmanOutput[i] >= 'a' && hangmanOutput[i] <= 'z' ) /** If the position already occupied by same alphabet then no need to fill it again*/
                      {
                            continue;
                  	  }

                      else
                      {
                            hangmanOutput[i] = '_';       /** Put a blank at not guessed alphabet position **/
                      }
                    }
                tempWord[position] = alphabetFromUser;/**put the alphabet in another char array to check with the original word**/
                tempWord[length] = '\0'; /**put the NULL character at the end of the temp string**/
                winner = strcmp(tempWord,hangmanWord);  /** upon a match, it will return 0 **/

                if(winner == 0)      /**if the player guessed the whole word right then he/she is the WINNER**/
                {
                    printf("\n\n\t \t YAHOO!!!!! You are the WINNER !!!!!");
                    printf("\n\n\t The Word was %s ",hangmanWord);
                    getchar();
                    return 0;
                }
	       }
	    }
      }
     }

    printf("\n\n\t");
    for(i = 0 ; i < length ; i++)
    {
        printf(" ");
        printf("%c",hangmanOutput[i]);   /** to Show the original Word With blanks and right Input alphabet**/
    }

    getchar();
    }

      if(wrongTry <= 0)       /**if the player can not guess the whole word in 5 chances**/
      {
          printf("\n\n\t The Word was %s ",hangmanWord);
	      printf("\n\n\t Better luck next!!!");

      }
getchar();
return 0;
}



void showHangman(int choice)           /**This function is to show the hangman figure after each wrong try**/
 {

    switch(choice)
    {

     case 0:
	    printf("\n\t||===== ");
	    printf("\n\t||    | ");
	    printf("\n\t||   %cO/",'\\');
	    printf("\n\t||    | ");
	    printf("\n\t||   / %c",'\\');
	    printf("\n\t||      ");
	    break;
     case 1:
	    printf("\n\t||===== ");
	    printf("\n\t||    | ");
	    printf("\n\t||   %cO/",'\\');
	    printf("\n\t||    | ");
	    printf("\n\t||     %c",'\\');
	    printf("\n\t||      ");
	    break;
     case 2:
	    printf("\n\t||===== ");
	    printf("\n\t||    | ");
	    printf("\n\t||   %cO/",'\\');
	    printf("\n\t||    | ");
	    printf("\n\t||      ");
	    printf("\n\t||      ");
	    break;
     case 3:
	    printf("\n\t||===== ");
	    printf("\n\t||    | ");
	    printf("\n\t||   %cO/",'\\');
	    printf("\n\t||      ");
	    printf("\n\t||      ");
	    printf("\n\t||      ");
	    break;
     case 4:
	    printf("\n\t||===== ");
	    printf("\n\t||    | ");
	    printf("\n\t||   %cO ",'\\');
	    printf("\n\t||      ");
	    printf("\n\t||      ");
	    printf("\n\t||      ");
	    break;
     case 5:
	    printf("\n\t||===== ");
	    printf("\n\t||    | ");
	    printf("\n\t||    O ");
	    printf("\n\t||      ");
	    printf("\n\t||      ");
	    printf("\n\t||      ");
	    break;
      }
      return;
}