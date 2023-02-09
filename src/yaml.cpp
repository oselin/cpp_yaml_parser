#include "../include/yaml.h"


YamlReader::YamlReader(){
    // Not really needed
}

YamlReader::YamlReader(std::string filename){

    this->read(filename, "read");
}


YamlReader::~YamlReader(){
    yaml_file.close();
}

void YamlReader::read(std::string filename, std::string mode){

    // String switch not implemented in CPP
    if (mode == "read"){
        yaml_file.open(filename, std::ios::in);
    }
    else if (mode == "write"){
        yaml_file.open(filename, std::ios::out);
    }
    else if (mode == "append"){
        yaml_file.open(filename, std::ios::app);
    }
    else throw std::invalid_argument("Argument not recognized. Did you spell it correctly?");

    if (!yaml_file){
        // File not found nor read
        throw std::runtime_error("Could not open the yaml file");
    }

    std::string str((std::istreambuf_iterator<char>(yaml_file)),
                     std::istreambuf_iterator<char>());


    // Delimiter for YAML files
    std::string yaml_delimiter = ":";
    size_t pos = 0;
    
    std::istringstream f(str);
    std::string line;    

    while (std::getline(f, line)) {

        line = remove_char(' ', line);
        // Find delimiter in line
        pos = line.find(yaml_delimiter);

        // If the delimiter is found
        if ((pos != std::string::npos)){
            this->yaml.insert({line.substr(0,pos), line.substr(pos + yaml_delimiter.length())});
        }
    }

}


std::string YamlReader::get(std::string key){
    return this->yaml.find(key)->second;
}

std::string YamlReader::remove_char(char c, std::string fromstring){
    
    std::string bfr;
 
    // Traverse a string and if it is non space character then, place it at index non_space_count
    for (int i = 0; fromstring[i] != '\0'; i++)
        if (fromstring[i] != c)
        {
            bfr += fromstring[i];
        }    
    
    // Finally placing final character at the string end
    bfr += '\0';

    return bfr;
}