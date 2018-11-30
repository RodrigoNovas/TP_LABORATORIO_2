#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Empleados.h"
#include "Herramientas.h"
#define MAXEMP 1000
#define CHAR 51

int main()
{   int option;
    int Empleadito=0;
    int bandera=0;
    int id=0;
    int sk,encontrarAux,idAux,idbaja,Ord,Modif,NumeroValidar;
    char nombre[51],apellido[51];
    float salario;
    employee emp[MAXEMP];
    do{
         option= menuoption();
         if (!isValidMenu(option, 1, 5))
                {
                    printf("El numero ingresado no es valido.\n");
                    option = 0;
                }
        switch(option){
            case 1:
                system("cls");
                if(bandera==0){
                    if(initEmployee(emp,MAXEMP)==0){
                        initEmployee(emp,MAXEMP);
                       bandera=1;
                    }
                }
                if(getFreeSpace(emp,MAXEMP)!=-1){
                    id++;
                    Empleadito++;
                }
                else{
                    printf("No hay espacio para agregar empleados!\n");
                    break;
                }
                utn_getStringAvanzado(nombre,"Ingrese nombre del empleado: ","El nombre debe ser solo letras!!!!!!\n",CHAR,2);
                utn_getStringAvanzado(apellido,"Ingrese apellido del empleado: ","El apellido debe ser solo letras!!!!!\n",CHAR,2);
                utn_getFlotante(&salario,"Ingrese salario del empleado: ","Ingrese salario positivo y que no exceda 1000000000!!!!!!\n",1,1000000000,2);
                utn_getEntero(&sk,"Ingrese sector del empleado: ","Ingrese numeros positivos entre 1 y 200!!!!!!!!!!\n",1,200,2);
                addEmployee(emp,MAXEMP, nombre, apellido,salario,sk,id);
                system("cls");
                printf("Empleado agregado correctamente\n");
                system("PAUSE");
                system("cls");
                break;
            case 2:
                system("cls");

                if(firstEmployee(bandera)!=0){ //si no es la primera vez
                    printEmployee(emp,MAXEMP);
                    utn_getEntero(&idAux,"Ingrese ID a modificar: ","ERROR! Ingrese numero entre 1 y 1000\n",1,1000,2);
                    encontrarAux=findEmployeeById(emp,MAXEMP,idAux);
                    if(encontrarAux!=-1){ //si lo encontro
                        printf("1- Ingrese Nombre\n");
                        printf("2- Ingrese apellido\n");
                        printf("3- Ingrese Salario\n");
                        printf("4- Ingrese Sector\n\n");
                        utn_getEntero(&Modif,"Ingrese valor que desea modificar\n\n",
                                      "ERROR! Ingrese numero entre 1 y 5\n",1,5,2);
                        switch(Modif){
                            case 1:
                                utn_getStringAvanzado(nombre,"Ingrese nombre: ",
                                                      "ERROR! El nombre debe ser solo letras\n",CHAR,2);
                                modifyEmployee(emp,MAXEMP, nombre, apellido, salario,sk,encontrarAux,Modif);
                            break;
                            case 2:
                                utn_getStringAvanzado(apellido,"Ingrese apellido: ",
                                                      "ERROR! El apellido debe ser solo letras\n",CHAR,2);
                                modifyEmployee(emp,MAXEMP, nombre, apellido, salario,sk,encontrarAux,Modif);
                            break;
                            case 3:
                                utn_getFlotante(&salario,"Ingrese salario: ",
                                                "ERROR! Ingrese salario positivo\n",1,100000,2);
                                modifyEmployee(emp,MAXEMP, nombre, apellido, salario,sk,encontrarAux,Modif);
                            break;
                            case 4:
                                utn_getEntero(&sk,"Ingrese sector: ",
                                              "ERROR! Ingrese numeros entre 1 y 200\n",1,200,2);
                                modifyEmployee(emp,MAXEMP, nombre, apellido, salario,sk,encontrarAux,Modif);
                            break;
                            system("cls");
                            printf("Empleado modificado correctamente\n");
                        }
                    }
                    else{
                        system("cls");
                        printf("No se encuentra el ID\n");
                    }
                }
                break;
            case 3:
                system("cls");

                if(firstEmployee(bandera)!=0){ //si no es la primera vez

                        printEmployee(emp,MAXEMP);
                        utn_getEntero(&idbaja,"Ingrese ID a eliminar: ",
                                      "ERROR! Ingrese numero entre 1 y 1000\n",1,1000,2);
                encontrarAux=findEmployeeById(emp,MAXEMP,idbaja);
                if(encontrarAux!=-1){
                        removeEmployee(emp,MAXEMP,idbaja);

                system("cls");
                printf("Empleado eliminado correctamente\n");
                system("PAUSE");
                system("cls");
                }
                else{
                        system("cls");
                        printf("No se encuentra el ID\n");
                    }}
                break;
            case 4:
                system("cls");
                if(firstEmployee(bandera)!=0){ //si no es la primera vez
                NumeroValidar=utn_getEntero(&Ord,"Ingrese el orden de ordenamiento, 1 para ascendente y 0 para descendente: ",
                                        "ERROR! Ingrese numero 0 o 1\n",0,1,2);
                switch(Ord){
                    case 1:
                        if(NumeroValidar!=-1){
                            Touperralizar(emp, MAXEMP);
                            sortEmployee(emp,MAXEMP,nombre,apellido,Ord);
                            printEmployee(emp,MAXEMP);
                            if(totalSalary(emp,MAXEMP)!=-1)
                                printf("El total de salarios es: %.02f\n",totalSalary(emp,MAXEMP));
                            if(averageSalary(emp,MAXEMP)!=-1)
                                printf("El promedio de salarios es: %d\n",averageSalary(emp,MAXEMP));
                            if(excSalary(emp,MAXEMP)!=-1)
                            printf("La cantidad de empleados que superan el salario promedio es de: %d\n",excSalary(emp,MAXEMP));
                            printf("___________________________________________________________________\n");
                        }
                    break;
                    case 0:
                        Touperralizar(emp, CHAR);
                        sortEmployee(emp,MAXEMP,nombre,apellido,Ord);
                        printEmployee(emp,MAXEMP);
                        if(totalSalary(emp,MAXEMP)!=-1)
                            printf("El total de salarios es: %.02f\n",totalSalary(emp,MAXEMP));
                        if(averageSalary(emp,MAXEMP)!=-1)
                            printf("El promedio de salarios es: %d\n",averageSalary(emp,MAXEMP));
                        if(excSalary(emp,MAXEMP)!=-1)
                        printf("La cantidad de empleados que superan el salario promedio es de: %d\n",excSalary(emp,MAXEMP));
                        printf("___________________________________________________________________\n");
                        break;
                    }
                }
                break;
            }
    }while(option!=5);

    return 0;
}
