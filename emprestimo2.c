#include <stdio.h>
#include <iostream>

double es;
double ej;
double parcela;
int   en;
int   corrente;

void novoEmprestimo(double s, int n, double j) {
    es = s;
    en = n;
    ej = j;
    corrente = 1;
    parcela = s;
}

double proximaParcela() {
    double valor = parcela;
    
    corrente++;
    if (corrente <= en)
        parcela = parcela + (parcela * (ej/100));
    else
        parcela = 0;
        
    return valor;
}

int main(int argc, char **argv) {
	int res = system("clear");
	if (res) printf("error\n");
	
    novoEmprestimo(200, 5, 1);
    
    int i = 0;
    double p = proximaParcela();
    while (p > 0) {
        printf("Valor da parcela %d: %3.2f\n", i+1, p);
        p = proximaParcela();
        i++;
    }
    
    return 0;
}
