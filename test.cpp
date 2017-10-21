#include "check_op.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <cinttypes>
#include <string>
#include <cstdlib>
#include <iostream>
using namespace std;

const int TEST_CASES = 1000;

template<typename TInt>
TInt randInt() {
    TInt ans = 0;
    for (size_t i = 0; i < sizeof(TInt) * 4; i += 15) {
        ans |= (TInt)(rand() & 0x7FFF) << i;
    }
    return ans;
}

template<typename TInt>
void test_sign(const string &typeName) {
    TInt a = randInt<TInt>();
    TInt b = randInt<TInt>();
    TInt result;

    bool succ = check_add(a, b, result);
    if (succ ^ ((int64_t)a + (int64_t)b == (int64_t)result)) {
        cout << "Wrong for " << typeName << " : " << a << " + " << b << endl;
    }

    succ = check_sub(a, b, result);
    if (succ ^ ((int64_t)a - (int64_t)b == (int64_t)result)) {
        cout << "Wrong for " << typeName << " : " << a << " - " << b << endl;
    }

    succ = check_mul(a, b, result);
    if (succ ^ ((int64_t)a * (int64_t)b == (int64_t)result)) {
        cout << "Wrong for " << typeName << " : " << a << " * " << b << endl;
    }
}

template<typename TInt>
void test_unsign(const string &typeName) {
    TInt a = randInt<TInt>();
    TInt b = randInt<TInt>();
    TInt result;

    bool succ = check_uadd(a, b, result);
    if (succ ^ ((int64_t)a + (int64_t)b == (int64_t)result)) {
        cout << "Wrong for " << typeName << " : " << a << " + " << b << endl;
    }

    succ = check_usub(a, b, result);
    if (succ ^ ((int64_t)a - (int64_t)b == (int64_t)result)) {
        cout << "Wrong for " << typeName << " : " << a << " - " << b << endl;
    }

    succ = check_umul(a, b, result);
    if (succ ^ ((int64_t)a * (int64_t)b == (int64_t)result)) {
        cout << "Wrong for " << typeName << " : " << a << " * " << b << endl;
    }
}
int main() {
    srand(time(NULL));
    for (int i = 0; i < TEST_CASES; ++i ) {
        test_sign<int8_t>("signed 8bits");
        test_unsign<uint8_t>("unsigned 8bits");

        test_sign<int16_t>("signed 16bits");
        test_unsign<uint16_t>("unsigned 16bits");

        test_sign<int32_t>("signed 32bits");
        test_unsign<uint32_t>("unsigned 32bits");
    }
    return 0;
}