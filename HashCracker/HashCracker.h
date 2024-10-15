#pragma once

#ifndef HASHCRACKER
#define HASHCRACKER
#include <chrono>

void QuebraHash(std::vector<std::string> dictionary, std::string hash, std::string hash_type);

void QuebraHashSalt(std::vector<std::string> dictionary, std::string hash, std::string salt, std::string hash_type);

#endif
