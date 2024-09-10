#include <cstdlib>
#include <random>
#include <iostream>
#include <string>

using namespace std;

bool ranNumGen = false;
int playersHand, dealersHand;

int randomNumGen(int from, int to) {
    if (!ranNumGen) srand(time(0));
    return rand() % (to - from + 1) + from;

}

bool promptToHit() {
    /* if this returns true then the player want to hit
    */
   while (true) {
        printf("You currently have %d. Do you want to (h)it or (s)tand: ", playersHand);
        string playerOption;
        cin >> playerOption;
        if (playerOption == "hit" || playerOption[0] == 'h') {
            playersHand += randomNumGen(1,10);
            return true;
            }
        else if (playerOption == "stay" || playerOption[0] == 's') return false;
        else cout << "Error: That is not an option try again.";
   }
}



bool gameOver() {
    char playerResponse;
    if (playersHand > 21) {
        printf("You have busted with the amount of %d. ", playersHand);
    } else if (dealersHand > 21) {
        printf("You have won! The dealer has buseted and you won with the amount of %d. ", playersHand);
    } else if (dealersHand > 21 && playersHand > 21) {
        printf("You drawed! Both you and the dealer busted. You busted with the amount of %d. ", playersHand);
    } else if (playersHand >= dealersHand) {
        printf("You won! You had a hand of %d. ", playersHand);
    } else if (playersHand < dealersHand) {
        printf("You lost! You had a hand of %d while the dealer had %d. ", playersHand, dealersHand);
    }
    cout << "Do you want to play again? y/N ";
    cin >> playerResponse;
    if (playerResponse == 'Y' || playerResponse == 'y') {
        return false;
    } else if (playerResponse == 'n' || playerResponse == 'N') return true;
    else return gameOver();
}

int main() {
    bool wantsHit = true;

    cout << "This is Blackjack. you will receive a number that is in the range of 2-20.\nYou can then hit which will add 1-10.\n";
    cout << "to hit type (h)it, to stay type (s)tay.";
    while (true) {

        playersHand = 0;
        dealersHand = 0;

        playersHand = randomNumGen(2, 20);

        while (dealersHand < 17) dealersHand += randomNumGen(1, 10);
        while (wantsHit) {
            wantsHit = promptToHit();
            if (!wantsHit || playersHand >= 21) {
                if (gameOver()) return 0;
                else break;
            }
        }
    }
    return 0;
}

