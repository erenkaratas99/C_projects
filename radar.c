//Radar


//10x10 zeros matrix represents the radar screen from top view, plane makes a random move with maximum manoeuvre angle of 45. Code tries to estimate location of the plane
//at the t=7 from its previous move

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void DisplayScreen(int a[10][10]); //the function to print the current RADAR Screen 
void fill_w_zeros(int b[10][10]); //the function to create a 10x10 zeros matrix

void Diagonal(int n,int last_t, int c[10][10]);   //depending on the previous manoeuvre of the plane...
									  		   	 //the next move of the plane could be occur with the maximum absolute degree of 45 (given in the question)...
void Straight(int n, int d[10][10]); 			//therefore I've impelemented 2 functions that called Diagonal and Straight (the names referred the previous move of the plane)...
												//to determine the next move of the plane's properly (to answer properly)
									
int probs[18] = {-1,0,1,-1,0,1,-1,0,1,-1,0,1,-1,0,1,-1,0,1}; //this is the domain of probabilities (-1,0,1) to add or subtract from coordinates to...
															//obtain their adjacents
															//rand() % 18 used below for random indexing (the main logic is sweepstake)

int resultant_x;		//those are the variables used while calculating the resultant vector
int resultant_y;														
void Resultant(int res1,int res2); //the function definition is given below (used for calculating the resultant vector)																
int i;
int j;
int x[100]; //x axis 
int y[100];	//y axis
int temp_x;//temporary value
int temp_y;//temporary value
int screen[10][10]; //RADAR Screen Matrix
int main()

{
	
	x[0] = 8;
	y[0] = 8;	//I've gave the numbers by hand to the program but...
				//it could be done in several ways including scanf("%d %d",&x[0],&y[0]); etc.
	
	screen[x[0]][y[0]]=1;
	printf("RADAR Screen at t[1]\n\n");
	DisplayScreen(screen);
	printf("\nThe first coordinate that plane have seen ==> x[0],y[0] = (%d,%d)\n",x[0],y[0]);
	
	while(1)	//giving the 2nd coordinate to the system randomly
	{
		temp_x = x[0]+probs[rand()%2];
		temp_y = y[0]+probs[rand()%2];
		x[1] = temp_x; 
		y[1] = temp_y;
		screen[x[1]][y[1]] = 1;
		
		if(x[0] != x[1] && y[0] != y[1])
		{
			break;
		}
	}
	printf("\nRADAR Screen at t[2]\n\n");
	DisplayScreen(screen);
	
	printf("\t.\n\t.\n\t.\n\t.\n\t.");
	printf("\nRADAR Screen at t[6]\n");
	Diagonal(1,5,screen);		//calling mover function to obtain manoeuvre (first 2 integers can be changed for asked conditions) 1==> start at t[2] & 5==> stop at t[6] and estimate t[7]
	printf("\n");
	DisplayScreen(screen);
	


	printf("\nThe last coordinate that plane have seen ==> x[6],y[6] = (%d,%d)\n",x[5],y[5]); //last coordinates at t[6]; (question ask to estimate the location at t[7])
	
	printf("\n");
	if(x[5]-x[4]==-1&&y[5]-y[4]==1) 	//this if-else sequence is based on the vectoral positioning and angle...
	{									//it subtracts 2 latest points and gives the most proper estimation tuple
		printf("potential coordinates in t[7]:\n");
		printf("x[7],y[7] = (%d,%d)\n",x[5]-1,y[5]);
		printf("x[7],y[7] = (%d,%d)\n",x[5]-1,y[5]+1);
		printf("x[7],y[7] = (%d,%d)\n",x[5],y[5]+1);
	}
	else if(x[5]-x[4]==-1&&y[5]-y[4]==-1) 
	{
		printf("Potential coordinates at t[7]:\n");
		printf("x[7],y[7] = (%d,%d)\n",x[5]-1,y[5]);
		printf("x[7],y[7] = (%d,%d)\n",x[5],y[5]-1);
		printf("x[7],y[7] = (%d,%d)\n",x[5]-1,y[5]-1);
	}
	else if(x[5]-x[4]==1&&y[5]-y[4]==-1)
	{
		printf("Potential coordinates at t[7]:\n");
		printf("x[7],y[7] = (%d,%d)\n",x[5]+1,y[5]);
		printf("x[7],y[7] = (%d,%d)\n",x[5],y[5]-1);
		printf("x[7],y[7] = (%d,%d)\n",x[5]+1,y[5]-1);
	}
	else if(x[5]-x[4]==1&&y[5]-y[4]==1)
	{
		printf("Potential coordinates at t[7]:\n");
		printf("x[7],y[7] = (%d,%d)\n",x[5]+1,y[5]+1);
		printf("x[7],y[7] = (%d,%d)\n",x[5],y[5]+1);
		printf("x[7],y[7] = (%d,%d)\n",x[5]+1,y[5]);
	}
	else if(x[5] - x[4] == 0 || y[5] - y[4]==0)
	{
		if(x[5] - x[4] == -1)
		{
			printf("Potential coordinates at t[7]:\n");
			printf("x[7],y[7] = (%d,%d)\n",x[5]-1,y[5]-1);
			printf("x[7],y[7] = (%d,%d)\n",x[5]-1,y[5]);
			printf("x[7],y[7] = (%d,%d)\n",x[5]-1,y[5]+1);			
		}
		else if(x[5] - x[4] == 1)
		{
			printf("Potential coordinates at t[7]:\n");
			printf("x[7],y[7] = (%d,%d)\n",x[5]+1,y[5]-1);
			printf("x[7],y[7] = (%d,%d)\n",x[5]+1,y[5]);
			printf("x[7],y[7] = (%d,%d)\n",x[5]+1,y[5]+1);	
		}
		else if(y[5] - y[4]==1)
		{
			printf("potential coordinates in t[7]:\n");
			printf("x[7],y[7] = (%d,%d)\n",x[5]-1,y[5]+1);
			printf("x[7],y[7] = (%d,%d)\n",x[5]+1,y[5]+1);
			printf("x[7],y[7] = (%d,%d)\n",x[5],y[5]+1);	
		}
		else if(y[5] - y[4]==1)
		{
			printf("Potential coordinates at t[7]:\n");
			printf("x[7],y[7] = (%d,%d)\n",x[5]-1,y[5]-1);
			printf("x[7],y[7] = (%d,%d)\n",x[5],y[5]-1);
			printf("x[7],y[7] = (%d,%d)\n",x[5]+1,y[5]-1);
		}
	}
	printf("\n");
	Resultant(0,5); //index 0 ==> t[1], index 5 ==> t[6]
	
	return 0;
}

