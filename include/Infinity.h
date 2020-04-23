#pragma once
template<typename T> constexpr T inf;
template<> constexpr short int inf<short int> = 32767;
template<> constexpr unsigned short int inf<unsigned short int> = 65535;
template<> constexpr int inf<int> = 2147483647;
template<> constexpr long long int inf<long long int> = 9223372036854775807;
template<> constexpr unsigned long long int inf<unsigned long long int> = 18446744073709551615;
