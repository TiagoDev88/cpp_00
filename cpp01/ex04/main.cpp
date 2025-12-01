
#include <fstream>
#include <iostream>
#include <string>

void replaceString(std::ifstream& file, std::ofstream& outfile, const std::string& s1, const std::string& s2)
{
    std::string read;
    while (getline(file, read))
    {
        std::size_t pos = 0;
        while ((pos = read.find(s1, pos)) != std::string::npos)
        {
            read.erase(pos, s1.length());
            read.insert(pos, s2);
            pos += s2.length();
        }
        outfile << read << '\n';
    }
}

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cerr << "./SedIsForLosers <filename> string1 string2" << std::endl;
        return -1;
    }
    std::string infile = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    if (s1.empty())
    {
        std::cerr << "Error: s1 is empty" << std::endl;
        return -1;
    }
    
    std::string newFile = infile + ".replace";
    
    std::ifstream file(infile.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: Cannot open file " << infile << std::endl;
        return -1;
    }

    std::ofstream outfile(newFile.c_str());
    if (!outfile.is_open())
    {
        std::cerr << "Error: With output file " << newFile << std::endl;
        return -1;
    }
    replaceString(file, outfile, s1, s2);
    return 0;
}