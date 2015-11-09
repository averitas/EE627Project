#ifndef USERDATA_H
#define USERDATA_H

class userdata{
public:
	userdata();
	void setSize(int nums);
	void setRate(int order,int tag,int r);
	~userdata();
	int search(int tag);
	int size();
private:
	class Rate{
	public:	
		int tag;
		int rate;
		Rate(){}
		~Rate(){}
	};
	Rate *datas;
	int size_;
};

#endif  // def userdata