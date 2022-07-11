/*
Name:  A version of the popular memory game "Find the pairs".
File Name: 1928748_2.c
Copyright: Free
Author: Zhongpei.Wang
Description: 
An entertainment company would like you to develop a version of the popular memory game
"Find the Pairs". In this game, a player is shown a grid of randomised pairs of symbols to
memorise in a short time. The player then selects pairs of objects to uncover, which remain
uncovered if they match. The aim is to turn over all pairs in the smallest number of attempts
possible. The program will allow the user to create an account so that their game history can
be recorded and viewed each time they login.
*/



#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <string.h>

typedef struct account/*Define the structure of account*/
{
struct z*zp; /*User name and password*/
struct player*playerp; /*Game history*/
} f;


struct e/*Define the user name and password*/ 
{
char a[10];
char b[10];
}z;
typedef struct Player /*define the record information for every player*/
{
	int number;
	int time;
}player;
int record=5;/*There maximum game record number is 5 */
player py[5];/*Each account could contain 5 players*/
player p={0,0};/*The reocrd list structure, which contain the player's number and the time*/



void mainmenu();/* The function that judges the choice you take*/
void Menu();/*main menu*/
void menu1();/*Login menu*/
void Sort();/*Player rankings*/
void Record();/*Show the reord*/
void Start(); /*Start the main manu and play the game*/ 
void PlayGame();/*Play the game*/
int ReadFile(); /*Read the file*/
void SaveFile();/*Save the file*/
void CreateFile();/*Create a file*/
void account(); /*Login system*/
void a12();/*Detlete records and account*/
void a13(); /*Deiete game record*/
void Play();/*Start the paly the game*/ 
void delay();/*Funtion used to stop the program*/

int main() /*define main function*/
{
	mainmenu();	/*Login menu*/ 
	return 0;
}


void delay(int t) /*Functions that used to delay the program*/
{
  int i,j;
	for(i=0;i<t;i++)
	   {
	   for(j=0;j<1141;j++);
       }
}

void menu1()  /*Login menu and give your choice*/
{
	printf("*Welcome to play the game         *\n");
	printf("*1.Users login                    *\n");
	printf("*2. Delete account                *\n");
	printf("*0. Exit                          *\n");
}

void Menu()/*Define the game menu and give your choice*/
{
    printf("*  Play find the pairs and enjoy the game *\n");
	printf("*  1.Start the game         *\n");
	printf("*  2.See the record         *\n");
	printf("*  3.Delete the record       *\n");
	printf("*  0.exit                   *\n");
}

void mainmenu()/* The function that judge the choice you take*/
{
	int choice;
	do {
	
		system("CLS");
		menu1();
		printf("Please input your choice");
		
		while (scanf("%d",&choice)!=1&&choice>2&&choice<0);
		{
			fflush(stdin);
		}/*Check whether you input the wrong thing*/
		switch(choice)
		{
			case 1: account();break; /* Login if you choose 1*/
			case 2: a12();break;   /*Delete all the records and your account*/
			case 0: exit(0);/*Log out the game*/
		}
} while(choice);
}


void a12()/*Detlete records and account*/ 
{
	remove("user.txt");
	remove("record.txt");
    printf("Your account has been removed\n");
    delay(500000);
}

