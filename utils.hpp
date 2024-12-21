#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include "os.hpp"

using hex = unsigned char;

std::vector<hex> read_file_as_hex(const std::string& path, size_t& file_size);
void write_file_from_string(const std::string& file_path, const std::string& str);
void write_file_from_hex(const std::string& file_path, const std::vector<hex>& data);
std::vector<hex> char_array_to_hex_vec(unsigned char contents[], unsigned int& file_size);
void zip_contents(const std::string& output_name);
void my_xxd(const std::string& filename);

