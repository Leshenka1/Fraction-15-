#pragma once
#include <iostream>
#include <math.h>
#include <exception>

using namespace std;
class chislznam
{
private:
	long ch, zn;
public:
	chislznam();
	chislznam (long _ch, long _zn);
	
	void setch(long _ch);
	long getch() const;
	void setzn(long _zn);
	long getzn() const;
	float desdrob();

	chislznam operator -- () const;
	chislznam operator + (const chislznam& p) const;
	chislznam operator - (const chislznam&) const;
	chislznam operator * (const chislznam& p) const;
	chislznam operator /(const chislznam& p) const;
	bool operator == (const chislznam& p) const;
	bool operator != (const chislznam& p) const;
	bool operator > (const chislznam& p) const;
	bool operator < (const chislznam& p) const;
	bool operator >= (const chislznam& p) const;
	bool operator <=(const chislznam& p) const;

	friend ostream& operator <<(ostream&, const chislznam&);


};

