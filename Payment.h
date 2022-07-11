#pragma once
#include <string>

enum PaymentMethod {
	BankTransfer,
	Check,
	CreditCard
};

class Payment
{
private:
	int paymentID;
public:
	PaymentMethod paymentMethod;
	float paymentAmount;
	std::string paymentDescription;
	tm createdAt;
public:
	int getPaymentID();
	void setPaymentID(int id);
};

