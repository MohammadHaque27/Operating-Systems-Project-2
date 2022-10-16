#ifndef D_STRUCTS
#define D_STRUCTS

#include <cstdlib>
#include <string>
#include <vector>

class CircularArray 
{
public:    
    CircularArray(int length);
    int getSize();
    int getLoopOffset();
    void incrementLoopOffset();
    int calculateCircularIndex(); //used when index >= size
    unsigned *array; //may need to add array as a member somewhere, but also might not want it to be a private member

private:
    int size; //length of array
    int loopOffset; // for loopOffset % size
};


// class LRUQueue
// {
// public:
//     LRUQueue();

// private:

// };

#endif // D_STRUCTS
