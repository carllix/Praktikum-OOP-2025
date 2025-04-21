#ifndef FOOTBALLER_HPP
#define FOOTBALLER_HPP

#include <iostream>
#include <iomanip>

using namespace std;

#define CURRENT_YEAR 2025

class Footballer
{
protected:
  string name;
  string playPosition;
  int birthYear;

  string nationality;
  int height;
  int weight;

public:
  // Default cosntructor set nilai attribut sebagai berikut:
  // name = "noname"; birthYear = 2000; playPosition = "none";
  // nationality = "Indonesia"; height = 180, weight = 70
  // ...

  Footballer();

  // User-defined constructor:
  // set nilai atribut berdasarkan nilai parameter masukan
  // dengan urutan: name, birthYear, playPosition, nationality, height, weight
  // ...
  Footballer(const string& name, int birthYear, const string& playPosition, const string& nationality, int height, int weight);

  // Copy constructor
  // ...
  Footballer(const Footballer &other);

  // Destructor
  // ...
  ~Footballer();

  // Operator assignment
  // ...
  Footballer &operator=(const Footballer &other);

  // Getter dan setter name
  string getName() const;
  void setName(const string& name);


  // Getter dan setter playPosition
  string getPlayPosition() const;
  void setPlayPosition(const string& playPosition);

  // Getter dan setter nationality
  string getNationality() const;
  void setNationality(const string& nationality);

  // Getter dan setter height and weight
  void setHeight(int height);
  int getHeight() const;
  void setWeight(int weight);
  int getWeight() const;

  // gunakan CURRENT_YEAR untuk menghitung umur
  // getAge()
  int getAge() const;

  // gunakan height and weight untuk menghitung BMI
  float getBMI() const;
  // BMI = weight(kg) / (height(m))²
  // getBMI()

  // gunakan BMI untuk mendapat category
  // BMI < 18.5         -> Underweight
  // 18.5 ≤ BMI < 25.0  -> Normal
  // 25.0 ≤ BMI < 30.0  -> Overweight
  // BMI ≥ 30.0         -> Obese
  // getCategory() -> string
  string getCategory() const;
  
  // Mencetak informasi footballer dengan format sebagai berikut:
  // Name: {name}
  // Age: {hasil pemanggilan getAge()}
  // Position: {playPosition}
  // Nationality: {nationality}
  // BMI: {<BMI> (<getCategory()>)}, BMI 2 angka di belakang koma, HINT: "cout << fixed << setprecision(2);"
  // Transfer Rate: {hasil pemanggilan transferRate()}
  // displayInfo()

  // Melakukan kalkulasi nilai transfer sesuai umur, playPosition, dan getCategory()
  // transferRate() akan diimplementasikan oleh kelas anak Footballer
  // yang ada di soal berikutnya. Gunakan tipe data integer.
  // ... transferRate()
  void displayInfo();
  

  virtual int transferRate() = 0;
};

#endif