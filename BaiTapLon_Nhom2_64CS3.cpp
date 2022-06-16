#include<iostream>
#include<cstdio>
#include<iomanip>
#include<cmath>
using namespace std;

class SinhVien
{
private:
    string tenSV;
    string hoTendem;
    string maSV;
public:
    SinhVien()
    {

    }
    void setTenSV(string t)
    {
        tenSV = t;
    }
    void setMaSV(string m)
    {
        maSV = m;
    }
    void setHoTenDem(string t)
    {
        hoTendem =t;
    }
    string getTenSV()
    {
        return tenSV;
    }
    string getMaSV()
    {
        return maSV;
    }
    string getHoTenDem()
    {
        return hoTendem;
    }
};


struct QTvaKT
{
    double diemQT;
    double diemKT;

};
struct MonHoc
{
    string maMH;
    string tenMH;
    int soTC;
    QTvaKT diemQTvaKT;
};

MonHoc dsMonHoc[] ={{"LTNC","Lap trinh nang cao",3,0,0},
                    {"LTKT","Lap trinh ky thuat",2,0,0},
                    {"VL2","Vat Ly 2",2},
                    {"TNVL2","Thi nghiem vat ly 2",1},
                    {"GT2","Giai Tich 2",3},
                    {"PL2","Phap Luat 2",2},
                    {"KTVM","Kinh te vi mo",2},
                    {"MLN","CN Mac Le-Nin",3}};


class BangDiem
{

 private:
     //MonHoc MH[8];
     //dung cau lenh tren ko dc nen dung cai duoi
     MonHoc MH[8] ={{"LTNC","Lap trinh nang cao",3},
                    {"LTKT","Lap trinh ky thuat",2},
                    {"VL2","Vat Ly 2",2},
                    {"TNVL2","Thi nghiem vat ly 2",1},
                    {"GT2","Giai Tich 2",3},
                    {"PL2","Phap Luat 2",2},
                    {"KTVM","Kinh te vi mo",2},
                    {"MLN","CN Mac Le-Nin",3}};
    //code block 17.12 bi loi cho nay huhu


    //5 he diem
     //he 10 tung mon
     double diemHe10[8];

     // 10 sang A,B,C
     string diemChu[8];

     //diem he chu sang 4
     double diemHe4[8];

     // TBT he 4;
     double TBCHK04;

     // TBT hoc ky he 10
     double TBCHK10; // 1 cai

     //double tongTC;

 public:
//     BangDiem()
//     {
//         MH = dsMonHoc;
//     }
    //co 8 mon hoc thoi

    string getMaMH(int i)
    {
        return MH[i].maMH;
    }
    string getTenMH(int i)
    {
        return MH[i].tenMH;
    }
     // set diem cho mon hoc,i la chi so mon hoc trong truct MonHoc
    void setDiem(double qt,double kt,int i);

    // goi ham de tinh toan 5 dau diem
    void tinh5daudiem();

    //tra ve cac dau diem
    double getTBCHK10()
    {
        return TBCHK10;
    }
    double getTBCHK04()
    {
        return TBCHK04;
    }

    void setDiemQT(int i, double qt)
    {
        MH[i].diemQTvaKT.diemQT = qt;
    }
    void setDiemKT(int i,double kt)
    {
        MH[i].diemQTvaKT.diemKT = kt;
    }

    //nhap
    double tongTCc( )
    {
        double t;
        for(int i =0;i<8;i++)
        {
            t += MH[i].soTC;
        }
        return t;
    }

    double getDiemLTNC()
    {
        return diemHe10[0];
    }

    double getDiemLTKT()
    {
        return diemHe10[1];
    }


};

