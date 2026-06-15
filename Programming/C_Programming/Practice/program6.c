/*
  Algorithm

   START
    Accept first as No1
    Accept Secound as No2
    Perform Addition of No1 And No2
    Display result
   STOP

*/
#include<stdio.h>
int main()
{
    //Variable Creation with Default values
    float i=0.0f,j=0.0f,k=0.0f;

    printf("Enter first number: \n");
    scanf("%f",&i);

    printf("Enter Secound number: \n");
    scanf("%f",&j);

    k = i + j;

    printf("Addition is : %f \n",k);
    return 0;
}