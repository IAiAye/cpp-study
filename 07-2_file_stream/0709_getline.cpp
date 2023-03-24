//한 줄씩 읽기
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    ifstream in("text.txt");
    //char buf[100];

    if (!in.is_open())
    {
        cout << "파일을 찾을 수 없습니다!" << endl;
        return 0;
    }

    string s;
    while (in)
    {
        //in.getline(buf, 100, '.'); // 개행문자가 나올때까지 읽어준다. 혹은 세번째 인자로 지정해줄수 있다. 
        //cout << buf << endl; // 하지만 ifstream의 getline함수는 지정한 버퍼(위에서의 100)가 너무 작다면 오류가 발생하므로 확인해야한다.
        getline(in, s); // string에서 제공하는 getline
        cout << s << endl;
    }
    
    return 0;
}