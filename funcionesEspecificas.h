#ifndef FUNCIONESESPECIFICAS_H_INCLUDED
#define FUNCIONESESPECIFICAS_H_INCLUDED
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<ctime>
#include<windows.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "rlutil.h"
#include <dos.h>

using namespace std;

using namespace rlutil;

#define ABAJO 80
#define ARRIBA 72
#define ENTER 13

/// Prototipo de Funciones

bool escalera(int [], int);

int puntos(int [], int, int);

void dadoUno();

void dadoDos();

void dadoTres();

void dadosGraficos (int [], int);

void mayorPuntuacion(char[][25], int[], int[], int);

void estructuraPrincipal();

void estructuraNombre();

void estructuraResultados();

void estructuraResultadosDos();

int menu();

void dameNombre(char [], int tam);

void dameContrincante(char [], int tam);

void mostrarResultados(int, int, int, int, int);

void cambioTurnoDosJugadores(int, char[25], char[25], int, int, int, int);

void mostrarGanador(char[25], int, int, int, int);

void mostrarEmpate(char [25], char [25], int, int, int, int);

void mostrarRanking(char [][25], int [], int [], int);

void mostrarDatosTirada(char [], int, int, int, int);

void mensajeResultado(char [], int, int, int, int);

void mensajeRonda(int, char [], int, int, int, int);

void instrucciones();

void estructuraPrincipalC5();

void dadoaux(int,int,int, int );

void indicacionesSimulado();

/// Desarrollo de Funciones / Definiciones

bool escalera(int v[], int tam) /// DEVUELVE TRUE SI HAY ESCALERA
{
    ordenarVector(v, tam); /// LLAMO A ESTA FUNCION PARA ORDENAR EL VECTOR POR SI LOS DADOS SALEN DE LA SIGUIENTE MANERA: 3 1 2
    for(int i = 0; i < (tam - 1); i++)
    {
        if(v[i + 1] - 1 != v[i])
        {
            return false;
        }
    }
    return true;
}

int puntos(int v[], int tam, int ronda) /// RETORNA EL PUNTAJE DE LA TIRADA E IMPRIME EN PANTALLA LO QUE SIGNIFICA ESA PUNTUACION
{
    int puntaje;
    if(contarNumerosRepetidos(v, v[0], 3) == 3 && v[0] == ronda) /// UTILIZAMOS ESTA FUNCION PARA CONTAR LOS REPETIDOS
    {
        puntaje = 21;
        locate(30, 10.5);
        cout<<"BUNCO - ";
        locate(38, 10.5);
        cout<<"PUNTAJE TIRADA "<<puntaje<<endl;
        return puntaje;

    }
    else if(contarNumerosRepetidos(v, v[0], 3) == 3 && v[0] != ronda)
    {
        puntaje = 5;
        locate(30, 10.5);
        cout<<"IGUALES - ";
        locate(40, 10.5);
        cout<<"PUNTAJE TIRADA "<<puntaje<<endl;
        return puntaje;
    }
    else if (sumarVector(v, 3) % 5 == 0)
    {
        puntaje = 3;
        locate(26, 10.5);
        cout<<"DIVISIBLE POR 5 - ";
        locate(44, 10.5);
        cout<<"PUNTAJE TIRADA "<<puntaje<<endl;
        return puntaje;
    }
    else if(escalera(v, tam) == true)
    {
        puntaje = 2;
        locate(30, 10.5);
        cout<<"ESCALERA - ";
        locate(41, 10.5);
        cout<<"PUNTAJE TIRADA "<<puntaje<<endl;
        return puntaje;
    }
    else if(contarNumerosRepetidos(v, ronda, tam) != 0)
    {
        puntaje = contarNumerosRepetidos(v, ronda, tam);
        locate(20, 10.5);
        cout<<"COINCIDE CON NUMERO DE RONDA - ";
        locate(51, 10.5);
        cout<<"PUNTAJE TIRADA "<<puntaje<<endl;
        return puntaje;
    }
    else
    {
        puntaje = 0;
        locate(26, 10.5);
        cout<<" TIRADA FALLIDA - ";
        locate(44, 10.5);
        cout<<"PUNTAJE TIRADA "<<puntaje<<endl;
        return puntaje;
    }
}

