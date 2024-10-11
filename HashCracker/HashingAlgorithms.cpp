#include "Headers.h"

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