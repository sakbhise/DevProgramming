#include<stdio.h>

void Display(int iNo)
{
    // Filter

    if(iNo <0)
    {
        printf("Invalid Input\n");
    
    }


    int iCnt = 0;
    for(iCnt = 1; iCnt <= iNo; iCnt++)
    {
        printf("Jay Ganesh..\n");
    }
}
int main()
{
    int iValue = 0;

    printf("Enter The Frequency : ");
    scanf("%d",&iValue);
    
    Display(iValue);
    return 0;
} 