#include "Headers.h"

std::atomic<bool> found(false);

int main(int argc, char** argv) {
    int thread_count;
    bool haveSalt = false;
    char resposta;

    std::string titulo = "  _    _           _       _____       _   \n"
        " | |  | |         | |     |  __ \\     | |  \n"
        " | |__| | __ _ ___| |___  | |__) |__ _| |_ \n"
        " |  __  |/ _  / __| '_  \\ |  _  // _  | __|\n"
        " | |  | | (_| \\__ \\ | | | | | \\ \\ (_| | |_ \n"
        " |_|  |_|\__,_|___/|_| |_| |_|  \\_\\__,_|\\__| (v4.1.3)©\n";

    std::string salt = " ";
    std::string hash, hash_type;
    std::vector<std::string> dictionary;
    std::map<std::string, std::string> lookup_table_sha512, lookup_table_sha256, lookup_table_sha1, lookup_table_md5;

    std::cout << titulo << std::endl;

    std::cout << "Carregando dicionario... " << std::endl;
    CarregaDicionario(dictionary);
    std::cout << "Dicionario carregado.\n " << std::endl;

    std::cout << "Carregando lookup tables... " << std::endl;
    CarregaLookUpTables(lookup_table_sha512, lookup_table_sha256, lookup_table_sha1, lookup_table_md5);
    std::cout << "Lookup tables carregadas.\n " << std::endl;

    std::cout << "Insira o numero de threads: ";
    std::cin >> thread_count;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    system("CLS");
    std::cout << titulo << std::endl;
    while (true) {
        std::cout << "\nTem salt?(s/n) \n> ";
        std::cin >> resposta;
        haveSalt = resposta == 's' ? true : false;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (haveSalt) {
            std::cout << "Insira o salt: ";
            std::getline(std::cin, salt);
        }

        std::cout << "Insira o hash: ";

        std::getline(std::cin, hash);

        if (hash.compare("exit") == 0) {
            std::cout << "\nPrograma encerrado.\n" << std::endl;
            break;
        }


        hash_type = DescobreHash(hash);
        if (hash_type.empty()) {
            continue;
        }

        if (hash_type == "SHA-512") {
            try {
                std::string senha = lookup_table_sha512.at(hash);
                std::cout << "\nSenha encontrada: " << senha << std::endl;
                std::cout << "Tipo de hash: SHA-512" << std::endl;
                continue;
            }
            catch (const std::out_of_range& e) {
                std::cout << "\nHash nao encontrado na lookup table.\n" << std::endl;
            }
        }

        if (hash_type == "SHA-256") {
            try {
                std::string senha = lookup_table_sha256.at(hash);
                std::cout << "\nSenha encontrada: " << senha << std::endl;
                std::cout << "Tipo de hash: SHA-256" << std::endl;
                continue;
            }
            catch (const std::out_of_range& e) {
                std::cout << "\nHash nao encontrado na lookup table.\n" << std::endl;
            }
        }

        if (hash_type == "SHA-1") {
            try {
                std::string senha = lookup_table_sha1.at(hash);
                std::cout << "\nSenha encontrada: " << senha << std::endl;
                std::cout << "Tipo de hash: SHA-1" << std::endl;
                continue;
            }
            catch (const std::out_of_range& e) {
                std::cout << "\nHash nao encontrado na lookup table.\n" << std::endl;
            }
        }

        if (hash_type == "MD5") {
            try {
                std::string senha = lookup_table_md5.at(hash);
                std::cout << "\nSenha encontrada: " << senha << std::endl;
                std::cout << "Tipo de hash: MD5" << std::endl;
                continue;
            }
            catch (const std::out_of_range& e) {
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