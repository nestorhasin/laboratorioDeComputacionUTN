#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <cstring>

using namespace std;

#include "funcionesGenerales.h"
#include "funcionesEspecificas.h"
#include "rlutil.h"

int main()
{
    int opc, dados[3], puntaje, aux;
    int acuPuntaje1[6] = {0}, acuPuntaje2[6] = {0}, puntajeFinal[2];
    int tiradaFallida[2] = {0}, buncos[2] = {0}, lanzamientos[2] = {0}, totalLanzamientos[2] = {0}, totalTiradaFallida[2] = {0};
    char ranking[] = "R A N K I N G";
    const int tam = 3;
    char nombre[25], nombrecito[25];
    int indicePuntajeMaximo = 0;
    char nombreMaximo[25][25];
    int puntajeMaximo[25];
    int buncoMaximo[25];

    do
    {
        opc = menu();

        switch(opc)
        {
        case 1:
            buncos[0] = 0, buncos[1] = 0, acuPuntaje1[1] = 0, lanzamientos[1] = 0;
            estructuraNombre();
            dameNombre(nombre, 25);
            system("cls");

            for(int i = 0; i < 6; i++)
            {
                lanzamientos[0] = 0, acuPuntaje1[0] = 0, tiradaFallida[0] = 0;

                while(acuPuntaje1[0] < 21)
                {

                    estructuraPrincipal();
                    mostrarDatosTirada(nombre, i, buncos[0], lanzamientos[0], acuPuntaje1[0]);
                    cargarAleatorio(dados, tam, 6);
                    dadosGraficos(dados, tam);
                    cout<<endl;
                    puntaje = puntos(dados, tam, (i + 1));
                    acuPuntaje1[0] += puntaje;
                    lanzamientos[0]++;
                    lanzamientos[1]++; /// ACUMULA EL TOTAL DE LANZAMIENTOS PARA MOSTRARLO AL FINAL

                    if(puntaje == 0)
                    {
                        tiradaFallida[0]++;
                        tiradaFallida[1]++;
                        fflush(stdin);
                    }
                    else if(puntaje == 21)
                    {
                        buncos[0]++;
                        buncos[1]++;
                        fflush(stdin);
                    }
                    else
                    {
                        fflush(stdin);
                    }
                    locate(16, 20);
                    system("pause");
                    system("cls");
                }
                acuPuntaje1[1] += acuPuntaje1[0];
                estructuraResultados();
                mostrarResultados(i + 1, lanzamientos[0], tiradaFallida[0], buncos[0], acuPuntaje1[0]);
                cout<<endl<<endl;
                locate(25, 22);
                system("pause");
                system("cls");
            }
            acuPuntaje1[1] = acuPuntaje1[1] - (tiradaFallida[1] * 2);
            strcpy(nombreMaximo[indicePuntajeMaximo],nombre);
            puntajeMaximo[indicePuntajeMaximo] = acuPuntaje1[1];
            buncoMaximo[indicePuntajeMaximo] = buncos[1];
            indicePuntajeMaximo++;
            estructuraResultados();
            mensajeResultado(nombre, lanzamientos[1], tiradaFallida[1], buncos[1], acuPuntaje1[1]);
            break;
        case 2:
            puntajeFinal[0] = 0, puntajeFinal[1] = 0;
            aux = 0;
            buncos[0] = 0, buncos[1] = 0;
            estructuraNombre(); /// JUGADOR 1
            dameNombre(nombre, 25);
            system("cls");
            estructuraNombre(); /// JUGADOR 2
            dameContrincante(nombrecito, 25);
            system("cls");
            for(int i = 0; i < 6; i++)
            {
                bool aviso1 = false, estrucResul = false;
                acuPuntaje1[i] = 0, acuPuntaje2[i] = 0, lanzamientos[0] = 0, lanzamientos[1] = 0, tiradaFallida[0] = 0, tiradaFallida[1] = 0;
                while(acuPuntaje1[i] < 21 && acuPuntaje2[i] < 21)
                {
                    if(aviso1 == false && estrucResul == false)
                    {
                        estructuraPrincipal();
                        mostrarDatosTirada(nombre, i, buncos[0], lanzamientos[0], acuPuntaje1[i]);
                        cargarAleatorio(dados, tam, 6);
                        dadosGraficos(dados, tam);
                        cout<<endl;
                        puntaje = puntos(dados, tam, (i + 1));
                        acuPuntaje1[i] += puntaje;
                        lanzamientos[0]++;
                        if(puntaje == 0)
                        {
                            tiradaFallida[0]++;
                            aviso1 = true;
                            estrucResul = true;
                            fflush(stdin);
                        }
                        else if(puntaje == 21)
                        {
                            buncos[0]++;
                            fflush(stdin);
                        }
                        else
                        {
                            fflush(stdin);
                        }
                        locate(16, 20);
                        system("pause");
                        system("cls");
                        if(acuPuntaje1[i] >= 21 && lanzamientos[1] == 0)
                        {
                            aviso1 = true;
                            estrucResul = true;
                            aux = acuPuntaje1[i];
                            acuPuntaje1[i] = 0;
                            fflush(stdin);
                        }

                        if(estrucResul == true)
                        {
                            estructuraResultadosDos();
                            if(aux != 0)
                            {
                                cambioTurnoDosJugadores(i + 1, nombre, nombrecito, aux, acuPuntaje2[i], buncos[0], buncos[1]);
                            }
                            else
                            {
                                cambioTurnoDosJugadores(i + 1, nombre, nombrecito, acuPuntaje1[i], acuPuntaje2[i], buncos[0], buncos[1]);
                            }
                            cout<<endl<<endl;
                            locate(25, 24);
                            system("pause");
                            system("cls");
                        }
                    }
                    else
                    {
                        estructuraPrincipal();
                        mostrarDatosTirada(nombrecito, i, buncos[1], lanzamientos[1], acuPuntaje2[i]);
                        cargarAleatorio(dados, tam, 6);
                        dadosGraficos(dados, tam);
                        cout<<endl;
                        puntaje = puntos(dados, tam, (i + 1));
                        acuPuntaje2[i] += puntaje;
                        lanzamientos[1]++;
                        if(puntaje == 0)
                        {
                            tiradaFallida[1]++;
                            aviso1 = false;
                            estrucResul = false;
                            fflush(stdin);
                        }
                        else if(puntaje == 21)
                        {
                            buncos[1]++;
                            fflush(stdin);
                        }
                        else
                        {
                            fflush(stdin);
                        }
                        locate(16, 20);
                        system("pause");
                        system("cls");

                        if ((puntaje == 0 || acuPuntaje2[i] >= 21) && aux != 0)
                        {
                            acuPuntaje1[i] = aux;
                        }

                        if(estrucResul == false)
                        {
                            estructuraResultadosDos();
                            cambioTurnoDosJugadores(i + 1, nombrecito, nombre, acuPuntaje2[i], acuPuntaje1[i], buncos[1], buncos[0]);
                            cout<<endl<<endl;
                            locate(25, 24);
                            system("pause");
                            system("cls");
                        }
                    }
                }
                estructuraResultados();
                mostrarResultados(i + 1, lanzamientos[0], tiradaFallida[0], buncos[0], acuPuntaje1[i]);
                mensajeRonda(i, nombre, lanzamientos[0], tiradaFallida[0], buncos[0], acuPuntaje1[i]);
                estructuraResultados();
                mensajeRonda(i, nombrecito, lanzamientos[1], tiradaFallida[1], buncos[1], acuPuntaje2[i]);
                totalLanzamientos[0] += lanzamientos[0];
                totalLanzamientos[1] += lanzamientos[1];
                totalTiradaFallida[0] += tiradaFallida[0];
                totalTiradaFallida[1] += tiradaFallida[1];
            }
            puntajeFinal[0] = acumularVector(acuPuntaje1, 6);
            puntajeFinal[1] = acumularVector(acuPuntaje2, 6);
            strcpy(nombreMaximo[indicePuntajeMaximo],nombre);
            puntajeMaximo[indicePuntajeMaximo] = puntajeFinal[0];
            buncoMaximo[indicePuntajeMaximo] = buncos[0];
            indicePuntajeMaximo++;
            strcpy(nombreMaximo[indicePuntajeMaximo],nombrecito);
            puntajeMaximo[indicePuntajeMaximo] = puntajeFinal[1];
            buncoMaximo[indicePuntajeMaximo] = buncos[1];
            indicePuntajeMaximo++;
            if (puntajeFinal[0] > puntajeFinal[1])
            {
                estructuraResultados();
                mostrarGanador(nombre, totalLanzamientos[0], totalTiradaFallida[0], buncos[0], puntajeFinal[0]);
            }
            else if(puntajeFinal[0] == puntajeFinal[1] && buncos[0] > buncos[1])
            {
                estructuraResultados();
                mostrarGanador(nombre, totalLanzamientos[0], totalTiradaFallida[0], buncos[0], puntajeFinal[0]);
            }
            else if(puntajeFinal[0] == puntajeFinal[1] && buncos[0] == buncos[1])
            {
                estructuraResultados();
                mostrarEmpate(nombre, nombrecito, puntajeFinal[0], puntajeFinal[1], buncos[0], buncos[1]);
            }
            else
            {
                estructuraResultados();
                mostrarGanador(nombrecito, totalLanzamientos[1], totalTiradaFallida[1], buncos[1], puntajeFinal[1]);
            }
            break;
        case 3:
            if(indicePuntajeMaximo == 0)
            {
                estructuraResultados();
                locate(32, 6);
                cout<<"LA BESTIA DEL PUNTAJE"<<endl;
                locate(35, 10);
                cout<<"AQUI REVELAREMOS"<<endl;
                locate(38, 12);
                cout<<"SU NOMBRE"<<endl;
                locate(31, 14);
                cout<<"TE GUSTARIA VER EL TUYO?"<<endl;
                locate(32, 18);
                cout<<"PERSEVERA Y TRIUNFARAS"<<endl;
                locate(25, 22);
                system("pause");
                system("cls");
            }
            else
            {
                estructuraResultados();
                mayorPuntuacion(nombreMaximo, puntajeMaximo, buncoMaximo, indicePuntajeMaximo);
                locate(25, 22);
                system("pause");
                system("cls");
                estructuraPrincipal();
                locate(35, 4);
                for(int i = 0; i < 14; i++)
                {
                    cout<<ranking[i];
                    Sleep(50);
                }
                mostrarRanking(nombreMaximo, puntajeMaximo, buncoMaximo, indicePuntajeMaximo);
                locate(25, 20);
                system("pause");
                system("cls");
            }
            break;
        case 4:
            estructuraNombre();
            dameNombre(nombre, 25);
            system("cls");
            estructuraNombre();
            indicacionesSimulado();
            system("cls");
            buncos[1] = 0, buncos[0] = 0, lanzamientos[1] = 0, acuPuntaje1[1] = 0, tiradaFallida[1] = 0;
            for(int i = 0; i < 6; i++)
            {
                lanzamientos[0] = 0, acuPuntaje1[0] = 0, tiradaFallida[0] = 0;
                while(acuPuntaje1[0] < 21)
                {
                    estructuraPrincipal();
                    mostrarDatosTirada(nombre, i, buncos[0], lanzamientos[0], acuPuntaje1[0]);
                    int x = 32;
                    for(int z = 0; z < 3; z++)
                    {
                        do
                        {
                            locate(x, 12);
                            cin>>dados[z];
                        }
                        while(dados[z]<1 || dados[z]>6);
                        x+=10;
                    }
                    dadosGraficos(dados, tam);
                    cout<<endl;
                    puntaje = puntos(dados, tam, (i + 1));
                    acuPuntaje1[0] += puntaje;
                    lanzamientos[0]++;
                    lanzamientos[1]++; /// ACUMULA EL TOTAL DE LANZAMIENTOS PARA MOSTRARLO AL FINAL
                    if(puntaje == 0)
                    {
                        tiradaFallida[0]++;
                        tiradaFallida[1]++;
                        fflush(stdin);
                    }
                    else if(puntaje == 21)
                    {
                        buncos[0]++;
                        buncos[1]++;
                        fflush(stdin);
                    }
                    else
                    {
                        fflush(stdin);
                    }
                    locate(16, 20);
                    system("pause");
                    system("cls");
                }
                acuPuntaje1[1] += acuPuntaje1[0];

                estructuraResultados();
                mostrarResultados(i + 1, lanzamientos[0], tiradaFallida[0], buncos[0], acuPuntaje1[0]);
                cout<<endl<<endl;
                locate(25, 22);
                system("pause");
                system("cls");
            }
            acuPuntaje1[1] = acuPuntaje1[1] - (tiradaFallida[1] * 2);
            strcpy(nombreMaximo[indicePuntajeMaximo],nombre);
            puntajeMaximo[indicePuntajeMaximo] = acuPuntaje1[1];
            buncoMaximo[indicePuntajeMaximo] = buncos[1];
            indicePuntajeMaximo++;
            estructuraResultados();
            mensajeResultado(nombre, lanzamientos[1], tiradaFallida[1], buncos[1], acuPuntaje1[1]);
            break;
        case 5:
            instrucciones(); /// TODO EL CASE 5
            break;
        case 0:
            break;
        default:
            locate(10,1);
            cout<<"Opcion Invalida (vuelva a ingresar una opcion)"<<endl;
        }
    }
    while(opc!=0);
    return 0;
}
