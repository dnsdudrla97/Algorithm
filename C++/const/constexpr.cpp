constexpr int dmv = 17;        // dmv는 명명된 상수
int var = 17;                  // var는 상수가 아님
const double sqv = sqrt(var);  // sqv는 명명된 상수로 실행 시간에 계산될 수 있다.

double sum(const vector<double>&); // sum은 인자를 변경하지 않음

vector<double> v {1.2,3.5,4.5}; // v는 상수가 아님
const double s1 = sum(v);       // OK: sum(v)를 실행시간에 평가
constexpr double s2 = sum(v)    // err: sum(v)는 상수 표현식이 아님

constexpr double square(double x) {return x*x;}

constexpr double max1 = 1.4*square(17);     //OK
constexpr double max2 = 1.4*square(var);    //err: var은 상수표현식이 아님
const double max3 = 1.4*square(var);        // OK, 실행 시간에 평가 가능