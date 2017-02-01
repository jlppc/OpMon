#include "File.hpp"

File::File(string path){
    this->path = path;
}

ifstream* File::getIn() const{
    return &ifstream(string(path));
}

ofstream* File::getOut() const{
    return &ofstream(string(path));
}
