#pragma once
#include <iostream>

const double EPSILON = 0.000000001;

class Nvector {
private:
	double* coordinates;
	size_t size; //size
public:
	Nvector();
	Nvector(const double*, const size_t);
	Nvector(const Nvector&);
	Nvector& operator=(const Nvector&);
	~Nvector();

	Nvector& operator+=(const Nvector&);
	Nvector& operator-=(const Nvector&);
	Nvector& operator*=(const double);

	bool isCollinear(const Nvector&);
	bool isPerpendicular(const Nvector&);
	
	size_t getSize() const;
	void print() const;

	double getCoordinate(size_t) const; //index
	void setCoordinate(double, size_t); //value, index

	friend std::ostream& operator<<(std::ostream&, const Nvector&);
	friend std::istream& operator>>(std::istream&, Nvector&);
private:
	void copy(const Nvector&);
	void free();
	double dotProduct(const Nvector&);
};

const Nvector operator+(const Nvector&, const Nvector&);
const Nvector operator-(const Nvector&, const Nvector&);
const Nvector operator*(const Nvector&, const double);
const Nvector operator*(const double, const Nvector&);