void a13()/*Delete Game record*/
{
	remove("record.txt");
	printf("Your record has been removed, please login again.");
	
}


 
void Play() /*Program to play the game*/
{   FILE *p;
    int num = 0;/*Record the attempt times*/
    int a[16];/*Define the game map*/
	int c,d,e,f,g,i,j,m,n,h;
	int k;
	int b[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};	    /*Print out the map which could hide the game map*/ 
	srand((unsigned)time(NULL));/*The number will change according to the time*/
	
	a[0]=rand()%13+1;
	a[8]=a[0];
	for(g=1;g<=7;g++){
		a[g]=(a[g-1]+7)%13+1;
		a[g+8]=a[g];
	}/*the nineth number should be equal to the first number*/
	for(g=1;g<=30;++g){ 
		i=rand()%16;
		j=rand()%16;
		c=a[i];
		a[i]=a[j];
		a[j]=c;
	}/*Produce the game map*/
	printf("\n\n	%d	%d	%d	%d\n\n\n	%d	%d	%d	%d\n\n\n	%d	%d	%d	%d\n\n\n	%d	%d	%d	%d\n\n\n"
	,a[0],a[1],a[2],a[3],a[4],a[5],a[6],a[7],a[8],a[9],a[10],a[11],a[12],a[13],a[14],a[15]);/*Print out the map*/ 
	printf("\n\nPlease remember all the characters and start the game");
    delay(1000000);/*Show the map and give you several seconds to remember the  number*/
	system("cls");
	printf("\n						the corresponding order number shown below\n	0	0	0	0		1	2	3	4\n\n\n	0	0	0	0		5	6	7	8\n\n\n	0	0	0	0		9	10	11	12\n\n\n	0	0	0	0		13	14	15	16\n\n\n");	
	
	printf("    If you want to quit the game, you can input coordinates'0 0'\n");
	printf("	Please input the numbers you want(separate by blank) ");
	f=scanf("%d%d",&m,&n);
	if (m==0&&n==0) 
	{
	system("CLS");
	return;
	} /*If you want to exit the game, you can input 0 0*/
	num = num+1;
	
		for(;;){
			fflush(stdin);
		  for(;;){
		  	fflush(stdin);
			for(;;){
				fflush(stdin);
				if(f!=2){
					for(;;){	
						fflush(stdin);
						printf("\n wrong format, try again");/*If you input something that is not a number, try again.*/
						f=scanf("%d%d",&m,&n);
						if (m==0&&n==0)
		                   {
		                   system("CLS");
		                   return;
	                       }
						if(f==2){
							break;
				}   num = num+1;
					} 
				} 
				if(m==n&&m<=16&&m>=1&&n<=16&&n>=1){
					printf("\nYou can not input the same number, try again");
					f=scanf("%d%d",&m,&n);	/*If you input the same coordinates , try again.*/
					if (m==0&&n==0)
		                   {
		                   system("CLS");
		                   return;
	                       }	
					num = num+1;
				}
				if(m>16||m<0||n>16||n<0){
					printf("\nWrong input, try again");
					f=scanf("%d%d",&m,&n);	/*If you input coordinates which are smaller than 0 or larger than 16, try again*/
					if (m==0&&n==0)
		                   {
		                   system("CLS");
		                   return;
	                       }
					num = num+1;
				}
				if(b[m-1]!=0||b[n-1]!=0){
					printf("\n  Wrong chosen, try again");
					f=scanf("%d%d",&m,&n);/*If you input the coordinate which has been chosen before, try again*/
					if (m==0&&n==0)
		                   {
		                   system("CLS");		                   		                   
		                   return;
	                       }
					num = num+1;
				}
				if(m!=n&&m>=1&&m<=16&&n>=1&&n<=16&&b[m-1]==0&&b[n-1]==0){
					break;
				}				 
			}			
			if(a[m-1]!=a[n-1]){
			b[m-1]=a[m-1];
			b[n-1]=a[n-1];
			system("CLS");
			printf("\n							the corresponding order number shown below\n	%d	%d	%d	%d		1	2	3	4\n\n\n	%d	%d	%d	%d		5	6	7	8\n\n\n	%d	%d	%d	%d		9	10	11	12\n\n\n	%d	%d	%d	%d		13	14	15	16\n\n\n"
			,b[0],b[1],b[2],b[3],b[4],b[5],b[6],b[7],b[8],b[9],b[10],b[11],b[12],b[13],b[14],b[15]);
			printf("You input different values");
			delay(1000000);/*If the coordinates you input are not point to the same number, the system will show you the two number in several seconds*/
			system("cls");
			b[m-1]=0;
			b[n-1]=0;
			printf("\n							the corresponding order number shown below\n	%d	%d	%d	%d		1	2	3	4\n\n\n	%d	%d	%d	%d		5	6	7	8\n\n\n	%d	%d	%d	%d		9	10	11	12\n\n\n	%d	%d	%d	%d		13	14	15	16\n\n\n"
			,b[0],b[1],b[2],b[3],b[4],b[5],b[6],b[7],b[8],b[9],b[10],b[11],b[12],b[13],b[14],b[15]);
			printf("Try again");/* You will go back to the game map and try again*/
			f=scanf("%d%d",&m,&n);
			if (m==0&&n==0)
		                   {
		                   system("CLS");	      
		                   return;
	                       }
			num = num+1;
			}				
			if(a[m-1]==a[n-1]){	
				system("cls");
				b[m-1]=a[m-1];
				b[n-1]=a[n-1];
				printf("\n							the corresponding order number shown below\n	%d	%d	%d	%d		1	2	3	4\n\n\n	%d	%d	%d	%d		5	6	7	8\n\n\n	%d	%d	%d	%d		9	10	11	12\n\n\n	%d	%d	%d	%d		13	14	15	16\n\n\n"
				,b[0],b[1],b[2],b[3],b[4],b[5],b[6],b[7],b[8],b[9],b[10],b[11],b[12],b[13],b[14],b[15]);
				break; /*Check whether the two coordinates you choose point to the same number and show them to you*/
				
			}				
		}	
		if(b[0]!=0&&b[1]!=0&&b[2]!=0&&b[3]!=0&&b[4]!=0&&b[5]!=0&&b[6]!=0&&b[7]!=0&&b[8]!=0&&b[9]!=0&&b[10]!=0&&b[11]!=0&&b[12]!=0&&b[13]!=0&&b[14]!=0&&b[15]!=0&&b[m-1]==b[n-1]){
		printf("Attempt %d", num);break; /*Check whether you win the game*/
		}
		printf("Correct!, Please continue");
		/* If you the coordinates you choose point to the number, the map will show the number and you can continue the game*/
		f=scanf("%d%d",&m,&n);
		if (m==0&&n==0)
			{
		    system("CLS");
		    return;
	        }	
		num = num+1;
		}
	
		
    }   


