#include <iostream>
#include <sstream>
#include <algorithm>

template <typename T>
class dynamic_array
{
    T *data; // 타입이 정해지지 않은 데이터 포인터
    size_t n; // 사이즈가 정해지지 않은 변수 n

    public:
    dynamic_array(int n)
    {
        this->n = n;    //  dynamic_array.n
        data = new T[n]; // n사이즈의 type이 정해지지 않은 데이터 포인터
    }

    dynamic_array(const dynamic_array<T>& other)
    {
        n = other.n;    // 객체 자체를 input으로 받으면서 인스턴스화 됐을 때는 객체의 n을 가리킨다.
        data = new T[n];    // n사이즈의 type이 정해지지 않은 데이터 포인터
        for(int i = 0; i < n; i++)
            data[i] = other[i]; // other[i], [] 오퍼레이터가 other 객체 내의 data[n]을 가져온다.
    }

    T& operator[](int index)
    {
        return data[index];
    }

    const T& operator[](int index) const
    {
        return data[index];
    }

    T& at(int index)
    {
        if(index < n)
            return data[index];
        throw "Index out of range";
    }

    size_t size() const
    {
        return n;
    }

    ~dynamic_array()    // destructor (소멸자)
    {
        delete[] data;  //  메모리 릭 방지 = 할당된 메모리를 해제
    }

    T* begin() {return data;}
    const T* begin() const {return data;}
    T* end() {return data+n;}
    const T* end() const {return data+n;}

    friend dynamic_array<T> operator+(const dynamic_array<T>& arr1, dynamic_array<T>& arr2)
    {
        dynamic_array<T> result(arr1.size() + arr2.size()); // 새로운 객체 생성하고 두 어레이 크기의 합만큼의 size를 부여한다.
        std::copy(arr1.begin(), arr1.end(), result.begin()); // std::copy ? 
        std::copy(arr2.begin(), arr2.end(), result.begin() + arr1.size());

        return result;
    }

    std::string to_string(const std::string& sep = ", ")
    {
        if(n == 0)
            return "";

        std::ostringstream os;
        os << data[0];

        for (int i = 1; i < n; i++)
            os << sep << data[i];

        return os.str();
    }

};


struct student
{
    std::string name;
    int standard;
};


std::ostream& operator << (std::ostream& os, const student& s) // class 에서 생성된 string의 주소와 struct 의 주소를 받는다.
{
    return (os << "[" << s.name << ", " << s.standard << "]");
}


int main( )
{
    int nStudents;
    std::cout << "1반 학생 수를 입력하세요: ";
    std::cin >> nStudents;
    std::cout << "하하하하하하" << std::endl;
    dynamic_array<student> class1(nStudents);
    for(int i=0; i < nStudents; i++)
    {
        std::string name;
        int standard;
        std::cout << i + 1 << "번째 학생 이름과 나이를 입력하세요: ";
        std::cin >> name >> standard;
        class1[i] = student{name, standard};
    }   

    // 배열 크기보다 큰 인덱스의 학생에 접근
    try
    {
        //  아래 주석을 해제하면 프로그램이 비정상 종료합니다.
        //  class1[nStudends] = student {"John", 8};    // 예상할 수 없는 동작

        class1.at(nStudents) = student{"John", 8};      // 예외 발생
    }

    catch (...)
    {
        std::cout << "예외 발생!" << std::endl;
    }

    // 깊은 복사
    auto class2 = class1;
    std::cout << "1반을 복사하여 2반 생성: " << class2.to_string() << std::endl;

    //  두 학급을 합쳐서 새로운 큰 학급을 생성
    auto class3 = class1 + class2;
    std::cout << "1반과 2반을 합쳐 3반 생성: " << class3.to_string() << std::endl;

    return 0;
}