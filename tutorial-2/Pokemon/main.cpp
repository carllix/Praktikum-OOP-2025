#include "Pokemon.hpp"
#include "WaterPokemon.hpp"
#include "GrassPokemon.hpp"
#include "FirePokemon.hpp"

int main(){
    FirePokemon f1("Charmander");
    WaterPokemon f2("Squirtle",100,20,10);
    f2.heal(10);
    f2.attack(f1);
    f1.attack(f2);
    f2.attack(f1);
    GrassPokemon f3("Bulbasaur",100,50,20);
    f2.attack(f3);
    f3.attack(f2);

    return 0;
}