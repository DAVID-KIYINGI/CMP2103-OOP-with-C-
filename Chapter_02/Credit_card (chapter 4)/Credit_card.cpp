#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function prototypes
vector<int> readCardNumber();
int getPrefix(const vector<int>& number, int k);
bool prefixMatched(const vector<int>& number);
int getSize(const vector<int>& number);
int getDigit(int number);
int sumOfDoubleEvenPlace(const vector<int>& number);
int sumOfOddPlace(const vector<int>& number);
bool isValid(const vector<int>& number);

int main()
{
    vector<int> number = readCardNumber();

    if (number.empty()) {
        cout << "Error: No valid digits entered.\n";
        return 1;
    }

    cout << "Card Length: " << getSize(number) << "\n";
    cout << "Prefix (3 digits): " << getPrefix(number, 3) << "\n";
    cout << "Prefix Matched: " << (prefixMatched(number) ? "True" : "False") << "\n";
    cout << "Sum of Double Even Places: " << sumOfDoubleEvenPlace(number) << "\n";
    cout << "Sum of Odd Places: " << sumOfOddPlace(number) << "\n";
    
    if (isValid(number))
    {
        cout << "Result: The credit card number is VALID.\n";
    }
    else
    {
        cout << "Result: The credit card number is INVALID.\n";
    }

    return 0;
}

// Reads card digits from input as a string and converts to vector<int>
vector<int> readCardNumber()
{
    string numberStr;
    cout << "Enter credit card number: ";
    cin >> numberStr;

    vector<int> card_digits;
    for (char ch : numberStr)
    {
        if (ch >= '0' && ch <= '9')
        {
            card_digits.push_back(ch - '0');
        }
    }
    return card_digits;
}

// Returns card size
int getSize(const vector<int>& number)
{
    return number.size();
}

// Returns the first k digits of the card
int getPrefix(const vector<int>& number, int k)
{
    if (number.size() < static_cast<size_t>(k))
    {
        k = number.size();
    }

    int k_prefix = 0;
    for (int i = 0; i < k; i++)
    {
        k_prefix = k_prefix * 10 + number[i];
    }
    return k_prefix;
}

// Validates whether the prefix matches standard card prefixes (4, 5, 37, 6)
bool prefixMatched(const vector<int>& number)
{
    int p1 = getPrefix(number, 1);
    int p2 = getPrefix(number, 2);

    return (p1 == 4 || p1 == 5 || p1 == 6 || p2 == 37);
}

// Returns the single digit or sum of two digits for Luhn's algorithm
int getDigit(int number)
{
    if (number < 10)
    {
        return number;
    }
    return (number / 10) + (number % 10);
}

// Sum of doubled digits from right-to-left in second-to-last positions (Luhn's algorithm)
int sumOfDoubleEvenPlace(const vector<int>& number)
{
    int sum = 0;
    int n = number.size();
    
    for (int i = n - 2; i >= 0; i -= 2)
    {
        sum += getDigit(number[i] * 2);
    }
    return sum;
}

// Sum of digits in odd places counting right-to-left
int sumOfOddPlace(const vector<int>& number)
{
    int sum = 0;
    int n = number.size();
    
    for (int i = n - 1; i >= 0; i -= 2)
    {
        sum += number[i];
    }
    return sum;
}

// Validates length, prefix match, and Luhn checksum
bool isValid(const vector<int>& number)
{
    int totalSize = getSize(number);
    bool validSize = (totalSize >= 13 && totalSize <= 16);
    bool validPrefix = prefixMatched(number);
    bool validChecksum = ((sumOfDoubleEvenPlace(number) + sumOfOddPlace(number)) % 10 == 0);

    return (validSize && validPrefix && validChecksum);
}