#include <iostream>
#include <string>
#include <list>
#include <stack>
#include <algorithm>
using namespace std;

struct Multa
{
    int ID;
    string Conductor;
    string Motivo;
    string Fecha; // Formato: YYYY-MM-DD
    double Monto;
};

// ✅ Función para registrar una multa con validación básica
Multa registrarMulta()
{
    Multa m;

    cout << "ID de multa (mayor que 0): ";
    cin >> m.ID;
    while (cin.fail() || m.ID <= 0)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Entrada inválida. Ingrese un número entero positivo: ";
        cin >> m.ID;
    }

    cin.ignore();
    cout << "Nombre del conductor: ";
    getline(cin, m.Conductor);

    cout << "Motivo de la multa: ";
    getline(cin, m.Motivo);

    cout << "Fecha (YYYY-MM-DD): ";
    getline(cin, m.Fecha);

    cout << "Monto de la multa (mayor que 0): ";
    cin >> m.Monto;
    while (cin.fail() || m.Monto <= 0)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Entrada inválida. Ingrese un número mayor que 0: ";
        cin >> m.Monto;
    }

    cin.ignore();
    return m;
}

// ✅ Ordenar por fecha
void ordenarPorFecha(list<Multa> &multas)
{
    multas.sort([](const Multa &a, const Multa &b)
                { return a.Fecha < b.Fecha; });
}

// ✅ Mostrar una multa
void mostrarMulta(const Multa &m)
{
    cout << "---------------------------------\n";
    cout << "ID: " << m.ID << endl;
    cout << "Conductor: " << m.Conductor << endl;
    cout << "Motivo: " << m.Motivo << endl;
    cout << "Fecha: " << m.Fecha << endl;
    cout << "Monto: $" << m.Monto << endl;
}

// ✅ Mostrar todas las multas
void mostrarMultas(const list<Multa> &multas)
{
    if (multas.empty())
    {
        cout << "No hay en existencia.\n";
        return;
    }

    for (const auto &m : multas)
    {
        mostrarMulta(m);
    }
}

// ✅ Buscar multa por ID
void buscarMulta(list<Multa> &multas, int idBuscado)
{
    if (multas.empty())
    {
        cout << "No hay en existencia.\n";
        return;
    }

    multas.sort([](const Multa &a, const Multa &b)
                { return a.ID < b.ID; });

    Multa clave{};
    clave.ID = idBuscado;

    auto cmp = [](const Multa &a, const Multa &b)
    { return a.ID < b.ID; };

    auto it = lower_bound(multas.begin(), multas.end(), clave, cmp);

    if (it != multas.end() && it->ID == idBuscado)
    {
        cout << "\nMulta encontrada:\n";
        mostrarMulta(*it);
    }
    else
    {
        cout << "\nNo se encontró ninguna multa con ese ID.\n";
    }
}

// ✅ Programa principal
int main()
{
    list<Multa> registroMultas;
    stack<Multa> pilaRecientes;
    int opcion;

    do
    {
        cout << "\n===== SISTEMA DE CONTROL DE MULTAS =====\n";
        cout << "1. Registrar nueva multa\n";
        cout << "2. Mostrar todas las multas (ordenadas por fecha)\n";
        cout << "3. Buscar multa por ID\n";
        cout << "4. Anular la última multa registrada\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        while (cin.fail() || opcion < 0 || opcion > 4)
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Opción inválida. Ingrese un número entre 0 y 4: ";
            cin >> opcion;
        }

        switch (opcion)
        {
        case 1:
        {
            int n;
            cout << "¿Cuántas multas deseas registrar?: ";
            cin >> n;
            while (cin.fail() || n <= 0)
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Ingrese un número válido (mayor que 0): ";
                cin >> n;
            }
            cin.ignore();

            for (int i = 0; i < n; ++i)
            {
                cout << "\n--- Multa #" << (i + 1) << " ---\n";
                Multa m = registrarMulta();
                registroMultas.push_back(m);
                pilaRecientes.push(m);
            }

            cout << "\nSe han registrado " << n << " multa(s).\n";
            break;
        }

        case 2:
        {
            if (registroMultas.empty())
            {
                cout << "No hay en existencia.\n";
                break;
            }
            ordenarPorFecha(registroMultas);
            cout << "\nMultas ordenadas por fecha:\n";
            mostrarMultas(registroMultas);
            break;
        }

        case 3:
        {
            int id;
            cout << "\nIngrese el ID de la multa a buscar: ";
            cin >> id;
            while (cin.fail() || id <= 0)
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Ingrese un ID válido (mayor que 0): ";
                cin >> id;
            }
            buscarMulta(registroMultas, id);
            break;
        }

        case 4:
        {
            if (pilaRecientes.empty())
            {
                cout << "No hay en existencia.\n";
            }
            else
            {
                Multa anulada = pilaRecientes.top();
                pilaRecientes.pop();

                // Eliminar también de la lista principal
                auto it = find_if(registroMultas.begin(), registroMultas.end(),
                                  [&](const Multa &m)
                                  { return m.ID == anulada.ID; });

                if (it != registroMultas.end())
                    registroMultas.erase(it);

                cout << "\nSe ha anulado la multa más reciente:\n";
                mostrarMulta(anulada);
                cout << "Multas restantes en el registro: " << registroMultas.size() << endl;
            }
            break;
        }

        case 0:
            cout << "Saliendo del sistema...\n";
            break;
        }

    } while (opcion != 0);

    return 0;
}
