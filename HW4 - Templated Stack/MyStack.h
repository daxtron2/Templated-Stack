// HW4 - Templated Stack
// TJ Wolschon
#pragma once
#include <iostream>


using namespace std;

template <class Type>
class MyStack
{
private:
    Type* dynamicArray;
    int arrayLength;

    void ResizeArray(int newLength)
    {
        //setup a temp array 
        Type* temp = new Type[newLength]{};

        //if we want to make array bigger, use 1
        //if we want to make it smaller, use 0
        int iter = newLength > arrayLength;
        //loop through temp
        for (int i = 0; i < arrayLength; i++)
        {
            //if making larger i.e. a push, it leaves a free space in the front
            //if it's making smaller, i.e. a pop, it doesn't
            //the first space in the array is essentially dead and will only get overwritten eventually
            temp[i + iter] = dynamicArray[i];
        }

        //clear the array
        delete[] dynamicArray;
        //and store the newly resized version back in
        dynamicArray = temp;
        //change length
        arrayLength = newLength;

    }
public:
    //constructor
    MyStack()
    {
        //start with an array of size 1 filled with the default of the given type
        dynamicArray = new Type[1]{};
        arrayLength = 1;
    }

    //destructor
    ~MyStack()
    {
        delete[] dynamicArray;
        dynamicArray = nullptr;
    }


    //copy constructor
    MyStack(const MyStack &other)
    {
        cout << "Using Copy Constructor" << endl;

        //copy the length and setup the array
        arrayLength = other.arrayLength;
        dynamicArray = new Type[arrayLength];

        //copy the data into the newly made array.
        for (int i = 0; i < other.arrayLength; i++)
        {
            dynamicArray[i] = other.dynamicArray[i];
        }
    }

    //copy assignment operator
    MyStack& operator=(const MyStack & other)
    {
        cout << "Using Copy Assignment Operator" << endl;
        //if trying to copy to itself, just return itself
        if (this == &other) return *this;

        //if there's already data stored in it
        if (dynamicArray != nullptr)
        {
            //get rid of it so it wont cause problems
            delete[] dynamicArray;
            dynamicArray = nullptr;
        }

        arrayLength = other.arrayLength;
        dynamicArray = new Type[arrayLength];

        //copy over the data
        for (int i = 0; i < other.arrayLength; i++)
        {
            dynamicArray[i] = other.dynamicArray[i];
        }

        return *this;
    }

    //index operator overload
    Type &operator[](int index)
    {
        if (index < 0)
        {
            cout << "Invalid index... Returning first." << endl;
            return dynamicArray[1];//first real value
        }
        return dynamicArray[index+1];//+1 because first position is not used for up-to-date data
    }

    //push to stack
    void Push(Type itemToPush)
    {
        cout << "Pushing: " << itemToPush << endl;
        //add to the front of the array
        dynamicArray[0] = itemToPush;
        //and immediately resize to push it to the correct position
        ResizeArray(arrayLength + 1);
    }

    //pop from stack
    void Pop()
    {
        arrayLength--;
        cout << "Popping: " << dynamicArray[1] << endl;
        //loop through all but first
        for (int i = 0; i < arrayLength; i++)
        {
            //move the element back one
            dynamicArray[i] = dynamicArray[i+1];
        }

        ResizeArray(arrayLength);
    }

    //print contents
    void Print()
    {
        cout << "Stack Size: " << GetSize() << " Stack Contents: ";
        //loop through, ignore the first in the array
        for (int i = 1; i < arrayLength; i++)
        {
            //if last in array, add an endline
            if (i == arrayLength - 1)
            {
                cout << dynamicArray[i] << endl;
            }
            else//otherwise use a pipe for seperation
            {
                cout << dynamicArray[i] << " | ";
            }
        }
    }

    //get number of valid elements
    int GetSize()
    {
        //because of the way I am using the array,
        //the size will always be one less than length
        return arrayLength - 1;
    }

    //check if empty
    bool IsEmpty()
    {
        return GetSize() > 0;
    }
};

