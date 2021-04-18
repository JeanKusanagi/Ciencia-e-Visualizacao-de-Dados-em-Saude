#include <stdio.h>
#include <iostream>

typedef struct {
    double s;    
    double j;
    double p;
    int corrente;
    int n;
} Emprestimo;

Emprestimo novoEmprestimo(double s, double n, double j) {
	Emprestimo e;
	
	e.s = s;
    e.n = n;
    e.j = j;
    
    e.corrente = 1;
    e.p = e.s;
    
    return e;
}

double proximaParcela(Emprestimo *e) {
    double retorno = e->p;
    
    if (e->corrente < e->n)
        e->p = e->p + (e->p * (e->j/100));
    else
        e->p = 0;
        
    (e->corrente)++;
    
    return retorno;
}

void main1() {

    Emprestimo emprestimo = novoEmprestimo(200,5,1);
    
    int i = 0;
    double p = proximaParcela(&emprestimo);
    while (p > 0) {
        printf("Valor da parcela %d: %3.2f\n", i+1, p);
        i++;
        p = proximaParcela(&emprestimo);
    }
}

void main2() {
    
    Emprestimo emprestimo1 = novoEmprestimo(200,5,1);
    Emprestimo emprestimo2 = novoEmprestimo(500,7,2);
       
    double p1 = proximaParcela(&emprestimo1), p2 = proximaParcela(&emprestimo2);
    
    int i = 0;
    while (p1 > 0 || p2 > 0) {
        if (p1 > 0)
            printf("Emprestimo 1: parcela %d -> %3.2f\n", i+1, p1);
        if (p2 > 0)
            printf("Emprestimo 2: parcela %d -> %3.2f\n", i+1, p2);
            
        p1 = proximaParcela(&emprestimo1);
        p2 = proximaParcela(&emprestimo2);
        i++;
    } 
}

int main(int argc, char **argv) {
	int res = system("clear");
	if (res) printf("error\n");
    
    main1();
    main2();
    
    return 0;
}
