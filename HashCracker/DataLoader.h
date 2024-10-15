#pragma once

#ifndef DATALOADER
#define DATALOADER

void CarregaDicionario(std::vector<std::string>& dictionary);

void CarregaLookUpTables(std::map<std::string, std::string>& lookup_table_SHA512, std::map<std::string, std::string>& lookup_table_SHA256, std::map<std::string, std::string>& lookup_table_SHA1, std::map<std::string, std::string>& lookup_table_MD5);

#endif