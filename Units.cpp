#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

class Unit {
public:
	Unit(string nick, string name, string type, double count) :nick(nick), name(name), type(type), count(count) {};
	string nick;
	string name;
	string type;
	double count;
};
class Value {
public:
	string name;
	string type;
	double count;
	long long value;
};
class Unit_Converter {
public:
	Unit_Converter();
	int unit_convert();

private:
	vector<Unit> list;
};
Unit_Converter::Unit_Converter() {
	//��ʾ��
	cout << "������Ҫת������ֵ�͵�λ���Լ��µ�λ��" << endl;
	cout << "�磺1kg g" << endl;
	cout << "������-1�鿴֧��ת���ĵ�λ�б�����-2�˳�����" << endl;
	//���뵥λ
	//����
	list.push_back(Unit("��", "m", "length", 1));
	list.push_back(Unit("ǧ��", "km", "length", 1e-3));
	list.push_back(Unit("����", "dm", "length", 1e+1));
	list.push_back(Unit("����", "cm", "length", 1e+2));
	list.push_back(Unit("����", "mm", "length", 1e+3));
	list.push_back(Unit("΢��", "um", "length", 1e+6));
	list.push_back(Unit("����", "nm", "length", 1e+9));
	list.push_back(Unit("Ƥ��", "pm", "length",  1e+12));
	list.push_back(Unit("����", "ly", "length",  1.0570e-16));
	list.push_back(Unit("���ĵ�λ", "AU", "length",  6.6846e-12));
	list.push_back(Unit("Ӣ��", "in", "length",  39.3700787));
	list.push_back(Unit("Ӣ��", "mi", "length",  0.0006214));
	list.push_back(Unit("Ӣ��", "ft", "length",  3.2808399));
	list.push_back(Unit("��", "chi", "length", 3));
	list.push_back(Unit("��", "yd", "length",  1.0936133));
	list.push_back(Unit("����", "nmi", "length",  0.00054));
	list.push_back(Unit("ӢѰ", "fm", "length",  0.5468066));
	list.push_back(Unit("��¡", "fur", "length", 0.004971));
	list.push_back(Unit("��", "li", "length", 2e-3));
	list.push_back(Unit("��", "ac_zhang", "length", 3e-1));
	list.push_back(Unit("��", "ac_cun", "length", 3e+1));
	list.push_back(Unit("��", "ac_fen", "length", 3e+2));
	list.push_back(Unit("��", "ac_li", "length", 3e+4));
	list.push_back(Unit("��", "ac_hao", "length", 3e+5));
	//���
	list.push_back(Unit("ƽ����", "m^2", "square", 1));
	list.push_back(Unit("����", "ha", "square", 1e-4));
	list.push_back(Unit("Ķ", "mu", "square", 0.0015));
	list.push_back(Unit("ƽ������", "cm^2", "square", 1e+4));
	list.push_back(Unit("��Ķ", "are", "square", 1e-2));
	list.push_back(Unit("ƽ������", "mm^2", "square", 1e+7));
	list.push_back(Unit("ӢĶ", "acre", "square", 0.0002471));
	list.push_back(Unit("ƽ��Ӣ��", "mi^2", "square", 3.8610e-7));
	list.push_back(Unit("ƽ����", "yd^2", "square", 1.19599));
	list.push_back(Unit("ƽ��Ӣ��", "in^2", "square", 1550.0031));
	list.push_back(Unit("ƽ������", "dm^2", "square", 100));
	list.push_back(Unit("ƽ��ǧ��", "km^2", "square", 1e-6));
	list.push_back(Unit("ƽ��Ӣ��", "sq.ft", "square", 10.7639104));
	list.push_back(Unit("ƽ����", "sq.rd", "square", 0.0395369));
	list.push_back(Unit("��", "qin", "square", 0.000015));
	list.push_back(Unit("��", "fen^2", "square", 0.015));
	list.push_back(Unit("ƽ����", "chi^2", "square", 9));
	list.push_back(Unit("ƽ����", "cun^2", "square", 900));
	//���
	list.push_back(Unit("������", "m^3", "volume", 1));
	list.push_back(Unit("��", "l", "volume", 1000));
	list.push_back(Unit("��������", "cm^3", "volume", 1000000));
	list.push_back(Unit("��������", "dm^3", "volume", 1000));
	list.push_back(Unit("����", "dl", "volume", 10000));
	list.push_back(Unit("����", "cl", "volume", 100000));
	list.push_back(Unit("��ʯ", "hl", "volume", 10));
	list.push_back(Unit("΢��", "ul", "volume", 1000000000));
	list.push_back(Unit("����Ӣ��", "cu_in", "volume", 61023.8445022));
	list.push_back(Unit("������", "cu_yd", "volume", 1.3079528));
	list.push_back(Unit("��������", "mm^3", "volume", 1000000000));
	list.push_back(Unit("����Ӣ��", "cu_ft", "volume", 35.3147248));
	list.push_back(Unit("����", "ml", "volume", 1000000));
	list.push_back(Unit("Ӣ�Ƽ���", "uk_gal", "volume", 219.9691573));
	list.push_back(Unit("���Ƽ���", "us_gal", "volume", 264.1720524));
	list.push_back(Unit("Ӣ��Һ�尻˾", "uk_oz", "volume", 35198.873636));
	list.push_back(Unit("����Һ�尻˾", "us_oz", "volume", 34164.6737274));
	//����������
	list.push_back(Unit("ǧ��", "kg", "mass&weight", 1));
	list.push_back(Unit("��", "jin", "mass&weight", 2));
	list.push_back(Unit("��", "liang", "mass&weight", 20));
	list.push_back(Unit("��", "g", "mass&weight", 1000));
	list.push_back(Unit("����", "mg", "mass&weight", 1000000));
	list.push_back(Unit("΢��", "ug", "mass&weight", 1000000000));
	list.push_back(Unit("����", "q", "mass&weight", 0.01));
	list.push_back(Unit("����", "ct", "mass&weight", 5000));
	list.push_back(Unit("����", "ct", "mass&weight", 5000));
	list.push_back(Unit("����", "gr", "mass&weight", 15432.3583529));
	list.push_back(Unit("����", "lt", "mass&weight", 0.0009842));
	list.push_back(Unit("��", "t", "mass&weight", 0.001));
	list.push_back(Unit("��", "lb", "mass&weight", 2.2046226));
	list.push_back(Unit("��˾", "oz", "mass&weight", 35.2739619));
	list.push_back(Unit("�̶�", "st", "mass&weight", 0.0011023));
	list.push_back(Unit("Ӣʯ", "st", "mass&weight", 0.157473));
	list.push_back(Unit("����", "dr", "mass&weight", 564.3833912));
	list.push_back(Unit("��", "dan", "mass&weight", 0.02));
	list.push_back(Unit("Ǯ", "qian", "mass&weight", 200));
	//�¶�
	list.push_back(Unit("���϶�", "oC", "temperature", 1));
	list.push_back(Unit("���϶�", "oF", "temperature", 33.8));
	list.push_back(Unit("���϶�", "K", "temperature", 274.15));
	list.push_back(Unit("���϶�", "oRe", "temperature", 0.8));
	list.push_back(Unit("���϶�", "oR", "temperature", 493.47));

	//ѹ��
	list.push_back(Unit("��˹��", "Pa", "pressure", 1));
	list.push_back(Unit("���׹���", "mmHg", "pressure", 0.0075006));
	list.push_back(Unit("ǧ��", "kpa", "pressure", 0.001));
	list.push_back(Unit("����", "MPa", "pressure", 1e-6));
	list.push_back(Unit("����", "hpa", "pressure", 0.01));
	list.push_back(Unit("����", "mbar", "pressure", 0.01));
	list.push_back(Unit("��", "bar", "pressure", 0.00001));
	list.push_back(Unit("��׼����ѹ", "atm", "pressure", 9.8692e-6));
	//����
	list.push_back(Unit("��", "W", "power", 1));
	list.push_back(Unit("��������", "ps", "power", 0.0013596));
	list.push_back(Unit("ǧ��", "kW", "power", 0.001));
	list.push_back(Unit("Ӣ������", "hp", "power", 0.001341));
	list.push_back(Unit("���� / ��", "J/s", "power", 1));

	//��
	list.push_back(Unit("ţ", "N", "force", 1));
	list.push_back(Unit("ǧ����", "kgf", "force", 0.1019716));
	list.push_back(Unit("����", "gf", "force", 101.971621));
	list.push_back(Unit("ǧ����", "kip", "force", 0.0002248));
	list.push_back(Unit("����", "dyn", "force", 100000));
	list.push_back(Unit("ǧţ", "kN", "force", 0.001));
	list.push_back(Unit("����", "lbf", "force", 0.2248089));
	list.push_back(Unit("������", "tf", "force", 0.000102));

	//ʱ��
	list.push_back(Unit("��", "d", "time", 1));
	list.push_back(Unit("��", "yr", "time", 0.0027397));
	list.push_back(Unit("��", "s", "time", 86400));
	list.push_back(Unit("��", "min", "time", 1440.0000029));
	list.push_back(Unit("΢��", "us", "time", 86400000000));
	list.push_back(Unit("ʱ", "h", "time", 24));
	list.push_back(Unit("����", "ms", "time", 86400000));
	list.push_back(Unit("��", "week", "time", 0.1428571));
	list.push_back(Unit("����", "ns", "time", 86400000000000));
	//�ٶ�
	list.push_back(Unit("��/��", "m/s", "velocity", 1));
	list.push_back(Unit("ǧ��/ʱ", "km/h", "velocity", 3.6));
	list.push_back(Unit("ǧ��/��", "km/s", "velocity", 0.001));
	list.push_back(Unit("���", "mach", "velocity", 0.0029386));
	list.push_back(Unit("Ӣ��/��", "in/s", "velocity", 39.370079));
	list.push_back(Unit("����", "c", "velocity", 3.3356e-9));
	list.push_back(Unit("Ӣ��/ʱ", "mile/h", "velocity", 2.236936));

}

