#include <stdio.h>
#include <string.h>

int i,j,menu,num_of_rotations,num,place,insert=0,flag=1;
char sentence[30],output[30],arr[30],tav,direction;


void printMenu();
int checkChars(char str[]);
int maxWordLength(char str[]);
int countWords(char str[]);
void inputSent(char str_in[],int k, char str_out[],int n);
void printSent(char str[], int n);
void revSent(char str[]);
void rolSent(char str[], int m);
void rorSent(char str[], int m);
void subSent(char str[], int k);
int WordLast(char str[], int wordIndex);
int WordFirst(char str[], int wordIndex, int end);
void SortSent(char str[], char direction);
int SearchWord(char str[], char word[]);
void main()
{
	do{

		printMenu();
		scanf("%d",&menu);


	switch(menu)
	{
	case 1 :
			getchar(); //In order to ignore the enter we insert after we chose option 1.

			for(i=0;i<strlen(sentence);i++)
				sentence[i]=' ';
			sentence[i]= '\0';

			for(i=0;i<strlen(output);i++)
				output[i]=' ';
			output[i]= '\0';
			
			printf("Please, enter your sentence >");
			i=0;
			
 			while((tav= getchar())!='\n') //That way we can take every space.
			{
				sentence[i]=tav;
				i++;
			}

			sentence[i]='\0';
				inputSent(sentence,strlen(sentence),output,strlen(output));
			
			break;

	case 2 :
			if(insert)
				printSent(sentence,strlen(sentence));
			else
				printf("ERROR: The sentence is empty.\n\n");

			break;

	case 3 :
			
			if(insert)
				revSent(sentence);
			else
				printf("ERROR: The sentence is empty.\n\n");
			break;

	case 4 :
			if(insert)
			{
				scanf("%d",&num_of_rotations);

				rolSent(sentence,num_of_rotations);
			}
			else
				printf("ERROR: The sentence is empty.\n\n");
			break;

	case 5 :
			if(insert)
			{
				scanf("%d",&num_of_rotations);

				rorSent(sentence,num_of_rotations);
			}
			else
				printf("ERROR: The sentence is empty.\n\n");
			break;


	case 6 :
			if(insert)
			{
			if((tav=getchar())=='\n')
				direction= 'A';
			else
				direction=getchar();


			if((direction=='A')||(direction=='D'))
				SortSent(sentence,direction);
			}
			else
				printf("ERROR: The sentence is empty.\n\n");

		break;
	case 7 :
			if(insert)
			{
			scanf("%s",&arr);

			place= SearchWord(sentence,arr);
			
			if(place)
				printf("The word %s is placed in the %d place.",arr,place);
			else
				printf("The word %s is not found.", arr);

			}
			else
				printf("ERROR: The sentence is empty.\n\n");
		break;

	case 8 :
			if(insert)
			{
			printf("The number of words in the sentence is %d.",countWords(sentence));
			}
			else
				printf("ERROR: The sentence is empty.\n\n");
		break;

	case 9 :
			if(insert)
			{
			  getchar();
			 scanf("%d",&num);
			 subSent(sentence,num);
			}
			else
				printf("ERROR: The sentence is empty.\n\n");
			
		break;
	case 10 :
		flag=0;
		break;
	default :
		printf("ERROR: Incorrect command, try again.\n");
		
		break;
		

	
	}

	}while(flag);
}



void printMenu()
{
	printf("\n********   Main menu   ********\n\n1 :  Input the sentence\n2 :  Print the sentence\n3 :  Reverse the sentence\n4 :  Rotate left N\n5 :  Rotate right N\n6 :  Sort the sentence\n");
	printf("7 :  Search the word\n8 :  Count number of words\n9 :  Display substring M\n10 : Quit\n\n****************************\nPlease, enter your choise >");
}

int checkChars(char str[])
{
	int counter=0;

	i=0; //Start checking the characters from the first cell.
	while(str[i]!='\0')
	{
		if(((str[i]>='A')&&(str[i]<='Z'))||((str[i]==' '))) 
			counter++;
		else
			return 0; //Continue the check only if all characters are capital letters or spaces.

		i++;
	}

	if(counter<=30) // Approving the input line only if it has 30 characters or less.
		return 1;
	else
		return 0;

}

