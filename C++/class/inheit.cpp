#include <iostream>
#include <string>

int main() {
  std::string s = "abc";
  std::string t = "def";
  std::string s2 = s;

   std::cout << s << " 의 길이 : " << s.length() <<  std::endl;
   std::cout << s << " 뒤에 " << t << " 를 붙이면 : " << s + t <<  std::endl;

  if (s == s2) {
     std::cout << s << " 와 " << s2 << " 는 같다 " <<  std::endl;
  }
  if (s != t) {
     std::cout << s << " 와 " << t << " 는 다르다 " <<  std::endl;
  }
  return 0;
}
// string-> 짧은 문자열에 대해서는 동적을 메모리를 할당 하지 않고 지역 변수로 보관후 문자열을 복사할 때 해당 문자열의 내용이 바뀌지 않는 한 실제로 데이터를 복하는 것이 아니다.