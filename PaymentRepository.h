#pragma once
#include "Payment.h"
#include "IRepository.h"
#include "TextDataReader.h"
#include "LinkedList.h"
#include <string>

class PaymentRepository: public IRepository
{
private:
	virtual void loadData();
private:
	std::string fileLocation;
	TextDataReader* dataReader;
public:
	LinkedList<Payment>* payments;
public:
	Payment* getPayment(int paymentID);
	Payment* addPayment(Payment payment);
	Payment deletePayment(int paymentID);
private:
	int getNewPaymentID();
public:
	PaymentRepository(std::string fileLocation);
	~PaymentRepository();
};

