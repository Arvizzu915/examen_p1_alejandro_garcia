#include <iostream>
#include<cstdlib> //Trabaja con números random
using namespace std;

void Game();
int askQuestion(int low, int high, string type);

int main()
{
    int option = 0;

    do {
        if (option != 1) {
            cout << "1. Play, 2. Exit";
            option = askQuestion(1, 2, "option");
        }


        switch (option)
        {
        case 1:
            Game();
            cout << "Quieres volver a jugar? (1. si, 2. no)";
            option = askQuestion(1, 2, "option");
            system("cls");
            break;
        case 2:
            cout << "Realmente quieres salir? (1. si, 2. no)" << endl;
            option = askQuestion(1, 2, "option");
            if (option == 2) {
                system("cls");
            }
            else {
                option--;
                cout << "Vuelve pronto!";
            }
            break;
        default:
            break;
        }
    } while (option != 0);
}

void Game() {
    srand(static_cast<unsigned int>(time(0)));
    //srand(time(NULL));

    int guess;
    int tries = 0;
    int rangoLow = 0, rangoHigh = 0;

    cout << "En que rango de numeros quieres jugar?" << endl;
    cout << "Minimo: ";
    cin >> rangoLow;
    cout << "Maximo: ";
    cin >> rangoHigh;

    int randomNumber = rand();
    int secretNumber = (randomNumber % (rangoHigh - rangoLow)) + 1 + rangoLow;

    cout << "GUESS MY NUMBER" << endl;
    cout << "Adivina el numero en el menor número de intentos posible." << endl;

    do
    {
        guess = askQuestion(rangoLow, rangoHigh, "number");
        cout << secretNumber;

        tries++;

        if (guess > secretNumber) {
            cout << "Mas bajo\n\n";
            if (guess - secretNumber < 6 && guess - secretNumber > -6 && guess - secretNumber != 0) {
                cout << "(Muy cerca)" << endl;
            }
        }
        else if (guess < secretNumber) {
            cout << "Mas alto\n\n";
            if (guess - secretNumber < 6 && guess - secretNumber > -6 && guess - secretNumber != 0) {
                cout << "(Muy cerca)" << endl;
            }
        }
        else {
            cout << "Excelente lo hiciste en -- " << tries << "-- intentos" << endl;;

        }
    } while (guess != secretNumber);
}

int askQuestion(int low, int high, string type)
{
    int guess;

    do {
        cout << "\nEnter a " << type << ": (" << low << "-" << high << "):" << endl;
        cin >> guess;
    } while (guess < low || guess > high);

    return guess;
}

