#ifndef GEOQUIZ_HPP
#define GEOQUIZ_HPP

#include <string>
#include <vector>

class GeoQuiz
{
public:
    GeoQuiz(int maxTries);
    void startGame();

private:
    int maxTries;
    int currentScore;
    int remainingTries;

    void displayWelcomeMessage() const;
    void displayScore() const;
    void displayGameOver() const;
    std::string getRandomCountry() const;
    std::string getCorrectCapital(const std::string &country) const;
};

#endif // GEOQUIZ_HPP