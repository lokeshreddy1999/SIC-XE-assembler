#include<bits/stdc++.h>
#include<iostream>
#include<cstdlib>
#include<fstream>
#include<string>
#include<cstdio>
#include<map>
#include<climits>
#include "Pass2.cpp"

void clean()
{
	fstream intm3;intm3.open("intermediate1.txt",ios::out | ios::trunc); intm3.close();
	fstream intm31;intm31.open("list.txt",ios::out | ios::trunc); intm31.close();
	fstream intm32;intm32.open("object.txt",ios::out | ios::trunc); intm32.close();
	fstream intm34;intm32.open("tempinput.txt",ios::out | ios::trunc); intm34.close();

}



int main()
{
	 fstream fin;
	 fstream fout;
	
	 fin.open("Nainput.txt");
	 fout.open("tempinput.txt", ios::out | ios::trunc);	
	 
	 
	 string CSECT;

	 clean();
     
	 while(1)
	 {

	 	 string s;
	 	 getline(fin,s);
	 	 
	 	 if(s.find("START")!=string::npos)
	 	 {
	 	 	int i=0;
	 	 	CSECT="";
	 	 	while(s[i]!=' '){CSECT+=s[i];i++;}
	 	 }

          	 	 
	 	 if(s.find("CSECT")!=string::npos)
	 	 {
            fout<<"END"<<"\t"<<CSECT<<endl;
            int i=0;
	 	 	CSECT="";
	 	 	while(s[i]!=' '){CSECT+=s[i];i++;}
            run2();  //pass1();pass2();
            
            fout.close();
            fout.open("tempinput.txt", ios::out | ios::trunc);
	 	 	
	 	 	
	 	 }
	 	 
	 	 
	 	 if(s.find(" END ")!=string::npos)
	 	 {
	 	 	
           
	 	 	string h1=s;
            string s1;
            getline(fin,s1);
            
            if(s1.find("*")!=string::npos)
            {
            	fout<<s1<<endl;
            } 
            
           fout<<h1<<endl;  
	 	   run2();	//pass1();pass2();
	 	   break;

	 	 	
	 	 	
	 	 }
        fout<<s<<endl;
	 	 
          	 	 


	 }
    




}
