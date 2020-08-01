

#include<iostream>
#include<cstdlib>
#include<fstream>
#include<string>
#include<cstdio>
#include<map>

using namespace std;

#include "DATA_STRUCTURES.cpp"
#include "Conversions.cpp"

bool isWhiteSpace(char a)
{
    if(a==' ')  return true;
    if(a=='\t') return true;
    return false;
}

void printforview()
{   
       

       
    
    if(1)
    {


      fstream   lst; 
      lst.open("list.txt",ios::out | ios::app);
      lst<<""<<endl;
       lst<<""<<endl;
       lst<<""<<endl;
       lst<<""<<endl;
       lst<<""<<endl;
      lst<<"symtableview"<<"_____________________________________________________________________________________________________"<<endl;
      lst<<"NAME\t\t\t\t\t\t\tadresss\t\t\t\t\t\t\tBlock"<<endl;
      MapType3::iterator it;        

      for (it = SYMTAB.begin(); it != SYMTAB.end(); it++)
       {
            pair<string,info_label> tra=*it;
            if(tra.second.exist=='n')continue;
            if(tra.first[0]=='=')continue;
            lst<<tra.first<<"\t\t\t\t\t\t\t"<<tra.second.address<<"\t\t\t\t\t\t\t"<<tra.second.block<<endl;
             
       }

     
       

       lst<<""<<endl;
       lst<<""<<endl;
       lst<<""<<endl;
       lst<<""<<endl;
       lst<<""<<endl;


       lst.close();

    }
    if(1)
    {
     

      fstream   lst; 
      lst.open("list.txt",ios::out | ios::app);
      lst<<"litableview"<<"_____________________________________________________________________________________________________"<<endl;
      lst<<"NAME\t\t\t\t\t\t\tadresss"<<endl;
      MapType7::iterator it;

      for (it = LITAB.begin(); it != LITAB.end(); it++)
       {
            pair<string,info_litab> tra=*it;
            if(tra.second.exist=='n')continue;
           // if(tra.first[0]=='=')continue;
            lst<<tra.first<<"\t\t\t\t\t\t\t"<<tra.second.address<<"\t\t\t\t\t\t\t"<<tra.second.block<<endl;
             
       }


       lst<<""<<endl;
       lst<<""<<endl;
       lst<<""<<endl;
       lst<<""<<endl;
       lst<<""<<endl;

       lst.close();
       



    }
      




      

}

void extract(string a,string word[],int& count)
{
    int i;
    for(i=0;i<5;++i) word[i]="";
    count=0;
    i=0;
    while(isWhiteSpace(a[i])&&i<a.length()) {++i;continue;}
    if(i==a.length()||a[i]=='.')   return;
    for(;i<a.length();)
    {
        while(isWhiteSpace(a[i])&&i<a.length()) {++i;continue;}
        if(i==a.length()) break;
        for(;!isWhiteSpace(a[i])&&i<a.length();++i) word[count]+=a[i];
        ++count;
    }

    if(word[0]!="EXTDEF")
    {
        if(word[0]!="EXTREF")
        {
            return;
        }
    }
    
    
    string h1=word[1];
    count--;
    word[1]="";
    for(int k1=0;k1<h1.length();k1++)
    {
        if(!isWhiteSpace(h1[k1])&&h1[k1]!=',')
        {
            word[count]+=h1[k1];

        }
        if(h1[k1]==',')count++;
    }

    count++;


    

    
}

void execute(string[],int);

int block_num,line;
hexa pc;
string curr_block;
bool error_flag=0;

    
ifstream fin1;
ofstream fout1,error;
fstream naku;


