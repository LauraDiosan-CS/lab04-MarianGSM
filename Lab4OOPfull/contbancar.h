#pragma once
class ContBancar {
private:
	int zi;
	int bani;
	int id;
	char* tip;
	char* desc;
public:
	ContBancar();
	ContBancar(int zi, int bani, char* tip, char* desc, int id);
	ContBancar(const ContBancar& contbancar);
	~ContBancar();
	int getZi() {
		return this->zi;
	}
	char* getTip() {
		return this->tip;
	}
	char* getDesc() {
		return this->desc;
	}
	int getBani() {
		return this->bani;
	}
	int getId() {
		return this->id;
	}

	void setZi(int z);
	void setBani(int b);
	void setTip(char* t);
	void setId(int id);
	void setDesc(char* d);
	char* toString();
	ContBancar& operator= (const ContBancar& c);
};