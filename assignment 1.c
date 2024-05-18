#include <stdio.h>
#include <math.h>

float calculate_theta(float wavelength, float a, int m) {
    return asin(m * wavelength / (a * 1e3));
}

char* get_color(float wavelength) {
    return (wavelength >= 380 && wavelength <= 450) ? "violet" :
           (wavelength > 450 && wavelength <= 485) ? "blue" :
           (wavelength > 485 && wavelength <= 500) ? "cyan" :
           (wavelength > 500 && wavelength <= 565) ? "green" :
           (wavelength > 565 && wavelength <= 590) ? "yellow" :
           (wavelength > 590 && wavelength <= 625) ? "orange" :
           (wavelength > 625 && wavelength <= 750) ? "red" : "out of range";
}

int main() {
    float wavelength, a[3], max_theta = 0;
    int m, max_theta_index = 0;

    printf("Enter the wavelength (in nm): ");
    scanf("%f", &wavelength);
    if (wavelength < 380 || wavelength > 750) {
        printf("Invalid wavelength. Please enter a value between 380 and 750 nm.\n");
        return 0;
    }

    printf("Enter the value of m: ");
    scanf("%d", &m);

    printf("Enter the values of a1, a2, and a3 (in micrometers): ");
    for (int i = 0; i < 3; i++) {
        scanf("%f", &a[i]);
        if (a[i] <= 0) {
            printf("Invalid slit width. Please enter a positive value.\n");
            return 0;
        }
        float theta = calculate_theta(wavelength, a[i], m);
        printf("theta%d: %.2f radians\n", i + 1, theta);
        if (theta > max_theta) max_theta = theta, max_theta_index = i + 1;
    }

    printf("The %s light was bent most by slit %d.\n", get_color(wavelength), max_theta_index);
    return 0;
}
