#include "cambio.h"

double realToDollar(double real){
    return real / DOLLAR_REAL;
}

double realToEuro(double real) {
    return real / EURO_REAL;
}

double euroToReal(double euro) {
    return euro * EURO_REAL;
}

double dollarToReal(double dollar) {
    return dollar * DOLLAR_REAL;
}
