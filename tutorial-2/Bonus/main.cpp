#include "Pokemon.hpp"
#include "WaterPokemon.hpp"
#include "GrassPokemon.hpp"
#include "FirePokemon.hpp"

int main(){
    FirePokemon *f1 = new FirePokemon("Charmander");
    FirePokemon *f2 = new FirePokemon(*f1);

    WaterPokemon *w1 = new WaterPokemon("Squirtle",100,20,10);
    w1->heal(10);

    WaterPokemon *w2 = new WaterPokemon("Magikarp");
    *w2 = *w1;

    w2->attack(*f1);
    w2->attack(*f1);


    delete f1;
    delete w1;
    return 0;
}