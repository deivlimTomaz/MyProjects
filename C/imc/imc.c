#include <stdio.h>
#include <ctype.h>
#include <math.h>

int main(){

    // Declare variables

    float height, weight, imc;
    char gender;
    
    // Inputs
    printf("What's your gender (M / F): ");
    scanf(" %c", &gender);
    gender = tolower(gender);

    printf("Enter your height (m): ");
    scanf("%f", &height);

    printf("Enter your weight (kg): ");
    scanf("%f", &weight);

    // Calculating IMC
    imc = weight / pow(height, 2);

    // Print the result
    printf("Your BMI is: %.1f", imc);

    return 0;
}