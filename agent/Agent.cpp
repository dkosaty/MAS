#include "Agent.h"

Agent::Agent() : value_(0.0) { }

void Agent::setValue(double value)
{
    this->value_ = value;
}

double Agent::getValue()
{
    return this->value_;
}
