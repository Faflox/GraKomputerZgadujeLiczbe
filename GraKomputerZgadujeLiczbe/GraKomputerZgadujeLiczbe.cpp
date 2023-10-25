#include <iostream>
#include <windows.h>
#include <ctime>

int main()
{
    //Poczatek gry i ogarniecie przedzialu
    std::cout << "Wymysl w glowie sobie jakas liczbe jaka chcesz\n";
    std::cout << "Podaj przedzial liczb naturalnych w jakim znajduje sie ta liczba\n\n";
    int przedzialDol, przedzialGora;

    std::cout << "Podaj najmniejsza liczbe przedzialu:\n";
    std::cin >> przedzialDol;
    std::cout << "Podaj najwieksza liczbe przedzialu:\n";
    std::cin >> przedzialGora;
    if (przedzialDol > przedzialGora)
    {
        int temp = przedzialDol;
        przedzialDol = przedzialGora;
        przedzialGora = temp;
    }
    else if (przedzialDol == przedzialGora)
    {
        std::cout << "Bez sensu taka gra...\n";
    }
    system("cls");
    std::cout << "Gramy na przedziale:\n" << przedzialDol << " - " << przedzialGora;
    //Poczatek gry i ogarniecie przedzialu




    //Gra
    int tries=0, toMuch=0, toLittle=0;//ilosc prob
    
    while (true)
    {
        int guess = przedzialGora - przedzialDol + 1;                //daje ilosc mozliwych odpowiedzi
        srand(time(NULL));
        int num = (rand() % guess) + przedzialDol;                   // to pozwala na wrocenie do mozliwej odp
        if (guess == 1)//to przypadek, gdzie przedzial to tylko jedna liczba calkowita
        {
            std::cout << "\n\nTwoja liczba to: " << num;
            std::cout << "\nNastepnym razem wymysl trudniejsza liczbe\n";
            std::cout << "Wygralem w: " << tries << " ruchow...\n\n\n";
            std::cout << toMuch << " razy dalem za duza liczbe a " << toLittle << " dalem za mala liczbe";
            break;
            break;
        }
        std::cout << "\n\nCzy twoja liczba to: " << num;
        std::cout << "\n1. Tak\n2. Moja liczba jest wieksza\n3. Moja liczba jest mniejsza\n";
        int result;
        tries++;
        std::cin >> result;
        if (result == 1)//gdy komputer zgadnie
        {
            std::cout << "\nNastepnym razem wymysl trudniejsza liczbe\n";
            std::cout << "Wygralem w: " << tries << " ruchow...\n\n\n";
            std::cout << toMuch << " razy dalem za duza liczbe a " << toLittle << " dalem za mala liczbe\n\n";
            break;
        }
        else if (result == 2)//gdy komputer da za mala liczbe
        {
            system("cls");
            std::cout << "Okeeeeej...\n";
            toLittle++;
            przedzialDol = num+1;//dzieki temu wypada ta opcja
            std::cout << "Teraz gramy na przedziale:\n" << przedzialDol << " - " << przedzialGora;
        }
        else if (result == 3)//gdy komputer da za duza liczbe
        {
            system("cls");
            std::cout << "Okeeeeej...\n";
            toMuch++;
            przedzialGora = num-1;//dzieki temu wypada ta opcja
            std::cout << "Teraz gramy na przedziale:\n" << przedzialDol << " - " << przedzialGora;
        }
        else 
        {
            std::cout << "Nie odwalaj maniany";
            break;
        }

    }

    std::cout<<"\nKoniec gry";
   

    return 0;
}

