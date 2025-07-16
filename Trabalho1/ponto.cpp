#include "ponto.h"

#include <cmath>
#include <iostream>

double Ponto::MAX_X=100.00;

Ponto::Ponto()
{
    this->x=0;
    this->y=0;
}

Ponto::Ponto(double x, double y) {
    this->x = x;
    this->y = y;
}

Ponto::Ponto(const Ponto &p) {
    this->x = p.x;
    this->y = p.y;
}

void Ponto::setMAX_X ( double max ) {
    MAX_X = max;
}

double Ponto::getX() const
{
    return x;
}

void Ponto::setX(double newX)
{
    x = newX;
}

double Ponto::getY() const
{
    return y;
}

void Ponto::setY(double newY)
{
    y = newY;
}

void Ponto::move ( ) {
    x = 0;
    y = 0;
}

void Ponto::move ( double x, double y ) {
    this->x = x;
    this->y = y;
}

void Ponto::move ( const Ponto &p ) {
    this->x = p.x;
    this->y = p.y;
}

double Ponto::distancia ( const Ponto &p ) {
    return sqrt( pow(x-p.x,2) + pow(y-p.y,2) );
}

bool Ponto::equais ( const Ponto &p ) {
    return x==p.x && y==p.y;
}

std::string Ponto::mostrar ( ) {
    return "(" + std::to_string ( x ) +
            "," + std::to_string ( y ) +
            ")";
}

Ponto::~Ponto() {
    std::cout << "Destruindo ponto\n";
}