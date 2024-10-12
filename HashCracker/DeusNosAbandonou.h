#pragma once

#ifndef DEUSNOSABANDONOU
#define DEUSNOSABANDONOU

static std::atomic<bool> found(false);

std::vector<std::string> DivideVector(std::vector<std::string> dictionary, int start_index, int end_index);

void Tomie(std::vector<std::string>& sliced_dictionary, std::string hash, std::string hash_type, int thread_count);

std::string QuebraHash(std::vector<std::string> dictionary, std::string hash, std::string hash_type);

#endif
