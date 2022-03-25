#include <iostream>
#include <fstream>

using namespace std;

const int PROBLEMS_PER_EXAM = 3;

struct Problem
{
    char* name;
    char* description;
    int points;

    void changeName(char* newName)
    {
        delete[] name;
        name = newName;
    }

    void changeDescription(char* newDescription)
    {
        delete[] description;
        description = newDescription;
    }

    void changePoints(int newPoints)
    {
        points = newPoints;
    }

    void readFromFile(ifstream& inFile)
    {
        int nameLength = 0;
        int descriptionLength = 0;

        inFile.read((char*)&nameLength, sizeof(nameLength));
        name = new char[nameLength + 1];
        inFile.read(name, nameLength);
        name[nameLength] = '\0';

        inFile.read((char*)&descriptionLength, sizeof(descriptionLength));
        description = new char[descriptionLength + 1];
        inFile.read(description, descriptionLength);
        description[descriptionLength] = '\0';

        inFile.read((char*)&points, sizeof(points));
    }
};

struct Exam
{
    Problem problems[PROBLEMS_PER_EXAM];
    int neededPoints;

    Exam(int neededPoints)
    {
        this->neededPoints = neededPoints;
    }

    void readFromFile(const char* filePath) {
        std::ifstream inFile(filePath, std::ios::binary);

        if (!inFile)
        {
            return;
        }

        for (int i = 0; i < PROBLEMS_PER_EXAM; i++)
        {
            problems[i].readFromFile(inFile);
        }
    }

    void changeMin(int newNeededPoints)
    {
        neededPoints = newNeededPoints;
    }

    int getMax()
    {
        int total = 0;

        for (size_t i = 0; i < PROBLEMS_PER_EXAM; i++)
        {
            total += problems[i].points;
        }

        return total;
    }

    void writeToFile(const char* filePath) const
    {
        ofstream outFile("Schedule.dat", ios::app | ios::binary);
        if (!outFile.is_open())
        {
            return;
        }

        char input[200];
        for (size_t j = 0; j < PROBLEMS_PER_EXAM; j++)
        {
            for (size_t i = 0; i < 2; i++)
            {
                cin.getline(input, 200);
                int len = strlen(input);
                outFile.write((char*)&len, sizeof(int));
                outFile.write((char*)&input, strlen(input));
            }

            int neededPoints;
            cin >> neededPoints;
            cin.ignore();
            outFile.write((char*)&neededPoints, sizeof(int));
        }
    }
};




int main()
{
    Exam exam(20);
    exam.readFromFile("Schedule.dat");

    cout << exam.getMax();
}
