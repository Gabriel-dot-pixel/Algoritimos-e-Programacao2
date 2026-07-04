#include <stdio.h>

float converter_celsius_fahrenheit(float celsius)
{
    float fahrenheit;

    fahrenheit = (float)(9 * celsius + 160) / 5;

    return fahrenheit;
}

float converter_fahrenheit_celsius(float fahrenheit)
{
    float celsius;

    celsius = (fahrenheit - 32) * (float)(5/9);

    return celsius;
}

void main()
{
    float c, f;
    float convert_c_f, convert_f_c;

    printf("Digite a temperatura em Celsius: ");
    scanf("%f", &c);

    convert_c_f = converter_celsius_fahrenheit(c);
    printf("A temperatura convertida para Fahrenheit = %.2f\n", convert_c_f);

    printf("Digite a temperatura em Fahrenheit: ");
    scanf("%f", &f);

    convert_f_c = converter_fahrenheit_celsius(f);
    printf("A temperatura convertida para Celsius = %.2f\n", convert_f_c);
}
