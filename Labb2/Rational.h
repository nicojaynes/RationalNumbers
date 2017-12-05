#pragma once
#include "stdafx.h"
#include <iostream> 
#include <vector>
#include <string>
#include "GCD.h" 

using namespace std;

template<typename Tint> class Rational {
public:  
	Tint P, Q;  
	friend std::ostream& operator<< (std::ostream & cout, Rational<Tint> R) { 
			cout << R.P << '/' << R.Q;   
			return cout; 
	}

	friend std::istream& operator>> (std::istream & cin, Rational<Tint>& R) {
		string input;
		cin >> input;
		int middle = input.find("/");
		string P = input.substr(0, middle);
		string Q = input.substr(middle + 1);
		int Pint = stoi(P);
		int Qint = stoi(Q);
		R.P = Pint;
		R.Q = Qint;
		return cin;
	} 

	//Empty constructor, gives us the rational number 0/1
	Rational() : P(0), Q(1) { }  

	//Constructor from a single int
	Rational(Tint P) :P(P), Q(1) {}

	//Constructor from two numbers gives us the rational number P/Q
	Rational(Tint P, Tint Q) :P(P), Q(Q) {
		Reduce(this->P, this->Q);
	}

	Rational(Rational<short>& rShort) :P(rShort.P), Q(rShort.Q) {}

	Rational(Rational<int>& rInt) :P(rInt.P), Q(rInt.Q) {}

	Rational(Rational<long long>& rLong) :P(rLong.P), Q(rLong.Q) {}

	Rational operator+(const Rational<long long> right) {
		Rational temp;
		Tint rightDenom = right.Q;
		Tint leftDenom = Q;
		Tint rightNom = right.P;
		Tint leftNom = P;
		
		temp.P = (leftNom * rightDenom) + (rightNom * leftDenom);
		temp.Q = leftDenom * rightDenom;

		Reduce(temp.P, temp.Q);
		return temp;
	}

	bool operator==(const Rational<long long>& rcompare) {
		if (P == rcompare.P && Q == rcompare.Q) {
			return true;
		}
		return false;
	}

	Rational operator+=(const Rational<long long>& right) {
		Rational temp;
		Tint rightDenom = right.Q;
		Tint leftDenom = Q;
		Tint rightNom = right.P;
		Tint leftNom = P;

		this->P = (leftNom * rightDenom) + (rightNom * leftDenom);
		this->Q = leftDenom * rightDenom;

		Reduce(temp.P, temp.Q);

		return *this;
	}

	Rational operator++() {
		*this = *this + 1;
		return *this;
	}

	Rational operator++(int) {
		Rational beforeIncrement = *this;
		*this = *this + 1;
		return beforeIncrement;
	}

	Rational operator-() const {
		Rational temp;
		temp.P = -this->P;
		temp.Q = this->Q;
		return temp;
	}

	explicit operator short() const {
		short num = P / Q;
		return num;
	}

	explicit operator int() const {
		int num = P / Q;
		return num;
	}

	explicit operator long long() const {
		int num = P / Q;
		return num;
	}
};

