#include <cstdlib>
#include <ctime>
#include <iostream>
#include <utility>
#include "bj.h"

using namespace std;

const int MAX_SIZE = 100;

int main() {
    char choice = 'y';
    int cards[MAX_SIZE];
    int numCards = 0;
    int totalScore = 0;
    int newCard = 0;

    srand(time(nullptr));
    printPrompt();
    cards[numCards++] = initialDraw(rand() % 1024 + 1);
    cards[numCards++] = initialDraw(rand() % 1024 + 1);
    totalScore = getSum(cards, numCards);
    cout << "Your cards: ";
    for (int i = 0; i < numCards; i++) {
        cout << cards[i] << " ";
    }
    cout << "\nYour total score: " << totalScore << endl;
    while (checkScore(totalScore) && choice == 'y') {
        cout << "Would you like to draw again? <y> or <n>" << endl;
        cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            newCard = drawOne();
            cards[numCards++] = newCard;
            totalScore = getSum(cards, numCards);
            cout << "Your new card: " << newCard << endl;
            cout << "Your cards: ";
            for (int i = 0; i < numCards; i++) {
                cout << cards[i] << " ";
            }
            cout << "\nYour total score: " << totalScore << endl;
        }
    }
    if (totalScore > 21) {
        cout << "Bust! Your score is over 21." << endl;
    } else {
        cout << "You win! Your score is " << totalScore << endl;
    }
    return 0;
}

int initialDraw(int seed) {
    srand(seed);
    int randomNumber = rand() % 12 + 1;
    return randomNumber;
}

int getSum(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

int drawOne() {
    int newCard = rand() % 12 + 1;
    return newCard;
}

void printPrompt() {
    cout << "Welcome to the blackjack game..\n"
            "Get as close to 21 without going over, good luck!\n";
}

bool checkScore(int score) {
    return (score < 21);
}
