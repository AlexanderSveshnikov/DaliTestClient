#ifndef ADDRESSSELECTOR_H
#define ADDRESSSELECTOR_H

#include <QWidget>

namespace Ui {
class addressSelector;
}

class addressSelector : public QWidget
{
    Q_OBJECT

public:
    explicit addressSelector(QWidget *parent = nullptr);
    ~addressSelector();

private:
    Ui::addressSelector *ui;
};

#endif // ADDRESSSELECTOR_H
