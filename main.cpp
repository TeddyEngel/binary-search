//
//  main.cpp
//  BinarySearch
//
//  Created by Teddy Engel on 19/02/2015.
//  Copyright (c) 2015 Teddy Engel. All rights reserved.
//

#include <vector>
#include <iostream>

#define NIL -1

void PrintVectorInline(std::vector<int>& values)
{
    int i;
    
    for(i = 0; i < values.size(); i++)
    {
        std::cout << values[i] << ' ';
    }
    std::cout << std::endl;
}

void PrintVector(std::vector<int>& values)
{
    int i;
    
    for(i = 0; i != values.size(); i++)
    {
        std::cout << values[i] << std::endl;
    }
}

int RecursiveBinarySearch(const int& needle, const std::vector<int>& haystack, const int& start, const int& end)
{
    int position = NIL;
    int length = end - start;

    if (length == 1 && haystack[start] == needle)
    {
        position = start;
        printf("Found position with length 1: %d!\n", start);
    }
    else if (length > 1)
    {
        int middle = (start + end) / 2;

        if (haystack[middle] > needle)
        {
            printf("Going down left\n");
            position = RecursiveBinarySearch(needle, haystack, start, middle);
        }
        else if (haystack[middle] < needle)
        {
            printf("Going down right\n");
            position = RecursiveBinarySearch(needle, haystack, middle, end);
        }
        else
        {
            printf("Found position: %d!\n", middle);
            position = middle;
        }
    }
    return position;
}

int BinarySearch(const int& needle, const std::vector<int>& haystack)
{
    return RecursiveBinarySearch(needle, haystack, 0, haystack.size());
}

int main(int argc, const char* argv[])
{
    int needle = 3;
    int foundPosition = NIL;
    // Collection HAS to be sorted
    std::vector<int> values = {-4, 0, 2, 2, 3, 5, 10};
    
    std::cout << "Our sorted collection is:" << std::endl;
    PrintVector(values);
    std::cout << "Looking for: " << needle << std::endl;
    foundPosition = BinarySearch(needle, values);
    if (foundPosition == NIL)
        std::cout << "Not found in sorted collection" << std::endl;
    else
        std::cout << "Found in sorted collection at position " << foundPosition << std::endl;
    return 0;
}
