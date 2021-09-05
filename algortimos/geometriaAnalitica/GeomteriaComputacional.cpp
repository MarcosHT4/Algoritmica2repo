#include <bits/stdc++.h>

using namespace std;


// Vector = Point Pero Vector = B - A
// Vector A
// A = Point(4,5);
struct Point{
    double x, y; //Las coordenadas x, y del punto


    Point(double a,double b) { //Constructor para el punto
        x = a;
        y = b;
    }

    double angle() { //Nos saca el ángulo que genera el vector (Recordemos que en esta implementación, un punto y un vector son lo mismo)
        return atan2(y,x);
    }

    double mod() { //Obtiene el módulo de un vector
        return sqrt(x*x+y*y);
    }

    Point unit() {
        double modulo = mod(); //Obtenemos el módulo del mismo vector
        return Point(x/modulo, y/modulo); //Con ésta fórmula, obtenemos el vector unitario, dividimos las coordenadas entre el módulo del mismo vector
    }
};

Point operator +(const Point &a, const Point &b) { //Hacemos una sobrecarga del operador para que sume las coordenadas x,y de ambos puntos
    return Point(a.x + b.x, a.y + b.y);
}

Point operator -(const Point &a, const Point &b) { //Hacemos una sobrecarga del operador para que reste las coordenadas x,y de ambos puntos
    return Point(a.x - b.x, a.y-b.y);
}

Point operator *(const Point &a, double k) { //Hacemos una sobrecarga del operador para que multiplique las coordenadas del punto por una constante k
    return Point(a.x*k,a.y*k);
}

Point operator /(const Point &a, double k) { //Hacemos una sobrecarga del operador para que divida las coordenadas del punto entre una constante k
    return Point(a.x/k, a.y/k);
}

bool operator <(const Point &a, const Point &b) { //Verifica si un punto es menor a otro punto
    if(a.x != b.x) {
        return a.x < b.x;
    } else {
        return  a.y < b.y;
    }
}

ostream& operator<<(ostream&os, Point p) {

    return os <<"("<<p.x<< "," << p.y <<")";

}

// Funciones Basicas
// Distancia de dos puntos // sqrt(B.x-A.x + B.y-A.y)
// http://www.cplusplus.com/reference/cmath/hypot/
double dist(const Point &A, const Point &B) { //Utilizando hypot, nos saca la formula directamente, es la distancia entre A y B
    return hypot(A.x-B.x,A.y - B.y);
}

// Producto Escalar
// A y B son vectores
// si el producto es 0 son perpendiculares
double dot(const Point &A, const Point &B) { //Obtiene el producto punto de dos vectores
    return A.x * B.x + A.y * B.y;
}

// Product Cross or producto Vectorial (Area de un paralelogramo)
// V y U son vectores
// si el producto es 0 son paralelos
double cross(const Point &V, const Point &U) { //Obtiene el producto cruz de dos vectores, puede ser interpretado como área.
    return V.x * U.y - V.y * U.x;
}

// Get Area

double areaP(const Point &V, const Point &U) { //Si queremos un área, ésta misma debe ser positiva, por lo tanto, sacamos el valor abosluto del producto cruz
    return abs(cross(V,U));
}

// Area de 3 puntos

double area(const Point &A, const Point &B, const Point &C) {
    return cross(B - A, C - A);
}

// Area de un triangulo
// Area formada por 3 puntos.
// Primero Crear el vector V = C-A y el vector U = B-A
// Por lo tanto puedo usar el cross product

double areaTriangulo(const Point &A, const Point &B, const Point &C) { //Nos sirve para obtener el área de un triángulo, obtiene el área mediante el producto escalar de AB y AC, y luego lo divide entre 2
    return abs(area(A,B,C))/2.0;
}

//  Formula de heron

