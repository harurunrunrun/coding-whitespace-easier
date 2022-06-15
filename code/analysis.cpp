/*
auther harurun

Reference
https://magazine.rubyist.net/articles/0022/0022-Legwork.html#fn:2
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

const char space=' ';
const char tab='\t';
const char newline='\n';

string code;
unsigned int i=0;
vector<string> commands;
char imp1,imp2,cmd1,cmd2;

void output_commands(){
  for(const string& str:commands){
    cout<<str<<endl;
  }
}

char get(){
  while(code[i]!=space && code[i]!=tab && code[i]!=newline){
    i++;
    if(i==code.size()){
      cerr<<"wrong cmd"<<endl;
      exit(1);
    }
  }
  return code[i++];
}

long long read_num_or_value(){
  string tmp;
  while(code[i]!=newline){
    if(code[i]==space){
      tmp.append(1,'0');
    }else if(code[i]==tab){
      tmp.append(1,'1');
    }
    i++;
  }
  i++;
  if(tmp.size()==0){
    return 999999LL;
  }
  long long res=0;
  long long c=1;
  for(unsigned int j=tmp.size()-1;j>=1;j--){
    res+=c*(tmp[j]-'0');
    c*=2;
  }
  if(tmp[0]=='1'){
    res*=-1;
  }
  return res;
}

void stack_operation(){
  cmd1=get();
  switch(cmd1){
    case space:
      commands.push_back("push ");
      commands.back().append(to_string(read_num_or_value()));
      return;
    case newline:
      cmd2=get();
      switch(cmd2){
        case space:
          commands.push_back("copy_top");
          return;
        case tab:
          commands.push_back("swap");
          return;
        case newline:
          commands.push_back("pop");
          return;
        default:
          cerr<<"stack operation cmd1 = "<<cmd1<<" cmd2 = "<<cmd2<<" is not defined."<<endl;
          output_commands();
          exit(1);
      }
      return;
    default:
      cerr<<"stack operation cmd1 = "<<cmd1<<" is not defined."<<endl;
      output_commands();
      exit(1);
  }
}

void calculation(){
  cmd1=get();
  switch(cmd1){
    case space:
      cmd2=get();
      switch(cmd2){
        case space:
          commands.push_back("add");
          return;
        case tab:
          commands.push_back("sub");
          return;
        case newline:
          commands.push_back("mul");
          return;
        default:
          cerr<<"calculation cmd1 = "<<cmd1<<" cmd2 = "<<cmd2<<" is not defined."<<endl;
          output_commands();
          exit(1);
      }
      return;
    case tab:
      cmd2=get();
      switch(cmd2){
        case space:
          commands.push_back("div");
          return;
        case tab:
          commands.push_back("rem");
          return;
        default:
          cerr<<"calculation cmd1 = "<<cmd1<<" cmd2 = "<<cmd2<<" is not defined."<<endl;
          output_commands();
          exit(1);
      }
      return;
    default:
      cerr<<"calculation cmd1 = "<<cmd1<<" is not defined."<<endl;
      output_commands();
      exit(1);
  }
}

void heap_access(){
  cmd1=get();
  switch(cmd1){
    case space:
      commands.push_back("house");
      return;
    case tab:
      commands.push_back("take");
      return;
    default:
      cerr<<"heap_access cmd1 = "<<cmd1<<" is not defined."<<endl;
      output_commands();
      exit(1);
  }
}

void input_or_output(){
  cmd1=get();
  switch(cmd1){
    case space:
      cmd2=get();
      switch(cmd2){
        case space:
          commands.push_back("wt_chr");
          return;
        case tab:
          commands.push_back("wt_int");
          return;
        default:
          cerr<<"input_or_output cmd1 = "<<cmd1<<" cmd2 = "<<cmd2<<" is not defined."<<endl;
          output_commands();
          exit(1);
      }
      return;
    case tab:
      cmd2=get();
      switch(cmd2){
        case space:
          commands.push_back("rd_chr");
          return;
        case tab:
          commands.push_back("rd_int");
          return;
        default:
          cerr<<"input_or_output cmd1 = "<<cmd1<<" cmd2 = "<<cmd2<<" is not defined."<<endl;
          output_commands();
          exit(1);
      }
      return;
    default:
      cerr<<"input_or_output cmd1 = "<<cmd1<<" is not defined."<<endl;
      output_commands();
      exit(1);
  }
}

void flow_control(){
  cmd1=get();
  switch(cmd1){
    case space:
      cmd2=get();
      switch(cmd2){
        case space:
          commands.push_back("def ");
          commands.back().append(to_string(read_num_or_value()));
          return;
        case tab:
          commands.push_back("sbr ");
          commands.back().append(to_string(read_num_or_value()));
          return;
        case newline:
          commands.push_back("jump ");
          commands.back().append(to_string(read_num_or_value()));
          return;
        default:
          cerr<<"flow_control cmd1 = "<<cmd1<<" cmd2 = "<<cmd2<<" is not defined."<<endl;
          output_commands();
          exit(1);
      }
      return;
    case tab:
      cmd2=get();
      switch(cmd2){
        case space:
          commands.push_back("if0 ");
          commands.back().append(to_string(read_num_or_value()));
          return;
        case tab:
          commands.push_back("ifm ");
          commands.back().append(to_string(read_num_or_value()));
          return;
        case newline:
          commands.push_back("quit_sbr");
          return;
        default:
          cerr<<"flow_control cmd1 = "<<cmd1<<" cmd2 = "<<cmd2<<" is not defined."<<endl;
          output_commands();
          exit(1);
      }
      return;
    case newline:
      cmd2=get();
      switch(cmd2){
        case newline:
          commands.push_back("exit");
          return;
        default:
          cerr<<"flow_control cmd1 = "<<cmd1<<" cmd2 = "<<cmd2<<" is not defined."<<endl;
          output_commands();
          exit(1);
      }
      return;
    default:
      cerr<<"flow_control cmd1 = "<<cmd1<<" is not defined."<<endl;
      output_commands();
      exit(1);
  }
}

void analysis_code(){
  imp1=get();
  switch(imp1){
    case space:
      stack_operation();
      return;
    case tab:
      imp2=get();
      switch(imp2){
        case space:
          calculation();
          return;
        case tab:
          heap_access();
          return;
        case newline:
          input_or_output();
          return;
        default:
          cerr<<"analysis_code imp1 = "<<imp1<<" imp2 = "<<imp2<<" is not defined."<<endl;
          output_commands();
          exit(1);
      }
      return;
    case newline:
      flow_control();
      return;
    default:
      cerr<<"analysis_code imp1 = "<<imp1<<" is not defined."<<endl;
      output_commands();
      exit(1);
  }
}

int main(){
  getline(cin,code,'\0');
  while(i<code.size()){
    analysis_code();
  }
  output_commands();
}
