#include "BarangMakanan.hpp"
/*
        Constructor BarangMakanan
        nama: nama barang
        berat: berat barang
        hariKedaluwarsa: berapa hari lagi sampai kedaluwarsa
    */
BarangMakanan::BarangMakanan(string nama, int berat, int hariKedaluwarsa) : Barang(nama,berat){
    this->hariKedaluwarsa = hariKedaluwarsa;
}

int BarangMakanan::getHariKedaluwarsa() const{
    return this->hariKedaluwarsa;
}
string BarangMakanan::getJenis() const{
    return "Makanan";
}