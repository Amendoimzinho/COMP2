#ifndef PONTO_H
#define PONTO_H

#include <string>

class Ponto
{
protected:
    static double MAX_X;
    double x;
    double y;
public:
    Ponto();
    Ponto(double x, double y);
    Ponto(const Ponto &p);

    void setMAX_X ( double max );

    double getX() const;
    void setX(double newX);
    double getY() const;
    void setY(double newY);

    void move ( );
    void move ( double x, double y );
    void move ( const Ponto &p );

    double distancia ( const Ponto &p );
    bool equais ( const Ponto &p );

    std::string mostrar ( );

    ~Ponto();
};


#endif // PONTO_H
