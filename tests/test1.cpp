#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "Prostokat.hh"
#define PRECISION 0.0000000001

TEST_CASE("Konstruktor bezparametryczny"){
    Prostokat Pr;
    double x,y;
    x=y=10;
    CHECK(Pr[0] == x);
    CHECK(Pr[1] == y+KR_BOK);
    CHECK(Pr[2] == x+DL_BOK);
    CHECK(Pr[3] == y+KR_BOK);
    CHECK(Pr[6] == x);
    CHECK(Pr[5] == y);
    CHECK(Pr[4] == x+DL_BOK);
    CHECK(Pr[7] == y);

}

TEST_CASE("Konstruktor parametryczny"){
    double x=5,y=10;
    Prostokat Pr(x,y);
    CHECK(Pr[0] == x);
    CHECK(Pr[1] == y+KR_BOK);
    CHECK(Pr[2] == x+DL_BOK);
    CHECK(Pr[3] == y+KR_BOK);
    CHECK(Pr[6] == x);
    CHECK(Pr[5] == y);
    CHECK(Pr[4] == x+DL_BOK);
    CHECK(Pr[7] == y);
}


TEST_CASE("Translacja wektora"){
    Prostokat Pr;
    double x,y,a=2,b=4;
    Wektor2D vec(a,b);
    Pr.przesunieciewektor(vec);
    x=y=10;
    CHECK(Pr[0]-(x+a)<PRECISION);
    CHECK(Pr[1]-(y+KR_BOK+b)<PRECISION);
    CHECK(Pr[2]-(x+DL_BOK+a)<PRECISION);
    CHECK(Pr[3]-(y+KR_BOK+b)<PRECISION);
    CHECK(Pr[6]-(x+a)<PRECISION);
    CHECK(Pr[5]-(y+b)<PRECISION);
    CHECK(Pr[4]-(x+DL_BOK+a)<PRECISION);
    CHECK(Pr[7]-(y+b)<PRECISION);
}

TEST_CASE("Rotacja +"){
    Prostokat Pr;
    Pr.rotacja(360);
    double x,y;
    x=y=10;
    CHECK(Pr[0]-(x)<PRECISION);
    CHECK(Pr[1]-(y+KR_BOK)<PRECISION);
    CHECK(Pr[2]-(x+DL_BOK)<PRECISION);
    CHECK(Pr[3]-(y+KR_BOK)<PRECISION);
    CHECK(Pr[6]-(x)<PRECISION);
    CHECK(Pr[5]-(y)<PRECISION);
    CHECK(Pr[4]-(x+DL_BOK)<PRECISION);
    CHECK(Pr[7]-(y)<PRECISION);

}

TEST_CASE("Rotacja -"){
    Prostokat Pr;
    Pr.rotacja(-360);
    double x,y;
    x=y=10;
    CHECK(Pr[0]-(x)<PRECISION);
    CHECK(Pr[1]-(y+KR_BOK)<PRECISION);
    CHECK(Pr[2]-(x+DL_BOK)<PRECISION);
    CHECK(Pr[3]-(y+KR_BOK)<PRECISION);
    CHECK(Pr[6]-(x)<PRECISION);
    CHECK(Pr[5]-(y)<PRECISION);
    CHECK(Pr[4]-(x+DL_BOK)<PRECISION);
    CHECK(Pr[7]-(y)<PRECISION);

}

