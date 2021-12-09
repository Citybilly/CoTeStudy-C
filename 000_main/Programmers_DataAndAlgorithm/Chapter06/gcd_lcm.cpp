#include <iostream>
#include <numeric> // -std=c++17 버전부터 지원
// 컴파일, 실행 커멘드 : cd "/Users/woohyun/000_Github/001_CoTeStudy-C/000_main/Programmers_DataAndAlgorithm/Chapter06/" && g++ -std=c++17 gcd_lcm.cpp -o gcd_lcm && "/Users/woohyun/000_Github/001_CoTeStudy-C/000_main/Programmers_DataAndAlgorithm/Chapter06/"gcd_lcm

using namespace std;

// 유클리드 알고리즘 (유클리드 호제법) 을 이용하여재귀적으로 구할 수 있음.

int gcd(int a, int b) // 최대 공약수
{
    if(b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int lcm (int a, int b) // 최대 공약수
{
    return a * b / gcd(a,b);
}


int main()
{
	int gcd1 = gcd(10, 15);
	int lcm1 = lcm(10, 15);

	int gcd2 = std::gcd(10, 15);
	int lcm2 = std::lcm(10, 15);

	std::cout << gcd1 << ", " << gcd2 << std::endl;
	std::cout << lcm1 << ", " << lcm2 << std::endl;

    return 0;
}