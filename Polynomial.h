#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H


struct termOfPolynomial{
    int coefficient;
    int exponent;
};
class Polynomial {
private:
    const static int capacity = 10;
    termOfPolynomial term[capacity];
    int totalTerms;
    int biggestExponent;
    
public:
    Polynomial();
    void addTerm(int coefficient, int exponent);
    int degree();
    int coefficient(int power);
    int numberOfTerms();
    int value(int x);

};


#endif
