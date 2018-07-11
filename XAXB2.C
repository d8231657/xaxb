#include<stdlib.h>
#include<time.h>
static char org_table[10000];
int pass[4];
struct number
{
	int n4,n1[4];
}player,playergass,computer,computergass;
main()
{
	int turn4to1(int *);
	void turn1to4(int,int *);
	char test(int);
	void returngass(int,int,int *,int *);

	static char playerwin,computerwin,computertable[10000];
	int i,a,b,passa,passb,counter=0;

	randomize();
	clrscr();

	for(i=0;i<10000;i++)
	{
		turn1to4(i,pass);
		org_table[i]=computertable[i]=!(
					pass[0]==pass[1]||
					pass[0]==pass[2]||
					pass[0]==pass[3]||
					pass[1]==pass[2]||
					pass[1]==pass[3]||
					pass[2]==pass[3]);
	}
	do
	{
		printf("Please enter your number:");
		scanf("%4d",&(player.n4));
	}while(!test(player.n4));
	turn1to4(player.n4,player.n1);
	printf("\n");

	do
	{
		computer.n4=random(10000);
	}while(!test(computer.n4));
	turn1to4(computer.n4,computer.n1);

	do
	{
		counter++;
		do
		{
			printf("Enter your gass%2d:",counter);
			scanf("%4d",&(playergass.n4));
		}while(!test(playergass.n4));
		turn1to4(playergass.n4,playergass.n1);

		returngass(playergass.n4,computer.n4,&a,&b);
		printf("==>%1dA%1dB",a,b);
		playerwin=a==4;

		do
		{
			computergass.n4=random(10000);
		}while(!computertable[computergass.n4]);
		turn1to4(computergass.n4,computergass.n1);

		printf("\t\t\t\tComputer gass%2d:%1d%1d%1d%1d",counter
										  ,computergass.n1[3]
										  ,computergass.n1[2]
										  ,computergass.n1[1]
										  ,computergass.n1[0]);

		returngass(computergass.n4,player.n4,&a,&b);
		printf("==>%1dA%1dB\n",a,b);
		computerwin=a==4;

		for(i=0;i<10000;i++)	/*AI start*/
		{
			if(computertable[i])
			{
				returngass(computergass.n4,i,&passa,&passb);
				computertable[i]=(a==passa)&&(b==passb);
			}
		}
	}while(!(playerwin||computerwin));

	printf("\n");
	if(playerwin&&computerwin)
	{
		printf("NO WINNER");
	}
	else
	{
		if(playerwin)
		{
			printf("YOU WIN");
		}
		else
		{
			printf("COMPUTER WIN");
		}
	}
	printf("\nComputer's number:%1d%1d%1d%1d",computer.n1[3]
									 ,computer.n1[2]
									 ,computer.n1[1]
									 ,computer.n1[0]);
	getch();
}
int turn4to1(int point4[])
{
	return(point4[0]+point4[1]*10+point4[2]*100+point4[3]*1000);
}
void turn1to4(int inn,int point4[])
{
	point4[3]=inn/10/10/10%10;
	point4[2]=inn/10/10%10;
	point4[1]=inn/10%10;
	point4[0]=inn%10;
	return;
}
char test(int testnumber)
{
	return(org_table[testnumber]);
}
void returngass(int a,int b,int *A,int *B)
{
	int a4[4],b4[4],i,j;
	*A=*B=0;
	turn1to4(a,a4);
	turn1to4(b,b4);
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			if(a4[i]==b4[j])
			{
				if(i==j)
				{
					(*A)++;
				}
				else
				{
					(*B)++;
				}
			}
		}
	}
	return;
}