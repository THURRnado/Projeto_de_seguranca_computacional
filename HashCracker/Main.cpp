#include <iostream>
#include "Headers.h"

#define TESTE "realhuman_phill.txt"

std::string DescobreHash(std::string s) {

    std::string hash_type;

    switch (s.length()) {
    
    case 32:
        hash_type = "MD5";
        break;

    case 40:
        hash_type = "SHA-1";
        break;

    case 64:
        hash_type = "SHA-256";
        break;

    default:
        hash_type = "ERROR";
        break;
    }

    return hash_type;
}

std::string md5(const std::string& str) {
    unsigned char hash[MD5_DIGEST_LENGTH];

    MD5_CTX md5;
    MD5_Init(&md5);
    MD5_Update(&md5, str.c_str(), str.size());
    MD5_Final(hash, &md5);

    std::stringstream ss;

    for (int i = 0; i < MD5_DIGEST_LENGTH; i++) {
        ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(hash[i]);
    }
    return ss.str();
}

std::string QuebraHash(std::string hash, std::string hash_type) {
    int x = 1;
    std::ifstream in_file;
    std::string password, hashed_password;
    in_file.open(TESTE);

    if (!in_file.is_open()) {
        std::cout << "Erro ao abrir o arquivo!" << std::endl;
        exit(1);
    }

    while (x<=100000) {
        in_file >> password;
        hashed_password = md5(password);
        std::cout << password << std::endl;
        x++;

        if (hashed_password.compare(hash) == 0) {
            break;
        }
    }

    return password;
}

int main(int argc, char** argv) {
    std::string hash, hash_type;

    std::cout << "Insira o hash: ";
    std::cin >> hash;

    hash_type = DescobreHash(hash);

    auto start = std::chrono::steady_clock::now();

    std::string resultado = QuebraHash(hash, hash_type);

    auto end = std::chrono::steady_clock::now();

    std::chrono::duration<double> elapsed = end - start;

    std::cout << "Tipo de hash: " << hash_type << std::endl;
    std::cout << "Senha encontrada: " << resultado << std::endl;
    std::cout << "Tempo para quebrar o hash: " << elapsed.count() << " segundos" << std::endl;

    return 0;
}