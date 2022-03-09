#include <iostream>
#include <fstream>

struct jobOffer
{
    //подравняване
    char company[25];
    int teamCount;
    int vacationDays;
    long long salary;
};

bool saveJobOffers(int n) 
{
    std::ofstream outFile("jobOffers.dat", std::ios::app | std::ios::binary);
    if (!outFile.is_open())
    {
        return false;
    }

    for (size_t i = 0; i < n; i++)
    {
        char company[25];
        int teamCount, vacationDays;
        long long salary;

        std::cin.getline(company, 25);
        size_t companyLen = std::strlen(company) + 1;
        std::cin >> teamCount >> vacationDays >> salary;

        outFile.write((const char*)&companyLen, sizeof(companyLen));
        outFile.write(company, companyLen);
        outFile.write((const char*)&teamCount, sizeof(teamCount));
        outFile.write((const char*)&vacationDays, sizeof(vacationDays));
        outFile.write((const char*)&salary, sizeof(salary));
    }

    return true;
}

void printOffer(const jobOffer& jobOffer)
{
    std::cout << jobOffer.company << " " << jobOffer.teamCount << " " << jobOffer.vacationDays << " " << jobOffer.salary << std::endl;
}

bool perfectOffer(const char* filePath, int teamCount, int vacationDays, int minSalary) 
{
    std::ifstream inFile(filePath, std::ios::binary);
    if (!inFile.is_open())
    {
        return false;
    }

    while (true)
    {
        size_t companyLen;
        inFile.read((char*)&companyLen, sizeof(companyLen));

        if (inFile.eof())
        {
            break;
        }

        jobOffer jobOffer;
        inFile.read(jobOffer.company, companyLen);
        inFile.read((char*)&jobOffer.teamCount, sizeof(int));
        inFile.read((char*)&jobOffer.vacationDays, sizeof(int));
        inFile.read((char*)&jobOffer.salary, sizeof(long long));

        if (jobOffer.vacationDays == vacationDays && jobOffer.teamCount == teamCount && jobOffer.salary >= minSalary)
        {
            printOffer(jobOffer);
        }
    }

    inFile.close();


    return true;
}

bool filterOffers(const char* filePath, long long minSalary)
{
    std::ifstream inFile(filePath, std::ios::binary);
    if (!inFile.is_open())
    {
        return false;
    }

    while (true)
    {
        size_t companyLen;
        inFile.read((char*)&companyLen, sizeof(companyLen));

        if (inFile.eof())
        {
            break;
        }

        jobOffer jobOffer;
        inFile.read(jobOffer.company, companyLen);
        inFile.read((char*)&jobOffer.teamCount, sizeof(int));
        inFile.read((char*)&jobOffer.vacationDays, sizeof(int));
        inFile.read((char*)&jobOffer.salary, sizeof(long long));

        if (jobOffer.salary >= minSalary)
        {
            printOffer(jobOffer);
        }
    }

    inFile.close();


    return true;
}

int main()
{
    saveJobOffers(1);
    perfectOffer("jobOffers.dat", 1000, 1000, 1000);

    return 0;
}