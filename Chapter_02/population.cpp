// (Population projection) UBoS projects population based on the
// following assumptions:
// One birth every 7 seconds
// One death every 13 seconds
// One new immigrant every 45 seconds
// Write a program to display the population for each of the next five years. Assume the current population is 312032486 and one year has 365 days.

#include <iostream>

using namespace std;

int main() {
    // Initial population (using long long to prevent overflow)
    long long population = 312032486LL;

    // Calculate total seconds in one year (365 days)
    long long secondsPerYear = 365 * 24 * 60 * 60;

    // Calculate annual demographic changes based on assumptions
    long long annualBirths = secondsPerYear / 7;
    long long annualDeaths = secondsPerYear / 13;
    long long annualImmigrants = secondsPerYear / 45;

    // Net population increase per year
    long long netIncrease = annualBirths - annualDeaths + annualImmigrants;
    
    // Display the population for each of the next 5 years
    for (int year = 1; year <= 5; ++year) {
        population += netIncrease;
        cout << "Year " << year << " projected population: " << population << endl;
        }
    
    return 0;}