void run()
{
    
    fin1.close();
    fout1.close();
    error.close();
    


    string cset1;
    SYMTAB.clear();
    OPTAB.clear();
    SYMTAB.clear();
    BLOCK.clear();
    IMPORT.clear();
    EXPORT.clear();
    create();
    char ch;
    string s,word[5];
    int count=0;
    fin1.open("tempinput.txt");
    fout1.open("intermediate.txt",ios::out | ios::trunc);
    error.open("error.txt");
    line=5;
    getline(fin1,s);
    extract(s,word,count);
    while(count==0)
    {
        fout1<<line<<endl;
        fout1<<"$";
        fout1<<s<<endl;
        fout1<<""<<endl;
        fout1<<""<<endl;
        line+=5;
        cout<<"s: "<<s<<endl;
    }
    pc="0";
    BLOCK["DEFAULT"].num=0;
    BLOCK["DEFAULT"].address=pc;
    BLOCK["DEFAULT"].length="0";
    BLOCK["DEFAULT"].exist='y';
    curr_block="DEFAULT";
    block_num=1;
    line=5;
    if(word[0]=="START")
    {
        pc=word[1];
        fout1<<line<<endl;
        fout1<<""<<endl;
        fout1<<"START"<<endl;
        fout1<<pc<<endl;
        fout1<<pc<<endl;
        fout1<<""<<endl;
        cout<<"0 is start!"<<endl;
    }
    else if(word[1]=="START")
    {
        pc=word[2];
        fout1<<line<<endl;
        fout1<<word[0]<<endl;cset1=word[0];
        fout1<<"START"<<endl;
        fout1<<pc<<endl;
        fout1<<pc<<endl;
        fout1<<""<<endl;
        cout<<"1 is start!"<<endl;
    }
    else if(word[1]=="CSECT")
    {
        fout1<<line<<endl;
        fout1<<word[0]<<endl;cset1=word[0];
        fout1<<"START"<<endl;
        fout1<<pc<<endl;
        fout1<<pc<<endl;
        fout1<<""<<endl;
        cout<<"1 is start!"<<endl;
    }
    else
        execute(word,count);
    while(true)
    {
        getline(fin1,s);
        if(s.find("EXTDEF")!=string::npos||s.find("EXTREF")!=string::npos)
        {
           extract(s,word,count);
           for(int i=1;i<count;i++)
           {
             if(word[0]=="EXTDEF")
             {
                  EXPORT[word[i]].exist='y';
                  EXPORT[word[i]].cset=cset1;
             }
             else
             {

                // cout<<word[i]<<"                    DFGESDRFGYHJKXXCVBNHJMZXCVBNM*^RBBITykjGHSbjwah,admsbhfdm222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222"<<endl;
                 IMPORT[word[i]].exist='y';
                 IMPORT[word[i]].cset=cset1;
             }
           }
           continue;    
        }
        if(s.find("LTORG")!=string::npos)continue;



        extract(s,word,count);
       // cout<<s<<endl;
        
        line+=5;
        cout<<"s: "<<s<<endl;
        fout1<<line<<endl;
        if(count==0)
        {
            cout<<"Comment detected!"<<endl;
            fout1<<"$"<<endl;
            fout1<<s<<endl;
            fout1<<""<<endl;
            fout1<<""<<endl;
            fout1<<""<<endl;
            continue;
        }
        
         if(word[0]=="END")
        {
            cout<<"entered here*********************************************************************88for"<<cset1<<endl;
            BLOCK[curr_block].length=pc;
            fout1<<""<<endl;
            fout1<<word[0]<<endl;
            fout1<<word[1]<<endl;
            fout1<<pc<<endl;
            fout1<<""<<endl;

            printforview();    
            
       

            break;

        }
        execute(word,count);
       // cin>>ch;
     }
     hexa addr,len;
     string temp=find_block(0);
     addr=BLOCK[temp].address;
     len=BLOCK[temp].length;
     for(int i=1;i<block_num;++i)
     {
            temp=find_block(i);
            BLOCK[temp].address=toHex(toDec(addr)+toDec(len));
            addr=BLOCK[temp].address;
            len=BLOCK[temp].length;

     }







}

