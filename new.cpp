#include<iostream>
#include<vector>
#include<string>
#include<ctime>
#include<cstdlib>

using namespace std;

class Chart{
private:
    vector<char> V;//边
    vector<char> E;//结点
    vector<string> f;//从边到结点的函数关系
    vector<int> deg;//度

public:
    int get_rand(int start, int end);//取一个随机数
    void generate_chart(int m, int n);//随机生成一个图
    void generate_deg();//计算各结点的度
    bool judge_oula_road();//判断是否有欧拉路
    bool judge_euler_circuit();//判断是否有欧拉回路
};

//取一个随机数
int Chart::get_rand(int start, int end){
    return (rand() % (end - start + 1)) + start;
}

//随机生成一个图
void Chart::generate_chart(int m, int n){
    //生成边
    char v = 'a';
    for(int i=0;i<m;i++){
        V.push_back(v);
        v++;
    }
    //生成结点
    char e = '1';
    for(int i=0;i<n;i++){
        E.push_back(e);
        e++;
    }
    //生成边到结点的函数
    int num;
    for(int i=0;i<V.size();i++){
        //初始化一个字符串
        string str = "";
        //先把边添加进去
        str += V[i];
        //再随机取两个结点添加进字符串
        num = get_rand(0, E.size()-1);
        str += E[num];
        num = get_rand(0, E.size()-1);
        str += E[num];
        //字符串存入数组
        f.push_back(str);
    }
}

//计算各结点的度
void Chart::generate_deg(){
    for(int i=0;i<E.size();i++){
        int count = 0;//记录结点所领接的边数
        //遍历函数关系记录此点出现次数
        for(int j=0;j<f.size();j++){
            for(int k=0;k<f[j].size();k++){
                if(E[i] == f[j][k]){ count++; }
            }
        }
        //存入数组
        deg.push_back(count);
    }
}

//判断是否有欧拉路
bool Chart::judge_oula_road(){
    //统计各奇数度数和孤立结点数
    int arr[2] = {0};
    for(int i=0;i<deg.size();i++){
        if(deg[i] == 0){
            arr[0]++;
        }else if(deg[i]%2 == 1){
            arr[1]++;
        }
    }
    if(arr[0] != 0){return false;}//有孤立结点就没有欧拉路
    if(arr[1] == 0 || arr[1] == 2){return true;}//奇数度数不是0或2也不是欧拉路
    return false;
}

//判断是否有欧拉回路
bool Chart::judge_euler_circuit(){
    //记录偶度数结点个数
    int record = 0;
    for(int i=0;i<deg.size();i++){
        if(deg[i]%2 == 0 && deg[i] != 0){ record++; }
    }
    if(record == deg.size()){return true;}//若所以结点度数皆为偶数则有欧拉回路
    return false;//否则没有
}

int main(){

    srand(time(NULL));//随机数种子
    Chart chart;//实例化一个图对象
    chart.generate_chart(10, 6);//随机生成一个图
    chart.generate_deg();
    bool result = chart.judge_oula_road();
    if(result == true){
        cout<<"此图有欧拉路"<<endl;
    }else{
        cout<<"此图无欧拉路"<<endl;
    }
    result = chart.judge_euler_circuit();
    if(result == true){
        cout<<"此图有欧拉回路"<<endl;
    }else{
        cout<<"此图无欧拉回路"<<endl;
    }
    return 0;
}