#include <iostream>
#include <fstream>

int check_error(std::ofstream &outfile, std::string string1, std::string string2)
{
    if (!outfile.is_open())
    {
        std::cout << "file didn't open properly" << std::endl;
        return 1;
    }
    if (string1.length() == 0 || string2.length() == 0)
    {
        std::cout << "no string" << std::endl;
        return 1;
    }
    return 0;
}

void    ft_replace(std::string &line, std::string string1, std::string string2)
{
    size_t pos = 0;

    pos = line.find(string1, pos);
    while (pos != std::string::npos)
    {
        line.erase(pos, string1.length());
        line.insert(pos, string2);
        pos += string2.length();
        pos = line.find(string1, pos);
    }
}

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "argc error" << std::endl;
        return 1;
    }

    std::ifstream infile(argv[1]);
    if (!infile.is_open())
    {
        std::cout << "file didn't open properly" << std::endl;
        return 1;
    }
    std::string newFilename = std::string(argv[1]) + ".replace";
    std::ofstream outfile(newFilename.c_str());
    std::string string1;
    std::string string2;
    std::string line;

    string1 = argv[2];
    string2 = argv[3];

    if (check_error(outfile, string1, string2))
        return 1;
    
    while (!infile.eof())
    {
        std::getline(infile, line);
        ft_replace(line, string1, string2);
        outfile << line;
        if (!infile.eof())
            outfile << std::endl;
    }
}