void BangDiem::tinh5daudiem()
{
    double tongTC=0;
    //double tongTCTL = 0;
    double tongDiemHe10=0;
    double tongDiemHe04=0;
    for(int i = 0;i<8;i++)
    {
        tongTC += MH[i].soTC;
    }
    for(int i =0;i<8;i++)
    {
        //MH[i] =dsMonHoc;
        //tongTC += MH[i].soTC;
        diemHe10[i] = MH[i].diemQTvaKT.diemQT*0.3 + MH[i].diemQTvaKT.diemKT*0.7;
        if(diemHe10[i] >= 8.5)
        {
            diemChu[i] = "A";
            diemHe4[i] =4;
        }
        else if(diemHe10[i] >= 8)
        {
            diemChu[i] = "B+";
            diemHe4[i] = 3.5;
        }
        else if(diemHe10[i] >= 7)
        {
            diemChu[i] = "B";
            diemHe4[i] = 3;
        }
        else if(diemHe10[i] >= 6.5)
        {
            diemChu[i] = "C+";
            diemHe4[i] = 2.5;
        }
        else if(diemHe10[i] >= 5.5)
        {
            diemChu[i] = "C";
            diemHe4[i] = 2;
        }
        else if(diemHe10[i] >= 5)
        {
            diemChu[i] = "D+";
            diemHe4[i] = 1.5;
        }
        else if(diemHe10[i] >= 4)
        {
            diemChu[i] = "D";
            diemHe4[i] = 1;
        }
        else
        {
            diemChu[i] = "F";
            diemHe4[i] = 0;
        }

    }
    for(int i=0;i<8;i++)
    {
        tongDiemHe10 += diemHe10[i]*MH[i].soTC;
        tongDiemHe04+=diemHe4[i]*MH[i].soTC;
    }

    TBCHK10 = (double)tongDiemHe10/tongTC;
    TBCHK04 = (double)tongDiemHe04/tongTC;

}
void BangDiem::setDiem(double qt, double kt ,int i)
{
    MH[i].diemQTvaKT.diemQT = qt;
    MH[i].diemQTvaKT.diemKT = kt;

    //tinh5daudiem();
}

class Lop
{
private:
    string tenLop;
    int siSo;
    //SinhVien SV[60];
    //BangDiem BD[60];

public:
    SinhVien SV[60];
    BangDiem BD[60];
    void setTenLop(string t)
    {
        tenLop =t;
    }
    void setSiSo(int s)
    {
        siSo = s;
    }
    void setSinhVien(SinhVien sv,int i)
    {
        this->SV[i] = sv;
    }
    void setBangDiem(BangDiem bd , int i)
    {
        this->BD[i] = bd;
    }
    string getTenLop()
    {
        return tenLop;
    }
    int getSiso()
    {
        return siSo;
    }


};

void NhapDuLieu(Lop &cs)
{
    MonHoc mh[8] = dsMonHoc;

    // code block 20.03 thi bi loi o tren
    // neu cau lenh tren khong nhan thi dung cau lenh ben duoi

//    MonHoc mh[8] ={{"LTNC","Lap trinh nang cao",3},
//                    {"LTKT","Lap trinh ky thuat",2},
//                    {"VL2","Vat Ly 2",2},
//                    {"TNVL2","Thi nghiem vat ly 2",1},
//                    {"GT2","Giai Tich 2",3},
//                    {"PL2","Phap Luat 2",2},
//                    {"KTVM","Kinh te vi mo",2},
//                    {"MLN","CN Mac Le-Nin",3}};
    string tenlop;
    int siso;
    cout << "Ten Lop : ";
    cin >> tenlop;
    cs.setTenLop(tenlop);

    cout << "Si so : ";
    cin >> siso;
    cs.setSiSo(siso);

    cin.ignore();
    //cin.get();
    string ten;
    string hotendem;
    string mssv;
    double qt,kt;
    for(int ss = 0;ss < siso;ss++)
    {
        cout << "Sinh vien : " << (ss+1) << endl;

        cout << "Ho ten dem: ";
        getline(cin,hotendem);
        cs.SV[ss].setHoTenDem(hotendem);

        cout << "Ten : ";
        getline(cin,ten);
        cs.SV[ss].setTenSV(ten);

        cout << "Ma so SV : ";
        cin >> mssv;
        cs.SV[ss].setMaSV(mssv);

        cout << "---------------" << endl;
        cout << "Nhap diem qt va kt : " << endl;
        //float qt,kt;
        for(int i = 0;i < 8; i++)
        {
            cout << mh[i].maMH << "-" << mh[i].tenMH << endl;
            cout << "Diem QT : ";
            cin >> qt;
            if(qt > 10)
                qt = 10;
            else if(qt < 0)
                qt =0;
            cs.BD[ss].setDiemQT(i,qt);
            cout << "Diem KT : ";
            cin >> kt;
            if(kt > 10)
                kt = 10;
            else if(qt < 0)
                kt =0;
            cs.BD[ss].setDiemKT(i,kt);

        }
        cs.BD[ss].tinh5daudiem();
        cin.get();
    }

}
//sap xep ABC

void swapSV(SinhVien &a,SinhVien &b)
{
    SinhVien c ;
    c = a;
    a = b;
    b = c;
}
void swapBD(BangDiem &a,BangDiem &b)
{
    BangDiem c;
    c = a;
    a = b;
    b = c;
}

