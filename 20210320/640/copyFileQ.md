#copyFileQ
//OCE......640
//copyFileQ
#include <iostream> // cout, endl
#include <string>   // string
#include <cstdio>   // fopen, fwrite, fclose
#include <cstdlib>  // system

#define SID_LEN	12    // length of sid
//#define SR_NUM  5   // number of student records

using namespace std;

typedef struct student
{	char	sid[SID_LEN];   // fixed-length ID
	int		score;          // integer score
}	studentType;

// (1) 填寫函數宣告的參數型別才能編譯
void saveFile(FILE *, studentType [], int);

int main(void)
{   FILE        *infile = NULL, *outfile = NULL;     // handler of input file
	string      fileName = "DSsample1.dat";
	studentType *bufS;             // buffer to keep all students
	int         studentNo = 0;

// (2) 置換下方NULL為開啟檔案指令fopen即可成功讀檔，二個參數：檔名字串, 開檔模式
    infile = fopen (fileName.c_str(),"r");    // open a file to read
    if (infile != NULL)
    {   fseek(infile, 0, SEEK_END);
        studentNo = ftell(infile) / sizeof(studentType);    // total number of students
        rewind(infile);
        try
        {	bufS = new studentType [studentNo];
            for (int i = 0; i < studentNo;	i++)
                fread(&bufS[i], sizeof(studentType), 1, infile);    // read the records one by one
            fileName = fileName.substr(0, 8) + "2.dat";             // change the file name

// (3) 置換下方NULL為開啟檔案指令fopen即可成功寫檔，二個參數：檔名字串, 開檔模式
			outfile = fopen (fileName.c_str(),"w");                 // open a file to write
            if (outfile != NULL)
                saveFile(outfile, bufS, studentNo);

// (4) 加入一行敘述釋放動態配置給指標變數的空間
            delete [] bufS;         // release the memory space occupied
		}   // end try
        catch (bad_alloc& ba)  // failed to allocate memory
        {   cerr << endl << "bad_alloc caught: " << ba.what() << endl;
        }   // end catch
        fclose(infile);             // close the file handler
    }   // end if
    system("pause");
    return 0;
}	// end main

void saveFile(FILE *fp, studentType dA[], int no)
{   for (int i = 0; i < no; i++)    // write records one by one
    {   fwrite(&dA[i], sizeof(dA[i]), 1, fp);
        cout << dA[i].sid << ", " << dA[i].score << endl;
    }   // end for
    fclose(fp); // close the file handler
}
