#include "Creature.hpp"
#include "Dragon.hpp"

int main() {
    // Lengkapi disini
    Dragon d("Draco");
    d.speak();
    d.wound();
    d.wound();
    d.print();
    
    Creature *c = &d;
    c->wound();
    d.speak();
    c->print();
    d.print();
    
    Creature c2 = d;
    c2.speak();
    c2.wound();
    c2.print();
    d.print();

    
    return 0;
}