void sapXepABC(Lop &cs)
{
    for(int i = 0; i <cs.getSiso()-1; i++)
    {
        for(int j = i+1; j < cs.getSiso(); j++)
        {
            if(cs.SV[i].getTenSV() > cs.SV[j].getTenSV())
            {
                swapSV(cs.SV[i],cs.SV[j]);
                swapBD(cs.BD[i],cs.BD[j]);
            }
            else if(cs.SV[i].getTenSV() == cs.SV[j].getTenSV())
            {
                if(cs.SV[i].getHoTenDem() > cs.SV[j].getHoTenDem())
                {
                    swapSV(cs.SV[i],cs.SV[j]);
                    swapBD(cs.BD[i],cs.BD[j]);
                }
            }
        }
    }
}
void hienThi(Lop &cs)
{
    sapXepABC(cs);
    cout << "Lop : " << cs.getTenLop() << endl;
    cout << "Si so : " <<cs.getSiso() << endl;
    cout << "___________________________________________________\n";
    cout << "| STT | Ten SV \t\t  | Ma sv | TBHK(10) | TBTL (04) |\n";
    for(int i =0;i<cs.getSiso();i++)
    {
        //cout << fixed << showpoint << setprecision(2);
        cout << "|  " <<(i+1) << "  |  "<< cs.SV[i].getHoTenDem() << " " <<cs.SV[i].getTenSV() << " \t| " << cs.SV[i].getMaSV();
        cout << fixed << setprecision(2);
        cout <<"| "<<cs.BD[i].getTBCHK10() << " | " << cs.BD[i].getTBCHK04() << endl;
    }
    cout << "=================================="<< endl;

}

//c tinh in ra gia tri trung binh diem mon lap trinh nang cao cua ca lop
void tinhTBLTNC(Lop cs)
{
    double sum =0;
    for(int i = 0; i < cs.getSiso(); i++)
    {
        sum += cs.BD[i].getDiemLTNC();
    }
    cout << "Gia tri trung binh diem mon lap trinh cua lop " << cs.getTenLop() << " la : " << sum/cs.getSiso() << endl;;
}

//d diem  thap nhat va cao nhat lap trinh danh cho ky thuat
void minMaxLTDCKY(Lop cs)
{
    double min = cs.BD[0].getDiemLTKT();
    int imin = 0;
    double max = cs.BD[cs.getSiso()-1].getDiemLTKT();
    int imax = cs.getSiso()-1;
    for(int i = 0; i< cs.getSiso();i++)
    {
        if(cs.BD[i].getDiemLTKT() < min )
        {
            min = cs.BD[i].getDiemLTKT();
            imin = i;
        }
        if(cs.BD[i].getDiemLTKT()> max)
        {
            max = cs.BD[i].getDiemLTKT();
            imax =i;
        }
    }

    cout << "Lop : "<<cs.getTenLop() << "\n";
    cout << "Diem thap nhat mon LTKT la : " << min << " thuoc ve sinh vien : ";
    cout << cs.SV[imin].getHoTenDem() << " " << cs.SV[imin].getTenSV() << endl;
    cout << "Diem cao nhat mon LTKT la : " << max << " thuoc ve sinh vien : ";
    cout << cs.SV[imax].getHoTenDem() << " " <<cs.SV[imax].getTenSV() << endl;
}

//e tinh %
void percentPoint(Lop cs)
{
    int numOfA =0;
    int numOfB =0;
    int numOfC =0;
    int numOfD =0;

    double percentA,percentB,percentC,percentD;
    double c;
    for(int i = 0; i < cs.getSiso(); i++)
    {
        c = cs.BD[i].getDiemLTNC();
        if(c >= 8.5)
            numOfA++;
        else if(c >= 7 && c < 8.5)
            numOfB++;
        else if(c >= 5.5 && c < 7)
            numOfC++;
        else if(c >= 4 && c < 5.5)
            numOfD++;
    }

    percentA = ((double)numOfA/cs.getSiso())*100;
    percentB = ((double)numOfB/cs.getSiso())*100;
    percentC = ((double)numOfC/cs.getSiso())*100;
    percentD = ((double)numOfD/cs.getSiso())*100;

    cout << "So luong va  % so sv dat diem mon LTNC lop "<< cs.getTenLop() << " la : \n";
    cout << "Diem A    : " << numOfA << " - " << percentA << "%." << endl;
    cout << "Diem B,B+ : " << numOfB << " - " << percentB << "%." << endl;
    cout << "Diem C,C+ : " << numOfC << " - " << percentC << "%." << endl;
    cout << "Diem D,D+ : " << numOfD << " - " << percentD << "%." << endl;

}

