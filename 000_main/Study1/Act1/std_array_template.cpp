#include <iostream>
#include <array>

// Non-Template function
void print1(std::array<int,5> arr)
{
    for (auto ele : arr)
        std::cout << ele << ", ";
}
// Template Function
template <size_t N>
void print2(const std::array<int, N>& arr)
{
    for (auto ele : arr)
        std::cout << ele << ", ";
}

int main(void)
{
    // example case of Template not-used
    std::array<int,5> arr = {1,2,3,4,5};
    print1(arr);

    std::cout << std::endl;

    // example case of Template used
    print2(arr);
    std::cout << std::endl;

    // example case of NOT USING FUNCTION
    for (auto element : arr)
    {
        std::cout << element << ' ';  // Print All elements of arr
    }

    return 0;
}