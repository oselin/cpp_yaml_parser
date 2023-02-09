#include "include/yaml.h"
#include <iostream>

int main(){

    YamlReader myreader;
    myreader.read("file.yaml","read");

    std::cout << myreader.get("param1")<< std::endl;
    std::cout << myreader.get("param2")<< std::endl;
    std::cout << myreader.get("param3")<< std::endl;
    
    return 0;
}
