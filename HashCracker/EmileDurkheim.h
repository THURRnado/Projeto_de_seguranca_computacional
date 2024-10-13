#pragma once

#ifndef EMILEDURKHEIM
#define EMILEDURKHEIM

std::string QuebraHash(std::vector<std::string> dictionary, std::string hash, std::string hash_type);

std::string QuebraHashSalt(std::vector<std::string> dictionary, std::string hash, std::string salt, std::string hash_type);

#endif
