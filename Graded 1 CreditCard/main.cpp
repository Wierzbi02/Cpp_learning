#include <iostream>
#include "CreditCard.h"

using namespace std;

int main() {

    cout << "\n********************* PART 2 *********************\n\n";

    CreditCard card1{"5469 7455 5465 5424", "12/2023"};
    CreditCard card2{"9378-1235-2313-2222", "03/2025", 42};
    CreditCard card3{"3554//2343//3223//2132", card2};
    CreditCard card4{"       7231         3543       8786    2154             ", card2, 123};

    std::cout << "\n********************* PART 3 *********************\n\n";

    cout << card1 << endl;
    cout << card2 << endl;
    cout << card3 << endl;
    cout << card4 << endl;

    cin >> card1;
    cout << card1 << endl;

    cin >> card2;
    cout << card2;

    cout << "\n********************* PART 4 *********************\n\n";

    if (card1 < card2) {
        cout << "Card 1 has an earlier expiration date than Card 2" << endl;
    }

    if (card1 >= card2) {
        cout << "Card 1 has a greater or equal expiration date than Card 2" << endl;
    }

    cout << "\n********************* PART 5 *********************\n\n";

    cout << card1 << endl;
    cout << "Buying a PlayStation" << endl;
    card1.BuyItem("PlayStation");
    cout << card1 << endl;
    cout << "Buying a PlayStation 5 times" << endl;
    card1.BuyItem(5);
    cout << card1;

    cout << "\n********************* PART 6 *********************\n\n";

    card1 += 10;
    cout << card1 << endl;
    card1 += card2;
    cout << card1 << endl;

    return 0;
}