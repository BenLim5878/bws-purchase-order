#include "PaymentRepository.h"
#include "Helper.h"
#include <vector>
#include <algorithm>

//PaymentID, (0)
//PaymentMethod, (1)
//PaymentAmount, (2)
//PaymentDescription, (3)
//PaymentCreatedAt (4)

void PaymentRepository::loadData()
{
	for (std::list<std::string>::iterator i = this->dataReader->context->begin(); i != this->dataReader->context->end(); ++i) {
		std::vector<std::string> record = this->dataReader->splitDelimeter(*i);
		Payment temp;
		temp.setPaymentID(std::stoi(record.at(0)));
		temp.paymentMethod = static_cast<PaymentMethod>(std::stoi(record.at(1)));
		temp.paymentAmount = std::stoll(record.at(2));
		temp.paymentDescription = record.at(3);
		temp.createdAt = stringToTime(record.at(4));
		this->payments->push(temp);
	}
}

Payment* PaymentRepository::getPayment(int paymentID)
{
	Payment* t = nullptr;
	for (int i = 0; i < this->payments->length; i++) {
		t = this->payments->get(i);
		if (t->getPaymentID() == paymentID) {
			return t;
		}
	}
	return nullptr;
}

Payment* PaymentRepository::addPayment(Payment payment)
{
	payment.setPaymentID(getNewPaymentID());
	this->payments->push(payment);
	return &payment;
}

Payment PaymentRepository::deletePayment(int paymentID)
{
	Payment* tarr = getPayment(paymentID);
	Payment res;
	if (tarr) {
		res = this->payments->remove(tarr);
	}
	return res;
}

int PaymentRepository::getNewPaymentID()
{
	if (this->payments->length == 0) {
		return 0;
	}
	std::vector<int> ids;
	for (int i = 0; i < this->payments->length; i++) {
		ids.push_back(this->payments->get(i)->getPaymentID());
	}
	int max = *std::max_element(ids.begin(), ids.end());
	return  max + 1;
}

PaymentRepository::PaymentRepository(std::string fileLocation):payments(new LinkedList<Payment>())
{
	this->dataReader = new TextDataReader(fileLocation);
	this->dataReader->readFile();
	this->loadData();
}

PaymentRepository::~PaymentRepository()
{
	delete this->payments;
	delete this->dataReader;
}