int Unit_Converter::unit_convert() {
	
	Value former;
	cin >> former.value;
	if (former.value < 0) {
		if (former.value == -2) return 0;
		if (former.value == -1) {
			for (int i = 0; i < list.size(); i++) {
				cout.flags(ios::left);
				cout << setw(15) << list[i].type << setw(15) << list[i].nick << setw(15) << list[i].name << endl;
			}
			cout << setw(15) << "   ��" << setw(15) << "  ��" << setw(15) << "  ��" << endl;
			cout << setw(15) << "��λ����" << setw(15) << "��λ����" << setw(15) << "��λ��Ӧ����" << endl;
		}
		else {
			cout << "�����ֵ����" << endl;
		}
	}
	else{
		cin >> former.name;
		int mark = 0;
		int t;
		for (t = 0; t < list.size(); t++)
			if (former.name.compare(list[t].name) == 0) {
				former.count = list[t].count;
				former.type = list[t].type;
				break;
			}
		if (t == list.size()) {
			cout << "δ�ҵ���λ:" << former.name << endl;
			mark = 1;
		}
		Value later;
		cin >> later.name;
		for (t = 0; t < list.size(); t++) {
			if (later.name.compare(list[t].name) == 0) {
				later.count = list[t].count;
				later.type = list[t].type;
				break;
			}
		}
		if (t == list.size()) {
			cout << "δ�ҵ���λ:" << later.name << endl;
			mark = 1;
		}
		if (mark == 0) {
			if (former.type.compare(later.type) != 0) cout << "��λ���Ͳ�ͬ���޷�ת����" << endl;
			else cout << former.value << "(" << former.name << ") = " << former.value / former.count * later.count << "(" << later.name << ")" << endl;
		}
	}
	return 1;
}


int main() {
	Unit_Converter body;
	while (body.unit_convert() != 0);
	return 0;
}


