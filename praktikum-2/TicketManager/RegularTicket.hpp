#ifndef REGULARTICKET_HPP
#define REGULARTICKET_HPP

#include "Ticket.hpp"

class RegularTicket : public Ticket {
public:
    RegularTicket(const string &ticketID, const string &ownerName);
    string getType() const override;
    string getBenefits() const override;
};

#endif
