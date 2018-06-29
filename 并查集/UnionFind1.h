#ifndef UNIONFIND1_H
#define UNIONFIND1_H

#include<iostream>
#include<cassert>

using namespace std;
//Quick Find
namespace UF1
{
	class UnionFind
	{
	private:
		int* id;
		int count;
	public:
		UnionFind(int n)
		{
			count = n;
			id = new int[n];
			for (int i = 0; i < n; i++)
			{
				id[i] = i;
			}
		}
		~UnionFind()
		{
			delete[] id;
		}

		int find(int p)//返回相应元素所对应的id,O(n)
		{
			assert(p >= 0 && p < count);
			return id[p];
		}

		bool isConnected(int p, int q)
		{
			return find(p) == find(q);
		}

		void unionElements(int p, int q)//并运算，O(n)
		{
			int pID = find(p);
			int qID = find(q);

			if (pID == qID)
				return;

			for (int i = 0; i < count; i++)
			{
				if (id[i] == pID)
					id[i] = qID;
			}
		}
	};
}


#endif // !UNIONFIND1_H

