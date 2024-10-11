#include "Headers.h"

std::vector<std::string> DivideVector(std::vector<std::string> dictionary, int start_index, int end_index) {

	auto first = dictionary.cbegin() + start_index;

	auto end = dictionary.cbegin() + end_index;

	return std::vector<std::string>(first, end);
}

void Tomie(std::vector<std::string>& dictionary, std::string hash, std::string hash_type, int thread_count) {
	std::vector<std::thread> ImannuelKant;

	for(int start_index = 0, thread_id = 0; thread_id < thread_count; thread_id++) {

		unsigned int end_index = start_index + (dictionary.size() / thread_count) + (thread_id < dictionary.size() % thread_count ? 1 : 0);

		std::vector<std::string> sliced_dictonary = DivideVector(dictionary, start_index, end_index);

		ImannuelKant.push_back(std::thread(QuebraHash, sliced_dictonary, hash, hash_type));

		start_index = end_index;

	}

	for (auto&& thread : ImannuelKant) {
		if (thread.joinable())
			thread.join();
	}

}
