//This program aims to seperate passed and failed students according to their 4 homework grade means and printing the list on 2 files named fail.txt and pass.txt
//pass-fail conditions:
//mean>=30 ===> pass
//mean<30  ===> fail

#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <stdlib.h>

int j;

float FindMean(float x[]);		// the function for finding means of the homework grades

int main()
{
	float st1[4];
	float st2[4];
	float st3[4];
	float st4[4];
	float st5[4];
	
	int i = 0;
	for(i;i<=3;i++)						//getting students grades
	{
		printf("enter the Hw[%d] grade Student1 : \n",i+1);
		scanf("%f",&st1[i]);
	}
	i = 0;
	for(i;i<=3;i++)
	{
		printf("enter the Hw[%d] grade of Student2 : \n",i+1);
		scanf("%f",&st2[i]);
	}
	i = 0;
	for(i;i<=3;i++)
	{
		printf("enter the Hw[%d] grade of Student3 : \n",i+1);
		scanf("%f",&st3[i]);
	}
	i = 0;
	for(i;i<=3;i++)
	{
		printf("enter the Hw[%d] grade of Student4 : \n",i+1);
		scanf("%f",&st4[i]);
	}
	i = 0;
	for(i;i<=3;i++)
	{
		printf("enter the Hw[%d] grade of Student5 : \n",i+1);
		scanf("%f",&st5[i]);
	}
	
	FILE *pass;
	pass = fopen("pass.txt","w");
	if (pass == NULL)				//to know the situation of an error while opening the file
	{
    	printf("Error opening file!\n");
   		exit(1);
	}
	fprintf(pass,"ID\thw1\thw2\thw3\thw4\n");
	if(FindMean(st1)>=30)
	{
		fprintf(pass,"1\t");
		for(i=0;i<=3;i++)
		{
			fprintf(pass,"%.2f\t",st1[i]);
		}
		fprintf(pass,"\n");
	}
	if(FindMean(st2)>=30)
	{
		fprintf(pass,"2\t");
		for(i=0;i<=3;i++)
		{
			fprintf(pass,"%.2f\t",st2[i]);
		}
		
		fprintf(pass,"\n");
	}
	if(FindMean(st3)>=30)
	{
		fprintf(pass,"3\t");
		for(i=0;i<=3;i++)
		{
			fprintf(pass,"%.2f\t",st3[i]);
		}
		fprintf(pass,"\n");
	}
	if(FindMean(st4)>=30)
	{
		fprintf(pass,"4\t");
		for(i=0;i<=3;i++)
		{
			fprintf(pass,"%.2f\t",st4[i]);
		}
		fprintf(pass,"\n");
	}
	if(FindMean(st5)>=30)
	{
		fprintf(pass,"5\t");
		for(i=0;i<=3;i++)
		{
			fprintf(pass,"%.2f\t",st5[i]);
		}
		fprintf(pass,"\n");
	}
	fclose(pass);
	FILE *fail;
	fail = fopen("fail.txt","w");
	fprintf(fail,"ID\thw1\thw2\thw3\thw4\n");
	if(FindMean(st1)<30)
	{
		fprintf(fail,"1\t");
		for(i=0;i<=3;i++)
		{
			fprintf(fail,"%.2f\t",st1[i]);
		}
		fprintf(fail,"\n");
	}
	if(FindMean(st2)<30)
	{
		fprintf(fail,"2\t");
		for(i=0;i<=3;i++)
		{
			fprintf(fail,"%.2f\t",st2[i]);
		}
		fprintf(fail,"\n");
	}
	if(FindMean(st3)<30)
	{
		fprintf(fail,"3\t");
		for(i=0;i<=3;i++)
		{
			fprintf(fail,"%.2f\t",st3[i]);
		}
		fprintf(fail,"\n");
	}
	if(FindMean(st4)<30)
	{
		fprintf(fail,"4\t");
		for(i=0;i<=3;i++)
		{
			fprintf(fail,"%.2f\t",st4[i]);
		}
		fprintf(fail,"\n");
	}
	if(FindMean(st5)<30)
	{
		fprintf(fail,"5\t");
		for(i=0;i<=3;i++)
		{
			fprintf(fail,"%.2f\t",st5[i]);
		}
		fprintf(fail,"\n");
	}
	fclose(fail);
	
	return 0;
	
}

float FindMean(float x[])
{
	int sum = 0;
	for(j=0;j<=3;j++)
	{
		sum = sum + x[j];
	}
	int mean;
	mean = sum/4;
	
	return mean;
}