int maxWordLength(char str[])
{
	int i=0,j=0, counter[30]={0},max,num_of_words,c;// Set a counter of maximum 30 characters because we have maximum 30 words.
	
	num_of_words= countWords(str);

	for(i=0; i<num_of_words;i++)
	{
		c=0;
		while((str[j]>='A')&&(str[j]<='Z')) //Continue increase the counter c as long as we are in the same letter.
		{
			c++;
			j++;
		}
		counter[i]=c; // for the word number i we counted c letters.
		j++;
	}

	i=0;
	max= counter[0]; // Intializing the first word's number of letters as the maximum number of letters.
	while(counter[i]) // As long as the number of words.
	{
		if(max<counter[i]) //If there is a word with more letters then the previous maximum, we define this word as the one with the maximum number of letters.
			max= counter[i];
		i++;
	}
	return max;
}

int countWords(char str[])
{
	int count=0;
	i=0;
	 //Go all over the sentence array looking for a cell with letter followed by a cell with space, and define it as a word and count the amount of all words found. 
	while(i<strlen(str))
	{
		if((str[i]>='A')&&(str[i]<='Z')&&((str[i+1]==' ')||(str[i+1]=='\0')))
			count+=1;
			i++;
	}

	return count;
}

void inputSent(char str_in[],int k, char str_out[],int n)
{

		if(checkChars(str_in)) //Sending the sentence array to the function checking if the sentence is leggal.
		{
			for(i=0;i<k;i+=1) //If the sentence is leggal it will be copied to the output string.
				str_out[i]= str_in[i];

	//In case the output string is larger then the input string, it should get spaces instaid of the letters that were there before and did not get replaced in the new shorter sentence.
			for(i=k;i<n;i+=1) 
				str_out[i]=' ';

			printf("%s\n",str_out);
			insert=1; //Confirm that the sentence exist and leggal, So the other cases could run.
		}

		else
		{
			printf("ERROR: Incorrect data, try again.\n");
			for(i=0;i<strlen(str_out);i++) 
				str_out[i]=' ';
			str_out[i]='\0';
		}
}

void printSent(char str[], int n)
{
	j=0;
	for(i=0; i<n; i++)
	{
			while(str[i]!=' ')
			{ // Copy only letters, in order to avoid unnecessary spaces.
				output[j]= str[i];
				i++;
				j++;
			}
			if((str[i]==' ')&&(str[i-1]!=' ')&&(j!=0)) 
			{ //Copy only the first space after the last letter in order to make sure we have only one space.
				output[j]= ' ';
				j++;
			}
				
	}

	printf("%s\n",output);
}

void revSent(char str[])
{
  int i,word,end,start,num_of_words;

	num_of_words= countWords(str);

	for(word=num_of_words; word>0; word--)
	{
		end= WordLast(str,word); //Giving the last index of the specific word.
		start= WordFirst(str,word,end); //Giving the first index of the specific word.

		for(i=start; i<=end; i++)//Printing a specific word 
			putchar(str[i]);
		putchar(' ');
		
	}
	printf("\n");

}

void rorSent(char str[], int m)
{
	int num_of_words,end,word,start;

	num_of_words= countWords(str);

	j=0;
	if(m<=num_of_words)
	{

	for(word= num_of_words-m+1; word<=num_of_words; word++)
	{
		end= WordLast(str,word); //Giving the last index of the specific word.
		start= WordFirst(str,word,end); //Giving the first index of the specific word.

		for(i=start; i<=end; i++)
			putchar(str[i]);
		putchar(' ');
		j++;
	}

	
	end= WordLast(str,num_of_words-m); //Giving the last index of the last word that didn't rotate.

		for(i=0; i<=end; i++)
			putchar(str[i]);
	
		
	}
	else
		printf("ERROR: Incorrect command, try again.");
	
	printf("\n");
}

void rolSent(char str[], int m)
{
	int num_of_words,end,word,start;

	num_of_words= countWords(str);

	j=0;
	if(m<=num_of_words)
	{

	for(word=m+1; word<=num_of_words; word++)
	{
		end= WordLast(str,word); //Giving the last index of the specific word.
		start= WordFirst(str,word,end); //Giving the first index of the specific word.

		for(i=start; i<=end; i++)
			putchar(str[i]);
		putchar(' ');
		j++;
	}

	
	end= WordLast(str,m); //Giving the last index of the last word that didnt rotate.

		for(i=0; i<=end; i++)
			putchar(str[i]);
	
		
	}
	else
		printf("ERROR: Incorrect command, try again.");
	printf("\n");
}

