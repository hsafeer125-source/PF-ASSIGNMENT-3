#include<stdio.h>

int calculateRepayment(int years, double loan, double interest, int installments, int currentYear){
    if(years == 0 || loan <= 0) return 0;

    loan = loan + (loan * interest);
    loan = loan - installments;
    if(loan < 0) loan = 0;

    printf("YEAR %d: Loan = %.2lf \n", currentYear, loan);

    return installments + calculateRepayment(years - 1, loan, interest, installments, currentYear + 1);

}
int main(){

    int years = 4;
    double loan = 100000;
    double interest = 0.05;
    int installments = 30000;

    double result = calculateRepayment(years, loan, interest, installments, 1);
    printf("Ammount to be paid: %.2lf", result);
    return 0;
}