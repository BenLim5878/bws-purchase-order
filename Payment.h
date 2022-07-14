#pragma once
#include <string>

enum PaymentMethod {
	CreditCard,
	Check,
	BankTransfer
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
	static std::string paymentMethodToString(PaymentMethod paymentMethod);
public:
	int getPaymentID();
	void setPaymentID(int id);
};

