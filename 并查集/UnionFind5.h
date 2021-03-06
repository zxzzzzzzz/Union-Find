#ifndef UNIONFIND_UNIONFIND5_H
#define UNIONFIND_UNIONFIND5_H
#include<iostream>
#include <cassert>

using namespace std;


// Quick Union + rank + path compression
namespace UF5{
	//近乎O(1)
    class UnionFind{

    private:
        int* parent;
        int* rank;// rank[i]表示以i为根的集合所表示的树的层数
        int count;

    public:
        UnionFind(int count){
            parent = new int[count];
            rank = new int[count];
            this->count = count;
            for( int i = 0 ; i < count ; i ++ ){
                parent[i] = i;
                rank[i] = 1;
            }
        }

        ~UnionFind(){
            delete[] parent;
            delete[] rank;
        }

        int size(){
            return count;
        }

        bool isConnected( int p , int q ){
            return find(p) == find(q);
        }

        int find(int p){

            assert( p >= 0 && p < count );

            // path compression 1
            while( p != parent[p] ){
                parent[p] = parent[parent[p]];
                p = parent[p];
            }
            return p;

            // path compression 2
//            if( p != parent[p] )
//                parent[p] = find( parent[p] );
//            return parent[p];
        }

        void unionElements(int p, int q){

            int pRoot = find(p);
            int qRoot = find(q);

            if( pRoot == qRoot )
                return;

            if( rank[pRoot] < rank[qRoot] )
                parent[pRoot] = qRoot;
            else if( rank[qRoot] < rank[pRoot])
                parent[qRoot] = pRoot;
            else{ // rank[pRoot] == rank[qRoot]
                parent[pRoot] = qRoot;
                rank[qRoot] ++;
            }

        }

        void show(){
            for( int i = 0 ; i < count ; i ++ )
                cout<<i<<" : "<<parent[i]<<endl;
        }
    };
}

#endif //UNIONFIND_UNIONFIND5_H
