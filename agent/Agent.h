#ifndef AGENT_H
#define AGENT_H

class Agent
{
public:
    Agent();

    void setValue(double value);

    double getValue();

private:
    double value_;
};

#endif // AGENT_H
