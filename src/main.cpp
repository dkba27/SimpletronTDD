/*
 * main.cpp
 *
 *  Created on: Oct 23, 2015
 *      Author: adminuser
 */

#include "simpletron.h"
#include <fstream>


using namespace std;

void readFile(simpletron &s)
{
	string line;
	int count = 0;
	ifstream myfile ("/home/adminuser/workspace/Simpletron_mb/program.sml");
	if (myfile.is_open())
	{
		while ( getline (myfile,line) )
		{
			if (line !="-99999")
			{
				s.loadmem(count, line);
				count ++;
			}
		}
		myfile.close();
	}
}

int main(int argc, char **argv)
{
	simpletron s ;
	//s.inputprogram();
	readFile(s);
	try
	{
		s.execute();
	}
	catch (exception &e)
	{
		cout << e.what() << endl;
		//	s.dump();
	}
	s.dump();
}



