#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int SizeOfArray;
    int *arr;

    printf("만들고 싶은 배열의 원소의 수  : ");
    scanf("%d", &SizeOfArray);

    arr = (int *)malloc(sizeof(int) * SizeOfArray);
    //int arr[SizeOfArray] 와 동일한 작업을 한 크기의 배열 생성
    // int * 를 통해 형변환

    free(arr);
    // 메모리를 다시 풀어줘서 사용안하는 메모리를 안잡고 있게 만든다.
    return 0;
}