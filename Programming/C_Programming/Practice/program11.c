/*
  START
    Accept number as No
    If No is Completely divisible by 2
      then print even 
    otherwise
      print odd
  STOP

  START
    Accept number aas np
    divide no by 2
    if reminder is 0
        then print as even

    otherwise
        print odd
  STOP
*/

#include<stdio.h>

int main()
{
    int iValue = 0;
    int iRemainder = 0;
    printf("Enter Number : \n");
    scanf("%d",&iValue);
    
    iRemainder = iValue % 2;

    if(iRemainder == 0)
    {
        printf("Number is even \n");

    }  
    else
    {
        printf("Number is odd \n");

    }
    return 0;
}