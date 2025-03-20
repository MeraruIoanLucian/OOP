#include <stdio.h>

int Atoiul(const char *str) {
    int i = 0, result = 0;
    while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
        i++;
    while (str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return result;
}

int main() {
    int suma = 0;
    FILE *fp = fopen("input.txt", "r");
    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        suma = suma + Atoiul(line);
    }
    printf("%d\n", suma);
    fclose(fp);
    return 0;
}

#include <iostream>
using namespace std;

bool isPrime(int n)
{
    for (int tr = 2; tr < n / 2; tr++)
        if ((n % tr ) == 0)
            return true;
    return false;
}
int main()
{
    int n;
    std::cout << "Enter a number:";
    std::cin >> n;
    if (isPrime(n))
        std::cout << n << " is prime !";
    else
        std::cout << n << " is NOT prime !";
    return 0;
}
