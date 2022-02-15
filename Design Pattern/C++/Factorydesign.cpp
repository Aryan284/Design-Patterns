#include <iostream>
#include <string>
using namespace std;

class MiModel {
    public:
	    virtual void CPU() = 0;
	    virtual void RAM() = 0;
	    virtual void Price() = 0;
};

class MiBolt : public MiModel {
    void CPU() {
        cout << "C3" << endl;
    }
    void RAM() {
        cout << "4GB" << endl;
    }
    void Price() {
        cout << "$250" << endl;
    }
};

class MiFire : public MiModel {
    void CPU() {
        cout << "C4" << endl;
    }
    void RAM() {
        cout << "8GB" << endl;
    }
    void Price() {
        cout << "$350" << endl;
    }
};

class MiFactoryMethodClass {
	public:
    static MiModel* getInstance(string model) {
        MiModel *mobile;
        if (model == "MiBolt") {
            mobile = new MiBolt;
        }
        else if (model == "MiFire") {
            mobile = new MiFire;
        }
        return mobile;
    }
};

class MiModelFactoryImpl {
    public:
	static MiModel* produceMobile(string model) {
		MiFactoryMethodClass* Mi = new MiFactoryMethodClass;
        MiModel *mobile = Mi->getInstance(model);
        mobile->CPU();
        mobile->RAM();
        mobile->Price();
        return mobile;
    }
};

int main() {
	MiModelFactoryImpl* MiMobile = new MiModelFactoryImpl;
    MiModel* MiBoltMobile = MiMobile->produceMobile("MiBolt");
    MiModel* MiFireMobile = MiMobile->produceMobile("MiFire");
    return 0;
}