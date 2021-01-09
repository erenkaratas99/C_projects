//Q2 W/FÝLE

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() 
{
	printf("Hello!\n");
	printf("Function ===> y=a*x**b\n");
	printf("This program using 'Least Square Regression Method' to obtain a,b .\n");
	printf("Outputs will be the most appropriate a,b for the entered x's and y's.\n");
	printf("*********************************************************************\n"); //presenting, preparation phase 
	int n;
	float xy[1000][2]; //float input to store and index x,y values
	
	printf("How many data points you want to enter : ? [Points will be denoted as P(x,y)] \n");
	scanf("%d",&n); //taking the number of data points from the user 
	
	if(n<=0)
	{
		printf("Number of data points cannot be zero nor a negative number!\n");
		printf("Enter an another number of data points : \n");						//to prevent missunderstanding
		scanf("%d",&n);
	}
	
	int i = 0;
	printf("*******************************************************************************\n");
	for(i;i<n;i++) 				//taking the x and y values from the user
	{
		printf("x of P[%d] : ? \n",i+1);
		scanf("%f",&xy[i][0]);
		
		printf("y of P[%d] : ? \n",i+1);
		scanf("%f",&xy[i][1]);
		
		if(xy[i][0]<=0 || xy[i][1]<=0)
		{
			while(xy[i][0] <=0 || xy[i][1]<=0)
			{
				
				printf("Please enter a point in the 'First Quadrant' !\n");
				printf("x of P[%d] : ? \n",i+1);
				scanf("%f",&xy[i][0]);
				
				printf("y of P[%d] : ? \n",i+1);
				scanf("%f",&xy[i][1]);
			}
		}
			
			
	}
	
	printf("\n*************\n");
	int j = 0;
	printf("Corresponding values of entered numbers :\n"); //computing the values given from the user 
	for(j;j<n;j++)
	{
		printf("x[%d] : %.2f\n",j+1,xy[j][0]);
		
	}
	printf("***********");
	for(j=0;j<n;j++)
	{
		printf("\ny[%d] : %.2f",j+1,xy[j][1]);
	}
	
	float sumx = 0, sumy= 0, sumxy= 0, sumx_sq=0; //summation elements to use in regression formula, sum ==> "sum of" , sumx_sq = sum of x squared 
	
	//least square regression method : 
	//y=ax^b ==> I take the logarithms of both sides and obtain ==> log(y) = log(ax^b)  ==> log(y) = log(a) + b*log(x) [according to logarithm laws]
	//now our equation is in the form of y = mx + b
	// I denote our variables as b ==> slope(m), log_a ==> constant(b)
	//to solve them simultaneously I used summation and according to Least Square Regression method;
	// b = (n*sumxy*sumy)/(n*sumx_sq - sumx*sumx)
	// log_a = (sumy - b*sumx)/n
	
	
	for(i=0;i<n;i++) 			//for loop to sum up
	{
		sumx = sumx + log(xy[i][0]);
		sumy = sumy + log(xy[i][1]);
		sumxy = sumxy + log(xy[i][0])*log(xy[i][1]);
		sumx_sq = sumx_sq + log(xy[i][0])*log(xy[i][0]);
	}
	
	float b, a, log_a; //least square formula element log_a and a,b from our equation
	
	b = (float)(n*sumxy-sumx*sumy)/(n*sumx_sq - sumx*sumx);
	log_a = (float)(sumy-b*sumx)/n;
	
	a = exp(log_a); 		//since log_a from least square formula is in the logarithmic form we need to transform it
	
	char choice;
	
	printf("\n------------\n");
	printf("Most appropriate a,b for given P(x,y)'s is : \n");
	printf("a = %.2f\nb = %.2f\n",a,b);
	printf("-------------------\n");
	
	
	
	
	printf("Do you want to create a file? (Y/N)\n"); //I wanted to ask user to not occupy his/her storage without any permission
	choice = getchar();
	scanf("%c",&choice); //y ==> yes , n ==> no
	FILE *ab;			//file 
	int counter = 0;
	switch(choice)
	{
		case 'Y':
		case 'y':
			ab = fopen("ab_res.txt","w");
			if (ab == NULL)				//to know the situation of an error while opening the file
			{
    			printf("Error opening file!\n");
    				exit(1);
			}
			fprintf(ab, "\tx:\t\ty:\n");
			for(counter;counter<n;counter++)
			{
				fprintf(ab,"P[%d]:\tx[%d]=%.2f\ty[%d]=%.2f\n",counter+1,counter+1,xy[counter][0],counter+1,xy[counter][1]);
			}
			fprintf(ab,"\nMost appropriate a,b is ==> (a,b) = (%.3f,%.3f)\n",a,b);
			fprintf(ab,"Thanks!");
			fclose(ab);
			printf("Data file has been created!\n");
			break;
		
		case'n':
		case'N':
			printf("Not creating a file!\n");
			break;
				
	}
		
	printf("-----------\nThanks!\n");	
	
	return 0;
} 

