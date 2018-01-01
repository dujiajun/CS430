#include <iostream>
#include<fstream>
using namespace std;

int main()
{
    fstream fp;//("file.dat");
    int num,cnt=0,sum=0;
    fp.open("file.txt");//,ios::in);//ifstream::in);
    if(!fp){cerr<<"error1";return 1;}
    while (fp>>num)
    {
        sum+=num;
        cnt++;
    }
    fp<<sum<<" ";
    fp<<cnt<<endl;
    //ofstream outfile("file.txt");
    //outfile<<" "<<(1.0*sum/cnt);
    //fp.close();
    //fp.open("file.txt",ifstream::out);
    /*
    if(!fp)
    {
        cerr<<"error2";
        return 1;
    }
    else

    double i;*/
    //fp>>i;
    //fp.open("file.txt",ofstream::out);
    fp<<(1.0*sum/cnt);
    //为什么不能读入啊！！
    fp.close();

    return 0;
}
