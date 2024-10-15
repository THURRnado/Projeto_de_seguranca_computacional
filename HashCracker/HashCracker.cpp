#include "Headers.h"

void QuebraHash(std::vector<std::string> dictionary, std::string hash, std::string hash_type) {
    std::string password, hashed_password;

    auto start = std::chrono::high_resolution_clock::now();

    if (hash_type.compare("MD5") == 0) {
        for (int i = 0; i < dictionary.size(); ++i) {
            if (found)
                return;
            password = dictionary[i];
            hashed_password = md5(password);
            if (hashed_password.compare(hash) == 0) {
                auto end = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double> elapsed = end - start;
                std::cout << "Senha encontrada: " << password << std::endl;
                std::cout << "Tipo de hash: " << hash_type << std::endl;
                std::cout << "Tempo para quebrar o hash: " << elapsed.count() << " segundos" << std::endl;
                found.exchange(true);
                return;
            }
        }
    }

    if (hash_type.compare("SHA-1") == 0) {
        for (int i = 0; i < dictionary.size(); ++i) {
            if (found)
                return;
            password = dictionary[i];
            hashed_password = sha1(password);
            if (hashed_password.compare(hash) == 0) {
                auto end = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double> elapsed = end - start;
                std::cout << "Senha encontrada: " << password << std::endl;
                std::cout << "Tipo de hash: " << hash_type << std::endl;
                std::cout << "Tempo para quebrar o hash: " << elapsed.count() << " segundos" << std::endl;
                found.exchange(true);
                return;
            }
        }
    }

    if (hash_type.compare("SHA-256") == 0) {
        for (int i = 0; i < dictionary.size(); ++i) {
            if (found)
                return;
            password = dictionary[i];
            hashed_password = sha256(password);
            if (hashed_password.compare(hash) == 0) {

                auto end = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double> elapsed = end - start;
                std::cout << "Senha encontrada: " << password << std::endl;
                std::cout << "Tipo de hash: " << hash_type << std::endl;
                std::cout << "Tempo para quebrar o hash: " << elapsed.count() << " segundos" << std::endl;
                found.exchange(true);
                return;
            }
        }
    }

    if (hash_type.compare("SHA-512") == 0) {
        for (int i = 0; i < dictionary.size(); ++i) {
            if (found)
                return;
            password = dictionary[i];
            hashed_password = sha512(password);
            if (hashed_password.compare(hash) == 0) {
                auto end = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double> elapsed = end - start;
                std::cout << "Senha encontrada: " << password << std::endl;
                std::cout << "Tipo de hash: " << hash_type << std::endl;
                std::cout << "Tempo para quebrar o hash: " << elapsed.count() << " segundos" << std::endl;
                found.exchange(true);
                return;
            }
        }
    }
    return;
}

void QuebraHashSalt(std::vector<std::string> dictionary, std::string hash, std::string salt, std::string hash_type) {

    std::string password, hashed_password;
    auto start = std::chrono::high_resolution_clock::now();
    if (hash_type.compare("MD5") == 0) {
        for (int i = 0; i < dictionary.size(); ++i) {
            if (found)
                return;
            password = dictionary[i] + salt;
            hashed_password = md5(password);
            if (hashed_password.compare(hash) == 0) {
                password = password.substr(0, password.length() - salt.length());
                auto end = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double> elapsed = end - start;
                std::cout << "Senha encontrada: " << password << std::endl;
                std::cout << "Tipo de hash: " << hash_type << std::endl;
                std::cout << "Tempo para quebrar o hash: " << elapsed.count() << " segundos" << std::endl;
                found.exchange(true);
                return;
            }
        }
    }

    if (hash_type.compare("SHA-1") == 0) {
        for (int i = 0; i < dictionary.size(); ++i) {
            if (found)
                return;
            password = dictionary[i] + salt;
            hashed_password = sha1(password);
            if (hashed_password.compare(hash) == 0) {
                auto end = std::chrono::high_resolution_clock::now();
                password = password.substr(0, password.length() - salt.length());
                std::chrono::duration<double> elapsed = end - start;
                std::cout << "Senha encontrada: " << password << std::endl;
                std::cout << "Tipo de hash: " << hash_type << std::endl;
                std::cout << "Tempo para quebrar o hash: " << elapsed.count() << " segundos" << std::endl;
                found.exchange(true);
                return;
            }
        }
    }

    if (hash_type.compare("SHA-256") == 0) {
        for (int i = 0; i < dictionary.size(); ++i) {
            if (found)
                return;
            password = dictionary[i] + salt;
            hashed_password = sha256(password);
            if (hashed_password.compare(hash) == 0) {
                auto end = std::chrono::high_resolution_clock::now();
                password = password.substr(0, password.length() - salt.length());
                std::chrono::duration<double> elapsed = end - start;
                std::cout << "Senha encontrada: " << password << std::endl;
                std::cout << "Tipo de hash: " << hash_type << std::endl;
                std::cout << "Tempo para quebrar o hash: " << elapsed.count() << " segundos" << std::endl;
                found.exchange(true);
                return;
            }
        }
    }

    if (hash_type.compare("SHA-512") == 0) {
        for (int i = 0; i < dictionary.size(); ++i) {
            if (found)
                return;
            password = dictionary[i] + salt;
            hashed_password = sha512(password);
            if (hashed_password.compare(hash) == 0) {
                auto end = std::chrono::high_resolution_clock::now();
                password = password.substr(0, password.length() - salt.length());
                std::chrono::duration<double> elapsed = end - start;
                std::cout << "Senha encontrada: " << password << std::endl;
                std::cout << "Tipo de hash: " << hash_type << std::endl;
                std::cout << "Tempo para quebrar o hash: " << elapsed.count() << " segundos" << std::endl;
                found.exchange(true);
                return;
            }
        }
    }

    return;
}