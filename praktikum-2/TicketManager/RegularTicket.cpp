#include "RegularTicket.hpp"

RegularTicket::RegularTicket(const string &ticketID, const string &ownerName)
    : Ticket(ticketID, ownerName) {}

string RegularTicket::getType() const {
    return "Regular";
}

string RegularTicket::getBenefits() const {
    return "Standard Entry";
}
