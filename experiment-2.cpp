#include<iostream>

using namespace std;

//计算字符串长度
int len(char* arr)
{
    int i = 0;
    while (arr[i] != '\0')
    {
        i++;
    }

    return i;
}

//矩阵乘法
int** multiply(int** list, int** A, int count)
{
    int **M = new int*[count];
    for(int j=0;j<count;j++)
        M[j] = new int[count];

    for (int i = 0; i < count; i++)
        for (int j = 0; j < count; j++)
            M[i][j] = 0;

    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < count; j++)
        {
            for (int k = 0; k < count; k++)
            {
                M[i][j] += list[i][k]*A[k][j];
            }
        }
    }

    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < count; j++)
        {
            list[i][j] = M[i][j];
        }
    }

    for (int i = 0; i < count; i++)
            delete[] M[i];
        delete[] M;

    return list;
}

int main()
{
    char A[] = "{a, b, c, d}";
    char R[] = "{<a,b>,<b,a>,<b,c>,<c,c,>,<c,d>}";
    //计算元素个数
    int count = 0;
    char* Alist = new char[len(A)]; 
    for(int i=0;i<len(A);i++)
    {
        if(A[i] >= 'a' && A[i] <='z')
        {
            Alist[count] = A[i];
            count++;
        }
    }

    //转化为关系矩阵
    int **list = new int*[count];
    for(int j=0;j<count;j++)
        list[j] = new int[count];

    for(int j=0;j<count;j++)
        for(int k=0;k<count;k++)
            list[j][k] = 0;
    
    int num = 0;
    int width = -1, height = -1;
    for(int i=0;i<len(R);i++)
    {
        if(R[i] >= 'a' && R[i] <= 'z')
        {
            if(num == 0)
            {
                for(int j=0;j<count;j++)
                {
                    if(R[i] == Alist[j])
                        width = j;
                        
                    num = 1;
                }
            }else{
                for(int j=0;j<count;j++)
                {
                    if(R[i] == Alist[j]){
                        height = j;
                        list[width][height] = 1;
                        width = -1;
                        height = -1;
                    }
                    num = 0;
                }
            }
            
        }
    }

    //验证自反性
    for(int i=0;i<count;i++){
        if(list[i][i] != 1)
        {
            cout<<"不满足自反性"<<endl;
            break;
        }
        if(i == count-1)
            cout<<"满足自反性"<<endl;
    }

    //验证对称性
    int record = 0;
    for(int i=0;i<count;i++)
    {
        for(int j=0;j<count;j++)
        {
            if(list[i][j] != list[j][i])
            {
                cout<<"不满足对称性"<<endl;
                record++;
            }
            if(i == count-1 && j == count-1 && record == 0)
                cout<<"满足对称性"<<endl;
        }
        if(record != 0)
            break;
    }

    //验证传递性
    int **M = new int*[count];
    for(int j=0;j<count;j++)
        M[j] = new int[count];

    for (int i = 0; i < count; i++)
        for (int j = 0; j < count; j++)
            M[i][j] = 0;

    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < count; j++)
        {
            for (int k = 0; k < count; k++)
            {
                M[i][j] += list[i][k]*list[k][j];
            }
        }
    }

    record = 0; 
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < count; j++)
        {
            if(list[i][j] == 0 && M[i][j] != 0)
            {
                 record++;
                 cout<<"不满足传递性"<<endl;
                 break;
            }
            if(i == count-1 && j == count-1 && record == 0)
                cout<<"满足传递性"<<endl;
        }
        if(record != 0)
            break;
    }

    //求自反闭包
    int **r = new int*[count];
    for(int j=0;j<count;j++)
        r[j] = new int[count];

    for (int i = 0; i < count; i++)
        for(int j=0;j<count;j++)
            r[i][j] = list[i][j];
    for (int i = 0; i < count; i++)
        r[i][i] = 1;
    cout<<"自反闭包为：";
    record = 0;
    cout<<"{";
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < count; j++)
        {
            if(r[i][j] == 1)
            {
                if(record != 0)
                    cout<<",";
                cout<<"<"<<Alist[i]<<","<<Alist[j]<<">";
                record = 1;
            }
        }
    }
    cout<<"}"<<endl;

    //求对称闭包
    int **s = new int*[count];
    for(int j=0;j<count;j++)
        s[j] = new int[count];

    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < count; j++)
        {
            if(list[i][j] == 1)
            {
                s[i][j] = 1;
                s[j][i] = 1;
            }
        }
    }
    cout<<"对称闭包为：";
    record = 0;
    cout<<"{";
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < count; j++)
        {
            if(s[i][j] == 1)
            {
                if(record != 0)
                    cout<<",";
                cout<<"<"<<Alist[i]<<","<<Alist[j]<<">";
                record = 1;
            }
        }
    }
    cout<<"}"<<endl;

    //求传递闭包
    int **t = new int*[count];
    for(int j=0;j<count;j++)
        t[j] = new int[count];
    for (int i = 0; i < count; i++)
        for(int j=0;j<count;j++)
            t[i][j] = list[i][j];
    int **T = new int*[count];
    for(int j=0;j<count;j++)
        T[j] = new int[count];
    for (int i = 0; i < count; i++)
        for(int j=0;j<count;j++)
            T[i][j] = list[i][j];
    for (int i = 1; i < count; i++)
    {
        T = multiply(T, list, count);
        for (int i = 0; i < count; i++)
        {
            for (int j = 0; j < count; j++)
            {
                if(T[i][j] == 1)
                    t[i][j] = 1;
            }
        }
    }
    cout<<"传递闭包为：";
    record = 0;
    cout<<"{";
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < count; j++)
        {
            if(t[i][j] == 1)
            {
                if(record != 0)
                    cout<<",";
                cout<<"<"<<Alist[i]<<","<<Alist[j]<<">";
                record = 1;
            }
        }
    }
    cout<<"}"<<endl;

    //释放空间
    delete[] Alist;
    for (int i = 0; i < count; i++)
            delete[] list[i];
        delete[] list;
    for (int i = 0; i < count; i++)
            delete[] M[i];
        delete[] M;
    for (int i = 0; i < count; i++)
            delete[] r[i];
        delete[] r;
    for (int i = 0; i < count; i++)
            delete[] s[i];
        delete[] s;
    for (int i = 0; i < count; i++)
            delete[] t[i];
        delete[] t;

    return 0;
}

