/*
Name: Assignment 1 
File Name:1928748_Zhongpei.Wang_Assignment1.c
Copyright: Free
Author: Zhongpei.Wang
Description:
1.Read a full name with spaces from the keyboard.
Use a loop to add together the character values of the name entered and print the total on
the screen. 
2.Read a telephone number assume all phone numbers have 11 digits from the keyboard.
Divide the first 6 figures of the telephone number by the last 5 and store the result in a
variable. Print the value on the screen.
3.Read a three-digit positive integer number from the keyboard.
Convert the integer number to its binary equivalent and print it on the screen.
4.Provide the user with a choice of performing a two-dimensional rectangular to polar or
polar to rectangular coordinate conversion for a vector and read the
necessary values from the keyboard. Display the converted values on the screen
*/







#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define o 100
void ex1(void);
void ex2(void);
void ex3(void);
void ex4(void);

int main(void) /*define the main function*/ 
{
 ex1();
 ex2();
 ex3();
 ex4();
}
 void ex1(void){ /*task 1 program*/
 char name[o],*u; /*variables for task 1*/ 
 int j, length;
 int z, l=0,v;
 do {
 printf("Please input your name with spaces\n");    /*ask to input a name*/
  gets(name);                           /* store the name you input*/
  u = name;                               /*Initilaize pointer to string*/
  length = strlen(name);                /*record the length of the name*/

 for (j = 0; j<length; j++)
 {
 if(islower(name[j])||name[j]==32||isupper(name[j]))
 v = 1;
 else {
 v = 0;
 printf("You input the wrong name\nPlease try again\n");
 fflush(stdin);
 break;
 }}

  }while (!v);                                      /*Check whether you input the right thing*/           
printf(" \n");
puts(name);                           
 for(j=0; j<length;j++)
 {z = toascii(*(u++));               /*Obtain the ASCII value for each character*/
      if(z == 32)                    /*neglet the space*/
      continue;
      else;
      l = l+z;
	  fflush(stdin);                       /*add all values together*/  
 }
 printf("The sum is %d", l);         /*Output the value*/
 printf("\n");}
 
 
 void ex2(void){ 
 double a,c,n,p;/*variables for task 2*/
 double s = pow(10,11)-1;
 double q = pow(10,10);   
 int m;
 
 printf("Please input a 11-digit telephone number");     /*task 2 program*/
  while (scanf("%lf",&a)!=1||a>s ||a<q)      /*input the 11-digit telephone number*/
 {
  fflush(stdin);
  printf("\nThe value you entered is wrong please try again\n");
  printf("Please input a 11-digit telephone number");
 }      
  m = a/100000;                 /*first 6 digits*/
  n = m;        /*change the range of a, because "int" could not calculate a number with more than 10 digits*/
  c = a - n*100000;   /*another 5 digits*/
  while (c==0)
 {
   printf("\nThe value you entered is wrong because a number can not be divided by 0\nplease try again\n");
   printf("Please input a 11-digit telephone number");
    while (scanf("%lf",&a)!=1||a>s ||a<q)      
 {
  fflush(stdin);
  printf("\nThe value you entered is wrong please try again\n");
  printf("Please input a 11-digit telephone number");
 }      
  m = a/100000;                
  n = m;        
  c = a - n*100000;} /*if the last 5 digits are all 0, input again*/
 p = m/c;    /*calculate the required value*/
 printf("The value is %lf\n",p); /*Output the value*/
 printf("\n");
 }
 
 
 void ex3(void){               /*task 3 program*/
 int s;                              
 int l[20];
 int i=0;
 printf("Please input a three-digit positive number");   /*Input the three-digit value*/
 while (scanf("%d",&s)!=1||s>=1000||s<=99)                /*Check whether users input the correct thing*/
 {
  fflush(stdin);
  printf("\nThe value you entered is wrong please try again\n");
  printf("Please input a three-digit positive number");
 } 
 
 while(s)         /* Divided by 2 over and over again to obtain the binary value and store all the values in an array*/
 {
  fflush(stdin);
  l[i]=s%2;
  s=s/2;
  i++;
 }
 
 for(i--;i>=0;i--) /*reverse the order of the array to get the correct answer*/
 printf("%d",l[i]);
 }            
 
 
 
 
void ex4(void){
double Ax,Ay;           /*variables for task4*/
 double C,D;
 double d,e,Ax1,Ay1;
 char ch;

  printf("\nWhat kind of transformation do you want\n");      
  printf("Choose [r], transfer rectangular to polar\n"); 
  printf("Choose [p], transfer polar to rectangular\n");
  printf("Now give your choice- ");
     while((scanf("%c", &ch))!=1||(ch!='p' &&ch!= 'r'))
	{
	 fflush(stdin);
	 printf("The number you entered is wrong\nPlease try again\n");
	 printf("What kind of transformation do you want\n");      
     printf("Choose [r], transfer rectangular to polar\n"); 
     printf("Choose [p], transfer polar to rectangular\n");
     printf("Now give your choice- ");	    	  
    }    /*ask what kind of choice you want again if you input the wrong character*/
 switch (ch){                           
 case 'r':printf("The vector is A = Axi + Ayj\nThe values of the Ax and Ay are\n(values separated by spaces)-");  /*If you choose"t"*/
 while(scanf("%lf %lf", &Ax, &Ay)!=2)               /*Input numbers*/
	{
	fflush(stdin);
	printf("\nThe values you entered are wrong please try again\n");
	printf("\nThe vector is A = Axi + Ayj\nThe values of the Ax and Ay are\n(values separated by spaces)-");
	}
  /*If you input the wrong value, the program will let you input the  value again until you input the right value*/
 C = atan(Ay/Ax); 
 D = sqrt(pow(Ax,2)+pow(Ay,2)); /* Do calculation*/  
 printf("The transformation value |A| is %lf and rad value of angle theta is %lf\n",D, C);     /* Output values*/
 break;
 case 'p':printf("The value of |A| and rad value of angle theta are\n(values separated by spaces)-");    /*If you choose"p"*/
 while(scanf("%lf %lf", &d, &e)!=2)
	{
	fflush(stdin);
	printf("\nThe values you entered are wrong please try again\n");
	printf("\nThe value of |A| and rad value of angle theta are\n(values separated by spaces)-");
	}
/*If you input the wrong value, the program will let you input the  value again until you input the right value*/
 Ax1 = d*cos(e); 
 Ay1 = d*sin(e);        /*Do calculation*/
 printf("The transfrom values Ax1 and Ay1 are %lf %lf", Ax1, Ay1);      /*Output values*/
 break;
 }
 printf("\n");} 

