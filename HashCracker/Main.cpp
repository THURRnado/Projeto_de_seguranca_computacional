#include <iostream>
#include "Headers.h"

#define TESTE "D:\\Dev\\realhuman_phill_sem_diabo.txt"

void CarregaDicionario(std::vector<std::string>& dictionary, std::string dictionary_path) {
    std::string line;
    std::ifstream in_file;

    in_file.open(dictionary_path);

    if (!in_file.is_open()) {
        std::cout << "Nao foi possivel abrir o arquivo." << std::endl;
        exit(1);
    }

    while (!in_file.eof()) {
        std::getline(in_file, line);
        dictionary.push_back(line);
    }
    
    in_file.close();

}

std::string QuebraHash(std::vector<std::string> dictionary, std::string hash, std::string hash_type) {
    std::string password, hashed_password;

    if (hash_type.compare("MD5") == 0) {
        for (int i = 0; i < dictionary.size(); ++i) {
            password = dictionary[i];
            hashed_password = md5(password);
            if (hashed_password.compare(hash) == 0) {
                std::cout << password << std::endl;
                break;
            }
        }
    }

    if (hash_type.compare("SHA-1") == 0) {
        for (int i = 0; i < dictionary.size(); ++i) {
            password = dictionary[i];
            hashed_password = sha1(password);
            if (hashed_password.compare(hash) == 0) {
                std::cout << password << std::endl;
                break;
            }
        }
    }

    if (hash_type.compare("SHA-256") == 0) {
        for (int i = 0; i < dictionary.size(); ++i) {
            password = dictionary[i];
            hashed_password = sha256(password);
            if (hashed_password.compare(hash) == 0) {
                std::cout << password << std::endl;
                break;
            }
        }
    }

    if (hash_type.compare("SHA-512") == 0) {
        for (int i = 0; i < dictionary.size(); ++i) {
            password = dictionary[i];
            hashed_password = sha512(password);
            if (hashed_password.compare(hash) == 0) {
                std::cout << password << std::endl;
                break;
            }
        }
    }

    return password;
}

int main(int argc, char** argv) {
    int thread_count;
    std::string hash, hash_type, dictionary_path = TESTE;
    std::vector<std::string> dictionary;

    std::cout << "Carregando dicionario... " << std::endl;
    CarregaDicionario(dictionary, dictionary_path);
    std::cout << "Dicionario carregado.\n " << std::endl;
    std::cout << "Insira o numero de threads: ";
    std::cin >> thread_count;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    while(true){ 
        std::cout << "Insira o hash: ";
        std::getline(std::cin, hash);

        if (hash.empty()) {
            std::cout << "\nPrograma encerrado.\n" << std::endl;
            break;
        }

        hash_type = DescobreHash(hash);

        auto start = std::chrono::high_resolution_clock::now();

        Tomie(std::ref(dictionary), hash, hash_type, thread_count);

        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> elapsed = end - start;

        std::cout << "Tipo de hash: " << hash_type << std::endl;
        std::cout << "Tempo para quebrar o hash: " << elapsed.count() << " segundos" << std::endl;
    }

    return 0;
}
