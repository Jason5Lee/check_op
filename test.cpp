#include "check_op.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <cinttypes>
#include <string>
#include <cstdlib>
#include <iostream>
#include <cstdlib>
using namespace std;

void assert(bool expr, int line) {
    if (!expr) {
        cout << "Test failed at line " << line << "." << endl;
        abort();
    }
}

#define ASSERT(...) assert(__VA_ARGS__, __LINE__)

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
    ASSERT(succ == ((int64_t)a + (int64_t)b == (int64_t)result));
    
    succ = check_sub(a, b, result);
    ASSERT(succ == ((int64_t)a - (int64_t)b == (int64_t)result));

    succ = check_mul(a, b, result);
    ASSERT(succ == ((int64_t)a * (int64_t)b == (int64_t)result));
}

template<typename TInt>
void test_unsign(const string &typeName) {
    TInt a = randInt<TInt>();
    TInt b = randInt<TInt>();
    TInt result;

    bool succ = check_uadd(a, b, result);
    ASSERT(succ == ((int64_t)a + (int64_t)b == (int64_t)result)); 

    succ = check_usub(a, b, result);
    ASSERT(succ == ((int64_t)a - (int64_t)b == (int64_t)result));

    succ = check_umul(a, b, result);
    ASSERT(succ == ((int64_t)a * (int64_t)b == (int64_t)result)); 
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