//f tinh ra tri trung binh chung (he 4 ) hk2
void tinhTBCHK04(Lop cs)
{
    double sum;
    for(int i = 0 ;i < cs.getSiso() ; i++)
    {
        sum += cs.BD[i].getTBCHK04();
    }

    cout << "Gia tri trung binh diem trung binh chung (he 4) HK2 cua lop " << cs.getTenLop() << " la : ";
    cout << sum/cs.getSiso() << endl;
}


//g tinh ra tri trung binh chung (he 10 ) hk2
void tinhTBCHK10(Lop cs)
{
    double sum;
    for(int i = 0 ;i < cs.getSiso() ; i++)
    {
        sum += cs.BD[i].getTBCHK10();
    }

    cout << "Gia tri trung binh diem trung binh chung (he 10) HK2 cua lop " << cs.getTenLop() << " la  : ";
    cout << sum/cs.getSiso() << endl;
}

void diem5svLTKT1(Lop cs)
{
    for(int i = 0; i < cs.getSiso()-1;i++)
    {
        for(int j = i+1; j<cs.getSiso();j++)
        {
            if(cs.BD[i].getDiemLTKT() < cs.BD[i].getDiemLTKT())
            {
                swapSV(cs.SV[i],cs.SV[j]);
                swapBD(cs.BD[i],cs.BD[j]);
            }
        }
    }

    cout << "Lop : "<< cs.getTenLop() << endl;
    double fifthPoint = cs.BD[5].getDiemLTKT();
    for(int i = 0; i < 5 ; i++)
    {
        cout << cs.SV[i].getHoTenDem() << " " << cs.SV[i].getTenSV() << " - " <<cs.BD[i].getDiemLTKT() << endl;
    }
}
//h in ds 5 sv dat diem cao nhat
void diem5svLTKT(Lop cs[3])
{
    double diemLTKT [180];
    //tinh tong so sv 3 lop
    int tongSV =0;
    for(int i = 0; i < 3 ; i++)
    {
        tongSV += cs[i].getSiso();
    }

    cout << "Tong so SV la : " << tongSV << endl;
    //tao 1 mang chua diem LTKT
    //double diemLTKT [180];

    //truyen tung gia tri vao mang
    for(int cs0 =0 ; cs0 < cs[0].getSiso(); cs0++)
    {
        diemLTKT[cs0] = cs[0].BD[cs0].getDiemLTKT();

    }
    int cs01 = cs[0].getSiso()+cs[1].getSiso();
    for(int cs1 = cs[0].getSiso(); cs1 < cs01 ; cs1++)
    {
        diemLTKT[cs1] = cs[1].BD[cs1].getDiemLTKT();
    }
    for(int cs2 = cs01; cs2 < tongSV; cs2++)
    {
        diemLTKT[cs2] = cs[2].BD[cs2].getDiemLTKT();
    }

    cout << "Da truyen du lieu vao bang diem " << endl;
    //sap xep bang diem
    for(int i = 0; i< 180-1 ; i++)
    {
        for(int j = i+1 ; j<180 ; j++)
        {
            if(diemLTKT[i] < diemLTKT[j])
            {
                double a = diemLTKT[i];
                diemLTKT[i] = diemLTKT[j];
                diemLTKT[j] = a;
            }
        }
    }
    //chon diem cao thu 5
    double fifthPoint = diemLTKT[4];

    cout << "Done ! " <<endl;
    cout << "Diem dung thu 5 trong ds : " << fifthPoint << endl;

    cout << "Den day thi khong biet sai cho nao nua r ! HUHU "<< endl;
//    //duyen tung lop ai co diem cao hon thi in ra man hinh
//    for(int cs0 = 0; cs0 < cs[0].getSiso() ;cs0++)
//    {
//        if(cs[0].BD[cs0].getDiemLTKT() >= fifthPoint)
//            cout << cs[0].BD[cs0].getDiemLTKT() << " -- "
//            <<cs[0].SV[cs0].getMaSV() <<  "-- " << cs[2].getTenLop()<< endl;
//    }
//    for(int cs1 = 0; cs1 < cs[1].getSiso() ;cs1++)
//    {
//        if(cs[1].BD[cs1].getDiemLTKT() >= fifthPoint)
//            cout << cs[1].BD[cs1].getDiemLTKT() << " -- "
//            <<cs[1].SV[cs1].getMaSV() << "-- " << cs[2].getTenLop()<< endl;
//    }
//
//    for(int cs2 = 0; cs2 < cs[2].getSiso() ;cs2++)
//    {
//        if(cs[2].BD[cs2].getDiemLTKT() >= fifthPoint)
//            cout << cs[2].BD[cs2].getDiemLTKT() << " -- "
//            <<cs[2].SV[cs2].getMaSV() << "-- " << cs[2].getTenLop()<< endl;
//    }

    for(int i = 0 ; i < 3 ;i++)
    {
        for(int sv = 0; sv < cs[i].getSiso() ;sv++)
        {
            if(cs[i].BD[sv].getDiemLTKT() >= fifthPoint)
            {
                cout << cs[i].BD[sv].getDiemLTKT() << " -- ";
                cout << cs[i].SV[sv].getHoTenDem() << " " << cs[i].SV[sv].getTenSV() << " -- " << cs[i].getTenLop()<< endl;
            }
        }
    }


}

