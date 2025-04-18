#ifndef MIDFIELDER_HPP
#define MIDFIELDER_HPP

#include "Footballer.hpp"

class Midfielder : public Footballer
{
protected:
  // atribut tambahan assist (jumlah assist) dan keyPasses (jumlah umpan kunci)
  // ...
  int assist;
  int keyPasses;

public:
  // Default constructor
  // set atribut Footballer dengan nilai default,
  // set assist dan keyPasses ke 0, dan playPosition ke "midfielder"
  // ...
  Midfielder();

  // User-defined constructor
  // parameter: string name, int birthYear, int assist, int keyPasses
  // set atribut dengan nilai parameter, playPosition tetap "midfielder"
  // nationality, height, dan weight gunakan nilai default superclass
  // ...
  Midfielder(const string &name, int birthYear, int assist, int keyPasses);

  // Getter dan Setter untuk assist
  // setAssist(...)
  // getAssist()
  void setAssist(int assist);
  int getAssist() const;

  // Getter dan Setter untuk keyPasses
  // setKeyPasses(...)
  // getKeyPasses()
  void setKeyPasses(int keyPasses);
  int getKeyPasses() const;

  // Method tambahan: menghitung playmakerRating
  // rumus: (assist * 3) + keyPasses
  // return dalam bentuk int
  // ...
  int playmakerRating() const;

  // Override transferRate:
  // rumus: (800.000 * assist) + (30.000 * keyPasses)
  // hasil berupa int
  // ...
  int transferRate() override;

  // Override displayInfo():
  // Cetak info Footballer + atribut tambahan midfielder (assist, keyPasses, playmakerRating)
  // Format:
  // Assists: <assist>
  // Key Passes: <keyPasses>
  // Playmaker Rating: <playmakerRating>
  void displayInfo();
};

#endif
