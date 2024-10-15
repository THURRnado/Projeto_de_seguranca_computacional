#include "Headers.h"

#define DICTIONARY "D:\\Dev\\realhuman_phill_sem_diabo.txt"
#define LOOKUP_TABLE_SHA512 "D:\\Dev\\Lookup_table_SHA512.txt"
#define LOOKUP_TABLE_SHA256 "D:\\Dev\\Lookup_table_SHA256.txt"
#define LOOKUP_TABLE_SHA1 "D:\\Dev\\Lookup_table_SHA1.txt"
#define LOOKUP_TABLE_MD5 "D:\\Dev\\Lookup_table_MD5.txt"

void CarregaDicionario(std::vector<std::string>& dictionary) {
    std::string line;
    std::ifstream in_file;

    in_file.open(DICTIONARY);

    if (!in_file.is_open()) {
        std::cout << "Nao foi possivel abrir o arquivo do dicionario." << std::endl;
        exit(1);
    }

    while (!in_file.eof()) {
        std::getline(in_file, line);
        dictionary.push_back(line);
    }

    in_file.close();

}

void CarregaLookUpTables(std::map<std::string, std::string>& lookup_table_sha512, std::map<std::string, std::string>& lookup_table_sha256, std::map<std::string, std::string>& lookup_table_sha1, std::map<std::string, std::string>& lookup_table_md5) {
    std::string line;
    std::ifstream in_file;

    in_file.open(LOOKUP_TABLE_SHA512);

    if (!in_file.is_open()) {
        std::cout << "Nao foi possivel abrir o arquivo da lookup table sha-512." << std::endl;
        exit(1);
    }

    while (std::getline(in_file, line)) {
        std::string hash = line.substr(0, 128);
        std::string password = line.substr(129);
        lookup_table_sha512[hash] = password;
    }

    in_file.close();

    in_file.open(LOOKUP_TABLE_SHA256);

    if (!in_file.is_open()) {
        std::cout << "Nao foi possivel abrir o arquivo da lookup table sha-256." << std::endl;
        exit(1);
    }

    while (std::getline(in_file, line)) {
        std::string hash = line.substr(0, 64);
        std::string password = line.substr(65);
        lookup_table_sha256[hash] = password;
    }

    in_file.close();

    in_file.open(LOOKUP_TABLE_SHA1);

    if (!in_file.is_open()) {
        std::cout << "Nao foi possivel abrir o arquivo da lookup table sha-1." << std::endl;
        exit(1);
    }

    while (std::getline(in_file, line)) {
        std::string hash = line.substr(0, 40);
        std::string password = line.substr(41);
        lookup_table_sha1[hash] = password;
    }

    in_file.close();

    in_file.open(LOOKUP_TABLE_MD5);

    if (!in_file.is_open()) {
        std::cout << "Nao foi possivel abrir o arquivo da lookup table md5." << std::endl;
        exit(1);
    }

    while (std::getline(in_file, line)) {
        std::string hash = line.substr(0, 32);
        std::string password = line.substr(33);
        lookup_table_md5[hash] = password;
    }

    in_file.close();

}
