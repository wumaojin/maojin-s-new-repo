#include<iostream>
#include<vector>
#include<string>

using namespace std;

//偏序集对象
class Posets {
public:
    string row_rales;//初始输入的偏序集
    vector<string> rales;//转化为数组的偏序集
    vector<string> cov_row_rales;//数组形式的覆盖集
    string cov_rales;//最终输出的覆盖集

    //初始化输入偏序集
    void init_row_rales(string rale) {
        this->row_rales = rale;
    }
    void init_rales();//转化为数组形式的偏序集
    int compare_element(char a, char b);//检查两个元素之间的序偶
    void init_cov_row_rales();//产生覆盖集
    void init_cov_rales();//把数组形式的覆盖集转化为字符串
    void output_cov_rales();//输出最终的覆盖集
};

//输出最终的覆盖集
void Posets::output_cov_rales() {
    cout << "此偏序集的覆盖集为：";
    cout << cov_rales << endl;
}

//把数组形式的覆盖集转化为字符串
void Posets::init_cov_rales() {
    //用一个字符串储存
    string str = "";
    //先生成大括号
    str += "{ ";
    //遍历偏序集数组并添加尖嘴号和间隔的逗号
    for (int i = 0; i < cov_row_rales.size();i++) {
        if (i == 0) {
            str += "<";
        } else {
            str += ", <";
        }
        char tem1[2];
        tem1[0] = cov_row_rales[i][0];
        tem1[1] = '\0';
        string fir_element = tem1;
        str += fir_element;
        str += ",";
        char tem2[2];
        tem2[0] = cov_row_rales[i][1];
        tem2[1] = '\0';
        string sec_element = tem2;
        str += sec_element;
        str += ">";
    }
    //补充最后的大括号
    str += " }";
    cov_rales = str;
}

//产生覆盖集
void Posets::init_cov_row_rales() {
    //遍历偏序集数组
    for (int i = 0; i < rales.size(); i++) {
        int judge = 0;//判断状态的一个临时变量
        char first_element = rales[i][0];//序偶的第一个元素
        char second_element = rales[i][1];//序偶的第二个元素
        if (first_element == second_element) { judge = 1; }//元素相同判断值为1
        //再次遍历偏序集数组，找到和第一个元素相同的序偶，并比较此序偶的第二个元素，是否之间也有不符合条件序偶，有则判断值为1
        for (int j = 0; j < rales.size(); j++) {
            if (rales[j][0] == first_element && first_element != rales[j][1] && compare_element(second_element, rales[j][1]) == -1 && j != i) {
                judge = 1;
            }
        }
        //判断值并未被改为1则将此序偶加入覆盖集数组
        if (judge == 0) {
            cov_row_rales.push_back(rales[i]);
        }
    }
}

//检查两个元素之间的序偶
int Posets::compare_element(char a, char b) {
    if (a == b) { return -1; }//元素相同则返回-1
    for (int i = 0; i < rales.size(); i++) {
        if (rales[i][0] == a && rales[i][1] == b) { return 1; }//有<a, b>则返回1
        if (rales[i][0] == b && rales[i][1] == a) { return -1; }//有<b, a>则返回1
    }
    return 1;//没有关系则返回1
}

//转化为数组形式的偏序集
void Posets::init_rales() {
    //遍历初始的偏序集字符串的每个元素
    int i = 0;
    while (i < row_rales.size()) {
        //遇到"<"号则将后面的两个元素合并为一个字符串存入数组
        if (row_rales[i] == '<') {
            string rale = "";
            while (row_rales[i] != '>') {
                if ((row_rales[i] >= 'a' && row_rales[i] <= 'z') || (row_rales[i] >= '0' && row_rales[i] <= '9')) {
                    rale += row_rales[i];
                    i++;
                }
                else {
                    i++;
                }
            }
            rales.push_back(rale);
        }
        i++;
    }
}

//格的类，继承偏序集类
class Grids : public Posets{
public:
    char min_element;//最大元
    char max_element;//最小元
    vector<char> elements;//元素数组

    void generate_elements();//提取出所有元素
    void generate_Mm();//找到最大元和最小元
    char get_min(vector<char> eles);//在一个元素数组中找到最小元
    char get_max(vector<char> eles);//在一个元素数组中找到最大元
    vector<char> find_big(char a);//找到比a元素高位的元素
    vector<char> find_small(char a);//找到比a元素低位的元素
    vector<char> find_same(vector<char> elem1, vector<char> elem2);//找到两个元素数组中相同的元素
    char union_element(char a, char b);//并运算
    char intersection_element(char a, char b);//交运算
    bool is_mend();//判断是否为有补格
};

//判断是否为有补格
bool Grids::is_mend() {
    int count = 0;//记录有补元的个数
    //两次遍历所以元素，并找他们的补元
    for (int i = 0; i < elements.size(); i++) {
        for (int j = 0; j < elements.size(); j++) {
            //若找到并运算结果为最大元且交运算为最小元则此元素有补元，count加一
            if (union_element(elements[i], elements[j]) == max_element && intersection_element(elements[i], elements[j]) == min_element) {
                count++;
                break;
            }
        }
    }
    //若所以元素都有补元则此格为有补格
    if (count == elements.size()) { return true; }
    return false;
}

