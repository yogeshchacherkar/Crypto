/*********************************
Title: RAILFENCE ALGORITHM
Programmer: <YoGeSh ChAcHeRkAr/>
*********************************/


#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
{
	//declaring variables
	int i,j,k,key,length,col_trace=0;
	char plain_text[50],cipher_text[50],arr[30][30];
	clrscr();

	//initialize 2D array
	for(i=0;i<30;i++)
		for(j=0;j<30;j++)
			arr[i][j]='0';

	//geting inputs
	printf("\n Enter plain text: ");
	gets(plain_text);
	printf(" Enter key value: ");
	scanf("%d",&key);

	printf("\n");

	length = strlen(plain_text);

	//putting inputs in 2D array
	i=0;
	for(j=0;j<length;j++)
	{
		if(i<0)
		{
			i+=2;
			col_trace=0;
		}
		if(i==key)
		{
			i-=2;
			col_trace=1;
		}

		arr[i][j] = plain_text[j];

		if(col_trace==0)
			i++;
		else
			i--;
	}

	//creating cipher text
	k=0;
	for(i=0;i<key;i++)
	{
		for(j=0;j<length;j++)
		{
			if(arr[i][j]!='0')
			{
				cipher_text[k] = arr[i][j];
				k++;
			}
			else continue;
		}
	}

	//display 2D array
	for(i=0;i<key;i++)
	{
		for(j=0;j<30;j++)
		{
			if(arr[i][j]=='0')
				arr[i][j]=' ';
			printf("%c ",arr[i][j]);
		}
		printf("\n");
	}

	printf("\nCipher Text => %s\n",cipher_text);

	getch();
}