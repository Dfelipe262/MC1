#include <iostream>
using namespace std;

int divisao(int a, int b){
    int soma = 0;
    int quociente = 0;
    
    if(b == 0){
        cout << "divisao inválida" << endl;
    }
    
    else if(a > 0 && b > 0){
        while(soma + b <= a){
            soma += b;
            quociente++;
        }
        
        return quociente;
    }
    
    else if(a>0 && b<0){ // 8/-3
        b = -b;
        while(soma + b <= a){
            soma += b;
            quociente++;
        }
        
        return -quociente;
    }
    
    else if(a<0 && b>0){ // -3/8
    
        while(a <= soma){
            soma -= b;
            quociente--;
        }
        
        return quociente;
    }
    
    else if(a<0 && b<0){ // -3/-4  -8/-3
    
        while(a <= soma){
            soma += b;
            quociente++;
        }
        
        return quociente;
            
    }
    
    return 0;
        
}

int main() {
    
    cout << divisao (10, 3) << endl;

    return 0;
}