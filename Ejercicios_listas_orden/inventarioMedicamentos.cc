#include <iostream>
#include <list>
#include <string>
#include <algorithm>
using namespace std;

struct Medicamento
{
    string nombre;
    string laboratorio;
    int cantidad;
};

void mostrarMedicamento(const Medicamento &m)
{
    cout << "\nNombre: " << m.nombre
         << "\nLaboratorio: " << m.laboratorio
         << "\nCantidad disponible: " << m.cantidad << endl;
}

int main()
{
    list<Medicamento> inventario;
    int opcion;

    do
    {
        cout << "\n=== MENU DE INVENTARIO ===\n";
        cout << "1. Agregar medicamento\n";
        cout << "2. Mostrar inventario ordenado\n";
        cout << "3. Buscar medicamento por nombre\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;
        cin.ignore();

        if (opcion == 1)
        {
            Medicamento m;
            cout << "Nombre del medicamento: ";
            getline(cin, m.nombre);
            cout << "Laboratorio: ";
            getline(cin, m.laboratorio);

            do
            {
                cout << "Cantidad disponible (1 - 500): ";
                cin >> m.cantidad;
                if (m.cantidad < 1 || m.cantidad > 500)
                    cout << "⚠️ Cantidad fuera de rango.\n";
            } while (m.cantidad < 1 || m.cantidad > 500);

            inventario.push_back(m);
            cout << "✅ Medicamento agregado correctamente.\n";
        }
        else if (opcion == 2)
        {
            if (inventario.empty())
                cout << "Inventario vacío.\n";
            else
            {
                inventario.sort([](const Medicamento &a, const Medicamento &b)
                                { return a.nombre < b.nombre; });
                cout << "\n--- Inventario ordenado ---\n";
                for (const auto &m : inventario)
                    mostrarMedicamento(m);
            }
        }
        else if (opcion == 3)
        {
            string buscar;
            cout << "Ingrese el nombre del medicamento: ";
            getline(cin, buscar);

            bool encontrado = false;
            for (const auto &m : inventario)
            {
                if (m.nombre == buscar)
                {
                    mostrarMedicamento(m);
                    encontrado = true;
                    break;
                }
            }
            if (!encontrado)
                cout << "❌ No se encontró el medicamento.\n";
        }
        else if (opcion != 4)
        {
            cout << "Opción inválida.\n";
        }

    } while (opcion != 4);

    cout << "Saliendo del sistema...\n";
    return 0;
}
