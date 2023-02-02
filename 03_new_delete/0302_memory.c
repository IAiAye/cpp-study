//메모리의 배치 모습

#include <stdio.h>

int global = 3;
int main()
{
    int i;
    char *str = "Hello, Baby";
    char arr[20] = "WHATTHEHECK";

    printf("global : %p \n", &global); // 리터럴 다음으로 전역변수가 위치해있음.
    printf("i : %p \n", &i); // 전역변수 다음으로 지역 변수가 위치.
    printf("str : %p \n", str); // 리터럴이므로 가장 낮은 위치에 있음.
    printf("arr : %p \n", arr); 
}