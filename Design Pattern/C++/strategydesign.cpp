#include <iostream>
#include <string>
#include <vector>
using namespace std;

class PaymentStrategy {
	public:
		virtual void pay(int amount) = 0;
};
 
class CreditCardStrategy : public PaymentStrategy {

	private:
		string name;
		string cardNumber;
		string cvv;
		string dateOfExpiry;
	
	public:
		CreditCardStrategy(string nm, string ccNum, string cvv, string expiryDate){
			name = nm;
			cardNumber = ccNum;
			cvv = cvv;
			dateOfExpiry = expiryDate;
		}
		void pay(int amount) {
			cout << amount << " paid with credit/debit card" << endl;
		}
};
 
class PaypalStrategy : public PaymentStrategy {
 
	private:
		string emailId;
		string password;
	
	public:
		PaypalStrategy(string email, string pwd){
			emailId=email;
			password=pwd;
		}
	
		void pay(int amount) {
			cout << amount << " paid using Paypal." << endl;
		}
};
 
class Item {
 
	private:
		string upcCode;
		int price;
	
	public:
		Item(string upc, int cost){
			upcCode=upc;
			price=cost;
		}
	 
		string getUpcCode() {
			return upcCode;
		}
	 
		int getPrice() {
			return price;
		}	
};


class ShoppingCart {

	vector<Item*> items;
	
	public:
		ShoppingCart() { }
	
		void addItem(Item* item){
			items.push_back(item);
		}
		
		int calculateTotal() {
			int sum = 0;
			for(int i = 0; i < items.size(); i++) {
				sum += items[i]->getPrice();
			}
			return sum;
		}
		
		void pay(PaymentStrategy* paymentMethod) {
			int amount = calculateTotal();
			paymentMethod->pay(amount);
		}
};

int main() {
	ShoppingCart* cart1 = new ShoppingCart;
	
	Item* item1;
	item1 = new Item("1234", 10);
	Item* item2;
	item2 = new Item("5678", 40);
	
	cart1->addItem(item1);
	cart1->addItem(item2);
	
	//pay by paypal
	cart1->pay(new PaypalStrategy("myemail@example.com", "mypwd"));
	

	ShoppingCart* cart2 = new ShoppingCart;
	
	Item* item3;
	item3 = new Item("2355", 65);
	Item* item4;
	item4 = new Item("5465", 42);
	
	cart2->addItem(item3);
	cart2->addItem(item4);
	//pay by credit card
	cart2->pay(new CreditCardStrategy("Aryan", "28584381", "144", "12/45"));

	return 0;
}