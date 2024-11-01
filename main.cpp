#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "algorithm"
using namespace std;

// �ж������ظ�Ԫ��
bool judge_repeat(const string& value, vector<string>& list) {
    for (const auto& item : list) {
        if (item == value) return true;
    }
    return false;
}

// ������õ��ۺ����ݿ�������ս���ж�
void judge_last(const vector<string>& list) {
    if (find(list.begin(), list.end(), "23") != list.end()) {
        if (find(list.begin(), list.end(), "12") != list.end()) {
            if (find(list.begin(), list.end(), "21") != list.end()) {
                if (find(list.begin(), list.end(), "13") != list.end()) {
                    cout << "�ƺ�ɫ���аߵ�, �����࣬ʳ���� -> ��Ǯ��\n";
                    cout << "��ʶ��Ķ���Ϊ��Ǯ��\n";
                    return;
                } else if (find(list.begin(), list.end(), "14") != list.end()) {
                    cout << "�ƺ�ɫ���к�ɫ���ƣ������࣬ʳ���� -> ��\n";
                    cout << "��ʶ��Ķ���Ϊ��\n";
                    return;
                }
            }
        }
    } else if (find(list.begin(), list.end(), "14") != list.end() &&
               find(list.begin(), list.end(), "24") != list.end()) {
        cout << "�к�ɫ���ƣ����� -> ����\n";
        cout << "��ʶ��Ķ���Ϊ����\n";
        return;
    } else if (find(list.begin(), list.end(), "24") != list.end() &&
               find(list.begin(), list.end(), "13") != list.end() &&
               find(list.begin(), list.end(), "15") != list.end() &&
               find(list.begin(), list.end(), "16") != list.end()) {
        cout << "�аߵ㣬�к�ɫ���ƣ����������� -> ����¹\n";
        cout << "��ʶ��Ķ���Ϊ����¹\n";
        return;
    } else if (find(list.begin(), list.end(), "20") != list.end() &&
               find(list.begin(), list.end(), "22") != list.end()) {
        cout << "�Ʒɣ����� -> ������\n";
        cout << "��ʶ��Ķ���Ϊ������\n";
        return;
    } else if (find(list.begin(), list.end(), "22") != list.end() &&
               find(list.begin(), list.end(), "4") != list.end() &&
               find(list.begin(), list.end(), "15") != list.end() &&
               find(list.begin(), list.end(), "16") != list.end()) {
        cout << "����ɣ����������ȣ����� -> ����\n";
        cout << "��ʶ��Ķ���Ϊ����\n";
        return;
    } else if (find(list.begin(), list.end(), "4") != list.end() &&
               find(list.begin(), list.end(), "22") != list.end() &&
               find(list.begin(), list.end(), "18") != list.end() &&
               find(list.begin(), list.end(), "19") != list.end()) {
        cout << "����ɣ�����Ӿ���ڰ׶�ɫ������ -> ���\n";
        cout << "��ʶ��Ķ���Ϊ���\n";
        return;
    } else {
        cout << "\n�������������޷��ж�Ϊ���ֶ���\n";
    }
}

int main() {
    unordered_map<string, string> dict_before = {
            {"1", "��ë��"}, {"2", "����"}, {"3", "����ë"}, {"4", "�����"}, {"5", "���µ�"},
            {"6", "����"}, {"7", "��Ȯ��"}, {"8", "��צ"}, {"9", "�۶�ǰ��"}, {"10", "����"},
            {"11", "��ۻ"}, {"12", "�ƺ�ɫ"}, {"13", "�аߵ�"}, {"14", "�к�ɫ����"}, {"15", "����"},
            {"16", "����"}, {"17", "�����"}, {"18", "����Ӿ"}, {"19", "�ڰ׶�ɫ"}, {"20", "�Ʒ�"},
            {"21", "������"}, {"22", "����"}, {"23", "ʳ����"}, {"24", "����"}
    };

    vector<string> list_real;
    cout << "�����Ӧ����ǰ�������:\n";
    cout << "*******************����������0ʱ!�������***************\n";

    string num_real;
    while (true) {
        cout << "�����룺";
        cin >> num_real;
        if (num_real == "0") break;
        list_real.push_back(num_real);
    }

    cout << "\nǰ������Ϊ��\n";
    for (const auto& code : list_real) {
        cout << dict_before[code] << " ";
    }
    cout << "\n����������£�\n";

    for (const auto& i : list_real) {
        if (i == "1" && !judge_repeat("21", list_real)) {
            list_real.push_back("21");
            cout << "��ë�� -> ������\n";
        } else if (i == "2" && !judge_repeat("21", list_real)) {
            list_real.push_back("21");
            cout << "���� -> ������\n";
        } else if (i == "3" && !judge_repeat("22", list_real)) {
            list_real.push_back("22");
            cout << "����ë -> ����\n";
        }
    }

    for (const auto& i : list_real) {
        if (i == "4" && find(list_real.begin(), list_real.end(), "5") != list_real.end() &&
            !judge_repeat("22", list_real)) {
            list_real.push_back("22");
            cout << "����ɣ����µ� -> ����\n";
        } else if (i == "6" && find(list_real.begin(), list_real.end(), "21") != list_real.end() &&
                   !judge_repeat("23", list_real)) {
            list_real.push_back("23");
            cout << "ʳ�� -> ������\n";
        } else if (i == "7" && find(list_real.begin(), list_real.end(), "8") != list_real.end() &&
                   find(list_real.begin(), list_real.end(), "9") != list_real.end() &&
                   !judge_repeat("23", list_real)) {
            list_real.push_back("23");
            cout << "��Ȯ��,��צ,�۶�ǰ�� -> ʳ����\n";
        } else if (i == "10" && find(list_real.begin(), list_real.end(), "21") != list_real.end() &&
                   !judge_repeat("24", list_real)) {
            list_real.push_back("24");
            cout << "���㣬������ -> ����\n";
        }
    }

    judge_last(list_real);
    return 0;
}
