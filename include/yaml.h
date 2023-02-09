#ifndef YAML_H
#define YAML_H

#include <fstream>
#include <sstream>
#include <map>

class YamlReader{

    private:
        std::fstream yaml_file;
        std::map<std::string, std::string> yaml;

    public:
        YamlReader();
        ~YamlReader();

    void read(std::string filename, std::string mode="read");

    std::string remove_char(char c, std::string fromstring);

    std::string get(std::string key);
};

#endif //YAML_H