void subSent(char str[], int k)
{
	int max_word_len,in=0,place,ind=0,t,number;
	char out[60], temp[30], temp2[30],tempo[30];

	max_word_len= maxWordLength(str);
	i=0;

	strcpy(tempo,str);

	for(j=0; j<max_word_len-1;j++)
	{
		if(tempo[j]!=' ')
			temp2[j]= tempo[j];
	}
	temp2[j]= '\0';
	strcat(tempo,temp2); // The string must continue circulary as the length of str+ length of the most large word.
	

if(k<=max_word_len)
{ 		
	number=0;
	while(tempo[i+1]!='\0') //Start checking for multiply words.
	 {
		 for(j=0; j<k; j++)
			temp[j]=' ';
		temp[j]='\0';
		i=number;
		 //Create an array with k length.
		for(t=0; t<k; t++,i++)
		{
			
			if((tempo[i]!=' '))
				temp[t]= tempo[i];

			else if(tempo[i+1]!='\0')
				temp[t]= tempo[++i];
			else
			{
				for(t=0; t<k; t++)
					temp[t]=' ';
			}

		}

		temp[t]='\0';

		if(tempo[i+1]!='\0')
			number++;
		else
			break;
		
		

		place= SearchWord(out,temp);

		if(!place) //The word does not exist yet in the array.
		{
			for(t=0; t<k; t++)
			{
				out[ind]= temp[t];
				ind++;
			}
			out[ind]=' ';
			ind++;
			out[ind]= '\0';

			printf("%s\n",temp);
				
		}



		
	}
	
	}
	else
		printf("ERROR: Incorrect command, try again.\n");

}

int WordLast(char str[], int wordIndex)
{
	int index=0,i,start,end;

	for(i=0;index<wordIndex; i+=1)
	{  //The last letter of word is define as the cell with a letter, followed by a cell with space or end of array.
		if((str[i]>='A')&&(str[i]<='Z')&&((str[i+1]==' ')||(str[i+1]=='\0')))
			index++; //continue increase the index untill we find the index of the last letter of the word we are looking for.
	}


	end = i-1;

	return end;
}

int WordFirst(char str[], int wordIndex, int end)
{
	int start;
		if(wordIndex!=1)
		{
	/*From the last index of a specific word we found, we start decrease the index untill we get to a space,
	which indicate that this is the index of the begining of a specific word. */
			while((str[end]!=' '))
				end-=1;

			start=end+1;
		}
		else
			start=0; //If we are looking for the first word in the sentence, so the first index of the word is 0.
	
	return start;

}

void SortSent(char str[], char direction)
{
	char temp[30],tempo,zmani;
	int end[30]={0},start[30]={0}, temp1, temp2,k,temp3,temp4, num_of_words,a,b;

	num_of_words= countWords(str);

	for(i=0; i<num_of_words; i++) 
	{
		a= WordLast(str,i+1); //Create an array with all the last indexes of all words.
		end[i]=a;
		b= WordFirst(str,i+1,a);//Create an array with all the first indexes of all words.
		start[i]=b;
		temp[i]= str[b]; //Create an array with all the first letters of all words.
	}

for(j=0; j<num_of_words-1;j++)
{
	for(i=0; i<num_of_words-1;i++)
	{
			if(direction=='A') //In case the user asked for an acending direction.
			{
				if(temp[i]> temp[i+1])
				{
					tempo= temp[i];
					zmani= temp[i+1];
					temp[i+1]=tempo;
					temp[i]= zmani;

					temp2= start[i];
					temp1= start[i+1];
					start[i+1]= temp2;
					start[i]= temp1;

					temp3= end[i];
					temp4= end[i+1];
					end[i+1]= temp3;
					end[i]= temp4;
				}

			}
			else //In case the user asked for an decending direction.
			{
				if(temp[i]< temp[i+1])
				{
					tempo= temp[i];
					zmani= temp[i+1];
					temp[i+1]=tempo;
					temp[i]= zmani;

					temp2= start[i];
					temp1= start[i+1];
					start[i+1]= temp2;
					start[i]= temp1;

					temp3= end[i];
					temp4= end[i+1];
					end[i+1]= temp3;
					end[i]= temp4;
				}

			}
	}
}
	for(i=0; i<num_of_words; i++) 
	{ //Printing all words according to the ordered arrays of starts and ends indexes.
		for(k=start[i]; k<=end[i]; k++)
			putchar(str[k]);
		putchar(' '); //Printing only one space after each word.
		
	}

	printf("\n");

}

int SearchWord(char str[], char word[])
{
	int num_of_words,start,end,k=0;

	num_of_words= countWords(str);

	for(i=0; i<num_of_words; i++)
	{
		end= WordLast(str,i+1); //Find final index of each word.
		start= WordFirst(str,i+1,end); //Find start index of each word.

		for(j=start; j<=end; j++) //Checking all the letters in the word.
		{
			if(word[k]!=str[j])
			{
				k=0; //Even if one letter is not match, we break the loop and checking the next word.
				break;
			}
			else
				k++;
		}
		

		if(j==end+1)
			return i+1;
	}
		if(i==num_of_words)
			return 0;
	

}
