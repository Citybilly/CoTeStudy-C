#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

char * MakeStrAdr(int len)
{
    char * str = (char*)malloc(sizeof(char)*len); // char 을 입력받고 길이를 곱해서 char * len 만큼의 사이즈를 할당한다. , char 포인터로 형변환
    return str;
}

int main(void)
{
    char * str = MakeStrAdr(20);
    strcpy(str, "I am so happy~");
    cout << str << endl;
    free(str);
    return 0;
}