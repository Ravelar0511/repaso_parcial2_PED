#include <iostream>
#include <stack>
#include <string>
using namespace std;

struct Pedido {
    string cliente;
    string producto;
    float precio;
};

int main() {
    stack<Pedido> pedidos;
    int opcion;

    do {
        cout << "\n=== CAFETERÍA CENTRAL ===\n";
        cout << "1. Agregar pedido\n";
        cout << "2. Mostrar pedidos\n";
        cout << "3. Eliminar último pedido\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;
        cin.ignore();

        if (opcion == 1) {
            Pedido p;
            cout << "Nombre del cliente: ";
            getline(cin, p.cliente);
            cout << "Producto: ";
            getline(cin, p.producto);
            cout << "Precio: $";
            cin >> p.precio;
            cin.ignore();

            pedidos.push(p);
            cout << "✅ Pedido agregado correctamente.\n";
        } 
        else if (opcion == 2) {
            if (pedidos.empty()) {
                cout << "No hay pedidos registrados.\n";
            } else {
                stack<Pedido> temp = pedidos;
                cout << "\n=== PEDIDOS ACTUALES ===\n";
                while (!temp.empty()) {
                    Pedido p = temp.top();
                    cout << "Cliente: " << p.cliente 
                         << " | Producto: " << p.producto 
                         << " | Precio: $" << p.precio << endl;
                    temp.pop();
                }
            }
        } 
        else if (opcion == 3) {
            if (pedidos.empty()) cout << "⚠️ No hay pedidos que eliminar.\n";
            else {
                cout << "Eliminando pedido de " << pedidos.top().cliente << endl;
                pedidos.pop();
            }
        } 
        else if (opcion != 4) {
            cout << "Opción inválida.\n";
        }

    } while (opcion != 4);

    cout << "👋 Programa finalizado.\n";
    return 0;
}
