#include <stdio.h>
#include <math.h>

int main()
{
    float lambda_green = 5.30e-7f;
    float lambda_red = 7.00e-7f;
    int n_green = 3;
    int n_red = 2;
    float theta_green = 65.0f;

    float theta_green_rad = theta_green * M_PI / 180.0f;
    float d = (n_green * lambda_green) / sinf(theta_green_rad);
    float sin_theta_red = (n_red * lambda_red) / d;
    float theta_red = asinf(sin_theta_red) * 180.0f / M_PI;

    printf("The angle for the second-order bright spot for red light is: %.2f degrees\n", theta_red);

    return 0;
}

