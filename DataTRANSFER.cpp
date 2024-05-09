#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    // Program 2 requests to develop an output file that has the employees' updated salary

    // input the file, "SalaryData.txt" in the Algorithm
    ifstream inputFile("SALARYData.txt");
    if (!inputFile.is_open()) {
        cerr << "Error: Could not open SalaryData.txt" << endl;
        return 1;
    }

    // output the file, "NEWsalarydata.txt"
    ofstream outputFile("NEWsalarydata.txt");
    if (!outputFile.is_open()) {
        cerr << "Error: Could not create NEWsalarydata.txt" << endl;
        inputFile.close();
        return 1;
    }

    // process the data in "SalaryData.txt" and develop a new file, "NEWsalarydata.txt"
    string firstNAME, lastNAME;
    double currentSALARY, payINCREASE;

    while (inputFile >> lastNAME >> firstNAME >> currentSALARY >> payINCREASE) {
        // calculate the updated salary by adding the current salary to the pay increase
        double UPDATEDsalary = currentSALARY + (currentSALARY * payINCREASE / 100.0);

        // transfer the new data to the new file, "NEWsalarydata.txt"
        ostringstream oss;
        outputFile << fixed << setprecision(2);
        outputFile << firstNAME << " " << lastNAME << " " << UPDATEDsalary << endl;

        outputFile << oss.str();
    }

    // close the input and outputFile, "SalaryData.txt" and "NEWsalarydata.txt"
    inputFile.close();
    outputFile.close();

    cout << "Data has been processed and saved to NEWsalarydata.txt." << endl;

    return 0;
}