double areaHeron(double a, double b, double c) {
    double s = (a+b+c)/2;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

// es rectangulo

/*

bool is_triangle(Point &A, Point &B, Point &C) {
    a = dist(A,B);// cuadrado
    b = dist(A,C);// cuadrado
    c = dist(B,C);// cuadrado
    return 2*max(a,b,c) == a+b+c;
}

 */


// punto de interseccion de rectas
// division entre dos double
// multiplicacion Point por un Double // por esa razon lo llevamos (B-A) a la izq.
Point lineIntersection(const Point &A,const Point &B,const Point &C,const Point &D) { //Nos sirve para obtener el punto de la intersección entre dos rectas
    return A+(B-A)*(cross(C-A,D-C)/cross(B-A,D-C));
}



// P esta dentro del segmento AB
// 0.0
bool onSegment(const Point &A, const Point&B, const Point &P) { //Nos preguntamos si un punto P está en un segmento formado por A->B
    return areaTriangulo(A,B,P) == 0 && //El área que generan los tres puntos debe ser igual a cero, ya que si no fuera asi, formarian un triangulo
    (P.x >= min(A.x,B.x) && P.x <= max(A.x,B.x)) &&
    (P.y >= min(A.y,B.y) && P.y <= max(A.y,B.y)); //Las coordenandas de P deben ser de tal manera que estén dentro del segmento A->B
}

bool intersectsSegment(const Point &A,const Point &B,const Point &C,const Point &D) {
    double A1 = area(C,A,D);   // el segmento es CD y A es el punto
    double A2 = area(C,B,D);   // el segmento es CD, y B es el punto
    double A3 = area(A,B,C);   // el segmento es AB, y C es el punto
    double A4 = area(A,B,D);   // el segmento es AB, y D es el punto

    if(((A1 > 0 && A2 < 0) || (A1<0 && A2>0)) && //En resumen, si una area es positiva, la otra debe ser negativa
    ((A3 > 0 && A4 < 0) || (A3<0 && A4>0)))  {
        return true;
    }

    if(A1 == 0 && onSegment(C,D,A)) { //Si un area es 0, significa de que el punto principal debe estar en el segmento (3er caso)
        return true;
    }

    if(A2 == 0 && onSegment(C,D,B)) {
        return true;
    }

    if(A3 == 0 && onSegment(A,B,C)) {
        return true;
    }

    if(A4 == 0 && onSegment(A,B,D)) {
        return true;
    }

    return false;
}



// poligono Convexo o No convexo

bool isConvex(const vector<Point> &polign) {
    int nroPoints = polign.size();
    int areasPositive =  0, areasNegative = 0;
    for(int i = 0; i < nroPoints ;i++) {
        double areaPoints = area(polign[i],polign[(i+1)%nroPoints],polign[(i+2)%nroPoints]);
        if(areaPoints>0) {
            areasPositive++;
        } else if(areaPoints<0) {
            areasNegative++;
        }
    }
    return areasPositive == 0 || areasNegative == 0;
}

// Area de un Poligono

double areaPoligono(const vector<Point> &poligono) {
    int nroPoints = poligono.size();
    double areaTotal = 0;
    for(int i = 1; i < nroPoints - 1; i++) {
        areaTotal += area(poligono[0],poligono[i],poligono[i+1]);
    }
    return abs(areaTotal/2);
}

// Convex Hull

/*

vector<Point> convexHull(vector<Point> &points) {
    sort(points.begin(),points.end());
    int k = 0;
    Point hulls[points.size()+10];   // podriamos usar una pila
    // Parte Inferior
    for(int i = 0; i<points.size();i++){
        while(k>=2 && area(hulls[k-2],hulls[k-1],points[i])<=0) {
            k--; // stack.pop();
        }
        hulls[k++] = points[i];
    }

    // Parte Superior

    for(int i = points.size()-2, t = k;i>=0; i--) {
        while( k > t && area(hulls[k-2],hull[k-1],points[i]<=0)){
            k--;
        }
        hulls[k++] = points[i];
    }

    return vector<Point> (hulls,hulls+k-1);
}

 */

int main() {

    Point A(0,0);
    Point B(1,0);
    cout<<A+B<<endl;

    return 0;


}




