/*
The following is for the case using a shared pointer. 
Note that the get() function of a smart pointer returns a pointer to the managed object2.
*/


#include <iostream>
#include <memory>
#include <algorithm> // For std::copy



int main() 
{
    // Define the size of the arrays
    const size_t size = 5;

    // Create a unique_ptr to manage a dynamic array
    std::unique_ptr<int[]> sourceArray(new int[size]);

    // Initialize the source array
    for (int i = 0; i < size; ++i) 
    {
        sourceArray[i] = i + 1; // Fill with values 1, 2, 3, 4, 5
    }

    // Display the source array
    std::cout << "Source array: ";
    for (size_t i = 0; i < size; ++i) 
    {
        std::cout << sourceArray[i] << " ";
    }
    std::cout << std::endl;

    // Create another unique_ptr to manage the destination array
    std::unique_ptr<int[]> destArray(new int[size]);

    // Copy the contents of the source array to the destination array using std::copy
    std::copy(sourceArray.get(), sourceArray.get() + size,
    destArray.get());

    // Display the destination array to verify the copy
    std::cout << "Destination array: ";
    for (size_t i = 0; i < size; ++i) 
    {
        std::cout << destArray[i] << " ";
    }
    std::cout << std::endl;

    // No need to manually delete the arrays, unique_ptr will handle it automatically
    return 0;
}