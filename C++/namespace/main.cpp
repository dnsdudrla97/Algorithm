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
    int isStaticFunc() {

    }

    int isStaticVar = 0;
}


int main() {
    foo();
    bar();
}