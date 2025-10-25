#include <iostream>
#include <stack>

struct Carta
{
    int Numero;
    char Palo;
    char Color;
};

int main()
{
    std::stack<Carta> Mazo;
    int opcion;

    do
    {

        std::cout << "\n=== Bienvenido al Juego de Cartas ===" << std::endl;
        std::cout << "1. Agregar cartas" << std::endl;
        std::cout << "2. Mostrar cartas" << std::endl;
        std::cout << "3. Robar carta" << std::endl;
        std::cout << "4. Salir" << std::endl;
        std::cout << "Seleccione una opción (1-4): ";
        std::cin >> opcion;

        if (opcion == 1)
        {
            int cantidad;
            std::cout << "¿Cuantas cartas deseas agregar al mazo? ";
            std::cin >> cantidad;

            for (int i = 0; i < cantidad; ++i)
            {
                Carta c;
                std::cout << "\n--- Carta #" << (i + 1) << " ---" << std::endl;

                do
                {
                    std::cout << "Numero (1-13): ";
                    std::cin >> c.Numero;
                    if (c.Numero < 1 || c.Numero > 13)
                    {
                        std::cout << "Número invalido. Intente de nuevo." << std::endl;
                    }
                } while (c.Numero < 1 || c.Numero > 13);

                do
                {
                    std::cout << "Palo (C: corazones, D: diamantes, T: treboles, P: picas): ";
                    std::cin >> c.Palo;
                    if (c.Palo != 'C' && c.Palo != 'D' && c.Palo != 'T' && c.Palo != 'P')
                    {
                        std::cout << "Palo invalido. Intente de nuevo." << std::endl;
                    }
                } while (c.Palo != 'C' && c.Palo != 'D' && c.Palo != 'T' && c.Palo != 'P');

                do
                {
                    std::cout << "Color (R: rojo, N: negro): ";
                    std::cin >> c.Color;
                    if (c.Color != 'R' && c.Color != 'N')
                    {
                        std::cout << "Color invalido. Intente de nuevo." << std::endl;
                    }
                } while (c.Color != 'R' && c.Color != 'N');

                Mazo.push(c);
            }

            std::cout << "\nSe han agregado " << cantidad << " carta(s) al mazo." << std::endl;
            std::cout << "Cartas totales en el mazo: " << Mazo.size() << std::endl;
        }

        else if (opcion == 2)
        {
            if (Mazo.empty())
            {
                std::cout << "El mazo esta vacio." << std::endl;
            }
            else
            {
                std::stack<Carta> temp = Mazo;
                std::cout << "\n== Cartas en el mazo ==" << std::endl;
                while (!temp.empty())
                {
                    Carta c = temp.top();
                    std::cout << "Numero: " << c.Numero << ", Palo: " << c.Palo << ", Color: " << c.Color << std::endl;
                    temp.pop();
                }
            }
        }

        else if (opcion == 3)
        {
            if (Mazo.empty())
            {
                std::cout << "No hay cartas para robar." << std::endl;
            }
            else
            {
                Carta c = Mazo.top();
                Mazo.pop();
                std::cout << "\nCarta robada:" << std::endl;
                std::cout << "Numero: " << c.Numero << std::endl;
                std::cout << "Palo: " << c.Palo << std::endl;
                std::cout << "Color: " << c.Color << std::endl;
                std::cout << "Cartas restantes en el mazo: " << Mazo.size() << std::endl;
            }
        }

        else if (opcion != 4)
        {
            std::cout << "Opción inválida. Por favor, seleccione una opción entre 1 y 4." << std::endl;
        }

    } while (opcion != 4);

    std::cout << "Gracias por jugar. ¡Hasta la próxima!" << std::endl;
    return 0;
}