#include<stdio.h>
#include<stdlib.h>

#pragma pack(1)
struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void Display(PNODE first)
{
    while(first != NULL)
    {
        printf("| %d|->",first->data);
        first = first->next;
    }
    printf("NULL\n");
}

int Count(PNODE first)
{
    int iCount = 0;

    while(first != NULL)
    {
        iCount++;
        first = first->next;
    }
    return iCount;

}

void InsertFirst(PPNODE first , int iNo)
{
    PNODE newn = NULL;
    
    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = iNo;
    newn->next = NULL;

    if( *first == NULL)      //LL is empty
    {
        *first = newn;
    }
    else                       //LL Contains /at least 1 node
    {
        newn->next = *first;
        *first = newn;

    }

}

void InsertLast(PPNODE first ,int iNo)
{
    PNODE temp = NULL;
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = iNo;
    newn->next = NULL;

    if(*first == NULL)      //LL is empty
    {
        *first = newn;
    }
    else
    {
        temp = *first;

        while(temp->next != NULL)
        {
            temp = temp->next;

        }
        temp->next = newn;

    }


}

void InsertAtPos(PPNODE first , int iNo ,int iPos)
{
    int iCount = 0;
    int i = 0;

    PNODE newn = NULL;
    PNODE temp = NULL;

    iCount = Count(*first);

    if((iPos <1 )||(iPos > iCount+1))
    {
        printf("Invalid Position\n");
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(first ,iNo);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(first ,iNo);
    }
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));

        newn->data = iNo;
        newn->next = NULL;

        temp = *first;

        for(i = 1; i< iPos -1;i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
    }
}

void DeleteFirst(PPNODE first)
{
    PNODE temp = NULL;
    if(*first == NULL)
    {
        return;
    }
    else if((*first)-> next == NULL)
    {
        free(*first);
        *first =NULL;
    }
    else
    {
        temp = *first;
        *first = (*first)->next;
        free(temp);
    }

}

void DeleteLast(PPNODE first)
{
    PNODE temp = NULL;
    temp =*first;
    if(*first == NULL)
    {
        return;
    }
    else if((*first)-> next == NULL)
    {
        free(*first);
        *first =NULL;
    }
    else
    {
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }

}

void DeleteAtPos(PPNODE first ,int iPos)
{
    int iCount = 0;
    int i = 0;

    PNODE temp = NULL;
    temp = *first;

    iCount = Count(*first);

    if((iPos <1 )||(iPos > iCount))
    {
        printf("Invalid Position\n");
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst(first);
    }
    else if(iPos == iCount+1)
    {
        DeleteLast(first);
    }
    else
    {
        PNODE target = NULL;
        for(i = 1 ; i < iPos-1; i++)
        {
            temp = temp->next;
        }

        target = temp->next;
        temp->next = target->next;
        free(target);   
    }
}

int main()
{
    PNODE head = NULL;
    int iRet = 0;

    InsertFirst(&head , 51);
    InsertFirst(&head , 21);
    InsertFirst(&head , 11);

    Display(head);
    iRet = Count(head);
    printf("Number of Nodes Are : %d\n",iRet);

    InsertLast(&head , 101);
    InsertLast(&head , 111);
    InsertLast(&head , 121);

    Display(head);
    iRet = Count(head);
    printf("Number of Nodes Are : %d\n",iRet);

    DeleteFirst(&head);

    Display(head);
    iRet = Count(head);
    printf("Number of Nodes Are : %d\n",iRet);

    DeleteLast(&head);

    Display(head);
    iRet = Count(head);
    printf("Number of Nodes Are : %d\n",iRet);

    InsertAtPos(&head , 105,3);

    Display(head);
    iRet = Count(head);
    printf("Number of Nodes Are : %d\n",iRet);

    DeleteAtPos(&head ,3);

    Display(head);
    iRet = Count(head);
    printf("Number of Nodes Are : %d\n",iRet);

    return 0;
}