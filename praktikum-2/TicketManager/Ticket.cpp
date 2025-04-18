#include "Ticket.hpp"

Ticket::Ticket(const string &ticketID, const string &ownerName)
    : ticketID(ticketID), ownerName(ownerName) {}

string Ticket::getTicketID() const {
    return ticketID;
}

string Ticket::getOwnerName() const {
    return ownerName;
}

void Ticket::printTicket() {
    cout << ticketID << " | " << getType() << " | " << ownerName << " | " << getBenefits() << endl;
}