void dadoUno() /// DIBUJA EL PRIMER DADO
{
    /// HORIZONTAL
    for (int i = 28; i < 36; i++)
    {
        locate(i, 13);
        printf("%c", 205);
        locate(i, 17);
        printf("%c", 205);
    }
    /// VERTICAL
    for (int i = 14; i < 17; i++)
    {
        locate(28, i);
        printf("%c", 186);
        locate(36, i);
        printf("%c", 186);
    }
    /// ESQUINAS
    locate(28, 13);
    printf("%c", 201);
    locate(28, 17);
    printf("%c", 200);
    locate(36, 13);
    printf("%c", 187);
    locate(36, 17);
    printf("%c", 188);
}

void dadoDos()  /// DIBUJA EL SEGUNDO DADO
{
    /// HORIZONTAL
    for (int i = 38; i < 46; i++)
    {
        locate(i, 13);
        printf("%c", 205);
        locate(i, 17);
        printf("%c", 205);
    }
    /// VERTICAL
    for (int i = 14; i < 17; i++)
    {
        locate(38, i);
        printf("%c", 186);
        locate(46, i);
        printf("%c", 186);
    }
    /// ESQUINAS
    locate(38, 13);
    printf("%c", 201);
    locate(38, 17);
    printf("%c", 200);
    locate(46, 13);
    printf("%c", 187);
    locate(46, 17);
    printf("%c", 188);
}

void dadoTres()  /// DIBUJA EL TERCER DADO
{
    /// HORIZONTAL
    for (int i = 48; i < 56; i++)
    {
        locate(i, 13);
        printf("%c", 205);
        locate(i, 17);
        printf("%c", 205);
    }
    /// VERTICAL
    for (int i = 14; i < 17; i++)
    {
        locate(48, i);
        printf("%c", 186);
        locate(56, i);
        printf("%c", 186);
    }
    /// ESQUINAS
    locate(48, 13);
    printf("%c", 201);
    locate(48, 17);
    printf("%c", 200);
    locate(56, 13);
    printf("%c", 187);
    locate(56, 17);
    printf("%c", 188);
}

