#include<stdio.h>
#include<string.h>
int main()
{
int i,j,c,count=0,ans=0,flag=0,*ptr;
char a[1][6]={"man"}; // Characters to Guess

char b[10],alpha;
char d='_';

c=strlen(&a[0][0]);
printf("\t\t\t ** HANGMAN ** \n");
	printf("\n\t\t\t**************\t\t\t");
		printf("\n\t\t\t..............\n\n\t\t\t  ");
for(j=0;j<c;j++)
	  {
	  printf("%c ",d);
	  b[j]=d;
	  }
	  printf("\n\t\t\t..............\t\t\t");
	  printf("\n\t\t\t**************");

/*This loop is used to guess one letter at a time from the secret word and you will repeat this process untill 
all the correct letters have been guessed or the user has entered 5 wrong letters.
*/
while (count<6)//||(ans<c))
 {
 flag=0;
	   printf("\n\n\n\t Plz Enter a Character	");
		alpha=getchar();
		for(i=0;i<c;i++)
		{
			if (alpha==a[0][i])
		    {
		   		b[i]=a[0][i];
		   		flag=1;
				ans++; 
			}
		}
		printf("\n\t\t\t ** HANGMAN ** \n");
		printf("\n\t\t\t**************\t\t\t");
		printf("\n\t\t\t..............\n\n\t\t\t  ");
		for(i=0;i<c;i++)
		printf("%c ",b[i]);
		printf("\n\t\t\t..............\t\t\t");
		printf("\n\t\t\t**************");

		if(flag==0)
			{
		count++;
		printf("\n\t\t%c is a Wrong Guess",alpha);
		printf("\n\t\t (You Have %d More Guesses Left)",6-count);
			}

		else{
		printf("\n\t\t You Are Correct !!");
	   printf("\n\t\t( You Have %d More Words To Go)",c-ans);
	   		}
		if(ans==c) break;
 }
 if(ans==c) printf("\n\n\t You Won !!");
 else printf("\n\t\t  You Lost !!\n \t\t **SORRY  YOU ARE HANGED**");
return 1;
}//End of main function
