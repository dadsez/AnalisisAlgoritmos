#include <math.h>
#include <stdio.h>

/* ------------------------------------------------------------------------- */
double CubeRoot( double a, double error )
{
  double _0 = ( double )( 0 );
  double _1 = ( double )( 1 );
  double _2 = ( double )( 2 );
  double _3 = ( double )( 3 );
  double xPrev = a;
  double xNext;
  double diff;

  do
  {
    xNext = ( ( _2 * xPrev ) + ( a / ( xPrev * xPrev ) ) ) / _3;
    diff = fabs( xPrev - xNext );
    xPrev = xNext;

  } while( diff > error );

  return( xNext );
}

/* ------------------------------------------------------------------------- */
int main( int argc, char* argv[] )
{
  unsigned int N, i;
  double n, R, r;

  scanf( "%d %lf", &N, &R );
  for( i = 0; i < N; i++ )
  {
    scanf( "%lf", &n );

    r = CubeRoot( n, R );
    printf( "%.10f\n", r );

  } /* rof */
  return( 0 );
}

/* eof - cuberoot.c */
