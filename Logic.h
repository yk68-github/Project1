#ifndef LOGIC_H
#define LOGIC_H
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <random>
#include <ctime>
#include <thread>
#include <mutex>
#include <functional>

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
        virtual ~Logic();

        void setNumberOfGoats(const int);
        const int getNumberOfGoats();
        void setNumberOfCars(const int);
        const int getNumberOfCars();
        std::vector<int> shuffleSample(std::vector<int> s);
        const int getSuccessWithChanges() { return successWithChanges; };
        const int getFailureWithChanges() {return failureWithChanges; };
        const int getSuccessWithoutChanges() {return successWithoutChanges; };
        const int getFailureWithoutChanges() {return failureWithoutChanges; };
        void executeSimulation(int);

    protected:

        int numberOfGoats = 2;
        int numberOfCars = 1;
        int numberOfDoors = 3;
        int successWithChanges = 0;
        int failureWithChanges = 0;
        int successWithoutChanges = 0;
        int failureWithoutChanges = 0;

        std::vector<int> sample;
        std::vector<int> situation;
        void populateSample(std::vector<int>&) const;

    private:
};

#endif // LOGIC_H