void dadosGraficos (int v[], int tam) /// DIBUJA EL VALOR DEL DADO, ES DECIR, LOS PUNTITOS DE ADENTRO DEL CUADRADO
{
    dadoUno();
    dadoDos();
    dadoTres();
    for(int i = 0; i < tam; i++)
    {
        switch(v[i])
        {
        case 1:
            if(i == 0)
            {
                locate(32, 15);
                printf("%c", 254);
            }
            else if(i == 1)
            {
                locate(42, 15);
                printf("%c", 254);
            }
            else
            {
                locate(52, 15);
                printf("%c", 254);
            }
            break;
        case 2:
            if(i == 0)
            {
                locate(30, 14);
                printf("%c", 254);
                locate(34, 16);
                printf("%c", 254);
            }
            else if(i == 1)
            {
                locate(40, 14);
                printf("%c", 254);
                locate(44, 16);
                printf("%c", 254);
            }
            else
            {
                locate(50, 14);
                printf("%c", 254);
                locate(54, 16);
                printf("%c", 254);
            }
            break;
        case 3:
            if(i == 0)
            {
                locate(30, 14);
                printf("%c", 254);
                locate(32, 15);
                printf("%c", 254);
                locate(34, 16);
                printf("%c", 254);
            }
            else if(i == 1)
            {
                locate(40, 14);
                printf("%c", 254);
                locate(42, 15);
                printf("%c", 254);
                locate(44, 16);
                printf("%c", 254);
            }
            else
            {
                locate(50, 14);
                printf("%c", 254);
                locate(52, 15);
                printf("%c", 254);
                locate(54, 16);
                printf("%c", 254);
            }
            break;
        case 4:
            if(i == 0)
            {
                locate(30, 14);
                printf("%c", 254);
                locate(30, 16);
                printf("%c", 254);
                locate(34, 14);
                printf("%c", 254);
                locate(34, 16);
                printf("%c", 254);
            }
            else if(i == 1)
            {
                locate(40, 14);
                printf("%c", 254);
                locate(40, 16);
                printf("%c", 254);
                locate(44, 14);
                printf("%c", 254);
                locate(44, 16);
                printf("%c", 254);
            }
            else
            {
                locate(50, 14);
                printf("%c", 254);
                locate(50, 16);
                printf("%c", 254);
                locate(54, 14);
                printf("%c", 254);
                locate(54, 16);
                printf("%c", 254);
            }
            break;
        case 5:
            if(i == 0)
            {
                locate(30, 14);
                printf("%c", 254);
                locate(30, 16);
                printf("%c", 254);
                locate(32, 15);
                printf("%c", 254);
                locate(34, 14);
                printf("%c", 254);
                locate(34, 16);
                printf("%c", 254);
            }
            else if (i == 1)
            {
                locate(40, 14);
                printf("%c", 254);
                locate(40, 16);
                printf("%c", 254);
                locate(42, 15);
                printf("%c", 254);
                locate(44, 14);
                printf("%c", 254);
                locate(44, 16);
                printf("%c", 254);
            }
            else
            {
                locate(50, 14);
                printf("%c", 254);
                locate(50, 16);
                printf("%c", 254);
                locate(52, 15);
                printf("%c", 254);
                locate(54, 16);
                printf("%c", 254);
                locate(54, 14);
                printf("%c", 254);
            }
            break;
        case 6:
            if(i == 0)
            {
                locate(30, 14);
                printf("%c", 254);
                locate(30, 15);
                printf("%c", 254);
                locate(30, 16);
                printf("%c", 254);
                locate(34, 14);
                printf("%c", 254);
                locate(34, 15);
                printf("%c", 254);
                locate(34, 16);
                printf("%c", 254);
            }
            else if(i == 1)
            {
                locate(40, 14);
                printf("%c", 254);
                locate(40, 15);
                printf("%c", 254);
                locate(40, 16);
                printf("%c", 254);
                locate(44, 14);
                printf("%c", 254);
                locate(44, 15);
                printf("%c", 254);
                locate(44, 16);
                printf("%c", 254);
            }
            else
            {
                locate(50, 14);
                printf("%c", 254);
                locate(50, 15);
                printf("%c", 254);
                locate(50, 16);
                printf("%c", 254);
                locate(54, 14);
                printf("%c", 254);
                locate(54, 15);
                printf("%c", 254);
                locate(54, 16);
                printf("%c", 254);
            }
            break;
        }
    }
}

void mayorPuntuacion(char nombreMaximo[][25], int puntajeMaximo[], int buncoMaximo[], int tam) /// INFORMA EL PUNTAJE MAXIMO
{
    int indiceMaximo = maximoVector(puntajeMaximo, tam); /// UTILIZAMOS ESTA FUNCION PARA ADQUIRIR EL INDICE DEL VALOR MAXIMO
    locate(32, 6);
    cout<<"LA BESTIA DEL PUNTAJE"<<endl;
    locate(40, 10);
    cout<<nombreMaximo[indiceMaximo]<<endl;
    locate(34, 12);
    cout<<"PUNTAJE MAXIMO: "<<puntajeMaximo[indiceMaximo]<<endl;
    locate(35, 14);
    cout<<"RECORD BUNCOS: "<<buncoMaximo[indiceMaximo]<<endl;
    locate(32, 18);
    cout<<"PERSEVERA Y TRIUNFARAS"<<endl;
}

void estructuraPrincipal() /// DIBUJAMOS UNA ESTRUCTURA PRINCIPAL EN PANTALLA
{
    for (int i = 10; i < 75; i++)
    {
        locate(i, 2);
        printf("%c", 42);
        locate(i, 6);
        printf("%c", 42);
        locate(i, 22);
        printf("%c", 42);
    }

    for(int i = 2; i < 23; i++)
    {
        locate(10, i);
        printf("%c", 42);
        locate(74, i);
        printf("%c", 42);
    }
}

