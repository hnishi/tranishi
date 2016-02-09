# tranishi
Make movie.pdb from trajectory file of psygene

使い方
./tranishi (trajectory file) (pdb file) (stride) (selection)

  trajectory file: ファイル名
  pdb file: テンプレートとなるpdbファイル（trajectoryファイルの原子数と完全に一致していること）
  stride: 整数型（>0）の数字を指定。trajectoryファイルのstep数を間引いて出力するかどうか。全て出力したいときは「1」を入れる。
  selection: 以下4つの選択肢が利用可能。水を全て出力するとファイルが大きくなり過ぎるため、「heavy」の指定を推奨。
    all       水（残基名：WAT）やイオン（CIP、CIM）、水素を含む全原子
    heavy     重原子のみ
    protein   水素を含むタンパク質
    mainchain 主鎖原子（原子名：N, CA, C, O）のみ


（１）psygene（cosgene）のトラジェクトリーファイルの書式
trajectoryファイル（.codや.crd）はバイナリで書かれているため、その書式が分からないと中身も読めない。
以下に記す。

[BEGIN OF FILE]
  [BEGIN OF STEP]
  
  [END OF STEP]
  ...同上
  ...同上
  ...同上
[END OF FILE]
