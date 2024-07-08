#include <stdio.h>


int main() {
    // Variables
    int dia, mes, aa, suma, lucky_n;
    char continuar = 'S';

    while (continuar == 'S'|| continuar == 's') {
        printf("Ingrese su fecha de nacimiento (dd-mm-aa). Ingrese 0 para salir\n");
        printf("Dia: ");
        scanf("%d", &dia);
        if (dia == 0) 
        break;
        printf("Mes: ");
        scanf("%d", &mes);
        printf("Año: ");
        scanf("%d", &aa);

        // Validar la fecha
        switch (mes) {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                if (dia >= 1 && dia <= 31 && aa >= 1000 && aa <= 9999) {
                    suma = dia + mes + aa;
                } else {
                    printf("Fecha fuera de rango\n");
                    continue;
                }
                break;

            case 2:
                if (dia >= 1 && dia <= 28 && aa >= 1000 && aa <= 9999) {
                    suma = dia + mes + aa;
                } else {
                    printf("Fecha fuera de rango\n");
                    continue;
                }
                break;

            case 4: case 6: case 9: case 11:
                if (dia >= 1 && dia <= 30 && aa >= 1000 && aa <= 9999) {
                    suma = dia + mes + aa;
                } else {
                    printf("Fecha fuera de rango\n");
                    continue;
                }
                break;
            
            default:
                printf("Fecha inválida\n");
                continue;
        }

        // Calcular el número de la suerte
        while (suma >= 9) {
            lucky_n = 0;
            while (suma > 0) {
                lucky_n = lucky_n + (suma % 10);
                suma = suma / 10;
            }
            suma = lucky_n;
        }

        printf("Su numero de la suerte es: %d\n", suma);
        printf("Desea calcular otro numero de la suerte? (S/N)\n");
        scanf(" %c", &continuar); 
    }

    return 0;
}