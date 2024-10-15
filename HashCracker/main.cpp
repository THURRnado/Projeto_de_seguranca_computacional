#include <iostream>
#include "Headers.h"

#define DICIONARIO "C:/Users/carlo/Desktop/programação/C++/Projeto_de_seguranca_computacional/projeto_final_segurança/realhuman_phill.txt"
#define LOOKUPTABLE "Devlookup_table.txt"
std::atomic<bool> found(false);

void CarregaDicionario(std::vector<std::string>& dictionary,std::map<std::string,std::string>& lookup_table, std::string dictionary_path, std::string lookup_table_path) {
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

    in_file.open(lookup_table_path);

    if (!in_file.is_open()) {
        std::cout << "Nao foi possivel abrir o arquivo." << std::endl;
        exit(1);
    }
      while (std::getline(in_file, line)) {
        if (line.length() >= 129) {

            std::string hash = line.substr(0, 128);

            std::string password = line.substr(129);

            // Store them in the lookup table map
            lookup_table[hash] = password;

        }
    }
    in_file.close();
}


int main(int argc, char** argv) {
    int thread_count;
    bool haveSalt = false;
    char resposta;

    std::string titulo= "  _    _           _       _____       _   \n"
                        " | |  | |         | |     |  __ \\     | |  \n"
                        " | |__| | __ _ ___| |___  | |__) |__ _| |_ \n"
                        " |  __  |/ _  / __| '_  \\ |  _  // _  | __|\n"
                        " | |  | | (_| \\__ \\ | | | | | \\ \\ (_| | |_ \n"
                        " |_|  |_|\__,_|___/|_| |_| |_|  \\_\\__,_|\\__| (v4.1.3)©\n";

    std::string salt = " ";
    std::string hash, hash_type;
    std::vector<std::string> dictionary;
    std::map<std::string,std::string> lookup_table;

    std::cout << titulo << std::endl;

    std::cout << "Carregando dicionario... " << std::endl;
    CarregaDicionario(dictionary,lookup_table,DICIONARIO,LOOKUPTABLE);
    std::cout << "Dicionario carregado.\n " << std::endl;

    std::cout << "Insira o numero de threads: ";
    std::cin >> thread_count;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    system("CLS");
    std::cout << titulo << std::endl;
    while(true){

        std::cout << "\nTem salt?(s/n) \n>";
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
        if(hash_type.empty()){
            continue;
        }

        if (hash_type == "SHA-512") {
            try {
                std::string senha = lookup_table.at(hash);
                std::cout << "Senha encontrada: "<< senha << std::endl;
                std::cout <<"Tipo de hash: SHA-512" << std::endl;
                continue;
            } catch (const std::out_of_range& e) {
                std::cout << "\nHash nao encontrado na lookup table.\n" << std::endl;
            }
        }

        found.store(false);

        auto start = std::chrono::high_resolution_clock::now();

        CreateThreads(std::ref(dictionary), hash, salt, hash_type, thread_count, haveSalt);

        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> elapsed = end - start;

        std::cout << "Tempo total de excucao: " << elapsed.count() << " segundos" << std::endl;
    }

    return 0;
}
