#include <QCoreApplication>
#include <QCommandLineParser>
#include <QProcess>
#include <QDebug>

struct CommandLineArgs
{
    CommandLineArgs(const QCoreApplication& app)
    {
        QCommandLineParser parser;

        QCommandLineOption option("agents-count", "The agents count", "0");

        parser.addOption(option);

        parser.process(app);

        this->agentsCount = parser.value(option).toInt();
    }

    int agentsCount;
};

int main(int argc, char* argv[])
{
    srand(uint(time(nullptr)));

    QCoreApplication app(argc, argv);

    CommandLineArgs* args = new CommandLineArgs(app);

    QVector<QProcess*> processes(args->agentsCount);

    for (QProcess* process : processes)
    {
        process = new QProcess;

        QStringList args = {"--value", QString::number(rand() / double(RAND_MAX))};

        process->start("../agent/agent", args);

        if (!process->waitForStarted() || !process->waitForFinished())
        {
            qDebug() << "The process both doesn't start and finish";

            return 1;
        }

        qDebug() << process->readAllStandardOutput();

        qDebug() << process->readAllStandardError();
    }

    return 0;
}
