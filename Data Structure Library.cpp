#include<iostream>
using namespace std;

/////////////////////////////////////////////////////////////
//
// Code of Singly Linear
//
/////////////////////////////////////////////////////////////

template <class T>
struct nodeSL
{
    T data;
    struct nodeSL *next;
};

template <class T>
class SinglyLL
{
    private:
        struct nodeSL<T> * First;
        int iCount;

    public:
        SinglyLL();

        void Display();
        int Count();

        void InsertFirst(T No);
        void InsertLast(T No);
        void InsertAtPos(T No, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

template <class T>
SinglyLL<T>::SinglyLL()
{
    cout<<"Inside Constructor\n";
    First = NULL;
    iCount = 0;
}

template <class T>
void SinglyLL<T>::Display()
{
    struct nodeSL<T> * temp = First;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<"|-> ";
        temp = temp -> next;
    }
    cout<<"NULL\n";
}

template <class T>
int SinglyLL<T>::Count()
{
    return iCount;
}

template <class T>
void SinglyLL<T>::InsertFirst(T No)
{
    struct nodeSL<T> * newn = NULL;

    newn = new nodeSL<T>;    // malloc

    newn->data = No;
    newn->next = NULL;

    if(First == NULL) // if(iCount == 0)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    iCount++;
}

template <class T>
void SinglyLL<T>::InsertLast(T No)
{
    struct nodeSL<T> * newn = NULL;
    struct nodeSL<T> * temp = First;

    newn = new nodeSL<T>;    // malloc

    newn->data = No;
    newn->next = NULL;

    if(First == NULL) // if(iCount == 0)
    {
        First = newn;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = newn;
    }
    iCount++;
}

template <class T>
void SinglyLL<T>::InsertAtPos(T No, int iPos)
{
    struct nodeSL<T> * newn = NULL;
    int i = 0;
    struct nodeSL<T> * temp;

    if((iPos < 1) || (iPos > iCount+1))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(No);
    }
    else 
    {
        temp = First;
        
        newn = new nodeSL<T>;
        newn->data = No;
        newn->next = NULL;

        for(i = 1; i < iPos-1; i++)
        {
            temp = temp -> next;
        }

        newn->next = temp->next;
        temp -> next = newn;
        iCount++;
    }
}

template <class T>
void SinglyLL<T>::DeleteFirst()
{
    struct nodeSL<T> * temp = First;

    if(First == NULL)
    {
        cout<<"LL is empty\n";
        return;
    }
    else if(First -> next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        First = First -> next;
        delete temp;
    }
    iCount--;
}

