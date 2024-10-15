
#pragma once

#ifndef HASHINGALGORITHMS
#define HASHINGALGORITHMS

std::string DescobreHash(std::string s);

std::string md5(const std::string& str);

std::string sha1(const std::string& str);

std::string sha256(const std::string& str);

std::string sha512(const std::string& str);

#endif
