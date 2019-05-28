#pragma once


template<int N, bool positive>
class fibonacciHelper{
public:
    static const int value=0;
};

template <int T>
class fibonacci{
public:
    static const int value =fibonacciHelper<T,(T<0)?false: true>::value;
};

template<int N>
class fibonacciHelper<N,true>{
public:
    static const int value = fibonacci<N-1>::value + fibonacci<N-2>::value;
};

template<int N>
class fibonacciHelper<N,false>{
public:
    static const int value = - fibonacci<N+1>::value + fibonacci<N+2>::value;
};

template<>
class fibonacci<0>{
public:
    static const int value=0;
};

template<>
class fibonacci<1>{
public:
    static const int value=1;
};