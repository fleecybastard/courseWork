#include <iostream>
#include <string>
#include <ctime>
#include <cmath>
#include <vector>
#include "rsa_encryption.h"
using namespace std;

string delimiter = " ";
// public functions
string encrypt(string text, long long e, long long n);
string decrypt(string text, long long d, long long n);
long long* generateValues();
bool checkValues(long long EorD, long long n);
bool checkText(string text);


// private functions
int hexToCode(char ch);
char codeToHex(int cd);
long long generatePrimeLong();
bool isPrime(long long number);
long long calculateN(long long p, long long q);
long long calculatePhi(long long p, long long q);
long long gcd(long long a, long long b);
bool checkE(long long phi);
long long calculateE(long long phi);
long long calculateD(long long phi, long long e);
vector<long long> stringToVector(string text);

bool isPrime(long long number)
{
    for(int i = 2; i <= sqrt(number); i++)
    {
        if(number % i == 0) return false;
    }
    return true;
}

long long calculateN(long long p, long long q)
{
    return p*q;
}

long long calculatePhi(long long p, long long q)
{
    return (p-1)*(q-1);
}

long long gcd(long long a, long long b)
{
    long long temp;
    while(b != 0)
    {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

bool checkE(long long phi)
{
    long long e;
    long long i = 2;
    while (gcd(i, phi) != 1) i++;
    e = i;
    if(e >= phi) return false;
    return true;

}

long long calculateE(long long phi)
{
    long long e;
    long long i = 2;
    while (gcd(i, phi) != 1) i++;
    e = i;
    if(e >= phi) return 0;
    return e;
}

long long calculateD(long long phi, long long e)
{
    long long k = 1;
    while ((k*phi+1)%e != 0) k++;
    return (k*phi+1)/e;
}

string encrypt(string text, long long e, long long n)
{
    string cipher = "";
    for(int i = 0; i < text.size(); i++)
    {
        char ch = text[i];
        long long k = 1;
        for(long long j = 0; j < e; j++)
        {
            k *= ch;
            k %= n;
        }

        cipher += to_string(k);
        if(i != text.size() -1) cipher += delimiter;
    }
    return cipher;
}

string decrypt(string text, long long d, long long n)
{
    string decryptedText = "";
    vector<long long> encryptedNums = stringToVector(text);
    for(int i = 0; i < encryptedNums.size(); i++)
    {
        long long ch = encryptedNums[i];
        long long k = 1;
        for(long long j = 0; j < d; j++)
        {
            k *= ch;
            k %= n;
        }

        ch = k;
        decryptedText += (char)ch;
    }
    return decryptedText;
}

long long* generateValues()
{
    // e, d, N
    srand(time(NULL));
    long long primeNumbers[] = {11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103};
    long long* values = new long long[3];
    long long p = 1, q = 1;
    while (p == q)
    {
        p = primeNumbers[rand()%(sizeof(primeNumbers)/sizeof(primeNumbers[0]))];
        q = primeNumbers[rand()%(sizeof(primeNumbers)/sizeof(primeNumbers[0]))];
    }
    long long N = calculateN(p, q);
    long long phi = calculatePhi(p, q);
    long long e = calculateE(phi);
    long long d = calculateD(phi, e);
    values[0] = e;
    values[1] = d;
    values[2] = N;
    return values;
}

bool checkValues(long long EorD, long long n)
{
    if (EorD <= 0 || n <= 0) return false;
    return true;
}

bool checkText(string text)
{
    if(text.empty()) return false;
    return true;
}

vector<long long> stringToVector(string text)
{
    vector<long long> numbers;
    int position = 0;
    while((position = text.find(delimiter)) != string::npos)
    {
        numbers.push_back(stoll(text.substr(0, position)));
        text.erase(0, position + delimiter.size());
    }
    numbers.push_back(stoll(text));
    return numbers;
}
