#ifndef MENU_H
#define MENU_H

#include <QMenuBar>
#include <QVBoxLayout>

#include <QWidget>

class menu : public QWidget
{
    Q_OBJECT
public:
    explicit menu(QWidget *parent = nullptr);

signals:

public slots:

private:

    QVBoxLayout *mainLayout;

    void addMenu();
};

#endif // MENU_H
