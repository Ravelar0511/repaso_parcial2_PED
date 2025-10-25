#include <iostream>
#include <list>
#include <string>
using namespace std;

struct Estudiante
{
    string carnet;
    string nombre;
    int edad;
    string carrera;
};

void mostrarEstudiante(const Estudiante &e)
{
    cout << "\nCarnet: " << e.carnet
         << "\nNombre: " << e.nombre
         << "\nEdad: " << e.edad
         << "\nCarrera: " << e.carrera << endl;
}

int main()
{
    list<Estudiante> estudiantes;
    int opcion;

    do
    {
        cout << "\n=== MENU DE ESTUDIANTES ===\n";
        cout << "1. Agregar estudiante\n";
        cout << "2. Mostrar todos\n";
        cout << "3. Buscar por carnet\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;
        cin.ignore();

        if (opcion == 1)
        {
            Estudiante e;
            cout << "Carnet: ";
            getline(cin, e.carnet);
            cout << "Nombre: ";
            getline(cin, e.nombre);
            cout << "Edad: ";
            cin >> e.edad;
            cin.ignore();
            cout << "Carrera: ";
            getline(cin, e.carrera);

            estudiantes.push_back(e);
            cout << "✅ Estudiante agregado correctamente.\n";
        }
        else if (opcion == 2)
        {
            if (estudiantes.empty())
                cout << "No hay estudiantes registrados.\n";
            else
            {
                cout << "\n--- Lista de estudiantes ---\n";
                for (const auto &e : estudiantes)
                    mostrarEstudiante(e);
            }
        }
        else if (opcion == 3)
        {
            string carnetBuscado;
            cout << "Ingrese el carnet a buscar: ";
            getline(cin, carnetBuscado);

            bool encontrado = false;
            for (const auto &e : estudiantes)
            {
                if (e.carnet == carnetBuscado)
                {
                    mostrarEstudiante(e);
                    encontrado = true;
                    break;
                }
            }

            if (!encontrado)
                cout << "❌ No se encontró ningún estudiante con ese carnet.\n";
        }
        else if (opcion != 4)
        {
            cout << "Opción inválida.\n";
        }

    } while (opcion != 4);

    cout << "Programa finalizado.\n";
    return 0;
}
