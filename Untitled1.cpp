#include<stdio.h>
#include<stdlib.h>

long long nck[100][100];
void calculate(long long num);
long long bino(long long n,long long k);

int main()
{
	long long num,i,j;
	printf("Enter the no. to be checked for primality:");
	scanf("%lli",&num);
	if(num<=1){printf("Invalid input");exit(0);
	}
	for(i=0;i<=num;i++)
	{
		for(j=0;j<=i;j++)
			nck[i][j]=0;
	}
	calculate(num);	
	return 0;
}

void calculate(long long num)
{
	long long check,i,j;
	check=(num/2);
	if(check>0){
	printf("\nCoefficients to be checked for divisibility are:\n");}
	for(i=2;i<=check;i++)
	{
		nck[num][i]=bino(num,i);
		if((nck[num][i])%num!=0)
		{
			printf("%lli is not divisible by %lli\n",nck[num][i],num);
			printf("\nThe number %lli is composite.",num);
			exit(0);
		}
		else
			printf("%lli is divisible by %lli\n",nck[num][i],num);
	}
	printf("\nThe number %lli is prime.",num);
}

long long bino(long long n,long long k)
{
	if(nck[n][k]!=0)
		return nck[n][k];
	else if(n==k || k==0)
		return 1;
	else
	{
		nck[n][k]=bino(n-1,k)+bino(n-1,k-1);
		return nck[n][k];
	}
}