void estructuraPrimera() /// DIBUJAMOS LA ESTRUCTURA DEL MENU
{
    for (int i = 10; i < 75; i++)
    {
        locate(i, 2);
        printf("%c", 42);
        locate(i, 6);
        printf("%c", 42);
        locate(i, 24);
        printf("%c", 42);
    }

    for(int i = 2; i < 25; i++)
    {
        locate(10, i);
        printf("%c", 42);
        locate(74, i);
        printf("%c", 42);
    }
}

void estructuraNombre() /// DIBUJAMOS LA ESTRUCTURA PARA PEDIRLE AL USUARIO EL NOMBRE
{
    for (int j = 25; j < 60; j++)
    {
        locate(j, 8);
        printf("%c", 42);
        locate(j, 16);
        printf("%c", 42);
    }

    for(int i = 8; i < 16; i++)
    {
        locate(25, i);
        printf("%c", 42);
        locate(59, i);
        printf("%c", 42);
    }
}

void estructuraResultados() /// DIBUJAMOS LA ESTRUCTURA RESULTADOS PARA UN JUGADOR Y EN MODO SIMULADO
{
    for (int j = 25; j < 60; j++)
    {
        locate(j, 4);
        printf("%c", 42);
        locate(j, 8);
        printf("%c", 42);
        locate(j, 16);
        printf("%c", 42);
        locate(j, 20);
        printf("%c", 42);
    }

    for(int i = 4; i < 21; i++)
    {
        locate(25, i);
        printf("%c", 42);
        locate(59, i);
        printf("%c", 42);
    }
}

int menu() /// ESTA FUNCION NOS DA LA BIENVENIDA, PRESENTA EL MENU Y RETORNA EL VALOR DE LA OPCION ELEGIDA POR EL USUARIO
{
    int opc;
    char bienvenido[] = "B I E N V E N I D O   A L   B U N C O";
    estructuraPrimera();
    locate(24, 4);
    for(int i = 0; i < 38; i++)
    {
        cout<<bienvenido[i];
        Sleep(50);
    }
    locate(38, 8);
    cout<<"- MENU -"<<endl;
    Sleep(500);
    locate(35, 10);
    cout<<"1. Un jugador"<<endl;
    locate(35, 12);
    cout<<"2. Dos jugadores"<<endl;
    locate(35, 14);
    cout<<"3. Mayor puntuacion"<<endl;
    locate(35, 16);
    cout<<"4. Modo simulado"<<endl;
    locate(35, 18);
    cout<<"5. Instrucciones"<<endl;
    locate(35, 20);
    cout<<"0. Salir"<<endl;
    Sleep(500);
    locate(35, 22);
    cout<<"Opcion: ";
    cin>>opc;
    system("cls");
    return opc;
}

void estructuraResultadosDos() /// DIBUJAMOS LA ESTRUCTURA DE RESULTADOS PARA DOS JUGADORES
{
    for (int j = 25; j < 60; j++)
    {
        locate(j, 4);
        printf("%c", 42);
        locate(j, 10);
        printf("%c", 42);
        locate(j, 16);
        printf("%c", 42);
        locate(j, 22);
        printf("%c", 42);
    }

    for(int i = 4; i < 23; i++)
    {
        locate(25, i);
        printf("%c", 42);
        locate(59, i);
        printf("%c", 42);
    }
}

void dameNombre(char nombre[], int tam) /// PEDIMOS AL USUARIO QUE INGRESE SU NOMBRE
{
    locate(35, 11);
    cout<<"DAME TU NOMBRE"<<endl;
    locate(39, 13);
    cin>>nombre;
}

void dameContrincante(char nombre[], int tam) /// PEDIMOS AL USUARIO QUE INGRESE EL NOMBRE DEL CONTRINCANTE
{
    locate(30, 11);
    cout<<"DAME EL NOMBRE DE TU RIVAL"<<endl;
    locate(39, 13);
    cin>>nombre;
}

void indicacionesSimulado() /// INFORMAMOS COMO ES EL MODO SIMULADO
{
    locate(32, 10);
    cout<<"Y AHORA VAS A INGRESAR"<<endl;
    locate(30, 12);
    cout<<"LOS TRES DADOS MANUALMENTE";
    locate(32, 14);
    cout<<"Y LA VAS A ROMPER TODA";
    locate(25, 18);
    system("pause");
}