void DisplayScreen(int a[10][10]) //the function to print 10x10 matrix
{
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
}

void fill_w_zeros(int b[10][10])
{
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			b[i][j] = 0;
		}
	}
}

void Diagonal(int n,int last_t, int c[10][10])
{
	int temp;
	for(n;n<last_t;n++)	//"n" lasts until 4 because the first 2 point had been implemented
	{
		
		
		
		if(x[n]-x[n-1] == -1 && y[n]-y[n-1] == 1) //the purpose of the if-else sequence is creating a basic deciding mechanism whether if it is diagonol or not 
		{
			while(1) //while(1) runs and tries to find a proper coordinate until the break condition breaches...
			{		// before break condition temporary value is written into array of coordinates(axis')
				
				temp_x = x[n] + probs[rand()%18]; //using temporary values to avoid missing data
				temp_y = y[n] +probs[rand()%18];
				x[n+1] = temp_x;
				y[n+1] = temp_y;
				if((x[n+1]-x[n] == -1 && y[n+1] - y[n] == 1) || (x[n+1]-x[n] == 0 && y[n+1] - y[n] == 1) || (x[n+1]-x[n] == -1 && y[n+1] - y[n] == 0))
				{
					screen[x[n+1]][y[n+1]]=1;
					x[n+1] = temp_x;
					y[n+1] = temp_y;
					break;
				}
		
			}
		}
		else if(x[n]-x[n-1] == -1 && y[n]-y[n-1] == -1)
		{
			while(1)
			{
				
				temp_x = x[n] + probs[rand()%18];
				temp_y = y[n] +probs[rand()%18];
				x[n+1] = temp_x;
				y[n+1] = temp_y;
				
				if((x[n+1]-x[n] == -1 && y[n+1] - y[n] == -1) || (x[n+1]-x[n] == -1 && y[n+1] - y[n] == 0) || (x[n+1]-x[n] == 0 && y[n+1] - y[n] == -1))
				{
					screen[x[n+1]][y[n+1]]=1;
					x[n+1] = temp_x;
					y[n+1] = temp_y;
					break;
				}
		
			}
		}
		else if(x[n]-x[n-1] == 1 && y[n]-y[n-1] == -1)
		{
			while(1)
			{
				
				temp_x = x[n] + probs[rand()%18];
				temp_y = y[n] +probs[rand()%18];
				x[n+1] = temp_x;
				y[n+1] = temp_y;
				if((x[n+1]-x[n] == 0 && y[n+1] - y[n] == -1) || (x[n+1]-x[n] == 1 && y[n+1] - y[n] == -1) || (x[n+1]-x[n] == 1 && y[n+1] - y[n] == 0))
				{
					screen[x[n+1]][y[n+1]]=1;
					x[n+1] = temp_x;
					y[n+1] = temp_y;
					
					break;
				}
		
			}
		}
		else if(x[n]-x[n-1] == 1 && y[n]-y[n-1] == 1)
		{
			while(1)
			{
				
				temp_x = x[n] + probs[rand()%18];
				temp_y = y[n] +probs[rand()%18];
				x[n+1] = temp_x;
				y[n+1] = temp_y;
				if((x[n+1]-x[n] == 0 && y[n+1] - y[n] == 1) || (x[n+1]-x[n] == 1 && y[n+1] - y[n] == 1) || (x[n+1]-x[n] == 1 && y[n+1] - y[n] == 0))
				{
					screen[x[n+1]][y[n+1]]=1;
					x[n+1] = temp_x;
					y[n+1] = temp_y;
					break;
				}
		
			}
		}
		else
		{
			Straight(n,screen); //the other conditions stands for the Straight scenario
		}
		
	}
}

