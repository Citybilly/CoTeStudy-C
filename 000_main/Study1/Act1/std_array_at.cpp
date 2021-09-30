#include <iostream>
#include <array>

int main( void )
{

    std::array<int, 4> arr3 = {1,2,3,4};

    std::cout << arr3[3] << std::endl; // 4 출력
    std::cout << arr3[4] << std::endl; // 0 출력 "out of range 이지만 크기 검사 하지 않는다"

    try
    {
        std::cout << arr3.at(3) << std::endl;   // 에러 아님
        std::cout << arr3.at(4) << std::endl;   // std::out_of_range 예외 발생
    }
    catch(const std::out_of_range& ex)
    {
        std::cerr << ex.what() << std::endl;
    }

    return 0;
    
}