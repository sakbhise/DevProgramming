class node
{
    public int data;
    public node next;
    public node prev;

    node(int iNo)
    {
        this.data = iNo;
        this.next = null;
        this.prev = null;
    }
}

class DoublyCL
{
    private node first;
    private node last;
    private int iCount;

    public DoublyCL()
    {
        this.first = null;
        this.last = null;
        this.iCount = 0;
    }

    public void Display()
    {
        node temp = first;
        do
        {
            System.out.print("|"+temp.data+"| ->");
            temp = temp.next;
        }while(last.next != temp);

        System.out.println();
    }

    public int Count()
    {
        return iCount;
    }

    public void InsertFirst(int iNo)
    {
        node newn = new node(iNo);

        if(first == null && last == null)
        {
            first = newn;
            last = newn;
        }
        else
        {
            newn.next = first;
            first = newn;
        }
        last.next = first;
        first.prev = last;
        iCount++;
    }

    public void InsertLast(int iNo)
    {
        node newn = new node(iNo);

        if(first == null && last == null)
        {
            first = newn;
            last = newn;
        }
        else
        {
            last.next = newn;
            last = newn;
        }

        last.next = first;
        first.prev = last;       
        iCount++;        
    }

    public void InsetrAtPos(int iNo, int iPos)
    {
        node temp = null;
        node newn = null;
        int i = 0;
        
        if((iPos < 1) || (iPos > iCount+1))
        {
            return;
        }

        if(iPos == 1)
        {
            InsertFirst(iNo);
        }
        else if(iPos == iCount+1)
        {
            InsertLast(iNo);
        }
        else
        {
            newn = new node(iNo);

            temp = first;

            for(i = 1; i < iPos-1; i++)
            {
                temp = temp.next;
            }

            newn.next = temp.next;
            temp.next.prev = newn;
            temp.next = newn;
            newn.prev = temp;
            last.next = first;
            first.prev = last;

            iCount++;
        }
    }

    public void DeleteFirst()
    {
        if(first == null)
        {
            return;
        }
        else if(first == last)
        {
            first = null;
            last = null;
        }
        else
        {
            first = first.next;
        }
        last.next = first;
        first.prev = last;
        iCount--;
    }
    
    public void DeleteLast()
    {
        if(first == null)
        {
            return;
        }
        else if(first == last)
        {
            first = null;
            last = null;
        }
        else
        {
            node temp = first;

            while(temp.next.next != last.next)
            {
                temp = temp.next;
            }

            temp.next = null;
            last = temp;
        }
        last.next = first;
        first.prev = last;
        iCount--;        
    }

    public void DeleteAtPos(int iPos)
    {
        node temp = null;
        int i = 0;
        
        if((iPos < 1) || (iPos > iCount))
        {
            return;
        }

        if(iPos == 1)
        {
            DeleteFirst();
        }
        else if(iPos == iCount)
        {
            DeleteLast();
        }
        else
        {
            temp = first;

            for(i = 1; i < iPos-1; i++)
            {
                temp = temp.next;
            }

            temp.next = temp.next.next;
            temp.next.prev = temp;

            iCount--;
            last.next = first;
            first.prev = last;
        }        
    }
}

class program461
{
    public static void main(String A[])
    {
        int iRet = 0;

        DoublyCL dobj = new DoublyCL();
        
        dobj.InsertFirst(51);
        dobj.InsertFirst(21);
        dobj.InsertFirst(11);

        dobj.InsertLast(101);
        dobj.InsertLast(111);
        dobj.InsertLast(121);
        
        dobj.Display();

        iRet = dobj.Count();

        System.out.println("Number of nodes are : "+iRet);

        dobj.DeleteFirst();
        dobj.DeleteLast();

        dobj.Display();

        iRet = dobj.Count();

        System.out.println("Number of nodes are : "+iRet);

        dobj.InsetrAtPos(105,4);

        dobj.Display();

        iRet = dobj.Count();

        System.out.println("Number of nodes are : "+iRet);

        dobj.DeleteAtPos(4);

        dobj.Display();

        iRet = dobj.Count();

        System.out.println("Number of nodes are : "+iRet);
    }
}

/*
-------------------------------------------------------------------------------------
                SingLL      SinglyCL        DoublyLL    DoublyCL    Stack   Queue
-------------------------------------------------------------------------------------
C               DONE           DONE         DONE          DONE      --      --
C++             DONE           DONE         DONE          DONE      --      --
Java            DONE            --          DONE          --       --      --
C++ generic     --              --           --            --       --      --
-------------------------------------------------------------------------------------
*/