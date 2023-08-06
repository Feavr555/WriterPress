#include <iostream>
#include <stdio.h>
#include <fstream>

void creacionCarpeta(std::string proyecto);
void copiaArchivos(std::string ubicacion);
void seleccionPlantilla(std::string proyecto,int plantilla);
void indexHTML(std::string proyecto,int plantilla);

int main()
{
    //Inicialización de variables y bienvenida del proyecto
    std::string tipoRecurso, Archivo, ubicacionDestino, proyecto;
    int plantilla;
    printf("Bienvenido a Writerpress\nNombre de proyecto: ");
    std::cin >> proyecto;
    creacionCarpeta(proyecto);
    system("cls");
    //Selección de la plantilla css para el proyecto del usuario
    std::string direccion=proyecto+"/index.html";
    printf("Elige una plantilla para la web:\n");
    printf("1_Texto en el medio, fondo de flores de lis y fondo veis.\n");
    printf("2_Texto en el medio, fondo salmon y fondo del medio verde gris.\n");
    printf("3_Texto a un lado y fondo verde claro.");
    printf("\nPlantilla: ");
    std::cin >> plantilla;
    seleccionPlantilla(proyecto,plantilla);
    //Construcción del texto de la página
    indexHTML(proyecto,plantilla);
    system("pause");
    return 0;
}
