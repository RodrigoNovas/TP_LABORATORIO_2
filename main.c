#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Empleados.h"
#include "Herramientas.h"
#define MAXEMP 1000
#define CHAR 51

int main()
{
    int opcion,sector,flag=0,id=0,findEmployeeAux,idAux,contEmp=0,idbaja,opcionOrd,opcionModif,validaNum;
    char name[51], lastName[51];
    float salary;
    employee emp[MAXEMP];
    do{
        printf("\tMenu\n");
        printf("-----------------------BIENVENIDO----------------------------- \n");
        printf("1- Alta empleados\n");
        printf("2- Modificar empleados (debera tener empleados cargados)\n");
        printf("3- Baja empleados (debera tener empleados cargados)\n");
        printf("4- Imprimir empleados (debera tener empleados cargados/ NOMBRE Y APELLIDO APARECERAN EN MAYUSCULAS)\n");
        printf("5- Salir\n");
        printf("--------------------------------------------------------------- \n");
        fflush(stdin);
        scanf("%d",&opcion);
         if (!isValidMenu(opcion, 1, 5))
                {
                    printf("El numero ingresado no es valido.\n");
                    opcion = 0;
                }
        switch(opcion){
            case 1:
                system("cls");
                if(flag==0){
                    if(initEmployee(emp,MAXEMP)==0){
                        initEmployee(emp,MAXEMP);
                        flag=1;
                    }
                }
                if(getFreeSpace(emp,MAXEMP)!=-1){
                    id++;
                    contEmp++;
                }
                else{
                    printf("No hay espacio para agregar empleados!\n");
                    break;
                }
                utn_getStringAvanzado(name,"Ingrese nombre del empleado: ","El nombre debe ser solo letras!!!!!!\n",CHAR,2);
                utn_getStringAvanzado(lastName,"Ingrese apellido del empleado: ","El apellido debe ser solo letras!!!!!\n",CHAR,2);
                utn_getFlotante(&salary,"Ingrese salario del empleado: ","Ingrese salario positivo y que no exceda 1000000000!!!!!!\n",1,1000000000,2);
                utn_getEntero(&sector,"Ingrese sector del empleado: ","Ingrese numeros positivos entre 1 y 200!!!!!!!!!!\n",1,200,2);
                addEmployee(emp,MAXEMP, name, lastName,salary,sector,id);
                system("cls");
                printf("Empleado agregado correctamente\n");
                system("PAUSE");
                system("cls");
                break;
            case 2:
                system("cls");

                if(firstEmployee(flag)!=0){ //si no es la primera vez
                    printEmployee(emp,MAXEMP);
                    utn_getEntero(&idAux,"Ingrese ID a modificar: ","ERROR! Ingrese numero entre 1 y 1000\n",1,1000,2);
                    findEmployeeAux=findEmployeeById(emp,MAXEMP,idAux);
                    if(findEmployeeAux!=-1){ //si lo encontro
                        utn_getEntero(&opcionModif,"Ingrese valor que desea modificar\n1 para nombre, 2 para apellido, 3 para salario, 4 para sector: ",
                                      "ERROR! Ingrese numero entre 1 y 5\n",1,5,2);
                        switch(opcionModif){
                            case 1:
                                utn_getStringAvanzado(name,"Ingrese nombre: ",
                                                      "ERROR! El nombre debe ser solo letras\n",CHAR,2);
                                modifyEmployee(emp,MAXEMP, name, lastName, salary,sector,findEmployeeAux,opcionModif);
                            break;
                            case 2:
                                utn_getStringAvanzado(lastName,"Ingrese apellido: ",
                                                      "ERROR! El apellido debe ser solo letras\n",CHAR,2);
                                modifyEmployee(emp,MAXEMP, name, lastName, salary,sector,findEmployeeAux,opcionModif);
                            break;
                            case 3:
                                utn_getFlotante(&salary,"Ingrese salario: ",
                                                "ERROR! Ingrese salario positivo\n",1,100000,2);
                                modifyEmployee(emp,MAXEMP, name, lastName, salary,sector,findEmployeeAux,opcionModif);
                            break;
                            case 4:
                                utn_getEntero(&sector,"Ingrese sector: ",
                                              "ERROR! Ingrese numeros entre 1 y 200\n",1,200,2);
                                modifyEmployee(emp,MAXEMP, name, lastName, salary,sector,findEmployeeAux,opcionModif);
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

                if(firstEmployee(flag)!=0){ //si no es la primera vez

                        printEmployee(emp,MAXEMP);
                        utn_getEntero(&idbaja,"Ingrese ID a eliminar: ",
                                      "ERROR! Ingrese numero entre 1 y 1000\n",1,1000,2);
                findEmployeeAux=findEmployeeById(emp,MAXEMP,idbaja);
                if(findEmployeeAux!=-1){
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
                if(firstEmployee(flag)!=0){ //si no es la primera vez
                validaNum=utn_getEntero(&opcionOrd,"Ingrese el orden de ordenamiento, 1 para ascendente y 0 para descendente: ",
                                        "ERROR! Ingrese numero 0 o 1\n",0,1,2);
                switch(opcionOrd){
                    case 1:
                        if(validaNum!=-1){
                            toUpperLastNameAndNameClients(emp, MAXEMP);
                            sortEmployee(emp,MAXEMP,name,lastName,opcionOrd);
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
                        toUpperLastNameAndNameClients(emp, MAXEMP);
                        sortEmployee(emp,MAXEMP,name,lastName,opcionOrd);
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
    }while(opcion!=5);

    return 0;
}
