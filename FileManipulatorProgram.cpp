#include <iostream>
#include <fstream>
#include <typeinfo>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

//argv[0]は必ず実行ファイルが保存されている
//https://programming.pc-note.net/cpp/filestream.html
//fstreamのバリデーション
int main(int argc, char *argv[]){
    // cout << "argc " << argc << endl;
    if(argv[1] == NULL){
        cout << "コマンドの指定がないか、間違ったコマンドを入れています。" << endl;
        return 0;
    }
    string file1Name = argv[1];

    if(file1Name == "reverse"){
        //読み込みファイルの設定
        ifstream file1(argv[2]);
        if(file1.fail()){
            cerr << "Fileの指定ができていません。" << endl;
            return 0;
        }
        //書き込みファイルの設定、なければ新規に作られるので大丈夫
        ofstream file2(argv[3]);
        string file1Contents;
        while(1){
        //string型だけど配列としてsの中に文字が入ってる
            string s;
            getline(file1,s);
            //読み込みが終わったら処理から抜ける
            if(file1.eof()) break;
            //sはあくまでstringなのでpush_backはエラーになる。
            // file1Contents.push_back(s);
            file1Contents += s + "\n";
        }
        //ファイルに書き込み
        for (int i = file1Contents.length() - 1; i >= 0; i--){
            file2 << file1Contents[i];
        }
        file1.close();
        file2.close();
        
    }else if(file1Name == "copy"){
        //読み込みファイルの設定
        ifstream file1(argv[2]);
        if(file1.fail()){
            cerr << "Fileの指定ができていません。" << endl;
            return 0;
        }
        string file1Contents;
        while(1){
            string s;
            getline(file1,s);
            if(file1.eof()) break;
            file1Contents += s + "\n";
        }
        //書き込みファイルの設定
        ofstream file2(argv[3]);
        file2 << file1Contents;
        file1.close();
        file2.close();

    }else if(file1Name == "duplicate-contents"){
        fstream file1(argv[2]);
        if(file1.fail()){
            cerr << "Fileの指定ができていません。" << endl;
            return 0;
        }
        int repeatTime = stoi(argv[3]);
        string file1Contents;
        while(1){
            string s;
            getline(file1,s);
            if(file1.eof()) break;
            file1Contents += s + "\n";
        }

        //ファイルの終端まで達しているため、EOFフラグをリセットしてファイルの位置を先頭に戻してから上書きする。
        file1.clear();
        file1.seekp(ios::beg);

        for (int i = 1; i <= repeatTime; i++){
            file1 << file1Contents;
        }
        file1.close();

    }else if(file1Name == "replace-string"){
        fstream file1(argv[2]);
        if(file1.fail()){
            cerr << "Fileの指定ができていません。" << endl;
            return 0;
        }

        string changeString = argv[3];
        string newString = argv[4];
        string file1Contents;
        while(1){
            string s;
            getline(file1,s);
            if(file1.eof()) break;

            if(s.find(changeString) != string::npos) s.replace(s.find(changeString), changeString.length(), newString);
            file1Contents += s + "\n";
        }

        file1.clear();
        file1.seekp(ios::beg);

        file1 << file1Contents;
        file1.close();
    }
    cout << "正常に" << argv[1] << "の操作が完了しました。" << endl;

    return 0;
}