int main()
{

    int key;

    Lop CS[3];
    do
    {

        cout << "\n";
        cout << "************************************************************************\n";
        cout << "*          Menu ( Hay chon chuc nang )                                 *\n";
        cout << "* [ 1 ] Nhap du lieu cua lop                                           *\n";
        cout << "* [ 2 ] Danh sach sinh vien trong lop (Alphabe)                        *\n";
        cout << "* [ 3 ] Gia tri trung binh diem mon lap trinh nang cao                 *\n";
        cout << "* [ 4 ] Diem thap nhat va cao nhat mon lap trinh ki thuat              *\n";
        cout << "* [ 5 ] In ra so luong va phan tram diem LTNC                          *\n";
        cout << "* [ 6 ] Gia tri trung binh diem trung binh (he 4)                      *\n";
        cout << "* [ 7 ] Gia tri trung binh diem trung binh (he 10)                     *\n";
        cout << "* [ 8 ] Danh sach 5 sinh vien diem cao nhat mon LTKT (1 Lop)           *\n";
        cout << "* [ 9 ] Danh sach 5 sinh vien diem cao nhat mon LTKT (3 Lop)           *\n";
        cout << "* [ 10] Thoat chuong trinh                                             *\n";
        cout << "************************************************************************\n";
        cout <<"\nNhap lua chon (1-9): ";
        cin>>key;


        //Lop CS[3];
        switch(key)
        {
        case 1:
            cout << "Yeu cau nhap du lieu cua ca 3 lop : " << endl;
            //Lop CS[3];
            NhapDuLieu(CS[0]);
            cout << "=================" << endl;
            NhapDuLieu(CS[1]);
            cout << "=================" << endl;
            NhapDuLieu(CS[2]);
            cout << "=================" << endl;
            cout << " DONE ! " << endl;
            break;
        case 2:
            hienThi(CS[0]);
            cout << "=================" << endl;
            hienThi(CS[1]);
            cout << "=================" << endl;
            hienThi(CS[2]);
            cout << "=================" << endl;
            break;
        case 3:
            tinhTBLTNC(CS[0]);
            cout << "=================" << endl;
            tinhTBLTNC(CS[1]);
            cout << "=================" << endl;
            tinhTBLTNC(CS[2]);
            cout << "=================" << endl;
            break;
        case 4:
            minMaxLTDCKY(CS[0]);
            cout << "=================" << endl;
            minMaxLTDCKY(CS[1]);
            cout << "=================" << endl;
            minMaxLTDCKY(CS[2]);
            cout << "=================" << endl;
            break;
        case 5:
            percentPoint(CS[0]);
            cout << "=================" << endl;
            percentPoint(CS[1]);
            cout << "=================" << endl;
            percentPoint(CS[2]);
            cout << "=================" << endl;
            break;
        case 6:
            tinhTBCHK04(CS[0]);
            cout << "=================" << endl;
            tinhTBCHK04(CS[1]);
            cout << "=================" << endl;
            tinhTBCHK04(CS[2]);
            cout << "=================" << endl;
            break;

        case 7:
            tinhTBCHK10(CS[0]);
            cout << "=================" << endl;
            tinhTBCHK10(CS[1]);
            cout << "=================" << endl;
            tinhTBCHK10(CS[2]);
            cout << "=================" << endl;
            break;

        case 8:
            diem5svLTKT1(CS[0]);
            cout << "=================" << endl;
            diem5svLTKT1(CS[1]);
            cout << "=================" << endl;
            diem5svLTKT1(CS[2]);
            cout << "=================" << endl;
            break;
        case 9:
            cout << "Khong biet sai cho nao, mong thay co sua giup ! " << endl;
            diem5svLTKT(CS);
            break;
        case 10:
            return 0;
            break;
        default:
            cout << "Chon sai ! Moi chon lai : " << endl;
            break;

        }
    }while (key >= 1  && key <=9);
    return 0;

}
