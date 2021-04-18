#include <stdio.h>
#include <iostream>

double proximaParcela(double s, int n, double j, int corrente, double *valor) {
	
	if (corrente == 0)   	// cálculo da primeira parcela
        *valor = s;
    else if (corrente < n)	// cálculo das demais parcelas
        *valor = *valor + (*valor * (j/100));
    else
        *valor = 0;  		// não há mais parcelas para calcular
        	
	return *valor;
}

int main(int argc, char **argv) {
	int res = system("clear");
	if (res) printf("error\n");
	
	double s=200;
    int n=5;
    double j=1;
    
    double parcela=s;
    for (unsigned i=0; i<n; ++i) {
        printf("Valor da parcela %d: %3.2f\n", i+1, parcela);
        parcela = parcela + (parcela * (j/100));
    }
	
	printf("\n\n\n");
	
	int corrente=0;
	for (unsigned i=0; i<n; ++i) {
        parcela = proximaParcela(s, n, j, i, &parcela);
        printf("Valor da parcela %d: %3.2f\n", i+1, parcela);
    }  
    
	return 0;
}

