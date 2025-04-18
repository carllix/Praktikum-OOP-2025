#include "Authenticator.hpp"

Authenticator::Authenticator(){
    this->secretResource = "Ini adalah data rahasia!";
    this->currentUser = nullptr;
    this->userCount = 0;
}
  /* Constructor:
   * - Menginisialisasi sistem dengan resource rahasia ("Ini adalah data rahasia!")
   * - Tidak ada user yang login (nullptr)
   * - Tidak ada user yang terdaftar
   */

void Authenticator::registerUser(const string &username, const string &password, bool isAdmin){
    if (this->userCount < MAX_USERS){
        bool isExist = false;
        int i = 0;
        while(i < this->userCount && isExist == false){
            string uname = this->users[i]->getUsername();
            if (uname == username){
                isExist = true;
            }
            i++;
        }
        if(isExist){
            cout << "Gagal: Username sudah digunakan!" << endl;
        } else {
            if (isAdmin){
                this->users[this->userCount] = new AdminUser(username,password);
            } else {
                this->users[this->userCount] = new User(username,password);
            }

            this->userCount++;
            cout << "Sukses: User " << username << " berhasil terdaftar!" << endl;
        }
    } else {
        cout << "Gagal: Kapasitas user penuh!" << endl;
    }
}
  /* Mendaftarkan user baru sebagai RegularUser atau AdminUser.
   * Input:
   * - username: Nama pengguna yang ingin didaftarkan.
   * - password: Kata sandi untuk pengguna.
   * - isAdmin: Jika true, user akan dibuat sebagai AdminUser, jika false sebagai User biasa.
   *
   * Output:
   * - "Gagal: Kapasitas user penuh!" jika jumlah user telah mencapai batas maksimum.
   * - "Gagal: Username sudah digunakan!" jika username sudah terdaftar dalam sistem.
   * - "Sukses: User <username> berhasil terdaftar!" jika pendaftaran berhasil.
   *      *<username> diganti dengan nama pengguna yang baru terdaftar.
   */

void Authenticator::login(const string &username, const string &password){
    int userIndex = -1;
    int i = 0;
    while (i<this->userCount && userIndex == -1){
        if (this->users[i]->getUsername() == username){
            userIndex = i;
        }
        i++;
    }

    if (userIndex != -1){
        if(this->users[userIndex]->checkPassword(password)){
            cout << "Sukses: Login berhasil! Selamat datang, " << username << "." << endl;
            this->currentUser = this->users[userIndex];
        } else {
            cout << "Gagal: Username atau password salah!" << endl;
        }
    } else {
        cout << "Gagal: Username atau password salah!" << endl;
    }
}
  /* Mencoba login dengan username dan password yang diberikan.
   * Input:
   * - username: Nama pengguna yang ingin login.
   * - password: Kata sandi pengguna yang ingin login.
   *
   * Output:
   * - "Gagal: Username atau password salah!" jika kombinasi username dan password tidak ditemukan.
   * - "Sukses: Login berhasil! Selamat datang, <username>." jika login berhasil.
   *      *<username> diganti dengan nama pengguna yang berhasil login.
   */

void Authenticator::logout(){
    if (this->currentUser == nullptr){
        cout << "Gagal: Tidak ada user yang sedang login!" << endl;
    } else {
        string username = this->currentUser->getUsername();
        this->currentUser = nullptr;
        cout << "Sukses: User " <<  username << " telah logout." << endl;
    }
}
  /* Melakukan logout dari sesi yang sedang berjalan.
   *
   * Output:
   * - "Gagal: Tidak ada user yang sedang login!" jika tidak ada user yang sedang login.
   * - "Sukses: User <username> telah logout." jika logout berhasil.
   *      *<username> diganti dengan nama pengguna yang logout.
   */

void Authenticator::accessResource() const {
    if (this->currentUser == nullptr){
        cout << "Akses ditolak! Silakan login terlebih dahulu." << endl;
    } else {
        cout << "Resource: " << this->secretResource << endl;
    }
}
  /* Menampilkan resource rahasia jika user sudah login.
   *
   * Output:
   * - "Akses ditolak! Silakan login terlebih dahulu." jika tidak ada user yang login.
   * - "Resource: <secretResource>" jika user sedang login.
   *      *<secretResource> diganti dengan resource rahasia saat ini.
   */

void Authenticator::setResource(const string &newResource){
    if (this->currentUser == nullptr){
        cout << "Gagal: Tidak bisa mengubah resource! Silakan login terlebih dahulu." << endl;
    } else {
        if (this->currentUser->isAdmin()){
            this->secretResource = newResource;
            cout << "Sukses: Resource telah diperbarui oleh " << this->currentUser->getUsername() << "." << endl;
        } else {
            cout << "Gagal: Tidak bisa mengubah resource! Hanya admin yang dapat melakukan ini." << endl;
        }
    }
}
  /* Mengubah resource rahasia (hanya AdminUser yang dapat melakukannya).
   * Input:
   * - newResource: Resource baru yang akan disimpan.
   *
   * Output:
   * - "Gagal: Tidak bisa mengubah resource! Silakan login terlebih dahulu." jika tidak ada user yang login.
   * - "Gagal: Tidak bisa mengubah resource! Hanya admin yang dapat melakukan ini." jika user yang login bukan AdminUser.
   * - "Sukses: Resource telah diperbarui oleh <username>." jika resource berhasil diubah.
   *      *<username> diganti dengan nama pengguna admin yang melakukan perubahan.
   */

Authenticator::~Authenticator(){
    for (int i = 0; i < this->userCount; i++){
        delete this->users[i];
        this->users[i] = nullptr;
    }
}
  /* Destructor:
   * - Membersihkan semua objek User dan AdminUser yang telah dibuat.
   */