void execute(string word[],int count)
{
    cout<<"word[0]: "<<word[0]<<" pc: "<<pc<<endl;
    if(word[0]=="USE")
    {
        cout<<"USE detected!"<<endl;
        BLOCK[curr_block].length=pc;
        if(word[1]=="")
        {
            word[1]="DEFAULT";
            curr_block="DEFAULT";
            pc=BLOCK["DEFAULT"].length;
        }
        else if(BLOCK[word[1]].exist=='y')
        {
            curr_block=word[1];
            pc=BLOCK[word[1]].length;
        }
        else
        {
            BLOCK[word[1]].num=block_num;
            BLOCK[word[1]].exist='y';
            BLOCK[word[1]].length="0";
            curr_block=word[1];
            pc="0";
            ++block_num;
        }
        fout1<<""<<endl;
        fout1<<word[0]<<endl;
        fout1<<word[1]<<endl;
        fout1<<pc<<endl;
        fout1<<""<<endl;
        return;
    }
    if(word[0][0]=='+')
    {
        cout<<"Format 4"<<endl;
        fout1<<""<<endl;
        fout1<<word[0]<<endl;
        fout1<<word[1]<<endl;
        fout1<<pc<<endl;
        pc=toHex(toDec(pc)+4);
        fout1<<pc<<endl;
        return;
    }
    if(OPTAB[word[0]].exist=='y')
    {
        cout<<"0 is opcode!"<<endl;
        fout1<<""<<endl;
        fout1<<word[0]<<endl;
        fout1<<word[1]<<endl;
        fout1<<pc<<endl;
        pc=toHex(toDec(pc)+OPTAB[word[0]].format);
        fout1<<pc<<endl;
        return;
    }
    if(OPTAB[word[0]].exist=='n')
    {
        if(SYMTAB[word[0]].exist=='y')
        {
            error<<"Line "<<line<<": Duplicate Symbol"<<endl;
            error_flag=1;
        }
        else
        {
            if(EXPORT[word[0]].exist=='y')
            {
               EXPORT[word[0]].address=pc;   
            }
 
            
            if(word[0]=="*")
            {
                word[0]=word[1];
                word[2]=word[1].substr(1);
                word[1]="BYTE";
                LITAB[word[0]].address=pc;
                LITAB[word[0]].exist='y';
                LITAB[word[0]].block=curr_block;

            }
            if(word[1]=="EQU")
            {
                 
                 SYMTAB[word[0]].block=curr_block;
                 SYMTAB[word[0]].exist='y';

                 if(word[2]=="*")
                 {
                    SYMTAB[word[0]].address=pc;
                    SYMTAB[word[0]].block=curr_block;

                 }
                 else
                 {

                     string h1=word[2];
                     word[2]="";
                     word[3]="";

                    int  count =2;
                    for(int k1=0;k1<h1.size();k1++)
                    {
                         if(h1[k1]=='-')count++;
                         else
                         {
                            word[count]+=h1[k1];
                         }
                         
                    }
                    
                    if(count==2)
                    {
                       SYMTAB[word[0]]=SYMTAB[word[2]];
                       SYMTAB[word[0]].block=curr_block;
                    }
                    else
                    {
                        SYMTAB[word[0]].address=toHex(toDec(SYMTAB[word[2]].address)-toDec(SYMTAB[word[3]].address));          
                    }

                    word[2]=h1;                      
                 }

                 
                 fout1<<word[0]<<endl;
                 fout1<<word[1]<<endl;
                 fout1<<word[2]<<endl; 
                 fout1<<pc<<endl;
                 fout1<<pc<<endl;


              return ;
 
            }
            

            
            SYMTAB[word[0]].address=pc;
            SYMTAB[word[0]].block=curr_block;
            SYMTAB[word[0]].exist='y';
            fout1<<word[0]<<endl;
            fout1<<word[1]<<endl;
            fout1<<word[2]<<endl;
            fout1<<pc<<endl;
            if(word[1][0]=='+')
                pc=toHex(toDec(pc)+4);
            else if(OPTAB[word[1]].exist=='y')
                pc=toHex(toDec(pc)+OPTAB[word[1]].format);
            else if(word[1]=="WORD")      pc=toHex(toDec(pc)+3);
            else if(word[1]=="RESW")      pc=toHex(toDec(pc)+(atoi(word[2].c_str())*3));
            else if(word[1]=="RESB")      pc=toHex(toDec(pc)+atoi(word[2].c_str()));
            else if(word[1]=="BYTE")
            {

                 int len=word[2].length()-3;
                 if(word[2][0]=='X') len/=2;
                 pc=toHex(toDec(pc)+len);
            }
            else
            {
                error<<"Line "<<line<<": Opcode not found"<<endl;
                error_flag=1;
            }
            fout1<<pc<<endl;
        }
    }
}


