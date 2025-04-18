#include "VIPTicket.hpp"

VIPTicket::VIPTicket(const string &ticketID, const string &ownerName)
    : Ticket(ticketID, ownerName) {}

string VIPTicket::getType() const {
    return "VIP";
}

string VIPTicket::getBenefits() const {
    return "Standard Entry + Soundcheck Access";
}
