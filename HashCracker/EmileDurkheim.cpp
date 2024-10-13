#include "Headers.h"

std::string QuebraHash(std::vector<std::string> dictionary, std::string hash, std::string hash_type) {
    std::string password, hashed_password;

    if (hash_type.compare("MD5") == 0) {
        for (int i = 0; i < dictionary.size(); ++i) {
            if (found)
                return password;
            password = dictionary[i];
            hashed_password = md5(password);
            if (hashed_password.compare(hash) == 0) {
                std::cout << password << std::endl;
                found.exchange(true);
                break;
            }
        }
    }

    if (hash_type.compare("SHA-1") == 0) {
        for (int i = 0; i < dictionary.size(); ++i) {
            if (found)
               return password;
            password = dictionary[i];
            hashed_password = sha1(password);
            if (hashed_password.compare(hash) == 0) {
                std::cout << password << std::endl;
                found.exchange(true);
                break;
            }
        }
    }

    if (hash_type.compare("SHA-256") == 0) {
        for (int i = 0; i < dictionary.size(); ++i) {
            if (found)
                return password;
            password = dictionary[i];
            hashed_password = sha256(password);
            if (hashed_password.compare(hash) == 0) {
                std::cout << password << std::endl;
                found.exchange(true);
                break;
            }
        }
    }

    if (hash_type.compare("SHA-512") == 0) {
        for (int i = 0; i < dictionary.size(); ++i) {
            if (found)
                return password;
            password = dictionary[i];
            hashed_password = sha512(password);
            if (hashed_password.compare(hash) == 0) {
                std::cout << password << std::endl;
                found.exchange(true);
                break;
            }
        }
    }
    return password;
}

std::string QuebraHashSalt(std::vector<std::string> dictionary, std::string hash, std::string salt, std::string hash_type){

    std::string password, hashed_password;

    if (hash_type.compare("MD5") == 0) {
        for (int i = 0; i < dictionary.size(); ++i) {
            if (found)
                break;
            password = dictionary[i] + salt;
            hashed_password = md5(password);
            if (hashed_password.compare(hash) == 0) {
                password = password.substr(0,password.length() - salt.length());
                std::cout << password << std::endl;
                found.exchange(true);
                break;
            }
        }
    }

    if (hash_type.compare("SHA-1") == 0) {
        for (int i = 0; i < dictionary.size(); ++i) {
            if (found)
                break;
            password = dictionary[i] + salt;
            hashed_password = sha1(password);
            if (hashed_password.compare(hash) == 0) {
                password = password.substr(0,password.length() - salt.length());
                std::cout << password << std::endl;
                found.exchange(true);
                break;
            }
        }
    }

    if (hash_type.compare("SHA-256") == 0) {
        for (int i = 0; i < dictionary.size(); ++i) {
            if (found)
                break;
            password = dictionary[i] + salt;
            hashed_password = sha256(password);
            if (hashed_password.compare(hash) == 0) {
                password = password.substr(0,password.length() - salt.length());
                std::cout << password << std::endl;
                found.exchange(true);
                break;
            }
        }
    }

    if (hash_type.compare("SHA-512") == 0) {
        for (int i = 0; i < dictionary.size(); ++i) {
            if (found)
                break;
            password = dictionary[i] + salt;
            hashed_password = sha512(password);
            if (hashed_password.compare(hash) == 0) {
                password = password.substr(0,password.length() - salt.length());
                std::cout << password << std::endl;
                found.exchange(true);
                break;
            }
        }
    }

    return password;
}
