# matrix-cpp

## 動機

大学の講義・実習で配布してもらった、お手製の行列ライブラリ（ヘッダオンリー）は C で書かれたものだった。しかし私は C++ の方が好きだ。そこで C++ 向けのヘッダオンリーライブラリを作ることにした。  
実習では BLAS/LAPACK を使用したので、同じように LAPACK に使用できる行列（生配列）を作る。私は他のライブラリを知らないのだ。

種々のアルゴリズム（ガウスの消去法とかLU分解とか）を自前で実装しても良いことは一つもないので、やらない。あくまでも解きたい問題がサクッと解ければよいだけなのだ。

## 目標

速度より使いやすさを重視する予定。~~速度を意識できるような技量はないし~~サクッと計算したいので。
