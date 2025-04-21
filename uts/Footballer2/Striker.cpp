#include "Striker.hpp"

// Default constructor
// set atribut Footballer dengan nilai default,
// set goalScore dan shotsOnTarget ke 0, dan playPosition ke "striker"
// ...
Striker::Striker() : Footballer() {
    this->goalScore = 0;
    this->shotsOnTarget = 0;
    this->playPosition = "striker";
}

// User-defined constructor
// parameter: string name, int birthYear, int goalScore, int shotsOnTarget
// set atribut dengan nilai parameter, playPosition tetap "striker"
// nationality, height, dan weight gunakan nilai default superclass
// ...
Striker::Striker(const string &name, int birthYear, int goalScore, int shotsOnTarget) : Footballer(name, birthYear, "striker", "Indonesia", 180, 70) {
    this->goalScore = goalScore;
    this->shotsOnTarget = shotsOnTarget;
}

// Getter dan Setter untuk goalScore
// setGoalScore(...)
// getGoalScore()
void Striker::setGoalScore(int goalScore){
    this->goalScore = goalScore;
}

int Striker::getGoalScore() const{
    return this->goalScore;
}

// Getter dan Setter untuk shotsOnTarget
// setShotsOnTarget(...)
// getShotsOnTarget()
void Striker::setShotsOnTarget(int shotsOnTarget){
    this->shotsOnTarget = shotsOnTarget;
}

int Striker::getShotsOnTarget() const{
    return this->shotsOnTarget;
}

// Method tambahan: menghitung conversion rate dalam persen
// conversionRate() = (goalScore / shotsOnTarget) * 100
// return dalam bentuk float
// Hint: Gunakan static_cast<float> untuk mengonversi int ke float
// ...
float Striker::conversionRate() const{
    if (shotsOnTarget == 0) return 0.0;
    return (static_cast<float>(goalScore) / shotsOnTarget) * 100;
}

// Override transferRate:
// rumus: 1.000.000 * goalScore + 10.000 * conversionRate()
// hasil berupa int
// ...
int Striker::transferRate(){
    return static_cast<int>(1000000 * goalScore + 10000.0f * conversionRate());
}

// Override displayInfo():
// Cetak info Footballer + atribut tambahan striker (goalScore, conversionRate)
// Format:
// Goals: <goalScore>
// Conversion Rate: <conversionRate>%

// Hint: Gunakan fixed dan setprecision(2) untuk menampilkan conversionRate
// Contoh: cout << fixed << setprecision(2) << conversionRate() << "%" << endl;
// ...
void Striker::displayInfo(){
    Footballer::displayInfo();
    cout << "Goals: " << getGoalScore() << endl;
    cout << "Conversion Rate: " << fixed << setprecision(2) << conversionRate() << "%" << endl;
}