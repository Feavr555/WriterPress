#include <iostream>
#include <fstream>
#include <stdio.h>
#include <cstdio>

void copiaArchivos(std::string ubicacion){
    std::string archivo=ubicacion+"/recursos/js/botones.js";
    std::ifstream copyFile("recursos/js/botones.js");
    std::string linea,texto;
    while(getline(copyFile,linea)){
        texto=texto+linea+"\n";
    }
    copyFile.close();
    std::ofstream pasteFile(archivo);
    pasteFile << texto;
    pasteFile.close();
}

void creacionCarpeta(std::string proyecto){
    //Creaci�n de la carpeta del proyecto
    std::string nombreProyecto=proyecto;
    std::string usuario=getenv("USERNAME");
    std::string createFollow="mkdir "+nombreProyecto;
    const char* comando=createFollow.c_str();
    system(comando);
    std::string ubicacion=nombreProyecto+"/index.html";
    std::ofstream inicio(ubicacion);
    inicio.close();
    //Creaci�n de carpeta de recursos
    ubicacion=proyecto;
    createFollow="cd "+ubicacion+" && mkdir recursos";
    const char* comando2=createFollow.c_str();
    system(comando2);
    //Carpeta del aspecto del proyecto
    createFollow="cd "+ubicacion+"/recursos && mkdir css";
    const char* comando3=createFollow.c_str();
    system(comando3);
    //Carpeta del dinamismo del proyecto
    createFollow="cd "+ubicacion+"/recursos && mkdir js";
    const char* comando4=createFollow.c_str();
    system(comando4);
}

void seleccionPlantilla(std::string proyecto,int plantilla){
    //Funci�n para elegir el archivo .css para el proyecto del usuario
    int css=plantilla;
    std::string linea;
    std::string texto;
    std::string direccion_1=proyecto+"/recursos/css/plantilla_1.css";
    std::string direccion_2=proyecto+"/recursos/css/plantilla_2.css";
    std::string direccion_3=proyecto+"/recursos/css/plantilla_3.css";
    std::string direccion2=proyecto+"/recursos/css/fondo.jpg";
    if(css==1){
        //copiar y pegar estilo en proyecto
        std::ifstream estilo("recursos/css/plantilla_1.css");
        while(getline(estilo,linea)){
            texto=texto+linea+"\n";
        }
        std::ofstream plantillas(direccion_1);
        plantillas << texto;
        plantillas.close();
        //copiar y pegar fondo en proyecto
        std::string originalJPG="recursos/css/fondo.jpg";
        std::string copiaJPG=direccion2;
        std::ifstream inputFile(originalJPG, std::ios::binary);
        std::ofstream outputFile(copiaJPG, std::ios::binary);
        outputFile << inputFile.rdbuf();
        inputFile.close();
        outputFile.close();
    }else if(css==2){
        std::ifstream estilo("recursos/css/plantilla_2.css");
        while(getline(estilo,linea)){
            texto=texto+linea+"\n";
        }
        std::ofstream plantillas(direccion_2);
        plantillas << texto;
        plantillas.close();
    }else if(css==3){
        std::ifstream estilo("recursos/css/plantilla_3.css");
        while(getline(estilo,linea)){
            texto=texto+linea+"\n";
        }
        std::ofstream plantillas(direccion_3);
        plantillas << texto;
        plantillas.close();
    }else{
        printf("Plantilla inexistente.");
    }
}

void indexHTML(std::string proyecto, int plantilla){
    //variables de la funcion
    std::string titulo;
    std::string ubicacion=proyecto;
    std::string direccion=proyecto+"/index.html";
    std::ofstream index(direccion);
    //comienzo del archivo .html
    index << "<!DOCTYPE html>\n<html>\n<head>\n<title>";
    //titulo de pesta�a
    printf("Tras el enter, inserte FIN para finalizar titulo.\n");
    printf("Titulo de pestana: ");
    bool tit=false;
    while(!tit){
        std::cin >> titulo;
        if(titulo=="FIN"){
            tit=true;
        }else{
            index << titulo << " ";
        }
    }
    //titulo principal de la etiqueta <h1>
    index << "</title>\n";
    //inserci�n de la plantilla seleccionada
    if(plantilla==1){
        index << "<link href='recursos/css/plantilla_1.css' rel='stylesheet'>\n";
    }else if(plantilla==2){
        index << "<link href='recursos/css/plantilla_2.css' rel='stylesheet'>\n";
    }else if(plantilla==3){
        index << "<link href='recursos/css/plantilla_3.css' rel='stylesheet'>\n";
    }
    //continuamos
    index << "</head>\n<body id='cuerpo'>\n<nav id='nave'>\n";
    index << "<h1 id='titulo'>";
    tit=false;
    printf("Titulo web: ");
    while(!tit){

        std::cin >> titulo;
        if(titulo=="FIN"){
            tit=true;
        }else{
            index << titulo << " ";
        }
    }
    //Parrafo lateral izquierdo
    index << "</h1>\n<section id='lateral'>\n<p id='parrafo'>";
    tit=false;
    printf("Parrafo lateral izquierdo: ");
    while(!tit){
        std::cin >> titulo;
        if(titulo=="FIN"){
            tit=true;
        }else{
            index << titulo << " ";
        }
    }
    index << "</p>\n";
    //segundo parrafo
    //Botones
    printf("Insercion de botones. [1=si/2=no] ");
    int seleccionBTN=0;
    std::cin >> seleccionBTN;
    if(seleccionBTN==1){
        printf("Funcion del boton:\n");
        printf("1_Cambiar fondo a gris.\n");
        printf("2_Cambiar boton.\n");
        printf("3_Senal del boton.\n");
        printf("Boton: ");
        int btn1=0;
        std::cin >> btn1;
        if(btn1==1){
            index << "<button id='btn1' onclick='cambiarFondo();'>";
        }else if(btn1==2){
            index << "<button id='btn1' onclick='cambiarBtn();'>";
        }else if(btn1==3){
            index << "<button id='btn1' onclick='ejecuta();'>";
        }else{printf("Inv�lido.");}
        printf("Texto del boton: ");
        std::string txtBTN;
        std::cin >> txtBTN;
        index << txtBTN << "</button>\n";
    }else if(seleccionBTN==2){
    }else{}
    //finalizacion
    index << "</section>\n";
    index << "</nav>\n</body>\n";
    //JavaScript seleccionado
    if(seleccionBTN==1){
        index << "<script src='recursos/js/botones.js'></script>\n";
        copiaArchivos(ubicacion);
    }else if(seleccionBTN==2){
        printf("De acuerdo.");
    }else{}

    //Cierre
    index << "\n</html>\n";
    index.close();
}
