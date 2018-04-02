#include <iostream>
#include "include/md5wrapper.h"
#include <stdlib.h>  
#include <ctime>




using namespace std;





string maHoaMD5(string password){
	md5wrapper md5;
	string paswwordmd5= md5.getHashFromString(password);
	return paswwordmd5;
}

string randomID(int length){
	char a[]="123456789QAZXSWEDCVFRTGBNHYUJMKILOP";
	string result;
	srand (time (NULL)); 
	for(int i=0; i<length; i++){	
		int x= rand() % (sizeof(a)-1); 
		result+=a[x];
	}	
	return result;
}

struct MonHoc
{
	string MaMH;
	string TenMH;	
};

struct NodeMonHoc
{
	MonHoc monhoc;
	NodeMonHoc *next;
};

typedef NodeMonHoc* NodeMonHocPTR;

struct DanhSachMonHoc
{
	NodeMonHocPTR first;
	NodeMonHocPTR last;
};



void KhoiTaoDanhSachMonHoc(DanhSachMonHoc &dsmh)
{
	dsmh.first=NULL;
	dsmh.last=NULL;
}

NodeMonHocPTR newNodeMH(MonHoc monhoc){
	NodeMonHocPTR p= new NodeMonHoc;
	if(p==NULL) return 0;
	
	p->monhoc = monhoc;
	p->next= NULL;
	return p;
}

void themNodeMonHocDauDS(DanhSachMonHoc &dsmh, NodeMonHocPTR x){
	x->next=dsmh.first;
	dsmh.first=x;
}

void themNodeMonHocCuoiDS(DanhSachMonHoc &dsmh, NodeMonHocPTR x){
	if(dsmh.first==NULL){
		dsmh.first=dsmh.last=x;
	}else{
		dsmh.last->next=x;
		dsmh.last=x;
		
	}
	
}

//Ham doc du lieu tu file
void docDuLieuMonHoc(ifstream &filein, MonHoc &monhoc){
	getline(filein,monhoc.MaMH,',');
	getline(filein,monhoc.TenMH);
}


void xuatThongTinMonHoc(MonHoc monhoc){
	cout<<"Ma mon hoc:"<<monhoc.MaMH<<endl;
	cout<<"Ten mon hoc:"<<monhoc.TenMH<<endl;
}


void docDSMonHoc(ifstream &filein,DanhSachMonHoc &danhsachmonhoc){

	while(!filein.eof())
	{
		MonHoc mh;
		docDuLieuMonHoc(filein,mh);
	
		// khoi tao  1 NODE
		NodeMonHocPTR p = newNodeMH(mh);
		
		// them monhoc vao danh sach
		themNodeMonHocCuoiDS(danhsachmonhoc,p);
		
	}
	filein.close();
}

void xuatThongTinDSMonHoc(NodeMonHocPTR First){
	NodeMonHocPTR p;
	p=First;
	if(p==NULL) cout<<"khong co mon hoc trong danh sach";
	while (p!=NULL){
		cout<<"Ma mon hoc:"<<p->monhoc.MaMH<<endl;
		cout<<"Ten mon hoc:"<<p->monhoc.TenMH<<endl;		
		p=p->next;	
	}
}



void themMonHocVaoFile(ofstream &fileout,MonHoc monhoc){
	if(fileout.fail()){
		cout<<"Khong tao duoc file"<<endl;
		return;
	}		
		fileout<< monhoc.MaMH<<",";
		fileout<<monhoc.TenMH;
		fileout<<endl;
	

}





int main(int argc, char** argv) {

	
	
	return 0;	
	return 0;
}
