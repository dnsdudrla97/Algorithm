#include <iostream>

class string {
  char *string_content;
  int string_length;

 public:
  string(char c, int n);  // 문자 c 가 n 개 있는 문자열로 정의
//   string(const char *s);
  string(const string &s);
  ~string();

  // string_content 뒤에 s 를 붙인다.
  void add_string(const string &s); 
  void copy_string(const string &s);  // string_content 에 s 를 복사한다.
  int strlen();                       // 문자열 길이 리턴
};
int string::strlen() {
    char* origin = this->string_content;
    std::cout << origin << std::endl;
    for (unsigned int i = 0; origin[i]; i++) {
        this->string_length = i;
    }
    return this->string_length;

}
string::string(char c, int n) {
    std::cout << "문자 : " << c << std::endl;
    string_content = new char[n+1];
    for (int i = 0; i < n; i++) {
        string_content[i] = c;
    }
    string_content[n] = 0x0;
    std::cout << "문자열 : " << string_content << std::endl;
};
void string::add_string(const string &s) {
    unsigned int cnt = 0;
    std::cout << "복사 생성자" << std::endl;
    std::cout << s.string_content << std::endl;
    std::cout << string_content << std::endl;
    
    while(true) {
        if (string_content[cnt++] == 0x0) {
            string_content[cnt-1] = s.string_content[0];
            std::cout << string_content << std::endl;
            
            break;
        }
    }
    // std::cout << s.string_content << std::endl;
    
}

string::~string() {
    if (string_content) delete[] string_content;
}


int main(int argc, char const *argv[])
{
    int string_length;
    /* code */
    string s1('A', 10);
    string s2('B', 10);

    s1.add_string(s2);
    string_length = s1.strlen();
    std::cout << string_length << std::endl;


    
    
    
    return 0;
}
