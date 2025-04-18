#ifndef TICKET_HPP
#define TICKET_HPP

#include <iostream>
using namespace std;

class Ticket {
protected:
    string ticketID;
    string ownerName;

public:
    Ticket(const string &ticketID, const string &ownerName);
    virtual ~Ticket() {}

    string getTicketID() const;
    string getOwnerName() const;

    void printTicket(); // Print in format "ticketID | type | ownerName | benefits"

    virtual string getType() const = 0;
    virtual string getBenefits() const = 0;
};

#endif
