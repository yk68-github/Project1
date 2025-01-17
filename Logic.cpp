#include "Logic.h"

Logic::Logic()
{
    //ctor
    srand((int)time(NULL));
}

Logic::~Logic()
{
    //dtor
}

void Logic::setNumberOfGoats(const int g)
{
    if ( (g<MINGOATS) || (g>MAXGOATS) )
        {
            throw std::invalid_argument("Le nombre de ch�vre(s) transmis � la fonction de traitement est incorrect.");
        }
        else
        {
          numberOfGoats = g;
        }
}

void Logic::setNumberOfCars(const int c)
{
    if ( (c<MINCARS) || (c>MAXCARS) )
        {
            throw std::invalid_argument("Le nombre de voiture(s) transmis � la fonction de traitement est incorrect.");
        }
        else
        {
          numberOfCars = c;
        }
}

const int Logic::getNumberOfGoats()
{
    return numberOfGoats;
}

const int Logic::getNumberOfCars()
{
    return numberOfCars;
}

void Logic::populateSample(std::vector<int>& s) const
{
    s.clear();
    for(int i = 0; i < numberOfGoats; i++)
    {
        s.push_back(GOAT);
    }

    for(int i = 0; i < numberOfCars; i++)
    {
        s.push_back(CAR);
    }
}

std::vector<int> Logic::shuffleSample(std::vector<int> s)
{
    std::mt19937 eng((int)std::time(NULL));
    std::shuffle(s.begin(), s.end(), eng);
    return s;
}

bool Logic::executeSimulation(int numberOfSimulations)
{
  if (numberOfSimulations<=0) return false;

    successWithChanges = 0;
    failureWithChanges = 0;
    successWithoutChanges = 0;
    failureWithoutChanges = 0;
    numberOfDoors = numberOfGoats + numberOfCars;

    populateSample(situation);
    situation = shuffleSample(situation);

    if ( ((int(situation.size())!=numberOfDoors)) )
        {
            throw std::invalid_argument("Erreur de logique interne au programme.  Le nombre de portes n'est pas �gal � la somme des ch�vres et des voitures !");
        }

        int firstChoice = -1;
        int newChoice = -1;

        // Choix sans changement

        for(int i = 0; i<numberOfSimulations; i++)
        {
            firstChoice = rand()%numberOfDoors;
            if (situation.at(firstChoice)==CAR)
            {
                successWithoutChanges++;
            }
        }

        // Choix avec changement

        int oneGoat = 0;
        for(int i = 0; i<numberOfSimulations; i++)
        {
            firstChoice = rand()%numberOfDoors;

            do
            {
                oneGoat = rand()%numberOfDoors;
            } while ( (situation.at(oneGoat)!=GOAT) || (firstChoice==oneGoat) );

            do
            {
                newChoice = rand()%numberOfDoors;
            } while ( (newChoice==firstChoice) || (newChoice==oneGoat) );

            if (situation.at(newChoice)==CAR)
            {
                successWithChanges++;
            }
    }
   return true;
}
