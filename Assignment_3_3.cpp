// Zachary McLaughlin
// 18 February 2022
// Assignment 3 Part 3
// Attempting to provide an answer to the ultimate question of Alabama using vectors
// *Updated to sort the team records by year and print the win-loss records*

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

const string DATAFILE = "football.txt";
int bamaW, bamaL, bamaTotal, bamaPercent, aubW, aubL, aubTotal, aubPercent;
int count = 0;

struct titleRow
{
    string school;
    string year;
    string schoolW;
    string schoolL;
    string schoolT;
};

struct dataRows
{
    string school;
    int year;
    int win;
    int loss;
    int tie;
};

vector <titleRow> titleReadings;
vector <dataRows> dataReadings;

bool readData(bool &var);
void sortData();
void outputYearWL();
void bamaCalc();
void aubCalc();
void outputResults();

int main()
{
    bool goodread = true;
    readData(goodread);
    if (goodread = true)
    {
        sortData();
        bamaCalc();
        aubCalc();
        outputYearWL();
        outputResults();
    }
    return 0;
}

bool readData(bool &goodread)
{
    ifstream dfile;
    titleRow tempRow;
    dataRows tempData;

    dfile.open(DATAFILE);
    if (dfile.is_open())
    {
        cout << "Processing file, please wait." << endl;
        dfile >> tempRow.school >> tempRow.year >> tempRow.schoolW >> tempRow.schoolL >> tempRow.schoolT;
        while (!dfile.eof())
        {
            if (dfile.good())
            {
                dfile >> tempData.school >> tempData.year >> tempData.win >> tempData.loss >> tempData.tie;
                dataReadings.push_back(tempData);
            }
            else
            {
                cerr << "Error: File contained bad data." << endl;
                cerr << "Please resubmit data file with corrected data." << endl;
                cerr << endl;
                goodread = false;
                break;
            }
        }
        dfile.close();
    }
    else
    {
        cerr << "Error: Unable to open data file" << endl;
        goodread = false;
    }
    return goodread;
}

void sortData()
{
    int minIndex;
    int i;
    for (i = 0; i < dataReadings.size(); i++)
    {
        int minYear;
        minIndex = i;
        minYear = dataReadings[i].year;
        int j;
        for (j = i + 1; j < dataReadings.size(); j++)
        {
            if (dataReadings[j].year < minYear)
            {
                minYear = dataReadings[j].year;
                minIndex = j;
            }
        }  
        swap(dataReadings[minIndex], dataReadings[i]);
    }
}

void bamaCalc()
{
    int i;
    for (i = 0; i < dataReadings.size(); i++)
    {
        if (dataReadings[i].school == "Alabama");
        {
            bamaW += dataReadings[i].win;
            bamaL += dataReadings[i].loss;
            bamaTotal += dataReadings[i].win + dataReadings[i].loss + dataReadings[i].tie;
        }
    }
    bamaPercent = (bamaW / bamaTotal);
}

void aubCalc()
{
    int i;
    for (i = 0; i < dataReadings.size(); i++)
    {
        if (dataReadings[i].school == "Auburn");
        {
            aubW += dataReadings[i].win;
            aubL += dataReadings[i].loss;
            aubTotal += dataReadings[i].win + dataReadings[i].loss + dataReadings[i].tie;
        }
    }
    aubPercent = (aubW / aubTotal);
}

void outputYearlyWL()
{
    int i;
    for (i=0; i < dataReadings.size(); i++)
    {
        cout << dataReadings[i].year << " " << dataReadings[i].school << " " << dataReadings[i].win << " - " << dataReadings[i].loss << endl;
    }
}

void outputResults()
{
    if (aubPercent > bamaPercent)
    {
        cout << "Auburn is the superior college football team in Alabama." << endl;
    }
    else if (bamaPercent > aubPercent)
    {
        cout << "Alabama is the superior college football team in Alabama." << endl;
    }
    else
    {
        cout << "The superior college football team could not be determined." << endl;
        cout << "Better luck next season." << endl;
        cout << "WarTide and RollEagle y'all!" << endl;
    }
}