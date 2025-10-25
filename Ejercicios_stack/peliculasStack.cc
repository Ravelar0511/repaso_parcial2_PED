#include <iostream>
#include <stack>
#include <string>

struct Pelicula
{
    std::string Titulo;
    std::string Genero;
    int Anio;
    double Calificacion;
};

int main()
{
    std::stack<Pelicula> PilaPeliculas;
    int opcion;

    do
    {
        std::cout << "\n=== Biblioteca de Películas ===" << std::endl;
        std::cout << "1. Agregar películas" << std::endl;
        std::cout << "2. Mostrar películas" << std::endl;
        std::cout << "3. Ver (y sacar) la última película agregada" << std::endl;
        std::cout << "4. Salir" << std::endl;
        std::cout << "Seleccione una opción (1-4): ";
        std::cin >> opcion;
        std::cin.ignore();

        if (opcion == 1)
        {
            int cantidad;
            std::cout << "¿Cuántas películas deseas agregar? ";
            std::cin >> cantidad;
            std::cin.ignore();

            for (int i = 0; i < cantidad; ++i)
            {
                Pelicula p;
                std::cout << "\n--- Película #" << (i + 1) << " ---" << std::endl;

                std::cout << "Título: ";
                getline(std::cin, p.Titulo);

                std::cout << "Género: ";
                getline(std::cin, p.Genero);

                do
                {
                    std::cout << "Año de estreno: ";
                    std::cin >> p.Anio;
                    if (p.Anio < 1888 || p.Anio > 2025)
                        std::cout << "Año inválido. Intente de nuevo." << std::endl;
                } while (p.Anio < 1888 || p.Anio > 2025);

                do
                {
                    std::cout << "Calificación (0 a 10): ";
                    std::cin >> p.Calificacion;
                    if (p.Calificacion < 0 || p.Calificacion > 10)
                        std::cout << "Calificación inválida. Intente de nuevo." << std::endl;
                } while (p.Calificacion < 0 || p.Calificacion > 10);

                std::cin.ignore();
                PilaPeliculas.push(p);
            }

            std::cout << "\nSe han agregado " << cantidad << " película(s) al registro." << std::endl;
            std::cout << "Total de películas en la pila: " << PilaPeliculas.size() << std::endl;
        }

        else if (opcion == 2)
        {
            if (PilaPeliculas.empty())
            {
                std::cout << "No hay películas registradas." << std::endl;
            }
            else
            {
                std::stack<Pelicula> temp = PilaPeliculas;
                std::cout << "\n=== Películas registradas ===" << std::endl;
                while (!temp.empty())
                {
                    Pelicula p = temp.top();
                    std::cout << "Título: " << p.Titulo
                              << " | Género: " << p.Genero
                              << " | Año: " << p.Anio
                              << " | Calificación: " << p.Calificacion << std::endl;
                    temp.pop();
                }
            }
        }

        else if (opcion == 3)
        {
            if (PilaPeliculas.empty())
            {
                std::cout << "No hay películas para ver." << std::endl;
            }
            else
            {
                Pelicula p = PilaPeliculas.top();
                PilaPeliculas.pop();
                std::cout << "\nHas seleccionado para ver:\n";
                std::cout << "Título: " << p.Titulo << std::endl;
                std::cout << "Género: " << p.Genero << std::endl;
                std::cout << "Año: " << p.Anio << std::endl;
                std::cout << "Calificación: " << p.Calificacion << std::endl;
                std::cout << "Películas restantes en la pila: " << PilaPeliculas.size() << std::endl;
            }
        }

        else if (opcion != 4)
        {
            std::cout << "Opción inválida. Por favor, seleccione una opción entre 1 y 4." << std::endl;
        }

    } while (opcion != 4);

    std::cout << "\nGracias por usar el sistema de películas. ¡Hasta la próxima!\n" << std::endl;

    return 0;
}
