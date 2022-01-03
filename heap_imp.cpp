#include "heap_header.h"
void MaxHeap::enqueue(int e)
{
    if(!isFull())
    {
        size++;
        max_heap[size]=e;
        int index = size;
        percolateUp(index);
        cout<<"\nElement Queued.\n\n";
    }
    else
        cout<<"\nQueue is full.\n\n";
}
void MaxHeap::dequeue()
{
    if(isEmpty())
    {
        cout<<"\nHeap is empty.\n\n";
        return;
    }
    int ele = max_heap[0];
    cout<<"\nDequeued element : "<<ele<<"\n\n";
    max_heap[0]=max_heap[size];
    size--;
    percolateDown(0);
}
void MaxHeap::display()
{
    if(isEmpty())
    {
        cout<<"\nHeap is empty.\n\n";
        return;
    }
    cout<<"Max Heap : ";
    for(int i=0;i<size+1;i++)
        cout<<max_heap[i]<<"   ";
    cout<<"\n\n";
}
void MaxHeap::search()
{
    if(isEmpty())
    {
        cout<<"\nHeap is empty.\n\n";
        return;
    }
    int e;
    cout<<"Enter the element to search : ";
    cin>>e;
    for(int i=0;i<size+1;i++)
    {
        if(max_heap[i]==e)
        {
            cout<<"\nElement found.\n\n";
            return;
        }
    }
    cout<<"\nElement not found.\n\n";
}
void MaxHeap::increaseKey(int e,int inc)
{
    int flag=0,index;
    for(int i=0;i<size+1;i++)
    {
        if(max_heap[i]==e)
        {
            index=i;
            flag=1;
        }
    }
    if(flag==1)
    {
        max_heap[index]+=inc;
        cout<<"Value of "<<e<<" is increased by "<<inc<<"\n\n";
        percolateUp(index);
    }
    else
        cout<<"\nElement not found.\n\n";
}
void MaxHeap::findMax()
{
    if(isEmpty())
    {
        cout<<"\nHeap is empty.\n\n";
        return;
    }
    cout<<"\nMaximum element : "<<max_heap[0]<<"\n\n";
}
void MaxHeap::percolateUp(int i)
{
    if(i && max_heap[root(i)] < max_heap[i])
    {
        swap(max_heap[i],max_heap[root(i)]);
        percolateUp(root(i));
    }
}
void MaxHeap::percolateDown(int i)
{
    int l = left(i);
    int r = right(i);
    int largest = i;
    if(l < size+1 && max_heap[l] > max_heap[i]) 
    {
        largest = l;
    }
    if(r < size+1 && max_heap[r] > max_heap[largest]) 
    {
        largest = r;
    }
    if(largest != i)
    {
        swap(max_heap[i],max_heap[largest]);
        percolateDown(largest);
    }
}
int MaxHeap::root(int i)
{
    return (i-1)/2;
}
int MaxHeap::left(int i)
{
    return (i*2)+1;
}
int MaxHeap::right(int i)
{
    return (i*2)+2;
}
bool MaxHeap::isFull()
{
    if(size==9)
        return true;
    return false;
}
bool MaxHeap::isEmpty()
{
    if(size==-1)
        return true;
    return false;
}