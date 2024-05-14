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
            throw std::invalid_argument("Le nombre de chèvre(s) transmis à la fonction de traitement est incorrect.");
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
            throw std::invalid_argument("Le nombre de voiture(s) transmis à la fonction de traitement est incorrect.");
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

void Logic::populateSample(std::vector<int>& s)
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

void Logic::executeSimulation(int numberOfSimulations, int& successWithoutChanges, int& successWithChanges)
{
  if (numberOfSimulations<=0) 
  {
      throw std::invalid_argument("Erreur de logique interne au programme.  Le nombre de simulations doit être supérieur à zéro");
  }

    srand((int)time(NULL) + successWithChanges);
    std::mt19937 eng((int)std::time(NULL) + successWithChanges);
  
    m_successWithChanges = 0;
    m_successWithoutChanges = 0;

    numberOfDoors = numberOfGoats + numberOfCars;

    populateSample(situation);
    situation = shuffleSample(situation);

    if ( ((int(situation.size())!=numberOfDoors)) )
        {
            throw std::invalid_argument("Erreur de logique interne au programme.  Le nombre de portes n'est pas égal à la somme des chèvres et des voitures !");
        }

        int firstChoice = -1;
        int newChoice = -1;

        // Choix sans changement

        for(int i = 0; i<numberOfSimulations; i++)
        {
            firstChoice = rand()%numberOfDoors;
            if (situation.at(firstChoice)==CAR)
            {
                m_successWithoutChanges++;
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
                m_successWithChanges++;
            }
    }
        successWithoutChanges = m_successWithoutChanges;
        successWithChanges = m_successWithChanges;
        
   return;
}
