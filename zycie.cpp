#include "zycie.h"

Zycie::Zycie(QWidget *parent) :
    QWidget(parent),
    timer(new QTimer(this))
{
    timer->setInterval(300);
    connect(timer, SIGNAL(timeout()), this, SLOT(NowaGeneracja()));
    memset(&tablicaKomorek, false, sizeof(99));

    rozmiar=100;

    for(int k = 0; k < 100; k++) {
        for(int j = 0; j < 100; j++) {
            tablicaKomorek[k][j] = false;
        }
    }

    tablicaKomorek[1][1]=true;
    tablicaKomorek[1][2]=true;
    tablicaKomorek[2][3]=true;
    tablicaKomorek[2][4]=true;


}
// zwracanie intervalu  [NowoDodane]
int Zycie::interval()
{
    return timer->interval();
}

// Ustawianie Intervalu  [NowoDodane]
void Zycie::UstawInterval(int time)
{
    timer->setInterval(time);
}

//  [NowoDodane]
bool Zycie::Dzialaj(int k, int j)
{
    int power = 0;
    power += tablicaKomorek[k+1][j];
    power += tablicaKomorek[k-1][j];
    power += tablicaKomorek[k][j+1];
    power += tablicaKomorek[k][j-1];
    power += tablicaKomorek[k+1][j+1];
    power += tablicaKomorek[k-1][j-1];
    power += tablicaKomorek[k-1][j+1];
    power += tablicaKomorek[k+1][j-1];
    if (((tablicaKomorek[k][j] == true) && (power == 2)) || (power == 3))
           return true;
    return false;
}

// slot zatrzymujący Timer [NowoDodane]
void Zycie::ZatrzymajTimer()
{
        timer->stop();
}

// Metoda odpowiedzialna za cale zycie -- trzeba tu pozmieniac [NowoDodane]
void Zycie::NowaGeneracja()
{
    if(generacja < 0)
        generacja++;
    int notChanged=0;
    for(int k=0; k < 100; k++) {
        for(int j=0; j < 100; j++) {
            tablicaNastepna[k][j] = Dzialaj(k, j);
            if(tablicaNastepna[k][j] == tablicaKomorek[k][j])
                notChanged++;
        }
    }
    if(notChanged == 100*100) {
        QMessageBox::information(this,
                                 tr("Game lost sense"),
                                 tr("The End. Now game finished because all the next generations will be the same."),
                                 QMessageBox::Ok);
        ZatrzymajTimer();
        return;
    }
    for(int k=0; k < 100; k++) {
        for(int j=0; j < 100; j++) {
            tablicaKomorek[k][j] = tablicaNastepna[k][j];
        }
    }
    update();
    generacja--;
    if(generacja == 0) {
        ZatrzymajTimer();
        QMessageBox::information(this,
                                 tr("Game finished."),
                                 tr("Iterations finished."),
                                 QMessageBox::Ok,
                                 QMessageBox::Cancel);
    }




}

// slot startujący działanie  [NowoDodane]
void Zycie::Start(const int &number)
{
    generacja = number;
    timer->start();
}


void Zycie::mousePressEvent(QMouseEvent *e)
{
    double szer = (double)width()/rozmiar;
    double wys = (double)height()/rozmiar;
    int k = floor(e->y()/wys)+1;
    int j = floor(e->x()/szer)+1;
    tablicaKomorek[k][j] = !tablicaKomorek[k][j];
    update();

}


void Zycie::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    malujPiksele(p);

}


void Zycie::malujPiksele(QPainter &p)
{
    double szerokosc = (double)width()/100;
    double wysokosc= (double)height()/100;

    for(int i=0; i<100;i++)
    {
        for(int j=0; j<100;j++)
        {
            if(tablicaKomorek[i][j]==true)
            {
                qreal left = (qreal)(szerokosc*j-szerokosc); // margin from left
                qreal top  = (qreal)(wysokosc*i-wysokosc); // margin from top
                QRectF r(left, top, (qreal)szerokosc, (qreal)wysokosc);
                p.fillRect(r, QBrush(m_masterColor)); // fill cell with brush of main color

            }

        }
    }

}
