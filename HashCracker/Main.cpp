#include <iostream>
#include "Headers.h"

#define TESTE "realhuman_phill.txt"

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

    case 128:
        hash_type = "SHA-512";
        break;

    default:
        hash_type = "Insira um hash valido!";
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

std::string sha1(const std::string& str) {
    unsigned char hash[SHA_DIGEST_LENGTH];

    SHA_CTX sha1;
    SHA1_Init(&sha1);
    SHA1_Update(&sha1, str.c_str(), str.size());
    SHA1_Final(hash, &sha1);

    std::stringstream ss;

    for (int i = 0; i < SHA_DIGEST_LENGTH; i++) {
        ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(hash[i]);
    }
    return ss.str();
}

std::string sha256(const std::string& str) {
    unsigned char hash[SHA256_DIGEST_LENGTH];

    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, str.c_str(), str.size());
    SHA256_Final(hash, &sha256);

    std::stringstream ss;

    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(hash[i]);
    }
    return ss.str();
}

std::string sha512(const std::string& str) {
    unsigned char hash[SHA512_DIGEST_LENGTH];

    SHA512_CTX sha512;
    SHA512_Init(&sha512);
    SHA512_Update(&sha512, str.c_str(), str.size());
    SHA512_Final(hash, &sha512);

    std::stringstream ss;

    for (int i = 0; i < SHA512_DIGEST_LENGTH; i++) {
        ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(hash[i]);
    }
    return ss.str();
}

std::string QuebraHash(std::vector<std::string> dictionary, std::string hash, std::string hash_type) {
    std::string password, hashed_password;

    if (hash_type.compare("MD5") == 0) {
        for (int i = 0; i < dictionary.size(); ++i) {
            password = dictionary[i];
            hashed_password = md5(password);
            if (hashed_password.compare(hash) == 0) {
                break;
            }
        }

    }

    if (hash_type.compare("SHA-1") == 0) {
        for (int i = 0; i < dictionary.size(); ++i) {
            password = dictionary[i];
            hashed_password = sha1(password);
            if (hashed_password.compare(hash) == 0) {
                break;
            }
        }
    }

    if (hash_type.compare("SHA-256") == 0) {
        for (int i = 0; i < dictionary.size(); ++i) {
            password = dictionary[i];
            hashed_password = sha256(password);
            if (hashed_password.compare(hash) == 0) {
                break;
            }
        }
    }

    if (hash_type.compare("SHA-512") == 0) {
        for (int i = 0; i < dictionary.size(); ++i) {
            password = dictionary[i];
            hashed_password = sha512(password);
            if (hashed_password.compare(hash) == 0) {
                break;
            }
        }
    }

    return password;
}

int main(int argc, char** argv) {
    std::string hash, hash_type, dictionary_path = TESTE;
    std::vector<std::string> dictionary;

    std::cout << "Carregando dicionario... " << std::endl;
    CarregaDicionario(dictionary, dictionary_path);
    std::cout << "Dicionario carregado.\n " << std::endl;
    
    while(true){ 
        std::cout << "Insira o hash: ";
        std::getline(std::cin, hash);

        if (hash.empty()) {
            std::cout << "\nPrograma encerrado.\n" << std::endl;
            break;
        }

        hash_type = DescobreHash(hash);

        auto start = std::chrono::high_resolution_clock::now();

        std::string resultado = QuebraHash(dictionary, hash, hash_type);

        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> elapsed = end - start;

        std::cout << "Tipo de hash: " << hash_type << std::endl;
        std::cout << "Senha encontrada: " << resultado << std::endl;
        std::cout << "Tempo para quebrar o hash: " << elapsed.count() << " segundos" << std::endl;
    }

    return 0;
}
