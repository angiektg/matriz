#include <iostream>
#include <thread>
#include <stdlib.h>

const int ENE = 3;


class Matrix {
    public:

    int mt[ENE][ENE];

    Matrix(){
        for(int i=0; i<ENE; i++){
            for(int j=0;j<ENE;j++){
                mt[i][j]=rand()%10 + 1;
            }   
        }
    };

    void show(){
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

Matrix producto(Matrix A, Matrix B){
Matrix c;
int acc = 0;
for(int i=0;i<ENE;i++){
    for(int j=0;j<ENE;j++){
            for(int k=0; k<ENE; k++){
                acc = acc + (A.mt[i][k]*B.mt[k][j]);
            }
        c.mt[i][j] = acc;
        acc = 0;
    }
}
return c;
};


int main (){
    Matrix a,b,r;
    a.show(); 
    b.show(); 
    r = producto(a, b);
    r.show();
   return 0;
};