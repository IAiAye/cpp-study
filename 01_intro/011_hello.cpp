#include <iostream>

//std를 사용하기 싫다면
//using namespace std;
//추가, 권장되지 않는다.

int main(){
    std::cout << "H i" << std::endl
     << "my name is " 
     << "Mad Monster" << std::endl; //iostream 헤더 파일 속의 std 라는 이름 공간 속의 cout, endl 이 정의 되어있음.
    //endl 은 엔터의 효과.
    return 0;
}