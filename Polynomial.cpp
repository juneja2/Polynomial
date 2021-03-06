#include "Polynomial.h"
#include <iostream>
#include <cmath>
using namespace std;

Polynomial::Polynomial() {
    for (int i = 0; i < capacity; i++) {
        term[i].coefficient= 0;
        term[i].exponent = 0;
        totalTerms = 0;
        biggestExponent = 0;
    }
}
void Polynomial::addTerm(int coefficient, int exponent) {
    if (totalTerms < capacity) {
        if (exponent >= 0 && exponent < capacity) {

            for (int i = 0; i < totalTerms; i++)
                if (term[i].exponent == exponent)
                    throw ("This exponent already exists");

            this->term[totalTerms].coefficient = coefficient;
            this->term[totalTerms].exponent = exponent;

            if (biggestExponent < term[totalTerms].exponent)
                biggestExponent = term[totalTerms].exponent;
            
            totalTerms++;
        }
        else throw out_of_range("Exponent has to be greater than or equal to 0 and less than 10");
    }
    else throw out_of_range("Number of terms in a polynomial is limited to 10");
    
}

int Polynomial::degree() {
    return biggestExponent;
}

int Polynomial::coefficient(int power) {
    for (int index = 0; index < totalTerms; index++)
        if (term[index].exponent == power)
            return term[index].coefficient;

    return 0;
}
int Polynomial::numberOfTerms() {
    return totalTerms;
}

int Polynomial::value(int x) {
    int total = 0;

    for (int index = 0; index < totalTerms; index++)
        total += term[index].coefficient * ((int)pow(x, term[index].exponent));

    return total;
 
}