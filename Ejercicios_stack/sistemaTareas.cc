#include <iostream>
#include <stack>
#include <string>
using namespace std;

struct Tarea
{
    string descripcion;
    string prioridad;
};

int main()
{
    stack<Tarea> tareas;
    int opcion;

    do
    {
        cout << "\n=== MENU DE TAREAS ===\n";
        cout << "1. Agregar tarea\n";
        cout << "2. Mostrar tareas\n";
        cout << "3. Eliminar última tarea\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opción (1-4): ";
        cin >> opcion;
        cin.ignore();

        if (opcion == 1)
        {
            Tarea t;
            cout << "Descripción: ";
            getline(cin, t.descripcion);

            do
            {
                cout << "Prioridad (Alta, Media, Baja): ";
                getline(cin, t.prioridad);
                if (t.prioridad != "Alta" && t.prioridad != "Media" && t.prioridad != "Baja")
                    cout << "⚠️ Prioridad inválida. Intente de nuevo.\n";
            } while (t.prioridad != "Alta" && t.prioridad != "Media" && t.prioridad != "Baja");

            tareas.push(t);
            cout << "✅ Tarea agregada correctamente.\n";
        }
        else if (opcion == 2)
        {
            if (tareas.empty())
            {
                cout << "No hay tareas pendientes.\n";
            }
            else
            {
                cout << "\n=== Tareas guardadas ===\n";
                stack<Tarea> temp = tareas;
                while (!temp.empty())
                {
                    Tarea t = temp.top();
                    cout << "Descripción: " << t.descripcion << " | Prioridad: " << t.prioridad << endl;
                    temp.pop();
                }
            }
        }
        else if (opcion == 3)
        {
            if (tareas.empty())
                cout << "⚠️ No hay tareas para eliminar.\n";
            else
            {
                cout << "Eliminando tarea: " << tareas.top().descripcion << endl;
                tareas.pop();
            }
        }
        else if (opcion != 4)
        {
            cout << "Opción inválida.\n";
        }

    } while (opcion != 4);

    cout << "Programa finalizado.\n";
    return 0;
}
