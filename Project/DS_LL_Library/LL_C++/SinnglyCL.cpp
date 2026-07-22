#include<iostream>
using namespace std;

#pragma pack(1)
struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node* PNODE;

class SinglyCL
{
    private :
        PNODE first;
        PNODE last;
        int iCount = 0;
    
    public:

        SinglyCL();
        void Display();
        int Count();

        void InsertFirst(int iNo);
        void InsertLast(int iNo);
        void InsertAtPos(int iNo,int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
        
};

SinglyCL :: SinglyCL()
{
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;

}

void SinglyCL :: Display()
{
    PNODE temp = NULL;
    
    if(first == NULL && last == NULL)
    {
        return;
    }
    
    temp = first;
    do
    {
        cout<<"|"<<temp->data<<"|->";
        temp = temp->next;

    }while(last->next != temp);
    cout<<"\n";
}

int SinglyCL ::  Count()
{
    return this->iCount;
}

void SinglyCL ::  InsertFirst(int iNo)
{
    PNODE newn = NULL;
    newn = new NODE;

    newn->data = iNo;
    newn->next = NULL;

    if(this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        newn->next = this->first;
        this->first = newn;
    }
    this->last->next = this->first;
    this->iCount++;
}

void SinglyCL ::  InsertLast(int iNo)
{
    PNODE newn = NULL;
    newn = new NODE;

    newn->data = iNo;
    newn->next = NULL;

    if(this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else 
    {
        this->last->next = newn;
        this->last = newn;
    }
   
    this->last->next = this->first;
    this->iCount++;
    
}

void SinglyCL ::  InsertAtPos(int iNo,int iPos)
{
    int i = 0;
    PNODE temp = NULL;
    PNODE newn = NULL;
    newn = new NODE;

    newn->data = iNo;
    newn->next = NULL;

    if((iPos < 1 ) ||(iPos > this->iCount + 1))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(iNo);
    }
    else if(iPos > this->iCount + 1)
    {
        InsertLast(iNo);
    }
    else
    {
        temp = this->first;
        for(i = 1 ; i < iPos-1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
        this->iCount++;

    }
    this->last->next = this->first;

}

void SinglyCL ::  DeleteFirst()
{
    PNODE temp = NULL;
    temp = this->first;
    
    if(this->first == NULL && this->last == NULL)
    {
        return;
    }
    else if(this->first == this->last)
    {
        delete temp;
        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        
        this->first = this->first->next;
        delete temp;

    }
    this->last->next = this->first;
    iCount--;
}

void SinglyCL ::  DeleteLast()
{
    PNODE temp = NULL;
    temp = this->first;
    
    if(this->first == NULL && this->last == NULL)
    {
        return;
    }
    else if(this->first == this->last)
    {
        delete temp;
        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        
        while( temp->next != this->last)
        {
            temp = temp->next;
        }
        delete(temp->next);
        this->last = temp;

    }
    this->last->next = this->first;
    iCount--;
}

void SinglyCL ::  DeleteAtPos(int iPos)
{
    int i = 0;
    PNODE temp = NULL;
    PNODE target = NULL;

    if((iPos < 1 ) ||(iPos > this->iCount))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos > this->iCount )
    {
        DeleteLast();
    }
    else
    {
        temp = this->first;
        for(i = 1 ; i < iPos-1; i++)
        {
            temp = temp->next;
        }

        target = temp->next;
        temp->next = target->next;
        delete target;
        this->iCount--;
    }

    
    this->last->next = this->first;
}

int main()
{
    int iRet = 0;
    SinglyCL sobj;

    sobj.InsertFirst(51);
    sobj.InsertFirst(21);
    sobj.InsertFirst(11);

    sobj.InsertLast(101);
    sobj.InsertLast(111);
    sobj.InsertLast(151);

    sobj.Display();
    iRet = sobj.Count();
    cout<<"Number of Nodes are :"<<iRet<<endl;
   
    sobj.DeleteFirst();
    sobj.Display();
    iRet = sobj.Count();
    cout<<"Number of Nodes are :"<<iRet<<endl;

    sobj.DeleteLast();
    sobj.Display();
    iRet = sobj.Count();
    cout<<"Number of Nodes are :"<<iRet<<endl;

    sobj.InsertAtPos(115,3);
    sobj.Display();
    iRet = sobj.Count();
    cout<<"Number of Nodes are :"<<iRet<<endl;

    sobj.DeleteAtPos(3);
    sobj.Display();
    iRet = sobj.Count();
    cout<<"Number of Nodes are :"<<iRet<<endl;

    return 0;

}