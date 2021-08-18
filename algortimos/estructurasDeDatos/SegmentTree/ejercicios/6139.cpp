
#include<bits/stdc++.h>
#define MAX_N 100010

using namespace std;



int a[1000000];
string finalAns;



struct node{
    int sum, mult , min, max;
}segmentTree[1+MAX_N*4];

int convert(int x) {

    if(x<0) {

        return -1;

    }

    if(x>0) {

        return 1;

    }

    return 0;

}


void init (int inicio, int final, int nodoActual) {
    if( inicio == final ) {
        segmentTree[nodoActual].max = convert(a[inicio]);
        segmentTree[nodoActual].min = convert(a[inicio]);
        segmentTree[nodoActual].sum = convert(a[inicio]);
        segmentTree[nodoActual].mult = convert(a[inicio]);
    } else {
        int mid = (inicio + final) / 2;
        int nodoIzquierdo = 2 * nodoActual+1;
        int nodoDerecho   = 2 * nodoActual + 2;
        // Ir por lado izquierdo
        init(inicio, mid, nodoIzquierdo );
        // Ir por lado derecho
        init( mid+1, final, nodoDerecho);


        segmentTree[nodoActual].mult = segmentTree[nodoIzquierdo].mult * segmentTree[nodoDerecho].mult;
        segmentTree[nodoActual].sum = segmentTree[nodoIzquierdo].sum + segmentTree[nodoDerecho].sum;
        segmentTree[nodoActual].max = max(segmentTree[nodoIzquierdo].max,  segmentTree[nodoDerecho].max);
        segmentTree[nodoActual].min = min(segmentTree[nodoIzquierdo].min, segmentTree[nodoDerecho].min);
    }
}


node query(int inicio, int final, int nodoActual, int izquierda, int derecha ) {

    if(inicio >= izquierda && final <= derecha ) {
        return segmentTree[nodoActual];
    }

    int mid = (inicio + final ) / 2;
    int nodoIzquierdo = 2 * nodoActual+1;
    int nodoDerecho   = 2 * nodoActual + 2;

    if(derecha <= mid ) {

        return query(inicio, mid, nodoIzquierdo, izquierda, derecha);
    } else if(izquierda > mid) {

        return query(mid+1, final, nodoDerecho, izquierda, derecha);
    } else {
        node maxIzquierdo = query(inicio, mid, nodoIzquierdo,izquierda,derecha);
        node maxDerecho   = query(mid+1, final, nodoDerecho,izquierda,derecha);

        node result;
        result.mult = maxIzquierdo.mult*maxDerecho.mult;
        result.max = max(maxIzquierdo.max, maxDerecho.max);
        result.min = min(maxIzquierdo.min, maxDerecho.min);
        return result;
    }
}

void update(int inicio, int final, int nodoActual, int posicion, int valor ) {
    if(posicion < inicio || posicion > final ) {
        return ;
    }

    if( inicio == final ) {
        segmentTree[nodoActual].max = convert(valor);
        segmentTree[nodoActual].min = convert(valor);
        segmentTree[nodoActual].sum = convert(valor);
        segmentTree[nodoActual].mult = convert(valor);
    } else {

        int mid = (inicio + final ) / 2;
        int nodoIzquierdo = 2 * nodoActual+1;
        int nodoDerecho   = 2 * nodoActual + 2;




        update(inicio, mid, nodoIzquierdo, posicion, valor );
        update(mid+1, final, nodoDerecho, posicion, valor );




        segmentTree[nodoActual].mult = segmentTree[nodoIzquierdo].mult * segmentTree[nodoDerecho].mult;
        segmentTree[nodoActual].max = max(segmentTree[nodoIzquierdo].max,  segmentTree[nodoDerecho].max);
        segmentTree[nodoActual].sum = segmentTree[nodoIzquierdo].sum + segmentTree[nodoDerecho].sum;
        segmentTree[nodoActual].min = min(segmentTree[nodoIzquierdo].min, segmentTree[nodoDerecho].min);

    }
}


int main() {

    int n ,k,x, I,V, J;
    char c;

    while(cin>>n>>k) {

        finalAns = "";


        for(int i = 0; i<n;i++) {

            cin>>x;

            a[i] = x;

        }



        init(0,n,0);

        while(k--) {

            cin>>c;

            switch(c) {

                case 'C':

                    cin>>I>>V;


                    update(0,n,0,I-1,V);

                    break;

                    case 'P':

                        cin>>I>>J;

                        int ans = query(0,n, 0, I-1, J-1).mult;

                        if(ans>0) {

                            finalAns+='+';

                        } else if (ans<0) {

                            finalAns+='-';

                        } else {

                            finalAns+= '0';

                        }

                        break;



            }


        }

        cout<<finalAns<<endl;

    }





    return 0;
}

