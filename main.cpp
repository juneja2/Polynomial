#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Polynomial.h"


using namespace std;

const int arrSize = 2;

void openFile(ifstream & infile, const char * fileName);
void readFromFile(Polynomial & p, ifstream & infile);
void output(Polynomial & p);

int main(){

    try {
        Polynomial a[arrSize];
        ifstream infile[arrSize];
        const char * fileName[arrSize];
        fileName[0] = "C:\\Users\\juneja\\Desktop\\Computer Science\\CS 536\\Lab2\\Polynomial\\Polynomial\\data1.txt";
        fileName[1] = "C:\\Users\\juneja\\Desktop\\Computer Science\\CS 536\\Lab2\\Polynomial\\Polynomial\\data2.txt";

        for (int i = 0; i < arrSize; i++) {
            openFile(infile[i], fileName[i]);
            readFromFile(a[i], infile[i]);
            infile[i].close();
            output(a[i]);
        }

        return 0;
    }
    catch (out_of_range error) {
        cout << error.what() << endl;
        exit(EXIT_FAILURE);
    }
    catch (const char * error) {
        cout << error << endl;
        exit(EXIT_FAILURE);
    }
}
void openFile(ifstream & infile, const char * fileName) {
    infile.open(fileName);
    if (!infile)
        throw ("Couldn't open specified file");
}
void readFromFile(Polynomial & p, ifstream & infile) {

    int coefficient, exponent;

    while (!infile.eof()) {
        infile >> coefficient >> exponent;
        p.addTerm(coefficient, exponent);
    }

}
void output(Polynomial & p) {
    cout << "Degree: " << p.degree() << endl;
    cout << "# terms: " << p.numberOfTerms() << endl;
    for (int i = 0; i < 8; i++)
        cout << "coeff(" << i << "):  " << p.coefficient(i) << endl;
    for (int i = 1; i <= 2; i++)
        cout << "value(" << i << "):  " << p.value(i) << endl;
}