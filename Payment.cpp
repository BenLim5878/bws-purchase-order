#include "Payment.h"

std::string Payment::paymentMethodToString(PaymentMethod paymentMethod)
{
	switch (paymentMethod)
	{
	case BankTransfer:
		return "Bank Transfer";
		break;
	case Check:
		return "Check";
		break;
	case CreditCard:
		return "Credit Card";
		break;
	}
}

int Payment::getPaymentID()
{
	return this->paymentID;
}

void Payment::setPaymentID(int id)
{
	this->paymentID = id;
}
