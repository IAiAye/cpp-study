// 문자열 합치기
// str = s1 + s2 + s3 와 같이 스트링을 합치게 되면
// str = s1.operator+(s2).operator+(s3) 와 같으므로 메모리 할당이 2번 발생한다.
// 이를 방지하기 위해 한번에 사이즈를 계산에 할당해주고 합쳐주는 방식을 택해보자.
#include <iostream>
#include <string>

size_t GetStringSize(const char* s) { return strlen(s); }

size_t GetStringSize(const std::string& s) { return s.size(); }

template <typename String, typename... Strings>
size_t GetStringSize(const String& s, Strings... strs)
{
    return GetStringSize(s) + GetStringSize(strs...);
}

// 재귀 마지막에 종료를 위해 리턴
void AppendToString(std::string* concat_str) { return; }

template <typename String, typename... Strings>
void AppendToString(std::string* concat_str, const String& s, Strings... strs) 
{
    concat_str->append(s);
    AppendToString(concat_str, strs...); 
}

// const char* 가 들어와도 가능하다.
template <typename String>
std::string StrCat(const String& s)
{
    return std::string(s);
}

template <typename String, typename... Strings>
std::string StrCat(const String& s, Strings... strs)
{
    // 문자열의 길이 먼저 구하기
    size_t total_size = GetStringSize(s, strs...);

    //reserve를 통해 공간 미리 할당
    std::string concat_str;
    concat_str.reserve(total_size);

    concat_str = s;
    AppendToString(&concat_str, strs...);

    return concat_str;
}


int main()
{
    std::cout << StrCat(std::string("this"), " ", "is", " ", std::string("a"), " ", std::string("sentence")) << std::endl;

    return 0;
}
