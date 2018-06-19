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
	//提示语
	cout << "输入需要转化的数值和单位，以及新单位：" << endl;
	cout << "如：1kg g" << endl;
	cout << "（输入-1查看支持转换的单位列表，输入-2退出程序）" << endl;
	//载入单位
	//长度
	list.push_back(Unit("米", "m", "length", 1));
	list.push_back(Unit("千米", "km", "length", 1e-3));
	list.push_back(Unit("分米", "dm", "length", 1e+1));
	list.push_back(Unit("厘米", "cm", "length", 1e+2));
	list.push_back(Unit("毫米", "mm", "length", 1e+3));
	list.push_back(Unit("微米", "um", "length", 1e+6));
	list.push_back(Unit("纳米", "nm", "length", 1e+9));
	list.push_back(Unit("皮米", "pm", "length",  1e+12));
	list.push_back(Unit("光年", "ly", "length",  1.0570e-16));
	list.push_back(Unit("天文单位", "AU", "length",  6.6846e-12));
	list.push_back(Unit("英寸", "in", "length",  39.3700787));
	list.push_back(Unit("英里", "mi", "length",  0.0006214));
	list.push_back(Unit("英尺", "ft", "length",  3.2808399));
	list.push_back(Unit("尺", "chi", "length", 3));
	list.push_back(Unit("码", "yd", "length",  1.0936133));
	list.push_back(Unit("海里", "nmi", "length",  0.00054));
	list.push_back(Unit("英寻", "fm", "length",  0.5468066));
	list.push_back(Unit("弗隆", "fur", "length", 0.004971));
	list.push_back(Unit("里", "li", "length", 2e-3));
	list.push_back(Unit("丈", "ac_zhang", "length", 3e-1));
	list.push_back(Unit("寸", "ac_cun", "length", 3e+1));
	list.push_back(Unit("分", "ac_fen", "length", 3e+2));
	list.push_back(Unit("厘", "ac_li", "length", 3e+4));
	list.push_back(Unit("毫", "ac_hao", "length", 3e+5));
	//面积
	list.push_back(Unit("平方米", "m^2", "square", 1));
	list.push_back(Unit("公顷", "ha", "square", 1e-4));
	list.push_back(Unit("亩", "mu", "square", 0.0015));
	list.push_back(Unit("平方厘米", "cm^2", "square", 1e+4));
	list.push_back(Unit("公亩", "are", "square", 1e-2));
	list.push_back(Unit("平方毫米", "mm^2", "square", 1e+7));
	list.push_back(Unit("英亩", "acre", "square", 0.0002471));
	list.push_back(Unit("平方英里", "mi^2", "square", 3.8610e-7));
	list.push_back(Unit("平方码", "yd^2", "square", 1.19599));
	list.push_back(Unit("平方英寸", "in^2", "square", 1550.0031));
	list.push_back(Unit("平方分米", "dm^2", "square", 100));
	list.push_back(Unit("平方千米", "km^2", "square", 1e-6));
	list.push_back(Unit("平方英尺", "sq.ft", "square", 10.7639104));
	list.push_back(Unit("平方竿", "sq.rd", "square", 0.0395369));
	list.push_back(Unit("顷", "qin", "square", 0.000015));
	list.push_back(Unit("分", "fen^2", "square", 0.015));
	list.push_back(Unit("平方尺", "chi^2", "square", 9));
	list.push_back(Unit("平方寸", "cun^2", "square", 900));
	//体积
	list.push_back(Unit("立方米", "m^3", "volume", 1));
	list.push_back(Unit("升", "l", "volume", 1000));
	list.push_back(Unit("立方厘米", "cm^3", "volume", 1000000));
	list.push_back(Unit("立方分米", "dm^3", "volume", 1000));
	list.push_back(Unit("分升", "dl", "volume", 10000));
	list.push_back(Unit("厘升", "cl", "volume", 100000));
	list.push_back(Unit("公石", "hl", "volume", 10));
	list.push_back(Unit("微升", "ul", "volume", 1000000000));
	list.push_back(Unit("立方英寸", "cu_in", "volume", 61023.8445022));
	list.push_back(Unit("立方码", "cu_yd", "volume", 1.3079528));
	list.push_back(Unit("立方毫米", "mm^3", "volume", 1000000000));
	list.push_back(Unit("立方英尺", "cu_ft", "volume", 35.3147248));
	list.push_back(Unit("毫升", "ml", "volume", 1000000));
	list.push_back(Unit("英制加仑", "uk_gal", "volume", 219.9691573));
	list.push_back(Unit("美制加仑", "us_gal", "volume", 264.1720524));
	list.push_back(Unit("英制液体盎司", "uk_oz", "volume", 35198.873636));
	list.push_back(Unit("美制液体盎司", "us_oz", "volume", 34164.6737274));
	//质量与重量
	list.push_back(Unit("千克", "kg", "mass&weight", 1));
	list.push_back(Unit("斤", "jin", "mass&weight", 2));
	list.push_back(Unit("两", "liang", "mass&weight", 20));
	list.push_back(Unit("克", "g", "mass&weight", 1000));
	list.push_back(Unit("毫克", "mg", "mass&weight", 1000000));
	list.push_back(Unit("微克", "ug", "mass&weight", 1000000000));
	list.push_back(Unit("公担", "q", "mass&weight", 0.01));
	list.push_back(Unit("克拉", "ct", "mass&weight", 5000));
	list.push_back(Unit("克拉", "ct", "mass&weight", 5000));
	list.push_back(Unit("格令", "gr", "mass&weight", 15432.3583529));
	list.push_back(Unit("长吨", "lt", "mass&weight", 0.0009842));
	list.push_back(Unit("吨", "t", "mass&weight", 0.001));
	list.push_back(Unit("磅", "lb", "mass&weight", 2.2046226));
	list.push_back(Unit("盎司", "oz", "mass&weight", 35.2739619));
	list.push_back(Unit("短吨", "st", "mass&weight", 0.0011023));
	list.push_back(Unit("英石", "st", "mass&weight", 0.157473));
	list.push_back(Unit("打兰", "dr", "mass&weight", 564.3833912));
	list.push_back(Unit("担", "dan", "mass&weight", 0.02));
	list.push_back(Unit("钱", "qian", "mass&weight", 200));
	//温度
	list.push_back(Unit("摄氏度", "oC", "temperature", 1));
	list.push_back(Unit("华氏度", "oF", "temperature", 33.8));
	list.push_back(Unit("开氏度", "K", "temperature", 274.15));
	list.push_back(Unit("列氏度", "oRe", "temperature", 0.8));
	list.push_back(Unit("兰氏度", "oR", "temperature", 493.47));

	//压力
	list.push_back(Unit("帕斯卡", "Pa", "pressure", 1));
	list.push_back(Unit("毫米汞柱", "mmHg", "pressure", 0.0075006));
	list.push_back(Unit("千帕", "kpa", "pressure", 0.001));
	list.push_back(Unit("兆帕", "MPa", "pressure", 1e-6));
	list.push_back(Unit("百帕", "hpa", "pressure", 0.01));
	list.push_back(Unit("毫巴", "mbar", "pressure", 0.01));
	list.push_back(Unit("巴", "bar", "pressure", 0.00001));
	list.push_back(Unit("标准大气压", "atm", "pressure", 9.8692e-6));
	//功率
	list.push_back(Unit("瓦", "W", "power", 1));
	list.push_back(Unit("米制马力", "ps", "power", 0.0013596));
	list.push_back(Unit("千瓦", "kW", "power", 0.001));
	list.push_back(Unit("英制马力", "hp", "power", 0.001341));
	list.push_back(Unit("焦耳 / 秒", "J/s", "power", 1));

	//力
	list.push_back(Unit("牛", "N", "force", 1));
	list.push_back(Unit("千克力", "kgf", "force", 0.1019716));
	list.push_back(Unit("克力", "gf", "force", 101.971621));
	list.push_back(Unit("千磅力", "kip", "force", 0.0002248));
	list.push_back(Unit("达因", "dyn", "force", 100000));
	list.push_back(Unit("千牛", "kN", "force", 0.001));
	list.push_back(Unit("磅力", "lbf", "force", 0.2248089));
	list.push_back(Unit("公吨力", "tf", "force", 0.000102));

	//时间
	list.push_back(Unit("天", "d", "time", 1));
	list.push_back(Unit("年", "yr", "time", 0.0027397));
	list.push_back(Unit("秒", "s", "time", 86400));
	list.push_back(Unit("分", "min", "time", 1440.0000029));
	list.push_back(Unit("微秒", "us", "time", 86400000000));
	list.push_back(Unit("时", "h", "time", 24));
	list.push_back(Unit("毫秒", "ms", "time", 86400000));
	list.push_back(Unit("周", "week", "time", 0.1428571));
	list.push_back(Unit("纳秒", "ns", "time", 86400000000000));
	//速度
	list.push_back(Unit("米/秒", "m/s", "velocity", 1));
	list.push_back(Unit("千米/时", "km/h", "velocity", 3.6));
	list.push_back(Unit("千米/秒", "km/s", "velocity", 0.001));
	list.push_back(Unit("马赫", "mach", "velocity", 0.0029386));
	list.push_back(Unit("英寸/秒", "in/s", "velocity", 39.370079));
	list.push_back(Unit("光速", "c", "velocity", 3.3356e-9));
	list.push_back(Unit("英里/时", "mile/h", "velocity", 2.236936));

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
			cout << setw(15) << "   ↑" << setw(15) << "  ↑" << setw(15) << "  ↑" << endl;
			cout << setw(15) << "单位类型" << setw(15) << "单位名称" << setw(15) << "单位对应符号" << endl;
		}
		else {
			cout << "输入的值有误。" << endl;
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
			cout << "未找到单位:" << former.name << endl;
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
			cout << "未找到单位:" << later.name << endl;
			mark = 1;
		}
		if (mark == 0) {
			if (former.type.compare(later.type) != 0) cout << "单位类型不同！无法转换。" << endl;
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


