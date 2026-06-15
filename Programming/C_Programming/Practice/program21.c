#include<stdio.h>

int CalculateTicketPrize(int iAge)
{
    //Input Filter
    if(iAge < 0)
    {
        return -1;
    }

    if(iAge >=0 && iAge <= 5)
    {
        return 0;
    }
    else if(iAge >=6 && iAge <= 18)
    {
        return 500;

    }
    else if(iAge >=19 && iAge <=50)
    {
        return 900;
    }
    else
    {
        return 400;
    }

}

int main()
{
    int iValue = 0;
    int iRet = 0;

    printf("Please Enter Your Age to Calculate Ticket Prize : ");
    scanf("%d",&iValue);

    iRet = CalculateTicketPrize(iValue);

    printf("Your Ticket Prize will be %d rupees\n",iRet);
    return 0;
}