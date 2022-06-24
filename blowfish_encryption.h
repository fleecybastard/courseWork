#ifndef BLOWFISH_ENCRYPTION_H
#define BLOWFISH_ENCRYPTION_H
#include <string>
std::string blowfishEncrypt(std::string plainText, std::string key);
std::string blowfishDecrypt(std::string encryptedText, std::string key);
std::string blowfishGenerateKey();
bool blowfishCheckKey(std::string key);
bool blowfishCheckText(std::string text);
#endif // BLOWFISH_ENCRYPTION_H
