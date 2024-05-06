#include <stdio.h>

//El problema es la variable n dentro de la función factorial. 
//Cuando se actualiza n dentro del bucle while se esta creando una nueva variable local n 
//que oculta la variable n original, lo que hace que el bucle se ejecute infinitamente ya que n nunca se 
//modifica

int factorial(int n) {
    int i = 1;
    while (n > 1) {
        i = i * n;
        n = n - 1;
    }
    return i;
}

int main(int argc, char *argv[]) {
    int num;
    printf("Ingrese un número para calcular su factorial: ");
    scanf("%d", &num);
   
    int fac = factorial(num);
   
    printf("%d! = %d\n", num, fac);
   
    return 0;
}