/*

Programa para generar varias utilidades para un determinado vendedor

El programa ejecuta los siguientes pasos, usando la programación modular:
1. Pide, por separado, el primer nombre, apellido paterno, y el apellido materno de un
   determinado vendedor, usando la función fgets() para cada pedido

2. Crea un PIN usando la perimera letra del nombre del vendedor en minúsculas, con la última
   letra de su apellido paterno (en mayúscula), con la última letra de su apellido materno
   (en mayúscula) y con uno de los siguientes textos: "x1g", "aj6", "u7f", "ne8", "k0g" , el 
   texto a colocar será elegido de manera aleatoria por el programa. En este caso, empleando
   una función para generar números aleatorios

3. Genera un código para el vendedor, con exactamente 3 dígitos, y que sea múltiplo de 3, usando
   la función previamente mencionada para obtener el número aleatoriamente

4. Sabiendo que el vendedor tiene asignado la venta de 12 tipos de producto (tipo 1, tipo 2, tipo 3,
   ..., tipo 12) , se deberá simular la cantidad vendida de cada producto con números aleatorios
   generados en el intervalo [15,60] unidades, los cuales deberán ser almacenados en un arreglo
   unidimensional. Los valores del arreglo se mostrarán en pantalla según el ejemplo de ejecución.

5. De los 12 tipos de productos vendidos, determinar cuántos de ellos dieron una ganancia bruta mayor
   a 1000 soles.  La ganancia bruta se calcula multiplicando la cantidad de unidades vendidas del producto
   con su precio unitario. En la figura dada para este trabajo se muestran los precios unitarios (en soles)
   de cada tipo de producto.

6. Finalmente, en caso el PIN del vendedor haya sido “jOZk0g”  y su código numérico termine en 6, se mostrará
   el mensaje: “UD. recibirá en bono”, caso contrario se indicará “No es acreedor al bono”.

Las soluciones para cada problema se han resuelto empleando la programación modular, en este caso, con las funciones:

- void crearPIN(char no[], char APF[], char AMF[], char pass[]) | Crea el PIN con las condiciones del paso 2

- int generaNumero() | Genera el número para el paso 3

- int aplicarConteo(int a[], int b) | Retorna la cantidad de productos vendidos, cuyos ingresos sean mayores a 1000, dado
  un "a" (Lista de productos vendidos, por tipo), y un "b" (Número de tipos de objetos vendidos)

- void mostrarMensajeFinal(char reci[], char comp[], int cod) | Muestra el mensaje final, dado por las condiciones del paso 6

Para el paso 1, solamente se utiliza la función fgets() en la función principal.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


void crearPIN(char no[], char APF[], char AMF[], char pass[]){

    char assembler[6] = "";
    int choice = rand() % (5 - 1 + 1) + 1;

    // Preparar Apellido Paterno y Materno en Mayusculas
    strlwr(no);
    strupr(APF);
    strupr(AMF);

    assembler[0] = no[0];
    assembler[1] = '\0';
    
    strcat(pass, assembler);

    assembler[0] = APF[strlen(APF)-1];
    assembler[1] = '\0';

    strcat(pass, assembler);

    assembler[0] = AMF[strlen(AMF)-1];
    assembler[1] = '\0';

    strcat(pass, assembler);

    switch (choice){
        case 1:
            strcat(pass,"x1g");
            break;
        case 2:
            strcat(pass,"aj6");
            break;
        case 3:
            strcat(pass,"u7f");
            break;
        case 4:
            strcat(pass,"ne8");
            break;
        case 5:
            strcat(pass,"k0g");
            break;   
    }

}


int generaNumero(){
    return 3*(rand() % (333 - 34 + 1) + 34); // En este caso, 34 siendo 34x3  = 102 y 333 siendo 333x3 = 999. Todos son múltiplos de 3
    // A siendo valor más pequeño, y B siendo valor más grande
}

// Recibe cantidades vendidas y tamaño del arreglo
int aplicarConteo(int a[], int b){

    // Tabla de precios para cada item
    int prices[12] = {12, 60, 23, 45, 25, 56, 80, 50, 45, 29, 67, 90};

    int may1000 = 0;
    int currentVal;

    for (int i = 0; i < b; i++){
        currentVal = a[i]*prices[i];

        if (currentVal > 1000){
            may1000++;
        }
    }

    return may1000;
}

void mostrarMensajeFinal(char reci[], char comp[], int cod){
    if (strcmp(reci,comp) == 0 && cod%10 == 6){
        printf("\n\nUD. recibirá en bono");
    }else{
        printf("\n\nNo es acreedor al bono");
    }
}

int main(){

    srand(time(NULL));
 
    // Espacios reservados para los nombres solicitados, PIN
    char PNombre[30], APaterno[30], AMaterno[30] = "";
    char PIN[6];

    printf("Ingresa el primer nombre del vendedor: ");
    fgets(PNombre, 30, stdin);
    strtok(PNombre, "\n");

    printf("Ingresa el apellido paterno del vendedor: ");
    fgets(APaterno, 30, stdin);
    strtok(APaterno, "\n");

    printf("Ingresa el apellido materno del vendedor: ");
    fgets(AMaterno, 30, stdin);
    strtok(AMaterno, "\n");

    crearPIN(PNombre,APaterno,AMaterno,PIN);

    printf("\nPIN generado: %s",PIN);

    int clave = generaNumero();

    printf("\n\nC%cdigo generado: %i\n",162,clave);

    int sales[12];

    for (int i = 0; i < 12; i++){
        sales[i] = rand() % (60 - 15 + 1) + 15; // Entre 15 a 60 unidades vendidas según las indicaciones.
    }

    printf("\nProducto:\tVentas (Unidades):\n");

    for (int i = 0; i < 12; i++){
        printf("Tipo %i\t\t\t",i+1);
        printf("%i\n",sales[i]);

    }

    printf("\nCantidad de productos con m%cs de 1000 soles en ganancias: %i",160,aplicarConteo(sales,12));

    mostrarMensajeFinal(PIN,"jOZk0g",clave);

    return 0;

}

// Prompt may vary between worksheets, this is NOT a definive solution
