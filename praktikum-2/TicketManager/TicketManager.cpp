#include <iostream>
#include "TicketManager.hpp"
using namespace std;

TicketManager::TicketManager(string eventName){
    this->eventName = eventName;
    this->vipCapacity = 5;
    this->regularCapacity = 10;
    this->ticketCount = 0;
    this->currentRegularTickets = 0;
    this->currentVIPTickets = 0;
}
    /* Constructor default:
     * - Membuat event dengan nama yang diberikan.
     * - Kapasitas default: 5 tiket VIP, 10 tiket Regular.
     * - Tidak ada tiket yang terjual pada awalnya.
     */

TicketManager::TicketManager(string eventName, int vipCapacity, int regularCapacity){
    if(vipCapacity + regularCapacity >15){
        cout << "The total capacity you construct is " << vipCapacity+regularCapacity << ", meanwhile the venue capacity is 15" << endl;
    } else {
        this->eventName = eventName;
        this->vipCapacity = vipCapacity;
        this->regularCapacity = regularCapacity;
        this->ticketCount = 0;
        this->currentRegularTickets = 0;
        this->currentVIPTickets = 0;
    }
    
}
    /* Constructor dengan kapasitas yang ditentukan:
     * - Membuat event dengan kapasitas khusus untuk VIP dan Regular.
     * - Jika total kapasitas melebihi VENUE_CAPACITY, cetak:
     *   "The total capacity you construct is <total>, meanwhile the venue capacity is 15"
     */

TicketManager::~TicketManager(){
    for (int i = 0; i<ticketCount; i++){
        delete tickets[i];
        tickets[i] = nullptr;
    }
}
    /* Destructor:
     * - Membersihkan semua tiket yang telah dialokasikan secara dinamis.
     * - Menetapkan pointer tiket menjadi nullptr setelah dihapus.
     */

string TicketManager::getEventName() const{
    return this->eventName;
}
    /* Mengembalikan nama acara yang dikelola oleh TicketManager.
     * Output: Nama acara dalam bentuk string.
     */

void TicketManager::buyTicket(const string &ownerName, bool isVIP){
    if (ticketCount < VENUE_CAPACITY){
        if (isVIP){
            if (currentVIPTickets < vipCapacity){
                currentVIPTickets++;
                // ticketCount++;
                string id = "V" + to_string(currentVIPTickets);
                Ticket* t = new VIPTicket(id, ownerName);
                this->tickets[ticketCount] = t;
                ticketCount++;

                cout << "Success: "<< ownerName << " bought a VIP ticket! Ticket ID: " << id << endl;

            } else {
                cout << "Error: No VIP tickets left!" << endl;
            }
        } else {
            if (currentRegularTickets < regularCapacity){
                currentRegularTickets++;
                // ticketCount++;
                string id = "R" + to_string(currentRegularTickets);
                Ticket* t = new RegularTicket(id, ownerName);
                this->tickets[ticketCount] = t;
                ticketCount++;

                cout << "Success: "<< ownerName << " bought a Regular ticket! Ticket ID: " << id << endl;
            } else {
                cout << "Error: No Regular tickets left!" << endl;
            }
        }
    } else {
        cout << "Error: All tickets are sold out!" << endl;
    }
}
    /* Membeli tiket untuk pengguna.
    * Input:
    * - ownerName: Nama pemilik tiket.
    * - isVIP: Jika true, membeli tiket VIP; jika false, membeli tiket Regular.
    *
    * Proses:
    * - Jika venue penuh, cetak "Error: All tickets are sold out!".
    * - Jika kapasitas VIP penuh, cetak "Error: No VIP tickets left!".
    * - Jika kapasitas Regular penuh, cetak "Error: No Regular tickets left!".
    *
    * - Jika pembelian berhasil, sistem akan membuat **ID tiket unik** berdasarkan jenis tiket:
    *   - Jika tiket VIP, ID akan berupa "V" diikuti nomor urut tiket VIP.
    *   - Jika tiket Regular, ID akan berupa "R" diikuti nomor urut tiket Regular.
    *
    * - Contoh penggunaan `to_string()` dalam pembuatan ID:
    *   int angka = 5;
    *   string hasil = "V" + to_string(angka); // hasil: "V5"
    *
    * - Jika pembelian berhasil, cetak:
    *   "Success: <ownerName> bought a <VIP/Regular> ticket! Ticket ID: <ticketID>"
    */

void TicketManager::checkTicket(const string &ticketID) const{
    bool isFound = false;
    for (int i = 0; i<ticketCount; i++){
        if (tickets[i]->getTicketID() == ticketID){
            tickets[i]->printTicket();
            isFound = true;
            break;
        }
    }

    if (isFound == false){
        cout << "Ticket ID is invalid!" << endl;
    }
}
    /* Mengecek apakah tiket dengan ID tertentu valid.
     * Input:
     * - ticketID: ID tiket yang ingin diperiksa.
     *
     * Output:
     * - Jika ditemukan, cetak detail tiket menggunakan metode printTicket().
     * - Jika tidak ditemukan, cetak "Ticket ID is invalid!".
     */

void TicketManager::listAudience() const{
    if (ticketCount == 0){
        cout << "No audience yet!"<< endl;
    } else {
        for (int i = 0; i<ticketCount; i++){
            cout << i+1 << ". ";
            tickets[i]->printTicket();
        }
    }
}
    /* Menampilkan daftar semua pemegang tiket.
     * Output:
     * - Jika belum ada yang membeli tiket, cetak "No audience yet!".
     * - Jika ada, cetak dalam format:
     *   "<nomor>. <printTicket()>"
     *
     * - Nomor urut dalam output harus dimulai dari 1.
     */

int TicketManager::calculateRevenue() const{
    return currentRegularTickets * 275 + currentVIPTickets * 500;
}
    /* Menghitung total pendapatan dari tiket yang terjual.
     * - Tiket VIP seharga 500.
     * - Tiket Regular seharga 275.
     * 
     * Output: Total pendapatan dalam bentuk integer.
     */