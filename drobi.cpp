#include <iostream>
#include "chislznam.h"
using namespace std;

void sokr(long* chisl1,long* znam1)
{
	if (*chisl1 == -0 || *chisl1==0 )
	{
		*znam1 = 1;
	}
	else
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
}

int main()
{
	chislznam dr1;
	chislznam dr2;

	long chisl,znam;
	cout << "enter numenator and denominator of first fraction " << endl;
	cin >> chisl >> znam;
	try 
	{
		dr1.setzn(znam);
	}
	catch (const exception &ex)
	{
		cout <<ex.what()<<endl;
		return 0;
	}

	sokr(&chisl, &znam);

	dr1.setch(chisl);
	dr1.setzn(znam);


	long chisl2, znam2;
	cout << "enter numenator and denominator of second fraction " << endl;
	cin >> chisl2>>znam2;
	try
	{
		dr2.setzn(znam2);
	}
	catch (const exception& ex)
	{
		cout << ex.what() << endl;
		return 0;
	}

	sokr(&chisl2, &znam2);

	dr2.setch(chisl2);

	dr2.setzn(znam2);

	cout << "===========================================" << endl;

	cout <<"unarniy -"<<endl<< --dr1 << endl;
	cout << "___________________________" << endl;
	cout <<"+"<<endl<< dr1 + dr2 << "\n";
	cout << "___________________________" << endl;
	cout <<"-"<<endl  << dr1 - dr2 << "\n";
	cout << "___________________________" << endl;
	cout << "*  " << endl <<dr1 * dr2 << "\n";
	cout << "___________________________" << endl;
	cout << "/  " << endl << dr1 / dr2 << "\n";
	cout << "___________________________" << endl;
	cout << "==  " << endl << "     " << (dr1 == dr2) << "\n";
	cout << "___________________________" << endl;
	cout << "!=  " << endl << "     " << (dr1 != dr2) << endl;
	cout << "___________________________" << endl;
	cout << ">  " << endl << "     " << (dr1 > dr2) << endl;
	cout << "___________________________" << endl;
	cout << "<  " << endl << "     " << (dr1 < dr2) << endl;
	cout << "___________________________" << endl;
	cout << ">=  " << endl << "     " << (dr1 >= dr2) << endl;
	cout << "___________________________" << endl;
	cout << "<=  " << endl << "     " << (dr1 <= dr2) << endl;
	cout << "___________________________" << endl;
	cout << "fraction in double " << endl << "     " << dr1.desdrob() << endl;
}

