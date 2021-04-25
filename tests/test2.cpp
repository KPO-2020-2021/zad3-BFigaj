#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "Wektor2D.hh"

TEST_CASE("Konstruktor bezparametryczny") {
    Wektor2D vec;
    CHECK(vec[0] == 0);
    CHECK(vec[1] == 0);
}



TEST_CASE("Konstruktor parametryczny") {
    Wektor2D vec(4,5);
    CHECK(vec[0] == 4);
    CHECK(vec[1] == 5);
}

TEST_CASE("Dodawanie i porownywanie") {
    Wektor2D vec(4,5),vek(4,3);
    Wektor2D v(8,8);
   CHECK(v == vec + vek);
}

TEST_CASE("Dodawanie i porownywanie") {
    Wektor2D vec(4,5),vek(4,3);
    Wektor2D v(8,8);
   CHECK(v == vec + vek);
}
TEST_CASE("Odejmowanie i porownywanie") {
    Wektor2D vec(4,5),vek(4,3);
    Wektor2D v(0,2);
   CHECK(v == vec - vek);
}
TEST_CASE("Operator[] z const i bez") {
    Wektor2D vec;
    vec[0]=1;
   CHECK(vec[0] == 1);
}
