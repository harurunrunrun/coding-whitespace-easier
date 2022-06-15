/*
auther harurun

Reference
https://magazine.rubyist.net/articles/0022/0022-Legwork.html#fn:2
*/

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <stdlib.h>
using namespace std;

stringstream buf;

const char space=' ';
const char tab='\t';
const char newline='\n';

void num(string x){
  long long n=stoll(x);
  if(n<0){
    buf<<tab;
    n=-n;
  }else{
    buf<<space;
  }
  string bin;
  while(n>0){
    if(n&1){
      bin.append(1,tab);
    }else{
      bin.append(1,space);
    }
    n>>=1;
  }
  reverse(bin.begin(),bin.end());
  buf<<bin;
  buf<<newline;
}

void analysis_line(string line){
  string cmd;
  string arg;
  stringstream ss(line);
  ss>>cmd;
  if(cmd=="push"){
    buf<<space<<space;
    ss>>arg;
    num(arg);
  }else if(cmd=="copy_top"){
    // 複製
    buf<<space<<newline<<space;
  }else if(cmd=="swap"){
    // topとsecondを交換
    buf<<space<<newline<<tab;
  }else if(cmd=="pop"){
    buf<<space<<newline<<newline;
  }else if(cmd=="add"){
    buf<<tab<<space<<space<<space;
  }else if(cmd=="sub"){
    buf<<tab<<space<<space<<tab;
  }else if(cmd=="mul"){
    buf<<tab<<space<<space<<newline;
  }else if(cmd=="div"){
    buf<<tab<<space<<tab<<space;
  }else if(cmd=="rem"){
    // 剰余
    buf<<tab<<space<<tab<<tab;
  }else if(cmd=="house"){
    // 値をアドレスに格納
    buf<<tab<<tab<<space;
  }else if(cmd=="take"){
    // アドレスから値をスタックに
    buf<<tab<<tab<<tab;
  }else if(cmd=="def"){
    // ラベル定義
    buf<<newline<<space<<space;
    ss>>arg;
    num(arg);
  }else if(cmd=="sbr"){
    // サブルーチン呼出し
    buf<<newline<<space<<tab;
    ss>>arg;
    num(arg);
  }else if(cmd=="jump"){
    buf<<newline<<space<<newline;
    ss>>arg;
    num(arg);
  }else if(cmd=="if0"){
    // top==0のときjump
    buf<<newline<<tab<<space;
    ss>>arg;
    num(arg);
  }else if(cmd=="ifm"){
    // top<0のときjump
    buf<<newline<<tab<<tab;
    ss>>arg;
    num(arg);
  }else if(cmd=="quit_sbr"){
    // サブルーチン終了
    buf<<newline<<tab<<newline;
  }else if(cmd=="exit"){
    buf<<newline<<newline<<newline;
  }else if(cmd=="wt_chr"){
    // topを文字として出力
    buf<<tab<<newline<<space<<space;
  }else if(cmd=="wt_int"){
    // topを数値として出力
    buf<<tab<<newline<<space<<tab;
  }else if(cmd=="rd_chr"){
    // アドレスに格納
    buf<<tab<<newline<<tab<<space;
  }else if(cmd=="rd_int"){
    buf<<tab<<newline<<tab<<tab;
  }else if(cmd.empty()){
    
  }else{
    cerr<<"wrong word: "<<cmd<<endl;
    exit(1);
  }
}

int main(){
  string line;
  while(!cin.eof()){
    getline(cin,line);
    analysis_line(line);
  }
  cout<<buf.str();
  fflush(stdout);
  return 0;
}
