#ifndef VIPTICKET_HPP
#define VIPTICKET_HPP

#include "Ticket.hpp"

class VIPTicket : public Ticket {
public:
    VIPTicket(const string &ticketID, const string &ownerName);
    string getType() const override;
    string getBenefits() const override;
};

#endif
