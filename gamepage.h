#ifndef GAMEPAGE_H
#define GAMEPAGE_H

#include "bullet.h"
#include "clickablelabel.h"
#include "clickablelabel2.h"
#include <QApplication>
#include <QMainWindow>
#include <QTabWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QTimer>
#include <QString>
#include <QDebug>
#include <map>
#include <utility>
#include <QList>
#include <QMouseEvent>
#include <QGroupBox>

namespace Ui {
class Gamepage;
}

class Gamepage : public QWidget
{
    Q_OBJECT

public:

    explicit Gamepage(QWidget *parent = nullptr);
    ~Gamepage();
    void changeLabelColor();
    QLabel *label_2;
    static QVector<Enemy*> enimi;

private slots:
    void on_pushButton_2_clicked();

private:
    std::map<std::pair<int, int>, std::pair<int, int>> matrix;
    void addMatrix();
    Ui::Gamepage *ui;
    static std::vector <int> cartbar;
    void on_pushButton_clicked();
    void moveObject(Enemy *label);
    void createBlueSquareLabel();
    QTimer *timer;
    QTimer *timer2;
    int labelCount;
    void labelClicked();
    void labelClicked2();
    void mousePressEvent(QMouseEvent *event) override;
    void mousePressEvent2(QMouseEvent *event);
    QPoint position = QPoint(50, 50);
    static bool check;
    ClickableLabel *selectedLabel;
    ClickableLabel2 *selectedLabel2;
    QVector<ClickableLabel*> labels;
    void createLabelsInGroupBox(int initialCount);
    void createNewLabel(QPoint position);
    bool isPositionOccupied(QRect position);
    void createLabelMap( int startx , int starty);
    bool checkMap(QMouseEvent *event);
    int wCount;
    int timeCount;
    void timeLabelText();
    int icount;
};

#endif // GAMEPAGE_H
