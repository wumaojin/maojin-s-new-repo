#include<iostream>
#include<vector>
#include<string>

using namespace std;

//ƫ�򼯶���
class Posets {
public:
    string row_rales;//��ʼ�����ƫ��
    vector<string> rales;//ת��Ϊ�����ƫ��
    vector<string> cov_row_rales;//������ʽ�ĸ��Ǽ�
    string cov_rales;//��������ĸ��Ǽ�

    //��ʼ������ƫ��
    void init_row_rales(string rale) {
        this->row_rales = rale;
    }
    void init_rales();//ת��Ϊ������ʽ��ƫ��
    int compare_element(char a, char b);//�������Ԫ��֮�����ż
    void init_cov_row_rales();//�������Ǽ�
    void init_cov_rales();//��������ʽ�ĸ��Ǽ�ת��Ϊ�ַ���
    void output_cov_rales();//������յĸ��Ǽ�
};

//������յĸ��Ǽ�
void Posets::output_cov_rales() {
    cout << "��ƫ�򼯵ĸ��Ǽ�Ϊ��";
    cout << cov_rales << endl;
}

//��������ʽ�ĸ��Ǽ�ת��Ϊ�ַ���
void Posets::init_cov_rales() {
    //��һ���ַ�������
    string str = "";
    //�����ɴ�����
    str += "{ ";
    //����ƫ�����鲢��Ӽ���źͼ���Ķ���
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
    //�������Ĵ�����
    str += " }";
    cov_rales = str;
}

//�������Ǽ�
void Posets::init_cov_row_rales() {
    //����ƫ������
    for (int i = 0; i < rales.size(); i++) {
        int judge = 0;//�ж�״̬��һ����ʱ����
        char first_element = rales[i][0];//��ż�ĵ�һ��Ԫ��
        char second_element = rales[i][1];//��ż�ĵڶ���Ԫ��
        if (first_element == second_element) { judge = 1; }//Ԫ����ͬ�ж�ֵΪ1
        //�ٴα���ƫ�����飬�ҵ��͵�һ��Ԫ����ͬ����ż�����Ƚϴ���ż�ĵڶ���Ԫ�أ��Ƿ�֮��Ҳ�в�����������ż�������ж�ֵΪ1
        for (int j = 0; j < rales.size(); j++) {
            if (rales[j][0] == first_element && first_element != rales[j][1] && compare_element(second_element, rales[j][1]) == -1 && j != i) {
                judge = 1;
            }
        }
        //�ж�ֵ��δ����Ϊ1�򽫴���ż���븲�Ǽ�����
        if (judge == 0) {
            cov_row_rales.push_back(rales[i]);
        }
    }
}

//�������Ԫ��֮�����ż
int Posets::compare_element(char a, char b) {
    if (a == b) { return -1; }//Ԫ����ͬ�򷵻�-1
    for (int i = 0; i < rales.size(); i++) {
        if (rales[i][0] == a && rales[i][1] == b) { return 1; }//��<a, b>�򷵻�1
        if (rales[i][0] == b && rales[i][1] == a) { return -1; }//��<b, a>�򷵻�1
    }
    return 1;//û�й�ϵ�򷵻�1
}

