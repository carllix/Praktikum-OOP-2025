#include "Footballer.hpp"
using namespace std;

// Default cosntructor set nilai attribut sebagai berikut:
// name = "noname"; birthYear = 2000; playPosition = "none";
// nationality = "Indonesia"; height = 180, weight = 70
// ...
Footballer::Footballer()
{
  this->name = "noname";
  this->birthYear = 2000;
  this->playPosition = "none";
  this->nationality = "Indonesia";
  this->height = 180;
  this->weight = 70;
}

// User-defined constructor:
// set nilai atribut berdasarkan nilai parameter masukan
// dengan urutan: name, birthYear, playPosition, nationality, height, weight
// ...
Footballer::Footballer(const string& name, int birthYear, const string& playPosition, const string& nationality, int height, int weight)
{
  this->name = name;
  this->birthYear = birthYear;
  this->playPosition = playPosition;
  this->nationality = nationality;
  this->height = height;
  this->weight = weight;
}

// Copy constructor
// ...
Footballer::Footballer(const Footballer &other)
{
  this->name = other.name;
  this->birthYear = other.birthYear;
  this->playPosition = other.playPosition;
  this->nationality = other.nationality;
  this->height = other.height;
  this->weight = other.weight;
}

// Destructor
// ...
Footballer::~Footballer()
{
}

// Operator assignment
// ...
Footballer &Footballer::operator=(const Footballer &other)
{
  if (this == &other) return *this;

  this->name = other.name;
  this->birthYear = other.birthYear;
  this->playPosition = other.playPosition;
  this->nationality = other.nationality;
  this->height = other.height;
  this->weight = other.weight;
  return *this;
}

// Getter dan setter name
void Footballer::setName(const string& name)
{
  this->name = name;
}

string Footballer::getName() const
{
  return name;
}

// Getter dan setter playPosition
void Footballer::setPlayPosition(const string& playPosition)
{
  this->playPosition = playPosition;
}

string Footballer::getPlayPosition() const
{
  return playPosition;
}
// getPlayPosition()

// Getter dan setter nationality
void Footballer::setNationality(const string& nationality)
{
  this->nationality = nationality;
}

string Footballer::getNationality() const
{
  return nationality;
}

// Getter dan setter height and weight
void Footballer::setHeight(int height)
{
  this->height = height;
}

int Footballer::getHeight() const
{
  return height;
}

void Footballer::setWeight(int weight)
{
  this->weight = weight;
}

int Footballer::getWeight() const
{
  return weight;
}

// gunakan CURRENT_YEAR untuk menghitung umur
// getAge()
int Footballer::getAge() const
{
  return CURRENT_YEAR - birthYear;
}

// gunakan height and weight untuk menghitung BMI
// BMI = weight(kg) / (height(m))²
// getBMI()
float Footballer::getBMI() const
{
  float heightInMeters = height / 100.0;
  return weight / (heightInMeters * heightInMeters);
}

// gunakan BMI untuk mendapat category
// BMI < 18.5         -> Underweight
// 18.5 ≤ BMI < 25.0  -> Normal
// 25.0 ≤ BMI < 30.0  -> Overweight
// BMI ≥ 30.0         -> Obese
// getCategory() -> string
string Footballer::getCategory() const
{
  float bmi = getBMI();
  if (bmi < 18.5)
  {
    return "Underweight";
  }
  else if (bmi >= 18.5 && bmi < 25.0)
  {
    return "Normal";
  }
  else if (bmi >= 25.0 && bmi < 30.0)
  {
    return "Overweight";
  }
  else
  {
    return "Obese";
  }
}

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
void Footballer::displayInfo()
{
  cout << "Name: " << getName() << endl;
  cout << "Age: " << getAge() << endl;
  cout << "Position: " << getPlayPosition() << endl;
  cout << "Nationality: " << getNationality() << endl;
  cout << fixed << setprecision(2);
  cout << "BMI: " << getBMI() << " (" << getCategory() << ")" << endl;
  cout << "Transfer Rate: " << transferRate() << endl;
}