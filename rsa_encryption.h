#ifndef RSA_ENCRYPTION_H
#define RSA_ENCRYPTION_H
#include <string>
std::string encrypt(std::string text, long long e, long long n);
std::string decrypt(std::string text, long long d, long long n);
long long* generateValues();
bool checkValues(long long EorD, long long n);
bool checkText(std::string text);
#endif // RSA_ENCRYPTION_H
