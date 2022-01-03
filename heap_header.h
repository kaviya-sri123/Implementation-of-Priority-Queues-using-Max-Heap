#include<iostream>
using namespace std;
class MaxHeap
{
    int max_heap[10];
    int size;
    public:
        MaxHeap()
        {
            size=-1;
        }
        void enqueue(int e);
        void dequeue();
        void display();
        void search();
        void increaseKey(int e,int dec);
        void findMax();
        void percolateUp(int i);
        void percolateDown(int i);
        int root(int i); 
        int left(int i); 
        int right(int i);
        bool isFull(); 
        bool isEmpty(); 
};