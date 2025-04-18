#ifndef TICKETMANAGER_HPP
#define TICKETMANAGER_HPP

#include <string>
#include "Ticket.hpp"
#include "RegularTicket.hpp"
#include "VIPTicket.hpp"

#define VENUE_CAPACITY 15 // Kapasitas maksimum venue

class TicketManager {
private:
    Ticket* tickets[VENUE_CAPACITY]; // Array untuk menyimpan tiket yang terjual
    string eventName; // Nama acara
    int vipCapacity; // Kapasitas maksimum tiket VIP
    int regularCapacity; // Kapasitas maksimum tiket Regular
    int ticketCount; // Jumlah tiket yang telah terjual
    int currentVIPTickets; // Jumlah tiket VIP yang telah dibeli
    int currentRegularTickets; // Jumlah tiket Regular yang telah dibeli

public:
    TicketManager(string eventName);
    /* Constructor default:
     * - Membuat event dengan nama yang diberikan.
     * - Kapasitas default: 5 tiket VIP, 10 tiket Regular.
     * - Tidak ada tiket yang terjual pada awalnya.
     */

    TicketManager(string eventName, int vipCapacity, int regularCapacity);
    /* Constructor dengan kapasitas yang ditentukan:
     * - Membuat event dengan kapasitas khusus untuk VIP dan Regular.
     * - Jika total kapasitas melebihi VENUE_CAPACITY, cetak:
     *   "The total capacity you construct is <total>, meanwhile the venue capacity is 15"
     */

    ~TicketManager();
    /* Destructor:
     * - Membersihkan semua tiket yang telah dialokasikan secara dinamis.
     * - Menetapkan pointer tiket menjadi nullptr setelah dihapus.
     */

    string getEventName() const;
    /* Mengembalikan nama acara yang dikelola oleh TicketManager.
     * Output: Nama acara dalam bentuk string.
     */

    void buyTicket(const string &ownerName, bool isVIP);
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

    void checkTicket(const string &ticketID) const;
    /* Mengecek apakah tiket dengan ID tertentu valid.
     * Input:
     * - ticketID: ID tiket yang ingin diperiksa.
     *
     * Output:
     * - Jika ditemukan, cetak detail tiket menggunakan metode printTicket().
     * - Jika tidak ditemukan, cetak "Ticket ID is invalid!".
     */

    void listAudience() const;
    /* Menampilkan daftar semua pemegang tiket.
     * Output:
     * - Jika belum ada yang membeli tiket, cetak "No audience yet!".
     * - Jika ada, cetak dalam format:
     *   "<nomor>. <printTicket()>"
     *
     * - Nomor urut dalam output harus dimulai dari 1.
     */

    int calculateRevenue() const;
    /* Menghitung total pendapatan dari tiket yang terjual.
     * - Tiket VIP seharga 500.
     * - Tiket Regular seharga 275.
     * 
     * Output: Total pendapatan dalam bentuk integer.
     */
};

#endif
