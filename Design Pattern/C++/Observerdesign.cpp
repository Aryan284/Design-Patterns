#include <iostream>
#include <list>
#include <string>
using namespace std;

class Observer {
    public:
        virtual void Update(const string &newVideo) = 0;
};

class Subject {
    public:
        virtual void registerObserver(Observer *observer) = 0;
        virtual void removeObserver(Observer *observer) = 0;
        virtual void notifyObservers() = 0;
};



class Publisher : public Subject {
    public:
        Publisher() {
            cout << "\nGoodbye, I was the Subject.\n";
        }

        void registerObserver(Observer *observer) override {
            cout << "Register Observer";
            list_observer_.push_back(observer);
        }
        void removeObserver(Observer *observer) override {
            cout << "Deregister Observer";
            list_observer_.remove(observer);
        }
        void notifyObservers() override {
            list<Observer *>::iterator iterator = list_observer_.begin();
            for (Observer *observer : list_observer_) { // notify all observers
                observer->Update(message_);
            }
        }
        void CreateMessage(string message = "Empty") {
            this->message_ = message;
            notifyObservers();
        }


    private:
        list<Observer *> list_observer_;
        string message_;
};

class Client : public Observer {
    public:
        Client(Subject &subject) : subject_(subject) {
            this->subject_.registerObserver(this);
            cout << "\nHi, I'm the New Subsriber \"" << ++Client::static_number_ << "\".\n";
            this->number_ = Client::static_number_;
        }
        virtual ~Client() {
            cout << "\nGoodbye, I was the Subsriber \"" << this->number_ << "\".\n";
        }

        void Update(const string &message_from_subject) override {
            message_from_subject_ = message_from_subject;
            PrintInfo();
        }
        void RemoveMeFromTheList() {
            subject_.removeObserver(this);
            cout << "\nObserver \"" << number_ << "\" removed from the list.\n";
        }
        void PrintInfo() {
            cout << "\nObserver \"" << this->number_ << "\": a new message is available --> " << this->message_from_subject_ << "\n";
        }

    private:
        string message_from_subject_;
        Subject &subject_;
        static int static_number_;
        int number_;
};

int Client::static_number_ = 0;

void ClientCode() {
    Publisher *subject = new Publisher;
    Client *observer1 = new Client(*subject);
    Client *observer2 = new Client(*subject);
    Client *observer3 = new Client(*subject);
    Client *observer4;
    Client *observer5;

    subject->CreateMessage("Hello New Subs");
    observer3->RemoveMeFromTheList();

    subject->CreateMessage("New Subs");
    observer4 = new Client(*subject);

    observer2->RemoveMeFromTheList();
    observer5 = new Client(*subject);

    subject->CreateMessage("Subs 2");
    observer5->RemoveMeFromTheList();

    observer4->RemoveMeFromTheList();
    observer1->RemoveMeFromTheList();

}

int main() {
    ClientCode();
    return 0;
}