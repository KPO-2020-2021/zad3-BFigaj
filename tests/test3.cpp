#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "Macierz2x2.hh"
#include "Wektor2D.hh"

TEST_CASE("Konstruktor bezparametryczny czyli macierz obrotu z 0") {
    Macierz2x2 mtx;
    CHECK(mtx(0,0) == cos(0) );
    CHECK(mtx(0,1) == -sin(0) );
    CHECK(mtx(1,0) == sin(0) );
    CHECK(mtx(1,1) == cos(0) );
}



TEST_CASE("Konstruktor parametryczny czyli macierz obrotu") {
    double i=90;
    Macierz2x2 mtx(90);
    double katrad;
    katrad=(i*M_PI)/180;
    CHECK(mtx(0,0) == cos(katrad) );
    CHECK(mtx(0,1) == -sin(katrad) );
    CHECK(mtx(1,0) == sin(katrad) );
    CHECK(mtx(1,1) == cos(katrad) );
}

TEST_CASE("Operator *") {
    Macierz2x2 mtx;
    Wektor2D v(8,8);
    v=v*mtx;
    CHECK(v[0] == 8 );
    CHECK(v[1] == 8 );
}

TEST_CASE("Operator() z i bez const") {
    Macierz2x2 mtx;
    mtx(0,0)=4;
    mtx(0,1)=3;
    mtx(1,0)=2;
    mtx(1,1)=1;
    CHECK(mtx(0,0) == 4 );
    CHECK(mtx(0,1) == 3 );
    CHECK(mtx(1,0) == 2 );
    CHECK(mtx(1,1) == 1 );
}
