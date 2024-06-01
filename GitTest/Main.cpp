#include<iostream>
#include <cstdlib> 

using namespace std; 

class Fraction 
{
private:
    double numerator;
    double denominator;

    int gcd(int a, int b)  
    {
        while (b != 0) 
        {
            int t = b;
            b = a % b;
            a = t;
        }
        return a;
    }
    // ����� ��� ���������� �����
    void reduce() 
    {
        int divisor = gcd(numerator, denominator);   
        numerator /= divisor;   
        denominator /= divisor;  

        // ���� ����������� �������������, ��������� ���� � ���������
        if (denominator < 0) 
        { 
            numerator = -numerator; 
            denominator = -denominator; 
        } 
    }

public:
    // ����������� �� ���������
    Fraction() : numerator(0), denominator(1) {} 

    // ����������� � �����������
    Fraction(int num, int denom) : numerator(num), denominator(denom)  
    {
        reduce();
    }

    // ����� ��� ����� ������
    int input() 
    {
        cout << "Enter numerator: ";
        cin >> numerator; 
        cout << "Enter denominator: ";
        cin >> denominator; 
        if (denominator == 0)  
        {
            cout << "Denominator cannot be zero" << endl;
            return 0;   
        } 
        reduce();
    }

    // ����� ��� ������ ������
    void output() 
    {
        cout << endl << numerator << "\n-\n" << denominator << endl;  
    }


    // �������� ��������
    Fraction operator+(Fraction& other)  
    {
        int num = numerator * other.denominator + other.numerator * denominator;
        int denom = denominator * other.denominator; 
        return Fraction(num, denom);
    }

    // �������� ���������
    Fraction operator-(Fraction& other)  
    {
        if (numerator == other.numerator || denominator == other.denominator) 
        {
            int num = 0;
            int denom = 0; 
            return Fraction(num, denom);  
        }
        int num = numerator * other.denominator - other.numerator * denominator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }

    // �������� ���������
    Fraction operator*(Fraction& other)  
    {
        int num = numerator * other.numerator; 
        int denom = denominator * other.denominator; 
        return Fraction(num, denom);
    }

    // �������� �������
    Fraction operator/(Fraction& other)  
    {
        if (other.numerator == 0) 
        {
            cout << "Denominator cannot be zero" << endl;
        }
        int num = numerator * other.denominator;
        int denom = denominator * other.numerator;
        return Fraction(num, denom);
    }
};

int main() {
    Fraction f1;
    cout << "Enter first fraction:\n";
    f1.input();

    Fraction f2;
    cout << "Enter second fraction:\n";
    f2.input();

    Fraction sum = f1 + f2;  
    Fraction diff = f1 - f2;
    Fraction prod = f1 * f2;
    Fraction quot = f1 / f2;

    cout << "Sum: ";
    sum.output();

    cout << "Difference: ";
    diff.output();

    cout << "Product: ";
    prod.output();

    cout << "Quotient: ";
    quot.output();
   

     

    return 0;
}
