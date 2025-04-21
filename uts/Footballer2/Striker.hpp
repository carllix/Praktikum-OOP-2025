#ifndef STRIKER_HPP
#define STRIKER_HPP

#include "Footballer.hpp"

class Striker : public Footballer
{
protected:
  // atribut tambahan goalScore (jumlah gol yang dicetak striker)
  // dan shotsOnTarget (jumlah tendangan tepat sasaran)
  // ...
  int goalScore;
  int shotsOnTarget;

public:
  // Default constructor
  // set atribut Footballer dengan nilai default,
  // set goalScore dan shotsOnTarget ke 0, dan playPosition ke "striker"
  // ...
  Striker();

  // User-defined constructor
  // parameter: string name, int birthYear, int goalScore, int shotsOnTarget
  // set atribut dengan nilai parameter, playPosition tetap "striker"
  // nationality, height, dan weight gunakan nilai default superclass
  // ...
  Striker(const string &name, int birthYear, int goalScore, int shotsOnTarget);

  // Getter dan Setter untuk goalScore
  // setGoalScore(...)
  // getGoalScore()
  void setGoalScore(int goalScore);
  int getGoalScore() const;

  // Getter dan Setter untuk shotsOnTarget
  // setShotsOnTarget(...)
  // getShotsOnTarget()
  void setShotsOnTarget(int shotsOnTarget);
  int getShotsOnTarget() const;

  // Method tambahan: menghitung conversion rate dalam persen
  // conversionRate() = (goalScore / shotsOnTarget) * 100
  // return dalam bentuk float
  // Hint: Gunakan static_cast<float> untuk mengonversi int ke float
  // ...
  float conversionRate() const;

  // Override transferRate:
  // rumus: 1.000.000 * goalScore + 10.000 * conversionRate()
  // hasil berupa int
  // ...
  int transferRate() override;

  // Override displayInfo():
  // Cetak info Footballer + atribut tambahan striker (goalScore, conversionRate)
  // Format:
  // Goals: <goalScore>
  // Conversion Rate: <conversionRate>%

  // Hint: Gunakan fixed dan setprecision(2) untuk menampilkan conversionRate
  // Contoh: cout << fixed << setprecision(2) << conversionRate() << "%" << endl;
  // ...
  void displayInfo();
};

#endif
