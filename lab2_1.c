#include<stdio.h>

double exponentiation(double, int);
int factorial(int);
void Output(int, double, double);

int main() {
    double S_Row = 0, Newbody_Row = 0, x;
    int N;
    scanf("%d%lf", &N, &x);

    if (N <= 0){
        printf("N cant be 0 \n");
        return 0;
    }

    for (int k=1; k<=N; k++){
        Newbody_Row = exponentiation(x, k) / factorial(k+1);
        if (k%2) Newbody_Row *= -1;
        S_Row += Newbody_Row;
        Output(k, S_Row, Newbody_Row);
    }

    return 0;
}

double exponentiation(double x, int k){
    double res = x;
    for (int i=1; i<k; i++){
        res *= x;
    }
    return res;
}

int factorial(int k){
    if (k == 1) return 1;
    return k * factorial(k-1);
}

void Output(int k, double S_Row, double Newbody_Row){
    printf("~~~~~\n");
    printf("NewBody(%d) = %lf\n", k, Newbody_Row);
    printf("Summ(%d) = %lf\n", k, S_Row);
    printf("~~~~~\n");
    return;
}