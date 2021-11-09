#include<stdio.h>

double exponentiation(double, int);
double module(double);
int factorial(int);
void Output(int, double, double, double);

int main() {

    double S_Row = 0, Newbody_Row = 0, Accuracy_Row, x;
    int k = 1;
    scanf("%lf%lf", &Accuracy_Row, &x);

    if (Accuracy_Row < 0) Accuracy_Row *= -1;

    do {
        Newbody_Row = exponentiation(x, k) / factorial(k+1);
        if (k%2) Newbody_Row *= -1;
        S_Row += Newbody_Row;
        Output(k, S_Row, Newbody_Row, Accuracy_Row);
        k++;
    } while (module(Newbody_Row) > Accuracy_Row);
    return 0;
}

double exponentiation(double x, int k){
    double res = x;
    for (int i=1; i<k; i++){
        res *= x;
    }
    return res;
}

double module(double Newbody_Row){
    if (Newbody_Row < 0) return Newbody_Row * -1;
    return Newbody_Row;
}

int factorial(int k){
    if (k == 1) return 1;
    return k * factorial(k-1);
}

void Output(int k, double S_Row, double Newbody_Row, double Accuracy_Row){
    printf("~~~~~\n");
    printf("NewBody(%d) = %lf\n", k, Newbody_Row);
    printf("Summ(%d) = %lf\n", k, S_Row);
    printf("Accuracy diffrence - %lf\n", module(Newbody_Row) - Accuracy_Row);
    printf("~~~~~\n");
    return;
}