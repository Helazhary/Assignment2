#pragma once
#include <iostream>
using namespace std;


template<class T>

class queue
{
    T cline[20];
    int f, b;

public:

    queue()
    {
        f = 0;
        b = -1;
    }
    void push(T x)
    {
        if (full()==false)
        {  
            b++;
            cline[b] = x;
          
        }
        else if (full()==true)
            cout << "queue full" << endl;

    }

    void pop()
    {
        if (empty() == false)
        {
            for (int i = 0; i < 19; i++)
            {
                cline[i] = cline[i + 1];
            }
            b--;
        }
        else
            cout << "queue full" << endl;
    }
    T front()
    {
        if (empty()==false)
            return cline[0];
        else
            cout << "queue empty" << endl;
    }
    bool empty()
    {
        if (f == 0 && b == -1)
             return true;
       return false;
    }
    bool full()
    {
        if (b == 19)
            return true;
        return false;
    }
    T returnfront()
    {
        if (empty()==false)
        {
            return cline[f];
        }
        else
            cout << "queue empty" << endl;
    }

};
