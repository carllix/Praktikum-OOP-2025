#include "Gradebook.hpp"
/*
 * Menambah atau mengupdate nilai mahasiswa.
 * Jika mahasiswa sudah ada, nilainya akan diupdate.
 * Jika mahasiswa belum ada, akan ditambahkan dengan nilai yang diberikan.
 */
void Gradebook::addOrUpdateStudent(const string &studentName, double grade){
    studentGrades[studentName] = grade;
}

/*
 * Menghapus mahasiswa dari gradebook.
 * Mengembalikan true jika mahasiswa ditemukan dan berhasil dihapus,
 * false jika tidak ditemukan.
 */
bool Gradebook::removeStudent(const string &studentName){
    if (studentExists(studentName)){
        studentGrades.erase(studentGrades.find(studentName));
        return true;
    }

    return false;
}

/*
 * Mengambil nilai dari mahasiswa tertentu.
 * Mengembalikan true jika mahasiswa ditemukan dan nilainya disimpan
 * di parameter 'grade', false jika mahasiswa tidak ditemukan.
 */
bool Gradebook::getGrade(const string &studentName, double &grade) const{
    if (studentExists(studentName)){
        grade = studentGrades.at(studentName);
        return true;
    }

    return false;
}

/*
 * Memeriksa apakah mahasiswa ada dalam gradebook.
 * Mengembalikan true jika mahasiswa ada, false jika tidak.
 */
bool Gradebook::studentExists(const string &studentName) const{
    return (studentGrades.find(studentName) != studentGrades.end());
}

/*
 * Mencetak semua nama mahasiswa dan nilai mereka
 * Jika gradebook kosong, akan mencetak pesan "Gradebook kosong\n"
 * Format:
 * 1. <nama_mahasiswa>: <nilai>
 * 2. <nama_mahasiswa>: <nilai>
 * ...
 */
void Gradebook::printGrades() const{
    if (studentGrades.empty()) {
        cout << "Gradebook kosong\n";
    } else {
        int idx = 1;
        for (auto it = studentGrades.begin(); it!=studentGrades.end(); it++){
            cout << idx << ". " << it->first << ": " << it->second << endl; 
            idx++;
        }
    }
}

bool comp(pair<string, double> a, pair<string, double> b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second > b.second;
}
/*
 * Mencetak semua nama mahasiswa dan nilai mereka, terurut berdasarkan nilai terbesar ke terkecil.
 * Hint: gunakan vector<pair<string, double>> untuk menyimpan semua data mahasiswa untuk memudahkan pengurutan. Gunakan fungsi bantuan untuk komparasi pada std::sort.
 * Format:
 * 1. <nama_mahasiswa>: <nilai>
 * 2. <nama_mahasiswa>: <nilai>
 * ...
 */
void Gradebook::printGradesRank() const{
    vector<pair<string,double>> v;

    for (auto it = studentGrades.begin(); it != studentGrades.end(); it++) {
        v.push_back(*it);
    }

    sort(v.begin(), v.end(), comp);

    for (int i = 0; i<v.size(); i++){
        cout << i+1 << ". " << v[i].first << ": " << v[i].second << endl;
    }
}

/*
 * Mengembalikan daftar nama mahasiswa yang nilainya di atas threshold tertentu.
 * Mengembalikan vector berisi nama mahasiswa dengan nilai lebih besar dari threshold,
 * terurut berdasarkan abjad.
 */
vector<string> Gradebook::getStudentsWithGradeAbove(double threshold) const{
    vector<string> v;

    for (auto it = studentGrades.begin(); it!=studentGrades.end(); it++){
        if (it->second > threshold){
            v.push_back(it->first);
        }
    }

    sort(v.begin(), v.end());

    return v;
}

/*
 * Menghitung rata-rata nilai semua mahasiswa dalam gradebook.
 * Mengembalikan rata-rata nilai, atau 0.0 jika gradebook kosong.
 */
double Gradebook::getAverageGrade() const{
    if (studentGrades.empty()){
        return 0.0;
    }

    double sum = 0.0;
    int n = studentGrades.size();

    for (auto it = studentGrades.begin(); it!=studentGrades.end(); it++){
        sum += it->second;
    }

    return sum/n;
}

/*
 * Mengembalikan jumlah mahasiswa yang ada dalam gradebook.
 */
size_t Gradebook::getNumberOfStudents() const{
    return studentGrades.size();
}