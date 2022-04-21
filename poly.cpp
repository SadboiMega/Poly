// --------------------- poly.cpp -----------------------------------------
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
#include "poly.h"
using namespace std;

// --------------------- Overloaded >> -----------------------------------------
// Takes two ints from console
// Sets the first to co (coefficent) and the 2nd to toT (to The power of)
// Calls setCoeff() to insert into Poly object
// --------------------------------------------------------------
istream& operator>>(std::istream &inStream, Poly &sCo) 
{
    int toT;
    int co;
    while (true)    
    {
        inStream >> co >> toT; 
        if ((co == -1) && (toT == -1)) 
        {
            break;
        }
        sCo.setCoeff(co, toT); 
    }
    return inStream;
} //end of >> function

// --------------------- Overloaded << -----------------------------------------
// Outputs the polynomial in print form
// If array is empty then 0 is returned
// --------------------------------------------------------------
ostream& operator<<(std::ostream &oStream, const Poly &sPoly)
{
    bool isZero = true;
    bool isFirst = true;  
    for (int i = sPoly.size - 1; i >= 0; i--)    
    {
        if (sPoly.coPtr[i] != 0)   
        {
            isZero = false;  
            if (!isFirst) 
            {
                oStream << " "; 
            } else {
                isFirst = false;
            }
            if (sPoly.coPtr[i] > 0) 
            {
                oStream << "+";   
            }
            oStream << sPoly.coPtr[i];
            if (i == 1) 
            {
                oStream << "x";   
            }    
            if (i != 0 && i != 1)  
            {
                oStream << "x^" << i; 
            }
        }
    }
    if (isZero == false)
    {
        return oStream;   
    }
    else
    {
        return oStream << "0";
    }
} //end of << function

// --------------------- Default Constructor ----------------------------------------
// Takes no parameters creates a Poly object
// Array size set to 1 and value set to 0
// --------------------------------------------------------------------------
Poly::Poly()
{
    this->size = 1;
    coPtr = new int[this->size];
    coPtr[0] = 0;
} //end of Default Constructor function

// --------------------- Constructor with int ----------------------------------------
// Overloaded constructor takes one parameter and creates a Poly object
// Array size set to 1 and value set to the int co
// --------------------------------------------------------------------------
Poly::Poly(int co)
{
    this->size = 1;
    coPtr = new int[this->size];
    coPtr[0] = co;
} //end of Default Constructor with int

// --------------------- Destructor -----------------------------------------
// Deletes coPtr and sets it NULL
// --------------------------------------------------------------
Poly::~Poly() 
{
    delete[] coPtr;
    coPtr = NULL;
} // end of destructor
// --------------------- Constructor with int int ----------------------------------------
// Overloaded constructor takes two parameters and creates a Poly object
// Array size set to toT + 1 and the coefficient value in the last index
// -----------------------------------------------------------------------------------
Poly::Poly(int co, int toT)
{
    this->size = toT + 1;
    coPtr = new int[this->size];
    for (int i = 0; i < this->size ; i++)
    {
        coPtr[i] = 0;
    }
    coPtr[toT] = co;
} // end of constructor with int int

// --------------------- Copy Constructor -----------------------------------------
// Creates a copy of the source Poly object passed in
// --------------------------------------------------------------
Poly::Poly(const Poly &s)
{
    this->size = s.size;
    coPtr = new int[size];
    for (int i = 0; i < this->size; i++)
    {
        coPtr[i] = s.coPtr[i];
    }
} // end of copy constructor

// --------------------- getCoeff -----------------------------------------
// Returns the coefficient at chosen index (toT)
// Returns 0 if index is out of range
// --------------------------------------------------------------
int Poly::getCoeff(int toT) const
{
    if ((toT < this->size) && (toT >= 0)) 
    {
        return coPtr[toT]; 
    }
    else
    {
        return 0;
    }
} // end of getCoeff function

// --------------------- setCoeff -----------------------------------------
// Set co passed in to the array index represented by power
// If toT is out of array range then a new array is 
// allocated and the co is assigned to correct index
// --------------------------------------------------------------
void Poly::setCoeff(int co, int toT)
{
  if (toT >= 0) 
    {
        if (toT < this->size)   
        {
            coPtr[toT] = co;    
        }
        else
        {
            int *tArr = new int[toT + 1];  
            for (int i = 0; i < this->size; i++)
            {
                tArr[i] = coPtr[i];   
            }
            for (int j = this->size; j < toT + 1; j++)
            {
                tArr[j] = 0; 
            }
            delete[] coPtr;   
            tArr[toT] = co; 
            coPtr = NULL;    
            coPtr = tArr; 
            tArr = NULL;     
            this->size = toT + 1;  
        }
    }
} // end of setCoeff function

