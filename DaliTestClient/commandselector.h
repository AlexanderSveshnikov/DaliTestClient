#ifndef COMMANDSELECTOR_H
#define COMMANDSELECTOR_H

#include <QWidget>

namespace Ui {
class CommandSelector;
}

class CommandSelector : public QWidget
{
    Q_OBJECT

public:
    explicit CommandSelector(QWidget *parent = nullptr);
    ~CommandSelector();

private:
    Ui::CommandSelector *ui;
};

#endif // COMMANDSELECTOR_H
