#include <iostream>
#include <string>
#include <list>
#include <algorithm>
using namespace std;

struct Producto
{
    int Codigo;
    string Nombre;
    string Categoria;
    double Precio;
    int Stock;
};

// ✅ Agregar un nuevo producto
Producto agregarProducto()
{
    Producto p;
    cout << "Código del producto: ";
    cin >> p.Codigo;
    cin.ignore();
    cout << "Nombre: ";
    getline(cin, p.Nombre);
    cout << "Categoría: ";
    getline(cin, p.Categoria);
    cout << "Precio: ";
    cin >> p.Precio;
    cout << "Stock disponible: ";
    cin >> p.Stock;
    cin.ignore();
    return p;
}

// ✅ Ordenar por nombre del producto
void ordenarPorNombre(list<Producto> &inventario)
{
    inventario.sort([](const Producto &a, const Producto &b)
                    { return a.Nombre < b.Nombre; });
}

// ✅ Mostrar un solo producto
void mostrarProducto(const Producto &p)
{
    cout << "----------------------------------\n";
    cout << "Código: " << p.Codigo << endl;
    cout << "Nombre: " << p.Nombre << endl;
    cout << "Categoría: " << p.Categoria << endl;
    cout << "Precio: $" << p.Precio << endl;
    cout << "Stock: " << p.Stock << endl;
}

// ✅ Mostrar todos los productos
void mostrarProductos(const list<Producto> &inventario)
{
    if (inventario.empty())
    {
        cout << "No hay productos registrados.\n";
        return;
    }

    for (const auto &p : inventario)
    {
        mostrarProducto(p);
    }
}

// ✅ Buscar un producto por código (usando búsqueda binaria)
void buscarProducto(list<Producto> &inventario, int codigoBuscado)
{
    inventario.sort([](const Producto &a, const Producto &b)
                    { return a.Codigo < b.Codigo; });

    Producto clave{};
    clave.Codigo = codigoBuscado;

    auto cmp = [](const Producto &a, const Producto &b)
    {
        return a.Codigo < b.Codigo;
    };

    auto it = lower_bound(inventario.begin(), inventario.end(), clave, cmp);

    if (it != inventario.end() && it->Codigo == codigoBuscado)
    {
        cout << "\nProducto encontrado:\n";
        mostrarProducto(*it);
    }
    else
    {
        cout << "\nNo se encontró ningún producto con el código "
             << codigoBuscado << ".\n";
    }
}

// ✅ Programa principal
int main()
{
    list<Producto> inventario;
    int opcion;

    do
    {
        cout << "\n===== MENU DE INVENTARIO =====\n";
        cout << "1. Agregar producto\n";
        cout << "2. Mostrar todos los productos\n";
        cout << "3. Buscar producto por código\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
        {
            int n;
            cout << "¿Cuántos productos deseas ingresar?: ";
            cin >> n;
            cin.ignore();

            for (int i = 0; i < n; ++i)
            {
                cout << "\nProducto " << (i + 1) << ":\n";
                inventario.push_back(agregarProducto());
            }
            break;
        }
        case 2:
        {
            ordenarPorNombre(inventario);
            cout << "\nProductos ordenados por nombre:\n";
            mostrarProductos(inventario);
            break;
        }
        case 3:
        {
            int codigo;
            cout << "\nIngrese el código del producto a buscar: ";
            cin >> codigo;
            buscarProducto(inventario, codigo);
            break;
        }
        case 0:
            cout << "Saliendo del sistema de inventario.\n";
            break;
        default:
            cout << "Opción inválida, intente de nuevo.\n";
            break;
        }

    } while (opcion != 0);

    return 0;
}
