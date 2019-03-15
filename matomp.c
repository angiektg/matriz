#include <stdio.h>
#include <omp.h>
#include <stdlib.h>

//g++ -fopenmp pi_reduccion.c -o pi_reduccion

int NTHREADS;

const long ENE = 1024;                                  //numero de filas y columnas en la matriz



class Matrix {      
    public:

    double mt[ENE][ENE];

    Matrix(bool fill){                              //constructor, se puede llenar la matriz con ceros o con numeros aleatorios
        for(int i=0; i<ENE; i++){
            for(int j=0;j<ENE;j++){
		        mt[i][j]=fill?(double)rand()/RAND_MAX:0;
            }   
        }
    };

    void show(){                                    //mostrar la matriz
        printf("\n");
        for(int i=0; i<ENE; i++){
            printf("\n");
            for(int j=0;j<ENE;j++){
                printf("%f ", mt[i][j]);
            }   
        }
        printf("\n");
    };
};

void producto(Matrix &A, Matrix &B, Matrix &C, int rango){    //multiplicacion de matriz en filas determinadas por rango, ENE y NTHREADS, actualiza una matriz C
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
    printf("Numero de hilos: %d\n" , NTHREADS);
    
    static Matrix a(true);
    static Matrix b(true);
    static Matrix r(false);
    //a.show(); 
    //b.show(); 
    omp_set_num_threads(NTHREADS);

    #pragma omp parallel
    {
        int id, nthrds;
        id = omp_get_thread_num();
        producto(a, b, r, id);
    }
    
    //r.show();
   return 0;
};
