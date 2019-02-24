#include <iostream>
#include <thread>
#include <stdlib.h>

const int ENE = 5;


class Matrix {
    public:

    int mt[ENE][ENE];

    Matrix(bool fill){
        for(int i=0; i<ENE; i++){
            for(int j=0;j<ENE;j++){
		mt[i][j]=fill?rand()%10 + 1:0;
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

Matrix producto(Matrix A, Matrix B, int FR, int TO){
Matrix c(false);
int acc = 0;
for(int i=FR;i<TO;i++){
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
    Matrix a(true);
    Matrix b(true);
    Matrix r(false);
    a.show(); 
    b.show(); 
    r = producto(a, b, 0, 2);
    r.show();
   return 0;
};
