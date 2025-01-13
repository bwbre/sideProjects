#include "list.h"
#include <iostream>

using namespace std;

template < typename T >
List< T >::List()
{
    size = 5;
    data = new T[5];    
}

template < typename T >
List<T>::List(int givenMaxSize)
{
    size = 0;
    maxSize = givenMaxSize;
    data = new T[maxSize];   
    if (maxSize <= 0)
    {
        size = 0;
        maxSize = 0;
    } 
}

template < typename T>
List<T>::List(const List<T> & listBeingCopied)
{
    Clone(listBeingCopied);

}

template < typename T>
List<T>& List<T>::operator=(const List<T> & listBeingCopied)
{
    if (this != &listBeingCopied)
    {
        if (data != 0)
            delete [] data;
        Clone(listBeingCopied);
    }
    return *this;
}

template < typename T > 
void List<T>::Resize(int newSize)
{
    maxSize = newSize;
    T *temp = new T[maxSize];
    for (int i = 0; i < size; i++)
    {
        temp[i] = data[i];
    }
    delete [] data;
    data = temp;
}

template < typename T >
void List<T>::Clone(const List<T> &srcList) const
{
    maxSize = srcList.maxSize;
    size = srcList.size;
    data = new T[maxSize];
    for (int i = 0; i < size; i++)
    {
        data[i] = srcList->data[i];
    }

}

template < typename T >
void List<T>::Print() const
{
    for (int i = 0; i < size-1; i++)
    { 
        cout << data[i] << " ";
    }
    cout << data[size] << endl;
}

template < typename T >
void List<T>::Insert()
{

}
