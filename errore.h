#ifndef ERRORE_H
#define ERRORE_H

#include <QObject>
#include <QDialog>
#include <QLabel>
#include <QFormLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QtWidgets>
#include "menu.h"

class errore: public QDialog
{
      Q_OBJECT
public:
    errore(QWidget *parent = nullptr);
    QLabel *messaggio;
    QHBoxLayout *errLayout;
    QVBoxLayout *erroreLayout;
};

#endif // ERRORE_H
