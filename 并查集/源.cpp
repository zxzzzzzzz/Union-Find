#include<iostream>
#include<algorithm>
#include<cassert>
#include"UnionFind1.h"
#include"UnionFind2.h"
#include"UnionFind3.h"
#include"UnionFind4.h"
#include"UnionFind5.h"
#include"UnionFindTestHelper.h"

using namespace std;

int main()
{
	int n = 100000;

	UnionFindTestHelper::testUF1(n);
	UnionFindTestHelper::testUF2(n);
	UnionFindTestHelper::testUF3(n);
	UnionFindTestHelper::testUF4(n);
	UnionFindTestHelper::testUF5(n);

	system("pause");
	return 0;
}