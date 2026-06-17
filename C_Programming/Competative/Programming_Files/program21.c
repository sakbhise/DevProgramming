//Input : 5
//Output :$ * $ * $ * $ * $ *

//Input : 3
//Output :$ * $ * $ * 

//Input : -5
//Output :$ * $ * $ * $ * $ *

#include<stdio.h>

void Pattern(int iNo)
{
    int iCnt = 0;
    if(iNo<0)
    {
        iNo = -iNo;
    }
    
   for(iCnt = 1 ; iCnt <= (iNo) ;iCnt++)
   {
        printf("$\n");
        printf("*\n");
    }

}

int main()
{
    int iValue = 0;
    printf("Enter Numbeer :");
    scanf("%d",&iValue);

    Pattern(iValue);

    return 0;
}

