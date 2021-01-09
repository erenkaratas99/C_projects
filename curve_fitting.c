//curve fitting for the type y=ax^b 

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

float maxFinder(float x[], int nx); //function of maximum finder (explained in the end)
float minFinder(float y[],int n); //function of maximum finder (explained in the end)
int n_1,n_2,n_3,n_4,n_5;
int main()
{
	printf("This program will follow these steps  ==>\nStep1: Finding minimum value of FIRST INPUT SET\nStep2: Forming a group with maximum values of LAST 4 INPUTS\n");
	printf("Step3: Finding minimum value of the new group\nStep4: OUTPUT= Greater value of Step1 and Step3\n---------------------------\n");
	printf("Size of FIRST INPUT SET : ?\n"); 
	scanf("%d",&n_1);
	
	//taking the size of array
	float *input1 = (float*)malloc(sizeof(float)*n_1);              //array definition
	int i = 0;
	
	for(i;i<n_1;i++)
	{
		printf("**********************\n");
		printf("Enter the %d. number of FIRST INPUT SET: \n",i+1);   //taking the numbers of array (ARRAY = INPUT SET)
		scanf("%f",&input1[i]);		
	} 
	


	float OutputMax[2]; 	//setting here an another array to use in output logic (finding maximum of 2 values at the end)
	OutputMax[0] = minFinder(input1,n_1); 
	printf("__________\nMinimum of FIRST INPUT SET: %.2f\n__________\n",OutputMax[0]); //printing the minimum number of the array 
	
	   
	float MaxofMaxs[4]; 	//this is the array of last 4 input sets' max values to calculate their minimum


	printf("\n-----------------\n");
	printf("\nSize of SECOND INPUT SET: ?\n");    //taking the 2nd array (input set)
	scanf("%d",&n_2);
	float *input2 = (float*)malloc(sizeof(float)*n_2);
	i = 0;
	for(i;i<n_2;i++)
	{
		printf("**********************\n");
		printf("enter the %d. number of SECOND INPUT SET : \n",i+1);
		scanf("%f",&input2[i]);		
	} 
	MaxofMaxs[0] = maxFinder(input2,n_2); 					//indexing the array of last 4 input sets' maximums to find their min value later
	
	
	printf("\n-----------------\n");
	printf("\nSize of THIRD INPUT SET : ?\n");			//taking the 3rd array (input set)
	scanf("%d",&n_3);
	float *input3 = (float*)malloc(sizeof(float)*n_3);
	i = 0;
	for(i;i<n_3;i++)
	{
		printf("**********************\n");
		printf("enter the %d. number of THIRD INPUT SET : \n",i+1);
		scanf("%f",&input3[i]);		
	} 
	MaxofMaxs[1] = maxFinder(input3,n_3); 			//indexing the array 
	
	
	printf("\n-----------------\n");
	printf("\nSize of FOURTH INPUT SET : ?\n");				//taking the 4th array (input set)
	scanf("%d",&n_4);
	float *input4 = (float*)malloc(sizeof(float)*n_4);
	i = 0;
	for(i;i<n_4;i++)
	{
		printf("**********************\n");
		printf("enter the %d. number of FOURTH INPUT SET : \n",i+1);
		scanf("%f",&input4[i]);		
	} 
	MaxofMaxs[2] = maxFinder(input4,n_4); 				//indexing the array
	
	
	printf("\n-----------------\n");
	printf("\nSize of FIFTH INPUT SET : ?\n");				//taking the 5th array (input set)
	scanf("%d",&n_5);
	float *input5 = (float*)malloc(sizeof(float)*n_5);
	i = 0;
	for(i;i<n_5;i++)
	{
		printf("**********************\n");
		printf("enter the %d. number of FIFTH INPUT SET : \n",i+1);
		scanf("%f",&input5[i]);		
	} 
	MaxofMaxs[3] = maxFinder(input5,n_5); 			//indexing the array
	
	
	printf("\n------------------\n");
	printf("Maximum values of 2nd, 3rd, 4th, 5th INPUT SETS respectively : \n");	//maximum values of entered inputs from...
	for(i=0;i<4;i++)																//2nd 3rd 4th 5th input sets and here... 
	{																				//I'm printing them to be observed by the user.
		printf("%.2f\t",MaxofMaxs[i]);
	}
	printf("\n---------------------\n");
	
	
	OutputMax[1] = minFinder(MaxofMaxs,4); //setting the 2nd index of the array to use in output logic
	
	printf("Minimum value of the set of maximum values of LAST 4 INPUT SETS : %.2f \n",OutputMax[1]); //minimum value 
	printf("************\n");
	
	

	if(OutputMax[0]>OutputMax[1]) //printing the output number from the diagram
	{
		printf("Maximum value from diagram : %.2f\n",OutputMax[0]);
		printf("************\n");
	}
	else if(OutputMax[1]>OutputMax[0])																
	{
		printf("Maximum value from diagram : %.2f\n",OutputMax[1]);
		printf("************\n");
	}
	else if(OutputMax[1]==OutputMax[0])
	{
		printf("There is an equality!\n");
		printf("************\n");
	}
	
	char choice;
	
	printf("Do you want to create a .txt file? (Y/N)\n");
	choice = getchar();
	scanf("%c",&choice);
	
	FILE *min_max;
	int counter = 0;
	switch(choice)
	{
		case 'Y':
		case 'y':
			min_max = fopen("min_max_res.txt","w");
			if (min_max == NULL)				//to know the situation of an error while opening the file
			{
    			printf("Error opening file!\n");
    				exit(1);
			}
			fprintf(min_max,"FIRST INPUT SET:\n");
			for(counter;counter<n_1;counter++)
			{
				fprintf(min_max,"[%d]:\t%.2f\n",counter+1,input1[counter]);
			}
			fprintf(min_max,"Minimum value of FIRST INPUT SET = %.2f\n",OutputMax[0]);
			fprintf(min_max,"-------------------\n");
			counter = 0;
			fprintf(min_max,"SECOND INPUT SET:\n");
			for(counter;counter<n_2;counter++)
			{
				fprintf(min_max,"[%d]:\t%.2f\n",counter+1,input2[counter]);
			}
			fprintf(min_max,"-------------------\n");
			counter = 0;
			fprintf(min_max,"THIRD INPUT SET:\n");
			for(counter;counter<n_3;counter++)
			{
				fprintf(min_max,"[%d]:\t%.2f\n",counter+1,input3[counter]);
			}
			fprintf(min_max,"-------------------\n");
			counter = 0;
			fprintf(min_max,"FOURTH INPUT SET:\n");
			for(counter;counter<n_4;counter++)
			{
				fprintf(min_max,"[%d]:\t%.2f\n",counter+1,input4[counter]);
			}
			fprintf(min_max,"-------------------\n");
			counter = 0;
			fprintf(min_max,"FIFTH INPUT SET:\n");
			for(counter;counter<n_5;counter++)
			{
				fprintf(min_max,"[%d]:\t%.2f\n",counter+1,input5[counter]);
			}
			fprintf(min_max,"-------------------\n");
			counter = 0;
			fprintf(min_max,"Maximum value set of LAST 4 INPUT SETS :\n");
			for(counter;counter<sizeof *MaxofMaxs;counter++)
			{
				fprintf(min_max,"%d. : %.2f\n",counter+1,MaxofMaxs[counter]);
			}
			fprintf(min_max,"*******************\n");
			if(OutputMax[0]>OutputMax[1]) //printing the output number from the diagram
			{
				fprintf(min_max,"Maximum value from diagram : %.2f\n",OutputMax[0]);
				fprintf(min_max,"************\n");
			}
			else if(OutputMax[1]>OutputMax[0])																
			{
				fprintf(min_max,"Maximum value from diagram : %.2f\n",OutputMax[1]);
				fprintf(min_max,"************\n");
			}
			else if(OutputMax[1]==OutputMax[0])
			{
				fprintf(min_max,"There is an equality!\n");
				fprintf(min_max,"*******************\n");
			}
			fprintf(min_max,"Thanks!\n");
			
			fclose(min_max);
			printf("Data file has been created!\n");
			break;
		case 'n':
		case 'N':
			printf("Not creating a file!\n");
			break;
	}
	printf("Thanks!\n");
	
	return 0;
}

float maxFinder(float x[], int nx) //maximum value finder function
{
	  
	int maxf =1;
	float max = x[0];
	for(maxf;maxf<nx;maxf++)
	{
		if(max<=x[maxf])
		{
			max = x[maxf];
		}
	}
	return max;
}

float minFinder(float y[],int n) //minimum value finder function
{
	int minf =1;
	float min = y[0];
	for(minf;minf<n;minf++)
	{
		if(min>=y[minf])
		{
			min= y[minf];
		}	
	}
	
	return min;
}

