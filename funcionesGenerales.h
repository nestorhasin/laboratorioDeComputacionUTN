#ifndef FUNCIONESGENERALES_H_INCLUDED
#define FUNCIONESGENERALES_H_INCLUDED

/// Prototipo de Funciones

int acumularVector (int v[], int tam);

void mostrarVector(int v[], int tam);

int contarUnos(int v[], int tam);

int contarImpares(int v[], int tam);

int contarPares(int v[], int tam);

int contarNumerosRepetidos(int v[], int tam, int numero);  /// Cuenta la cantidad de veces que se repite un n�mero en el vector

int maximoVector(int v[], int tam); /// Devuelve  la posici�n (primera) que ocupa el m�ximo en el vector

int minimoVector(int v[], int tam); /// Devuelve  la posici�n (primera) que ocupa el m�nimo en el vector

void cargarAleatorio(int v[], int tam, int limite); /// Asigna valores aleatorios a cada al vector

void ordenarVector(int v[], int tam ); /// Ordena de menor a mayor un vector

int sumarVector(int v[], int tam ); /// Suma los valores contenidos en el vector

int copiarVector(int v[], int v2[],int tam ); /// Copia el vector v en v2

bool compararVectores(int v[], int v2[],int tam ); /// Compara los dos vectores que recibe. Si son iguales devuelve true

void ordenarVectorDescendente(int v[], int);

/// Desarrollo de Funciones / Definiciones

int posicionNumeroEnVector(int v[],int tam, int numero)
{
    int i;
    for(i=0; i<tam; i++)
    {
        if(v[i]==numero)
            return i;
    }
    return -1;
}

int minimoVector(int v[], int tam)
{
    int i, posMin=0;
    for(i=1; i<tam; i++)
    {
        if(v[i]<v[posMin])
        {
            posMin=i;
        }
    }
    return posMin;
}

void ordenarVector(int v[], int tam )
{
    int i,j, posmin, aux;
    for(i=0; i<tam-1; i++)
    {
        posmin=i;
        for(j=i+1; j<tam; j++)
        {
            if(v[j]<v[posmin])
                posmin=j;
        }
        aux=v[i];
        v[i]=v[posmin];
        v[posmin]=aux;
    }
}

void ordenarVectorDescendente(int v[], int tam )
{
    int i,j, posmin, aux;
    for(i=0; i<tam-1; i++)
    {
        posmin=i;
        for(j=i+1; j<tam; j++)
        {
            if(v[j]>v[posmin])
                posmin=j;
        }
        aux=v[i];
        v[i]=v[posmin];
        v[posmin]=aux;
    }
}

int maximoVector(int v[], int tam)
{
    int i, posMax=0;
    for(i=1; i<tam; i++)
    {
        if(v[i]>v[posMax])
        {
            posMax=i;
        }
    }
    return posMax;
}

void cargarAleatorio(int v[], int tam, int limite)
{
    int i;
    srand(time(NULL));
    for( i=0; i<tam; i++ )
    {
        v[i]=(rand()%limite)+1;
    }
}

void mostrarVector(int v[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        cout<<v[i]<<"\t";
    }
}

int contarNumerosRepetidos(int v[], int numero, int tam)
{
    int i, cant=0;
    for(i=0; i<tam; i++)
    {
        if(v[i]==numero)
            cant++;
    }
    return cant;
}

void ponerCero(int v[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        v[i]=0;
    }
}

int sumarVector(int v[], int tam )
{
    int i, suma=0;
    for(i=0; i<tam; i++)
    {
        suma+=v[i];
    }
    return suma;
}

int copiarVector(int v[], int v2[],int tam )
{
    int i;
    for(i=0; i<tam; i++)
    {
        v2[i]=v[i];
    }
}

bool compararVectores(int v[], int v2[],int tam )
{
    int i;
    for(i=0; i<tam; i++)
    {
        if(v2[i]!=v[i])
            return false;
    }
    return true;
}

int contarPares(int v[], int tam)
{
    int conta = 0;
    for(int i = 0; i < tam; i++)
    {
        if(v[i] % 2 == 0)
        {
            conta++;
        }
    }
    return conta;
}

int contarImpares(int v[], int tam)
{
    int conta = 0;
    for(int i = 0; i < tam; i++)
    {
        if(v[i] % 2 != 0)
        {
            conta++;
        }
    }
    return conta;
}

int contarUnos(int v[], int tam)
{
    int conta = 0;
    for(int i = 0; i < tam; i++)
    {
        if(v[i] == 1)
        {
            conta++;
        }
    }
    return conta;
}

int acumularVector (int v[], int tam)
{
    int total = 0;
    for(int i = 0; i < tam; i++)
    {
        total += v[i];
    }
    return total;
}

#endif /// FUNCIONESGENERALES_H_INCLUDED