void mostrarResultados(int ronda, int lanzamiento, int tiradaFallida, int buncos, int puntaje) /// MOSTRAMOS LOS RESULTADOS
{
    locate(39, 6);
    cout<<"RONDA: "<<ronda<<endl;
    locate(35, 10);
    cout<<"LANZAMIENTOS: "<<lanzamiento<<endl;
    locate(33, 12);
    cout<<"TIRADAS FALLIDAS: "<<tiradaFallida<<endl;
    locate(37, 14);
    cout<<"BUNCOS: "<<buncos<<endl;
    locate(33, 18);
    cout<<"PUNTAJE ACUMULADO: "<<puntaje<<endl;
}

void cambioTurnoDosJugadores (int ronda, char nombre[25], char nombrecito[25], int puntajeNombre, int puntajeNombrecito, int buncoNombre, int buncoNombrecito) /// INFORMACION ENTRE TURNOS EN EL MODO DE DOS JUGADORES
{
    locate(38, 6);
    cout<<"RONDA: "<<ronda<<endl;
    locate(33, 8);
    cout<<"PROXIMO TURNO "<<strupr(nombrecito)<<endl;
    locate(34, 12);
    cout<<"PUNTAJE "<<nombre<<": "<<puntajeNombre<<endl;
    locate(38, 14);
    cout<<"BUNCOS: "<<buncoNombre<<endl;
    locate(34, 18);
    cout<<"PUNTAJE "<<strupr(nombrecito)<<": "<<puntajeNombrecito<<endl;
    locate(38, 20);
    cout<<"BUNCOS: "<<buncoNombrecito<<endl;
}

void mostrarGanador(char nombre[25], int lanzamientos, int tiradaFallida, int buncos, int puntajeFinal) /// MOSTRAMOS EL GANADOR EN EL MODO DE DOS JUGADORES
{
    locate(31, 6);
    cout<<"FELICITACIONES "<<nombre<<endl;
    locate(32, 10);
    cout<<"TOTAL LANZAMIENTOS: "<<lanzamientos<<endl;
    locate(30, 12);
    cout<<"TOTAL TIRADAS FALLIDAS: "<<tiradaFallida<<endl;
    locate(35, 14);
    cout<<"TOTAL BUNCOS: "<<buncos<<endl;
    locate(34, 18);
    cout<<"PUNTAJE FINAL: "<<puntajeFinal<<endl;
    locate(25, 22);
    system("pause");
    system("cls");
}

void mostrarEmpate(char nombre[25], char nombrecito[25], int puntajeFinalNombre, int puntajeFinalNombrecito, int buncosNombre, int buncosNombrecito) /// MOSTRAMOS LA INFORMACION CUANDO HAY UN EMPATE
{
    locate(32, 6);
    cout<<"HABEMUS EMPATE GENTES"<<endl;
    locate(32, 10);
    cout<<nombre<<endl;
    locate(46, 10);
    cout<<nombrecito<<endl;
    locate(32, 12);
    cout<<"PUNTOS: "<<puntajeFinalNombre<<endl;
    locate(46, 12);
    cout<<"PUNTOS: "<<puntajeFinalNombrecito<<endl;
    locate(32, 14);
    cout<<"BUNCOS: "<<buncosNombre<<endl;
    locate(46, 14);
    cout<<"BUNCOS: "<<buncosNombrecito<<endl;
    locate(34, 18);
    cout<<"A SEGUIR POR TODO"<<endl;
    locate(25, 22);
    system("pause");
    system("cls");
}

