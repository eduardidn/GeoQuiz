#include "GeoQuiz.h"
#include "CountryDatabase.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

GeoQuiz::GeoQuiz(int maxTries)
{
    this->maxTries = maxTries;
    this->currentScore = 0;
    this->remainingTries = maxTries;
}

void GeoQuiz::startGame()
{
    displayWelcomeMessage();

    auto countries = CountryDatabase::getCountryData();
    std::vector<std::string> countryList;
    for (const auto &entry : countries)
    {
        countryList.push_back(entry.first);
    }

    while (remainingTries > 0)
    {
        std::string country = getRandomCountry();
        std::string correctCapital = countries[country];

        std::cout << "What is the capital of " << country << "?" << std::endl;
        std::string userInput;
        std::getline(std::cin, userInput);

        if (userInput == correctCapital)
        {
            std::cout << "Correct! Good job!" << std::endl;
            currentScore++;
        }
        else
        {
            std::cout << "Incorrect! The correct answer is " << correctCapital << "." << std::endl;
            remainingTries--;
        }

        displayScore();
    }

    displayGameOver();
}

void GeoQuiz::displayWelcomeMessage() const
{
    std::cout << "Welcome to GeoQuiz!" << std::endl;
    std::cout << "Test your knowledge of world capitals." << std::endl;
    std::cout << "Rules: You have " << maxTries << " chances to guess correctly. Let's start!" << std::endl;
    std::cout << std::endl;
}

void GeoQuiz::displayScore() const
{
    std::cout << "Current Score: " << currentScore << std::endl;
    std::cout << "Remaining Tries: " << remainingTries << std::endl;
    std::cout << std::endl;
}

void GeoQuiz::displayGameOver() const
{
    std::cout << "Game Over!" << std::endl;
    std::cout << "Final Score: " << currentScore << std::endl;
}

std::string GeoQuiz::getRandomCountry() const
{
    auto countries = CountryDatabase::getCountryData();
    int index = std::rand() % countries.size();
    auto it = std::next(countries.begin(), index);
    return it->first;
}
