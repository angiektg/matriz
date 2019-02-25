#include <iostream>
#include <thread>
#include <stdlib.h>

int NTHREADS;

const unsigned long ENE = 256;                                  //numero de filas y columnas en la matriz



class Matrix {      
    public:

    double mt[ENE][ENE];

    Matrix(bool fill){                              //constructor, se puede llenar la matriz con ceros o con numeros aleatorios
        for(int i=0; i<ENE; i++){
            for(int j=0;j<ENE;j++){
		        mt[i][j]=fill?rand():0;
            }   
        }
    };

    void show(){                                    //mostrar la matriz
        std::cout << "\n";
        for(int i=0; i<ENE; i++){
            std::cout << "\n";
            for(int j=0;j<ENE;j++){
                std::cout << mt[i][j] << " ";
            }   
        }
        std::cout << "\n";
    };
};

void producto(Matrix A, Matrix B, Matrix &C, int rango){    //multiplicacion de matriz en filas determinadas por rango, ENE y NTHREADS, actualiza una matriz C
double acc = 0;
int inf = ENE/NTHREADS*rango;
int sup = inf+ENE/NTHREADS;

    for(int i=inf;i<sup;i++){
        for(int j=0;j<ENE;j++){
                for(int k=0; k<ENE; k++){
                    acc = acc + (A.mt[i][k]*B.mt[k][j]);
                }
            C.mt[i][j] = acc;
            acc = 0;
        }
    }
};


int main (int argc, char *argv[]){
    NTHREADS = atoi(argv[1]);
    std::cout << "Numero de hilos: " << NTHREADS << "\n";
    std::thread t[NTHREADS];
    Matrix a(true);
    Matrix b(true);
    Matrix r(false);
    //a.show(); 
    //b.show(); 
    for(int i=0;i<NTHREADS;i++) t[i] = std::thread (producto, a, b, std::ref(r), i);     
    for(int i=0;i<NTHREADS;i++) t[i].join();
    //r.show();
   return 0;
};
