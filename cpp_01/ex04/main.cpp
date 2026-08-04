#include <iostream>
#include <fstream>

std::string replaceAll(std::string line, std::string s1, std::string s2){
    if (s1.empty())
        return line;
    size_t pos = 0;
    while ((pos = line.find(s1, pos)) != std::string::npos) {
        line.erase(pos, s1.length());
        line.insert(pos, s2);
        pos += s2.length();     
    }
    return line;
}

int main(int argc, char *argv[]){
    if(argc != 4){
        std::cout << "Wrong number of arguments!" << std::endl;
        return 1;
    }
    std::string fileName = argv[1];
    std::ifstream inFile(argv[1]);
    if(!inFile){
        std::cerr << "Error opening input file!" << std::endl;
        return 1;
    }
    std::ofstream newFile(fileName + ".replace");
    if(!newFile){
        std::cerr << "Error opening output file!" << std::endl;
        return 1;
    }
    std::string line;
    while(std::getline(inFile, line)){
        newFile << replaceAll(line, argv[2], argv[3]);
        if (!inFile.eof())
            std::cout << std::endl;
    }
    inFile.close();
    newFile.close();
    return 0;
}