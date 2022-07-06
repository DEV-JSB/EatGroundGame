#pragma once
#include"CObject.h"

#include <list>
using namespace std;

class CEnemy : public CObject
{
	list<int> a;
	list<int> b;
	int Here = 3;
	int cnt = 0;

	for (list<int>::iterator iter = a.begin(); iter != a.end(); ++iter)
	{
		if (cnt++ != Here)
			continue;

		for (list<int>::iterator iter2 = b.begin(); iter2 != b.end(); ++iter2)
			a.emplace(iter2);

		b.clerar();
		b.shrinktofit();
		break;
	}
};

