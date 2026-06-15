
#include<stdio.h>
int main()
{
    float fValue1 = 0.0f;                    //To store first input
    float fValue2 = 0.0f;                    //To store secound input
    float fResult = 0.0f;                    // To store result


    printf("Enter first number: \n");
    scanf("%f",&fValue1);

    printf("Enter Secound number: \n");
    scanf("%f",&fValue2);

    fResult = fValue1 + fValue2;

    printf("Addition is : %f \n",fResult);    //Perform the Addition
    return 0;
}