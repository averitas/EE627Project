#include "userdata.h"

userdata::userdata(){
	size_=0;
}

userdata::~userdata(){
	delete [] datas;
}

void userdata::setSize(int nums){
	size_=nums;
	datas=new Rate[nums];
}

void userdata::setRate(int order,int tag,int r){
	datas[order].tag=tag;
	datas[order].rate=r;
}

int userdata::search(int tag){
	int i;
	for(i=0;i<size_;i++){
		if(datas[i].tag==tag) return datas[i].rate;
	}
	return 0;
}

int userdata::size(){
	return size_;
}

