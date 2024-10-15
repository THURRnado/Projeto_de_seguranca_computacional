#include "Headers.h"

std::vector<std::string> DivideVector(std::vector<std::string> dictionary, int start_index, int end_index) {

    auto first = dictionary.cbegin() + start_index;
    auto end = dictionary.cbegin() + end_index;

    return std::vector<std::string>(first, end);
}

void CreateThreads(std::vector<std::string>& dictionary, std::string hash, std::string salt, std::string hash_type, int thread_count, bool haveSalt) {

    ThreadPool pool(thread_count);

    for(int start_index = 0, thread_id = 0; thread_id < thread_count; thread_id++) {

        unsigned int end_index = start_index + (dictionary.size() / thread_count) + (thread_id < dictionary.size() % thread_count ? 1 : 0);

        std::vector<std::string> sliced_dictonary = DivideVector(dictionary, start_index, end_index);

        if(!haveSalt){
        pool.enqueue([=] {

            QuebraHash(sliced_dictonary, hash,hash_type);

            });
        }else{
            pool.enqueue([=] {

            QuebraHashSalt(sliced_dictonary, hash, salt, hash_type);
            });
        }
        start_index = end_index;

    }

}
