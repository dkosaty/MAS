#include <iostream>

#include <QCoreApplication>
#include <QCommandLineParser>

#include "Agent.h"

using namespace std;

struct CommandLineArgs
{
    CommandLineArgs(const QCoreApplication& app)
    {
        QCommandLineParser parser;

        QCommandLineOption option("value", "The agent value", "0.0");

        parser.addOption(option);

        parser.process(app);

        this->value = parser.value(option).toDouble();
    }

    double value;
};

int main(int argc, char* argv[])
{
    QCoreApplication app(argc, argv);

    CommandLineArgs* args = new CommandLineArgs(app);

    Agent* agent = new Agent;

    agent->setValue(args->value);

    cout << agent->getValue() << endl;

    delete agent;

    delete args;

    return 0;
}
