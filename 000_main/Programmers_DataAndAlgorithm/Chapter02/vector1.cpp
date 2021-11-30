#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v1;
    vector<int> v2(10); // v2[0] ~ v2[9]
    vector<int> v3(10, 1); // 초기값이 1로 만들어짐
    vector<int> v4 {10, 20, 30, 40, 50};

    vector<int> v5 = v4;   // 깊은 복사, vector<int> v5(v4) 도 가능
    vector<int> v6(v4.begin(), v4.begin() + 3); // 10, 20 ,30 까지만 복사. 

    for (int i = 0; i < v6.size(); i++)
        cout << v6[i] << endl;

    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);

    // v1[0], v1[1], v1[2]

    vector<vector<int>> mat1(2, vector<int>(3,1)); // 2차원 vector 2행 3열 이며 1로 체워짐.
    vector<vector<int>> mat2{ 
        {1,2,3}, 
        {4,5,6}
    };

    for (int r = 0; r < mat2.size(); r++) {
        for (int c = 0; c < mat2[r].size(); c++){
            cout << mat2[r][c] << ", ";
        }
        cout << endl;
    }
    return 0;
}