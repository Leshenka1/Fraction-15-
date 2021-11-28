#include "chislznam.h"
#include <iostream>

void Sokr(long *chisl1, long* znam1)
{
	if ((((*chisl1) / (*znam1)) > 0) && (*chisl1) < 0)
	{
		*chisl1 = -*chisl1;
		*znam1 = -*znam1;
	}
	if ((((*chisl1) / (*znam1)) < 0) && (*znam1) < 0)
	{
		*chisl1 = -*chisl1;
		*znam1 = -*znam1;
	}
	long zn = *znam1;
	long ch = *chisl1;
	while (zn != 0) {
		int c = ch % zn;
		ch = zn;
		zn = c;
	}
	*znam1 = *znam1 / sqrt(ch * ch);
	*chisl1 = *chisl1 / sqrt(ch * ch);
}

void chislznam::setzn(long _zn)
{
	if (_zn == 0)
	{
		throw exception("0 can not be denominator");
	}
	else {
	zn = _zn;
	}
	
}

long chislznam::getzn() const
{
	return zn;
}

float chislznam::desdrob()
{
	return (float)ch/zn;
}

void chislznam::setch(long _ch)
{
	ch = _ch;
}

long chislznam::getch() const
{
	return ch;
}


chislznam::chislznam(long _ch, long _zn)
{
	setch(_ch);
	setzn(_zn);
}

chislznam::chislznam()
{
	ch = 0;
	zn = 1;
}

chislznam chislznam::operator--() const
{
		return chislznam(-ch, zn);
}

chislznam chislznam::operator + (const chislznam& p) const
{
	long Chisl = ch * p.zn + p.ch * zn;
	long Znam = zn * p.zn;
	Sokr(&Chisl,&Znam);
	return chislznam(Chisl,Znam);
}

chislznam chislznam::operator -(const chislznam& p) const
{
	long Chisl = ch * p.zn - p.ch * zn;
	long Znam = zn * p.zn;
	Sokr(&Chisl, &Znam);
	return chislznam(Chisl, Znam);
}

chislznam chislznam::operator*(const chislznam& p) const
{
	long Chisl = ch * p.ch;
	long Znam = zn * p.zn;
	Sokr(&Chisl, &Znam);
	return chislznam(Chisl, Znam);
}

chislznam chislznam::operator/(const chislznam& p) const
{
	long Chisl = ch * p.zn;
	long Znam = zn * p.ch;
	Sokr(&Chisl, &Znam);
	return chislznam(Chisl, Znam);
}

bool chislznam::operator==(const chislznam& p) const
{
	return (ch == p.ch && zn==p.zn);
}

bool chislznam::operator!=(const chislznam& p) const
{
	return (ch != p.ch || zn != p.zn);
}

bool chislznam::operator>(const chislznam& p) const
{
	return ((ch * p.zn - p.ch * zn)>0);
}

bool chislznam::operator<(const chislznam& p) const
{
	return ((ch * p.zn - p.ch * zn) < 0);
}

bool chislznam::operator>=(const chislznam& p) const
{
	return ((ch * p.zn - p.ch * zn)>=0);
}

bool chislznam::operator<=(const chislznam& p) const
{
	return ((ch * p.zn - p.ch * zn) <= 0);
}


ostream& operator<<(ostream& s, const chislznam& p)
{
	s <<"     "<<p.ch << "\n" << "   -----\n" << "     " << p.zn << " \n";
	return s;
}
