#include "utils.hpp"
#include "os.hpp"

void my_xxd(const std::string& filename)
{
    size_t size = 0;
    std::vector<hex> contents = read_file_as_hex(filename, size);
    std::string text = "";
    for (size_t i = 0; i < size; i++) text += contents[i];
    std::string base = filename.substr(0, filename.find_last_of("."));
#if OS_UNIX_LIKE_DEFINED
    std::string cmd = "./my_xxd -i " + filename;  
#else
    std::string cmd = "Tool not yet implemented for Windows.";
#endif
    std::pair<int, std::string> res = OS::run_command(cmd);
    write_file_from_string(base + ".h", res.second);
}

void zip_contents(const std::string& output_name)
{
#if OS_UNIX_LIKE_DEFINED
	std::string cmd = "./my_zip -r " + output_name + " .";
#else 
    std::string cmd = "Tool not yet implemented for Windows.";
#endif
	OS::run_command(cmd);
}

std::vector<hex> char_array_to_hex_vec(unsigned char contents[], unsigned int& file_size)
{
    std::vector<hex> result;
    for (unsigned int i = 0; i < file_size; i++) {
        result.emplace_back(contents[i]);
    }
    return result;
}

std::vector<hex> read_file_as_hex(const std::string& file_path, size_t& file_size)
{
    std::ifstream file(file_path, std::ios::binary);
    if (!file) {
        std::cerr << "Error opening file: " << file_path << std::endl;
        exit(EXIT_FAILURE);
    }
    file.seekg(0, std::ios::end);
    file_size = file.tellg();
    file.seekg(0, std::ios::beg);
    std::vector<hex> buffer(file_size);
    file.read(reinterpret_cast<char*>(buffer.data()), file_size);
    return buffer;
}

void write_file_from_string(const std::string& file_path, const std::string& str)
{
    std::ofstream file(file_path);
    if (!file) {
        std::cerr << "Error opening file for writing: " << file_path << std::endl;
        exit(EXIT_FAILURE);
    }
    file.write(str.c_str(), str.size());
}

void write_file_from_hex(const std::string& file_path, const std::vector<hex>& data)
{
    std::ofstream file(file_path, std::ios::binary);
    if (!file) {
        std::cerr << "Error opening file for writing: " << file_path << std::endl;
        exit(EXIT_FAILURE);
    }
    file.write(reinterpret_cast<const char*>(data.data()), data.size());
}