void Sort()  /* record all the information of the players */
{
	int i,j;
	for(i=0;((i<record)&&(py[i].time>p.time));i++);
	if(i<record)
	{
	for(j=record-1;j>i;j--) 
	{
			py[j]=py[j-1];
	}
	py[i].time=p.time;
	py[i].number=p.number;
	return ;
	} /*List the times you play(player), and the time costing*/
	return ;
}

void Record()  /*Show all the palyers' record*/
{
	int i;
	int num;
	system("CLS");
	printf("*****************************************************\n");
			printf("*    player        time     *\n");
		for(i=0;i<record;i++)
		{
			if(py[i].time>0)
			{
			 printf("*%10d%10d         *\n",i+1,py[i].time);
		} /*Print all the player and time costing*/ 
			
		}

	printf("*****************************************************\n");
    printf("press 0 to leave:");
    while (scanf("%d",&i)!=1||i!=0)
    {
    	fflush(stdin);
    	printf("Please input 0 to leave");
    }

}
	
void RunningGame() /*The main program to control the game*/
{	
	time_t start,end;
	start=time(NULL);
    Play();/*Play the game*/
	end=time(NULL);
	p.time=(int)difftime(end,start); /*Calculate the time*/
	printf("   you win!    \n");
	printf("    costing time:%d\n",p.time);
	Sort();/*Record your information*/
	SaveFile();/*save your record*/ 
	printf("You will back to menu after several seconds\n");
	delay(1000000);
	Menu();/*After several seconds you will go back to the game menu*/

}


