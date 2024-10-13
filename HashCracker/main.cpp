#include <iostream>
#include "Headers.h"

#define TESTE "realhuman_phill.txt"
std::atomic<bool> found(false);
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


int main(int argc, char** argv) {
    int thread_count;
    bool haveSalt = false;
    char resposta;



    std::string salt = " ";
    std::string hash, hash_type, dictionary_path = TESTE;
    std::vector<std::string> dictionary;

    std::cout << "Carregando dicionario... " << std::endl;
    CarregaDicionario(dictionary, dictionary_path);
    std::cout << "Dicionario carregado.\n " << std::endl;

    std::cout << "Insira o numero de threads: ";
    std::cin >> thread_count;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    while(true){
        std::cout << "Tem salt?(s/n)" << std::endl;
        std::cin >> resposta;
        haveSalt = resposta == 's' ? true : false;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if(haveSalt){
            std::cout << "Insira o salt: " ;
            std::getline(std::cin, salt);
        }

        std::cout << "Insira o hash: ";

        std::getline(std::cin, hash);

        if (hash.compare("exit")==0) {
            std::cout << "\nPrograma encerrado.\n" << std::endl;
            break;
        }


        hash_type = DescobreHash(hash);

        auto start = std::chrono::high_resolution_clock::now();

        found.store(false);

        Tomie(std::ref(dictionary), hash, salt, hash_type, thread_count, haveSalt);

        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> elapsed = end - start;

        std::cout << "Tipo de hash: " << hash_type << std::endl;
        std::cout << "Tempo para quebrar o hash: " << elapsed.count() << " segundos" << std::endl;
    }

    return 0;
}
