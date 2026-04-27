#include "Transaction.h"

int Transaction::current_id = 0;

Transaction::Transaction(double price, const string& date) : price(price), date(date) {
	id = "TRA-" + to_string(++current_id);
}

void Transaction::process() {

}