//ת��Ϊ������ʽ��ƫ��
void Posets::init_rales() {
    //������ʼ��ƫ���ַ�����ÿ��Ԫ��
    int i = 0;
    while (i < row_rales.size()) {
        //����"<"���򽫺��������Ԫ�غϲ�Ϊһ���ַ�����������
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

//����࣬�̳�ƫ����
class Grids : public Posets{
public:
    char min_element;//���Ԫ
    char max_element;//��СԪ
    vector<char> elements;//Ԫ������

    void generate_elements();//��ȡ������Ԫ��
    void generate_Mm();//�ҵ����Ԫ����СԪ
    char get_min(vector<char> eles);//��һ��Ԫ���������ҵ���СԪ
    char get_max(vector<char> eles);//��һ��Ԫ���������ҵ����Ԫ
    vector<char> find_big(char a);//�ҵ���aԪ�ظ�λ��Ԫ��
    vector<char> find_small(char a);//�ҵ���aԪ�ص�λ��Ԫ��
    vector<char> find_same(vector<char> elem1, vector<char> elem2);//�ҵ�����Ԫ����������ͬ��Ԫ��
    char union_element(char a, char b);//������
    char intersection_element(char a, char b);//������
    bool is_mend();//�ж��Ƿ�Ϊ�в���
};

//�ж��Ƿ�Ϊ�в���
bool Grids::is_mend() {
    int count = 0;//��¼�в�Ԫ�ĸ���
    //���α�������Ԫ�أ��������ǵĲ�Ԫ
    for (int i = 0; i < elements.size(); i++) {
        for (int j = 0; j < elements.size(); j++) {
            //���ҵ���������Ϊ���Ԫ�ҽ�����Ϊ��СԪ���Ԫ���в�Ԫ��count��һ
            if (union_element(elements[i], elements[j]) == max_element && intersection_element(elements[i], elements[j]) == min_element) {
                count++;
                break;
            }
        }
    }
    //������Ԫ�ض��в�Ԫ��˸�Ϊ�в���
    if (count == elements.size()) { return true; }
    return false;
}

//������
char Grids::intersection_element(char a, char b) {
    //����СԪ�Ľ�������������СԪ
    if (a == min_element || b == min_element) { return min_element; }
    vector<char> small_a_elements = find_small(a);//�ҵ���aԪ����λ������Ԫ��
    vector<char> small_b_elements = find_small(b);//�ҵ���bԪ����λ������Ԫ��
    vector<char> same_elements = find_same(small_a_elements, small_b_elements);//�ҵ���������Ԫ���е���ͬԪ��
    return get_max(same_elements);//������ͬԪ���е����Ԫ��
}

//������
char Grids::union_element(char a, char b) {
    //�����Ԫ�Ĳ��������������Ԫ
    if (a == max_element || b == max_element) { return max_element; }
    vector<char> big_a_elements = find_big(a);//�ҵ���aԪ����λ������Ԫ��
    vector<char> big_b_elements = find_big(b);//�ҵ���bԪ����λ������Ԫ��
    vector<char> same_elements = find_same(big_a_elements, big_b_elements);//�ҵ���������Ԫ���е���ͬԪ��
    return get_min(same_elements);//������ͬԪ���е���СԪ��
}

//�ҵ�����Ԫ����������ͬ��Ԫ��
vector<char> Grids::find_same(vector<char> elem1, vector<char> elem2) {
    vector<char> same_elements;//��ͬԪ������
    //�����Ա�������������Ԫ�أ���ͬԪ�ش�����ͬԪ������
    for (int i = 0; i < elem1.size(); i++) {
        for (int j = 0; j < elem2.size(); j++) {
            if (elem1[i] == elem2[j]) { same_elements.push_back(elem1[i]); }
        }
    }
    return same_elements;//����Ԫ������
}

//�ҵ���aԪ�ص�λ��Ԫ��
vector<char> Grids::find_small(char a) {
    vector<char> small_elements;//��λԪ������
    //�ȱ���һ��Ԫ�����飬�ҵ���a��ֱ�ӹ�ϵ��λ��Ԫ��
    for (int i = 0; i < elements.size(); i++) {
        if (a != elements[i] && compare_element(a, elements[i]) == -1) { small_elements.push_back(elements[i]); }
    }
    //���ҵ���a��ֱ�ӹ�ϵ��λ��Ԫ�ػ�Ҫ��λ������Ԫ��
    while (small_elements.back() != min_element) {
        for (int i = 0; i < elements.size(); i++) {
            if (small_elements.back() != elements[i] && compare_element(small_elements.back(), elements[i]) == -1) { small_elements.push_back(elements[i]); }
        }
    }
    return small_elements;//���ص�λԪ������
}

//�ҵ���aԪ�ظ�λ��Ԫ��
vector<char> Grids::find_big(char a) {
    vector<char> big_elements;//��λԪ������
    //�ȱ���һ��Ԫ�����飬�ҵ���a��ֱ�ӹ�ϵ��λ��Ԫ��
    for (int i = 0; i < elements.size(); i++) {
        if (a != elements[i] && compare_element(elements[i], a) == -1) { big_elements.push_back(elements[i]); }
    }
    //���ҵ���a��ֱ�ӹ�ϵ��λ��Ԫ�ػ�Ҫ��λ������Ԫ��
    while (big_elements.back() != max_element) {
        for (int i = 0; i < elements.size(); i++) {
            if (big_elements.back() != elements[i] && compare_element(elements[i], big_elements.back()) == -1) { big_elements.push_back(elements[i]); }
        }
    }
    return big_elements;//���ظ�λԪ������
}

//��һ��Ԫ���������ҵ���СԪ
char Grids::get_min(vector<char> eles) {
    char init_min_element = eles[0];//�Ƚ���СԪ��ʼ��Ϊ��һ��Ԫ��
    //����Ԫ������Ƚϴ�С�����ָ�СԪ�����ԭ������СԪ
    for (int i = 0; i < eles.size(); i++) {
        if (init_min_element != eles[i] && compare_element(init_min_element, eles[i]) == -1) {
            init_min_element = eles[i];
        }
    }
    return init_min_element;//������СԪ
}

//��һ��Ԫ���������ҵ����Ԫ
char Grids::get_max(vector<char> eles) {
    char init_max_element = eles[0];//�Ƚ����Ԫ��ʼ��Ϊ��һ��Ԫ��
    //����Ԫ������Ƚϴ�С�����ָ���Ԫ�����ԭ�������Ԫ
    for (int i = 0; i < eles.size(); i++) {
        if (init_max_element != eles[i] && compare_element(eles[i], init_max_element) == -1) {
            init_max_element = eles[i];
        }
    }
    return init_max_element;//�������Ԫ
}

//�ҵ����Ԫ����СԪ
void Grids::generate_Mm() {
    min_element = get_min(elements);//������Ԫ�����ҵ���СԪ
    max_element = get_max(elements);//������Ԫ�����ҵ����Ԫ
}

//��ȡ������Ԫ��
void Grids::generate_elements() {
    //�����ַ����ҵ�Ԫ�أ���Ԫ���������޴�Ԫ���������������
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
    Posets poset;//ʵ����һ�������
    poset.init_row_rales("{<a,b>,<a,a>,<a,c>,<b,d>,<a,d>,<c,d>,<d,d>}");//��ʼ����
    poset.init_rales();//ת��Ϊ������ʽ
    poset.init_cov_row_rales();//����ƫ��
    poset.init_cov_rales();//ƫ��ת��Ϊ�ַ���
    poset.output_cov_rales();//���ƫ��

    Grids grid;//ʵ����һ����
    grid.init_row_rales("{ <0,c>,<0,d>,<c,a>,<d,b>,<a,1>,<b,1>}");//��ʼ����
    grid.init_rales();//ת��Ϊ����
    grid.generate_elements();//��ȡ��������Ԫ��
    grid.generate_Mm();//�ҵ��������Ԫ����СԪ
    //�ж��Ƿ�Ϊ�в���
    if (grid.is_mend()) {
        cout << "�˸�Ϊ�в���" << endl;
    } else {
        cout << "�˸�Ϊ�в���" << endl;
    }
    return 0;
}