#include <iostream>
#include <fstream>

bool duplicate(const char* filePath, const char* newFile, int n) 
{
    std::fstream inFile(filePath);
    if (!inFile.is_open())
    {
        return false;
    }

    std::ofstream outFile(newFile);
    if (!outFile.is_open())
    {
        return false;
    }
    for (size_t i = 0; i < n; i++)
    {
        char c;
        while (true)
        {
            inFile.get(c);
            if (inFile.eof())
            {
                break;
            }
            outFile << c;
        }

        inFile.clear();
        inFile.seekg(0);
    }

    return true;
}

int main()
{
    duplicate("input.txt", "result.txt", 3);
}