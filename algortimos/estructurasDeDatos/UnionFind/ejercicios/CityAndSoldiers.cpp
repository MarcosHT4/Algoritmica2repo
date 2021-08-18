#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int v[10000],n,q;
int parent[10000];
int rango[10000];


void init() {
    for(int i=0;  i<= n; i++) {
        parent[i] = i;
        rango[i] = 0;
    }
}

int find(int x) {
    if(x == parent[x]) {
        return x;
    }
    else {
        parent[x] = find(parent[x]);
        return parent[x];
    }
}

void unionRango(int a,int b) {
    int aRaiz = find(a);
    int bRaiz = find(b);

    parent[aRaiz] = bRaiz;

}

void unionSingle(int a) {

    int aRaiz = find(a);

    parent[aRaiz] = a;

}

int main() {

    cin>>n;

    for(int i = 1; i<=n; i++) {

        parent[i] = i;

    }

    cin>>q;

    int c, a,b;

    while(q--) {

        cin>>c;

        switch(c) {

            case 1:

                cin>>a>>b;
                unionRango(a,b);
                break;

                case 2:

                    cin>>a;
                    unionSingle(a);
                    break;



                    case 3:

                        cin>>a;

                        cout<<find(a)<<endl;

                        break;




        }


    }


    return 0;
}
