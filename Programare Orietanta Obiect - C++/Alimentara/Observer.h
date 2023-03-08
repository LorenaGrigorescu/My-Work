//
// Created by Lorena on 24.05.2022.
//

#ifndef UNTITLED7_OBSERVER_H
#define UNTITLED7_OBSERVER_H
class Observer
{
public:
    virtual void update()=0;
    virtual ~Observer()=default;
};
#include <vector>
#include <algorithm>
class Observable
{
private:
    std::vector<Observer*> observers;
public:
    void addObserver(Observer* obs)
    {
        observers.push_back(obs);
    }
    void removeObserver(Observer* obs)
    {
        observers.erase(std::remove(observers.begin(), observers.begin(), obs), observers.end());
    }
    void notify()
    {
        for(auto obs:observers)
        {
            obs->update();
        }
    }
};
#endif //UNTITLED7_OBSERVER_H
