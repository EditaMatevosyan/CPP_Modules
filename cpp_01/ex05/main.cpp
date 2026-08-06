#include "Harl.hpp"

int main(){
    Harl err1;
    err1.complain("WARNING");
    err1.complain("DEBUG");
    err1.complain("INFO");
    err1.complain("ERROR");
}