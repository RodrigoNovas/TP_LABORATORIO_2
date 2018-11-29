#ifndef EMPLEADOS_H_INCLUDED
#define EMPLEADOS_H_INCLUDED

typedef struct{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}employee;
/** \brief Indica que todas las posiciones del array estan libres,
 * Esta funcion pone la bandera (isEmpty) en TRUE en todas
 * las posiciones del array.
 * \param emp* puntero al array de empleados
 * \param CANT Entero del total del array
 * \return int Retorna (-1) si hay error, (0) si no hay error
 */
int initEmployee(employee*,int);
/** \brief Obtiene un espacio libre del array
 * \param emp* puntero al array de empleados
 * \param CANT Entero del total del array
 * \return int Retorna (-1) si hay error, la posicion del array si no hay error.
 */
int getFreeSpace(employee*,int);
/** \brief Da de alta el empleado en una posicion libre del array
 * \param emp* puntero al array de empleados
 * \param CANT Entero del total del array
 * \param name char auxiliar, nombre del empleado
 * \param lastName char auxiliar, apellido del empleado
 * \param salary float auxiliar, salario del empleado
 * \param id int auxiliar, id del empleado
 * \return int Retorna (-1) si hay error, (0) si no hay error.
 */
int addEmployee(employee*,int,char*,char*,float,int,int);
/** \brief Busca el empleado por id
 * \param emp* puntero al array de empleados
 * \param CANT Entero del total del array
 * \param id int auxiliar, id a ser buscado en el array
 * \return int Retorna (-1) si hay error o si el id no se encontro,
 * la posicion del array si no hay error.
 */
int findEmployeeById(employee*,int,int id);
/** \brief Elimina el empleado buscandolo por id
 * \param emp* puntero al array de empleados
 * \param CANT Entero del total del array
 * \param id int auxiliar, id a ser eliminado en el array
 * \return int Retorna (-1) si no se encuentra el id
 * o no se elimina el empleado, 0 si se elimina correctamente
 */
int removeEmployee(employee*,int,int);
/** \brief Ordena el empleado ascendente o descendente segun se desee
 * \param emp* puntero al array de empleados
 * \param CANT Entero del total del array
 * \param name char auxiliar, nombre del empleado
 * \param lastName char auxiliar, apellido del empleado
 * \param opcion int, opcion deseada para ordenar el empleado
 * \return int Retorna (0) cuando se ordena
 */
int sortEmployee(employee*,int,char*,char*,int);
/** \brief Imprime el empleado por consola
 * \param emp* puntero al array de empleados
 * \param MAXEMP Entero del total del array
 * \return int Retorna (-1) si hay error, la posicion del array si no hay error.
 */
int printEmployee(employee*,int);
/** \brief Valida que se haya cargado un empleado al menos
 * \param flag int
 * \return int Retorna (-1) si ya se cargo un empelado al menos,
 * 0 si no se cargo el empleado.
 */
int firstEmployee(int);
/** \brief Modifica el empleado solicitado por id
 * \param emp* puntero al array de empleados
 * \param MAXEMP Entero del total del array
 * \param name char auxiliar, nombre del empleado a modificar
 * \param lastName char auxiliar, apellido del empleado a modificar
 * \param salary float auxiliar, salario del empleado a modificar
 * \param id int auxiliar, id del empleado a modificar
 * \return No retorna nada ya que es una funcion void
 */
void modifyEmployee(employee*,int,char*,char*,float,int,int,int);
/** \brief Calcula el promedio de salarios
 * \param emp* puntero al array de empleados
 * \param MAXEMP Entero del total del array
 * \return Retorna (-1) si hay error, 0 si se realiza el promedio.
 */
int averageSalary(employee*,int);
/** \brief Calcula el total de salarios
 * \param emp* puntero al array de empleados
 * \param MAXEMP Entero del total del array
 * \return Retorna el promedio de salarios en float, retorna(-1) si hay error.
 */
float totalSalary(employee*,int);
/** \brief Calcula la cantidad de empleados que superan la media de salario
 * \param emp* puntero al array de empleados
 * \param MAXEMP Entero del total del array
 * \return Retorna (-1) si hay error, retorna el contador de cantidad
 */
int excSalary(employee*,int);
/**
 * Convierte en mayuscula cada letra de la palabra.
 * @param cliente eCliente* Pointer to array of eCliente
 * @param len int size of array
 */

void Touperralizar(employee emp[], int );

#endif // ARRAYEMPLOYEES_H_INCLUDED