//交运算
char Grids::intersection_element(char a, char b) {
    //与最小元的交运算结果还是最小元
    if (a == min_element || b == min_element) { return min_element; }
    vector<char> small_a_elements = find_small(a);//找到在a元素下位的所有元素
    vector<char> small_b_elements = find_small(b);//找到在b元素下位的所有元素
    vector<char> same_elements = find_same(small_a_elements, small_b_elements);//找到上面两组元素中的相同元素
    return get_max(same_elements);//返回相同元素中的最大元素
}

//并运算
char Grids::union_element(char a, char b) {
    //与最大元的并运算结果还是最大元
    if (a == max_element || b == max_element) { return max_element; }
    vector<char> big_a_elements = find_big(a);//找到在a元素上位的所有元素
    vector<char> big_b_elements = find_big(b);//找到在b元素上位的所有元素
    vector<char> same_elements = find_same(big_a_elements, big_b_elements);//找到上面两组元素中的相同元素
    return get_min(same_elements);//返回相同元素中的最小元素
}

//找到两个元素数组中相同的元素
vector<char> Grids::find_same(vector<char> elem1, vector<char> elem2) {
    vector<char> same_elements;//相同元素数组
    //两两对比两个数组所以元素，相同元素存入相同元素数组
    for (int i = 0; i < elem1.size(); i++) {
        for (int j = 0; j < elem2.size(); j++) {
            if (elem1[i] == elem2[j]) { same_elements.push_back(elem1[i]); }
        }
    }
    return same_elements;//返回元素数组
}

//找到比a元素低位的元素
vector<char> Grids::find_small(char a) {
    vector<char> small_elements;//低位元素数组
    //先遍历一次元素数组，找到与a有直接关系低位的元素
    for (int i = 0; i < elements.size(); i++) {
        if (a != elements[i] && compare_element(a, elements[i]) == -1) { small_elements.push_back(elements[i]); }
    }
    //再找到与a有直接关系低位的元素还要低位的所有元素
    while (small_elements.back() != min_element) {
        for (int i = 0; i < elements.size(); i++) {
            if (small_elements.back() != elements[i] && compare_element(small_elements.back(), elements[i]) == -1) { small_elements.push_back(elements[i]); }
        }
    }
    return small_elements;//返回低位元素数组
}

//找到比a元素高位的元素
vector<char> Grids::find_big(char a) {
    vector<char> big_elements;//高位元素数组
    //先遍历一次元素数组，找到与a有直接关系高位的元素
    for (int i = 0; i < elements.size(); i++) {
        if (a != elements[i] && compare_element(elements[i], a) == -1) { big_elements.push_back(elements[i]); }
    }
    //再找到与a有直接关系低位的元素还要高位的所有元素
    while (big_elements.back() != max_element) {
        for (int i = 0; i < elements.size(); i++) {
            if (big_elements.back() != elements[i] && compare_element(elements[i], big_elements.back()) == -1) { big_elements.push_back(elements[i]); }
        }
    }
    return big_elements;//返回高位元素数组
}

//在一个元素数组中找到最小元
char Grids::get_min(vector<char> eles) {
    char init_min_element = eles[0];//先将最小元初始化为第一个元素
    //遍历元素数组比较大小，出现更小元则代替原来的最小元
    for (int i = 0; i < eles.size(); i++) {
        if (init_min_element != eles[i] && compare_element(init_min_element, eles[i]) == -1) {
            init_min_element = eles[i];
        }
    }
    return init_min_element;//返回最小元
}

//在一个元素数组中找到最大元
char Grids::get_max(vector<char> eles) {
    char init_max_element = eles[0];//先将最大元初始化为第一个元素
    //遍历元素数组比较大小，出现更大元则代替原来的最大元
    for (int i = 0; i < eles.size(); i++) {
        if (init_max_element != eles[i] && compare_element(eles[i], init_max_element) == -1) {
            init_max_element = eles[i];
        }
    }
    return init_max_element;//返回最大元
}

//找到最大元和最小元
void Grids::generate_Mm() {
    min_element = get_min(elements);//在所有元素中找到最小元
    max_element = get_max(elements);//在所有元素中找到最大元
}

//提取出所有元素
void Grids::generate_elements() {
    //遍历字符串找到元素，若元素数组中无此元素则在数组中添加
    for (int i = 0; i < row_rales.size(); i++) {
        if ((row_rales[i] >= 'a' && row_rales[i] <= 'z') || (row_rales[i] >= '0' && row_rales[i] <= '9')) {
            int count = 0;
            for (int j = 0; j < elements.size(); j++) {
                if (row_rales[i] == elements[j]) { count = 1; }
            }
            if (count == 0) { elements.push_back(row_rales[i]); }
        }
    }
}

int main() {
    Posets poset;//实例化一个格对象
    poset.init_row_rales("{<a,b>,<a,a>,<a,c>,<b,d>,<a,d>,<c,d>,<d,d>}");//初始化格
    poset.init_rales();//转化为数组形式
    poset.init_cov_row_rales();//生成偏序集
    poset.init_cov_rales();//偏序集转化为字符串
    poset.output_cov_rales();//输出偏序集

    Grids grid;//实例化一个格
    grid.init_row_rales("{ <0,c>,<0,d>,<c,a>,<d,b>,<a,1>,<b,1>}");//初始化格
    grid.init_rales();//转化为数组
    grid.generate_elements();//提取格内所以元素
    grid.generate_Mm();//找到其中最大元和最小元
    //判断是否为有补格
    if (grid.is_mend()) {
        cout << "此格为有补格" << endl;
    } else {
        cout << "此格不为有补格" << endl;
    }
    return 0;
}