void account()/* Create your account and login*/ 
{ 
int t=0;
char s[10],d[10];
FILE *p;
void as();
if ((p=fopen("user.txt","r+"))==NULL) /*Check whether there is an account before*/
{
p=fopen("user.txt","w+");
t=1;
}
if(t==1)
{
printf("There is no account\nPlease create a new account\n");
printf("User name\n");
scanf("%s",s);
printf("Password\n ");
scanf("%s",d);
strcpy(z.a,s);
strcpy(z.b,d);
fprintf(p,"%s %s",z.a,z.b);
printf("You have created an account\n Please wait for a moment");/*If there is no account, create an account and login again*/ 
delay(500000);
fclose(p);
} 
if(t==0)/*If the document has an account before, check the account and login*/
{
printf("Input your username ");
scanf("%s",s);
fscanf(p,"%s %s",z.a,z.b);
fclose(p);
if (!strcmp(z.a,s))
{
printf("Input your password");
scanf("%s",d);getchar();/* Login your account*/
if(!strcmp(z.b,d))
{ char i;
printf("Do you want to change your password? Yes(y)or No(n)\n");/*Ask whether you want to change your password*/
while(scanf("%c",&i)!=1||(i!='y'&&i!='n'))/*If users input wrong value, they should input again*/
{
	fflush(stdin);
	printf("Wrong input, try again");
}
if(i=='y')
{
printf("Your new password");
scanf("%s",z.b);
p=fopen("user.txt","w+");
fprintf(p,"%s %s",z.a,z.b);
fclose(p);
printf("Successful");/*You have changed the password and you will go to the game menu after several second*/
delay(500000);
}
PlayGame();/*Game start*/
}

else printf("Wrong password, please check user.txt and login again");
delay(500000);
}
else printf("Wrong username, please check user.txt and login again");/*If users input the wrong username or password, the system will stop for several seconds*/
delay(500000);
fclose(p);                                                                   /*They should check the document to get the correct name and password*/
}
}

void Start() /* The start screen*/ 
{
	int choice;
	int i;
	if(ReadFile()==0) /*If there is no file to record players,create a file to store the record*/
	{
		CreateFile();
		i=ReadFile();
	}	
	do
	{
		system("CLS");
		Menu();/*Game menu*/
		printf("Please input your choice:\n");
		while (scanf("%d",&choice)!=1&&choice>3&&choice<0);/*Check whether you input the wrong thing*/
		{
			fflush(stdin);
		}
		switch(choice) 
		{
		case 1:RunningGame();break;/*The main program to control the game*/
		case 2:Record();break;/*See the record*/
		case 3: a13(); delay(500000);system("CLS");mainmenu();break;
		case 0:mainmenu();/*Back to the login menu*/
		} 
	}while(choice);
}
void CreateFile() /*Create a new file*/
{
	FILE *file;
	file=fopen("./record.txt","wb");
	if(!file)
	{
		printf("cannot create!\n");
		exit(1);
	}
	fclose(file);
}
int ReadFile() /*Read the file which you have created*/
{
	FILE *file;
	int i=0,j=0,last=0;
	player pl;
	file=fopen("./record.txt","rb");/*opeen the file*/
	if(!file)
	{
		return 0;
	}
	while(fread(&py[i],sizeof(py[i]),1,file)==1)
		i++;
	for(;i<record;i++)
	{
		py[i].time=0;
		py[i].number=0;
	} /*Define the origional value of the record*/ 

	for(i=0;i<record-1;i++)
	{
		for(j=0;j<record-i;j++)
		{
			if(py[j].time<py[j+1].time)
			{
				pl=py[j+1];
				py[j+1]=py[j];
				py[j]=pl;
				last=1;
			} /*Read all the infoemation*/ 
		}
		if(last==0)
			break;
		last=0;
	}

	fclose(file);
	return 1;
}


void SaveFile()/* Save the records*/
{
	FILE *file;
	int i=record-1;
	file=fopen("./record.txt","wb");
	if(!file)
	{
		printf("cannot open!\n");
		exit(1);
	}
	while(i>=0)
	{
		fwrite(&py[i],sizeof(py[i]),1,file);
		i--;
	}/*Write the record into the document*/
	fclose(file);
}


void PlayGame() /*Start to play the game*/
{
	Start(); /* The start screen*/
	
}

