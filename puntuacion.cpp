#include <iostream>
#include <limits> 
#include <iomanip>

using namespace std;

// Función para leer y validar la entrada de puntuaciones
int puntuaciones(const string& mensaje) {
    int puntuacion;
    while (true) {
        cout << mensaje;
        cin >> puntuacion;
        // Verificar si la entrada no es válida, si está fuera del rango o si no es un entero
        if (cin.fail() || puntuacion < 0 || puntuacion > 100 || cin.peek() != '\n') { 
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorar si la entrada es inválida
            cout << "Entrada invalida. Por favor ingrese una puntuacion entre 0 y 100." << endl;
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return puntuacion;
        }
    }
}

// Función para calcular la media de las cuatro puntuaciones
double calculaMedia(int p1, int p2, int p3, int p4) {
    return (p1 + p2 + p3 + p4) / 4.0;
}

// Función para calcular la puntuación basada en la media
char calcularPuntuacion(double media) {
    if (media >= 90) {
        return 'A';
    } else if (media >= 80) {
        return 'B';
    } else if (media >= 70) {
        return 'C';
    } else if (media >= 60) {
        return 'D';
    } else {
        return 'E';
    }
}

int main() {
    // Leer las cuatro puntuaciones
    int p1 = puntuaciones("Ingrese la primera puntuacion (0-100): ");
    int p2 = puntuaciones("Ingrese la segunda puntuacion (0-100): ");
    int p3 = puntuaciones("Ingrese la tercera puntuacion (0-100): ");
    int p4 = puntuaciones("Ingrese la cuarta puntuacion (0-100): ");

    // Calcular la media
    double media = calculaMedia(p1, p2, p3, p4);

    // Calcular la puntuación
    char puntuacion = calcularPuntuacion(media);

    // Mostrar la tabla de notas con dos decimales
    cout << fixed << setprecision(2);
    cout << "Media: " << media << endl;
    cout << "Puntuacion: " << puntuacion << endl;

    return 0;
}