// --------------------- Overloaded += -----------------------------------------
// Adds two different polynomials together
// assigns the sum to the Poly object to the left
// --------------------------------------------------------------
Poly& Poly::operator+=(const Poly &p)
{
    *this = *this + p;
    return *this;
} // end of += function
// --------------------- Overloaded -= -----------------------------------------
// Subtracts one from polynomial from another
// assigns the difference to the Poly object to the left
// --------------------------------------------------------------
Poly& Poly::operator-=(const Poly &p)
{
    *this = *this - p;
    return *this;
} // end of -= function

// --------------------- Overloaded *= -----------------------------------------
// Multiplies two different polynomials 
// assigns the product to the Poly object to the left 
// --------------------------------------------------------------
Poly& Poly::operator*=(const Poly &p)
{
    *this = *this * p;
    return *this;
} // end of *= function

// --------------------- Overloaded = -----------------------------------------
// Assigns the right Poly to the left Poly of the operator
// --------------------------------------------------------------
Poly& Poly::operator=(const Poly &p)
{
    if (this->coPtr == p.coPtr) 
    {
        return *this;  
    } 
        delete[] this->coPtr;   
        coPtr = NULL;    
        this->size = p.size;  
        this->coPtr = new int[this->size];   
        for (int i = 0; i < this->size; i++)
        {
            this->coPtr[i] = p.coPtr[i];    
        }
    return *this;   
} // end of = function

// --------------------- Overloaded + -----------------------------------------
// Adds two different polynomials together and returns it
// --------------------------------------------------------------
Poly Poly::operator+(const Poly &p) const
{
    if (this->size > p.size) {
        Poly pSum(0, this->size);    
        for (int i = 0; i < this->size; i++)
        {
            pSum.coPtr[i] = this->coPtr[i];            
        }
        for (int i = 0; i < p.size; i++)
        {
            pSum.coPtr[i] += p.coPtr[i]; 
        }
        return pSum; 
    }
    else    
    {
        Poly pSum(0, p.size);  
        for (int i = 0; i < p.size; i++)
        {
            pSum.coPtr[i] = p.coPtr[i];     
        }
        for (int i = 0; i < this->size; i++)
        {
            pSum.coPtr[i] += this->coPtr[i];  
        }
        return pSum;
    }
} // end of + function

// --------------------- Overloaded - ----------------------------------------
// Subtracts one polynomial from another and returns it
// --------------------------------------------------------------
Poly Poly::operator-(const Poly &p) const
{
 if (this->size > p.size)  
    {
        Poly diffrent(0, this->size);   

        for (int i = 0; i < this->size; i++)
        {
            diffrent.coPtr[i] = this->coPtr[i];         
        }
        for (int i = 0; i < p.size; i++)
        {
            diffrent.coPtr[i] -= p.coPtr[i]; 
        }
        return diffrent; 
    }
    else   
    {
        Poly diffrent(0, p.size); 
        for (int i = 0; i < this->size; i++)
        {
            diffrent.coPtr[i] = this->coPtr[i];   
        }
        for (int i = 0; i < p.size; i++)
        {
            diffrent.coPtr[i] -= p.coPtr[i]; 
        }
        return diffrent; 
    }
} // end of - function

// --------------------- Overloaded * -----------------------------------------
// Multiplies two different polynomials together and returns it
// --------------------------------------------------------------
Poly Poly::operator*(const Poly &p) const
{
    int tSize;   
    tSize = (this->size + p.size - 2); 
    Poly tArr(0, tSize);  
        for (int i = 0; i < this->size; i++)
        {
            if (this->coPtr[i] != 0) 
            {
                for (int j = 0; j < p.size; j++)
                {
                    tArr.coPtr[i + j] += (this->coPtr[i] * p.coPtr[j]); 
                }
            }
        }
    return tArr; 
} //end of * function

// --------------------- Overloaded == -----------------------------------------
// isZeros if two Poly objects contain identical polynomials
// --------------------------------------------------------------
bool Poly::operator==(const Poly &p) const 
{
   if (this->size != p.size)   
   {
       return false;
   }
   else
   {
        for (int i = 0; i < this->size; i++)
        {
            if (coPtr[i] != p.coPtr[i]) 
            {
                return false;   
            }
        }
        return true;    
    }
} // end of == function

// --------------------- Overloaded != -----------------------------------------
// isZeros if two Poly objects contain different polynomials
// --------------------------------------------------------------
bool Poly::operator!=(const Poly &p) const 
{
    return !(*this == p);
} // end of != function