#include<iostream>
#include<fstream>
#include<cstdio>
#include<vector>
#include<string>
#define MAX 100000000   // 将MAX看做正无穷
using namespace std;
int var_count;  // 目标函数中变量的个数
int con_count;  // 约束条件的个数
vector<double> coe;     // (两个0 加上)目标函数的系数
vector<string> var_name;    // 储存基变量的名称
typedef struct
{
    int row;    // 主元素的列
    int col;    // 主元素的行
    double sigma_max;   // σ 最大值
    double theta_min;   // θ 最小值
} pos;  // 主元素的信息

// 判断是否为最终表, σ 均小于等于 0
bool isEnd(vector<vector<double>> &table)
{
    for(int i = 2; i < table[0].size(); i++)
    {
        if(table[0][i] > 0)
            return false;
    }
    return true;
}

// 寻找主元素
pos get_hostElement(vector<vector<double>> &table)
{
    pos res;
    res.sigma_max = 0;
    // 寻找主元素的列
    for(int i = 0; i < table[0].size(); i++)
	{
		if(table[0][i] > res.sigma_max)
		{
            res.col = i;
            res.sigma_max = table[0][i];
        }
    }
    res.theta_min = MAX;

    // 寻找主元素的行
    for(int i = 1; i < table.size(); i++)
	{
		double divisor = table[i][res.col];
        // 如果除数为 0， 看做正无穷
		double theta = divisor == 0 ? MAX : table[i][1]/divisor;
		if(theta >= 0 && theta < res.theta_min)
		{
			res.theta_min = theta;
			res.row = i;
		}
	}
    return res;
}

int iterate_count = 1; // 迭代次数 
// 进行基变换并改变表中元素的值
void change(vector<vector<double>> &table, pos host_pos)
{
	cout<<"第"<<iterate_count++<<"迭代运算"<<endl; 
    int row = host_pos.row; // 换出变量，将第row行 x 的下标改为 col - 1
	int col = host_pos.col; // 换入变量，下标为col - 1
    var_name[row-1] = "x" + to_string(col-1);
    table[row][0] = coe[col];
    // 改变主元素那一行，主元素变为 1
    for(int j = 1; j < table[0].size(); j++)
	{
		if(j == col) continue;
		table[row][j] /= table[row][col];
	}
    table[row][col] = 1;
    // 初等行变换，改变非主元素哪一行，主元素那一列变为 0
    for(int i = 1; i < table.size(); i++)
	{
		if(i == row) continue;
		double temp = table[i][col];
		for(int j = 1; j < table[0].size(); j++)
		{
			table[i][j] -= temp*table[row][j];
		}
	}
    // 改变第一行，第一行是 σ(检验数)
    for(int j = 2; j < table[0].size(); j++)
	{
        table[0][j] = coe[j];
		for(int i = 1; i < table.size(); i++)
		{
			table[0][j] -= table[i][j]*table[i][0];
		}
	}
    // 输出此次迭代运算得到的表
    for(int i = 1; i < table.size(); i++)
	{
        cout<<var_name[i-1]<<"  ";
		for(int j = 0; j < table[0].size(); j++)
		{
			cout<<table[i][j]<<" ";
		}
		cout<<endl;
	}
    // 输出检验数
    cout<<"σ  ";
    for(int j = 2; j < table[0].size(); j++)
    {
        cout<<table[0][j]<<" ";
    }
    cout<<endl<<endl;
}

// 迭代运算
double iterate(vector<vector<double>> &table)
{
    // 是否为最终表
	if(isEnd(table))
	{
		double res = 0;
		for(int i = 0; i < table.size(); i++)
		{
			res += table[i][0]*table[i][1];
		}
		return res;
	}
    pos host_pos = get_hostElement(table);
	change(table, host_pos);
    // 若不是递归进入下一个表
	return iterate(table);
}

// 主函数，给出初始表
int main()
{
	freopen("LP3.txt","r",stdin);
    cin>>var_count; // 读取变量数
    cin>>con_count; // 读入约束条件个数
    int row = con_count + 1;
    int col = con_count + var_count + 2;
	vector<vector<double>> table(row, vector<double>(col, 0));
    // 读入初始表
    for(int i = 0; i < table.size(); i++)
    {
		for(int j = 0; j < var_count + 2; j++)
		{
            cin>>table[i][j];
        }
        // 加入松弛变量
        if(i > 0)
        {
            table[i][var_count+i+1] = 1; 
        }
    }
    // 储存目标函数系数
    for(int j = 0; j < table[0].size(); j++) 
	{
		coe.emplace_back(table[0][j]);
	}
    // 储存基变量名称
    for(int i = 0; i < table.size(); i++)
    {
        string str = "x" + to_string(var_count+i+1);
        var_name.emplace_back(str);
    }
    // 输出初始表
	cout<<"初始表: "<<endl; 
    for(int i = 1; i < table.size(); i++)
	{
        cout<<var_name[i-1]<<"  ";
		for(int j = 0; j < table[0].size(); j++)
		{
			cout<<table[i][j]<<" ";
		}
		cout<<endl;
	}
    cout<<"σ  ";
    for(int j = 2; j < table[0].size(); j++)
    {
        cout<<table[0][j]<<" ";
    }
    cout<<endl<<endl;
    cout<<"max="<<iterate(table)<<endl;
    cout<<"X = ( ";
    for(int i = 0; i < var_count+con_count; i++)
	{
		bool flag = true;
		for(int j = 0; j < var_name.size(); j++)
		{
			if(int(var_name[j][1]) - 49 == i)
			{
				cout<<table[j+1][1]<<" ";
				flag = false;
			}
		}
		if(flag) cout<<0<<" ";	
	} 
	cout<<")";
    return 0;
}