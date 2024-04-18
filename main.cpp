#include <iostream>
#include <chrono>
#include <random>
#include <limits>
#include <sstream>
#include "priority_queue_heap.h"

int generuj_x_liczb_do_pliku(int x, std::string nazwa_pliku)
{
    // Otwórz plik do zapisu
    std::ofstream outputFile(nazwa_pliku);

    // Sprawdź, czy plik został poprawnie otwarty
    if (!outputFile.is_open()) {
        std::cerr << "Nie można otworzyć pliku do zapisu.";
        return 1;
    }
    // Pobierz minimalną i maksymalną wartość dla typu int
    int min_int = std::numeric_limits<int>::min();
    int max_int = std::numeric_limits<int>::max();
    // Inicjalizuj generator liczb pseudolosowych
    std::random_device rd;
    std::mt19937 gen(rd());
    // Utwórz rozkład równomierny na przedziale [min_int, max_int]
    std::uniform_int_distribution<int> distribution(min_int, max_int);
    // Wygeneruj x losowych liczb i zapisz je do pliku CSV
    for (int i = 0; i < x; ++i) {
        // Wylosuj liczbę z przedziału [min_int, max_int]
        int random_number = distribution(gen);
        
        // Zapisz wylosowaną liczbę do pliku CSV
        outputFile << random_number << ",";
        random_number = distribution(gen);
        outputFile<< random_number << ",";
        
        // Dodaj znak nowej lini, z wyjątkiem ostatniej liczby w wierszu
        if (i < x - 1)
            outputFile << "\n";
    }
    outputFile.close();
    return 0;
}
int main(void)
{
    Priority_queue q{};
    q.load_from_file("random_numbers.csv", 10);
    q.show();
}