void mostrarRanking(char nombreMaximo[][25], int puntajeMaximo[], int buncoMaximo[], int tam) /// GENERA UN RANKING DE PERSONAS
{
    int i,j, posmay, auxPuntaje, auxBunco;
    char auxNombre[25][25];
    for(i=0; i<tam-1; i++)
    {
        posmay=i;
        for(j=i+1; j<tam; j++)
        {
            if(puntajeMaximo[j]>puntajeMaximo[posmay])
                posmay=j;
        }
        auxPuntaje=puntajeMaximo[i];
        puntajeMaximo[i]=puntajeMaximo[posmay];
        puntajeMaximo[posmay]=auxPuntaje;

        auxBunco=buncoMaximo[i];
        buncoMaximo[i]=buncoMaximo[posmay];
        buncoMaximo[posmay]=auxBunco;

        strcpy(auxNombre[0], nombreMaximo[i]);
        strcpy(nombreMaximo[i], nombreMaximo[posmay]);
        strcpy(nombreMaximo[posmay], auxNombre[0]);
    }
    int x = 25, y = 10;
    locate(25, 8);
    cout<<"NOMBRE";
    locate(40, 8);
    cout<<"PUNTOS";
    locate(55, 8);
    cout<<"BUNCOS";
    for(int i = 0; i < tam; i++)
    {
        locate(x, y);
        cout<<nombreMaximo[i];
        x+=15;
        locate(x, y);
        cout<<puntajeMaximo[i];
        x+=15;
        locate(x, y);
        cout<<buncoMaximo[i];
        x-=30;
        y+=2;
    }
}

void mostrarDatosTirada(char nombre[], int i, int buncos, int lanzamientos, int acuPuntaje1) /// MUESTRA LOS DATOS DE CADA TIRADA
{
    locate(35, 4);
    cout<<"DALO TODO "<<strupr(nombre);
    locate(16, 8);
    cout<<"RONDA "<<i + 1<<" | BUNCOS "<<buncos<<" | LANZAMIENTO "<<lanzamientos + 1<<" | PUNTAJE RONDA "<<acuPuntaje1<<endl;
    cout<<endl;
}

void mensajeResultado(char nombre[], int lanzamientos, int tiradaFallida, int buncos, int acuPuntaje1) /// MUESTRA RESULTADO FINAL EN EL MODO SIMULADO Y UN JUGADOR
{
    locate(31, 6);
    cout<<"PODIAS MUCHO MAS "<<nombre<<endl;
    locate(32, 10);
    cout<<"TOTAL LANZAMIENTOS: "<<lanzamientos<<endl;
    locate(30, 12);
    cout<<"TOTAL TIRADAS FALLIDAS: "<<tiradaFallida<<endl;
    locate(35, 14);
    cout<<"TOTAL BUNCOS: "<<buncos<<endl;
    locate(34, 18);
    cout<<"PUNTAJE FINAL: "<<acuPuntaje1<<endl;
    locate(25, 22);
    system("pause");
    system("cls");
}

void mensajeRonda(int i, char nombre[], int lanzamientos, int tiradaFallida, int buncos, int acuPuntaje1) /// INFORMA LO ACUMULADO ENTRE RONDA Y RONDA
{
    locate(34, 6);
    cout<<"RONDA: "<<i + 1<<" - "<<nombre<<endl;
    locate(35, 10);
    cout<<"LANZAMIENTOS: "<<lanzamientos<<endl;
    locate(33, 12);
    cout<<"TIRADAS FALLIDAS: "<<tiradaFallida<<endl;
    locate(37, 14);
    cout<<"BUNCOS: "<<buncos<<endl;
    locate(33, 18);
    cout<<"PUNTAJE ACUMULADO: "<<acuPuntaje1<<endl;
    cout<<endl<<endl;
    locate(25, 22);
    system("pause");
    system("cls");
}

void estructuraPrincipalC5() /// DIBUJA LA ESTRUCTURA DE LAS INSTRUCCIONES
{
    char instrucciones[] = "I N S T R U C C I O N E S";
    locate(30, 4);
    cout<<instrucciones;
    for (int i = 10; i < 75; i++)
    {
        locate(i, 2);
        printf("%c", 42);
        locate(i, 6);
        printf("%c", 42);
        locate(i, 126);
        printf("%c", 42);
    }

    for(int i = 2; i < 127; i++)
    {
        locate(10, i);
        printf("%c", 42);
        locate(74, i);
        printf("%c", 42);
    }
}

