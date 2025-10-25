#include <iostream>
#include <string>
#include <list>
#include <algorithm>
using namespace std;

struct Paquete
{
    int Tracking;
    string Destinatario;
    string Estado;
    string Fecha;
    string ciudadOrigen;
};

Paquete agregarPaquete()
{
    Paquete p;
    cout << "Tracking: ";
    cin >> p.Tracking;
    cin.ignore();
    cout << "Destinatario: ";
    getline(cin, p.Destinatario);
    cout << "Estado: ";
    getline(cin, p.Estado);
    cout << "Fecha (YYYY-MM-DD): ";
    getline(cin, p.Fecha);
    cout << "Ciudad origen: ";
    getline(cin, p.ciudadOrigen);
    return p;
}

void ordenarPorFecha(list<Paquete> &Envios)
{
    Envios.sort([](const Paquete &a, const Paquete &b)
                { return a.Fecha < b.Fecha; });
}

// ✅ Nueva función: muestra un solo paquete
void mostrarPaquete(const Paquete &p)
{
    cout << "----------------------------------\n";
    cout << "Tracking: " << p.Tracking << endl;
    cout << "Destinatario: " << p.Destinatario << endl;
    cout << "Estado: " << p.Estado << endl;
    cout << "Fecha: " << p.Fecha << endl;
    cout << "Ciudad Origen: " << p.ciudadOrigen << endl;
}

// ✅ Nueva función: muestra todos los paquetes
void mostrarPaquetes(const list<Paquete> &Envios)
{
    if (Envios.empty())
    {
        cout << "No hay paquetes registrados.\n";
        return;
    }

    for (const auto &p : Envios)
    {
        mostrarPaquete(p);
    }
}

void buscarPaquete(list<Paquete> &Envios, int trackingBuscado)
{
    Envios.sort([](const Paquete &a, const Paquete &b)
                { return a.Tracking < b.Tracking; });

    Paquete clave{};
    clave.Tracking = trackingBuscado;

    auto cmp = [](const Paquete &a, const Paquete &b)
    {
        return a.Tracking < b.Tracking;
    };

    auto it = lower_bound(Envios.begin(), Envios.end(), clave, cmp);

    if (it != Envios.end() && it->Tracking == trackingBuscado)
    {
        cout << "\nPaquete encontrado:\n";
        mostrarPaquete(*it);
    }
    else
    {
        cout << "\nNo se encontró ningún paquete con tracking "
             << trackingBuscado << ".\n";
    }
}

int main()
{
    list<Paquete> envios;
    int opcion;

    do
    {
        cout << "\n===== MENU DE PAQUETES =====\n";
        cout << "1. Agregar paquete\n";
        cout << "2. Mostrar todos los paquetes\n";
        cout << "3. Buscar paquete por tracking\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
        {
            cout << "Recuerda que se usa el formato YYYY-MM-DD, ej. 2025-05-15" << endl;
            cout << "¿Cuántos paquetes vas a ingresar?: ";
            int n = 0;
            if (!(cin >> n) || n <= 0)
                return 0;
            cin.ignore();

            for (int i = 0; i < n; ++i)
            {
                cout << "\nPaquete " << (i + 1) << "\n";
                envios.push_back(agregarPaquete());
            }
            break;
        }
        case 2:
        {
            ordenarPorFecha(envios);
            cout << "\nPaquetes ordenados por fecha:\n";
            cout << "El orden de entregas es:\n";
            mostrarPaquetes(envios);
            break; 
        }
        case 3:
        {
            int tracking;
            cout << "\nIngrese el número de tracking a buscar: ";
            cin >> tracking;
            buscarPaquete(envios, tracking);
            break;
        }
        case 0:
            cout << "Saliendo del programa.\n";
            break;
        default:
            cout << "Opción inválida, intente de nuevo.\n";
            break;
        }

    } while (opcion != 0);

    return 0;
}
