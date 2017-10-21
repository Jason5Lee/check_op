template<typename TSignInt>
inline bool check_add(TSignInt a, TSignInt b, TSignInt &result) {
    result = a + b;
    return (result^a) >= 0 || (result^b) >= 0;
}

template<typename TSignInt>
inline bool check_sub(TSignInt a, TSignInt b, TSignInt &result) {
    result = a - b;
    return (result^a) >= 0 || (result^b) < 0;
}

template<typename TSignInt>
inline bool check_mul(TSignInt a, TSignInt b, TSignInt &result) {
    result = a*b;
    return a == 0 || result/a == b;
}

template<typename TUInt>
inline bool check_uadd(TUInt a, TUInt b, TUInt &result) {
    result = a + b;
    return result >= a;
}

template<typename TUInt>
inline bool check_usub(TUInt a, TUInt b, TUInt &result) {
    result = a - b;
    return b <= a;
}

template<typename TUInt>
inline bool check_umul(TUInt a, TUInt b, TUInt &result) {
    result = a * b;
    return a == 0 || result/a == b;
}