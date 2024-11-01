#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "algorithm"
using namespace std;

// 判断有无重复元素
bool judge_repeat(const string& value, vector<string>& list) {
    for (const auto& item : list) {
        if (item == value) return true;
    }
    return false;
}

// 对整理好的综合数据库进行最终结果判断
void judge_last(const vector<string>& list) {
    if (find(list.begin(), list.end(), "23") != list.end()) {
        if (find(list.begin(), list.end(), "12") != list.end()) {
            if (find(list.begin(), list.end(), "21") != list.end()) {
                if (find(list.begin(), list.end(), "13") != list.end()) {
                    cout << "黄褐色，有斑点, 哺乳类，食肉类 -> 金钱豹\n";
                    cout << "所识别的动物为金钱豹\n";
                    return;
                } else if (find(list.begin(), list.end(), "14") != list.end()) {
                    cout << "黄褐色，有黑色条纹，哺乳类，食肉类 -> 虎\n";
                    cout << "所识别的动物为虎\n";
                    return;
                }
            }
        }
    } else if (find(list.begin(), list.end(), "14") != list.end() &&
               find(list.begin(), list.end(), "24") != list.end()) {
        cout << "有黑色条纹，蹄类 -> 斑马\n";
        cout << "所识别的动物为斑马\n";
        return;
    } else if (find(list.begin(), list.end(), "24") != list.end() &&
               find(list.begin(), list.end(), "13") != list.end() &&
               find(list.begin(), list.end(), "15") != list.end() &&
               find(list.begin(), list.end(), "16") != list.end()) {
        cout << "有斑点，有黑色条纹，长脖，蹄类 -> 长颈鹿\n";
        cout << "所识别的动物为长颈鹿\n";
        return;
    } else if (find(list.begin(), list.end(), "20") != list.end() &&
               find(list.begin(), list.end(), "22") != list.end()) {
        cout << "善飞，鸟类 -> 信天翁\n";
        cout << "所识别的动物为信天翁\n";
        return;
    } else if (find(list.begin(), list.end(), "22") != list.end() &&
               find(list.begin(), list.end(), "4") != list.end() &&
               find(list.begin(), list.end(), "15") != list.end() &&
               find(list.begin(), list.end(), "16") != list.end()) {
        cout << "不会飞，长脖，长腿，鸟类 -> 鸵鸟\n";
        cout << "所识别的动物为鸵鸟\n";
        return;
    } else if (find(list.begin(), list.end(), "4") != list.end() &&
               find(list.begin(), list.end(), "22") != list.end() &&
               find(list.begin(), list.end(), "18") != list.end() &&
               find(list.begin(), list.end(), "19") != list.end()) {
        cout << "不会飞，会游泳，黑白二色，鸟类 -> 企鹅\n";
        cout << "所识别的动物为企鹅\n";
        return;
    } else {
        cout << "\n根据所给条件无法判断为何种动物\n";
    }
}

int main() {
    unordered_map<string, string> dict_before = {
            {"1", "有毛发"}, {"2", "产奶"}, {"3", "有羽毛"}, {"4", "不会飞"}, {"5", "会下蛋"},
            {"6", "吃肉"}, {"7", "有犬齿"}, {"8", "有爪"}, {"9", "眼盯前方"}, {"10", "有蹄"},
            {"11", "反刍"}, {"12", "黄褐色"}, {"13", "有斑点"}, {"14", "有黑色条纹"}, {"15", "长脖"},
            {"16", "长腿"}, {"17", "不会飞"}, {"18", "会游泳"}, {"19", "黑白二色"}, {"20", "善飞"},
            {"21", "哺乳类"}, {"22", "鸟类"}, {"23", "食肉类"}, {"24", "蹄类"}
    };

    vector<string> list_real;
    cout << "输入对应条件前面的数字:\n";
    cout << "*******************当输入数字0时!程序结束***************\n";

    string num_real;
    while (true) {
        cout << "请输入：";
        cin >> num_real;
        if (num_real == "0") break;
        list_real.push_back(num_real);
    }

    cout << "\n前提条件为：\n";
    for (const auto& code : list_real) {
        cout << dict_before[code] << " ";
    }
    cout << "\n推理过程如下：\n";

    for (const auto& i : list_real) {
        if (i == "1" && !judge_repeat("21", list_real)) {
            list_real.push_back("21");
            cout << "有毛发 -> 哺乳类\n";
        } else if (i == "2" && !judge_repeat("21", list_real)) {
            list_real.push_back("21");
            cout << "产奶 -> 哺乳类\n";
        } else if (i == "3" && !judge_repeat("22", list_real)) {
            list_real.push_back("22");
            cout << "有羽毛 -> 鸟类\n";
        }
    }

    for (const auto& i : list_real) {
        if (i == "4" && find(list_real.begin(), list_real.end(), "5") != list_real.end() &&
            !judge_repeat("22", list_real)) {
            list_real.push_back("22");
            cout << "不会飞，会下蛋 -> 鸟类\n";
        } else if (i == "6" && find(list_real.begin(), list_real.end(), "21") != list_real.end() &&
                   !judge_repeat("23", list_real)) {
            list_real.push_back("23");
            cout << "食肉 -> 哺乳类\n";
        } else if (i == "7" && find(list_real.begin(), list_real.end(), "8") != list_real.end() &&
                   find(list_real.begin(), list_real.end(), "9") != list_real.end() &&
                   !judge_repeat("23", list_real)) {
            list_real.push_back("23");
            cout << "有犬齿,有爪,眼盯前方 -> 食肉类\n";
        } else if (i == "10" && find(list_real.begin(), list_real.end(), "21") != list_real.end() &&
                   !judge_repeat("24", list_real)) {
            list_real.push_back("24");
            cout << "有蹄，哺乳类 -> 蹄类\n";
        }
    }

    judge_last(list_real);
    return 0;
}
