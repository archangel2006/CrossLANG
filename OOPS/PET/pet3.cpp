// run : g++ pet.cpp -o pet -std=c++11 -fexec-charset=UTF-8


#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <windows.h>


using namespace std;

class Pet {
private:
    string name;
    int hunger, happiness, energy;

public:
    Pet(string n) : name(n), hunger(50), happiness(50), energy(50) {}

    void feed() {
        hunger = min(hunger + 20, 100);
        happiness = min(happiness + 5, 100);
        cout << name << " is eating 🍖\n";
    }

    void play() {
        if (energy > 10) {
            happiness = min(happiness + 20, 100);
            energy -= 10;
            cout << name << " is playing 🎾\n";
        } else {
            cout << name << " is too tired to play 😴\n";
        }
    }

    void sleep() {
        energy = min(energy + 30, 100);
        hunger -= 10;
        cout << name << " is sleeping 💤\n";
    }

    void tick() { // time passing
        hunger -= 5;
        happiness -= 5;
        energy -= 5;
    }

    void showStatus() {
        cout << "\n--- " << name << "'s Status ---\n";
        cout << "Hunger: " << hunger << "\n";
        cout << "Happiness: " << happiness << "\n";
        cout << "Energy: " << energy << "\n";
    }

    bool isAlive() {
        return hunger > 0 && happiness > 0 && energy > 0;
    }
};

int main() {
    SetConsoleOutputCP(CP_UTF8);

    Pet pet("Fluffy");

    while (pet.isAlive()) {
        pet.showStatus();
        cout << "\nChoose action: (1) Feed (2) Play (3) Sleep\n> ";
        int choice;
        cin >> choice;

        switch(choice) {
            case 1: pet.feed(); break;
            case 2: pet.play(); break;
            case 3: pet.sleep(); break;
            default: cout << "Invalid choice!\n";
        }

        pet.tick();
        clock_t start_time = clock();
        while (clock() < start_time + 1000);
    }

    cout << "\nOh no! Your pet has passed away 💔\n";
    return 0;
}
