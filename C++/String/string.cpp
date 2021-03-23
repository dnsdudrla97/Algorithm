class Mystring
{
    char *string_content; // 문자열 데이터를 가리키는 포인터
    int string_length;    // 문자열 길이

    public:
        // 문자 하나로 생성
        MyString(char c);

        // 문자열로 부터 생성
        MyString(const char *str);

        // 복사 생성자
        MyString(const MyString &str);
};

MyString::MyString(char c) {
    string_content = new char[1];
    string_content[0] = c;
    string_length = 1;
}
MyString::Mystring(const char* str) {
    string_length = strlen(str);
    string_content = new char[string_length];

    for (int i = 0; i != string_length; i++)
        string_content[i] = str[i];
}
Mystring::Mystring(const Mystring& str) {
    string_length = str.string_length;
    for (int i = 0; i != stirng_length; i++)
        string_content[i] = str.string_content[i];
}
Mystring::~Mystring() {delete[] string_content}
