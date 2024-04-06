## File Manipulation Program

### 概要
テキストファイルを読み込み、4つのコマンドに従って処理を行うプログラムです。

1. テキストのコピー  
   `./FileManipulatorProgram "copy" "test1.txt" "test2.txt" `
   と入力することで`test1.txt`の内容を`test2.txt`にコピーすることができます。  

2. テキストの逆順コピー  
   `./FileManipulatorProgram "reverse" "test1.txt" "test2.txt" `
   と入力することで`text1.txt`の内容を**逆順にして**`test2.txt`にコピーすることができます。  

3. テキストの複製  
   `./FileManipulatorProgram "duplicate-contents" "test1.txt" "2"`
   と入力することで`text1.txt`の内容を2回繰り返し`test1.txt`に書き込むことができます。  
   **注意**: 複製する回数は必ずダブルクォーテーション(\"")で囲んで入力してください！    

5. テキスト内の単語の置換  
   `./FileManipulatorProgram "replace-string" "test1.txt" "abc" "efg"`
   と入力することで`test1.txt`に存在する`abc`という文字列を`efg`に変換することができます。  
