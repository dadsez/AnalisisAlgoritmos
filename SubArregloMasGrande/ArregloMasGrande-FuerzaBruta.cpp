#include<iostream>
#include<vector>
#include<limits>
#include<stdlib.h>
#include<time.h>

std::vector<double> fuerzaBruta( std::vector<double> A )
{
    double maxGanancia = std::numeric_limits<double>::min();
    double suma, f, l;
    std::vector<double> retorno;
    for( int i = 0; i < A.size(); i++ )
    {
        for( int j = i + 1; j < A.size(); j++ )
        {
            suma = 0;
            for( int k = i; k <= j; k++ )
            {
                suma += A[k];
            }
            if( suma > maxGanancia )
            {
                maxGanancia = suma;
                f = (long) i;
                l = (long) j;
            }
        }
    }

    retorno.push_back( f );
    retorno.push_back( l );
    retorno.push_back( maxGanancia );
    retorno.push_back( A[A.size()-1] - A[0] );

return retorno;
}

std::vector<double> llenarVector( int tam )
{
    std::vector<double> A;
    srand(time(NULL));

    A.push_back( (rand()%500) );
    for( int i = 0; i < tam; i++ )
        A.push_back( (rand()%500) -250 );

  return A;
}

void imprirmiVector( std::vector<double> A )
{
    srand(time(NULL));

    for( int i = 0; i < A.size(); i++ )
        std::cout << i << " -> "<< A[i] << std::endl;
}

int main()
{
    std::vector<double> A = llenarVector( 5000 );
    imprirmiVector(A);

    std::vector<double> result = fuerzaBruta( A );

    std::cout << "First: "<< result[0] << std::endl;
    std::cout << "Last: "<< result[1] << std::endl;
    std::cout << "Sum: "<< result[2] << std::endl;
    std::cout << "Profit: "<< result[3] << std::endl;

return 0;
}
