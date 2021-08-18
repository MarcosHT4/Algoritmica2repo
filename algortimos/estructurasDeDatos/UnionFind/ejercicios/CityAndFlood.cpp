#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int v[10000],n,k;
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

void unionRango(int x,int y) {
    int xRaiz = find(x);
    int yRaiz = find(y);
    if(rango[xRaiz] > rango[yRaiz]) {
        parent[yRaiz] = xRaiz;
    } else {
        parent[xRaiz] = yRaiz;
        if(rango[xRaiz] == rango[yRaiz]) {
            rango[yRaiz]++;
        }
    }
}



int main() {

    cin>>n;
    int ans = 0;

    for(int x = 1; x<=n; x++) {

        parent[x] = x;

    }

    cin>>k;

    while(k--) {

        int i, j;
        cin>>i>>j;
        unionRango(j,i);

    }

    for(int x = 1; x<=n; x++) {

        if(parent[x] == x) {

            ans++;

        }

    }

    cout<<ans<<endl; //GG ez




    return 0;
}


