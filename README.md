# tranishi
Make movie.pdb from trajectory file of psygene

# コンパイル
make してください。
エラーが出るときは、一度make cleanしてみてください。

#使い方
./tranishi (trajectory file) (pdb file) (stride) (selection)


  trajectory file: ファイル名  
  pdb file: テンプレートとなるpdbファイル（trajectoryファイルの原子数と完全に一致していること）  
  stride: 整数型（>0）の数字を指定。trajectoryファイルのstep数を間引いて出力するかどうか。全て出力したいときは「1」を入れる。  
  selection: 以下4つの選択肢が利用可能。水を全て出力するとファイルが大きくなり過ぎるため、「heavy」の指定を推奨。  
    all       水（残基名：WAT）やイオン（CIP、CIM）、水素を含む全原子  
    heavy     重原子のみ  
    protein   水素を含むタンパク質  
    mainchain 主鎖原子（原子名：N, CA, C, O）のみ  


##（１）psygene（cosgene）のトラジェクトリーファイルの書式
trajectoryファイル（.codや.crd）はバイナリで書かれているため、その書式が分からないと中身も読めない。  
以下に記す。  

以下に示す数字は全てbyte単位である。intは整数型、floatは小数点型である。  


4 (no information)  
4 (int, loop number)  
4 (float, simulation time)  
4 (float, cpu time)  
4 (float, total energy)  
4 (float, kinetic energy)  
4 (float, temperature)  
4 (float, potential energy)  
4 (float, rmsf (root mean square fluctuation))  
4 (int, num15svw)  
4 (int, num15hyd)  
4 (float, rmsd (root mean square deviation))  
8 (no information)  
4*3N (float, coordinates(x, y, z), "N" is the number of atoms)  
4 (no information)  


以上が、MDのループの1step分で、以降はこれの繰り返し。

