#include <stdio.h>
#include <conio.h> 
#include <stdbool.h>  
#include <stdlib.h>   
#include <time.h>    

int obtenerAnioActual() {
    time_t now;
    time(&now);
    struct tm *local = localtime(&now);
    return local->tm_year + 1900;
}

bool esFechaValida(int dia, int mes, int anio) {
    int anio_actual = obtenerAnioActual();

    if (anio < 1900 || anio > anio_actual)
        return false;

    if (mes < 1 || mes > 12)
        return false;

    if (dia < 1 || dia > 31)
        return false;

    switch (mes) {
        case 4: case 6: case 9: case 11:
            if (dia > 30)
                return false;
            break;
        case 2:
            if ((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0)) {
                if (dia > 29)
                    return false;
            } else {
                if (dia > 28)
                    return false;
            }
            break;
    }

    return true;
}

int sumarDigitos(int num) {
    int suma = 0;
    while (num > 0) {
        suma += num % 10;
        num /= 10;
    }
    return suma;
}

int obtenerFechaDeNacimiento(char *fecha_nacimiento) {
    printf("Ingrese la fecha de nacimiento (dia-mes-ano): ");
    scanf("%s", fecha_nacimiento);
    return 0; 
}

int numeroSuerte(char *fecha) {
    int suma_total = 0;

    int dia, mes, anio;
    sscanf(fecha, "%d-%d-%d", &dia, &mes, &anio);

    if (!esFechaValida(dia, mes, anio)) {
        printf("La fecha ingresada no es valida. Por favor, ingrese una fecha valida (dia-mes-ano): ");
        return -1;  
    }

    while (*fecha != '\0') {
        if (*fecha >= '0' && *fecha <= '9') {
            suma_total += *fecha - '0';
        }
        fecha++;
    }

    while (suma_total > 9) {
        suma_total = sumarDigitos(suma_total);
    }

    return suma_total;
}

int main() {
    char fecha_nacimiento[11]; 
    int numero_lucky;
    bool fecha_valida = false;

    do {
        if (obtenerFechaDeNacimiento(fecha_nacimiento) != 0) {
            return 1;
        }

        numero_lucky = numeroSuerte(fecha_nacimiento);

        if (numero_lucky == -1) {
            fecha_valida = false;
        } else {
            fecha_valida = true;
        }
    } while (!fecha_valida);

    printf("El numero de la suerte es: %d\n", numero_lucky);

    return 0;
}
