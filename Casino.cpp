#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

class Display
{
public:
    void printMessageCenter(const char* message);
    void headMessage(const char* message);
    void welcomeMessage();
    void drawLine(int n, char symbol);
    void rules();
};

class Player : public Display
{
private:
    string name;
    int deposit_amount;
    int guess_number;
    int betting_amount;

public:
    void setDepositAmount();
    void setBettingAmount();
    void setGuessNumber();
    int generateRandomNumber();
    void win();
    void loss();
    void startGame();
};

void Player::setDepositAmount()
{
    do
    {
        cout << "\nEnter the player name: ";
        cin >> name;
        cout << "\nEnter deposit amount to play the game: $";
        cin >> deposit_amount;
        if (deposit_amount < 0)
        {
            cout << "\nPlease enter a valid amount to play the game!";
        }
    } while (deposit_amount < 0);
}

void Player::setBettingAmount()
{
    headMessage("Set Bet Amount");
    do
    {
        cout << "\nEnter the amount of money to bet: $";
        cin >> betting_amount;
        if (betting_amount > deposit_amount)
        {
            cout << "\nYour wallet balance is: $" << deposit_amount;
            cout << "\nYour betting amount exceeds your current balance.\n";
        }
    } while (betting_amount > deposit_amount);
}

void Player::setGuessNumber()
{
    do
    {
        cout << "\nGuess a number to bet between 1 to 10: ";
        cin >> guess_number;
        if (guess_number <= 0 || guess_number > 10)
        {
            cout << "\nPlease enter a valid number between 1 to 10.\n";
        }
    } while (guess_number <= 0 || guess_number > 10);
}

void Player::win()
{
    int random_num, remaining_amount;
    remaining_amount = deposit_amount - betting_amount;
    cout << "\nCongratulations! You won!\n";
    betting_amount = betting_amount * 10;
    cout << "Your winning amount is: $" << betting_amount << endl;
    deposit_amount = remaining_amount + betting_amount;
    cout << "Your total money in your wallet: $" << deposit_amount << endl;
}

void Player::loss()
{
    cout << "\nBad luck! You lost.\n";
    cout << "The random value was: " << generateRandomNumber() << endl;
    deposit_amount = deposit_amount - betting_amount;
    cout << "Your remaining amount is: $" << deposit_amount << endl;
}

void Player::startGame()
{
    int random_num, remaining_amount;
    char ch;

    do
    {
        setBettingAmount();
        setGuessNumber();

        random_num = generateRandomNumber();

        (random_num == guess_number) ? win() : loss();

        if (deposit_amount == 0)
        {
            break;
        }

        cout << "\nDo you want to play again? (y/n): ";
        cin >> ch;
        cout << "\n";
    } while (ch == 'y');
    cout << "\nThanks for playing the game. Your balance amount is: $" << deposit_amount << "\n\n";
}

int Player::generateRandomNumber()
{
    srand(time(0));
    return 1 + rand() % 10;
}

void Display::drawLine(int n, char symbol)
{
    for (int i = 0; i < n; i++)
    {
        cout << symbol;
    }
    cout << "\n";
}

void Display::rules()
{
    headMessage("RULES OF THE GAME");
    cout << "\n";
    drawLine(80, '-');
    cout << "\t1. Choose any number between 1 to 10\n";
    cout << "\t2. If you win, you will get 10 times the money you bet\n";
    cout << "\t3. If you bet on the wrong number, you will lose your betting amount\n";
    drawLine(80, '-');
    cout << "\n\n\tPress any key to continue...";
    getchar();
}

void Display::printMessageCenter(const char* message)
{
    int len = 0;
    int pos = 0;
    len = (78 - strlen(message)) / 2;
    cout << "\t\t\t";
    for (pos = 0; pos < len; pos++)
    {
        cout << " ";
    }
    cout << message;
}

void Display::headMessage(const char* message)
{
    system("cls");
    cout << "\t\t\t###########################################################################";
    cout << "\n\t\t\t############                                                   ############";
    cout << "\n\t\t\t############             Casino Game Project in C++            ############";
    cout << "\n\t\t\t############                                                   ############";
    cout << "\n\t\t\t###########################################################################";
    cout << "\n\t\t\t---------------------------------------------------------------------------\n";
    printMessageCenter(message);
    cout << "\n\t\t\t----------------------------------------------------------------------------";
}

void Display::welcomeMessage()
{
    cout << "\n\n\n\n\n";
    cout << "\n\t\t\t  *------------------*\n";
    cout << "\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=";
    cout << "\n\t\t\t        =                                           =";
    cout << "\n\t\t\t        =                    WELCOME                =";
    cout << "\n\t\t\t        =                      TO                   =";
    cout << "\n\t\t\t        =                 CASINO GAME               =";
    cout << "\n\t\t\t        =                                           =";
    cout << "\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=";
    cout << "\n\t\t\t  *------------------*\n";
    cout << "\n\n\n\t\t\t Press any key to continue...";
    getchar();
}

int main()
{
    Player player;

    player.welcomeMessage();

    player.setDepositAmount();
    player.rules();

    player.startGame();

    return 0;
}