template <class T>
void SinglyLL<T>::DeleteLast()
{
    struct nodeSL<T> * temp = First;

    if(First == NULL)
    {
        cout<<"LL is empty\n";
        return;
    }
    else if(First -> next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        while(temp->next->next != NULL)
        {
            temp = temp ->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}

template <class T>
void SinglyLL<T>::DeleteAtPos(int iPos)
{
    int i = 0;
    struct nodeSL<T> * temp1;
    struct nodeSL<T> * temp2;

    if((iPos < 1) || (iPos > iCount))
    {
        cout<<"Invalid position\n";
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
        temp1 = First;

        for(i = 1; i < iPos-1; i++)
        {
            temp1 = temp1 -> next;
        }

        temp2 = temp1->next;

        temp1->next = temp2->next;
        delete temp2;

        iCount--;
    }    
}

/////////////////////////////////////////////////////////////
//
// Code of Doubly Circular
//
/////////////////////////////////////////////////////////////
template <class T>
struct nodeDC
{
    T data;
    struct nodeDC *next;
    struct nodeDC *prev;
};

template <class T>
class DoublyCL
{
    private:
        struct nodeDC<T> * First;
        struct nodeDC<T> * Last;
        int iCount;

    public:
        DoublyCL();

        void Display();
        int Count();

        void InsertFirst(T No);
        void InsertLast(T No);
        void InsertAtPos(T No, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

template <class T>
DoublyCL<T>:: DoublyCL()
{
    First = NULL;
    Last = NULL;
    iCount = 0;
}

template <class T>
void DoublyCL<T>::Display()
{
    if(First == NULL && Last == NULL)
    {
        cout<<"Linked List is emprty\n";
        return;
    }

    cout<<"<=> ";
    do
    {
        cout<<"| "<<First->data <<"| <=> ";
        First = First -> next;
    }while(Last -> next != First);

    cout<<"\n";
}

template <class T>
int DoublyCL<T>::Count()
{
    return iCount;
}

template <class T>
void DoublyCL<T>::InsertFirst(T No)
{
    struct nodeDC<T> * newn = NULL;

    newn = new nodeDC<T>;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        newn->next = First;
        First->prev = newn;
        First = newn;
    }
    Last -> next = First;
    First -> prev = Last;

    iCount++;
}

template <class T>
void DoublyCL<T>::InsertLast(T No)
{
    struct nodeDC<T> * newn = NULL;

    newn = new nodeDC<T>;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        Last ->next = newn;
        newn->prev = Last;
        Last = newn;
    }
    Last -> next = First;
    First -> prev = Last;

    iCount++;    
}

template <class T>
void DoublyCL<T>::InsertAtPos(T No, int iPos)
{
    struct nodeDC<T> * temp = NULL;
    struct nodeDC<T> * newn = NULL;

    int i = 0;

    if(iPos < 1 || iPos > iCount+1)
    {
        cout<<"Invalid postion\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(No);
    }
    else
    {
        newn = new nodeDC<T>;

        newn->data = No;
        newn->next = NULL;
        newn->prev = NULL;

        temp = First;

        for(i = 1; i < iPos -1; i++)
        {
            temp = temp -> next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;

        iCount++;
    }
}

template <class T>
void DoublyCL<T>::DeleteFirst()
{
    if(First == NULL && Last == NULL)   // Empty LL
    {
        return;
    }
    else if(First == Last)   // Single node
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else    // More than one node
    {
        First = First -> next;
        delete Last->next;
        First -> prev = Last;
        Last -> next = First;
    }
    iCount--;
}

template <class T>
void DoublyCL<T>::DeleteLast()
{
    if(First == NULL && Last == NULL)   // Empty LL
    {
        return;
    }
    else if(First == Last)   // Single node
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else    // More than one node
    {
        Last = Last -> prev;
        delete First -> prev;

        Last -> next = First;
        First -> prev = Last;
    }
    iCount--;    
}

template <class T>
void DoublyCL<T>::DeleteAtPos(int iPos)
{
    struct nodeDC<T> * temp = NULL;

    int i = 0;

    if(iPos < 1 || iPos > iCount)
    {
        cout<<"Invalid postion\n";
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
        temp = First;

        for(i = 1; i < iPos -1; i++)
        {
            temp = temp -> next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        iCount--;
    }    
}

/////////////////////////////////////////////////////////////
//
// Code of Doubly Linear
//
/////////////////////////////////////////////////////////////

template <class T>

struct nodeDL
{
    T data;
    struct nodeDL *next;
    struct nodeDL *prev;      //$
};

template <class T>
class DoublyLL
{
    private:
        struct nodeDL <T> *First;
        int iCount;

    public:
        DoublyLL();

        void Display();
        int Count();

        void InsertFirst(T No);
        void InsertLast(T No);
        void InsertAtPos(T No , int Pos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
        
};

template <class T>
DoublyLL<T> :: DoublyLL()
{
    cout<<"inside Constructor\n";
    First = NULL;
    iCount = 0;
}

template <class T>
void DoublyLL<T> :: Display()
{
    struct nodeDL <T> *temp = First;

    cout<<"\n NULL <=>";

    while (temp != NULL)
    {
        cout<<"| "<<temp -> data<<"| =>";

        temp = temp -> next;
    }
    cout<<"NULL\n";


}


template <class T>
int DoublyLL <T>:: Count()
{
    return iCount;

}


template <class T>
void DoublyLL<T> :: InsertFirst(T No)
{
    struct nodeDL <T> *newn = NULL;

    newn = new nodeDL<T>;

    newn -> data = No;
    newn -> next = NULL;
    newn -> prev = NULL;        //$

    if (First == NULL)
    {
        First = newn;
    }
    else
    {
        newn -> next = First;

        First -> prev = newn;       //$

        First = newn;
    }
    iCount++; 


}


template <class T>
void DoublyLL<T> :: InsertLast(T No)
{
    struct nodeDL <T> *newn = NULL;
    struct nodeDL <T> *temp = First;

    newn = new nodeDL<T>;

    newn -> data = No;
    newn -> next = NULL;
    newn -> prev = NULL;        //$

    if(First == NULL)
    {
        First = newn;
    }

    else 
    {
        while (temp -> next != NULL)
        {
            temp = temp -> next;
        }

        temp -> next = newn;

        newn -> prev = temp;        //$

    }
    iCount ++;

}


template <class T>
void DoublyLL<T> :: InsertAtPos(T No , int iPos)
{
    struct nodeDL <T> *newn = NULL;

    int i = 0;

    struct nodeDL <T> *temp;

    if ((iPos < 1) || (iPos > iCount + 1))
    {
        cout<<"Invaild Position\n";

        return;
    }

    if (iPos == 1)
    {
        InsertFirst(No);
    }

    else if (iPos == iCount + 1)
    {
        InsertLast(No);
    }

    else
    {
        temp = First;

        newn = new nodeDL<T>;

        newn -> data = No;
        newn -> next = NULL;
        newn -> prev = NULL;         //$

        for(i = 1; i < iPos - 1; i++)
        {
            temp = temp -> next;
        }

        newn -> next = temp -> next;

        temp -> next = newn -> prev;

        temp -> next = newn;

        newn -> prev = temp;

        iCount++;
    }

}


template <class T>
void DoublyLL<T> :: DeleteFirst()
{

    if(First == NULL)
    {
        cout<<"LL is empty\n";

        return;
    }

    else if(First -> next = NULL)
    {
        delete First;
        First = NULL;
    }

    else
    {
        First = First -> next;

        delete First -> prev;       //$

        First -> prev = NULL;       //$
    }
    iCount--;

}


template <class T>
void DoublyLL<T> :: DeleteLast()
{
    struct nodeDL <T> *temp = First;

    if(First == NULL)
    {
        cout<<"LL is empty\n";

        return;
    }

    else if (First -> next == NULL)
    {
        delete First;

        First = NULL;
    }

    else
    {
        while(temp -> next -> next != NULL)
        {
            temp = temp -> next;
        }
        delete temp -> next;

        temp -> next = NULL;
    }
    iCount--;


}


template <class T>
void DoublyLL<T> :: DeleteAtPos(int iPos)
{
    int i = 0;
    struct nodeDL <T> *temp = NULL;

    if ((iPos < 1) || (iPos > iCount))
    {
        cout<<"invalid position\n";

        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }

    else if (iPos == iCount)
    {
        DeleteLast();
    }

    else
    {
        temp = First;

        for (i = 1; i < iPos - 1; i++)
        {
            temp = temp -> next;
        }

        temp -> next = temp -> next -> next;

        delete temp -> next -> prev;

        temp -> next -> prev = temp -> next;


        iCount--;
    }



}





/////////////////////////////////////////////////////////////
//
// Code of Singly Circular
//
/////////////////////////////////////////////////////////////

template <class T>
struct nodeSC
{
    T data;

    struct nodeSC *next;
};


template <class T>
class SinglyCl
{
    private:
        struct nodeSC<T> *First;
        struct nodeSC<T> *Last;
        int iCount;

    public:
        SinglyCl();

        void Display();
        int Count();

        void InsertFirst(T No);
        void InsertLast(T No);
        void InsertAtPos(T No , int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};


template <class T>
SinglyCl<T> :: SinglyCl()
{
    First = NULL;
    Last = NULL;
    iCount = 0;
}


template <class T>
void SinglyCl<T>  :: Display()
{
    if((First == NULL) && (Last == NULL))
    {
        cout<<"Link List is empty\n";
        return;
    }

    do
    {
        cout<<"|"<<First -> data<<"|->";
        First = First -> next;
    }while(First != Last -> next);

    cout<<"\n";

}


template <class T>
int SinglyCl<T> :: Count()
{
    
    return iCount; 
}


template <class T>
void SinglyCl<T>  :: InsertFirst(T No)
{
    struct nodeSC<T> *newn = NULL;

    newn  = new nodeSC<T>;

    newn -> data = 0;
    newn -> next = NULL;

    if(First == NULL)
    {
        First = newn;
    } 

    else
    {
        newn -> next = First;

        First = newn;
    }
    Last -> next = First;
    iCount ++;
}


template <class T>
void SinglyCl<T>  :: InsertLast(T No)
{
    struct nodeSC<T> *newn = NULL;

    newn = new nodeSC<T>;

    newn -> data = 0;
    newn -> next = NULL;

    if((First == NULL) && ( Last == NULL))
    {
        First = newn;
        Last = newn;

    }

    else
    {
        Last -> next = newn;

        Last = newn;
    }
    Last -> next = First;


    
}


template <class T>
void SinglyCl<T>  :: InsertAtPos(T No , int iPos)
{
    struct nodeSC<T> *newn = NULL;

    int i = 0;

    struct nodeSC<T> *temp = NULL;

    if((iPos < 1) || (iPos > iCount + 1))
    {
        cout<<"invalid position";
        return;

    }

    if (iPos == 1)
    {
        InsertFirst(No);
    }

    else if (iPos == iCount + 1)
    {
        InsertLast(No);
    }

    else
    {
        temp = First;

        newn = new nodeSC<T>;

        newn -> data = No;
        newn -> next = NULL;

        for (i = 1; i < iPos - 1; i++)
        {
            temp = temp -> next;

        }
        newn -> next = temp -> next;

        temp -> next = newn;

    }
}


template <class T>
void SinglyCl<T>  :: DeleteFirst()
{
    if((First == NULL) && (Last == NULL))
    {
        return;
    }

    else if (First == Last)
    {
        delete(First);

        First = NULL;
        Last = NULL;
    }

    else
    {
        First = First -> next;
        delete(Last -> next);
        Last -> next = NULL;
    }

    
}


template <class T>
void SinglyCl<T>  :: DeleteLast()
{
    struct nodeSC<T> *temp = NULL;

    if((First == NULL) && (Last == NULL))
    {
        return;
    }

    else if (First == Last)
    {
        delete(First);

        First = NULL;
        Last = NULL;
    }

    else
    {
        temp = First;

        while(temp -> next -> next != NULL)
        {
            temp = temp -> next;
        }

        delete (Last);

        Last = temp;

        Last -> next = First;
    }


    
}


template <class T>
void SinglyCl<T>  :: DeleteAtPos(int iPos)
{
    int i = 0;

    struct nodeSC<T> *temp1 = NULL;
    struct nodeSC<T> *temp2 = NULL;

    if((iPos < 1) || (iPos > iCount))
    {
        printf("invalid Syntax\n");

        return ;
    }

    if(iPos == 1 )
    {
        DeleteFirst();
    }

    else if (iPos == iCount + 1)
    {
        DeleteLast();
    }

    else
    {
        temp1 = Last;

        for(i = 1; i < iPos - 1; i++)
        {
            temp1 = temp1 -> next;
        }
        temp2 = temp1 -> next;

        temp1 -> next = temp2 -> next;

        delete(temp2);

    }
    
    
}






/////////////////////////////////////////////////////////////
//
// Code of Stack
//
/////////////////////////////////////////////////////////////

template <class T>
struct nodeSTR
{
    T data;
    struct nodeSTR *next;
};

template <class T>
class Stack
{
    private:
        struct nodeSTR<T> *First;
        int iCount;

    public:
        Stack();
        void Display();
        int Count();
        void Push(T No);  // InsertFirst()
        int Pop();   // DeleteFirst()
};

template <class T>
Stack<T> :: Stack()
{
    First = NULL;
    iCount  = 0;

}


template <class T>
void Stack<T> :: Display()
{
    cout<<"elements of stacks are :\n";

    struct nodeSTR<T> *temp = First;

    while(temp != NULL)
    {
        cout<<temp -> data<<"\n";
        temp = temp -> next;
    }
    cout<<"\n";

}


template <class T>
int Stack<T> :: Count()
{
    return iCount;
}


template <class T>
void Stack<T> :: Push(T No)  //Insert First
{
    struct nodeSTR<T> *newn = NULL;

    newn = new nodeSTR<T>;

    newn -> data = No;
    newn -> next = NULL;

    if (First == NULL)
    {
        First = newn;
    }
    else
    {
        newn -> next =First;
        First = newn;
    }
    iCount++;

}


template <class T>
int Stack<T> :: Pop()      // DeleteFirst
{
    int iValue = 0;
    struct nodeSTR<T> *temp = NULL;

    if (First == NULL)
    {
        cout<<"unable to pop the element as stack is empty\n";
        return -1;
    }

    else
    {
        temp = First;

        iValue = First -> data;
        First = First -> next;

        delete temp;
        

    }
    return iValue;
}




/////////////////////////////////////////////////////////////
//
// Code of Queue
//
/////////////////////////////////////////////////////////////

template <class T>
struct nodeQ
{
    T data;
    struct nodeQ *next;
};

template <class T>
class Queue
{
    private:
        struct nodeQ<T> *First;
        int iCount;

    public:
        Queue();
        void Display();
        int Count();
        void EnQueue(T No);    // Insert Last
        int DeQueue();      // DeleteFirst
};


template <class T>
Queue<T> :: Queue()
{
    First = NULL;
    iCount = 0;
}


template <class T>
void Queue<T> :: Display()
{
    cout<<"Element of Q are :\n";
    struct nodeQ<T> *temp = First;

    while (temp != NULL)
    {
        cout<<temp -> data<<"\t";
        temp = temp -> next;
    }
    cout<<"\n";
    
}


template <class T>
int Queue<T> :: Count()
{
    return iCount;
} 


template <class T>
void Queue<T> :: EnQueue(T No)     //InsertLast
{
    struct nodeQ<T> *temp = NULL;
    struct nodeQ<T> *newn = NULL;

    newn = new nodeQ<T>;

    newn -> data = No;
    newn -> next = NULL;

    if (First == NULL)
    {
        First = newn;
    }

    else
    {
        temp = First;

        while(temp -> next != NULL)
        {
            temp = temp -> next;
        } 

        temp -> next = newn;
    }
    iCount++;

}


template <class T>
int Queue<T> :: DeQueue()      //DeleteFirst
{
    int iValue = 0;
    struct nodeQ<T> *temp = NULL;

    if (First == NULL)
    {
        cout<<"unalbe to remove as quque is empty\n";
        return -1;
    }

    else
    {
        temp = First;
        iValue = First -> data;
        First = First -> next;
        delete temp;

        iCount--;
    }

    return iValue;

}



int main()
{
    

    return 0;
}