#include <stdio.h>
#include <stdlib.h>

/*Programa que recursivamente y apoyándose en el método de Newton-Raphson
  calcula, aproximádamente, la raíz cubica n números. */

long double calcRaiz ( long double num, long double x_0, long double error );

int main (int argc, char *argv[])

{
  int n, i;
  long double r;

  if( argc != 3 )
  {
    printf("Uso: %s Cantidad de numeros(N) Error(R)\n", argv[0] );
    return 0;
  }

  n = atoi(argv[1]);
  r = strtod(argv[2], NULL);

  long double num[n];  

  for( i = 0; i < n; i++ )
    scanf( "%Lf", &num[i] );   	


  for( i = 0; i < n; i++ ) 
    printf( "Raiz Cubica de %Lf = %.15Lf\n", num[i], calcRaiz( num[i], num[i]/3, r ) );

  return 0;
}

long double calcRaiz ( long double num, long double x_0, long double error )
{
  long double x_1 =  ( ( 2*x_0 + ( num/( x_0*x_0 ) ) ) ) /3;

  if ( ( x_0 - x_1 )  <=  error )
    return x_1;

  return calcRaiz( num, x_1, error ); 
} 
