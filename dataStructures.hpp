#ifndef D_STRUCTS
#define D_STRUCTS

#include <cstdlib>

class CircularArray 
{
public:    
    CircularArray(int size);
    int getSize();
    int getLoopOffset();
    void incrementLoopOffset();
    int calculateCircularIndex(); //used when index >= size

private:
    int size; //length of array
    int loopOffset; // for loopOffset % size
};

#endif // D_STRUCTS
