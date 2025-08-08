#ifndef _UTILITIES_H_
#define _UTILITIES_H_

#include <iostream>
#include <string>
#include <vector>
#include <nlohmann/json.hpp>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <ctime>
#include <openssl/sha.h>
#include <openssl/evp.h>
#include <openssl/rand.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <stdexcept>

std::chrono::year_month_day convertDate(std::string dateStr);
std::string convertDateToString(std::chrono::year_month_day chronoDate);
void printChronoDate(std::chrono::year_month_day chronoDate);
std::string generateHash(const std::string &input);
bool generateEncryptedRsaPrivateKey(const std::string &filename, const std::string &passphrase);

#endif