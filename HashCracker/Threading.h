#pragma once

#ifndef THREADING
#define THREADING

std::vector<std::string> DivideVector(std::vector<std::string> dictionary, int start_index, int end_index);

void CreateThreads(std::vector<std::string>& sliced_dictionary, std::string hash, std::string salt, std::string hash_type, int thread_count, bool haveSalt);

#endif