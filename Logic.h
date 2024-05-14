#ifndef LOGIC_H
#define LOGIC_H
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <random>
#include <ctime>
#include <wx/log.h>

#define MAXGOATS  8
#define MINGOATS  2
#define MAXCARS  8
#define MINCARS  1
#define GOAT 0
#define CAR 1

class Logic
{
    public:
        Logic();
        ~Logic();

        void setNumberOfGoats(const int);
        const int getNumberOfGoats();
        void setNumberOfCars(const int);
        const int getNumberOfCars();
        std::vector<int> shuffleSample(std::vector<int> s);
        void executeSimulation(int, int, int&, int&);

    protected:

    private:
        int numberOfGoats = 2;
        int numberOfCars = 1;
        int numberOfDoors = 3;
        int m_successWithChanges = 0;
        int m_successWithoutChanges = 0;


        std::vector<int> sample;
        std::vector<int> situation;
        void populateSample(std::vector<int>&);
};

#endif // LOGIC_H
