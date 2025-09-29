#pragma once

#include<iostream>
#include<string>
#include<vector>


#define ASCENDING 1
#define DESCENDING 0

using String = std::string;
template<class T>
using Vec = std::vector<T>;

using uint = unsigned int;
using uchar = unsigned char;


// callbacks defined
template<typename T>
using CompareCallback = bool (*)(T&, T&);