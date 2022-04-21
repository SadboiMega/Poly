// --------------------- poly.h -----------------------------------------
//
// Mohammad Zahid, CSS 343
// Created:         April 5, 202
// Date of Last Modification:   April 8, 2022
// --------------------------------------------------------------
// Purpose: This class implements a representation of polynomials
// that do not have negative exponents.  Each polynomial is
// stored completely in one array. The index of the array
// represents the power and is where the corresponding coefficient
// is stored. Polynomials will be able to be changed any time and
// can be added, subtracted, or multiplied by each other.
// --------------------------------------------------------------
// Assumptions: All data will be assumed to be correct and there
// is no error handling of any kind.  Negative exponents will be
// ignored.
// --------------------------------------------------------------
#ifndef POLY_H
#define POLY_H
#include <iostream>
using namespace std;
class Poly
{
// --------------------- Overloaded >> -----------------------------------------
// Takes two ints from console
// Sets the first to co (coefficent) and the 2nd to toT (to The power of)
// Calls setCoeff() to insert into Poly object
// --------------------------------------------------------------
friend istream& operator>>(std::istream &inStream, Poly &sCoeff);
// --------------------- Overloaded << -----------------------------------------
// Outputs the polynomial in print form
// If array is empty then 0 is returned
// --------------------------------------------------------------
friend ostream& operator<<(std::ostream &outStream, const Poly &sPoly);
public:
    // --------------------- Default Constructor ----------------------------------------   
    // Takes no parameters creates a Poly object
    // Array size set to 1 and value set to 0
    // --------------------------------------------------------------------------
    Poly();
    // --------------------- Constructor with int ----------------------------------------
    // Overloaded constructor takes one parameter and creates a Poly object
    // Array size set to 1 and value set to the int co
    // --------------------------------------------------------------------------
    Poly(int coeff);
    // --------------------- Destructor -----------------------------------------
    // Deletes coPtr and sets it NULL
    // --------------------------------------------------------------
    ~Poly();
    // --------------------- Constructor with int int ----------------------------------------
    // Overloaded constructor takes two parameters and creates a Poly object
    // Array size set to toT + 1 and the coefficient value in the last index
    // -----------------------------------------------------------------------------------
    Poly(int coeff, int toT);
    // --------------------- Copy Constructor -----------------------------------------
    // Creates a copy of the source Poly object passed in
    // --------------------------------------------------------------
    Poly(const Poly &s);
    // --------------------- getCoeff -----------------------------------------
    // Returns the coefficient at chosen index (toT)
    // Returns 0 if index is out of range
    // --------------------------------------------------------------
    int getCoeff(int toT) const;
    // --------------------- setCoeff -----------------------------------------
    // Set co passed in to the array index represented by power
    // If toT is out of array range then a new array is dynamically
    // allocated and the coeff is assigned to correct index
    // --------------------------------------------------------------
    void setCoeff(int coeff, int toT);
    // --------------------- Overloaded += -----------------------------------------
    // Adds two different polynomials together
    // assigns the sum to the Poly object to the left
    // --------------------------------------------------------------
    Poly& operator+=(const Poly &cf);
    // --------------------- Overloaded -= -----------------------------------------
    // Subtracts one from polynomial from another
    // assigns the difference to the Poly object to the left
    // --------------------------------------------------------------
    Poly& operator-=(const Poly &cf);
    // --------------------- Overloaded *= -----------------------------------------
    // Multiplies two different polynomials 
    // assigns the product to the Poly object to the left 
    // --------------------------------------------------------------
    Poly& operator*=(const Poly &cf);
    // --------------------- Overloaded = -----------------------------------------
    // Assigns the right Poly to the left Poly of the operator
    // --------------------------------------------------------------
    Poly& operator=(const Poly &cf);
    // --------------------- Overloaded + -----------------------------------------
    // Adds two different polynomials together and returns it
    // --------------------------------------------------------------
    Poly operator+(const Poly &cf) const;
    // --------------------- Overloaded - ----------------------------------------
    // Subtracts one polynomial from another and returns it
    // --------------------------------------------------------------
    Poly operator-(const Poly &cf) const;
    // --------------------- Overloaded * -----------------------------------------
    // Multiplies two different polynomials together and returns it
    // --------------------------------------------------------------
    Poly operator*(const Poly &cf) const;
    // --------------------- Overloaded == -----------------------------------------
    // Checks if two Poly objects contain identical polynomials
    // --------------------------------------------------------------
    bool operator==(const Poly &cf) const;
    // --------------------- Overloaded != -----------------------------------------
    // Checks if two Poly objects contain different polynomials
    // --------------------------------------------------------------
    bool operator!=(const Poly &cf) const;
private:
    //pointer 
    int* coPtr;  
    //size
    int size;   
};
#endif //POLY_H