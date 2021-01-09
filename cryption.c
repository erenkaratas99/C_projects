#include <stdio.h>
#include <stdlib.h>



int main()
{
	char text[1000]; //preparation phase
	
	printf("enter your message: \n"); //user enters the message
	gets(text); //getting our message to encrypt
	
	char alphabet[26] = "abcdefghijklmnopqrstuvwxyz"; //real alphabet
	char encryAlphabet[26] = "hysagobmxjfdrecnvpkluqzwti"; 	// mixed alphabet to use in encryption
	
	int index = 0; //preparation phase
	
	//user enters a text, loop encrypt the message	
	while(text[index]!='\0') 
	{
		int index2 =0;
		while(alphabet[index2]!='\0')
		{
			
			if(text[index]==alphabet[index2])
			{
				text[index] = encryAlphabet[index2];
				index2++;
				break;
			}
			else
			{
				index2++;
				continue;
			}
			
		}
		index++;
	}
	
	int print = 0; //printing encrypted text
	printf("\nEncrypted: \n");
	while(text[print]!='\0')
	{
		
		printf("%c",text[print]);
		print++;
	}
	
	//decryption
	printf("\n----\n");
	int decIndex = 0;
	while(text[decIndex]!='\0')
	{
		int decIndex2 = 0;
		while(encryAlphabet[decIndex2]!='\0')
		{
			
			if(text[decIndex]==encryAlphabet[decIndex2])
			{
				
				text[decIndex] = alphabet[decIndex2];
				decIndex2++;
				break;
			}
			else
			{
				decIndex2++;
				continue;
			}
		}
		decIndex++;
	}
	
	printf("Decrypted : \n");
	int decprint = 0;
	while(text[decprint]!='\0')
	{
		printf("%c",text[decprint]);
		decprint++;
	}
	return 0;

}
