#include<stdio.h>

void Accept(int iNo)
{
    int iCnt =0;
    for(iCnt = 1; iCnt<=iNo; iCnt++)
    {
        printf("*");
    }
}

int main()
{
    int iValue = 0;
    iValue = 10;

    Accept(iValue);
    return 0;
}