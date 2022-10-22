#include <stdio.h>
#include <string.h>

// Prototipos: 
int validate(char operator);
float sum(float a, float b), subtract(float a, float b), multiply(float a, float b), divide(float a, float b);

int main() {
    float operation[2]; // Elementos a operar
    char input; // Operador (Caracter)
    int operator; // Operador (Valor numérico)
    float result; // Resultado
    do {
        printf("Ingrese la operacion a realizar, con todos sus elementos separados por espacios\n\tEj: 2 + 4\n\t  > ");
        scanf("%f %c %f", &operation[0], &input, &operation[1]); // Guarda todos los valores de la operación
        operator = validate(input);
        if (!operator) // Si el operador es 0
            printf("La operación no es válida, intente con otra\n\n");
    } while(!operator); // El bucle no terminará hasta que operator != 0

    switch (operator) { // Realiza la operación correspondiente al operador
        case 1: result = sum(operation[0], operation[1]); break;
        case 2: result = subtract(operation[0], operation[1]); break;
        case 3: result = multiply(operation[0], operation[1]); break;
        case 4: result = divide(operation[0], operation[1]); break;
    }

    printf("El resultado es %.2f\n", result);

    return 0;
}

int validate(char operator) { // Verifica si el operador es válido
    char validInputs[4] = "+-*/";
    for (int i=0; i<4; i++) {
        if (operator == validInputs[i]) 
            return i+1;
    }
    return 0;
}

float sum(float a, float b) {
    return a + b;
}

float subtract(float a, float b) {
    return a - b;
}

float multiply(float a, float b) {
    return a * b;
}

float divide(float a, float b) {
    return a / b;
}

// Programación II: Asignación 2
// Rafael Mata | CI: 30.465.215
