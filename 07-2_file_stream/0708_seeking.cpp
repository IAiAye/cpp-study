//파일 전체를 한번에 읽기
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    ifstream in("text.txt");
    string s;

    if (in.is_open())
    {
        in.seekg(0, std::ios::end); // 위치 지정자를 파일 끝으로 옮긴다.
        int size = in.tellg(); // 그 위치를 읽는다. ( 파일의 크기 )
        s.resize(size); // 그 크기의 문자열 할당
        in.seekg(0, std::ios::beg); // 위치 지정자를 다시 파일 맨 앞으로 옮김
        in.read(&s[0], size); // 파일의 크기만큼 읽는다.
        cout << s << endl;
    }
    else
    {
        cout << "파일을 찾을 수 없습니다!" << endl;
    }
    return 0;
}