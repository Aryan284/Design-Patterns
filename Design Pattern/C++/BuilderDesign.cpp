#include <iostream>
#include <string>
using namespace std;

class MiModel {
    public:
	    virtual int Price() = 0;
};

class MiBolt : public MiModel {
    int Price() {
        cout << "$250" << endl;
        return 250;
    }
};

class MiFire : public MiModel {
    int Price() {
        cout << "$350" << endl;
        return 350;
    }
};

class SubscriptionModel : public MiModel {
    public:
        virtual int Price() = 0;
        virtual void Duration() = 0;
};

class Annual : public SubscriptionModel {
    public:
        int Price() {
            cout << "$100" << endl;
            return 100;
        }
        void Duration() {
            cout << "12 months" << endl;
        }
};

class Quarter : public SubscriptionModel {
    public:
        int Price() {
            cout << "$30" << endl;
            return 30;
        }
        void Duration() {
            cout << "3 months" << endl;
        }
};

class Assembly {
    public:
        MiModel* models[3];
        float showCost() {
            float cost = 0;
            int i;
            for (i = 0; i < 3; i++) {
                cost += models[i]->Price();
            }
            return cost;
        }
};

class Builder {
    public:
        Assembly* assembleMobile(string subscription) {
            Assembly* am = new Assembly;
            if (subscription == "Premium") {
                am->models[0] = new MiFire;
                am->models[1] = new MiBolt;
                am->models[2] = new Quarter;
            }
            else if (subscription == "Gold") {
                am->models[0] = new MiFire;
                am->models[1] = new MiBolt;
                am->models[2] = new Annual;
            }
            return am;
        }
};



int main() {
    Builder* builder = new Builder;
    Assembly* assembly = builder->assembleMobile("Premium");
    cout << "$" << assembly->showCost() << endl;
    return 0;
}