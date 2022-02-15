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

class MiPlus : public MiModel {
    void CPU() {
        cout << "C5" << endl;
    }
    void RAM() {
        cout << "12GB" << endl;
    }
    void Price() {
        cout << "$450" << endl;
    }
};

class MiFactory {
    public:
    virtual MiModel* produceMobile(string model) = 0;
    MiModel* configureMobile(string model) {
        MiModel* mobile = produceMobile(model);
        return mobile;
    }
};

class LondonFactory : public MiFactory {
	public:
    MiModel* produceMobile(string model) {
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

class NYFactory : public MiFactory {
    public:
    MiModel* produceMobile(string model) {
        MiModel *mobile;
        if (model == "MiPlus") {
            mobile = new MiPlus;
        }
        else if (model == "MiFire") {
            mobile = new MiFire;
        }
        return mobile;
    }
};

int main() {
	MiFactory* londonFactory = new LondonFactory;
    MiModel* MiBoltMobile = londonFactory->configureMobile("MiBolt");
    MiBoltMobile->CPU();
    MiBoltMobile->RAM();
    MiBoltMobile->Price();

    MiFactory* nyFactory = new NYFactory;
    MiModel* MiPlusMobile = nyFactory->configureMobile("MiPlus");
    MiPlusMobile->CPU();
    MiPlusMobile->RAM();
    MiPlusMobile->Price();

    return 0;
}