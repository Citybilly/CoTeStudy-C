#include <iostream>
#include <array>

int main (void)
{
    std::array<int,5> arr = {1,2,3,4,5};

    // example case of NOT USING FUNCTION
    for (auto element : arr)
    {
        std::cout << element << ' ';  // Print All elements of arr
    }

    std::cout << std::endl;

    // example case of using member fucntions
    for(auto it = arr.begin(); it != arr.end(); it++) // First element(begin) to Last element(end)
    {
        auto element = (*it);
        std::cout << element << ' ';
    }

    std::cout << arr.front() << std::endl;          // print 1
    std::cout << arr.back() << std::endl;           // print 5
    std::cout << *(arr.data() + 1) << std::endl;    // print 2

    return 0;
}