#include "Defender.hpp"

// Default constructor
// set atribut Footballer dengan nilai default,
// set tackleSuccess dan interceptions ke 0, dan playPosition ke "defender"
// ...
Defender::Defender() : Footballer(){
    this->tackleSuccess = 0;
    this->interceptions = 0;
    this->playPosition = "defender";
}

// User-defined constructor
// parameter: string name, int birthYear, int tackleSuccess, int interceptions
// set atribut dengan nilai parameter, playPosition tetap "defender"
// nationality, height, dan weight gunakan nilai default superclass
// ...
Defender::Defender(const string &name, int birthYear, int tackleSuccess, int interceptions) : Footballer(name, birthYear, "defender", "Indonesia", 180, 70){
    this->tackleSuccess = tackleSuccess;
    this->interceptions = interceptions;
}

// Getter dan Setter untuk tackleSuccess
// setTackleSuccess(...)
// getTackleSuccess()
void Defender::setTackleSuccess(int tackleSuccess){
    this->tackleSuccess = tackleSuccess;
}

int Defender::getTackleSuccess() const{
    return this->tackleSuccess;
}

// Getter dan Setter untuk interceptions
// setInterceptions(...)
// getInterceptions()
void Defender::setInterceptions(int interceptions){
    this->interceptions = interceptions;
}

int Defender::getInterceptions() const{
    return this->interceptions;
}

// Method tambahan: defensiveRating
// rumus: (tackleSuccess * 2) + interceptions
// return dalam bentuk int
// ...
int Defender::defensiveRating() const{
    return (tackleSuccess * 2 + interceptions); 
}

// Override transferRate:
// rumus: (600.000 * tackleSuccess) + (400.000 * interceptions)
// hasil berupa int
// ...
int Defender::transferRate(){
    return (600000 * tackleSuccess) + (400000 * interceptions);
}

// Override displayInfo():
// Cetak info Footballer + atribut tambahan defender (tackleSuccess, interceptions, defensiveRating)
// Format:
// Tackle Success: <tackleSuccess>
// Interceptions: <interceptions>
// Defensive Rating: <defensiveRating>
// ...
void Defender::displayInfo(){
    Footballer::displayInfo();
    cout << "Tackle Success: " << getTackleSuccess() << endl;
    cout << "Interceptions: " << getInterceptions() << endl;
    cout << "Defensive Rating: " << defensiveRating() << endl;
}