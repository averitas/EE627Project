#include <iostream>
#include <fstream>
#include <string>
#include "userdata.h"

using namespace std;

int main(){
	ifstream test("testTrack_hierarchy.txt");
	ifstream data("trainIdx2.txt");
	ofstream output("output.txt");
	userdata* store;
	store=new userdata[40300];
	while(!data.eof()){
	    string s;
	    int nums=0,user=0,i=0;
		getline(data,s);
	    while(s[i]!='|'){
		    user=user*10+(s[i]-'0');
		    i++;
	    }
	    for(int j=i+1;j<s.length();j++){
		    nums=nums*10+(s[j]-'0');
	    }
	    store[user].setSize(nums);
	    for(int j=0;j<nums;j++){
	    	int tag,rate;
	    	data>>tag;
	    	data>>rate;
	    	store[user].setRate(j,tag,rate);
	    }
	    getline(data,s);
	}


	while(!test.eof()){
		string s;
		getline(test,s);
		int user=0,tag=0,kind=0,i=0,score=0;
		while(s[i]!='|'){
			user=user*10+(s[i]-'0');
			i++;
		}
		i++;
		while(i<s.length()){
			if(s[i]>='0'&&s[i]<='9'){
				tag=tag*10+(s[i]-'0');
			}
			else if(s[i]=='|'&&tag!=0){
				switch(kind){
					case 0:
					score+=store[user].search(tag);
					break;
					case 1:
					score+=0.9*store[user].search(tag);
					break;
					case 2:
					score+=0.85*store[user].search(tag);
					break;
					default:
					score+=0.8*store[user].search(tag);
				}
				kind++;
				tag=0;
			}
			i++;
		}
		output<<score<<'\n';
	}


}