void Straight(int n, int d[10][10]) //the same logic in the "Diagonal" function works for here too
{
		
		
		if(x[n]-x[n-1] == -1 && y[n]-y[n-1] == 0)
		{
			while(1)
			{
				
				temp_x = x[n] + probs[rand()%18];
				temp_y = y[n] +probs[rand()%18];
				x[n+1] = temp_x;
				y[n+1] = temp_y;
				if((x[n+1]-x[n] == -1 && y[n+1] - y[n] == -1) || (x[n+1]-x[n] == -1 && y[n+1] - y[n] == 0) || (x[n+1]-x[n] == -1 && y[n+1] - y[n] == 1))
				{
					screen[x[n+1]][y[n+1]]=1;
					x[n+1] = temp_x;
					y[n+1] = temp_y;
					break;
				}
		
			}
		}
		else if(x[n]-x[n-1] == 1 && y[n]-y[n-1] == 0)
		{
			while(1)
			{
				
				temp_x = x[n] + probs[rand()%18];
				temp_y = y[n] +probs[rand()%18];
				x[n+1] = temp_x;
				y[n+1] = temp_y;
				if((x[n+1]-x[n] == 1 && y[n+1] - y[n] == -1) || (x[n+1]-x[n] == 1 && y[n+1] - y[n] == 0) || (x[n+1]-x[n] == 1 && y[n+1] - y[n] == 1))
				{
					screen[x[n+1]][y[n+1]]=1;
					x[n+1] = temp_x;
					y[n+1] = temp_y;
					break;
				}
		
			}
		}
		else if(x[n]-x[n-1] == 0 && y[n]-y[n-1] == 1)
		{
			while(1)
			{
				
				temp_x = x[n] + probs[rand()%18];
				temp_y = y[n] +probs[rand()%18];
				x[n+1] = temp_x;
				y[n+1] = temp_y;
				if((x[n+1]-x[n] == -1 && y[n+1] - y[n] == 1) || (x[n+1]-x[n] == 0 && y[n+1] - y[n] == 1) || (x[n+1]-x[n] == 1 && y[n+1] - y[n] == 1))
				{
					screen[x[n+1]][y[n+1]]=1;
					x[n+1] = temp_x;
					y[n+1] = temp_y;
					break;
				}
		
			}
		}
		else if(x[n]-x[n-1] == 0 && y[n]-y[n-1] == -1)
		{
			while(1)
			{
				
				temp_x = x[n] + probs[rand()%18];
				temp_y = y[n] +probs[rand()%18];
				x[n+1] = temp_x;
				y[n+1] = temp_y;
				if((x[n+1]-x[n] == -1 && y[n+1] - y[n] == -1) || (x[n+1]-x[n] == 0 && y[n+1] - y[n] == -1) || (x[n+1]-x[n] == 1 && y[n+1] - y[n] == -11))
				{
					screen[x[n+1]][y[n+1]]=1;
					x[n+1] = temp_x;
					y[n+1] = temp_y;
					break;
				}
		
			}
		}
		
		
}

void Resultant(int res1,int res2) //res1 and res2 is equal to the start and end coordinates
{
	//callculating the resultant vector 

	resultant_x = x[res2] - x[res1];
	resultant_y = y[res2] - y[res1];
	// resultant vector(v) equals to v = resultant_x*i + resultant_y*j; //i and j are the scalar multipliers not the declared i and j in the code
	printf("Resultant vector(v) is equal to ==> v = [%d]*i + [%d]*j",resultant_x,resultant_y);
}

