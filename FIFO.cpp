
#include<iostream>
#include<cstdlib>
#include <string>
#include <vector>
#include <stdio.h>
#include "dataStructures.cpp"


//Function for FIFO Algorithm 
void FIFO(int nframes, const char* traceName){
    //use a different class for each page table object based on what the replacement algorithm needs
    CircularArray pageTable(nframes); //passed as argument
    
    FILE * tracefile;
    tracefile = fopen(traceName, "r"); //argv[0] = <tracefile>
    
    unsigned addr; 
    unsigned frameNum;
    char rw;
    int hits = 0;
    std::string isFrame = "No";
    while (fscanf(tracefile,"%x %c",&addr,&rw) != EOF) //Loop: read each address from trace file
    {
        frameNum = addr / 4096; //Extract frame number by removing the 12 offset bits
        //std::cout << frameNum << " ";
        //loop to compare addr to each page table entry
        for (int i = 0; i < pageTable.getSize(); i++) {
            isFrame = "No";
            if (frameNum == pageTable.array[i])
            {
                hits++;
                isFrame = "Frame same as entry";
                break;
            }
            else if (pageTable.array[i] == 0)//Check if page table is empty
            {
                pageTable.array[i] = frameNum;
                break;
            }
            else //needs to be added to the table
            {
                //std::cout << i << " ";
                int replacementIndex = pageTable.calculateCircularIndex();
                pageTable.array[replacementIndex] = frameNum;
                pageTable.incrementLoopOffset();
                break;
            }
        }

    }


    //This is the replacement policy code if the page isn't found and it isn't empty

    
    


    // std::cout<< "Successfully added\n";
    for (int i = 0; i < pageTable.getSize(); i++) {
        std::cout<< pageTable.array[i] << ", ";
    }
    std::cout << hits << ".";
    

    //std::cout << size << std::endl;
    fclose(tracefile); //argv[0] = <tracefile>
}


int main(){
    //int frames[7] = {0x0042bf60, 0x2f293f60, 0x1f16ff60, 0x0041f760, 0x37c1f760, 0x0041f840, 0x0041f860};
    FIFO(4, "bzip.trace");

    return 0;
}