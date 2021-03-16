#include "header1.h"
#include "header2.h"

using namespace header1;


namespace header1 {
    int func() {
        foo();
        header2::foo();
    }
}

// static keyword
namespace {
    // static int isSstaticFunc() 
    int isStaticFunc() {

    }
    // static isStaticVar
    int isStaticVar = 0;
} // namespace


int main() {
    header2::foo();
    foo();
    bar();

    isStaticFunc();
    isStaticVar = 10;
}