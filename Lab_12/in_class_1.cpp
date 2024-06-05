/*
The following is an example of using the std::copy() function to create a deep copy of the content managed by a raw pointer.
*/



#include <iostream>
#include <algorithm> // For std::copy



int main() 
{
    // Define the size of the arrays
    const size_t size = 5;

    // Create a raw pointer to manage a dynamic array
    int* sourceArray = new int[size];

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

    // Create another raw pointer to manage the destination array
    int* destArray = new int[size];

    // Copy the contents of the source array to the destination array using std::copy
    std::copy(sourceArray, sourceArray + size, destArray);

    // Display the destination array to verify the copy
    std::cout << "Destination array: ";
    for (size_t i = 0; i < size; ++i) 
    {
        std::cout << destArray[i] << " ";
    }
    std::cout << std::endl;
    
    // Manually delete the arrays to free the memory
    delete[] sourceArray;
    delete[] destArray;
    return 0;
}