void dadoaux(int x,int y,int m, int n) /// DIBUJA LOS DADOS DE LAS INSTRUCCIONES
{
    /// HORIZONTAL
    for (int i =  x; i < y; i++)
    {
        locate(i, m);
        printf("%c", 205);
        locate(i, n);
        printf("%c", 205);
    }
    /// VERTICAL
    for (int i = m; i < n; i++)
    {
        locate(x, i);
        printf("%c", 186);
        locate(y, i);
        printf("%c", 186);
    }
    /// ESQUINAS
    locate(x, m);
    printf("%c", 201);
    locate(x, n);
    printf("%c", 200);
    locate(y, m);
    printf("%c", 187);
    locate(y, n);
    printf("%c", 188);
}

void instrucciones() /// MUESTRA LAS INSTRUCCIONES DEL JUEGO
{
    estructuraPrincipalC5();
    locate(12, 8);
    cout<<"Bunco es un juego que utiliza 3 dados, y que puede ser jugado ";
    locate(11, 10);
    cout<<" por uno o varios jugadores.";
    locate(12, 12);
    cout<<"El juego consiste en seis rondas, las cuales progresan ";
    locate(12, 14);
    cout<<"secuencialmente del uno al seis. Cada ronda comienza con un ";
    locate(12, 16);
    cout<<"lanzamiento de tres dados y un posterior analisis del puntaje ";
    locate(12, 18);
    cout<<"al que equivale la tirada. El jugador obtendra:";
    locate(12, 20);
    cout<<"- 21 PUNTOS si los tres dados coinciden con el numero de la ";
    locate(12, 22);
    cout<<"ronda que se esta jugando. A esta tirada se la denomina BUNCO";
    locate(39, 24);
    cout<<"RONDA 1";
    dadoaux(28,36,26,30);
    locate(32, 28);
    printf("%c", 254);
    dadoaux(38,46,26,30);
    locate(42, 28);
    printf("%c", 254);
    dadoaux(48,56,26,30);
    locate(52, 28);
    printf("%c", 254);
    locate(12, 32);
    cout<<"- 5 PUNTOS si los tres dados son IGUALES pero no coinciden ";
    locate(12, 34);
    cout<<"con la ronda en curso";
    locate(39, 36);
    cout<<"RONDA 2";
    dadoaux(28,36,38, 42);
    locate(30, 39);
    printf("%c", 254);
    locate(32, 40);
    printf("%c", 254);
    locate(34, 41);
    printf("%c", 254);
    dadoaux(38,46,38,42);
    locate(40, 39);
    printf("%c", 254);
    locate(42, 40);
    printf("%c", 254);
    locate(44, 41);
    printf("%c", 254);
    dadoaux(48,56,38,42);
    locate(50, 39);
    printf("%c", 254);
    locate(52, 40);
    printf("%c", 254);
    locate(54, 41);
    printf("%c", 254);
    locate(12, 44);
    cout<<"- 3 PUNTOS si la suma de los tres dados es DIVISIBLE POR 5";
    locate(39, 46);
    cout<<"RONDA 3";
    dadoaux(28,36,48,52);
    locate(30, 49);
    printf("%c", 254);
    locate(30, 51);
    printf("%c", 254);
    locate(32, 50);
    printf("%c", 254);
    locate(34, 49);
    printf("%c", 254);
    locate(34, 51);
    printf("%c", 254);
    dadoaux(38,46,48,52);
    locate(40, 49);
    printf("%c", 254);
    locate(40, 51);
    printf("%c", 254);
    locate(44, 49);
    printf("%c", 254);
    locate(44, 51);
    printf("%c", 254);
    dadoaux(48,56,48,52);
    locate(50, 49);
    printf("%c", 254);
    locate(50, 50);
    printf("%c", 254);
    locate(50, 51);
    printf("%c", 254);
    locate(54, 49);
    printf("%c", 254);
    locate(54, 50);
    printf("%c", 254);
    locate(54, 51);
    printf("%c", 254);
    locate(12, 54);
    cout<<"- 2 PUNTOS si los tres dados forman una ESCALERA";
    locate(39, 56);
    cout<<"RONDA 4";
    dadoaux(28,36,58,62);
    locate(30, 59);
    printf("%c", 254);
    locate(30, 61);
    printf("%c", 254);
    locate(32, 60);
    printf("%c", 254);
    locate(34, 59);
    printf("%c", 254);
    locate(34, 61);
    printf("%c", 254);
    dadoaux(38,46,58,62);
    locate(40, 59);
    printf("%c", 254);
    locate(42, 60);
    printf("%c", 254);
    locate(44, 61);
    printf("%c", 254);
    dadoaux(48,56,58,62);
    locate(50, 59);
    printf("%c", 254);
    locate(50, 61);
    printf("%c", 254);
    locate(54, 59);
    printf("%c", 254);
    locate(54, 61);
    printf("%c", 254);
    locate(12, 64);
    cout<<"- 1 PUNTO por cada dado que coincida con el numero de ronda";
    locate(39, 66);
    cout<<"RONDA 6";
    dadoaux(28,36,68,72);
    locate(30, 69);
    printf("%c", 254);
    locate(30, 70);
    printf("%c", 254);
    locate(30, 71);
    printf("%c", 254);
    locate(34, 69);
    printf("%c", 254);
    locate(34, 70);
    printf("%c", 254);
    locate(34, 71);
    printf("%c", 254);
    dadoaux(38,46,68,72);
    locate(40, 69);
    printf("%c", 254);
    locate(42, 70);
    printf("%c", 254);
    locate(44, 71);
    printf("%c", 254);
    dadoaux(48,56,68,72);
    locate(50, 69);
    printf("%c", 254);
    locate(50, 71);
    printf("%c", 254);
    locate(54, 69);
    printf("%c", 254);
    locate(54, 71);
    printf("%c", 254);
    locate(12, 74);
    cout<<"Mientras el jugador obtenga algun puntaje en la tirada, podra ";
    locate(12, 76);
    cout<<"seguir realizando lanzamientos. ";
    locate(12, 78);
    cout<<"Si realiza una tirada que no suma ningun puntaje, a la misma";
    locate(12, 80);
    cout<<"se la considerara tirada fallida.";
    locate(30, 82);
    cout<<"FINALIZACION DE CADA RONDA";
    locate(12, 84);
    cout<<"Modo 1 jugador:";
    locate(12, 86);
    cout<<"Cada ronda finaliza cuando el jugador llega a 21 o mas puntos.";
    locate(12, 88);
    cout<<"Al terminar las seis rondas, se le restara al puntaje final";
    locate(12, 90);
    cout<<"un total de dos puntos por cada tirada fallida.";
    locate(12, 92);
    cout<<"Modo 2 jugadores:";
    locate(12, 94);
    cout<<"Cada ronda finaliza cuando uno de los jugadores obtiene un";
    locate(12, 96);
    cout<<"puntaje mayor o igual a 21 puntos.";
    locate(12, 98);
    cout<<"Si en la primera tirada de una ronda el jugador 1 logra este ";
    locate(12, 100);
    cout<<"puntaje sin ninguna tirada fallida, el jugador 2 debe realizar";
    locate(12, 102);
    cout<<"lanzamientos hasta cumplir con la condición de finalizacion de";
    locate(12, 104);
    cout<<"ronda o realizar una tirada fallida.";
    locate(30, 106);
    cout<<"FINALIZACION DEL JUEGO";
    locate(12, 108);
    cout<<"El juego termina al concluir las seis rondas.";
    locate(12, 110);
    cout<<"Ganador: ";
    locate(12, 112);
    cout<<"El ganador de la partida es aquel jugador que obtenga el ";
    locate(12, 114);
    cout<<"puntaje más alto. En caso de paridad, gana el que tenga mayor";
    locate(12, 116);
    cout<<"cantidad de Buncos.";
    locate(12, 118);
    cout<<"Empate: ";
    locate(12, 120);
    cout<<"Se dará un empate solamente si ambos jugadores obtienen el";
    locate(12, 122);
    cout<<"mismo puntaje y la misma cantidad de Buncos al finalizar";
    locate(12, 124);
    cout<<"las rondas.";
    locate(10, 1);
    system("pause");
    system("cls");
}

#endif /// FUNCIONESESPECIFICAS_H_INCLUDED
